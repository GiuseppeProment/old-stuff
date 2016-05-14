// ADSerial 
// Giuseppe 01.01.2000
// Nota: Ler varias AD a comando da serial 

#include <16f877.h>

// informa o clock
#use delay(clock=4000000)
// USANDO A USART BUILT-IN  c6=tx c7=rx
// velocidade inicial 19200 selecional via comando VELOCIDADE
#use rs232 (baud=19200,xmit=pin_c6,rcv=pin_c7,ERRORS)

#define INTS_PER_SECOND 15     // (4000000/(4*256*256))

#include <string.h> 
#include <stdlib.h>

//#include <input.c>

static long baud=19200;

void help();
void setVelocidade(long valor);
void procComando( char comando );
void loopAnalogico();
void calcularMedia();
void temperatura();
void relogio();
// ************************

byte segundo;      // A running seconds counter
byte minuto;
byte hora;
byte int_count;    // Number of interrupts left before a second has elapsed

#int_rtcc                          // This function is called every time
clock_isr() {                      // the RTCC (timer0) overflows (255->0).
                                   // For this program this is apx 15 times
    if(--int_count==0) {           // per second.
    	
		if (++segundo > 60)
		{	segundo=0;
			if (++minuto > 60) 
			{ minuto=0;
				hora++;
			}
		}
		printf("%02u:%02u:%02u\n\r",hora,minuto,segundo);
      int_count=INTS_PER_SECOND;
    }

}

// ************************

void main() {
	

	char keypress;

	// logica 
	// exibir help
	// entrar em loop at‚ obter um comando v lido ou S1 ser pressionada

	// MENSAGEM DE ON-LINE
	help();
	
	// ajustar adc
	setup_adc_ports( A_ANALOG );
	setup_adc( ADC_CLOCK_DIV_32);
	set_adc_channel(0); // AN0  

	segundo=minuto=hora=0;

   int_count=INTS_PER_SECOND;
   set_rtcc(0);
   setup_counters( RTCC_INTERNAL, RTCC_DIV_256);
   enable_interrupts(RTCC_ZERO);
   enable_interrupts(GLOBAL);

	while(TRUE) 
	{
		output_high(pin_d6);
		
		if ( !input(pin_b0 ) ) // tecla S1 pressionada
		{				
			setVelocidade(19200);
		}

		// ler comando
		if (kbhit())
		{
			keypress=getc();
			output_high( PIN_D0 );
			procComando( keypress );
			output_low( PIN_D0 );
		}
		output_low(pin_d6);
	}
}
// ************************
void help()
{
	
	puts("\n\r(c) Giuseppe 2000 - v1.0B");
	puts("Placa Experimental On-Line");
	puts("--------------------------");
	puts("-=Comandos disponiveis=-");
	puts("L-Loop leitura analogica"); 
	puts("1-ajusta vel. UART"); 
	puts("2-le adc AN0"); 
	puts("3-le adc AN1"); 
	puts("4-le adc AN2"); 
	puts("5-liga leds"); 
	puts("6-desliga leds"); 
	puts("7-ajusta relogio");
	puts("H-ajuda");
	puts("T-Temperatura");
	puts("-=Teclas=-");
	puts("S1-volta a 19200 bauds");
	printf("Velocidade=%lu\n\r",baud);
}
// ************************
void setVelocidade(long valor)
{
	switch( valor ) {
		case 300 :set_uart_speed(300);
			break;
		case 1200 :set_uart_speed(1200);
			break;
		case 2400 :set_uart_speed(2400);
			break;
		case 9600 :set_uart_speed(9600);
			break;
		case 19200 :set_uart_speed(19200);
			break;
	}
	printf("i> velocidade=%lu\n\r",valor);
	baud=valor;
}
// ************************
void procComando(char comando)
{
	char dado[10] = "         ";
	long valor;
	
	switch( comando ) {
		case '1':
		puts("i> entre o valor:");
		gets(dado);
		valor=atol(dado);
		if	( valor<300 || valor>115000 ) 
			puts("i> valor incorreto")	
		else 
			setVelocidade( valor ); 
		break;
		
		case '2':
			printf("S1(A0) = %lu\n\r",read_adc());	
		break;
		
		case '3':
		set_adc_channel(1); 
		delay_ms(100); 
		printf("SENSOR2( A1 )=%lu\n\r",read_adc());
		set_adc_channel(0); 
		break;
		
		case '4':
		set_adc_channel(2); 
		delay_ms(100); 
		printf("SENSOR3( A2 )=%lu\n\r",read_adc());
 	 	set_adc_channel(0); // default
		break;
		
		case '5':
		output_high( pin_d1 );
		output_high( pin_d2 );
 		output_high( pin_d3 );	
		break;
		
		case '6':
		output_low( pin_d1 );
		output_low( pin_d2 );
 		output_low( pin_d3 );	
		break;
		
		case '7':
		relogio();
		break;
		
		case 'H':
		help();
		break;
		
		case 'L':
		loopAnalogico();
		break;
		
		case 'T':
		temperatura();
		break;
		
		
		default:
		puts("Comando invalido");
		break;
		
	}
}

//*******************
void loopAnalogico()
{
	long int nLido=0;
	long int nAntigo=1;
	float valor;
		
	puts(" ");
	puts("** Loop Analogico Diferencial iniciado **");
	while ( ! kbhit()	) {
		nLido = read_adc();
		if(nLido!=nAntigo) {
			valor = (float)nLido;
			valor = valor * (4.98/1023.00);
			printf("Lido=%lu  V+%F\r\n",nLido,valor );
		};
		nAntigo=nLido;
		delay_ms(100);
	}
	puts(" ** loop encerrado **");
}


void temperatura()
{
	// calcular temperatura
	// 0g  = 131
	// 97g = 94
	float valor;
	valor = read_adc();
	valor = (131-valor)*-2.621621621;
	printf("Temp=%F°\r\n",valor );
}




void relogio()
{
	char dado[10] = "         ";
   disable_interrupts(GLOBAL);
   puts("Hora:");
   gets( dado );
   hora=atoi(dado);
   puts("Minuto:");
   gets( dado );
   minuto=atoi(dado);
   puts("Segundo:");
   gets( dado );
   segundo=atoi(dado);
   enable_interrupts(GLOBAL);
}


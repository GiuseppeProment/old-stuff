#include <16f877.h>

// informa o clock
#use delay(clock=4000000)

// ************************

void piscaRapido() {
	while( !input(pin_b3 ) )
	{
		output_high( PIN_D1 );
		delay_ms(100); 
		output_low( PIN_D1 );
		delay_ms(100); 
	}
}
// ************************
/*
#INT_RTCC
interrupcao() {
#use rs232 (baud=300,xmit=pin_c6,rcv=pin_c7)
	printf("Pic> botao pressionado ");
	putc( getc()+1);
	piscaRapido();	
}
*/
// ************************
void main() {
	
	// led conectado em RD1  PortD  pin_d1
	// chave conectada em Rb0 PortD pin_b0 --> press leva a 0 pull-up 1k
	
	// usar interrupcao RTCC
	//set_rtcc(0);
	//setup_counters(RTCC_INTERNAL,RTCC_DIV_4);
	//enable_interrupts(RTCC_ZERO);
	//enable_interrupts(GLOBAL);
	
	//#use rs232 (baud=300,xmit=pin_b6,rcv=pin_b7)
	
	// USANDO A USART BUILT-IN  c6=tx c7=rx
	#use rs232 (baud=19200,xmit=pin_c6,rcv=pin_c7)
	
	short luz=0;
	char buffer[20]="                   ";
	
	while(TRUE) 
	{
		//output_high( PIN_D1 );
		//delay_ms(1000); // 1 segundo 
		//output_low( PIN_D1 );
		//delay_ms(1000); // 1 segundo 
		
		if ( !input(pin_b0 ) ) 
		{				
			output_high( PIN_D0 );
			puts("*************************");
			puts("* alo! PIC16F877 online *");
			puts("*************************");
			output_low( PIN_D0 );
			//piscaRapido();
		}

		// ler strings
		if (kbhit())
		{
			output_high( PIN_D1 );
			gets( buffer );
			puts("RECEBIDO:");
			puts( buffer );
			output_low( PIN_D1 );
		}

/*		if ( kbhit() ) {
			if (luz==0) {
				output_high( PIN_D1 );
				luz=1; }
			else { 
				output_low( pin_d1);
				luz=0; 
				}
		}
*/		
	}
}
// ************************


#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>


void funcao0( int argc, char *argv[ ], char *envp[ ] );
void funcao1( char*[] );
void funcao2( char*[] );
void funcao3( char*[] );

void main( int argc, char *argv[ ], char *envp[ ] ){
	// ler variavel getenv(
	char *conteudo;   
  conteudo = getenv( "QUERY_STRING" );   
	if( conteudo != NULL ) {
		char funcao = conteudo[7];
		switch (funcao) {
		case '1' : 
			funcao1( envp );
			break;
		case '2' : 
			funcao2( envp );
			break;
		case '3' : 
			funcao3( envp );
			break;
		default:
			funcao0(argc, argv, envp);
		}
		}
	else {

				funcao0(argc, argv, envp);
				//cout << "content-type:text/html\n\n" ;
				//cout << "<H1> <p>Nenhuma funcao foi chamada</p> </H1>";
		}
}
// set cookie
void funcao1( char*envp[] ){
	// header para cgi
	cout << "Set-Cookie: CGICookie=Valor;domain=promentflowers.com.br;path=/;expires= Sun, 26-Sep-1999 00:00:00 GMT"<<endl;
	cout << "content-type:text/html\n\n" ;
	cout << "<html> <body> <h1> Cookie Gravado  </h1> " << endl;
}
// ler cookie
void funcao2( char*envp[] ){
	cout << "content-type:text/html\n\n" ;
	cout << "<html> <body> <h1> HTTP_COOKIE=" << endl;
	// leitura 
	char* conteudo = getenv("HTTP_COOKIE");
	if (conteudo != NULL)
		cout << conteudo;
	cout <<  "</h1> </body> </html>";
}
// apagar cookie
void funcao3( char*envp[] ){
	// header para cgi
	cout << "Set-Cookie: CGICookie=Valor;domain=promentflowers.com.br;path=/;expires= Sun, 30-Aug-1998 00:00:00 GMT"<<endl;
	cout << "content-type:text/html\n\n" ;
	cout << "<html> <body> <h1>Cookie Apagado</h1> " << endl;
}

// Outros Testes
void funcao0( int argc, char *argv[ ], char *envp[ ] ){
	//cout << "HTTP/1.0" << endl;
	cout << "content-type:text/html\n\n" ;
	cout << "<html> <body> <h1> CGI inicial  </h1> " << endl;
	// parametros recebidos
	cout << "<p> <h2> Atenção para listagem das variaveis recebidas: </h2> </p>" << endl;
	cout << "<p>numero de variaveis=" << argc << "</p>" << endl;
	for (int i=0; i<argc; i++) 
		cout << "<p>" << argv[i] << "<p>" << endl;
	cout << "<p>*** final *** </p> </body> </html>" << endl;
	// variaveis de ambiente
	cout << "<p>variaveis de ambiente </p>" << endl;
	i=0; 
	while ( envp[i] != NULL )
		cout << "<p>" << envp[i++] << "<p>" << endl;
	cout << "<p>*** final *** </p> </body> </html>" << endl;

	cout << "<p>*** verificando se ha dados POST *** </p>" << endl;
	// verificar pela variavel ambiental CONTENT_LENGHT 
   char *conteudo;     
   conteudo = getenv( "CONTENT_LENGTH" );   
	 if( conteudo !=  NULL ) {
		 cout << "CONTENT_LENGHT=" << conteudo << endl;
		 char pf[100];
		 int len = atoi( conteudo );
		 cin.read(pf,len>100?100:len);
		 cout << "leitura c/ cin da entrada =" << pf << endl;
		 }
	//char list[10];
	//fread( list, sizeof( char ), 5, stdin );
	//cout << "leitura c/ fread da entrada =" << list << endl;

	// gravando arquivo
	 fstream arq( "Ordem.dat", ios::app|ios::binary , filebuf::sh_read|filebuf::sh_write);

	 arq << "Arquivo de Ordems";

	 arq.close();

	return ;
}

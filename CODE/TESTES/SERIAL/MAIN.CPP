 #include "DRICA.H"
 #include <CONIO.H>
 #include <STDIO.H>
 #include <STDLIB.H>


 int serialconfig(int BaudRate, int Parity, int StopBits, int WordLenght,
		  int PortNumber);
 int serialstatus(int PortNumber);
 int serialsend(int Caracter, int PortNumber);
 int serialrecive(int PortNumber);


 main()
 {
	int Tecla = 0;
	int Port = 1;
	int Captura = ERROR;

	/** Inicia a porta serial. *********************************************/
	serialconfig(9600, 0, 0, 8, Port);
	/** Inicia transmissao e recep‡ao. *************************************/
	while(Tecla != ESC)
	{
	   serialsend(Tecla, Port);
	   Tecla = ERROR;
	   Captura = RESET;
	   Captura = serialrecive(Port);
	   if(Captura != ERROR && Captura != 255)
	   {
	      printf("%c", Captura); }
	   if(kbhit()) { Tecla = getch(); }
	}
	printf("\nFinalizando...");
	/** Finaliza programa. *************************************************/
	return(OK);
 }

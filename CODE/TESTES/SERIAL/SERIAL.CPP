 /** Bibliotecas a serem utilizadas pelo modulo serial. ********************/
 #include <DOS.H>       /** Biblioteca de baixo nivel do sistema DOS. ******/
 #include <STDLIB.H>    /** Biblioteca de recursos melhorados. *************/
 #include "DRICA.H"     /** Biblioteca especifica do controlador. **********/
 #include <STRING.H>

 /** Fun‡ao: Configura a interface serial. *********************************/
 int serialconfig(int BaudRate, int Parity, int StopBits, int WordLenght,
		  int PortNumber)
 {
    int Auxiliar_1 = 0, Auxiliar_2 = 0, Auxiliar_3 = 0, Auxiliar_4 = 0;
    char Auxiliar_5[16], Auxiliar_6[16];
    int Aux = 0;
    union REGS regs;
    regs.h.ah = 0x0;  /** Servi‡o que configura a interface serial. ********/
    switch(BaudRate)  /** Captura da taxa de transferencia. ****************/
    {
       case 110:
	  Auxiliar_1 = 0;
          break;
       case 150:
	  Auxiliar_1 = 32;
          break;
       case 300:
	  Auxiliar_1 = 64;
          break;
       case 600:
	  Auxiliar_1 = 96;
          break;
       case 1200:
	  Auxiliar_1 = 128;
	  break;
       case 2400:
	  Auxiliar_1 = 160;
          break;
       case 4800:
	  Auxiliar_1 = 192;
          break;
       case 9600:
	  Auxiliar_1 = 224;
          break;
       default: break;
    }
    switch(Parity)  /** Captura da paridade. *******************************/
    {
       case 0:
          Auxiliar_2 = 0;
	  break;
       case 1:
	  Auxiliar_2 = 8;
	  break;
       case 2:
	  Auxiliar_2 = 24;
	  break;
       default: break;
    }
    switch(StopBits)  /** Captura dos bits de parada. **********************/
    {
       case 1:
          Auxiliar_3 = 0;
	  break;
       case 2:
          Auxiliar_3 = 4;
	  break;
       default: break;
    }
    switch(WordLenght)  /** Captura tamanho da palavra. ********************/
    {
       case 7:
	  Auxiliar_4 = 2;
	  break;
       case 8:
	  Auxiliar_4 = 3;
	  break;
       default: break;
    }
    Aux = Auxiliar_1 + Auxiliar_2 + Auxiliar_3 + Auxiliar_4;
    regs.h.al = Aux;  /** Dados de configura‡ao da interface serial. *******/
    regs.x.dx = PortNumber;  /** Porta de comunica‡ao, COM1, 2, 3, 4. ******/
    int86(0x14, &regs, &regs);  /** Executa interrup‡ao 14 do BIOS. ********/
    itoa(regs.h.ah, Auxiliar_5, 2);  /** Retorna dado obtido pela fun‡ao. **/
    ChkVarLenght:
    if(strlen(Auxiliar_5) < 8)
    {
       strcpy(Auxiliar_6, Auxiliar_5);
       strcpy(Auxiliar_5, "0");
       strcat(Auxiliar_5, Auxiliar_6);
       if(strlen(Auxiliar_5) < 8) { goto ChkVarLenght; }
    }
    if(Auxiliar_5[0] == '0') { return(OK); }
    else { return(ERROR); }
 }


 /** Fun‡ao: Retorna os dados sobre a porta serial. ************************/
 int serialstatus(int PortNumber)
 {
    union REGS regs;
    regs.h.ah = 0x3;  /** Servi‡o que verifica status da porta serial. *****/
    regs.x.dx = PortNumber;  /** Porta de comunica‡ao, COM1, 2, 3, 4. ******/
    int86(0x14, &regs, &regs);  /** Executa interrup‡ao 14 da BIOS. ********/
    return(regs.h.ah);  /** Retorna dado obtido pela fun‡ao. ***************/
 }


 /** Fun‡ao: Envia um caracter pela interface serial. **********************/
 int serialsend(int Caracter, int PortNumber)
 {
    char Auxiliar_1[16], Auxiliar_2[16];
    union REGS regs;
    regs.h.ah = 0x1;  /** Servi‡o que manda um caracter pela interface. ****/
    regs.h.al = Caracter;  /** Caracter a ser enviado pela interface. ******/
    regs.x.dx = PortNumber;  /** Porta de comunica‡ao, COM1, 2, 3, 4. ******/
    int86(0x14, &regs, &regs);  /** Executa interrup‡ao 14 da BIOS. ********/
    itoa(regs.h.ah, Auxiliar_2, 2);  /** Retorna dado obtido pela fun‡ao. **/
    ChkVarLenght:
    if(strlen(Auxiliar_1) < 8)
    {
       strcpy(Auxiliar_2, Auxiliar_1);
       strcpy(Auxiliar_1, "0");
       strcat(Auxiliar_1, Auxiliar_2);
       if(strlen(Auxiliar_1) < 8) { goto ChkVarLenght; }
    }
    if(Auxiliar_2[0] == '0') { return(regs.x.ax); }
    else { return(ERROR); }
 }


 /** Fun‡ao: Verifica se ha algum caracter na interface serial. ************/
 int serialrecive(int PortNumber)
 {
    char Auxiliar_1[16], Auxiliar_2[16];
    union REGS regs;
    regs.h.ah = 0x2;  /** Servi‡o que recebe um caracter pela interface. ***/
    regs.x.dx = PortNumber;  /** Porta de comunica‡ao, COM1, 2, 3, 4. ******/
    int86(0x14, &regs, &regs);  /** Executa interrup‡ao 14 da BIOS. ********/
    itoa(regs.h.ah, Auxiliar_1, 2);
    ChkVarLenght:
    if(strlen(Auxiliar_1) < 8)
    {
       strcpy(Auxiliar_2, Auxiliar_1);
       strcpy(Auxiliar_1, "0");
       strcat(Auxiliar_1, Auxiliar_2);
       if(strlen(Auxiliar_1) < 8) { goto ChkVarLenght; }
    }
    if(Auxiliar_1[0] == '0') { return(regs.h.al); }
    else { return(ERROR); }
 }
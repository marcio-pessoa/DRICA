 /** Bibliotecas a serem utilizadas pelo modulo GENERIC.CPP. ***************/
 #include <STDLIB.H>    /** Biblioteca de recursos melhorados. *************/
 #include <STRING.H>    /** Biblioteca de manipula‡ao de strings. **********/
 #include <STDIO.H>     /** Biblioteca de recursos melhorados. *************/
 #include <CONIO.H>     /** Biblioteca de recursos extendidos. *************/
 #include <DOS.H>       /** Biblioteca de baixo nivel do sistema DOS. ******/
 #include "DRICA.H"     /** Biblioteca especifica do controlador. **********/
 #include "\WIZ\LIBRARY\WIZ.H"  /** Biblioteca especifica Wizards soft. ****/


 /** Fun‡ao: Ajuda sobre o controlador. ************************************/
 int ajuda(char command[8])
 {

    /** Ajuda geral de todos os comandos. **********************************/
    if(strcmp(command, "") == 0)
    {
       fputs("Listando comandos disponiveis..."
	     "\nabout    \t caljoy    \t chkjoy   \t chkline  \t chkmouse"
	     "\nchkrs232 \t clear     \t close    \t control  \t delay"
	     "\nhelp     \t joymap    \t kbrate   \t keybmap  \t load"
	     "\nloop     \t mousemap  \t nport    \t quit     \t repeat"
	     "\nreset    \t run       \t sensomap \t single   \t system"
	     "\ntmouse   \t today"
	     "\n", stdout);
    }
    /** Ajuda do comando "about". ******************************************/
    if(strcmp(command, "about") == 0)
    {
       fputs("about    - Informa‡oes sobre o controlador (versao, fabric., etc.).", stdout);
    }
    /** Ajuda do comando "clear". ******************************************/
    if(strcmp(command, "clear") == 0)
    {
       fputs("clear    - Limpa a tela.", stdout);
    }
    /** Ajuda do comando "today". ******************************************/
    if(strcmp(command, "today") == 0)
    {
       fputs("today    - Exibe o dia e a hora do sistema.", stdout);
    }
    /** Ajuda do comando "port". *******************************************/
    if(strcmp(command, "port") == 0)
    {
       fputs("port     - Define a porta a ser utilizada (LPTx, COMx).", stdout);
    }
    /** Ajuda do comando "delay". ******************************************/
    if(strcmp(command, "delay") == 0)
    {
       fputs("delay    - Ajusta o tempo entre os pulsos de saida.", stdout);
    }
    /** Ajuda do comando "repeat". *****************************************/
    if(strcmp(command, "repeat") == 0)
    {
       fputs("repeat   - Ajusta o numero de vezes que e repetido um pulso de saida.", stdout);
    }
    /** Ajuda do comando "loop". *******************************************/
    if(strcmp(command, "loop") == 0)
    {
       fputs("loop     - Define o numero de repeti‡oes do programa.", stdout);
    }
    /** Ajuda do comando "control". ****************************************/
    if(strcmp(command, "control") == 0)
    {
       fputs("control  - Define os meios de entrada utilizados pelo controlador.", stdout);
    }
    /** Ajuda do comando "caljoy". *****************************************/
    if(strcmp(command, "caljoy") == 0)
    {
       fputs("caljoy   - Calibra o joystick.", stdout);
    }
    /** Ajuda do comando "chkjoy". *****************************************/
    if(strcmp(command, "chkjoy") == 0)
    {
       fputs("chkjoy   - Verifica a existencia de um joystick.", stdout);
    }
    /** Ajuda do comando "chkmouse". ***************************************/
    if(strcmp(command, "chkmouse") == 0)
    {
       fputs("chkmouse - Verifica a existencia de um mouse.", stdout);
    }
    /** Ajuda do comando "chkrs232". ***************************************/
    if(strcmp(command, "chkrs232") == 0)
    {
       fputs("chkrs232 - Verifica a existencia e a quantidade de portas seriais.", stdout);
    }
    /** Ajuda do comando "chkline". ****************************************/
    if(strcmp(command, "chkline") == 0)
    {
       fputs("chkline  - Verifica a existencia e a quantidade de portas paralelas.", stdout);
    }
    /** Ajuda do comando "tmouse". *****************************************/
    if(strcmp(command, "tmouse") == 0)
    {
       fputs("tmouse   - Testa mouse.", stdout);
    }
    /** Ajuda do comando "load". *******************************************/
    if(strcmp(command, "load") == 0)
    {
       fputs("load     - Carrega um programa DRICA - *.WPG.", stdout);
    }
    /** Ajuda do comando "close". ******************************************/
    if(strcmp(command, "close") == 0)
    {
       fputs("close    - Fecha um programa que foi carregado.", stdout);
    }
    /** Ajuda do comando "reset". ******************************************/
    if(strcmp(command, "reset") == 0)
    {
       fputs("reset    - Carrega o conteudo dos arquivos de configura‡ao originais.", stdout);
    }
    /** Ajuda do comando "    ". *******************************************/
    if(strcmp(command, "kbrate") == 0)
    {
       fputs("kbrate   - Ajusta intermitencia do cursor.", stdout);
    }
    /** Ajuda do comando "single". *****************************************/
    if(strcmp(command, "single") == 0)
    {
       fputs("single   - Executa modo texto simples, semelhante ao modo grafico.", stdout);
    }
    /** Ajuda do comando "run". *******************************************/
    if(strcmp(command, "run") == 0)
    {
       fputs("run      - Executa programa ou comandos on-line.", stdout);
    }
    /** Ajuda do comando "keybmap". ****************************************/
    if(strcmp(command, "keybmap") == 0)
    {
       fputs("keybmap  - Exibe mapa do teclado.", stdout);
    }
    /** Ajuda do comando "mousemap". ***************************************/
    if(strcmp(command, "mousemap") == 0)
    {
       fputs("mousemap - Exibe mapa do mouse.", stdout);
    }
    /** Ajuda do comando "joymap". *****************************************/
    if(strcmp(command, "joymap") == 0)
    {
       fputs("joymap   - Exibe mapa do joystick.", stdout);
    }
    /** Ajuda do comando "sensomap". ***************************************/
    if(strcmp(command, "sensomap") == 0)
    {
       fputs("sensomap - Exibe mapa dos sensores.", stdout);
    }
    /** Ajuda do comando "help". *******************************************/
    if(strcmp(command, "help") == 0)
    {
       fputs("help     - Exibe ajuda sobre o modo texto do controlador.", stdout);
    }
    /** Ajuda do comando "system". *****************************************/
    if(strcmp(command, "system") == 0)
    {
       fputs("system   - Chama o interpretador de comandos.", stdout);
    }
    /** Ajuda do comando "quit". *******************************************/
    if(strcmp(command, "quit") == 0)
    {
       fputs("quit     - Sai do controlador.", stdout);
    }

    fputs("\n", stdout);

    return(OK);
 }


 /** Fun‡ao: Exibe o dia e a hora. *****************************************/
 int today()
 {
    char dia[4], mes[16], ano[8];
    char hora[8], minuto[8], segundo[8];
    char horario[32], diario[32];
    struct time t;
    struct date d;

    getdate(&d);
    itoa(d.da_day, dia, 10);
    itoa(d.da_year, ano, 10);
    switch (d.da_mon)
    {
       case 1:
	  strcpy(mes, "janeiro");
	  break;
       case 2:
	  strcpy(mes, "fevereiro");
	  break;
       case 3:
	  strcpy(mes, "mar‡o");
	  break;
       case 4:
	  strcpy(mes, "abril");
	  break;
       case 5:
	  strcpy(mes, "maio");
	  break;
       case 6:
	  strcpy(mes, "junho");
	  break;
       case 7:
	  strcpy(mes, "julho");
	  break;
       case 8:
	  strcpy(mes, "agosto");
	  break;
       case 9:
	  strcpy(mes, "setembro");
	  break;
       case 10:
	  strcpy(mes, "outubro");
	  break;
       case 11:
	  strcpy(mes, "novembro");
	  break;
       case 12:
	  strcpy(mes, "dezembro");
	  break;
       default: break;
    }

    strcpy(diario, dia);
    strcat(diario, " de ");
    strcat(diario, mes);
    strcat(diario, " de ");
    strcat(diario, ano);
    strcat(diario, ".");

    gettime(&t);
    itoa(t.ti_hour, hora, 10);
    itoa(t.ti_min, minuto, 10);
    itoa(t.ti_sec, segundo, 10);
    strcpy(horario, "Hora: ");
    strcat(horario, hora);
    strcat(horario, ":");
    strcat(horario, minuto);
    strcat(horario, ":");
    strcat(horario, segundo);
    printf("Hoje, %s\n%s.\n", diario, horario);
    return(OK);
 }


 /** Funcao: Exibe moldura do modo texto. **********************************/
 int frame()
 {
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ "
	    "³                                                                             ³ "
	    "ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "³                                      ³                                      ³ "
	    "ÀÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÙ");
    /** Exibicao dos textos da moldura. ************************************/
    textcolor(WHITE);
    gotoxy(3,2);   cprintf("%s", TITLE);
    gotoxy(62,2);  cprintf("Single Text Mode");
    gotoxy(17,4);  cprintf("TECLADO");
    gotoxy(56,4);  cprintf("SENSORES");
    gotoxy(17,15); cprintf("JOYSTICK");
    gotoxy(57,15); cprintf("MOUSE");
    gotoxy(9,17);  cprintf("Up");
    gotoxy(9,19);  cprintf("Down");
    gotoxy(9,21);  cprintf("Right");
    gotoxy(9,23);  cprintf("Left");
    gotoxy(27,20); cprintf("Fire 1");
    gotoxy(27,22); cprintf("Fire 2");
    gotoxy(64,20); cprintf("Button 1");
    gotoxy(64,22); cprintf("Button 2");

    /** Exibe barra de status. *********************************************/
    textcolor(BLACK);
    textbackground(LIGHTGRAY);
    gotoxy(48,25); cprintf("³ ESCAPE encerra, ENTER pausa.");
    return(OK);
 }


 /** Funcao: Exibe conteudo da barra de status. ****************************/
 int genericstatus(char *Texto)
 {
    char Auxiliar_1[64];
    strcpy(Auxiliar_1, "Status: ");
    strcat(Auxiliar_1, Texto);
    /** Apaga texto de status anterior. ************************************/
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    gotoxy(3,25);
    printf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
    /** Exibe texto de status. *********************************************/
    textcolor(BLACK);
    textbackground(LIGHTGRAY);
    gotoxy(3,25);
    cprintf("%s", Auxiliar_1);
    return(OK);
 }


 int defaultvideo()
 {
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    return(OK);
 }


 /** Program notes. *********************************************************
 by: Marcio de Sousa Pessoa
 e-mail: marciomexicano@zipmail.com.br
 ***************************************************************************/
 /** Bibliotecas a serem utilizadas pelo controlador. **********************/
 #include <STDLIB.H>    /** Biblioteca de recursos melhorados. *************/
 #include <STRING.H>    /** Biblioteca de manipula‡ao de strings. **********/
 #include <CONIO.H>     /** Biblioteca de recursos extendidos. *************/
 #include <STDIO.H>     /** Biblioteca de recursos melhorados. *************/
 #include <DOS.H>       /** Biblioteca de baixo nivel do sistema DOS. ******/
 #include "DRICA.H"     /** Biblioteca especifica do controlador. **********/
 #include "\WIZ\LIBRARY\WIZ.H"  /** Biblioteca especifica Wizards soft. ****/


 /** Global: Declara‡ao das variaveis globais. *****************************/
 /** Dimensoes da tela. ****************************************************/
 int MaxScreen_xM = 0, MaxScreen_yM = 0, MidScreen_xM = 0, MidScreen_yM = 0;
 int MaxWindow_xM = 0, MaxWindow_yM = 0, MidWindow_xM = 0, MidWindow_yM = 0;
 /** Cores padrao de inicia‡ao. ********************************************/
 int AppWorkspaceM = 0;
 int BackgroundM = DARKGRAY, SelectorM = DARKGRAY, FrameM = BLACK;
 int WindowM = WHITE, ActiveWindowTextM = BLACK;
 int ActiveBorderM = LIGHTGRAY, ActiveTitleM = BLACK;
 int InactiveBorderM = 0, InactiveTitleM = 0, InactiveWindowTextM = 0;
 int ActiveObjectM = LIGHTGREEN, InactiveObjectM = GREEN;
 int ButtonFaceM = LIGHTGRAY, ButtonTextM = BLACK;
 int ButtonHilightM = WHITE, ButtonShadowM = DARKGRAY;
 int HilightM = LIGHTGRAY, HilightTextM = WHITE;
 int HilightWindowM = WHITE, HilightObjectM = WHITE;
 int ShadowM = BLACK, ShadowObjectM = BLACK;
 int ShadowTextM = BLACK, ShadowWindowM = DARKGRAY;
 int MenuM = WHITE, MenuTextM = BLACK, GrayTextM = LIGHTGRAY;
 /** Variaveis padrao de configura‡ao inicial. *****************************/
 int Wait = 0, Repeat = 0, Port = 0;
 /** Variaveis de anima‡ao, sons, entretenimento, etc. *********************/
 int AnimateM = 1, VerticalSizeButton = 19, Speaker = 0, Quit = FALSE;
 /** Defini‡ao do tamanho das variaveis de exibi‡ao de dados. **************/
 char Dado[32];
 char AdressWork[16]; //Essa variavel ‚ inutil
 char TimeWork[16];
 char RepeatWork[16];
 char Adress[8], Time[8], Emulation[8]; // Essas variaveis nao tem utiliza‡ao.
 /** Textos padrao de exibi‡ao inicial. ************************************/
 char InputMedia[17];
 char DeviceName[17];
 char ConfigurationFile[128];
 char DeviceInformationFile[128];
 char ProgramFile[128];
 /** Variaveis particulares ao dispositivo usado. **************************/
 char OutputName [17][128];
 int OutputAction [128];
 char SensorName [25][128];
 int SensorAction [128];
 char KeybName [8][128];
 int KeybAction [128];
 char KeybNameMap[9][128];
 int DeviceInterfaceCombinations = 8;
 /** Variaveis da porta paralela. ******************************************/
 int ParalelNumber = 0;
 /** Variaveis dos dispositivos de entrada de dados. ***********************/
 int Keyboard = FALSE, Mouse = FALSE, Joystick = FALSE, Serial = FALSE;
 /** Variaveis do teclado. *************************************************/
 int KeyboardEnable = FALSE;
 int LedNumbers = 8;
 /** Variaveis do mouse. ***************************************************/
 int MousePermission = FALSE;
 int MouseEnable = FALSE;
 int Mouse_x = 0, Mouse_y = 0;
 int MouseScanDelay = 40;
 int OldMouseb0 = 0, OldMouseb1 = 0;
 int MouseRIGHT[3], MouseLEFT[3], MouseUP[3], MouseDOWN[3];
 char MouseButton0Name[15], MouseButton1Name[15];
 /** Variaveis do joystick. ************************************************/
 int JoystickPermission = FALSE;
 int JoystickEnable = FALSE;
 int JoystickWait = 30;
 int Joystick_x = 0, Joystick_y = 0;
 int JoystickRIGHT[3], JoystickLEFT[3], JoystickUP[3], JoystickDOWN[3];
 int JoyFire0 = 0, JoyFire1 = 0;
 int JoyCenter_x = 0, JoyCenter_y = 0;
 int JoyCrossRIGHT = 0;
 int JoyCrossLEFT = 0;
 int JoyCrossUP = 0;
 int JoyCrossDOWN = 0;
 int OldJoyFire0 = 0, OldJoyFire1 = 0;
 char JoystickFire0Name[15], JoystickFire1Name[15];
 /** Variaveis do da interface serial. *************************************/
 int SerialPermission = FALSE;
 int SerialEnable = FALSE;
 int SerialNumber = 0;
 int StartUpSerialInLogon = 0;
 /** Variaveis dos sensores. ***********************************************/
 int LastSensor = 0;


 /**************************************************************************/
 /**                                                                      **/
 /**                  FUN€OES USADAS PELO CONTROLADOR                     **/
 /**                                                                      **/
 /**************************************************************************/


 /** Fun‡oes do modulo MESSAGES.CPP. ***************************************/
 int beep(int opcao);
 int about();
 /** Fun‡oes do modulo MOUSE.CPP. ******************************************/
 int mousepresente();
 int colmouse();
 int linmouse();
 int ligamouse();
 int desligamouse();
 int statusmouse();
 int gotoxymouse(int col, int lin);
 /** Fun‡oes do modulo JOYSTICK.CPP. ***************************************/
 int joystickchk();
 int coljoystick(int opcao);
 int linjoystick(int opcao);
 int statusjoystick(int opcao);
 /** Fun‡oes do modulo GENEREIC.CPP. ***************************************/
 int ajuda(char command[8]);
 int today();
 int frame();
 int genericstatus(char *Texto);
 int defaultvideo();
 /** Fun‡oes do modulo PARALEL.CPP. ****************************************/
 int paralelnumber();
 int input(int PortNumber);
 int output(int opcao, int PortNumber);
 /** Fun‡oes do modulo KEYBOARD.CPP. ***************************************/
 int kbrate(float rate, int delay);
 /** Fun‡oes do modulo RS232.CPP. ******************************************/
 int RS232number();
 int RS232config(int BaudRate, int Parity, int StopBits, int WordLenght,
		  int PortNumber);
 int RS232status(int PortNumber);
 int RS232send(int Caracter, int PortNumber);
 int RS232recive(int PortNumber);
 /** Fun‡oes referentes as jenelas. ****************************************/
 int endereco();
 int base_time();
 int correcao();
 int colors();
 int animacao();
 int keybspeed();
 int mousespeed();
 int chkcontrol();
 int selectcontrol();//int opcao);
 int configcontrol();
 int config();
 int sobre();
 int sair();
 int menu();
 /** Fun‡oes referentes aos dispoditivos de entrada. ***********************/
 int mousemap();
 int mouse(int opcao);
 int keybmap(int opcao);
 int keyboard(int Tecla1);
 int caljoy();
 int joymap();
 int joyfire();
 int joystick(int opcao);
 int sensomap();
 int sensor(int opcao);
 /** Fun‡oes referentes a leitura e grava‡ao em disco. *********************/
 int load(char Arquivo[16], char Argumento[16]);
 int configuracao();
 int aspectos();
 /** Fun‡oes referentes ao modulo TEXTO.CPP. *******************************/
 void setcursor (int Start, int End);

 int reset_variaveis();
 int limpa();
 int apresentacao();
 int iniciar();
 int genericmode();


 /**************************************************************************/
 /**                                                                      **/
 /**                       FUN€AO PRINCIPAL MAIN                          **/
 /**                                                                      **/
 /**************************************************************************/


 /** Fun‡ao: Fun‡ao principal - main. **************************************/
 main(int argc, char *argv[])
 {
    int Contador_1 = 0;
    char Auxiliar_1[11][11];
    int Exibition = 1;

    /** Reseta as variaveis. ***********************************************/
    reset_variaveis();

    /** Se nao houver argumentos na linha de comando. **********************/
    for(Contador_1 = 0; Contador_1 < argc; Contador_1 ++)
    {
       strcpy(Auxiliar_1[Contador_1], argv[Contador_1]);
       strupr(Auxiliar_1[Contador_1]);
       printf("Entrada %d= \"%s\".\n", Contador_1, Auxiliar_1[Contador_1]);
       /** Verifica entradas absurdas. *************************************/
       if(argc > 3)
       {
	  fputs("Erro: Entradas invalidas. Tente novamente com menos op‡oes.\n", stdout);
	  return(ERROR);
       }
       /** Verifica se deve iniciar em modo BW80 ou COLOR. *****************/
       if(strcmp("/BW80", Auxiliar_1[Contador_1]) == 0)
       {
	  Exibition = 0;
       }
       /** Se for requisitado a op‡ao de ajuda na linha de comandos. *******/
       if(strcmp("/?", Auxiliar_1[Contador_1]) == 0 ||
	  strcmp("/H", Auxiliar_1[Contador_1]) == 0)
       {
	  about();
	  fputs("Controlador de dispositivos Wizards.\n\n"
		"GENERIC [device] [/?] [/h] [BW80] [COLOR]\n\n"
		"  device     Nome do arquivo de dispositivo.\n"
		"  /? /H      Exibe esta tela de ajuda.\n"
		"  [BW80]     Inicia com tela monocromatica (default).\n"
		"  [COLOR]    Inicia com tela colorida.\n\n", stdout);
	  return(OK);
       }
    }
    /** Executa opcoes da linha de comando. ********************************/
    if(Exibition == 1)
    {
       fputs("\nModo texto colorido habilitado.", stdout);
    }
    else
    {
       fputs("\nModo texto BW80 habilitado.", stdout);
    }
    /** Carrega as configuracoes gravadas em arquivo. **********************/
    printf("\nAguarde. Carregando arquivos...");
    configuracao();
    aspectos();
    printf("\nConcluindo inicia‡ao...\n");
    /** Verifica a existencia de um mouse. *********************************/
    MousePermission = mousepresente();
    /** Verifica a existencia de joystick. *********************************/
    JoystickPermission = joystickchk();
    /** Verifica se exitem portas seriais dispon¡veis para remoto. *********/
    if((SerialNumber = RS232number()) > 0) { SerialPermission = TRUE; }
    else { SerialPermission = FALSE; }
    /** Verifica se existem portas paralelas livres para dispositivo. ******/
    ParalelNumber = paralelnumber();
    /** Verifica quais dispositivos estao prontos para utiliza‡Æo. *********/
    selectcontrol();
    genericmode();
    /** Finaliza execu‡ao do controlador. **********************************/
    about();
    return(OK);
 }


 /** Fun‡ao: Reseta variaveis do controlador. ******************************/
 int reset_variaveis()
 {
    int Contador_1 = 0;
    /** Textos padrao de exibi‡ao inicial. *********************************/
    strcpy(DeviceName, "sem nome");
    strcpy(InputMedia, "Todos");
    strcpy(ConfigurationFile, "DRICA.INI");
    strcpy(DeviceInformationFile, "sem-nome");
    strcpy(ProgramFile, "sem-nome");
    /** Reseta variaveis de exibi‡ao. **************************************/
    Speaker = 0;
    Dado[0] = '\0';
    AdressWork[0] = '\0';
    TimeWork[0] = '\0';
    RepeatWork[0] = '\0';
    Adress[0] = '\0';
    Time[0] = '\0';
    Emulation[0] = '\0';
    /** Reseta variaveis do teclado e das saidas. **************************/
    for(Contador_1 = 0; Contador_1 <= 128; Contador_1 ++)
    {
       OutputName[0][Contador_1] = '\0';
       SensorName[0][Contador_1] = '\0';
       OutputAction[Contador_1] = 0;
       SensorAction[Contador_1] = 0;
       KeybName[0][Contador_1] = '\0';
       KeybAction[Contador_1] = 0;
    }
    /** Reseta variaveis do mouse e do joystick. ***************************/
    for(Contador_1 = 0; Contador_1 <= 4; Contador_1 ++)
    {
       MouseRIGHT[Contador_1] = 0;
       MouseLEFT[Contador_1] = 0;
       MouseUP[Contador_1] = 0;
       MouseDOWN[Contador_1] = 0;
       JoystickRIGHT[Contador_1] = 0;
       JoystickLEFT[Contador_1] = 0;
       JoystickUP[Contador_1] = 0;
       JoystickDOWN[Contador_1] = 0;
    }
    /** Reseta variaveis do mouse. *****************************************/
    MouseButton0Name[0] = '\0';
    MouseButton1Name[0] = '\0';
    JoystickFire0Name[0] = '\0';
    JoystickFire1Name[0] = '\0';

    /** !!!!!!!!!!!!!!!!!!! apague isso agora !!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    Keyboard = TRUE, Mouse = TRUE, Joystick = TRUE, Serial = TRUE;

    return(OK);
 }


 /** Fun‡ao - LOAD: Carrega os Dados contidos no arquivo. ******************/
 int load(char Arquivo[16], char Argumento[16])
 {
    FILE *fptr;

    int Caracter = 0;
    int Tamanho_da_Linha = 0;
    int Tamanho_do_Comando = 0;
    int Tamanho_do_Dado = 0;
    int Contador = 0;
    int Retorna = 0;
    char Linha_de_Comando[128];
    char Acumulador_de_Caracter[1];
    char Auxiliar_de_Texto[128];
    char Comando[128];

    strcpy(Linha_de_Comando, '\0');
    strcpy(Acumulador_de_Caracter, '\0');
    strcpy(Comando, '\0');
    strcpy(Dado, '\0');
    strcpy(Auxiliar_de_Texto, '\0');

    /** Abre o arquivo. Se nao conseguir, executa conteudo do IF. **********/
    if((fptr = fopen(Arquivo, "r")) == NULL)
    {
       printf("\nNao foi possivel abrir o arquivo %s.", Arquivo);
       printf("\nPressione qualquer tecla para continuar...\n");
       getch();
       return(ERROR);
    }

    /** Le dados do arquivo ate chegar ao seu fim. *************************/
    while((Caracter = getc(fptr)) != EOF){
       *Acumulador_de_Caracter = Caracter;
       Acumulador_de_Caracter[1] = '\0';
       strcat(Linha_de_Comando, Acumulador_de_Caracter);
       /** Se for detectado pulo de linha executa conteudo. ****************/
       if(Caracter == '\n')
       {
	  Tamanho_da_Linha = strlen(Linha_de_Comando) - 1;
	  Linha_de_Comando[Tamanho_da_Linha] = '\0';

	  /** Sequencia de extra‡ao da palavra de comando da linha. ********/
	  for(Contador = 0; Contador < Tamanho_da_Linha; Contador++)
	  {
	     /** Inicia extra‡ao do comando da linha de comando. ***********/
	     *Acumulador_de_Caracter = Linha_de_Comando[Contador];
	     Acumulador_de_Caracter[1] = '\0';
	     strcat(Comando, Acumulador_de_Caracter);
	     Tamanho_do_Comando = strlen(Comando) - 1; /** COMANDO - '='. **/
	     /** Extrai o comando puro da linha de comando. ****************/
	     if(Linha_de_Comando[Contador] == '=')
	     {
		Comando[Tamanho_do_Comando] = '\0'; /** COMANDO - '='. *****/
		strcpy (Auxiliar_de_Texto, Comando);
	     }
	  }
	  strcpy(Comando, Auxiliar_de_Texto);
	  strcpy(Auxiliar_de_Texto, '\0');
	  /** Sequencia de extra‡ao do dado da linha de comando. ***********/
	  for(Contador = Tamanho_da_Linha; Contador > 0; Contador--)
	  {
	     /** Inicia extra‡ao do dado da linha de comando. **************/
	     *Acumulador_de_Caracter = Linha_de_Comando[Contador];
	     Acumulador_de_Caracter[1] = '\0';
	     strcat(Auxiliar_de_Texto, Acumulador_de_Caracter);
	     Tamanho_do_Dado = strlen(Auxiliar_de_Texto) - 1; /** DADO-'='.*/
	     /** Extrai o dado invertido puro da linha de comando. *********/
	     if(Linha_de_Comando[Contador] == '=')
	     {
		Auxiliar_de_Texto[Tamanho_do_Dado] = '\0'; /** DADO -'='. **/
		strcpy (Dado, Auxiliar_de_Texto);
	     }
	  }
	  strcpy(Auxiliar_de_Texto, '\0');
	  /** Sequencia de inversao do dado. *******************************/
	  Tamanho_do_Dado = strlen(Dado);
	  for(Contador = Tamanho_do_Dado; Contador >= 0; Contador--)
	  {
	     *Acumulador_de_Caracter = Dado[Contador];
	     Acumulador_de_Caracter[1] = '\0';
	     strcat(Auxiliar_de_Texto, Acumulador_de_Caracter);
	  }
	  strcpy(Dado, Auxiliar_de_Texto);
	  strcpy(Auxiliar_de_Texto, '\0');
	  if(strcmp(Comando, " ")  == 0 ||
	     strcmp(Comando, "")   == 0 ||
	     strcmp(Comando, "\t") == 0 ||
	     strcmp(Comando, "\n") == 0)
	  {
	     strcpy(Comando, '\0');
	     strcpy(Dado, '\0');
	  }
	  strcpy(Comando, strupr(Comando));
	  strcpy(Argumento, strupr(Argumento));
	  if(strcmp(Argumento, Comando) == 0)
	  {
	     Retorna = atoi(Dado);
	     /** Fecha arquivo. ********************************************/
	     fclose(fptr);
	     /** Zera as variaveis utilizadas no processo. *****************/
	     Caracter = 0;
	     Contador = 0;
	     strcpy(Argumento, '\0');
	     strcpy(Acumulador_de_Caracter, '\0');
	     strcpy(Auxiliar_de_Texto, '\0');
	     strcpy(Linha_de_Comando, '\0');
	     strcpy(Comando, '\0');
	     return(Retorna);
	  }
	  /** Zera as variaveis utilizadas no processo. ********************/
	  Caracter = 0;
	  Contador = 0;
	  strcpy(Acumulador_de_Caracter, '\0');
	  strcpy(Auxiliar_de_Texto, '\0');
	  strcpy(Linha_de_Comando, '\0');
	  strcpy(Comando, '\0');
	  strcpy(Dado, '\0');
       }
    }
    /** Fecha arquivo. *****************************************************/
    fclose(fptr);
    return(ERROR);
 }


 /** Fun‡ao: Limpa tela. ***************************************************/
 int limpa()
 {
    clrscr();
    return(OK);
 }


 /** Fun‡ao: Configura‡ao do endereco a ser lido. **************************/
 int endereco()
 {
    printf("O dispositivo esta localizado no endere‡o %xH.\n", Port);
    printf("Entre com o novo endere‡o: ");
    scanf("%x", &Port);

    return(OK);
 }


 /** Fun‡ao: Base de Tempo. ************************************************/
 int base_time()
 {
    printf("A base de tempo utilizada no momento ‚: %d miliseg.\n", Wait);
    printf("Entre com a nova base de tempo: ");
    scanf("%d", &Wait);

    return(OK);
 }


 /** Fun‡ao: Corre‡ao de Tempo. ********************************************/
 int correcao()
 {
    printf("A repeti‡ao dos pulsos esta ajustada da seguinte forma: %d vezes.\n", Repeat);
    printf("Entre com a nova taxa de repeti‡ao: ");
    scanf("%d", &Repeat);

    return(OK);
 }


 /** Ajusta intermitencia do cursor do teclado. ****************************/
 int keybspeed()
 {
    int Velocidade = 0, Atrazo = 0;

    printf("Entre com a nova taxa de intermitencia.\n");
    printf("Velocidade: ");
    scanf("%d", &Velocidade);
    printf("Atrazo: ");
    scanf("%d", &Atrazo);
    kbrate(Velocidade, Atrazo);

    return(ERROR);
 }


 /** Ajusta tempo de varredura do mouse. ***********************************/
 int mousespeed()
 {
/*    int MinDelay = 0;
    int MaxDelay = 99;
    int Contador_1 = MouseScanDelay;
    char DelayInMiliseg[32];
    int Tecla_1 = 0, Tecla_2 = 0;

    explica("Ajusta tempo de varredura do mouse.");
    janela(35, 60, 310, 190, 0, "Ajustar mouse");
    dimensao();
    /** Exibe dados da janela. *********************************************/
/*    print(1, 1, ActiveWindowTextM, "Curto");
    print(10, 1, ActiveWindowTextM, "Longo");
    itoa(Contador_1, DelayInMiliseg, 10);
    print(1, 4, ActiveWindowTextM, DelayInMiliseg);
    print(3, 4, ActiveWindowTextM, "milisegundos");
    crazy(MinDelay, MaxDelay, Contador_1,
	  2, 0,
	  25, 30, HORIZ_DIR);
    /** Exibe botao de conclusao de operacao. ******************************/
/*    botao(MaxWindow_xM - 40, MaxWindow_yM - VerticalSizeButton,
	  0, 0, 1, "OK");
    while((Tecla_1 = getch()) != -1)
       if(Tecla_1 == 0)
       {
	  Tecla_2 = getch();
	  switch(Tecla_2)
	  {
	     case LEFT:
		Contador_1 = Contador_1 - 1;
		if(Contador_1 < MinDelay) { Contador_1 = MinDelay; }
		crazy(MinDelay, MaxDelay, Contador_1,
		      2, 0,
		      25, 30, HORIZ_DIR);
		setfillstyle(1, WindowM);
		bar(19, 66, 35, 76);
		itoa(Contador_1, DelayInMiliseg, 10);
		print(1, 4, ActiveWindowTextM, DelayInMiliseg);
		break;
	     case RIGHT:
		Contador_1 = Contador_1 + 1;
		if(Contador_1 > MaxDelay) { Contador_1 = MaxDelay; }
		crazy(MinDelay, MaxDelay, Contador_1,
		      2, 0,
		      25, 30, HORIZ_DIR);
		setfillstyle(1, WindowM);
		bar(19, 66, 35, 76);
		itoa(Contador_1, DelayInMiliseg, 10);
		print(1, 4, ActiveWindowTextM, DelayInMiliseg);
		break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(Tecla_1)
	  {
	     case ENTER:
		MouseScanDelay = Contador_1;
		botao(MaxWindow_xM - 40, MaxWindow_yM - VerticalSizeButton,
		0, 1, 1, "OK");
		delay(100);
		limpa();
		return(OK);
	     case ESC:
		limpa();
		return(OK);
	     default: beep(Speaker);
	  }
    */
    return(OK);
 }


 /** Fun‡ao: Exibe mapa do mouse. ******************************************/
 int mousemap()
 {
    int Contador_1 = 0;
    char MouseRIGHTName[17];
    char MouseLEFTName[17];
    char MouseUPName[17];
    char MouseDOWNName[17];

    /** Verifica se o mouse pode ser executado. ****************************/
    if(mousepresente() == FALSE)
    {
       return(OK);
    }
    /** Verifica se mouse pode ser habilitado para funcaionar. *************/
    if(Mouse == FALSE)
    {
       printf("Nao foi possivel exibir mapa do mouse.\n");
       return(OK);
    }

    for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	Contador_1 ++)
    {
       if(MouseRIGHT[0] == OutputAction[Contador_1])
       {
	  strcpy(MouseRIGHTName, OutputName[Contador_1]);
       }
       if(MouseLEFT[0] == OutputAction[Contador_1])
       {
	  strcpy(MouseLEFTName, OutputName[Contador_1]);
       }
       if(MouseUP[0] == OutputAction[Contador_1])
       {
	  strcpy(MouseUPName, OutputName[Contador_1]);
       }
       if(MouseDOWN[0] == OutputAction[Contador_1])
       {
	  strcpy(MouseDOWNName, OutputName[Contador_1]);
       }
    }
    /** Exibe os dados do mapa do mouse. ***********************************/
    printf("       Botao 0  = %s\n       Botao 1  = %s\n",
	   MouseButton0Name, MouseButton1Name);
    printf("       Sobe     = %s\n       Desce    = %s\n       Direita  = %s\n       Esquerda = %s\n",
	   MouseUPName, MouseDOWNName,
	   MouseRIGHTName, MouseLEFTName);
    return(OK);
 }


 /** Fun‡ao: Mouse. ********************************************************/
 int mouse(int opcao)
 {
    int Mouseb0 = 0, Mouseb1 = 0;
    int MouseStartx = 320;
    int MouseStarty = 96;
    int Mouse_u[14], Mouse_d[14], Mouse_l[14], Mouse_r[14];

    textcolor(InactiveObjectM);
    textbackground(BLACK);
    /** Inicia dispositivo, exibindo sua aparencia. ************************/
    if(opcao == RESET){
       gotoxy(47,19); cprintf("Ü");  /** Banda superior do mouse. **********/
       gotoxy(47,21); cprintf("Ü");  /** Banda inferior do mouse. **********/
       gotoxy(49,20); cprintf("Ü");  /** Banda direita do mouse. ***********/
       gotoxy(45,20); cprintf("Ü");  /** Banda esquerda do mouse. **********/
       gotoxy(60,20); cprintf("ÜÜ");  /** B0 do mouse. *********************/
       gotoxy(60,22); cprintf("ÜÜ");  /** B1 do mouse. *********************/
       /** Desaciona botoes do mouse. **************************************/
       Mouseb0 = 0;
       Mouseb1 = 0;
       /** Botao b0. *******************************************************/
       gotoxy(60,20); cprintf("ÜÜ");  /** B0 do mouse. *********************/
       /** Botao b1. *******************************************************/
       gotoxy(60,22); cprintf("ÜÜ");  /** B1 do mouse. *********************/
       return(OK);
    }
    /** Verifica se o mouse pode ser executado. ****************************/
    if(MousePermission == FALSE)
    {
       return(OK);
    }
    /** Verifica se mouse pode ser habilitado para funcaionar. *************/
    if(Mouse == FALSE)
    {
       Mouseb0 = 0;
       Mouseb1 = 0;
       return(OK);
    }

    /** Coloca cursor do mouse numa posi‡ao especificada. ******************/
    gotoxymouse(MouseStartx, MouseStarty);
    /** Vefica se existe algum botao do mouse pressionado. *****************/
    switch(statusmouse())
    {
       case 0:
	  Mouseb0 = 0;
	  Mouseb1 = 0;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     textcolor(InactiveObjectM);
	     gotoxy(60,20); cprintf("ÜÜ");  /** B0 do mouse. ***************/
	     gotoxy(60,22); cprintf("ÜÜ");  /** B1 do mouse. ***************/
	  }
	  OldMouseb0 = Mouseb0;
	  OldMouseb1 = Mouseb1;
	  break;
       case 1:
	  Mouseb0 = 1;
	  Mouseb1 = 0;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     textcolor(ActiveObjectM);
	     gotoxy(60,20); cprintf("ÜÜ");  /** B0 do mouse. ***************/
	     textcolor(InactiveObjectM);
	     gotoxy(60,22); cprintf("ÜÜ");  /** B1 do mouse. ***************/
	  }
	  OldMouseb0 = Mouseb0;
	  OldMouseb1 = Mouseb1;
	  break;
       case 2:
	  Mouseb0 = 0;
	  Mouseb1 = 1;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     textcolor(InactiveObjectM);
	     gotoxy(60,20); cprintf("ÜÜ");  /** B0 do mouse. ***************/
	     textcolor(ActiveObjectM);
	     gotoxy(60,22); cprintf("ÜÜ");  /** B1 do mouse. ***************/
	  }
	  OldMouseb0 = Mouseb0;
	  OldMouseb1 = Mouseb1;
	  break;
       case 3:
	  Mouseb0 = 0;
	  Mouseb1 = 0;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     textcolor(InactiveObjectM);
	     gotoxy(60,20); cprintf("ÜÜ");  /** B0 do mouse. ***************/
	     gotoxy(60,22); cprintf("ÜÜ");  /** B1 do mouse. ***************/
	  }
	  OldMouseb0 = Mouseb0;
	  OldMouseb1 = Mouseb1;
	  break;
       default: break;
    }
    /** Inicia verifica‡ao da posi‡ao do mouse. ****************************/
    delay(MouseScanDelay);
    /** Verifica e executa movimento esquerdo do mouse. ********************/
    if(colmouse() < MouseStartx)
    {
       /** Seta esqueda acesa. *********************************************/
       textcolor(ActiveObjectM);
       gotoxy(45,20); cprintf("Ü");  /** Banda esquerda do mouse. **********/
       /** Envia pulso a saida. ********************************************/
       if(Mouseb0 == 0 && Mouseb1 == 0)
       {
	  output(MouseLEFT[0], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 1 && Mouseb1 == 0)
       {
	  output(MouseLEFT[1], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 0 && Mouseb1 == 1)
       {
	  output(MouseLEFT[2], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
    }
    else
    {
       /** Seta esqueda apagada. *******************************************/
       textcolor(InactiveObjectM);
       gotoxy(45,20); cprintf("Ü");  /** Banda esquerda do mouse. **********/
    }
    /** Verifica e executa movimento direito do mouse. *********************/
    if(colmouse() > MouseStartx)
    {
       /** Seta direita acesa. *********************************************/
       textcolor(ActiveObjectM);
       gotoxy(49,20); cprintf("Ü");  /** Banda direita do mouse. ***********/
       /** Envia pulso a saida. ********************************************/
       if(Mouseb0 == 0 && Mouseb1 == 0)
       {
	  output(MouseRIGHT[0], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 1 && Mouseb1 == 0)
       {
	  output(MouseRIGHT[1], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 0 && Mouseb1 == 1)
       {
	  output(MouseRIGHT[2], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
    }
    else
    {
       /** Seta direita apagada. *******************************************/
       textcolor(InactiveObjectM);
       gotoxy(49,20); cprintf("Ü");  /** Banda direita do mouse. ***********/
    }
    /** Verifica e executa movimento superior do mouse. ********************/
    if(linmouse() < MouseStarty)
    {
       /** Seta superior acesa. ********************************************/
       textcolor(ActiveObjectM);
       gotoxy(47,19); cprintf("Ü");  /** Banda superior do mouse. **********/
       /** Envia pulso a saida. ********************************************/
       if(Mouseb0 == 0 && Mouseb1 == 0)
       {
	  output(MouseUP[0], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 1 && Mouseb1 == 0)
       {
	  output(MouseUP[1], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 0 && Mouseb1 == 1)
       {
	  output(MouseUP[2], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
    }
    else
    {
       /** Seta superior apagada. ******************************************/
       textcolor(InactiveObjectM);
       gotoxy(47,19); cprintf("Ü");  /** Banda superior do mouse. **********/
    }
    /** Verifica e executa movimento inferior do mouse. ********************/
    if(linmouse() > MouseStarty)
    {
       /** Seta inferior acesa. ********************************************/
       textcolor(ActiveObjectM);
       gotoxy(47,21); cprintf("Ü");  /** Banda inferior do mouse. **********/
       /** Envia pulso a saida. ********************************************/
       if(Mouseb0 == 0 && Mouseb1 == 0)
       {
	  output(MouseDOWN[0], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 1 && Mouseb1 == 0)
       {
	  output(MouseDOWN[1], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
       if(Mouseb0 == 0 && Mouseb1 == 1)
       {
	  output(MouseDOWN[2], Port);
	  delay(Wait);
	  output(NULL, Port);
       }
    }
    else
    {
       /** Seta inferior apagada. ******************************************/
       textcolor(InactiveObjectM);
       gotoxy(47,21); cprintf("Ü");  /** Banda inferior do mouse. **********/
    }
    return(OK);
 }


 /** Fun‡ao: Mapa do teclado. **********************************************/
 int keybmap(int opcao)
 {
    int Contador_1 = 0;
    int Auxiliar_1 = 0, Auxiliar_2 = 0;
    char Auxiliar_3[8], Auxiliar_4[16];

    for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	Contador_1 ++)
    {
       /** Copia conteudo da variavel de teclas para a de exibicao. ********/
       strcpy(KeybNameMap[Contador_1], KeybName[Contador_1]);
       /** Detecta se a tecla do mapa e'especial ou nao. *******************/
       Auxiliar_1 = strlen(KeybName[Contador_1]);
       if(Auxiliar_1 == 1){
	  Auxiliar_2 = *KeybName[Contador_1];
	  KeybAction[Contador_1] = Auxiliar_2;
       }
       else
       {
	  strupr(KeybName[Contador_1]);
	  if(strcmp(KeybName[Contador_1], "UP") == 0)
	  {
	     KeybAction[Contador_1] = UP;
	  }
	  if(strcmp(KeybName[Contador_1], "DOWN") == 0)
	  {
	     KeybAction[Contador_1] = DOWN;
	  }
	  if(strcmp(KeybName[Contador_1], "LEFT") == 0)
	  {
	     KeybAction[Contador_1] = LEFT;
	  }
	  if(strcmp(KeybName[Contador_1], "RIGHT") == 0)
	  {
	     KeybAction[Contador_1] = RIGHT;
	  }
	  if(strcmp(KeybName[Contador_1], "PGUP") == 0)
	  {
	     KeybAction[Contador_1] = PGUP;
	  }
	  if(strcmp(KeybName[Contador_1], "PGDN") == 0)
	  {
	     KeybAction[Contador_1] = PGDN;
	  }
	  if(strcmp(KeybName[Contador_1], "INSERT") == 0)
	  {
	     KeybAction[Contador_1] = INSERT;
	  }
	  if(strcmp(KeybName[Contador_1], "DELETE") == 0)
	  {
	     KeybAction[Contador_1] = DELETE;
	  }
	  if(strcmp(KeybName[Contador_1], "HOME") == 0)
	  {
	     KeybAction[Contador_1] = HOME;
	  }
	  if(strcmp(KeybName[Contador_1], "END") == 0)
	  {
	     KeybAction[Contador_1] = END;
	  }
	  if(strcmp(KeybName[Contador_1], "F1") == 0)
	  {
	     KeybAction[Contador_1] = F1;
	  }
	  if(strcmp(KeybName[Contador_1], "F2") == 0)
	  {
	     KeybAction[Contador_1] = F2;
	  }
	  if(strcmp(KeybName[Contador_1], "F3") == 0)
	  {
	     KeybAction[Contador_1] = F3;
	  }
	  if(strcmp(KeybName[Contador_1], "F4") == 0)
	  {
	     KeybAction[Contador_1] = F4;
	  }
	  if(strcmp(KeybName[Contador_1], "F5") == 0)
	  {
	     KeybAction[Contador_1] = F5;
	  }
	  if(strcmp(KeybName[Contador_1], "F6") == 0)
	  {
	     KeybAction[Contador_1] = F6;
	  }
	  if(strcmp(KeybName[Contador_1], "F7") == 0)
	  {
	     KeybAction[Contador_1] = F7;
	  }
	  if(strcmp(KeybName[Contador_1], "F8") == 0)
	  {
	     KeybAction[Contador_1] = F8;
	  }
	  if(strcmp(KeybName[Contador_1], "F9") == 0)
	  {
	     KeybAction[Contador_1] = F9;
	  }
	  if(strcmp(KeybName[Contador_1], "F10") == 0)
	  {
	     KeybAction[Contador_1] = F10;
	  }
	  if(strcmp(KeybName[Contador_1], "F11") == 0)
	  {
	     KeybAction[Contador_1] = F11;
	  }
	  if(strcmp(KeybName[Contador_1], "F12") == 0)
	  {
	     KeybAction[Contador_1] = F12;
	  }
       }
       /** Coloca aspas no nome da tecla. **********************************/
       strcpy(Auxiliar_4, "'");
       strcat(Auxiliar_4, KeybNameMap[Contador_1]);
       strcat(Auxiliar_4, "'");
       strcpy(KeybNameMap[Contador_1], Auxiliar_4);
    }
    /** Exibe mapa do teclado. *********************************************/
    if(opcao != RESET)
    {
       for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	   Contador_1 ++)
       {
	  if(strcmp(KeybNameMap[Contador_1], "''") != 0)
	  {
	     printf("%d\t%s\t= %s\n", (Contador_1 + 1),
		     KeybNameMap[Contador_1], OutputName[Contador_1]);
	  }
       }
    }

    return(OK);
 }


 /** Fun‡ao: Teclado. ******************************************************/
 int keyboard(int Tecla1)
 {
    int Contador_1 = 0, Contador_2 = 0;
    int Tecla2 = 0;
    int KeybNameLenght = 0;
    char Ready[32];
    char Auxiliar_3[8], Auxiliar_4[16];

    textcolor(InactiveObjectM);
    textbackground(BLACK);
     /** Inicia dispositivo apenas exibindo seu mapa. ***********************/
    if(Tecla1 == RESET)
    {
       keybmap(RESET);
       for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	   Contador_1 ++)
       {
	  if(strcmp(KeybNameMap[Contador_1], "''") != 0 &&
	     Contador_1 < LedNumbers)
	  {
	     textcolor(InactiveObjectM);
	     gotoxy(3, Contador_1 + 6);   cprintf("±");
	     textcolor(WHITE);
	     gotoxy(5, Contador_1 + 6);
	     cprintf("%s", KeybNameMap[Contador_1]);
	     gotoxy(13, Contador_1 + 6);
	     cprintf("= %s", OutputName[Contador_1]);
	  }
       }
       return(OK);
    }
    /** Verifica se o teclado pode ser utilizado. **************************/
    if(Keyboard == FALSE)
    {
       return(OK);
    }
    /** Inicia a execu‡ao do dispositivo. **********************************/
    if(Tecla1 == 0)
    {
       Tecla2 = getch();
       switch(Tecla2)
       {
	  default:
	     for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
		 Contador_1 ++)
	     {
		KeybNameLenght = strlen(KeybName[Contador_1]);
		if(Tecla2 == KeybAction[Contador_1] && KeybNameLenght >= 2)
		{
		   for(Contador_2 = 0; Contador_2 <= Repeat; Contador_2 ++)
		   {
		      output(OutputAction[Contador_1], Port);
		      if(Contador_1 < LedNumbers)
		      {
/*			 print(2, 4 + Contador_1, ActiveObjectM,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, ActiveObjectM, "=");
			 print(7, 4 + Contador_1, ActiveObjectM,
			       OutputName[Contador_1]);
			 /** Acende led indicador. *************************/
			 textcolor(ActiveObjectM);
			 gotoxy(3, Contador_1 + 6);   cprintf("Û");
		      }
		      delay(Wait);
		      output(0, Port);
		      if(Contador_1 < LedNumbers)
		      {
/*			 print(2, 4 + Contador_1, HilightTextM,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, HilightTextM, "=");
			 print(7, 4 + Contador_1, HilightTextM,
			       OutputName[Contador_1]);
			 /** Apaga led indicador. **************************/
			 textcolor(InactiveObjectM);
			 gotoxy(3, Contador_1 + 6);   cprintf("±");
		      }
		      delay(Wait);
		   }
		}
	     }
	     break;
       }
    }
    else
    {
       switch(Tecla1)
       {
	  default:
	     for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
		 Contador_1 ++)
	     {
		KeybNameLenght = strlen(KeybName[Contador_1]);
		if(Tecla1 == KeybAction[Contador_1] && KeybNameLenght == 1)
		{
		   for(Contador_2 = 0; Contador_2 <= Repeat; Contador_2 ++)
		   {
		      output(OutputAction[Contador_1], Port);
		      if(Contador_1 < LedNumbers)
		      {
/*			 print(2, 4 + Contador_1, ActiveObjectM,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, ActiveObjectM, "=");
			 print(7, 4 + Contador_1, ActiveObjectM,
			       OutputName[Contador_1]);
			 /** Acende led indicador. *************************/
			 textcolor(ActiveObjectM);
			 gotoxy(3, Contador_1 + 6);   cprintf("Û");
		      }
		      delay(Wait);
		      output(0, Port);
		      if(Contador_1 < LedNumbers)
		      {
/*			 print(2, 4 + Contador_1, HilightTextM,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, HilightTextM, "=");
			 print(7, 4 + Contador_1, HilightTextM,
			       OutputName[Contador_1]);
			 /** Apaga led indicador. **************************/
			 textcolor(InactiveObjectM);
			 gotoxy(3, Contador_1 + 6);   cprintf("±");
		      }
		      delay(Wait);
		   }
		}
	     }
	     break;
       }
    }
    return(OK);
 }


 /** Fun‡ao: Calibra o joystick. *******************************************/
 int caljoy()
 {
    int tecla = 0;
    int OldJoyCenter_x = JoyCenter_x;
    int OldJoyCenter_y = JoyCenter_y;
    int JoyPos_x = 0, JoyPos_y = 0;
    int JoyPos_xMax = 0, JoyPos_yMax = 0;
    int JoyPos_xMin = 0, JoyPos_yMin = 0;
    int OldJoyCrossRIGHT = JoyCrossRIGHT;
    int OldJoyCrossLEFT = JoyCrossLEFT;
    int OldJoyCrossUP = JoyCrossUP;
    int OldJoyCrossDOWN = JoyCrossDOWN;

    limpa();
    printf("Processo de calibra‡ao do joystick.\n");
    printf("Mantenha o joystick centralizado e pressione algum botao dele.\n");
    while(statusjoystick(0) == 0)
    {
       /** Executa a tecla pressionada caso seja ESC. **********************/
       switch(tecla)
       {
	  case ESC:
	     printf("Foi cancelado o processo de calibra‡ao.\n");
	     JoyCenter_x = OldJoyCenter_x;
	     JoyCenter_y = OldJoyCenter_y;
	     return(OK);
	  default: break;
       }
       if(kbhit()) tecla = getch();
       /** Verifica qual o posicionamento do joystick. *********************/
       JoyCenter_x = coljoystick(0);
       JoyCenter_y = linjoystick(0);
       /** Exibe as cordenadas atuais do joystick. *************************/
       gotoxy(1,6);
       printf("x= %d, y= %d    \n", JoyCenter_x, JoyCenter_y);
    }
    gotoxy(1,3);
    printf("Direcione o joystick para todos os lados, entao pressione ENTER.\n");
    JoyPos_xMax = 1;
    JoyPos_yMax = 1;
    JoyPos_xMin = 500;
    JoyPos_yMin = 500;
    /** Inicia calibra‡ao. ****************************************************/
    while(TRUE){
       /** Verifica qual o posicionamento do joystick. *********************/
       JoyPos_x = coljoystick(0);
       JoyPos_y = linjoystick(0);
       /** Exibe as cordenadas atuais do joystick. *************************/
       gotoxy(1,6);
       printf("x= %d, y= %d    \n", JoyPos_x, JoyPos_y);
       /** Verifica qual o posicionamento maximo do joystick. **************/
       if(JoyPos_xMax < JoyPos_x) { JoyPos_xMax = JoyPos_x; }
       if(JoyPos_yMax < JoyPos_y) { JoyPos_yMax = JoyPos_y; }
       if(JoyPos_xMin > JoyPos_x) { JoyPos_xMin = JoyPos_x; }
       if(JoyPos_yMin > JoyPos_y) { JoyPos_yMin = JoyPos_y; }
       /** Verifica a area de operacao de cada bra‡o da cruz. **************/
       JoyCrossRIGHT = JoyPos_xMax - JoyCenter_x;
       JoyCrossLEFT = JoyCenter_x - JoyPos_xMin;
       JoyCrossUP = JoyCenter_y - JoyPos_yMin;
       JoyCrossDOWN = JoyPos_yMax - JoyCenter_y;
       /** Verifica se alguma tecla foi pressionada. ***********************/
       if(kbhit()) tecla = getch();
       /** Executa a tecla pressionada caso seja ENTER ou ESC. *************/
       switch(tecla)
       {
	  case ENTER:
	     JoyCrossRIGHT = JoyCrossRIGHT - 1;
	     JoyCrossDOWN = JoyCrossDOWN - 1;
	     return(OK);
	  case ESC:
	     JoyCenter_x = OldJoyCenter_x;
	     JoyCenter_y = OldJoyCenter_y;
	     JoyCrossRIGHT = OldJoyCrossRIGHT;
	     JoyCrossLEFT = OldJoyCrossLEFT;
	     JoyCrossUP = OldJoyCrossUP;
	     JoyCrossDOWN = OldJoyCrossDOWN;
	     return(OK);
	  default: break;
       }
    }
//    return(OK);
 }


 /** Fun‡ao: Exime mapa do joystick. ***************************************/
 int joymap()
 {
    int Contador_1 = 0;
    char JoystickRIGHTName[17];
    char JoystickLEFTName[17];
    char JoystickUPName[17];
    char JoystickDOWNName[17];

    /** Verifica se existe algum joystick no sistema. **********************/
    if(joystickchk() == FALSE)
    {
       return(OK);
    }
    /** Verifica se o joystick pode ser utilizado. *************************/
    if(Joystick == FALSE)
    {
       printf("Nao foi possivel exibir mapa do joystick.\n");
       return(OK);
    }

    for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	Contador_1 ++)
    {
       if(JoystickRIGHT[0] == OutputAction[Contador_1])
       {
	  strcpy(JoystickRIGHTName, OutputName[Contador_1]);
       }
       if(JoystickLEFT[0] == OutputAction[Contador_1])
       {
	  strcpy(JoystickLEFTName, OutputName[Contador_1]);
       }
       if(JoystickUP[0] == OutputAction[Contador_1])
       {
	  strcpy(JoystickUPName, OutputName[Contador_1]);
       }
       if(JoystickDOWN[0] == OutputAction[Contador_1])
       {
	  strcpy(JoystickDOWNName, OutputName[Contador_1]);
       }
    }
    printf("       Botao 0  = %s\n       Botao 1  = %s\n",
	   JoystickFire0Name, JoystickFire1Name);
    printf("       Sobe     = %s\n       Desce    = %s\n       Direita  = %s\n       Esquerda = %s\n",
	   JoystickUPName, JoystickDOWNName,
	   JoystickRIGHTName, JoystickLEFTName);
    return(OK);
 }


 /** Fun‡ao: Botoes do joystick. *******************************************/
 int joyfire()
 {
    /** Verifica quais botoes estao pressionados. **************************/
    switch (statusjoystick(0))
    {
       case 0:
	  JoyFire0 = 0;
	  JoyFire1 = 0;
	  if(OldJoyFire0 != JoyFire0 || OldJoyFire1 != JoyFire1)
	  {
	     textcolor(InactiveObjectM);
	     /** Botao f0. *************************************************/
	     gotoxy(23,20);
	     cprintf("ÜÜ");  /** F0 do joystick. ***************************/
	     /** Botao f1. *************************************************/
	     gotoxy(23,22);
	     cprintf("ÜÜ");  /** F1 do joystick. ***************************/
	  }
	  OldJoyFire0 = JoyFire0;
	  OldJoyFire1 = JoyFire1;
	  break;
       case 1:
	  JoyFire0 = 1;
	  JoyFire1 = 0;
	  if(OldJoyFire0 != JoyFire0 || OldJoyFire1 != JoyFire1)
	  {
	     textcolor(InactiveObjectM);
	     /** Botao f1. *************************************************/
	     gotoxy(23,22);
	     cprintf("ÜÜ");  /** F1 do joystick. ***************************/
	     textcolor(ActiveObjectM);
	     /** Botao f0. *************************************************/
	     gotoxy(23,20);
	     cprintf("ÜÜ");  /** F0 do joystick. ***************************/
	  }
	  OldJoyFire0 = JoyFire0;
	  OldJoyFire1 = JoyFire1;
	  break;
       case 2:
	  JoyFire0 = 0;
	  JoyFire1 = 1;
	  if(OldJoyFire0 != JoyFire0 || OldJoyFire1 != JoyFire1)
	  {
	     textcolor(InactiveObjectM);
	     /** Botao f0. *************************************************/
	     gotoxy(23,20);
	     cprintf("ÜÜ");  /** F0 do joystick. ***************************/
	     textcolor(ActiveObjectM);
	     /** Botao f1. *************************************************/
	     gotoxy(23,22);
	     cprintf("ÜÜ");  /** F1 do joystick. ***************************/
	  }
	  OldJoyFire0 = JoyFire0;
	  OldJoyFire1 = JoyFire1;
	  break;
       case 3:
	  JoyFire0 = 0;
	  JoyFire1 = 0;
	  if(OldJoyFire0 != JoyFire0 || OldJoyFire1 != JoyFire1)
	  {
	     textcolor(InactiveObjectM);
	     /** Botao f0. *************************************************/
	     gotoxy(23,20);
	     cprintf("ÜÜ");  /** F0 do joystick. ***************************/
	     /** Botao f1. *************************************************/
	     gotoxy(23,22);
	     cprintf("ÜÜ");  /** F1 do joystick. ***************************/
	  }
	  OldJoyFire0 = JoyFire0;
	  OldJoyFire1 = JoyFire1;
	  break;
       default: break;
    }
    return(OK);
 }


 /** Fun‡ao: Joystick. *****************************************************/
 int joystick(int opcao)
 {
    int JoystickWaitRIGHT = 0;
    int JoystickWaitLEFT = 0;
    int JoystickWaitUP = 0;
    int JoystickWaitDOWN = 0;
    int JoyPos_x = 0, JoyPos_y = 0;

    textcolor(InactiveObjectM);
    textbackground(BLACK);
    /** Inicia dispositivo, exibindo sua aparencia. ************************/
    if(opcao == RESET)
    {
       gotoxy(3,17);  cprintf("°±²Û");  /** Banda superior do joystick. ****/
       gotoxy(3,19);  cprintf("°±²Û");  /** Banda inferior do joystick. ****/
       gotoxy(3,21);  cprintf("°±²Û");  /** Banda direita do joystick. *****/
       gotoxy(3,23);  cprintf("°±²Û");  /** Banda esquerda do joystick. ****/
       /** Botao f0. *******************************************************/
       gotoxy(23,20); cprintf("ÜÜ");  /** F0 do joystick. ******************/
       /** Botao f1. *******************************************************/
       gotoxy(23,22); cprintf("ÜÜ");  /** F1 do joystick. ******************/
       return(OK);
    }
    /** Verifica se existe algum joystick no sistema. **********************/
    if(JoystickPermission == FALSE)
    {
       return(OK);
    }
    /** Verifica se o joystick pode ser utilizado. *************************/
    if(Joystick == FALSE)
    {
       return(OK);
    }
    /** Verifica quais botoes do joystick estao pressionados. **************/
    joyfire();
    /** Verifica posicionamento do joystick. *******************************/
    JoyPos_x = coljoystick(0);
    JoyPos_y = linjoystick(0);
    /** Exibe e executa leds do joystick. **********************************/
    if(JoyPos_x != 0 || JoyPos_y != 0)
    {
       /** Barras direitas. ************************************************/
       if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 4)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(3,21);
	  cprintf("°");  /** Banda direita do joystick. ********************/
	  JoystickWaitRIGHT = JoystickWait + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(3,21);
	  cprintf("°");  /** Banda direita do joystick. ********************/
       }
       if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 3)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(4,21);
	  cprintf("±");  /** Banda direita do joystick. ********************/
	  JoystickWaitRIGHT = JoystickWait / 2;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(4,21);
	  cprintf("±");  /** Banda direita do joystick. ********************/
       }
       if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 2)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(5,21);
	  cprintf("²");  /** Banda direita do joystick. ********************/
	  JoystickWaitRIGHT = JoystickWait / 4 + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(5,21);
	  cprintf("²");  /** Banda direita do joystick. ********************/
       }
       if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 1)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(6,21);
	  cprintf("Û");  /** Banda direita do joystick. ********************/
	  JoystickWaitRIGHT = 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(6,21);
	  cprintf("Û");  /** Banda direita do joystick. ********************/
       }
       /** Barras esquerdas. ***********************************************/
       if(JoyPos_x <= JoyCrossLEFT / 1)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(3,23);
	  cprintf("°");  /** Banda esquerda do joystick. *******************/
	  JoystickWaitLEFT = JoystickWait + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(3,23);
	  cprintf("°");  /** Banda esquerda do joystick. *******************/
       }
       if(JoyPos_x <= JoyCrossLEFT / 2)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(4,23);
	  cprintf("±");  /** Banda esquerda do joystick. *******************/
	  JoystickWaitLEFT = JoystickWait / 2 + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(4,23);
	  cprintf("±");  /** Banda esquerda do joystick. *******************/
       }
       if(JoyPos_x <= JoyCrossLEFT / 3)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(5,23);
	  cprintf("²");  /** Banda esquerda do joystick. *******************/
	  JoystickWaitLEFT = JoystickWait / 4 + 1;
       }
       else
       {
	  gotoxy(5,23);
	  cprintf("²");  /** Banda esquerda do joystick. *******************/
	  textcolor(InactiveObjectM);
       }
       if(JoyPos_x <= JoyCrossLEFT / 4)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(6,23);
	  cprintf("Û");  /** Banda esquerda do joystick. *******************/
	  JoystickWaitLEFT = 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(6,23);
	  cprintf("Û");  /** Banda esquerda do joystick. *******************/
       }
       /** Barras superiores. **********************************************/
       if(JoyPos_y <= JoyCrossUP / 1)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(3,17);
	  cprintf("°");  /** Banda superior do joystick. *******************/
	  JoystickWaitUP = JoystickWait + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(3,17);
	  cprintf("°");  /** Banda superior do joystick. *******************/
       }
       if(JoyPos_y <= JoyCrossUP / 2)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(4,17);
	  cprintf("±");  /** Banda superior do joystick. *******************/
	  JoystickWaitUP = JoystickWait / 2 + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(4,17);
	  cprintf("±");  /** Banda superior do joystick. *******************/
       }
       if(JoyPos_y <= JoyCrossUP / 3)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(5,17);
	  cprintf("²");  /** Banda superior do joystick. *******************/
	  JoystickWaitUP = JoystickWaitUP / 4 + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(5,17);
	  cprintf("²");  /** Banda superior do joystick. *******************/
       }
       if(JoyPos_y <= JoyCrossUP / 4)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(6,17);
	  cprintf("Û");  /** Banda superior do joystick. *******************/
	  JoystickWaitUP = 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(6,17);
	  cprintf("Û");  /** Banda superior do joystick. *******************/
       }
       /** Barras inferiores. **********************************************/
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 4)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(3,19);
	  cprintf("°"); /** Banda inferior do joystick. ********************/
	  JoystickWaitDOWN = JoystickWait + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(3,19);
	  cprintf("°"); /** Banda inferior do joystick. ********************/
       }
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 3)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(4,19);
	  cprintf("±"); /** Banda inferior do joystick. ********************/
	  JoystickWaitDOWN = JoystickWait / 2 + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(4,19);
	  cprintf("±"); /** Banda inferior do joystick. ********************/
       }
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 2)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(5,19);
	  cprintf("²"); /** Banda inferior do joystick. ********************/
	  JoystickWaitDOWN = JoystickWait / 4 + 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(5,19);
	  cprintf("²"); /** Banda inferior do joystick. ********************/
       }
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 1)
       {
	  textcolor(ActiveObjectM);
	  gotoxy(6,19);
	  cprintf("Û"); /** Banda inferior do joystick. ********************/
	  JoystickWaitDOWN = 1;
       }
       else
       {
	  textcolor(InactiveObjectM);
	  gotoxy(6,19);
	  cprintf("Û"); /** Banda inferior do joystick. ********************/
       }
       /** Manda pulso para saida referente ao bra‡o direito da cruz. ******/
       if(JoystickWaitRIGHT >= 1)
       {
	  if(JoyFire0 == 0 && JoyFire1 == 0)
	  {
	     output(JoystickRIGHT[0], Port);
	     delay(Wait + JoystickWaitRIGHT - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire0 == 1)
	  {
	     output(JoystickRIGHT[1], Port);
	     delay(Wait + JoystickWaitRIGHT - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire1 == 1)
	  {
	     output(JoystickRIGHT[2], Port);
	     delay(Wait + JoystickWaitRIGHT - 1);
	     output(NULL, Port);
	  }
       }
       /** Manda pulso para saida referente ao bra‡o esquerdo da cruz. *****/
       if(JoystickWaitLEFT >= 1)
       {
	  if(JoyFire0 == 0 && JoyFire1 == 0)
	  {
	     output(JoystickLEFT[0], Port);
	     delay(Wait + JoystickWaitLEFT - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire0 == 1)
	  {
	     output(JoystickLEFT[1], Port);
	     delay(Wait + JoystickWaitLEFT - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire1 == 1)
	  {
	     output(JoystickLEFT[2], Port);
	     delay(Wait + JoystickWaitLEFT - 1);
	     output(NULL, Port);
	  }
       }
       /** Manda pulso para saida referente ao bra‡o superior da cruz. *****/
       if(JoystickWaitUP >= 1)
       {
	  if(JoyFire0 == 0 && JoyFire1 == 0)
	  {
	     output(JoystickUP[0], Port);
	     delay(Wait + JoystickWaitUP - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire0 == 1)
	  {
	     output(JoystickUP[1], Port);
	     delay(Wait + JoystickWaitUP - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire1 == 1)
	  {
	     output(JoystickUP[2], Port);
	     delay(Wait + JoystickWaitUP - 1);
	     output(NULL, Port);
	  }
       }
       /** Manda pulso para saida referente ao bra‡o inferior da cruz. *****/
       if(JoystickWaitDOWN >= 1)
       {
	  if(JoyFire0 == 0 && JoyFire1 == 0)
	  {
	     output(JoystickDOWN[0], Port);
	     delay(Wait + JoystickWaitDOWN - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire0 == 1)
	  {
	     output(JoystickDOWN[1], Port);
	     delay(Wait + JoystickWaitDOWN - 1);
	     output(NULL, Port);
	  }
	  if(JoyFire1 == 1)
	  {
	     output(JoystickDOWN[2], Port);
	     delay(Wait + JoystickWaitDOWN - 1);
	     output(NULL, Port);
	  }
       }
    }
    return(OK);
 }


 /** Fun‡ao: Mapa dos sensores. ********************************************/
 int sensomap()
 {
    int Contador_1 = 0;

    for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	Contador_1 ++)
    {
       if(strcmp(SensorName[Contador_1], "") != 0)
       {
	  printf("%d\t%s\n", (Contador_1 + 1), SensorName[Contador_1]);
       }
    }
    return(OK);
 }


 /** Fun‡ao: Sensores. *****************************************************/
 int sensor(int opcao)
 {
    int Contador_1 = 0;

    textcolor(InactiveObjectM);
    textbackground(BLACK);
    /** Exibe mapa de sensores. ********************************************/
    if(opcao == RESET)
    {
       for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	   Contador_1 ++)
       {
	  if(strcmp(SensorName[Contador_1], "") != 0 &&
	     Contador_1 < LedNumbers)
	  {
	     textcolor(InactiveObjectM);
	     gotoxy(42, Contador_1 + 6);  cprintf("±");
	     textcolor(WHITE);
	     gotoxy(44, Contador_1 + 6);
	     cprintf("%s", SensorName[Contador_1]);
	  }
       }
       return(OK);
    }

    /** Inicia a busca por algum sensor ativado. ***************************/
    for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	Contador_1 ++)
    {
       if(input(Port) == SensorAction[Contador_1])
       {
	  if(Contador_1 < LedNumbers)
	  {
	     if(Contador_1 == LastSensor)
	     {
		return(OK);
	     }
	     if(Contador_1 != LastSensor)
	     {
		/** Apaga led e texto. *************************************/
		/** Exibe mapa do sensor. **********************************/
		textcolor(InactiveObjectM);
		gotoxy(42, LastSensor + 6);  cprintf("±");
		textcolor(WHITE);
		gotoxy(44, LastSensor + 6);
		cprintf("%s", SensorName[LastSensor]);
	     }
	     /** Ascende led e texto. **************************************/
	     /** Exibe mapa do sensor. *************************************/
	     textcolor(ActiveObjectM);
	     gotoxy(42, LastSensor + 6);  cprintf("Û");
	     textcolor(WHITE);
	     gotoxy(44, LastSensor + 6);
	     cprintf("%s", SensorName[LastSensor]);
	     LastSensor = Contador_1;
	  }
       }
    }
    return(OK);
 }


 /** Fun‡ao: Verifica quais dispositivos de entrada estao disponiveis. *****/
 int chkcontrol()
 {

    if(Serial == TRUE)
    {
       Keyboard = FALSE;
       Mouse = FALSE;
       Joystick = FALSE;
       strcpy(InputMedia, "Serial");
    }
    if(Serial == FALSE)
    {
       if(Keyboard == FALSE && Mouse == FALSE && Joystick == FALSE)
       { strcpy(InputMedia, "Nenhum"); }
       else
       if(Keyboard == FALSE && Mouse == FALSE && Joystick == TRUE)
       { strcpy(InputMedia, "Joystick"); }
       else
       if(Keyboard == FALSE && Mouse == TRUE && Joystick == FALSE)
       { strcpy(InputMedia, "Mouse"); }
       else
       if(Keyboard == FALSE && Mouse == TRUE && Joystick == TRUE)
       { strcpy(InputMedia, "Mouse Joy"); }
       else
       if(Keyboard == TRUE && Mouse == FALSE && Joystick == FALSE)
       { strcpy(InputMedia, "Teclado"); }
       else
       if(Keyboard == TRUE && Mouse == FALSE && Joystick == TRUE)
       { strcpy(InputMedia, "Tecl. Joy"); }
       else
       if(Keyboard == TRUE && Mouse == TRUE && Joystick == FALSE)
       { strcpy(InputMedia, "Tecl. Mouse"); }
       else
       if(Keyboard == TRUE && Mouse == TRUE && Joystick == TRUE)
       { strcpy(InputMedia, "Todos"); }
    }
    return(OK);
 }

 /** Fun‡ao: Sele‡ao de meio de entrada. ***********************************/
 int selectcontrol()
 {
    /** Atualiza dispositivos de entrada a serem utilizados. ************/
    if(KeyboardEnable == TRUE) { Keyboard = TRUE; }
    else { Keyboard = FALSE; }
    if(MousePermission > 1 && MouseEnable == TRUE) { Mouse = TRUE; }
    else { Mouse = FALSE; }
    if(JoystickPermission == TRUE && JoystickEnable == TRUE)
    { Joystick = TRUE; }
    else { Joystick = FALSE; }
    if(SerialPermission == TRUE && SerialEnable == TRUE &&
    StartUpSerialInLogon == TRUE)
    { Serial = TRUE; }

    return(OK);
 }


 /** Fun‡ao: Configura dispositivos de entrada. ****************************/
 int configcontrol()
 {
/*    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;

/*    explica("Configura‡oes dos controles.");
    janela(60, 80, 340, 250, 0, "Controles...");
    dimensao();
    /** Exibe op‡oes do menu. **********************************************/
/*    locate(0, 0, LEFT_TEXT, 1, "Ajustar teclado...");
    locate(0, 1, LEFT_TEXT, 0, "Ajustar mouse...");
    locate(0, 2, LEFT_TEXT, 0, "Calibrar joystick...");
    botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "OK");

    while(TRUE)
    {
       /** Executa menu de opcoes. *****************************************/
/*       OldRetorno = Retorno;
       Retorno = options(4, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
/*       switch(Retorno)
       {
       case 1:
	  botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "OK");
	  locate(0, 0, LEFT_TEXT, 1, "Ajustar teclado...");
	  locate(0, 1, LEFT_TEXT, 0, "Ajustar mouse...");
	  break;
       case 2:
	  locate(0, 0, LEFT_TEXT, 0, "Ajustar teclado...");
	  locate(0, 1, LEFT_TEXT, 1, "Ajustar mouse...");
	  locate(0, 2, LEFT_TEXT, 0, "Calibrar joystick...");
	  break;
       case 3:
	  locate(0, 1, LEFT_TEXT, 0, "Ajustar mouse...");
	  locate(0, 2, LEFT_TEXT, 1, "Calibrar joystick...");
	  botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "OK");
	  break;
       case 4:
	  locate(0, 2, LEFT_TEXT, 0, "Calibrar joystick...");
	  botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 1, "OK");
	  locate(0, 0, LEFT_TEXT, 0, "Ajustar teclado...");
	  break;
       default: break;
       }

       /** Verifica qual opcao foi escolhida e executa-a. ******************/
/*       switch(Retorno)
       {
	  case ENTER:
	     switch(OldRetorno)
	     {
		case 1:
		   keybspeed();
		   return(OK);
		case 2:
		   mousespeed();
		   return(OK);
		case 3:
		   caljoy();
		   return(OK);
		case 4:
		   botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton,
			 0, 1, 1, "OK");
		   delay(50);
		   limpa();
		   return(OK);
		default: break;
	     }
	     break;
	  case ESC:
	     limpa();
	     return(OK);
	  case ERROR:
	     Retorno = OldRetorno;
	     beep(Speaker);
	     break;
	  default: break;
       }
    }*/
    return(OK);
 }


 /** Fun‡ao: Configura‡oes do controlador. *********************************/
 int config()
 {
/*    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;
    char som[4], anim[16];
    if(Speaker == FALSE) strcpy(som, "Nao");
    if(Speaker == TRUE) strcpy(som, "Sim");

    itoa(AnimateM, anim, 10);
    strcat(anim, " passos");
    strcpy(AdressWork, Adress);
    strcat(AdressWork, " Hex");
    strcpy(TimeWork, Time);
    strcat(TimeWork, " miliseg.");
    strcpy(RepeatWork, Emulation);
    strcat(RepeatWork, " vezes.");

/*    explica("Configura‡oes do controlador.");
    janela(20, 50, 350, 294, 0, "Configurar...");
    dimensao();
    /** Exibe op‡oes do menu. **********************************************/
/*    locate(0, 0, LEFT_TEXT, 1, "Utilizar Sons:");
    locate(0, 0, RIGHT_TEXT, 1, som);
    locate(0, 1, LEFT_TEXT, 0, "Anima‡oes:");
    locate(0, 1, RIGHT_TEXT, 0, anim);
    locate(0, 2, LEFT_TEXT, 0, "Endere‡o:");
    locate(0, 2, RIGHT_TEXT, 0, AdressWork);
    locate(0, 3, LEFT_TEXT, 0, "Base de tempo:");
    locate(0, 3, RIGHT_TEXT, 0, TimeWork);
    locate(0, 4, LEFT_TEXT, 0, "Repeti‡ao:");
    locate(0, 4, RIGHT_TEXT, 0, RepeatWork);
    locate(0, 5, LEFT_TEXT, 0, "Controles...");
    locate(0, 6, LEFT_TEXT, 0, "Cores...");
    botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "OK");

    while(TRUE)
    {
       /** Executa menu de opcoes. *****************************************/
/*       OldRetorno = Retorno;
       Retorno = options(8, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
/*       switch(Retorno)
       {
       case 1:
	  botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "OK");
	  locate(0, 0, LEFT_TEXT, 1, "Utilizar Sons:");
	  locate(0, 0, RIGHT_TEXT, 1, som);
	  locate(0, 1, LEFT_TEXT, 0, "Anima‡oes:");
	  locate(0, 1, RIGHT_TEXT, 0, anim);
	  break;
       case 2:
	  locate(0, 0, LEFT_TEXT, 0, "Utilizar Sons:");
	  locate(0, 0, RIGHT_TEXT, 0, som);
	  locate(0, 1, LEFT_TEXT, 1, "Anima‡oes:");
	  locate(0, 1, RIGHT_TEXT, 1, anim);
	  locate(0, 2, LEFT_TEXT, 0, "Endere‡o:");
	  locate(0, 2, RIGHT_TEXT, 0, AdressWork);
	  break;
       case 3:
	  locate(0, 1, LEFT_TEXT, 0, "Anima‡oes:");
	  locate(0, 1, RIGHT_TEXT, 0, anim);
	  locate(0, 2, LEFT_TEXT, 1, "Endere‡o:");
	  locate(0, 2, RIGHT_TEXT, 1, AdressWork);
	  locate(0, 3, LEFT_TEXT, 0, "Base de tempo:");
	  locate(0, 3, RIGHT_TEXT, 0, TimeWork);
	  break;
       case 4:
	  locate(0, 2, LEFT_TEXT, 0, "Endere‡o:");
	  locate(0, 2, RIGHT_TEXT, 0, AdressWork);
	  locate(0, 3, LEFT_TEXT, 1, "Base de tempo:");
	  locate(0, 3, RIGHT_TEXT, 1, TimeWork);
	  locate(0, 4, LEFT_TEXT, 0, "Repeti‡ao:");
	  locate(0, 4, RIGHT_TEXT, 0, RepeatWork);
	  break;
       case 5:
	  locate(0, 3, LEFT_TEXT, 0, "Base de tempo:");
	  locate(0, 3, RIGHT_TEXT, 0, TimeWork);
	  locate(0, 4, LEFT_TEXT, 1, "Repeti‡ao:");
	  locate(0, 4, RIGHT_TEXT, 1, RepeatWork);
	  locate(0, 5, LEFT_TEXT, 0, "Controles...");
	  break;
       case 6:
	  locate(0, 4, LEFT_TEXT, 0, "Repeti‡ao:");
	  locate(0, 4, RIGHT_TEXT, 0, RepeatWork);
	  locate(0, 5, LEFT_TEXT, 1, "Controles...");
	  locate(0, 6, LEFT_TEXT, 0, "Cores...");
	  break;
       case 7:
	  locate(0, 5, LEFT_TEXT, 0, "Controles...");
	  locate(0, 6, LEFT_TEXT, 1, "Cores...");
	  botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "OK");
	  break;
       case 8:
	  locate(0, 6, LEFT_TEXT, 0, "Cores...");
	  botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 1, "OK");
	  locate(0, 0, LEFT_TEXT, 0, "Utilizar Sons:");
	  locate(0, 0, RIGHT_TEXT, 0, som);
	  break;
       default: break;
       }

       /** Verifica qual opcao foi escolhida e executa-a. ******************/
/*       switch(Retorno)
       {
	  case ENTER:
	     switch(OldRetorno)
	     {
		case 1:
		   if(Speaker == TRUE) Speaker = FALSE;
		   else Speaker = TRUE;
		   if(Speaker == FALSE) strcpy(som, "Nao");
		   if(Speaker == TRUE) strcpy(som, "Sim");
		   locate(0, 0, LEFT_TEXT, 1, "Utilizar Sons:");
		   locate(0, 0, RIGHT_TEXT, 1, som);
		   Contador_1 = 1;
		   Retorno = 1;
		   break;
		case 2:
		   animacao();
		   return(OK);
		case 3:
		   endereco();
		   return(OK);
		case 4:
		   base_time();
		   return(OK);
		case 5:
		   correcao();
		   return(OK);
		case 6:
		   configcontrol();
		   return(OK);
		case 7:
		   colors();
		   return(OK);
		case 8:
		   botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton,
			 0, 1, 1, "OK");
		   delay(50);
		   limpa();
		   return(OK);
		default: break;
	     }
	     break;
	  case ESC: limpa(); return(OK);
	  case ERROR:
	     Retorno = OldRetorno;
	     beep(Speaker);
	     break;
	  default: break;
       }
    }*/
    return(OK);
 }


 /** Fun‡ao: Sobre o controlador. ******************************************/
 int sobre()
 {
/*    int tecla = 0;
    char dia[3], mes[3], ano[5];
    char hora[5], minuto[5], segundo[5];
    char horario[16], diario[16];
    int old_time = 0;
    struct time t;
    struct date d;

/*    explica("Informa‡oes sobre o produto. BUGs: Relate ao autor.");
    janela(290, 100, 630, 320, 1, "Sobre...");
    dimensao();
    locate(0, 0, LEFT_TEXT, 0, TITLE);
    locate(0, 1, LEFT_TEXT, 0, COMENTS);
    locate(0, 2, LEFT_TEXT, 0, "copyright (c) 1995-1999");
    locate(0, 3, LEFT_TEXT, 0, "por: M rcio de Sousa Pessoa");
    botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 0, 1, "OK");

    while(tecla != ENTER && tecla != ESC){
       old_time = t.ti_sec;
       getdate(&d);
       itoa(d.da_day, dia, 10);
       itoa(d.da_mon, mes, 10);
       itoa(d.da_year, ano, 10);
       strcpy(diario, "Hoje:");
       strcat(diario, dia);
       strcat(diario, "/");
       strcat(diario, mes);
       strcat(diario, "/");
       strcat(diario, ano);
       gettime(&t);
       itoa(t.ti_hour, hora, 10);
       itoa(t.ti_min, minuto, 10);
       itoa(t.ti_sec, segundo, 10);
       strcpy(horario, "Hora:");
       strcat(horario, hora);
       strcat(horario, ":");
       strcat(horario, minuto);
       strcat(horario, ":");
       strcat(horario, segundo);
       if(t.ti_sec !=  old_time)
       {
	  locate(0, 5, LEFT_TEXT, 0, horario);
	  locate(0, 5, RIGHT_TEXT, 0, diario);
       }
       if(kbhit()) tecla = getch();
    }
    botao(MidWindow_xM, MaxWindow_yM - VerticalSizeButton, 0, 1, 1, "OK");
    delay(50);
    limpa();*/
    return(OK);
 }


 /** Fun‡ao: Exibe informacoes sobre o sistema DRICA. **********************/
 int about()
 {
    printf("%s, copyright(c) 1998-2000 Wizards Technology.\n", TITLE);
    printf("%s, copyright(c) 1995-2000 Wizards Technology.\n\n", COMENTS);
    return(OK);
 }


 /** Fun‡ao: Sair do controlador. ******************************************/
 int sair()
 {
/*    int tecla1 = 0, tecla2 = 0, contador = 1, memoria = 0;

    explica("Sai do controlador.");
    janela(32, 42, 320, 159, 1, "Sair");
    dimensao();
    locate(0, 0, LEFT_TEXT, 0, "Deseja realmente sair?");
    botao(MidWindow_xM - 40, MaxWindow_yM - VerticalSizeButton,
	  0, 0, 1, "Sim");
    botao(MidWindow_xM + 40, MaxWindow_yM - VerticalSizeButton,
	  0, 0, 0, "Nao");
    memoria = contador;
    while((tecla1 = getch()) != -1)
       if(tecla1 == 0)
       {
	  tecla2 = getch();
	  switch(tecla2)
	  {
	     case LEFT:
		if(contador == 1) contador = 2;
		contador = contador - 1;
		if(contador == 1)
		{
		   botao(MidWindow_xM + 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "Nao");
		   botao(MidWindow_xM - 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 1, "Sim");
		}
		if(contador == 2)
		{
		   botao(MidWindow_xM - 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "Sim");
		   botao(MidWindow_xM + 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 1, "Nao");
		}
		if(memoria == contador)
		{
		   beep(Speaker);
		   memoria = contador;
		   break;
		}
		memoria = contador;
	     break;
	     case RIGHT:
		if(contador == 2) contador = 1;
		contador = contador + 1;
		if(contador == 1)
		{
		   botao(MidWindow_xM + 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "Nao");
		   botao(MidWindow_xM - 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 1, "Sim");
		}
		if(contador == 2)
		{
		   botao(MidWindow_xM - 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "Sim");
		   botao(MidWindow_xM + 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 1, "Nao");
		}
		if(memoria == contador)
		{
		   beep(Speaker);
		   memoria = contador;
		   break;
		}
		memoria = contador;
	     break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(tecla1)
	  {
	     case ENTER:
		if(contador == 1)
		{
		   botao(MidWindow_xM + 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "Nao");
		   botao(MidWindow_xM - 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 1, 1, "Sim");
		   delay(100);
		   Quit = TRUE;
		   return(OK);
		}
		if(contador == 2)
		{
		   botao(MidWindow_xM - 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "Sim");
		   botao(MidWindow_xM + 40,
			 MaxWindow_yM - VerticalSizeButton, 0, 1, 1, "Nao");
		   delay(100);
		   limpa();
		   return(OK);
		}
	     case ESC:
		botao(MidWindow_xM - 40,
		      MaxWindow_yM - VerticalSizeButton, 0, 0, 0, "Sim");
		botao(MidWindow_xM + 40,
		      MaxWindow_yM - VerticalSizeButton, 0, 1, 1, "Nao");
		delay(100);
		limpa();
		return(OK);
	     default: beep(Speaker);
	  }*/
    return(OK);
 }


 /** Fun‡ao: Menu do controlador. ******************************************/
 int menu()
 {
/*    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;
    explica("Selecione a op‡ao.");
    janela(MaxScreen_xM / 4, MaxScreen_yM / 4,
	   MaxScreen_xM - MaxScreen_xM / 4,
	   MaxScreen_yM - MaxScreen_yM / 4 , 0, "Op‡oes...");

    /** Exibe op‡oes do menu. **********************************************/
/*    locate(0, 0, LEFT_TEXT, 1, "Iniciar:");
    locate(0, 0, RIGHT_TEXT, 1, DeviceName);
    locate(0, 1, LEFT_TEXT, 0, "Controles");
    locate(0, 1, RIGHT_TEXT, 0, InputMedia);
    locate(0, 2, LEFT_TEXT, 0, "Arquivos...");
    locate(0, 3, LEFT_TEXT, 0, "Configurar...");
    locate(0, 4, LEFT_TEXT, 0, "Sobre...");
    locate(0, 5, LEFT_TEXT, 0, "Sair");

    while(TRUE)
    {
       /** Executa menu de opcoes. *****************************************/
/*       OldRetorno = Retorno;
       Retorno = options(6, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
/*       switch(Retorno)
       {
       case 1:
	  locate(0, 5, LEFT_TEXT, 0, "Sair");
	  locate(0, 0, LEFT_TEXT, 1, "Iniciar:");
	  locate(0, 0, RIGHT_TEXT, 1, DeviceName);
	  locate(0, 1, LEFT_TEXT, 0, "Controles");
	  locate(0, 1, RIGHT_TEXT, 0, InputMedia);
	  break;
       case 2:
	  locate(0, 0, LEFT_TEXT, 0, "Iniciar:");
	  locate(0, 0, RIGHT_TEXT, 0, DeviceName);
	  locate(0, 1, LEFT_TEXT, 1, "Controles");
	  locate(0, 1, RIGHT_TEXT, 1, InputMedia);
	  locate(0, 2, LEFT_TEXT, 0, "Arquivos...");
	  break;
       case 3:
	  locate(0, 1, LEFT_TEXT, 0, "Controles");
	  locate(0, 1, RIGHT_TEXT, 0, InputMedia);
	  locate(0, 2, LEFT_TEXT, 1, "Arquivos...");
	  locate(0, 3, LEFT_TEXT, 0, "Configurar...");
	  break;
       case 4:
	  locate(0, 2, LEFT_TEXT, 0, "Arquivos...");
	  locate(0, 3, LEFT_TEXT, 1, "Configurar...");
	  locate(0, 4, LEFT_TEXT, 0, "Sobre...");
	  break;
       case 5:
	  locate(0, 3, LEFT_TEXT, 0, "Configurar...");
	  locate(0, 4, LEFT_TEXT, 1, "Sobre...");
	  locate(0, 5, LEFT_TEXT, 0, "Sair");
	  break;
       case 6:
	  locate(0, 4, LEFT_TEXT, 0, "Sobre...");
	  locate(0, 5, LEFT_TEXT, 1, "Sair");
	  locate(0, 0, LEFT_TEXT, 0, "Iniciar:");
	  locate(0, 0, RIGHT_TEXT, 0, DeviceName);
	  break;
       default: break;
       }

       /** Verifica qual opcao foi escolhida e executa-a. ******************/
/*       switch(Retorno)
       {
	  case ENTER:
	     switch(OldRetorno)
	     {
		case 1:
		   iniciar();
		   return(OK);
		case 2:
		   selectcontrol(TRUE);
		   return(OK);
		case 3:
		   limpa();
		   return(OK);
		case 4:
		   config();
		   return(OK);
		case 5:
		   sobre();
		   return(OK);
		case 6:
		   sair();
		   return(OK);
		default: break;
	     }
	     break;
	  case ESC: limpa(); return(OK);
	  case ERROR:
	     Retorno = OldRetorno;
	     beep(Speaker);
	     break;
	  default: break;
       }
    }*/
    return(OK);
 }


 /** Funcao: Apresentacao do controlador. **********************************/
 int apresentacao()
 {
/*    int tecla = 0;

    if(StartUpSerialInLogon == TRUE)
    {
       StartUpSerialInLogon = FALSE;
       iniciar();
    }

    explica("Pronto para iniciar.                                                   ê");
    while(TRUE){
       if(tecla == ENTER)
       {
	  menu();
	  return(OK);
       }
       if(tecla == ESC)
       {
	  sair();
	  return(OK);
       }
       if(tecla == 'c' || tecla == 'C')
       {
	  config();
	  return(OK);
       }
       if(tecla == 'j' || tecla == 'J')
       {
	  caljoy();
	  return(OK);
       }
       if(tecla == 'k' || tecla == 'K')
       {
	  keybspeed();
	  return(OK);
       }
       if(tecla == 'm' || tecla == 'M')
       {
	  mousespeed();
	  return(OK);
       }
       if(tecla == 's' || tecla == 'S')
       {
	  sobre();
	  return(OK);
       }
       if(tecla == 't' || tecla == 'T')
       {
	  selectcontrol(TRUE);
	  return(OK);
       }
       if(tecla == 222)
       {
	  genericmode(1);
	  return(OK);
       }
       if(kbhit()){
	  tecla = getch();
       }
    }*/
    return(OK);
 }


 /** Fun‡ao: Inicia a utiliza‡ao do dispositivo. ***************************/
 int iniciar()
 {
    int Tecla = RESET;

    /** Exibe os dispositivos com os leds apagados. ************************/
    keyboard(RESET);
    mouse(RESET);
    joystick(RESET);
    sensor(RESET);

    while(TRUE){
       /** Se for pressionado enter chama menu. ****************************/
       if(Tecla == ENTER)
       {
	  keyboard(RESET);
	  mouse(RESET);
	  joystick(RESET);
	  sensor(RESET);
	  getch();
       }
       /** Se for pressionado ESC, para execussao. *************************/
       if(Tecla == ESC)
       {
	  keyboard(RESET);
	  mouse(RESET);
	  joystick(RESET);
	  sensor(RESET);
	  return(OK);
       }
       /** Executa os meios de entrada e de saida. *************************/
       keyboard(Tecla);
       mouse(OK);
       joystick(OK);
       sensor(OK);
       /** Verifica qual caracter foi digitado. ****************************/
       Tecla = RESET;
       if(kbhit()){
	  Tecla = getch();
       }
    }
//    return(OK);
 }


 /** Fun‡ao: Carrega configuracoes do controlador. *************************/
 int configuracao()
 {
    int AuxScan = 0;
    printf("\nIniciando arquivos de configura‡ao.");
    /** Configura‡oes de entretenimento. ***********************************/
    if((AuxScan = load(ConfigurationFile, "AnimateSteps")) != ERROR &&
	AuxScan >= 1 && AuxScan <= 99) { AnimateM = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Speaker")) != ERROR &&
	AuxScan == 1) { Speaker = TRUE; }
    else { Speaker = FALSE; }
    if((AuxScan = load(ConfigurationFile, "LastAdress")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 4095) { Port = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "TimeBase")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 99) { Wait = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Repeat")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 99) { Repeat = AuxScan; }
    /** Configura‡oes do mouse. ********************************************/
    if((AuxScan = load(ConfigurationFile, "MouseScanDelay")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 99) { MouseScanDelay = AuxScan; }
    /** Configuracoes de dispositivo. **************************************/
    if((AuxScan = load(ConfigurationFile, "Device")) != ERROR)
    {
       Dado[127] = '\0';
       strcpy(DeviceInformationFile, Dado);
    }
    if((AuxScan = load(ConfigurationFile, "LastUsed")) != ERROR)
    {
       Dado[127] = '\0';
       strcpy(ProgramFile, Dado);
    }
    /** Le do arquivo as configuracoes do joystick. ************************/
    if((AuxScan = load(ConfigurationFile, "JoyCenter_x")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoyCenter_x = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "JoyCenter_y")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoyCenter_y = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "JoyCrossRIGHT")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoyCrossRIGHT = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "JoyCrossLEFT")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoyCrossLEFT = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "JoyCrossUP")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoyCrossUP = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "JoyCrossDOWN")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoyCrossDOWN = AuxScan; }
    /** Atribui valores as variaveis de texto. *****************************/
    itoa(Repeat, Emulation, 10);
    itoa(Wait, Time, 10);
    itoa(Port, Adress, 16);
    return(OK);
 }


 /** Fun‡ao: Carrega configuracoes do dispositivo. *************************/
 int aspectos()
 {
    int Contador_1 = 0, Contador_2 = 0;
    int AuxScan = 0;
    char Auxiliar_1 [64], Auxiliar_2 [32];

    /** Inicia a carregar aspectos do dispositivo. *************************/
    printf("\nIniciando arquivos de dispositivo.");
    if((AuxScan = load(DeviceInformationFile, "Title")) != ERROR)
    {
       Dado[16] = '\0';
       strcpy(DeviceName, Dado);
    }
    /** Carrega dados dos dispositivos a serem hebilitados. ****************/
    if((AuxScan = load(DeviceInformationFile, "Keyboard")) != ERROR)
       KeyboardEnable = AuxScan;
    if(KeyboardEnable == 1) { KeyboardEnable = TRUE; }
    else { KeyboardEnable = FALSE; }
    if((AuxScan = load(DeviceInformationFile, "Mouse")) != ERROR)
       MouseEnable = AuxScan;
    if(MouseEnable == 1) { MouseEnable = TRUE; }
    else { MouseEnable = FALSE; }
    if((AuxScan = load(DeviceInformationFile, "Joystick")) != ERROR)
       JoystickEnable = AuxScan;
    if(JoystickEnable == 1) { JoystickEnable = TRUE; }
    else { JoystickEnable = FALSE; }
    if((AuxScan = load(DeviceInformationFile, "Serial")) != ERROR)
       SerialEnable = AuxScan;
    if(SerialEnable == 1) { SerialEnable = TRUE; }
    else { SerialEnable = FALSE; }
    if((AuxScan = load(DeviceInformationFile, "StartUpSerialInLogon")) != ERROR)
       StartUpSerialInLogon = AuxScan;
    if(StartUpSerialInLogon == 1) { StartUpSerialInLogon = TRUE; }
    else { StartUpSerialInLogon = FALSE; }
    /** Le do arquivo o numero de combinacoes do dispositivo. **************/
    if((AuxScan = load(DeviceInformationFile, "DeviceInterfaceCombinations")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 128)
    { DeviceInterfaceCombinations = AuxScan; }
    /** Prepara para carregar dados dos pulsos de entrada e saida. *********/
    for(Contador_1 = 0; Contador_1 < DeviceInterfaceCombinations;
	Contador_1 ++)
    {
       /** Nome do pulso de saida. *****************************************/
       strcpy(Auxiliar_1, "OutName");
       itoa(Contador_1, Auxiliar_2, 10);
       strcat(Auxiliar_1, Auxiliar_2);
       if((AuxScan = load(DeviceInformationFile, Auxiliar_1)) != ERROR)
       {
	  Dado[16] = '\0';
	  strcpy(OutputName[Contador_1], Dado);
       }
       /** Dado do pulso de saida. *****************************************/
       strcpy(Auxiliar_1, "OutAct");
       itoa(Contador_1, Auxiliar_2, 10);
       strcat(Auxiliar_1, Auxiliar_2);
       if((AuxScan = load(DeviceInformationFile, Auxiliar_1)) != ERROR &&
	   AuxScan >= 0 && AuxScan <= 255)
       { OutputAction[Contador_1] = AuxScan; }
       /** Nome do pulso de entrada. ***************************************/
       strcpy(Auxiliar_1, "InpName");
       itoa(Contador_1, Auxiliar_2, 10);
       strcat(Auxiliar_1, Auxiliar_2);
       if((AuxScan = load(DeviceInformationFile, Auxiliar_1)) != ERROR)
       {
	  Dado[24] = '\0';
	  strcpy(SensorName[Contador_1], Dado);
       }
       /** Dado do pulso de entrada. ***************************************/
       strcpy(Auxiliar_1, "InpAct");
       itoa(Contador_1, Auxiliar_2, 10);
       strcat(Auxiliar_1, Auxiliar_2);
       if((AuxScan = load(DeviceInformationFile, Auxiliar_1)) != ERROR &&
	   AuxScan >= 0 && AuxScan <= 255)
	   { SensorAction[Contador_1] = AuxScan; }
       /** Dado do teclado correspondente ao dado de saida. ****************/
       strcpy(Auxiliar_1, "Keyb");
       itoa(Contador_1, Auxiliar_2, 10);
       strcat(Auxiliar_1, Auxiliar_2);
       if((AuxScan = load(DeviceInformationFile, Auxiliar_1)) != ERROR)
       {
	  Dado[6] = '\0';
	  strcpy(KeybName[Contador_1], Dado);
       }
       /** Exibe pontos de procedimento de carga do arquivo. ***************/
       Contador_2 = Contador_2 + 1;
       if(Contador_2 == 8)
       {
	  Contador_2 = 0;
	  printf(".");
       }
    }
    /** Le do arquivo as configura‡oes de posicionamento do mouse. *********/
    if((AuxScan = load(DeviceInformationFile, "MouseRight00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseRIGHT[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseLeft00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseLEFT[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseUp00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseUP[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseDown00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseDOWN[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseRight01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseRIGHT[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseLeft01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseLEFT[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseUp01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseUP[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseDown01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseDOWN[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseRight10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseRIGHT[2] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseLeft10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseLEFT[2] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseUp10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseUP[2] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "MouseDown10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { MouseDOWN[2] = AuxScan; }
    /** Le do arquivo as configura‡oes de botoes do mouse. *****************/
    if((AuxScan = load(DeviceInformationFile, "ButtonName0")) != ERROR)
    {
       Dado[14] = '\0';
       strcpy(MouseButton0Name, Dado);
    }
    if((AuxScan = load(DeviceInformationFile, "ButtonName1")) != ERROR)
    {
       Dado[14] = '\0';
       strcpy(MouseButton1Name, Dado);
    }
    printf(".");
    /** Le do arquivo as configura‡oes de posicionamento do joystick. ******/
    if((AuxScan = load(DeviceInformationFile, "JoyRight00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickRIGHT[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyLeft00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickLEFT[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyUp00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickUP[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyDown00")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickDOWN[0] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyRight01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickRIGHT[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyLeft01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickLEFT[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyUp01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickUP[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyDown01")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickDOWN[1] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyRight10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickRIGHT[2] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyLeft10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickLEFT[2] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyUp10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickUP[2] = AuxScan; }
    if((AuxScan = load(DeviceInformationFile, "JoyDown10")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 255) { JoystickDOWN[2] = AuxScan; }
    /** Le do arquivo as configura‡oes de botoes do joystick. **************/
    if((AuxScan = load(DeviceInformationFile, "FireName0")) != ERROR)
    {
       Dado[14] = '\0';
       strcpy(JoystickFire0Name, Dado);
    }
    if((AuxScan = load(DeviceInformationFile, "FireName1")) != ERROR)
    {
       Dado[14] = '\0';
       strcpy(JoystickFire1Name, Dado);
    }
    printf(".");
    return(OK);
 }

 /**************************************************************************/
 /**                                                                      **/
 /**                             MODO TEXTO                               **/
 /**                                                                      **/
 /**************************************************************************/


 /** Fun‡ao: Modo texto protegido secreto do Drica. ************************/
 int genericmode()
 {
    char linecommand[128];
    char AuxiliarTexto[64];

    /** Exibe texto de inicia‡ao do modo texto. ****************************/
    printf("\n\nWizards(R) DRICA(R) Versao 0.1b");
    printf("\n           (C)Copyright Wizards Technology 1998-1999.\n\n");

    /** Laco da linha de comandos. *****************************************/
    while(TRUE){
 /** Exibe prompt de comando. **********************************************/
       printf("\nDRICA> ");
       scanf("%s", linecommand);
 /** Comando: clear. *******************************************************/
       if(strcmp(linecommand, "clear") == 0 ||
	  strcmp(linecommand, "cls") == 0 ||
	  strcmp(linecommand, "clrscr") == 0)
       {
	  clrscr();
       }
       else
 /** Comando: about. Informa‡oes sobre o sistema DRICA. ********************/
       if(strcmp(linecommand, "about") == 0)
       {
	  printf("\nSobre DRICA...\n");
	  about();
       }
       else
 /** Comando: time. Ajusta o dia e a hora corrente do sistema. *************/
       if(strcmp(linecommand, "today") == 0)
       {
	  today();
       }
       else
 /** Comando: port. Ajusta a porta a ser utilizada. ************************/
       if(strcmp(linecommand, "port") == 0)
       {
	  endereco();
       }
       else
 /** Comando: delay. Ajusta o tempo entre os pulsos de saida. **************/
       if(strcmp(linecommand, "delay") == 0)
       {
	  base_time();
       }
       else
 /** Comando: repeat. Ajusta o numero de vezes que e repetido um pulso. ****/
       if(strcmp(linecommand, "repeat") == 0)
       {
	  correcao();
       }
       else
 /** Comando: loop. Define o numero de repeticoes do programa. *************/
       if(strcmp(linecommand, "loop") == 0)
       {

       }
       else
 /** Comando: reset. Carrega o conteudo dos arquivos originais. ************/
       if(strcmp(linecommand, "reset") == 0)
       {
	  printf("Resetando endere‡o %xH...\n", Port);
	  output(NULL, Port);
	  printf("Concluido.\n");
       }
       else
 /** Comando: keymap. Exibe o mapa do teclado. *****************************/
       if(strcmp(linecommand, "keybmap") == 0)
       {
	  keybmap(TRUE);
       }
       else

 /** Comando: kbrate. Ajusta intermitencia do cursor. **********************/
       if(strcmp(linecommand, "kbrate") == 0)
       {
	  keybspeed();
       }
       else
 /** Comando: mousemap. Exibe o mapa do mouse. *****************************/
       if(strcmp(linecommand, "mousemap") == 0)
       {
	  mousemap();
       }
       else
 /** Comando: joymap. Exibe o mapa do joystick. ****************************/
       if(strcmp(linecommand, "joymap") == 0)
       {
	  joymap();
       }
       else
 /** Comando: sensomap. Exibe o mapa dos sensores. *************************/
       if(strcmp(linecommand, "sensomap") == 0)
       {
	  sensomap();
       }
       else
 /** Comando: caljoy. Calibra joystick. ************************************/
       if(strcmp(linecommand, "caljoy") == 0)
       {
	  if(JoystickPermission == TRUE)
	  {
	     caljoy();
	  }
	  else { JoystickPermission = joystickchk(); }
       }
       else
 /** Comando: chkjoy. Vefica se ha uma porta de joystick no sistema. *******/
       if(strcmp(linecommand, "chkjoy") == 0)
       {
	  JoystickPermission = joystickchk();
	  if(JoystickPermission == TRUE)
	  {
	     printf("Foi encontrada uma porta de joystick.\n");
	  }
       }
       else
 /** Comando: chkmouse. Vefica se ha um mouse e quantos botoes ele tem. ****/
       if(strcmp(linecommand, "chkmouse") == 0)
       {
	  MousePermission = mousepresente();
	  if(MousePermission != FALSE)
	  {
	     if(MousePermission == 2){
		printf("Foi detectado um mouse com 2 botoes.\n");
	     }
	     if(MousePermission == 3){
		printf("Foi detectado um mouse com 3 botoes.\n");
		printf("Somente o primeiro e o ultimo botao serao utilizados.\n");
	     }
	  }
       }
       else
 /** Comando: chkrs232. Vefica se ha portas seriais conectadas. ************/
       if(strcmp(linecommand, "chkrs232") == 0)
       {
	  RS232number();
       }
       else
 /** Comando: chkline. Vefica ha existencia de portas paralelas. ***********/
       if(strcmp(linecommand, "chkline") == 0)
       {
	  paralelnumber();
       }
       else
 /** Comando: tmouse. Acinoa o cursor do mouse para testes. ****************/
       if(strcmp(linecommand, "tmouse") == 0)
       {
	  if(mousepresente() != ERROR)
	  {
	     printf("Mova o mouse para verificar se ele esta funcionando.\n");
	     printf("Apos o teste, pressione alguma tecla para continuar.\n");
	     ligamouse();
	     getch();
	     desligamouse();
	  }
       }
       else
 /** Comando: single. Inicia a executar o dispositivo. *********************/
       if(strcmp(linecommand, "single") == 0)
       {
	  setcursor(0, 0);
	  frame();
	  strcpy(AuxiliarTexto, "Executando ");
	  strcat(AuxiliarTexto, DeviceName);
	  genericstatus(AuxiliarTexto);
	  iniciar();
	  defaultvideo();
	  setcursor(6, 7);
	  clrscr();
       }
       else
 /** Comando: quit ou exit. Sai do controlador. ****************************/
       if(strcmp(linecommand, "quit") == 0 ||
	  strcmp(linecommand, "q") == 0)
       {
	  printf("Finalizando DRICA...\n");
	  about();
	  exit(OK);
       }
       else
 /** Comando: system. Chama o interpretador de comandos. *******************/
       if(strcmp(linecommand, "system") == 0)
       {
	  printf("Digite EXIT para retornar ao controlador.\n");
	  system("COMMAND");
	  printf("\nRetornado para DRICA... Concluido.");
       }
       else
 /** Comando: help. Exibe ajuda sobre o controlador em modo texto. *********/
       if(strcmp(linecommand, "help") == 0 ||
	  strcmp(linecommand, "?") == 0)
       {
	  ajuda("");
       }
       else
 /** Comando invalido. Exibe menssagem de comando invalido. ****************/
       {
	  printf("Comando inv lido. Tente novamente.\n");
       }
    }
//    return(OK);
 }


 /** Program notes. ********************************************************
 by: Marcio de Sousa Pessoa
 e-mail: marciomexicano@zipmail.com.br
 ***************************************************************************/
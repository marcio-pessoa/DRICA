 /** Bibliotecas a serem utilizadas pelo controlador. **********************/
 #include <GRAPHICS.H>  /** Biblioteca para recursos graficos. *************/
 #include <STDLIB.H>    /** Biblioteca de recursos melhorados. *************/
 #include <STRING.H>    /** Biblioteca de manipula‡ao de strings. **********/
 #include <CONIO.H>     /** Biblioteca de recursos extendidos. *************/
 #include <STDIO.H>     /** Biblioteca de recursos melhorados. *************/
 #include <DOS.H>       /** Biblioteca de baixo nivel do sistema DOS. ******/
 #include "DRICA.H"     /** Biblioteca especifica do controlador. **********/
 #include "\WIZ\LIBRARY\WIZ.H"  /** Biblioteca especifica Wizards soft. ****/


 /** Global: Declara‡ao das variaveis globais. *****************************/
 /** Dimensoes da tela. ****************************************************/
 int MaxScreen_x = 0, MaxScreen_y = 0, MidScreen_x = 0, MidScreen_y = 0;
 int MaxWindow_x = 0, MaxWindow_y = 0, MidWindow_x = 0, MidWindow_y = 0;
 /** Cores padrao de inicia‡ao. ********************************************/
 int AppWorkspace = 0;
 int Background = DARKGRAY, Selector = DARKGRAY, Frame = BLACK;
 int Window = WHITE, ActiveWindowText = BLACK;
 int ActiveBorder = LIGHTGRAY, ActiveTitle = BLACK;
 int InactiveBorder = 0, InactiveTitle = 0, InactiveWindowText = 0;
 int ActiveObject = LIGHTGREEN, InactiveObject = GREEN;
 int ButtonFace = LIGHTGRAY, ButtonText = BLACK;
 int ButtonHilight = WHITE, ButtonShadow = DARKGRAY;
 int Hilight = LIGHTGRAY, HilightText = WHITE;
 int HilightWindow = WHITE, HilightObject = WHITE;
 int Shadow = BLACK, ShadowObject = BLACK;
 int ShadowText = BLACK, ShadowWindow = DARKGRAY;
 int Menu = WHITE, MenuText = BLACK, GrayText = LIGHTGRAY;
 /** Variaveis padrao de configura‡ao inicial. *****************************/
 int Wait = 0, Repeat = 0, Port = 0;
 /** Variaveis de anima‡ao, sons, entretenimento, etc. *********************/
 int Animate = 1, VerticalSizeButton = 19, Speaker = 0, Quit = FALSE;
 /** Defini‡ao do tamanho das variaveis de exibi‡ao de dados. **************/
 char Dado[32];
 char AdressWork[16];
 char TimeWork[16];
 char RepeatWork[16];
 char Adress[8], Time[8], Emulation[8];
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
 /** Variaveis de comunica‡ao serial. **************************************/
 int ComunicationsPort = 2;
 int ComunicationsBaudRate = 9600;
 int ComunicationsParity = 0;
 int ComunicationsStopBits = 1;
 int ComunicationsWordLenght = 8;


 /** Fun‡oes do modulo GRAPHIC.CPP. ****************************************/
 int copygraphvar(int Auxiliar_1, int Auxiliar_2, int Auxiliar_3,
		  int Auxiliar_4, int Auxiliar_5, int Auxiliar_6,
		  int Auxiliar_7, int Auxiliar_8, int Auxiliar_9,
		  int Auxiliar_10, int Auxiliar_11, int Auxiliar_12,
		  int Auxiliar_13, int Auxiliar_14, int Auxiliar_15,
		  int Auxiliar_16, int Auxiliar_17, int Auxiliar_18,
		  int Auxiliar_19, int Auxiliar_20, int Auxiliar_21,
		  int Auxiliar_22, int Auxiliar_23, int Auxiliar_24,
		  int Auxiliar_25, int Auxiliar_26, int Auxiliar_27,
		  int Auxiliar_28, int Auxiliar_29);
 int grafico();
 int reset_variaveis();
 int explica(char texto[128]);
 int print(int x, int y, int cor, char *texto);
 int titulo();
 int botao(int x, int y, int tamanho, int on_off, int selecao, char *nome);
 int janela(int x1, int y1, int x2, int y2, int animation, char *nome);
 int locate(int x, int y, int xpos, int select, char *texto);
 int paleta(int x, int y, int xpos, int color);
 int WindowMaxx();
 int WindowMaxy();
 int options(int OpcoesMaximas, int OpcaoInicial);
 int crazy(float MinValue, float MaxValue, float ActualValue,
	   int FactorLenght, int AllClean,
	   int xPosition, int yPosition, int Orientation);
 /** Fun‡oes do modulo MESSAGES.CPP. ***************************************/
 int beep(int opcao);
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
 int ajuda();
 int today();
 int frame();
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
 int base_Time();
 int correcao();
 int colors();
 int animacao();
 int keybspeed();
 int mousespeed();
 int chkcontrol();
 int selectcontrol(int opcao);
 int configcontrol();
 int config();
 int configcomunications();
 int sobre();
 int sair();
 int menu();
 /** Fun‡oes referentes aos dispoditivos de entrada. ***********************/
 int mousemap();
 int mouse(int opcao);
 int keybmap();
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

 int about();
 int dimensao();
 int limpa();
 int apresentacao();
 int iniciar();


 /** Fun‡ao: Fun‡ao principal - main. **************************************/
 main(int argc, char *argv[])
 {
    /** Trabalha com argc para evitar problemas. ***************************/
    Speaker = argc;
    /** Se for requisitado a op‡ao de ajuda na linha de comandos. **********/
    if(strcmp("/?", argv[1]) == 0 ||
       strcmp("/H", argv[1]) == 0 ||
       strcmp("/h", argv[1]) == 0)
    {
       about();
       printf("Controlador de dispositivos Wizards.\n\n");
       exit(OK);
    }
    /** Reseta as variaveis. ***********************************************/
    reset_variaveis();
    /** Carrega as configuracoes gravadas em arquivo. **********************/
    printf("\n#Aguarde. Carregando arquivos...");
    configuracao();
    aspectos();
    printf("\n#Concluindo inicia‡ao...\n");
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
    selectcontrol(RESET);
    /** Inicia modo grafico. ***********************************************/
    if(grafico() == ERROR)
    {
       printf("#ERRO: Ocorreu um erro ao iniciar o modo grafico.\n");
       return(OK);
    }
    /** Faz acesso direto a memoria da placa de video. *********************/
    directvideo = 1;
    dimensao();
    /** Atualiza variaveis do modo grafico. ********************************/
    copygraphvar(AppWorkspace,
		 Background, Selector, Frame,
		 Window, ActiveWindowText,
		 ActiveBorder, ActiveTitle,
		 InactiveBorder, InactiveTitle, InactiveWindowText,
		 ActiveObject, InactiveObject,
		 ButtonFace, ButtonText,
		 ButtonHilight, ButtonShadow,
		 Hilight, HilightText,
		 HilightWindow, HilightObject,
		 Shadow, ShadowObject,
		 ShadowText, ShadowWindow,
		 Menu, MenuText, GrayText,
		 Animate);
    /** Monta tela. ********************************************************/
    limpa();
    while(Quit == FALSE)
    {
       /** Exibe a tela de apresentacao com link para menu. ****************/
       apresentacao();
    }
    /** Finaliza modo grafico. *********************************************/
    closegraph();
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


 /** Fun‡ao: Dimensoes da tela grafica. ************************************/
 int dimensao()
 {
    /** Verifica as dimensoes da tela grafica. *****************************/
    MaxScreen_x = getmaxx();
    MaxScreen_y = getmaxy();
    MidScreen_x = getmaxx() / 2;
    MidScreen_y = getmaxy() / 2;
    /** Verifica as dimensoes da ultilma janela aberta. ********************/
    MaxWindow_x = WindowMaxx();
    MaxWindow_y = WindowMaxy();
    MidWindow_x = WindowMaxx() / 2;
    MidWindow_y = WindowMaxy() / 2;
    /** Define o posicionamento do mouse. **********************************/
    Mouse_x = MidScreen_x + 15;
    Mouse_y = MaxScreen_y -20 - 15 - 81;
    /** Define o posicionamento do joystick. *******************************/
    Joystick_x = 15;
    Joystick_y = MaxScreen_y - 20 - 15 - 78;
    /** Define o numero maximo de led's do teclado e dos sensores. *********/
    if(MaxScreen_y == 479) { LedNumbers = 8; };
    if(MaxScreen_y == 349) { LedNumbers = 5; };
    LastSensor = LedNumbers * 10;
    return(OK);
 }


 /** Fun‡ao: Limpa tela. ***************************************************/
 int limpa()
 {
    /** Abre porta de visualiza‡ao grafica.*********************************/
    setviewport(0, 0, MaxScreen_x, MaxScreen_y, CLIP_ON);
    /** Exibe barra de titulo. *********************************************/
    titulo();
    /** Titulo da barra. ***************************************************/
    setcolor(ActiveTitle);
    settextjustify(LEFT_TEXT, CENTER_TEXT);
    settextstyle(FONTTYPE, HORIZ_DIR, 7);
    outtextxy(25, 7, TITLE);
    /** Limpa tela exibindo um quadrado que cobre parcialmente a tela. *****/
    setfillstyle(1, Background);
    bar(0, 21, MaxScreen_x, MaxScreen_y - 21);
    /** Exibe a parte hight-light da moldura. ******************************/
    setcolor(Hilight);
    line(2, MidScreen_y - 2, MidScreen_x - 2, MidScreen_y - 2);
    line(MidScreen_x + 2, MidScreen_y - 2,
	 MaxScreen_x - 2, MidScreen_y - 2);
    line(2, MaxScreen_y - 22, MidScreen_x - 2, MaxScreen_y - 22);
    line(MidScreen_x + 2, MaxScreen_y - 22,
	 MaxScreen_x - 1, MaxScreen_y - 22);
    line(MidScreen_x - 2, 22, MidScreen_x - 2, MidScreen_y - 2);
    line(MaxScreen_x - 1, 22, MaxScreen_x - 1, MidScreen_y - 2);
    line(MidScreen_x - 2, MidScreen_y + 2, MidScreen_x - 2,
	 MaxScreen_y - 22);
    line(MaxScreen_x - 1, MidScreen_y + 2,
	 MaxScreen_x - 1, MaxScreen_y - 22);
    /** Exibe a parte back-light da moldura. *******************************/
    setcolor(Shadow);
    line(1, 22, MidScreen_x - 2, 22);
    line(MidScreen_x + 1, 22, MaxScreen_x - 1, 22);
    line(1, MidScreen_y + 1 , MidScreen_x - 2, MidScreen_y + 1);
    line(MidScreen_x + 1, MidScreen_y + 1,
	 MaxScreen_x - 1, MidScreen_y + 1);
    line(1, 22, 1, MidScreen_y - 2);
    line(MidScreen_x + 1, 22,
	 MidScreen_x + 1, MidScreen_y - 2);
    line(1, MidScreen_y + 1,
	 1, MaxScreen_y - 22);
    line(MidScreen_x + 1, MidScreen_y + 1,
	 MidScreen_x + 1, MaxScreen_y - 22);
    /** Exibe textos de fundo de tela. *************************************/
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(FONTTYPE, HORIZ_DIR, 7);
    setcolor(ShadowText);
    outtextxy(MidScreen_x / 2 - 1, 37, "Teclado");
    outtextxy(MidScreen_x + (MidScreen_x / 2) - 1, 37, "Sensores");
    outtextxy(MidScreen_x / 2 - 1, MidScreen_y + 16, "Joystick");
    outtextxy(MidScreen_x + (MidScreen_x / 2) - 1,
	      MidScreen_y + 16, "Mouse");
    setcolor(HilightText);
    outtextxy(MidScreen_x / 2, 35, "Teclado");
    outtextxy(MidScreen_x + (MidScreen_x / 2), 35, "Sensores");
    outtextxy(MidScreen_x / 2, MidScreen_y + 14, "Joystick");
    outtextxy(MidScreen_x + (MidScreen_x / 2),
	      MidScreen_y + 14, "Mouse");
    /** Exibe tela do teclado. *********************************************/
    keyboard(RESET);
    /** Exibe tela do mouse. ***********************************************/
    mouse(RESET);
    /** Exibe tela do joystick. ********************************************/
    joystick(RESET);
    /** Exibe tecla dos sensores. ******************************************/
    sensor(RESET);

    return(OK);
 }


 /** Fun‡ao: Configura‡ao do endereco a ser lido. **************************/
 int endereco()
 {
    int tecla1 = 0, tecla2 = 0, aux = Port;
    char auxiliar[128];

    explica("Endere‡o do dispositivo de saida.");
    janela(32, 35, 373, 184, 0, "Endere‡o...");
    locate(0, 0, LEFT_TEXT, 0, "O dispoditivo est  conectado na");
    locate(0, 1, LEFT_TEXT, 0, "porta de endere‡o inicial:");
    strcpy(AdressWork, Adress);
    strcat(AdressWork, " Hex");
    locate(0, 3, LEFT_TEXT, 1, "Endere‡o:");
    locate(0, 3, RIGHT_TEXT, 1, AdressWork);
    while((tecla1 = getch()) != -1)
       if(tecla1 == 0)
       {
	  tecla2 = getch();
	  switch(tecla2)
	  {
	     case UP:
		aux = aux + 1;
		if(aux > 4095) aux = 0;
		itoa(aux, Adress, 16);
		strcpy(AdressWork, Adress);
		strcat(AdressWork, " Hex");
		locate(0, 3, LEFT_TEXT, 1, "Endere‡o:");
		locate(0, 3, RIGHT_TEXT, 1, AdressWork);
		break;
	     case DOWN:
		aux = aux - 1;
		if(aux < 0) aux = 4095;
		itoa(aux, Adress, 16);
		strcpy(AdressWork, Adress);
		strcat(AdressWork, " Hex");
		locate(0, 3, LEFT_TEXT, 1, "Endere‡o:");
		locate(0, 3, RIGHT_TEXT, 1, AdressWork);
		break;
	     case PGUP:
		aux = aux + 16;
		if(aux > 4095) aux = 0;
		itoa(aux, Adress, 16);
		strcpy(AdressWork, Adress);
		strcat(AdressWork, " Hex");
		locate(0, 3, LEFT_TEXT, 1, "Endere‡o:");
		locate(0, 3, RIGHT_TEXT, 1, AdressWork);
		break;
	     case PGDN:
		aux = aux - 16;
		if(aux < 0) aux = 4095;
		itoa(aux, Adress, 16);
		strcpy(AdressWork, Adress);
		strcat(AdressWork, " Hex");
		locate(0, 3, LEFT_TEXT, 1, "Endere‡o:");
		locate(0, 3, RIGHT_TEXT, 1, AdressWork);
		break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(tecla1)
	  {
	     case ENTER:
		Port = aux;
		itoa(Port, Adress, 16);
		limpa();
		return(OK);
	     case ESC:
		itoa(Port, Adress, 16);
		limpa();
		return(OK);
	     default: beep(Speaker);
	  }
    return(OK);
 }


 /** Fun‡ao: Base de Tempo. ************************************************/
 int base_Time()
 {
    int tecla1 = 0, tecla2 = 0, aux = Wait;
    explica("Tempo de espera entre os pulsos do dispositivo de saida.");
    janela(20, 44, 300 , 194, 0, "Base de tempo...");
    locate(0, 0, LEFT_TEXT, 0, "A base de tempo utilizada");
    locate(0, 1, LEFT_TEXT, 0, "no momento ‚:");
    strcpy(TimeWork, Time);
    strcat(TimeWork, " miliseg.");
    locate(0, 3, LEFT_TEXT, 1, "Base de tempo:");
    locate(0, 3, RIGHT_TEXT, 1, TimeWork);
    while((tecla1 = getch()) != -1)
       if(tecla1 == 0)
       {
	  tecla2 = getch();
	  switch(tecla2)
	  {
	     case UP:
		aux = aux + 1;
		if(aux > 99) aux = 0;
		itoa(aux, Time, 10);
		strcpy(TimeWork, Time);
		strcat(TimeWork, " miliseg.");
		locate(0, 3, LEFT_TEXT, 1, "Base de tempo:");
		locate(0, 3, RIGHT_TEXT, 1, TimeWork);
	     break;
	     case DOWN:
		aux = aux - 1;
		if(aux < 0) aux = 99;
		itoa(aux, Time, 10);
		strcpy(TimeWork, Time);
		strcat(TimeWork, " miliseg.");
		locate(0, 3, LEFT_TEXT, 1, "Base de tempo:");
		locate(0, 3, RIGHT_TEXT, 1, TimeWork);
	     break;
	     case PGUP:
		aux = aux + 10;
		if(aux > 99) aux = 0;
		itoa(aux, Time, 10);
		strcpy(TimeWork, Time);
		strcat(TimeWork, " miliseg.");
		locate(0, 3, LEFT_TEXT, 1, "Base de tempo:");
		locate(0, 3, RIGHT_TEXT, 1, TimeWork);
	     break;
	     case PGDN:
		aux = aux - 10;
		if(aux < 0) aux = 99;
		itoa(aux, Time, 10);
		strcpy(TimeWork, Time);
		strcat(TimeWork, " miliseg.");
		locate(0, 3, LEFT_TEXT, 1, "Base de tempo:");
		locate(0, 3, RIGHT_TEXT, 1, TimeWork);
	     break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(tecla1)
	  {
	     case ENTER:
		Wait = aux;
		itoa(Wait, Time, 10);
		limpa();
	     return(OK);
	     case ESC:
		itoa(Wait, Time, 10);
		limpa();
	     return(OK);
	     default: beep(Speaker);
       }
    return(OK);
 }


 /** Fun‡ao: Corre‡ao de Tempo. ********************************************/
 int correcao()
 {
    int tecla1 = 0, tecla2 = 0, aux = Repeat;
    explica("Repeti‡ao dos pulsos do dispositivo de saida.");
    janela(107, 58, 427, 206, 0, "Repeti‡ao de pulsos...");
    locate(0, 0, LEFT_TEXT, 0, "A repeti‡ao de pulsos est ");
    locate(0, 1, LEFT_TEXT, 0, "ajustada da seguinte forma:");
    strcpy(RepeatWork, Emulation);
    strcat(RepeatWork, " vezes.");
    locate(0, 3, LEFT_TEXT, 1, "Repeti‡ao:");
    locate(0, 3, RIGHT_TEXT, 1, RepeatWork);
    while((tecla1 = getch()) != -1)
       if(tecla1 == 0)
       {
	  tecla2 = getch();
	  switch(tecla2)
	  {
	     case UP:
		aux = aux + 1;
		if(aux > 99) aux = 0;
		itoa(aux, Emulation, 10);
		strcpy(RepeatWork, Emulation);
		strcat(RepeatWork, " vezes.");
		locate(0, 3, LEFT_TEXT, 1, "Repeti‡ao:");
		locate(0, 3, RIGHT_TEXT, 1, RepeatWork);
	     break;
	     case DOWN:
		aux = aux - 1;
		if(aux < 0) aux = 99;
		itoa(aux, Emulation , 10);
		strcpy(RepeatWork, Emulation);
		strcat(RepeatWork, " vezes.");
		locate(0, 3, LEFT_TEXT, 1, "Repeti‡ao:");
		locate(0, 3, RIGHT_TEXT, 1, RepeatWork);
	     break;
	     case PGUP:
		aux = aux + 10;
		if(aux > 99) aux = 0;
		itoa(aux, Emulation, 10);
		strcpy(RepeatWork, Emulation);
		strcat(RepeatWork, " vezes.");
		locate(0, 3, LEFT_TEXT, 1, "Repeti‡ao:");
		locate(0, 3, RIGHT_TEXT, 1, RepeatWork);
	     break;
	     case PGDN:
		aux = aux - 10;
		if(aux < 0) aux = 99;
		itoa(aux, Emulation , 10);
		strcpy(RepeatWork, Emulation);
		strcat(RepeatWork, " vezes.");
		locate(0, 3, LEFT_TEXT, 1, "Repeti‡ao:");
		locate(0, 3, RIGHT_TEXT, 1, RepeatWork);
	     break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(tecla1)
	  {
	     case ENTER:
		Repeat = aux;
		itoa(Repeat, Emulation, 10);
		limpa();
	     return(OK);
	     case ESC:
		itoa(Repeat, Emulation, 10);
		limpa();
	     return(OK);
	     default: beep(Speaker);
       }
    return(OK);
 }


 /** Fun‡ao: Configura‡ao das cores. ***************************************/
 int colors()
 {
    int tecla1 = 0, tecla2 = 0, contador = 1, Redraw = 0;
    int Old_AppWorkspace = AppWorkspace;
    int Old_Background = Background;
    int Old_Selector = Selector;
    int Old_Frame = Frame;
    int Old_Window = Window;
    int Old_ActiveWindowText = ActiveWindowText;
    int Old_ActiveBorder = ActiveBorder;
    int Old_ActiveTitle = ActiveTitle;
    int Old_InactiveBorder = InactiveBorder;
    int Old_InactiveTitle = InactiveTitle;
    int Old_InactiveWindowText = InactiveWindowText;
    int Old_ActiveObject = ActiveObject;
    int Old_InactiveObject = InactiveObject;
    int Old_ButtonFace = ButtonFace;
    int Old_ButtonText = ButtonText;
    int Old_ButtonHilight = ButtonHilight;
    int Old_ButtonShadow = ButtonShadow;
    int Old_Hilight = Hilight;
    int Old_HilightText = HilightText;
    int Old_HilightWindow = HilightWindow;
    int Old_HilightObject = HilightObject;
    int Old_Shadow = Shadow;
    int Old_ShadowObject = ShadowObject;
    int Old_ShadowText = ShadowText;
    int Old_ShadowWindow = ShadowWindow;
    int Old_Menu = Menu;
    int Old_MenuText = MenuText;
    int Old_GrayText = GrayText;

    Window_Color_Start:
    explica("Sele‡ao dos esquemas de cores.");
    janela(32, 25, 314, 300, 0, "Cores...");
    dimensao();
    if(Redraw == 0){
       locate(0, 0, LEFT_TEXT, 1, "Monocrom tico");
    }
    else
    {
       locate(0, 0, LEFT_TEXT, 0, "Monocrom tico");
    }
    paleta(0, 0, RIGHT_TEXT, BLACK);
    locate(0, 1, LEFT_TEXT, 0, "Inverso");
    paleta(0, 1, RIGHT_TEXT, WHITE);
    locate(0, 2, LEFT_TEXT, 0, "Azul");
    paleta(0, 2, RIGHT_TEXT, BLUE);
    locate(0, 3, LEFT_TEXT, 0, "Discreto");
    paleta(0, 3, RIGHT_TEXT, CYAN);
    locate(0, 4, LEFT_TEXT, 0, "Rubro");
    paleta(0, 4, RIGHT_TEXT, RED);
    locate(0, 5, LEFT_TEXT, 0, "Feliz");
    paleta(0, 5, RIGHT_TEXT, MAGENTA);
    locate(0, 6, LEFT_TEXT, 0, "Madeira");
    paleta(0, 6, RIGHT_TEXT, BROWN);
    locate(0, 7, LEFT_TEXT, 0, "Padrao");
    paleta(0, 7, RIGHT_TEXT, DARKGRAY);
    locate(0, 8, LEFT_TEXT, 0, "Cores aleat¢rias");
    botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
    if(Redraw == 1)
    {
       switch (contador)
       {
	  case 1:
	     locate(0, 0, LEFT_TEXT, 1, "Monocrom tico");
	     paleta(0, 0, RIGHT_TEXT, BLACK);
	     break;
	  case 2:
	     locate(0, 1, LEFT_TEXT, 1, "Inverso");
	     paleta(0, 1, RIGHT_TEXT, WHITE);
	     break;
	  case 3:
	     locate(0, 2, LEFT_TEXT, 1, "Azul");
	     paleta(0, 2, RIGHT_TEXT, BLUE);
	     break;
	  case 4:
	     locate(0, 3, LEFT_TEXT, 1, "Discreto");
	     paleta(0, 3, RIGHT_TEXT, CYAN);
	     break;
	  case 5:
	     locate(0, 4, LEFT_TEXT, 1, "Rubro");
	     paleta(0, 4, RIGHT_TEXT, RED);
	     break;
	  case 6:
	     locate(0, 5, LEFT_TEXT, 1, "Feliz");
	     paleta(0, 5, RIGHT_TEXT, MAGENTA);
	     break;
	  case 7:
	     locate(0, 6, LEFT_TEXT, 1, "Madeira");
	     paleta(0, 6, RIGHT_TEXT, BROWN);
	     break;
	  case 8:
	     locate(0, 7, LEFT_TEXT, 1, "Padrao");
	     paleta(0, 7, RIGHT_TEXT, DARKGRAY);
	     break;
	  case 9:
	     locate(0, 8, LEFT_TEXT, 1, "Cores aleat¢rias");
	     break;
	  default: break;
       }
       Redraw = 0;
    }
    while((tecla1 = getch()) != -1)
       if(tecla1 == 0)
       {
	  tecla2 = getch();
	  switch(tecla2)
	  {
	     case UP:
		if(contador <= 1) contador = 11;
		contador = contador - 1;
		switch (contador)
		{
		   case 1:
		      locate(0, 0, LEFT_TEXT, 1, "Monocrom tico");
		      paleta(0, 0, RIGHT_TEXT, BLACK);
		      locate(0, 1, LEFT_TEXT, 0, "Inverso");
		      paleta(0, 1, RIGHT_TEXT, WHITE);
		      break;
		   case 2:
		      locate(0, 1, LEFT_TEXT, 1, "Inverso");
		      paleta(0, 1, RIGHT_TEXT, WHITE);
		      locate(0, 2, LEFT_TEXT, 0, "Azul");
		      paleta(0, 2, RIGHT_TEXT, BLUE);
		      break;
		   case 3:
		      locate(0, 2, LEFT_TEXT, 1, "Azul");
		      paleta(0, 2, RIGHT_TEXT, BLUE);
		      locate(0, 3, LEFT_TEXT, 0, "Discreto");
		      paleta(0, 3, RIGHT_TEXT, CYAN);
		      break;
		   case 4:
		      locate(0, 3, LEFT_TEXT, 1, "Discreto");
		      paleta(0, 3, RIGHT_TEXT, CYAN);
		      locate(0, 4, LEFT_TEXT, 0, "Rubro");
		      paleta(0, 4, RIGHT_TEXT, RED);
		      break;
		   case 5:
		      locate(0, 4, LEFT_TEXT, 1, "Rubro");
		      paleta(0, 4, RIGHT_TEXT, RED);
		      locate(0, 5, LEFT_TEXT, 0, "Feliz");
		      paleta(0, 5, RIGHT_TEXT, MAGENTA);
		      break;
		   case 6:
		      locate(0, 5, LEFT_TEXT, 1, "Feliz");
		      paleta(0, 5, RIGHT_TEXT, MAGENTA);
		      locate(0, 6, LEFT_TEXT, 0, "Madeira");
		      paleta(0, 6, RIGHT_TEXT, BROWN);
		      break;
		   case 7:
		      locate(0, 6, LEFT_TEXT, 1, "Madeira");
		      paleta(0, 6, RIGHT_TEXT, BROWN);
		      locate(0, 7, LEFT_TEXT, 0, "Padrao");
		      paleta(0, 7, RIGHT_TEXT, DARKGRAY);
		      break;
		   case 8:
		      locate(0, 7, LEFT_TEXT, 1, "Padrao");
		      paleta(0, 7, RIGHT_TEXT, DARKGRAY);
		      locate(0, 8, LEFT_TEXT, 0, "Cores aleat¢rias");
		      break;
		   case 9:
		      locate(0, 8, LEFT_TEXT, 1, "Cores aleat¢rias");
		      botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
			    0, 0, 0, "OK");
		      break;
		   case 10:
		      botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
			    0, 0, 1, "OK");
		      locate(0, 0, LEFT_TEXT, 0, "Monocrom tico");
		      paleta(0, 0, RIGHT_TEXT, BLACK);
		      break;
		   default: break;
		}
	     break;
	     case DOWN:
		if(contador == 10) contador = 0;
		contador = contador + 1;
		if(contador == 1)
		{
		   botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
			 0, 0, 0, "OK");
		   locate(0, 0, LEFT_TEXT, 1, "Monocrom tico");
		   paleta(0, 0, RIGHT_TEXT, BLACK);
		}
		if(contador == 2)
		{
		   locate(0, 0, LEFT_TEXT, 0, "Monocrom tico");
		   paleta(0, 0, RIGHT_TEXT, BLACK);
		   locate(0, 1, LEFT_TEXT, 1, "Inverso");
		   paleta(0, 1, RIGHT_TEXT, WHITE);
		}
		if(contador == 3)
		{
		   locate(0, 1, LEFT_TEXT, 0, "Inverso");
		   paleta(0, 1, RIGHT_TEXT, WHITE);
		   locate(0, 2, LEFT_TEXT, 1, "Azul");
		   paleta(0, 2, RIGHT_TEXT, BLUE);
		}
		if(contador == 4)
		{
		   locate(0, 2, LEFT_TEXT, 0, "Azul");
		   paleta(0, 2, RIGHT_TEXT, BLUE);
		   locate(0, 3, LEFT_TEXT, 1, "Discreto");
		   paleta(0, 3, RIGHT_TEXT, CYAN);
		}
		if(contador == 5)
		{
		   locate(0, 3, LEFT_TEXT, 0, "Discreto");
		   paleta(0, 3, RIGHT_TEXT, CYAN);
		   locate(0, 4, LEFT_TEXT, 1, "Rubro");
		   paleta(0, 4, RIGHT_TEXT, RED);
		}
		if(contador == 6)
		{
		   locate(0, 4, LEFT_TEXT, 0, "Rubro");
		   paleta(0, 4, RIGHT_TEXT, RED);
		   locate(0, 5, LEFT_TEXT, 1, "Feliz");
		   paleta(0, 5, RIGHT_TEXT, MAGENTA);
		}
		if(contador == 7)
		{
		   locate(0, 5, LEFT_TEXT, 0, "Feliz");
		   paleta(0, 5, RIGHT_TEXT, MAGENTA);
		   locate(0, 6, LEFT_TEXT, 1, "Madeira");
		   paleta(0, 6, RIGHT_TEXT, BROWN);
		}
		if(contador == 8)
		{
		   locate(0, 6, LEFT_TEXT, 0, "Madeira");
		   paleta(0, 6, RIGHT_TEXT, BROWN);
		   locate(0, 7, LEFT_TEXT, 1, "Padrao");
		   paleta(0, 7, RIGHT_TEXT, DARKGRAY);
		}
		if(contador == 9)
		{
		   locate(0, 7, LEFT_TEXT, 0, "Padrao");
		   paleta(0, 7, RIGHT_TEXT, DARKGRAY);
		   locate(0, 8, LEFT_TEXT, 1, "Cores aleat¢rias");
		}
		if(contador == 10)
		{
		   locate(0, 8, LEFT_TEXT, 0, "Cores aleat¢rias");
		   botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
			 0, 0, 1, "OK");
		}
	     break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(tecla1)
	  {
	     case ENTER:
		if(contador == 1) /** Esquema Monocrom tico. ***************/
		{
		   AppWorkspace = 0;
		   Background = DARKGRAY;
		   Selector = DARKGRAY;
		   Frame = BLACK;
		   Window = WHITE;
		   ActiveWindowText = BLACK;
		   ActiveBorder = LIGHTGRAY;
		   ActiveTitle = BLACK;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = WHITE;
		   InactiveObject = LIGHTGRAY;
		   ButtonFace = LIGHTGRAY;
		   ButtonText = BLACK;
		   ButtonHilight = WHITE;
		   ButtonShadow = DARKGRAY;
		   Hilight = LIGHTGRAY;
		   HilightText = WHITE;
		   HilightWindow = WHITE;
		   HilightObject = WHITE;
		   Shadow = BLACK;
		   ShadowObject = BLACK;
		   ShadowText = BLACK;
		   ShadowWindow = DARKGRAY;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 2) /** Esquema Inverso. *****************/
		{
		   AppWorkspace = 0;
		   Background = BLACK;
		   Selector = LIGHTGRAY;
		   Frame = WHITE;
		   Window = BLACK;
		   ActiveWindowText = WHITE;
		   ActiveBorder = LIGHTGRAY;
		   ActiveTitle = BLACK;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = DARKGRAY;
		   InactiveObject = LIGHTGRAY;
		   ButtonFace = LIGHTGRAY;
		   ButtonText = BLACK;
		   ButtonHilight = DARKGRAY;
		   ButtonShadow = WHITE;
		   Hilight = LIGHTGRAY;
		   HilightText = LIGHTGRAY;
		   HilightWindow = BLACK;
		   HilightObject = BLACK;
		   Shadow = WHITE;
		   ShadowObject = WHITE;
		   ShadowText = WHITE;
		   ShadowWindow = WHITE;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 3) /** Esquema Azul. ************************/
		{
		   AppWorkspace = 0;
		   Background = BLUE;
		   Selector = LIGHTBLUE;
		   Frame = BLACK;
		   Window = WHITE;
		   ActiveWindowText = BLUE;
		   ActiveBorder = LIGHTBLUE;
		   ActiveTitle = WHITE;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = WHITE;
		   InactiveObject = LIGHTBLUE;
		   ButtonFace = LIGHTBLUE;
		   ButtonText = WHITE;
		   ButtonHilight = WHITE;
		   ButtonShadow = DARKGRAY;
		   Hilight = LIGHTBLUE;
		   HilightText = WHITE;
		   HilightWindow = WHITE;
		   HilightObject = WHITE;
		   Shadow = BLACK;
		   ShadowObject = BLACK;
		   ShadowText = BLACK;
		   ShadowWindow = DARKGRAY;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 4) /** Esquema Discreto. ********************/
		{
		   AppWorkspace = 0;
		   Background = CYAN;
		   Selector = CYAN;
		   Frame = BLACK;
		   Window = WHITE;
		   ActiveWindowText = BLACK;
		   ActiveBorder = LIGHTCYAN;
		   ActiveTitle = BLACK;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = WHITE;
		   InactiveObject = LIGHTCYAN;
		   ButtonFace = LIGHTCYAN;
		   ButtonText = BLACK;
		   ButtonHilight = WHITE;
		   ButtonShadow = DARKGRAY;
		   Hilight = LIGHTCYAN;
		   HilightText = WHITE;
		   HilightWindow = WHITE;
		   HilightObject = WHITE;
		   Shadow = DARKGRAY;
		   ShadowObject = BLACK;
		   ShadowText = BLACK;
		   ShadowWindow = DARKGRAY;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 5) /** Esquema Rubro. ***********************/
		{
		   AppWorkspace = 0;
		   Background = RED;
		   Selector = RED;
		   Frame = BLACK;
		   Window = WHITE;
		   ActiveWindowText = RED;
		   ActiveBorder = LIGHTRED;
		   ActiveTitle = BLACK;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = WHITE;
		   InactiveObject = LIGHTRED;
		   ButtonFace = LIGHTRED;
		   ButtonText = WHITE;
		   ButtonHilight = WHITE;
		   ButtonShadow = DARKGRAY;
		   Hilight = LIGHTRED;
		   HilightText = WHITE;
		   HilightWindow = WHITE;
		   HilightObject = WHITE;
		   Shadow = BLACK;
		   ShadowObject = BLACK;
		   ShadowText = BLACK;
		   ShadowWindow = DARKGRAY;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 6) /** Esquema Feliz. ***********************/
		{
		   AppWorkspace = 0;
		   Background = MAGENTA;
		   Selector = MAGENTA;
		   Frame = BLACK;
		   Window = WHITE;
		   ActiveWindowText = MAGENTA;
		   ActiveBorder = LIGHTMAGENTA;
		   ActiveTitle = BLACK;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = WHITE;
		   InactiveObject = LIGHTMAGENTA;
		   ButtonFace = LIGHTMAGENTA;
		   ButtonText = WHITE;
		   ButtonHilight = WHITE;
		   ButtonShadow = DARKGRAY;
		   Hilight = LIGHTMAGENTA;
		   HilightText = WHITE;
		   HilightWindow = WHITE;
		   HilightObject = WHITE;
		   Shadow = BLACK;
		   ShadowObject = BLACK;
		   ShadowText = BLACK;
		   ShadowWindow = DARKGRAY;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 7) /** Esquema Madeira. *********************/
		{
		   AppWorkspace = 0;
		   Background = BROWN;
		   Selector = BROWN;
		   Frame = BLACK;
		   Window = WHITE;
		   ActiveWindowText = BLACK;
		   ActiveBorder = BROWN;
		   ActiveTitle = WHITE;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = WHITE;
		   InactiveObject = YELLOW;
		   ButtonFace = BROWN;
		   ButtonText = WHITE;
		   ButtonHilight = WHITE;
		   ButtonShadow = DARKGRAY;
		   Hilight = LIGHTGRAY;
		   HilightText = WHITE;
		   HilightWindow = WHITE;
		   HilightObject = WHITE;
		   Shadow = BLACK;
		   ShadowObject = BLACK;
		   ShadowText = BLACK;
		   ShadowWindow = BLACK;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 8) /** Esquema Padrao. **********************/
		{
		   AppWorkspace = 0;
		   Background = DARKGRAY;
		   Selector = DARKGRAY;
		   Frame = BLACK;
		   Window = WHITE;
		   ActiveWindowText = BLACK;
		   ActiveBorder = LIGHTGRAY;
		   ActiveTitle = BLACK;
		   InactiveBorder = 0;
		   InactiveTitle = 0;
		   InactiveWindowText = 0;
		   ActiveObject = LIGHTGREEN;
		   InactiveObject = GREEN;
		   ButtonFace = LIGHTGRAY;
		   ButtonText = BLACK;
		   ButtonHilight = WHITE;
		   ButtonShadow = DARKGRAY;
		   Hilight = LIGHTGRAY;
		   HilightText = WHITE;
		   HilightWindow = WHITE;
		   HilightObject = WHITE;
		   Shadow = BLACK;
		   ShadowObject = BLACK;
		   ShadowText = BLACK;
		   ShadowWindow = DARKGRAY;
		   Menu = WHITE;
		   MenuText = BLACK;
		   GrayText = LIGHTGRAY;
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 9) /** Esquema aleatorio. *******************/
		{
		   AppWorkspace = random(getmaxcolor());
		   Background = random(getmaxcolor());
		   Selector = random(getmaxcolor());
		   Frame = random(getmaxcolor());
		   Window = random(getmaxcolor());
		   ActiveWindowText = random(getmaxcolor());
		   ActiveBorder = random(getmaxcolor());
		   ActiveTitle = random(getmaxcolor());
		   InactiveBorder = random(getmaxcolor());
		   InactiveTitle = random(getmaxcolor());
		   InactiveWindowText = random(getmaxcolor());
		   ActiveObject = random(getmaxcolor());
		   InactiveObject = random(getmaxcolor());
		   ButtonFace = random(getmaxcolor());
		   ButtonText = random(getmaxcolor());
		   ButtonHilight = random(getmaxcolor());
		   ButtonShadow = random(getmaxcolor());
		   Hilight = random(getmaxcolor());
		   HilightText = random(getmaxcolor());
		   HilightWindow = random(getmaxcolor());
		   HilightObject = random(getmaxcolor());
		   Shadow = random(getmaxcolor());
		   ShadowObject = random(getmaxcolor());
		   ShadowText = random(getmaxcolor());
		   ShadowWindow = random(getmaxcolor());
		   Menu = random(getmaxcolor());
		   MenuText = random(getmaxcolor());
		   GrayText = random(getmaxcolor());
		   Redraw = 1;
		   limpa();
		   goto Window_Color_Start;
		}
		if(contador == 10) /** Aceitacao do esquema escolhido. *****/
		{
		   /** Atualiza variaveis do modo grafico. *****************/
		   copygraphvar(AppWorkspace,
				Background, Selector, Frame,
				Window, ActiveWindowText,
				ActiveBorder, ActiveTitle,
				InactiveBorder, InactiveTitle,
				InactiveWindowText,
				ActiveObject, InactiveObject,
				ButtonFace, ButtonText,
				ButtonHilight, ButtonShadow,
				Hilight, HilightText,
				HilightWindow, HilightObject,
				Shadow, ShadowObject,
				ShadowText, ShadowWindow,
				Menu, MenuText, GrayText,
				Animate);
		   botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
			 0, 1, 1, "OK");
		   delay(50);
		   limpa();
		   return(OK);
		}
	     break;
	     case ESC: /** Rejeicao do esquema escolhido. ******************/
		AppWorkspace = Old_AppWorkspace;
		Background = Old_Background;
		Selector = Old_Selector;
		Frame = Old_Frame;
		Window = Old_Window;
		ActiveWindowText = Old_ActiveWindowText;
		ActiveBorder = Old_ActiveBorder;
		ActiveTitle = Old_ActiveTitle;
		InactiveBorder = Old_InactiveBorder;
		InactiveTitle = Old_InactiveTitle;
		InactiveWindowText = Old_InactiveWindowText;
		ActiveObject = Old_ActiveObject;
		InactiveObject = Old_InactiveObject;
		ButtonFace = Old_ButtonFace;
		ButtonText = Old_ButtonText;
		ButtonHilight = Old_ButtonHilight;
		ButtonShadow = Old_ButtonShadow;
		Hilight = Old_Hilight;
		HilightText = Old_HilightText;
		HilightWindow = Old_HilightWindow;
		HilightObject = Old_HilightObject;
		Shadow = Old_Shadow;
		ShadowObject = Old_ShadowObject;
		ShadowText = Old_ShadowText;
		ShadowWindow = Old_ShadowWindow;
		Menu = Old_Menu;
		MenuText = Old_MenuText;
		GrayText = Old_GrayText;
		limpa();
		return(OK);
	     default: beep(Speaker);
	  }
    return(OK);
 }


 /** Fun‡ao: Passos da anima‡ao. *******************************************/
 int animacao()
 {
    int tecla1 = 0, tecla2 = 0;
    int anim_buffer = Animate;
    char anim[16];

    itoa(anim_buffer, anim, 10);
    strcat(anim, " passos");

    explica("Velocidade das janelas animadas.");
    janela(80, 100, 410, 250, 0, "Anima‡oes...");
    locate(0, 0, LEFT_TEXT, 0, "Selecione a velocidade de");
    locate(0, 1, LEFT_TEXT, 0, "exibi‡ao das janelas animadas:");
    locate(0, 3, LEFT_TEXT, 1, "Velocidade:");
    locate(0, 3, RIGHT_TEXT, 1, anim);

    while((tecla1 = getch()) != -1)
       if(tecla1 == 0)
       {
	  tecla2 = getch();
	  switch(tecla2)
	  {
	     case UP:
		anim_buffer = anim_buffer + 1;
		if(anim_buffer > 99) anim_buffer = 1;
		itoa(anim_buffer, anim, 10);
		strcat(anim, " passos");
		locate(0, 3, LEFT_TEXT, 1, "Velocidade:");
		locate(0, 3, RIGHT_TEXT, 1, anim);
	     break;
	     case DOWN:
		anim_buffer = anim_buffer - 1;
		if(anim_buffer < 1) anim_buffer = 99;
		itoa(anim_buffer, anim, 10);
		strcat(anim, " passos");
		locate(0, 3, LEFT_TEXT, 1, "Velocidade:");
		locate(0, 3, RIGHT_TEXT, 1, anim);
	     break;
	     case PGUP:
		anim_buffer = anim_buffer + 10;
		if(anim_buffer > 99) anim_buffer = 1;
		itoa(anim_buffer, anim, 10);
		strcat(anim, " passos");
		locate(0, 3, LEFT_TEXT, 1, "Velocidade:");
		locate(0, 3, RIGHT_TEXT, 1, anim);
	     break;
	     case PGDN:
		anim_buffer = anim_buffer - 10;
		if(anim_buffer < 1) anim_buffer = 99;
		itoa(anim_buffer, anim, 10);
		strcat(anim, " passos");
		locate(0, 3, LEFT_TEXT, 1, "Velocidade:");
		locate(0, 3, RIGHT_TEXT, 1, anim);
	     break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(tecla1)
	  {
	     case ENTER:
		Animate = anim_buffer;
		   copygraphvar(AppWorkspace,
				Background, Selector, Frame,
				Window, ActiveWindowText,
				ActiveBorder, ActiveTitle,
				InactiveBorder, InactiveTitle,
				InactiveWindowText,
				ActiveObject, InactiveObject,
				ButtonFace, ButtonText,
				ButtonHilight, ButtonShadow,
				Hilight, HilightText,
				HilightWindow, HilightObject,
				Shadow, ShadowObject,
				ShadowText, ShadowWindow,
				Menu, MenuText, GrayText,
				Animate);
		limpa();
	     return(OK);
	     case ESC:
		limpa();
	     return(OK);
	     default: beep(Speaker);
	  }
    return(OK);
 }


 /** Ajusta intermitencia do cursor do teclado. ****************************/
 int keybspeed()
 {
    int MinChars = 0;
    int MaxChars = 31;
    int MinDelay = 0;
    int MaxDelay = 3;
    int Contador_1 = 0, Contador_3 = 0, Contador_4 = 0;
    float Contador_2 = 0;
    int Auxiliar_1 = 0;
    float Auxiliar_2 = 0;
    char AuxiliarTexto[8];
    char DelayInMiliseg[32];
    char CharPerSecond[16];
    int Tecla_1 = 0, Tecla_2 = 0;

    explica("Ajusta intermitencia do cursor do teclado.");
    janela(20, 45, 300, 305, 0, "Ajustar teclado");
    dimensao();
    /** Desenha linha divisora central horizontal. *************************/
    setcolor(Frame);
    line(10, MidWindow_y, MaxWindow_x - 10, MidWindow_y);
    /** Exibe dados da janela de caracteres/segundo. ***********************/
    Contador_1 = MaxChars;
    Contador_2 = 30;
    locate(0, 0, LEFT_TEXT, 0, "Lento");
    locate(0, 0, RIGHT_TEXT, 0, "R pido");
    strcpy(CharPerSecond, "30.0");
    print(4, 5, ActiveWindowText, "Caracteres/segundo");
    print(1, 5, ActiveWindowText, CharPerSecond);
    crazy(MinChars, MaxChars, MaxChars,
	  7, 0,
	  20, 50, HORIZ_DIR);
    /** Exibe dados da janela de espera(milisegundos). *********************/
    Contador_3 = MaxDelay;
    Contador_4 = 250;
    print(2, 7, ActiveWindowText, "Longo");
    print(2, 11, ActiveWindowText, "Curto");
    strcpy(DelayInMiliseg, "250 miliseg.");
    print(4, 9, ActiveWindowText, DelayInMiliseg);
    crazy(MinDelay, MaxDelay, MaxDelay,
	  24, 0,
	  20, 130, VERT_DIR);
    /** Exibe botao de conclusao de operacao. ******************************/
    botao(MaxWindow_x - 40, MaxWindow_y - VerticalSizeButton,
	  0, 0, 1, "OK");
    while((Tecla_1 = getch()) != -1)
       if(Tecla_1 == 0)
       {
	  Tecla_2 = getch();
	  switch(Tecla_2)
	  {
	     case LEFT:
		Contador_1 = Contador_1 - 1;
		if(Contador_1 < MinChars) { Contador_1 = MinChars; }
		crazy(MinChars, MaxChars, Contador_1,
		      7, 0,
		      20, 50, HORIZ_DIR);

		setfillstyle(1, Window);
		bar(19, 85, 71, 95);
		switch (Contador_1)
		{
		   case 0:  Contador_2 = 2;    break;
		   case 1:  Contador_2 = 2.1;  break;
		   case 2:  Contador_2 = 2.3;  break;
		   case 3:  Contador_2 = 2.5;  break;
		   case 4:  Contador_2 = 2.7;  break;
		   case 5:  Contador_2 = 3;    break;
		   case 6:  Contador_2 = 3.3;  break;
		   case 7:  Contador_2 = 3.7;  break;
		   case 8:  Contador_2 = 4;    break;
		   case 9:  Contador_2 = 4.3;  break;
		   case 10: Contador_2 = 4.6;  break;
		   case 11: Contador_2 = 5;    break;
		   case 12: Contador_2 = 5.5;  break;
		   case 13: Contador_2 = 6;    break;
		   case 14: Contador_2 = 6.7;  break;
		   case 15: Contador_2 = 7.5;  break;
		   case 16: Contador_2 = 8;    break;
		   case 17: Contador_2 = 8.6;  break;
		   case 18: Contador_2 = 9.2;  break;
		   case 19: Contador_2 = 10;   break;
		   case 20: Contador_2 = 10.9; break;
		   case 21: Contador_2 = 12;   break;
		   case 22: Contador_2 = 13.3; break;
		   case 23: Contador_2 = 15;   break;
		   case 24: Contador_2 = 16;   break;
		   case 25: Contador_2 = 17.1; break;
		   case 26: Contador_2 = 18.5; break;
		   case 27: Contador_2 = 20;   break;
		   case 28: Contador_2 = 21.8; break;
		   case 29: Contador_2 = 24;   break;
		   case 30: Contador_2 = 26.7; break;
		   case 31: Contador_2 = 30;   break;
		   default: break;
		}
		Auxiliar_1 = abs(Contador_2);
		itoa(Auxiliar_1, CharPerSecond, 10);
		strcat(CharPerSecond, ".");
		Auxiliar_2 = Contador_2 - Auxiliar_1;
		Auxiliar_2 = Auxiliar_2 * 10;
		Auxiliar_1 = abs(Auxiliar_2);
		itoa(Auxiliar_1, AuxiliarTexto, 10);
		strcat(CharPerSecond, AuxiliarTexto);
		print(1, 5, ActiveWindowText, CharPerSecond);
		break;
	     case RIGHT:
		Contador_1 = Contador_1 + 1;
		if(Contador_1 > MaxChars) { Contador_1 = MaxChars; }
		crazy(MinChars, MaxChars, Contador_1,
		      7, 0,
		      20, 50, HORIZ_DIR);

		setfillstyle(1, Window);
		bar(19, 85, 71, 95);
		switch (Contador_1)
		{
		   case 0:  Contador_2 = 2;    break;
		   case 1:  Contador_2 = 2.1;  break;
		   case 2:  Contador_2 = 2.3;  break;
		   case 3:  Contador_2 = 2.5;  break;
		   case 4:  Contador_2 = 2.7;  break;
		   case 5:  Contador_2 = 3;    break;
		   case 6:  Contador_2 = 3.3;  break;
		   case 7:  Contador_2 = 3.7;  break;
		   case 8:  Contador_2 = 4;    break;
		   case 9:  Contador_2 = 4.3;  break;
		   case 10: Contador_2 = 4.6;  break;
		   case 11: Contador_2 = 5;    break;
		   case 12: Contador_2 = 5.5;  break;
		   case 13: Contador_2 = 6;    break;
		   case 14: Contador_2 = 6.7;  break;
		   case 15: Contador_2 = 7.5;  break;
		   case 16: Contador_2 = 8;    break;
		   case 17: Contador_2 = 8.6;  break;
		   case 18: Contador_2 = 9.2;  break;
		   case 19: Contador_2 = 10;   break;
		   case 20: Contador_2 = 10.9; break;
		   case 21: Contador_2 = 12;   break;
		   case 22: Contador_2 = 13.3; break;
		   case 23: Contador_2 = 15;   break;
		   case 24: Contador_2 = 16;   break;
		   case 25: Contador_2 = 17.1; break;
		   case 26: Contador_2 = 18.5; break;
		   case 27: Contador_2 = 20;   break;
		   case 28: Contador_2 = 21.8; break;
		   case 29: Contador_2 = 24;   break;
		   case 30: Contador_2 = 26.7; break;
		   case 31: Contador_2 = 30;   break;
		   default: break;
		}
		Auxiliar_1 = abs(Contador_2);
		itoa(Auxiliar_1, CharPerSecond, 10);
		strcat(CharPerSecond, ".");
		Auxiliar_2 = Contador_2 - Auxiliar_1;
		Auxiliar_2 = Auxiliar_2 * 10;
		Auxiliar_1 = abs(Auxiliar_2);
		itoa(Auxiliar_1, AuxiliarTexto, 10);
		strcat(CharPerSecond, AuxiliarTexto);
		print(1, 5, ActiveWindowText, CharPerSecond);
		break;
	     case UP:
		Contador_3 = Contador_3 - 1;
		if(Contador_3 < MinDelay) { Contador_3 = MinDelay; }
		crazy(MinDelay, MaxDelay, Contador_3,
		      24, 1,
		      20, 130, VERT_DIR);
		switch (Contador_3)
		{
		   case 0:
		      Contador_4 = 1000;
		      strcpy(DelayInMiliseg, "1000 miliseg.");
		      break;
		   case 1:
		      Contador_4 = 750;
		      strcpy(DelayInMiliseg, "750 miliseg.");
		      break;
		   case 2:
		      Contador_4 = 500;
		      strcpy(DelayInMiliseg, "500 miliseg.");
		      break;
		   case 3:
		      Contador_4 = 250;
		      strcpy(DelayInMiliseg, "250 miliseg.");
		      break;
		   default: break;
		}
		setfillstyle(1, Window);
		bar(75, 161, 191, 174);
		print(4, 9, ActiveWindowText, DelayInMiliseg);
		break;
	     case DOWN:
		Contador_3 = Contador_3 + 1;
		if(Contador_3 > MaxDelay) { Contador_3 = MaxDelay; }
		crazy(MinDelay, MaxDelay, Contador_3,
		      24, 1,
		      20, 130, VERT_DIR);
		switch (Contador_3)
		{
		   case 0:
		      Contador_4 = 1000;
		      strcpy(DelayInMiliseg, "1000 miliseg.");
		      break;
		   case 1:
		      Contador_4 = 750;
		      strcpy(DelayInMiliseg, "750 miliseg.");
		      break;
		   case 2:
		      Contador_4 = 500;
		      strcpy(DelayInMiliseg, "500 miliseg.");
		      break;
		   case 3:
		      Contador_4 = 250;
		      strcpy(DelayInMiliseg, "250 miliseg.");
		      break;
		   default: break;
		}
		setfillstyle(1, Window);
		bar(75, 161, 191, 174);
		print(4, 9, ActiveWindowText, DelayInMiliseg);
		break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(Tecla_1)
	  {
	     case ENTER:
		kbrate(Contador_2, Contador_4);
		botao(MaxWindow_x - 40, MaxWindow_y - VerticalSizeButton,
		0, 1, 1, "OK");
		delay(100);
		limpa();
		return(OK);
	     case ESC:
		limpa();
		return(OK);
	     default: beep(Speaker);
	  }
    return(ERROR);
 }


 /** Ajusta tempo de varredura do mouse. ***********************************/
 int mousespeed()
 {
    int MinDelay = 0;
    int MaxDelay = 99;
    int Contador_1 = MouseScanDelay;
    char DelayInMiliseg[32];
    int Tecla_1 = 0, Tecla_2 = 0;

    explica("Ajusta tempo de varredura do mouse.");
    janela(35, 60, 310, 190, 0, "Ajustar mouse");
    dimensao();
    /** Exibe dados da janela. *********************************************/
    print(1, 1, ActiveWindowText, "Curto");
    print(10, 1, ActiveWindowText, "Longo");
    itoa(Contador_1, DelayInMiliseg, 10);
    print(1, 4, ActiveWindowText, DelayInMiliseg);
    print(3, 4, ActiveWindowText, "milisegundos");
    crazy(MinDelay, MaxDelay, Contador_1,
	  2, 0,
	  25, 30, HORIZ_DIR);
    /** Exibe botao de conclusao de operacao. ******************************/
    botao(MaxWindow_x - 40, MaxWindow_y - VerticalSizeButton,
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
		setfillstyle(1, Window);
		bar(19, 66, 35, 76);
		itoa(Contador_1, DelayInMiliseg, 10);
		print(1, 4, ActiveWindowText, DelayInMiliseg);
		break;
	     case RIGHT:
		Contador_1 = Contador_1 + 1;
		if(Contador_1 > MaxDelay) { Contador_1 = MaxDelay; }
		crazy(MinDelay, MaxDelay, Contador_1,
		      2, 0,
		      25, 30, HORIZ_DIR);
		setfillstyle(1, Window);
		bar(19, 66, 35, 76);
		itoa(Contador_1, DelayInMiliseg, 10);
		print(1, 4, ActiveWindowText, DelayInMiliseg);
		break;
	     default: beep(Speaker);
	  }
       }
       else
	  switch(Tecla_1)
	  {
	     case ENTER:
		MouseScanDelay = Contador_1;
		botao(MaxWindow_x - 40, MaxWindow_y - VerticalSizeButton,
		0, 1, 1, "OK");
		delay(100);
		limpa();
		return(OK);
	     case ESC:
		limpa();
		return(OK);
	     default: beep(Speaker);
	  }
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

    printf("#       Botao 0  = %s\n#       Botao 1  = %s\n",
	   MouseButton0Name, MouseButton1Name);
    printf("#       Sobe     = %s\n#       Desce    = %s\n#       Direita  = %s\n#       Esquerda = %s\n",
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

    /** Atribuicoes da seta superior. **************************************/
    Mouse_u[0]  = 40 + Mouse_x;
    Mouse_u[1]  =  1 + Mouse_y;
    Mouse_u[2]  = 57 + Mouse_x;
    Mouse_u[3]  = 18 + Mouse_y;
    Mouse_u[4]  = 49 + Mouse_x;
    Mouse_u[5]  = 18 + Mouse_y;
    Mouse_u[6]  = 49 + Mouse_x;
    Mouse_u[7]  = 25 + Mouse_y;
    Mouse_u[8]  = 31 + Mouse_x;
    Mouse_u[9]  = 25 + Mouse_y;
    Mouse_u[10] = 31 + Mouse_x;
    Mouse_u[11] = 18 + Mouse_y;
    Mouse_u[12] = 23 + Mouse_x;
    Mouse_u[13] = 18 + Mouse_y;
    /** Atribuicoes da seta inferior. **************************************/
    Mouse_d[0]  = 40 + Mouse_x;
    Mouse_d[1]  = 79 + Mouse_y;
    Mouse_d[2]  = 23 + Mouse_x;
    Mouse_d[3]  = 62 + Mouse_y;
    Mouse_d[4]  = 31 + Mouse_x;
    Mouse_d[5]  = 62 + Mouse_y;
    Mouse_d[6]  = 31 + Mouse_x;
    Mouse_d[7]  = 55 + Mouse_y;
    Mouse_d[8]  = 49 + Mouse_x;
    Mouse_d[9]  = 55 + Mouse_y;
    Mouse_d[10] = 49 + Mouse_x;
    Mouse_d[11] = 62 + Mouse_y;
    Mouse_d[12] = 57 + Mouse_x;
    Mouse_d[13] = 62 + Mouse_y;
    /** Atribuicoes da seta esquerda. **************************************/
    Mouse_l[0]  =  1 + Mouse_x;
    Mouse_l[1]  = 40 + Mouse_y;
    Mouse_l[2]  = 18 + Mouse_x;
    Mouse_l[3]  = 23 + Mouse_y;
    Mouse_l[4]  = 18 + Mouse_x;
    Mouse_l[5]  = 31 + Mouse_y;
    Mouse_l[6]  = 25 + Mouse_x;
    Mouse_l[7]  = 31 + Mouse_y;
    Mouse_l[8]  = 25 + Mouse_x;
    Mouse_l[9]  = 49 + Mouse_y;
    Mouse_l[10] = 18 + Mouse_x;
    Mouse_l[11] = 49 + Mouse_y;
    Mouse_l[12] = 18 + Mouse_x;
    Mouse_l[13] = 57 + Mouse_y;
    /** Atribuicoes da seta direita. ***************************************/
    Mouse_r[0]  = 79 + Mouse_x;
    Mouse_r[1]  = 40 + Mouse_y;
    Mouse_r[2]  = 62 + Mouse_x;
    Mouse_r[3]  = 57 + Mouse_y;
    Mouse_r[4]  = 62 + Mouse_x;
    Mouse_r[5]  = 49 + Mouse_y;
    Mouse_r[6]  = 55 + Mouse_x;
    Mouse_r[7]  = 49 + Mouse_y;
    Mouse_r[8]  = 55 + Mouse_x;
    Mouse_r[9]  = 31 + Mouse_y;
    Mouse_r[10] = 62 + Mouse_x;
    Mouse_r[11] = 31 + Mouse_y;
    Mouse_r[12] = 62 + Mouse_x;
    Mouse_r[13] = 23 + Mouse_y;

    /** Inicia dispositivo, exibindo sua aparencia. ************************/
    if(opcao == RESET){
       /** Moldura tridimensional do mouse. ********************************/
       setcolor(HilightObject);
       /** Moldura hight-light de b0. **************************************/
       line(100 + Mouse_x, 30 + Mouse_y, 100 + Mouse_x, 10 + Mouse_y);
       line(100 + Mouse_x, 10 + Mouse_y, 140 + Mouse_x, 10 + Mouse_y);
       /** Moldura hight-light de b1. **************************************/
       line(100 + Mouse_x, 70 + Mouse_y, 100 + Mouse_x, 50 + Mouse_y);
       line(100 + Mouse_x, 50 + Mouse_y, 140 + Mouse_x, 50 + Mouse_y);
       /** Moldura hight-light superior. ***********************************/
       line(30 + Mouse_x, 26 + Mouse_y, 30 + Mouse_x, 19 + Mouse_y);
       line(30 + Mouse_x, 19 + Mouse_y, 21 + Mouse_x, 19 + Mouse_y);
       line(21 + Mouse_x, 19 + Mouse_y, 40 + Mouse_x,  0 + Mouse_y);
       /** Moldura hight-light inferior. ***********************************/
       line(21 + Mouse_x, 61 + Mouse_y, 30 + Mouse_x, 61 + Mouse_y);
       line(30 + Mouse_x, 61 + Mouse_y, 30 + Mouse_x, 54 + Mouse_y);
       line(30 + Mouse_x, 54 + Mouse_y, 50 + Mouse_x, 54 + Mouse_y);
       /** Moldura hight-light direita. ************************************/
       line(54 + Mouse_x, 50 + Mouse_y, 54 + Mouse_x, 30 + Mouse_y);
       line(54 + Mouse_x, 30 + Mouse_y, 61 + Mouse_x, 30 + Mouse_y);
       line(61 + Mouse_x, 30 + Mouse_y, 61 + Mouse_x, 21 + Mouse_y);
       /** Moldura hight-light esquerda. ***********************************/
       line( 0 + Mouse_x, 40 + Mouse_y, 19 + Mouse_x, 21 + Mouse_y);
       line(19 + Mouse_x, 21 + Mouse_y, 19 + Mouse_x, 30 + Mouse_y);
       line(19 + Mouse_x, 30 + Mouse_y, 26 + Mouse_x, 30 + Mouse_y);
       setcolor(ShadowObject);
       /** Moldura back-light de b0. ***************************************/
       line(140 + Mouse_x, 11 + Mouse_y, 140 + Mouse_x, 30 + Mouse_y);
       line(140 + Mouse_x, 30 + Mouse_y, 101 + Mouse_x, 30 + Mouse_y);
       /** Moldura back-light de b1. ***************************************/
       line(140 + Mouse_x, 51 + Mouse_y, 140 + Mouse_x, 70 + Mouse_y);
       line(140 + Mouse_x, 70 + Mouse_y, 101 + Mouse_x, 70 + Mouse_y);
       /** Moldura back-light superior. ************************************/
       line(41 + Mouse_x,  1 + Mouse_y, 59 + Mouse_x, 19 + Mouse_y);
       line(59 + Mouse_x, 19 + Mouse_y, 50 + Mouse_x, 19 + Mouse_y);
       line(50 + Mouse_x, 19 + Mouse_y, 50 + Mouse_x, 26 + Mouse_y);
       line(50 + Mouse_x, 26 + Mouse_y, 31 + Mouse_x, 26 + Mouse_y);
       /** Moldura back-light inferior. ************************************/
       line(50 + Mouse_x, 55 + Mouse_y, 50 + Mouse_x, 61 + Mouse_y);
       line(50 + Mouse_x, 61 + Mouse_y, 59 + Mouse_x, 61 + Mouse_y);
       line(59 + Mouse_x, 61 + Mouse_y, 40 + Mouse_x, 80 + Mouse_y);
       line(40 + Mouse_x, 80 + Mouse_y, 22 + Mouse_x, 62 + Mouse_y);
       /** Moldura back-light direita. *************************************/
       line(62 + Mouse_x, 22 + Mouse_y, 80 + Mouse_x, 40 + Mouse_y);
       line(80 + Mouse_x, 40 + Mouse_y, 61 + Mouse_x, 59 + Mouse_y);
       line(61 + Mouse_x, 59 + Mouse_y, 61 + Mouse_x, 50 + Mouse_y);
       line(61 + Mouse_x, 50 + Mouse_y, 55 + Mouse_x, 50 + Mouse_y);
       /** Moldura back-light esquerda. ************************************/
       line(26 + Mouse_x, 31 + Mouse_y, 26 + Mouse_x, 50 + Mouse_y);
       line(26 + Mouse_x, 50 + Mouse_y, 19 + Mouse_x, 50 + Mouse_y);
       line(19 + Mouse_x, 50 + Mouse_y, 19 + Mouse_x, 59 + Mouse_y);
       line(19 + Mouse_x, 59 + Mouse_y,  1 + Mouse_x, 41 + Mouse_y);
       setcolor(InactiveObject);
       setfillstyle(1, InactiveObject);
       /** Seta esqueda. ***************************************************/
       fillpoly(7, Mouse_l);
       /** Seta direita. ***************************************************/
       fillpoly(7, Mouse_r);
       /** Seta superior. **************************************************/
       fillpoly(7, Mouse_u);
       /** Seta inferior. **************************************************/
       fillpoly(7, Mouse_d);
       /** Desaciona botoes do mouse. **************************************/
       Mouseb0 = 0;
       Mouseb1 = 0;
       /** Botao b0. *******************************************************/
       bar(101 + Mouse_x, 11 + Mouse_y, 139 + Mouse_x, 29 + Mouse_y);
       /** Botao b1. *******************************************************/
       bar(101 + Mouse_x, 51 + Mouse_y, 139 + Mouse_x, 69 + Mouse_y);
       settextjustify(CENTER_TEXT, CENTER_TEXT);
       settextstyle(FONTTYPE, HORIZ_DIR, 4);
       setcolor(ShadowObject);
       outtextxy(120 + Mouse_x, 20 + Mouse_y, "B0");
       outtextxy(120 + Mouse_x, 60 + Mouse_y, "B1");
       /** Exibe texto de fun‡oes dos botoes. ******************************/
       settextjustify(LEFT_TEXT, CENTER_TEXT);
       settextstyle(FONTTYPE, HORIZ_DIR, 6);
       setcolor(HilightObject);
       outtextxy(150 + Mouse_x, 20 + Mouse_y, MouseButton0Name);
       outtextxy(150 + Mouse_x, 60 + Mouse_y, MouseButton1Name);
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
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(FONTTYPE, HORIZ_DIR, 4);
    setcolor(ShadowObject);
    switch(statusmouse())
    {
       case 0:
	  Mouseb0 = 0;
	  Mouseb1 = 0;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     setfillstyle(1, InactiveObject);
	     bar(101 + Mouse_x, 11 + Mouse_y, 139 + Mouse_x, 29 + Mouse_y);
	     bar(101 + Mouse_x, 51 + Mouse_y, 139 + Mouse_x, 69 + Mouse_y);
	     outtextxy(120 + Mouse_x, 20 + Mouse_y, "B0");
	     outtextxy(120 + Mouse_x, 60 + Mouse_y, "B1");
	  }
	  OldMouseb0 = Mouseb0;
	  OldMouseb1 = Mouseb1;
	  break;
       case 1:
	  Mouseb0 = 1;
	  Mouseb1 = 0;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(101 + Mouse_x, 11 + Mouse_y, 139 + Mouse_x, 29 + Mouse_y);
	     outtextxy(120 + Mouse_x, 20 + Mouse_y, "B0");
	     setfillstyle(1, InactiveObject);
	     bar(101 + Mouse_x, 51 + Mouse_y, 139 + Mouse_x, 69 + Mouse_y);
	     outtextxy(120 + Mouse_x, 60 + Mouse_y, "B1");
	  }
	  OldMouseb0 = Mouseb0;
	  OldMouseb1 = Mouseb1;
	  break;
       case 2:
	  Mouseb0 = 0;
	  Mouseb1 = 1;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(101 + Mouse_x, 51 + Mouse_y, 139 + Mouse_x, 69 + Mouse_y);
	     outtextxy(120 + Mouse_x, 60 + Mouse_y, "B1");
	     setfillstyle(1, InactiveObject);
	     bar(101 + Mouse_x, 11 + Mouse_y, 139 + Mouse_x, 29 + Mouse_y);
	     outtextxy(120 + Mouse_x, 20 + Mouse_y, "B0");
	  }
	  OldMouseb0 = Mouseb0;
	  OldMouseb1 = Mouseb1;
	  break;
       case 3:
	  Mouseb0 = 0;
	  Mouseb1 = 0;
	  if(OldMouseb0 != Mouseb0 || OldMouseb1 != Mouseb1)
	  {
	     setfillstyle(1, InactiveObject);
	     bar(101 + Mouse_x, 11 + Mouse_y, 139 + Mouse_x, 29 + Mouse_y);
	     bar(101 + Mouse_x, 51 + Mouse_y, 139 + Mouse_x, 69 + Mouse_y);
	     outtextxy(120 + Mouse_x, 20 + Mouse_y, "B0");
	     outtextxy(120 + Mouse_x, 60 + Mouse_y, "B1");
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
       setcolor(ActiveObject);
       setfillstyle(1, ActiveObject);
       fillpoly(7, Mouse_l);
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
       setcolor(InactiveObject);
       setfillstyle(1, InactiveObject);
       fillpoly(7, Mouse_l);
    }
    /** Verifica e executa movimento direito do mouse. *********************/
    if(colmouse() > MouseStartx)
    {
       /** Seta direita acesa. *********************************************/
       setcolor(ActiveObject);
       setfillstyle(1, ActiveObject);
       fillpoly(7, Mouse_r);
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
       setcolor(InactiveObject);
       setfillstyle(1, InactiveObject);
       fillpoly(7, Mouse_r);
    }
    /** Verifica e executa movimento superior do mouse. ********************/
    if(linmouse() < MouseStarty)
    {
       /** Seta superior acesa. ********************************************/
       setcolor(ActiveObject);
       setfillstyle(1, ActiveObject);
       fillpoly(7, Mouse_u);
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
       setcolor(InactiveObject);
       setfillstyle(1, InactiveObject);
       fillpoly(7, Mouse_u);
    }
    /** Verifica e executa movimento inferior do mouse. ********************/
    if(linmouse() > MouseStarty)
    {
       /** Seta inferior acesa. ********************************************/
       setcolor(ActiveObject);
       setfillstyle(1, ActiveObject);
       fillpoly(7, Mouse_d);
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
       setcolor(InactiveObject);
       setfillstyle(1, InactiveObject);
       fillpoly(7, Mouse_d);
    }
    return(OK);
 }


 /** Fun‡ao: Mapa do teclado. **********************************************/
 int keybmap()
 {
    int Contador_1 = 0, Contador_2 = 0;
    int Auxiliar_1 = 0, Auxiliar_2 = 0;
    int KeybNameLenght = 0;
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
    for(Contador_1 = 0; Contador_1 < LedNumbers; Contador_1 ++)
    {
       KeybNameLenght = strlen(KeybName[Contador_1]);
       if(KeybNameLenght >= 1)
       {
	  /** Exibe mapa do teclado. ***************************************/
	  print(2, 4 + Contador_1, HilightText, KeybNameMap[Contador_1]);
	  print(6, 4 + Contador_1, HilightText, "=");
	  print(7, 4 + Contador_1, HilightText, OutputName[Contador_1]);
	  /** Desenho dos led's indicadores. *******************************/
	  Contador_2 = 19 * Contador_1;
	  setcolor(HilightObject);
	  line(12 , 67 + Contador_2, 27, 67 + Contador_2);
	  line(12 , 67 + Contador_2, 12, 74 + Contador_2);
	  setcolor(ShadowObject);
	  line(13 , 74 + Contador_2, 27, 74 + Contador_2);
	  line(27 , 68 + Contador_2, 27, 74 + Contador_2);
	  setfillstyle(1, InactiveObject);
	  bar(13 , 68 + Contador_2, 26, 73 + Contador_2);
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

    /** Inicia dispositivo apenas exibindo seu mapa. ***********************/
    if(Tecla1 == RESET)
    {
       keybmap();
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
			 print(2, 4 + Contador_1, ActiveObject,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, ActiveObject, "=");
			 print(7, 4 + Contador_1, ActiveObject,
			       OutputName[Contador_1]);
			 /** Acende led indicador. *************************/
			 setfillstyle(1, ActiveObject);
			 bar(13, 68 + (19 * Contador_1),
			     26, 73 + (19 * Contador_1));
		      }
		      delay(Wait);
		      output(0, Port);
		      if(Contador_1 < LedNumbers)
		      {
			 print(2, 4 + Contador_1, HilightText,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, HilightText, "=");
			 print(7, 4 + Contador_1, HilightText,
			       OutputName[Contador_1]);
			 /** Apaga led indicador. **************************/
			 setfillstyle(1, InactiveObject);
			 bar(13, 68 + (19 * Contador_1),
			     26, 73 + (19 * Contador_1));
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
			 print(2, 4 + Contador_1, ActiveObject,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, ActiveObject, "=");
			 print(7, 4 + Contador_1, ActiveObject,
			       OutputName[Contador_1]);
			 /** Acende led indicador. *************************/
			 setfillstyle(1, ActiveObject);
			 bar(13, 68 + (19 * Contador_1),
			     26, 73 + (19 * Contador_1));
		      }
		      delay(Wait);
		      output(0, Port);
		      if(Contador_1 < LedNumbers)
		      {
			 print(2, 4 + Contador_1, HilightText,
			       KeybNameMap[Contador_1]);
			 print(6, 4 + Contador_1, HilightText, "=");
			 print(7, 4 + Contador_1, HilightText,
			       OutputName[Contador_1]);
			 /** Apaga led indicador. **************************/
			 setfillstyle(1, InactiveObject);
			 bar(13, 68 + (19 * Contador_1),
			     26, 73 + (19 * Contador_1));
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
    int OldHilightObject = HilightObject;
    int OldJoyCenter_x = JoyCenter_x;
    int OldJoyCenter_y = JoyCenter_y;
    int JoyPos_x = 0, JoyPos_y = 0;
    int JoyPos_xMax = 0, JoyPos_yMax = 0;
    int JoyPos_xMin = 0, JoyPos_yMin = 0;
    int OldJoyCrossRIGHT = JoyCrossRIGHT;
    int OldJoyCrossLEFT = JoyCrossLEFT;
    int OldJoyCrossUP = JoyCrossUP;
    int OldJoyCrossDOWN = JoyCrossDOWN;

    /** Abre janela de calibra‡ao do joystick. *****************************/
    explica("Calibra o joystick.");
    janela(290, 40, 634, 320, 0, "Calibrar joystick...");
    dimensao();
    botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");
    /** Verifica a existencia de um joystick. ******************************/
    if(JoystickPermission == FALSE)
    {
       /** Exibe menssagem de erro caso nao haja joystick. *****************/
       locate(0, 0, LEFT_TEXT, 0, "ERRO: Falha ao ler joystick");
       locate(0, 1, LEFT_TEXT, 0, "  Nao foi encontrada nenhuma");
       locate(0, 2, LEFT_TEXT, 0, "  porta de joystick.");
       locate(0, 3, LEFT_TEXT, 0, "  Nao ser  possivel concluir");
       locate(0, 4, LEFT_TEXT, 0, "  a opera‡ao.");
       while(TRUE)
       {
	  /** Executa a tecla pressionada. *********************************/
	  switch(tecla)
	  {
	     case ENTER:
		botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
		      0, 1, 1, "OK");
		delay(50);
		limpa();
		return(OK);
	     case ESC:
		limpa();
		return(OK);
	     default: break;
	  }
	  if(kbhit()) tecla = getch();
       }
    }
    /** Inicia rotina de centraliza‡ao. ************************************/
    locate(0, 0, LEFT_TEXT, 0, "Mantenha o joystick centralizado");
    locate(0, 1, LEFT_TEXT, 0, "e pressione algum botao dele.");
    /** Exibe cruz do joystick na janela de calibracao. ********************/
    Joystick_x = 40;
    Joystick_y = 120;
    HilightObject = ActiveWindowText;
    joystick(RESET);
    while(statusjoystick(0) == 0)
    {
       /** Executa a tecla executada caso seja ENTER ou ESC. ***************/
       switch(tecla)
       {
	  case ESC:
	     HilightObject = OldHilightObject;
	     JoyCenter_x = OldJoyCenter_x;
	     JoyCenter_y = OldJoyCenter_y;
	     dimensao();
	     limpa();
	     return(OK);
	  default: break;
       }
       /** Verifica qual o posicionamento do joystick. *********************/
       JoyCenter_x = coljoystick(0);
       JoyCenter_y = linjoystick(0);
       /** Verifica quais botoes do joystick estao pressionados. ***********/
       joyfire();
       if(kbhit()) tecla = getch();
    }
    /** Inicia rotina de maximos e minimos. ********************************/
    locate(0, 0, LEFT_TEXT, 0, "Direcione o joystick para todos");
    locate(0, 1, LEFT_TEXT, 0, "os lados diversas vezes, entao");
    locate(0, 2, LEFT_TEXT, 0, "pressione ENTER.");
    /** Atribui valores as variaveis para calibracao. **********************/
    JoyPos_xMax = 1;
    JoyPos_yMax = 1;
    JoyPos_xMin = 500;
    JoyPos_yMin = 500;
    /** Inicia calibra‡ao. *************************************************/
    while(TRUE){
       /** Executa a tecla executada caso seja ENTER ou ESC. ***************/
       switch(tecla)
       {
	  case ENTER:
	     JoyCrossRIGHT = JoyCrossRIGHT - 1;
	     JoyCrossDOWN = JoyCrossDOWN - 1;
	     HilightObject = OldHilightObject;
	     dimensao();
	     botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
		   0, 1, 1, "OK");
	     delay(50);
	     limpa();
	     return(OK);
	  case ESC:
	     HilightObject = OldHilightObject;
	     JoyCenter_x = OldJoyCenter_x;
	     JoyCenter_y = OldJoyCenter_y;
	     JoyCrossRIGHT = OldJoyCrossRIGHT;
	     JoyCrossLEFT = OldJoyCrossLEFT;
	     JoyCrossUP = OldJoyCrossUP;
	     JoyCrossDOWN = OldJoyCrossDOWN;
	     dimensao();
	     limpa();
	     return(OK);
	  default: break;
       }
       /** Verifica qual o posicionamento do joystick. *********************/
       JoyPos_x = coljoystick(0);
       JoyPos_y = linjoystick(0);
       /** Verifica qual o posicionamento maximo do joystick. **************/
       if(JoyPos_xMax < JoyPos_x) { JoyPos_xMax = JoyPos_x; }
       if(JoyPos_yMax < JoyPos_y) { JoyPos_yMax = JoyPos_y; }
       if(JoyPos_xMin > JoyPos_x) { JoyPos_xMin = JoyPos_x; }
       if(JoyPos_yMin > JoyPos_y) { JoyPos_yMin = JoyPos_y; }
       /** Ferifica a area de operacao de cada bra‡o da cruz. **************/
       JoyCrossRIGHT = JoyPos_xMax - JoyCenter_x;
       JoyCrossLEFT = JoyCenter_x - JoyPos_xMin;
       JoyCrossUP = JoyCenter_y - JoyPos_yMin;
       JoyCrossDOWN = JoyPos_yMax - JoyCenter_y;
       /** Verifica se o valor obtido nao e igual a zero. ******************/
       if(JoyPos_x != 0 || JoyPos_y != 0)
       {
	  /** Barras superiores. *******************************************/
	  if(JoyPos_y <= JoyCrossUP / 1)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(28 + Joystick_x, 22 + Joystick_y,
		 49 + Joystick_x, 24 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(28 + Joystick_x, 22 + Joystick_y,
		 49 + Joystick_x, 24 + Joystick_y);
	  }
	  if(JoyPos_y <= JoyCrossUP / 2)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(21 + Joystick_x, 15 + Joystick_y,
		 56 + Joystick_x, 17 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(21 + Joystick_x, 15 + Joystick_y,
		 56 + Joystick_x, 17 + Joystick_y);
	  }
	  if(JoyPos_y <= JoyCrossUP / 3)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(14 + Joystick_x,  8 + Joystick_y,
		 63 + Joystick_x, 10 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(14 + Joystick_x,  8 + Joystick_y,
		 63 + Joystick_x, 10 + Joystick_y);
	  }
	  if(JoyPos_y <= JoyCrossUP / 4)
	  {
	     setfillstyle(1, ActiveObject);
	     bar( 7 + Joystick_x,  1 + Joystick_y,
		 70 + Joystick_x,  3 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar( 7 + Joystick_x,  1 + Joystick_y,
		 70 + Joystick_x,  3 + Joystick_y);
	  }
	  /** Barras inferiores. *******************************************/
	  if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 4)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(28 + Joystick_x, 53 + Joystick_y,
		 49 + Joystick_x, 55 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(28 + Joystick_x, 53 + Joystick_y,
		 49 + Joystick_x, 55 + Joystick_y);
	  }
	  if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 3)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(21 + Joystick_x, 60 + Joystick_y,
		 56 + Joystick_x, 62 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(21 + Joystick_x, 60 + Joystick_y,
		 56 + Joystick_x, 62 + Joystick_y);
	  }
	  if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 2)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(14 + Joystick_x, 67 + Joystick_y,
		 63 + Joystick_x, 69 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(14 + Joystick_x, 67 + Joystick_y,
		 63 + Joystick_x, 69 + Joystick_y);
	  }
	  if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 1)
	  {
	     setfillstyle(1, ActiveObject);
	     bar( 7 + Joystick_x, 74 + Joystick_y,
		 70 + Joystick_x, 76 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar( 7 + Joystick_x, 74 + Joystick_y,
		 70 + Joystick_x, 76 + Joystick_y);
	  }
	  /** Barras direitas. *********************************************/
	  if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 4)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(53 + Joystick_x, 28 + Joystick_y,
		 55 + Joystick_x, 49 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(53 + Joystick_x, 28 + Joystick_y,
		 55 + Joystick_x, 49 + Joystick_y);
	  }
	  if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 3)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(60 + Joystick_x, 21 + Joystick_y,
		 62 + Joystick_x, 56 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(60 + Joystick_x, 21 + Joystick_y,
		 62 + Joystick_x, 56 + Joystick_y);
	  }
	  if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 2)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(67 + Joystick_x, 14 + Joystick_y,
		 69 + Joystick_x, 63 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(67 + Joystick_x, 14 + Joystick_y,
		 69 + Joystick_x, 63 + Joystick_y);
	  }
	  if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 1)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(74 + Joystick_x,  7 + Joystick_y,
		 76 + Joystick_x, 70 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(74 + Joystick_x,  7 + Joystick_y,
		 76 + Joystick_x, 70 + Joystick_y);
	  }
	  /** Barras esquerdas. ********************************************/
	  if(JoyPos_x <= JoyCrossLEFT / 1)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(22 + Joystick_x, 28 + Joystick_y,
		 24 + Joystick_x, 49 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(22 + Joystick_x, 28 + Joystick_y,
		 24 + Joystick_x, 49 + Joystick_y);
	  }
	  if(JoyPos_x <= JoyCrossLEFT / 2)
	  {
	     setfillstyle(1, ActiveObject);
	     bar(15 + Joystick_x, 21 + Joystick_y,
		 17 + Joystick_x, 56 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar(15 + Joystick_x, 21 + Joystick_y,
		 17 + Joystick_x, 56 + Joystick_y);
	  }
	  if(JoyPos_x <= JoyCrossLEFT / 3)
	  {
	     setfillstyle(1, ActiveObject);
	     bar( 8 + Joystick_x, 14 + Joystick_y,
		 10 + Joystick_x, 63 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar( 8 + Joystick_x, 14 + Joystick_y,
		 10 + Joystick_x, 63 + Joystick_y);
	  }
	  if(JoyPos_x <= JoyCrossLEFT / 4)
	  {
	     setfillstyle(1, ActiveObject);
	     bar( 1 + Joystick_x,  7 + Joystick_y,
		  3 + Joystick_x, 70 + Joystick_y);
	  }
	  else
	  {
	     setfillstyle(1, InactiveObject);
	     bar( 1 + Joystick_x,  7 + Joystick_y,
		  3 + Joystick_x, 70 + Joystick_y);
	  }
       }
       /** Verifica quais botoes do joystick estao pressionados. ***********/
       joyfire();
       /** Verifica se alguma tecla foi pressionada. ***********************/
       if(kbhit()) tecla = getch();
    }
 }


 /** Fun‡ao: Exime mapa do joystick. ***************************************/
 int joymap()
 {
    int Contador_1 = 0;
    char JoystickRIGHTName[17];
    char JoystickLEFTName[17];
    char JoystickUPName[17];
    char JoystickDOWNName[17];

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
    printf("#       Botao 0  = %s\n#       Botao 1  = %s\n",
	   JoystickFire0Name, JoystickFire1Name);
    printf("#       Sobe     = %s\n#       Desce    = %s\n#       Direita  = %s\n#       Esquerda = %s\n",
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
	     setfillstyle(1, InactiveObject);
	     /** Botao f0. *************************************************/
	     bar(98 + Joystick_x, 11 + Joystick_y,
		136 + Joystick_x, 29 + Joystick_y);
	     /** Botao f1. *************************************************/
	     bar(98 + Joystick_x, 51 + Joystick_y,
		136 + Joystick_x, 69 + Joystick_y);
	     /** Exibe texto dos botoes. ***********************************/
	     settextjustify(CENTER_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 4);
	     setcolor(ShadowObject);
	     outtextxy(117 + Joystick_x, 20 + Joystick_y, "F0");
	     outtextxy(117 + Joystick_x, 60 + Joystick_y, "F1");
	     /** Exibe texto de fun‡oes dos botoes. ************************/
	     settextjustify(LEFT_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 6);
	     setcolor(HilightObject);
	     outtextxy(147 + Joystick_x, 20 + Joystick_y, JoystickFire0Name);
	     outtextxy(147 + Joystick_x, 60 + Joystick_y, JoystickFire1Name);
	  }
	  OldJoyFire0 = JoyFire0;
	  OldJoyFire1 = JoyFire1;
	  break;
       case 1:
	  JoyFire0 = 1;
	  JoyFire1 = 0;
	  if(OldJoyFire0 != JoyFire0 || OldJoyFire1 != JoyFire1)
	  {
	     setfillstyle(1, InactiveObject);
	     /** Botao f1. *************************************************/
	     bar(98 + Joystick_x, 51 + Joystick_y,
		136 + Joystick_x, 69 + Joystick_y);
	     setfillstyle(1, ActiveObject);
	     /** Botao f0. *************************************************/
	     bar(98 + Joystick_x, 11 + Joystick_y,
		136 + Joystick_x, 29 + Joystick_y);
	     /** Exibe texto dos botoes. ***********************************/
	     settextjustify(CENTER_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 4);
	     setcolor(ShadowObject);
	     outtextxy(117 + Joystick_x, 20 + Joystick_y, "F0");
	     outtextxy(117 + Joystick_x, 60 + Joystick_y, "F1");
	     /** Exibe texto de fun‡oes dos botoes. ************************/
	     settextjustify(LEFT_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 6);
	     setcolor(HilightObject);
	     outtextxy(147 + Joystick_x, 20 + Joystick_y, JoystickFire0Name);
	     outtextxy(147 + Joystick_x, 60 + Joystick_y, JoystickFire1Name);
	  }
	  OldJoyFire0 = JoyFire0;
	  OldJoyFire1 = JoyFire1;
	  break;
       case 2:
	  JoyFire0 = 0;
	  JoyFire1 = 1;
	  if(OldJoyFire0 != JoyFire0 || OldJoyFire1 != JoyFire1)
	  {
	     setfillstyle(1, InactiveObject);
	     /** Botao f0. *************************************************/
	     bar(98 + Joystick_x, 11 + Joystick_y,
		136 + Joystick_x, 29 + Joystick_y);
	     setfillstyle(1, ActiveObject);
	     /** Botao f1. *************************************************/
	     bar(98 + Joystick_x, 51 + Joystick_y,
		136 + Joystick_x, 69 + Joystick_y);
	     /** Exibe texto dos botoes. ***********************************/
	     settextjustify(CENTER_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 4);
	     setcolor(ShadowObject);
	     outtextxy(117 + Joystick_x, 20 + Joystick_y, "F0");
	     outtextxy(117 + Joystick_x, 60 + Joystick_y, "F1");
	     /** Exibe texto de fun‡oes dos botoes. ************************/
	     settextjustify(LEFT_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 6);
	     setcolor(HilightObject);
	     outtextxy(147 + Joystick_x, 20 + Joystick_y, JoystickFire0Name);
	     outtextxy(147 + Joystick_x, 60 + Joystick_y, JoystickFire1Name);
	  }
	  OldJoyFire0 = JoyFire0;
	  OldJoyFire1 = JoyFire1;
	  break;
       case 3:
	  JoyFire0 = 0;
	  JoyFire1 = 0;
	  if(OldJoyFire0 != JoyFire0 || OldJoyFire1 != JoyFire1)
	  {
	     setfillstyle(1, InactiveObject);
	     /** Botao f0. *************************************************/
	     bar(98 + Joystick_x, 11 + Joystick_y,
		136 + Joystick_x, 29 + Joystick_y);
	     /** Botao f1. *************************************************/
	     bar(98 + Joystick_x, 51 + Joystick_y,
		136 + Joystick_x, 69 + Joystick_y);
	     /** Exibe texto dos botoes. ***********************************/
	     settextjustify(CENTER_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 4);
	     setcolor(ShadowObject);
	     outtextxy(117 + Joystick_x, 20 + Joystick_y, "F0");
	     outtextxy(117 + Joystick_x, 60 + Joystick_y, "F1");
	     /** Exibe texto de fun‡oes dos botoes. ************************/
	     settextjustify(LEFT_TEXT, CENTER_TEXT);
	     settextstyle(FONTTYPE, HORIZ_DIR, 6);
	     setcolor(HilightObject);
	     outtextxy(147 + Joystick_x, 20 + Joystick_y, JoystickFire0Name);
	     outtextxy(147 + Joystick_x, 60 + Joystick_y, JoystickFire1Name);
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

    /** Inicia dispositivo, exibindo sua aparencia. ************************/
    if(opcao == RESET)
    {
       /** Moldura tridimensional do joystick. *****************************/
       setcolor(HilightObject);
       /** Moldura hight-light de f0. **************************************/
       line(97 + Joystick_x, 30 + Joystick_y,
	    97 + Joystick_x, 10 + Joystick_y);
       line(97 + Joystick_x, 10 + Joystick_y,
	   137 + Joystick_x, 10 + Joystick_y);
       /** Moldura hight-light de f1. **************************************/
       line(97 + Joystick_x, 70 + Joystick_y,
	    97 + Joystick_x, 50 + Joystick_y);
       line(97 + Joystick_x, 50 + Joystick_y,
	   137 + Joystick_x, 50 + Joystick_y);
       /** Moldura hight-light superior. ***********************************/
       line( 6 + Joystick_x,  0 + Joystick_y,
	    71 + Joystick_x,  0 + Joystick_y);
       line( 6 + Joystick_x,  0 + Joystick_y,
	     6 + Joystick_x,  4 + Joystick_y);
       line(13 + Joystick_x,  7 + Joystick_y,
	    64 + Joystick_x,  7 + Joystick_y);
       line(13 + Joystick_x,  7 + Joystick_y,
	    13 + Joystick_x, 11 + Joystick_y);
       line(20 + Joystick_x, 14 + Joystick_y,
	    57 + Joystick_x, 14 + Joystick_y);
       line(20 + Joystick_x, 14 + Joystick_y,
	    20 + Joystick_x, 18 + Joystick_y);
       line(27 + Joystick_x, 21 + Joystick_y,
	    50 + Joystick_x, 21 + Joystick_y);
       line(27 + Joystick_x, 21 + Joystick_y,
	    27 + Joystick_x, 25 + Joystick_y);
       /** Moldura hight-light inferior. ***********************************/
       line( 6 + Joystick_x, 73 + Joystick_y,
	    71 + Joystick_x, 73 + Joystick_y);
       line( 6 + Joystick_x, 73 + Joystick_y,
	     6 + Joystick_x, 77 + Joystick_y);
       line(13 + Joystick_x, 66 + Joystick_y,
	    64 + Joystick_x, 66 + Joystick_y);
       line(13 + Joystick_x, 66 + Joystick_y,
	    13 + Joystick_x, 70 + Joystick_y);
       line(20 + Joystick_x, 59 + Joystick_y,
	    57 + Joystick_x, 59 + Joystick_y);
       line(20 + Joystick_x, 59 + Joystick_y,
	    20 + Joystick_x, 63 + Joystick_y);
       line(27 + Joystick_x, 52 + Joystick_y,
	    50 + Joystick_x, 52 + Joystick_y);
       line(27 + Joystick_x, 52 + Joystick_y,
	    27 + Joystick_x, 56 + Joystick_y);
       /** Moldura hight-light direita. ************************************/
       line(73 + Joystick_x,  6 + Joystick_y,
	    77 + Joystick_x,  6 + Joystick_y);
       line(73 + Joystick_x,  6 + Joystick_y,
	    73 + Joystick_x, 71 + Joystick_y);
       line(66 + Joystick_x, 13 + Joystick_y,
	    70 + Joystick_x, 13 + Joystick_y);
       line(66 + Joystick_x, 13 + Joystick_y,
	    66 + Joystick_x, 64 + Joystick_y);
       line(59 + Joystick_x, 20 + Joystick_y,
	    63 + Joystick_x, 20 + Joystick_y);
       line(59 + Joystick_x, 20 + Joystick_y,
	    59 + Joystick_x, 57 + Joystick_y);
       line(52 + Joystick_x, 27 + Joystick_y,
	    56 + Joystick_x, 27 + Joystick_y);
       line(52 + Joystick_x, 27 + Joystick_y,
	    52 + Joystick_x, 50 + Joystick_y);
       /** Moldura hight-light esquerda. ***********************************/
       line( 0 + Joystick_x,  6 + Joystick_y,
	     4 + Joystick_x,  6 + Joystick_y);
       line( 0 + Joystick_x,  6 + Joystick_y,
	     0 + Joystick_x, 71 + Joystick_y);
       line( 7 + Joystick_x, 13 + Joystick_y,
	    11 + Joystick_x, 13 + Joystick_y);
       line( 7 + Joystick_x, 13 + Joystick_y,
	     7 + Joystick_x, 64 + Joystick_y);
       line(14 + Joystick_x, 20 + Joystick_y,
	    18 + Joystick_x, 20 + Joystick_y);
       line(14 + Joystick_x, 20 + Joystick_y,
	    14 + Joystick_x, 57 + Joystick_y);
       line(21 + Joystick_x, 27 + Joystick_y,
	    25 + Joystick_x, 27 + Joystick_y);
       line(21 + Joystick_x, 27 + Joystick_y,
	    21 + Joystick_x, 50 + Joystick_y);
       setcolor(ShadowObject);
       /** Moldura back-light de f0. ***************************************/
       line(137 + Joystick_x, 11 + Joystick_y,
	    137 + Joystick_x, 30 + Joystick_y);
       line(137 + Joystick_x, 30 + Joystick_y,
	     98 + Joystick_x, 30 + Joystick_y);
       /** Moldura back-light de f1. ***************************************/
       line(137 + Joystick_x, 51 + Joystick_y,
	    137 + Joystick_x, 70 + Joystick_y);
       line(137 + Joystick_x, 70 + Joystick_y,
	     98 + Joystick_x, 70 + Joystick_y);
       /** Moldura back-light superior. ************************************/
       line( 7 + Joystick_x,  4 + Joystick_y,
	    71 + Joystick_x,  4 + Joystick_y);
       line(71 + Joystick_x,  1 + Joystick_y,
	    71 + Joystick_x,  4 + Joystick_y);
       line(14 + Joystick_x, 11 + Joystick_y,
	    64 + Joystick_x, 11 + Joystick_y);
       line(64 + Joystick_x,  8 + Joystick_y,
	    64 + Joystick_x, 11 + Joystick_y);
       line(21 + Joystick_x, 18 + Joystick_y,
	    57 + Joystick_x, 18 + Joystick_y);
       line(57 + Joystick_x, 15 + Joystick_y,
	    57 + Joystick_x, 18 + Joystick_y);
       line(28 + Joystick_x, 25 + Joystick_y,
	    50 + Joystick_x, 25 + Joystick_y);
       line(50 + Joystick_x, 22 + Joystick_y,
	    50 + Joystick_x, 25 + Joystick_y);
       /** Moldura back-light inferior. ************************************/
       line( 7 + Joystick_x, 77 + Joystick_y,
	    71 + Joystick_x, 77 + Joystick_y);
       line(71 + Joystick_x, 74 + Joystick_y,
	    71 + Joystick_x, 77 + Joystick_y);
       line(14 + Joystick_x, 70 + Joystick_y,
	    64 + Joystick_x, 70 + Joystick_y);
       line(64 + Joystick_x, 67 + Joystick_y,
	    64 + Joystick_x, 70 + Joystick_y);
       line(21 + Joystick_x, 63 + Joystick_y,
	    57 + Joystick_x, 63 + Joystick_y);
       line(57 + Joystick_x, 60 + Joystick_y,
	    57 + Joystick_x, 63 + Joystick_y);
       line(28 + Joystick_x, 56 + Joystick_y,
	    50 + Joystick_x, 56 + Joystick_y);
       line(50 + Joystick_x, 53 + Joystick_y,
	    50 + Joystick_x, 56 + Joystick_y);
       /** Moldura back-light direita. *************************************/
       line(74 + Joystick_x, 71 + Joystick_y,
	    77 + Joystick_x, 71 + Joystick_y);
       line(77 + Joystick_x,  7 + Joystick_y,
	    77 + Joystick_x, 71 + Joystick_y);
       line(67 + Joystick_x, 64 + Joystick_y,
	    70 + Joystick_x, 64 + Joystick_y);
       line(70 + Joystick_x, 14 + Joystick_y,
	    70 + Joystick_x, 64 + Joystick_y);
       line(60 + Joystick_x, 57 + Joystick_y,
	    63 + Joystick_x, 57 + Joystick_y);
       line(63 + Joystick_x, 21 + Joystick_y,
	    63 + Joystick_x, 57 + Joystick_y);
       line(53 + Joystick_x, 50 + Joystick_y,
	    56 + Joystick_x, 50 + Joystick_y);
       line(56 + Joystick_x, 28 + Joystick_y,
	    56 + Joystick_x, 50 + Joystick_y);
       /** Moldura back-light esquerda. ************************************/
       line( 1 + Joystick_x, 71 + Joystick_y,
	     4 + Joystick_x, 71 + Joystick_y);
       line( 4 + Joystick_x,  7 + Joystick_y,
	     4 + Joystick_x, 71 + Joystick_y);
       line( 8 + Joystick_x, 64 + Joystick_y,
	    11 + Joystick_x, 64 + Joystick_y);
       line(11 + Joystick_x, 14 + Joystick_y,
	    11 + Joystick_x, 64 + Joystick_y);
       line(15 + Joystick_x, 57 + Joystick_y,
	    18 + Joystick_x, 57 + Joystick_y);
       line(18 + Joystick_x, 21 + Joystick_y,
	    18 + Joystick_x, 57 + Joystick_y);
       line(22 + Joystick_x, 50 + Joystick_y,
	    25 + Joystick_x, 50 + Joystick_y);
       line(25 + Joystick_x, 28 + Joystick_y,
	    25 + Joystick_x, 50 + Joystick_y);
       /** Preenchimento das barras tridimensionais. ***********************/
       setfillstyle(1, InactiveObject);
       /** Barras superiores. **********************************************/
       bar( 7 + Joystick_x,  1 + Joystick_y,
	   70 + Joystick_x,  3 + Joystick_y);
       bar(14 + Joystick_x,  8 + Joystick_y,
	   63 + Joystick_x, 10 + Joystick_y);
       bar(21 + Joystick_x, 15 + Joystick_y,
	   56 + Joystick_x, 17 + Joystick_y);
       bar(28 + Joystick_x, 22 + Joystick_y,
	   49 + Joystick_x, 24 + Joystick_y);
       /** Barras inferiores. **********************************************/
       bar( 7 + Joystick_x, 74 + Joystick_y,
	   70 + Joystick_x, 76 + Joystick_y);
       bar(14 + Joystick_x, 67 + Joystick_y,
	   63 + Joystick_x, 69 + Joystick_y);
       bar(21 + Joystick_x, 60 + Joystick_y,
	   56 + Joystick_x, 62 + Joystick_y);
       bar(28 + Joystick_x, 53 + Joystick_y,
	   49 + Joystick_x, 55 + Joystick_y);
       /** Barras direitas. ************************************************/
       bar(74 + Joystick_x,  7 + Joystick_y,
	   76 + Joystick_x, 70 + Joystick_y);
       bar(67 + Joystick_x, 14 + Joystick_y,
	   69 + Joystick_x, 63 + Joystick_y);
       bar(60 + Joystick_x, 21 + Joystick_y,
	   62 + Joystick_x, 56 + Joystick_y);
       bar(53 + Joystick_x, 28 + Joystick_y,
	   55 + Joystick_x, 49 + Joystick_y);
       /** Barras esquerdas. ***********************************************/
       bar( 1 + Joystick_x,  7 + Joystick_y,
	    3 + Joystick_x, 70 + Joystick_y);
       bar( 8 + Joystick_x, 14 + Joystick_y,
	   10 + Joystick_x, 63 + Joystick_y);
       bar(15 + Joystick_x, 21 + Joystick_y,
           17 + Joystick_x, 56 + Joystick_y);
       bar(22 + Joystick_x, 28 + Joystick_y,
	   24 + Joystick_x, 49 + Joystick_y);
       /** Botao f0. *******************************************************/
       bar(98 + Joystick_x, 11 + Joystick_y,
	  136 + Joystick_x, 29 + Joystick_y);
       /** Botao f1. *******************************************************/
       bar(98 + Joystick_x, 51 + Joystick_y,
	  136 + Joystick_x, 69 + Joystick_y);
       /** Exibe texto dos botoes. *****************************************/
       settextjustify(CENTER_TEXT, CENTER_TEXT);
       settextstyle(FONTTYPE, HORIZ_DIR, 4);
       setcolor(ShadowObject);
       outtextxy(117 + Joystick_x, 20 + Joystick_y, "F0");
       outtextxy(117 + Joystick_x, 60 + Joystick_y, "F1");
       /** Exibe texto de fun‡oes dos botoes. ******************************/
       settextjustify(LEFT_TEXT, CENTER_TEXT);
       settextstyle(FONTTYPE, HORIZ_DIR, 6);
       setcolor(HilightObject);
       outtextxy(147 + Joystick_x, 20 + Joystick_y, JoystickFire0Name);
       outtextxy(147 + Joystick_x, 60 + Joystick_y, JoystickFire1Name);
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
	  setfillstyle(1, ActiveObject);
	  bar(53 + Joystick_x, 28 + Joystick_y,
	      55 + Joystick_x, 49 + Joystick_y);
	  JoystickWaitRIGHT = JoystickWait + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(53 + Joystick_x, 28 + Joystick_y,
	      55 + Joystick_x, 49 + Joystick_y);
       }
       if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 3)
       {
	  setfillstyle(1, ActiveObject);
	  bar(60 + Joystick_x, 21 + Joystick_y,
	      62 + Joystick_x, 56 + Joystick_y);
	  JoystickWaitRIGHT = JoystickWait / 2;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(60 + Joystick_x, 21 + Joystick_y,
	      62 + Joystick_x, 56 + Joystick_y);
       }
       if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 2)
       {
	  setfillstyle(1, ActiveObject);
	  bar(67 + Joystick_x, 14 + Joystick_y,
	      69 + Joystick_x, 63 + Joystick_y);
	  JoystickWaitRIGHT = JoystickWait / 4 + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(67 + Joystick_x, 14 + Joystick_y,
	      69 + Joystick_x, 63 + Joystick_y);
       }
       if(JoyPos_x >= JoyCenter_x + JoyCrossRIGHT / 1)
       {
	  setfillstyle(1, ActiveObject);
	  bar(74 + Joystick_x,  7 + Joystick_y,
	      76 + Joystick_x, 70 + Joystick_y);
	  JoystickWaitRIGHT = 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(74 + Joystick_x,  7 + Joystick_y,
	      76 + Joystick_x, 70 + Joystick_y);
       }
       /** Barras esquerdas. ***********************************************/
       if(JoyPos_x <= JoyCrossLEFT / 1)
       {
	  setfillstyle(1, ActiveObject);
	  bar(22 + Joystick_x, 28 + Joystick_y,
	      24 + Joystick_x, 49 + Joystick_y);
	  JoystickWaitLEFT = JoystickWait + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(22 + Joystick_x, 28 + Joystick_y,
	      24 + Joystick_x, 49 + Joystick_y);
       }
       if(JoyPos_x <= JoyCrossLEFT / 2)
       {
	  setfillstyle(1, ActiveObject);
	  bar(15 + Joystick_x, 21 + Joystick_y,
	      17 + Joystick_x, 56 + Joystick_y);
	  JoystickWaitLEFT = JoystickWait / 2 + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(15 + Joystick_x, 21 + Joystick_y,
	      17 + Joystick_x, 56 + Joystick_y);
       }
       if(JoyPos_x <= JoyCrossLEFT / 3)
       {
	  setfillstyle(1, ActiveObject);
	  bar( 8 + Joystick_x, 14 + Joystick_y,
	      10 + Joystick_x, 63 + Joystick_y);
	  JoystickWaitLEFT = JoystickWait / 4 + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar( 8 + Joystick_x, 14 + Joystick_y,
	      10 + Joystick_x, 63 + Joystick_y);
       }
       if(JoyPos_x <= JoyCrossLEFT / 4)
       {
	  setfillstyle(1, ActiveObject);
	  bar( 1 + Joystick_x,  7 + Joystick_y,
	       3 + Joystick_x, 70 + Joystick_y);
	  JoystickWaitLEFT = 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar( 1 + Joystick_x,  7 + Joystick_y,
	       3 + Joystick_x, 70 + Joystick_y);
       }
       /** Barras superiores. **********************************************/
       if(JoyPos_y <= JoyCrossUP / 1)
       {
	  setfillstyle(1, ActiveObject);
	  bar(28 + Joystick_x, 22 + Joystick_y,
	      49 + Joystick_x, 24 + Joystick_y);
	  JoystickWaitUP = JoystickWait + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(28 + Joystick_x, 22 + Joystick_y,
	      49 + Joystick_x, 24 + Joystick_y);
       }
       if(JoyPos_y <= JoyCrossUP / 2)
       {
	  setfillstyle(1, ActiveObject);
	  bar(21 + Joystick_x, 15 + Joystick_y,
	      56 + Joystick_x, 17 + Joystick_y);
	  JoystickWaitUP = JoystickWait / 2 + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(21 + Joystick_x, 15 + Joystick_y,
	      56 + Joystick_x, 17 + Joystick_y);
       }
       if(JoyPos_y <= JoyCrossUP / 3)
       {
	  setfillstyle(1, ActiveObject);
	  bar(14 + Joystick_x,  8 + Joystick_y,
	      63 + Joystick_x, 10 + Joystick_y);
	  JoystickWaitUP = JoystickWaitUP / 4 + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(14 + Joystick_x,  8 + Joystick_y,
	      63 + Joystick_x, 10 + Joystick_y);
       }
       if(JoyPos_y <= JoyCrossUP / 4)
       {
	  setfillstyle(1, ActiveObject);
	  bar( 7 + Joystick_x,  1 + Joystick_y,
	      70 + Joystick_x,  3 + Joystick_y);
	  JoystickWaitUP = 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar( 7 + Joystick_x,  1 + Joystick_y,
	      70 + Joystick_x,  3 + Joystick_y);
       }
       /** Barras inferiores. **********************************************/
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 4)
       {
	  setfillstyle(1, ActiveObject);
	  bar(28 + Joystick_x, 53 + Joystick_y,
	      49 + Joystick_x, 55 + Joystick_y);
	  JoystickWaitDOWN = JoystickWait + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(28 + Joystick_x, 53 + Joystick_y,
	      49 + Joystick_x, 55 + Joystick_y);
       }
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 3)
       {
	  setfillstyle(1, ActiveObject);
	  bar(21 + Joystick_x, 60 + Joystick_y,
	      56 + Joystick_x, 62 + Joystick_y);
	  JoystickWaitDOWN = JoystickWait / 2 + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(21 + Joystick_x, 60 + Joystick_y,
	      56 + Joystick_x, 62 + Joystick_y);
       }
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 2)
       {
	  setfillstyle(1, ActiveObject);
	  bar(14 + Joystick_x, 67 + Joystick_y,
	      63 + Joystick_x, 69 + Joystick_y);
	  JoystickWaitDOWN = JoystickWait / 4 + 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar(14 + Joystick_x, 67 + Joystick_y,
	      63 + Joystick_x, 69 + Joystick_y);
       }
       if(JoyPos_y >= JoyCenter_y + JoyCrossDOWN / 1)
       {
	  setfillstyle(1, ActiveObject);
	  bar( 7 + Joystick_x, 74 + Joystick_y,
	      70 + Joystick_x, 76 + Joystick_y);
	  JoystickWaitDOWN = 1;
       }
       else
       {
	  setfillstyle(1, InactiveObject);
	  bar( 7 + Joystick_x, 74 + Joystick_y,
	      70 + Joystick_x, 76 + Joystick_y);
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
    int Contador_1 = 0, Contador_2 = 0;
    int SensorNameLenght = 0;

    /** Exibe mapa dos sensores. *******************************************/
    for(Contador_1 = 0; Contador_1 < LedNumbers; Contador_1 ++)
    {
       SensorNameLenght = strlen(SensorName[Contador_1]);
       if(SensorNameLenght >= 1)
       {
	  /** Exibe mapa do teclado. ***************************************/
	  print(19, 4 + Contador_1, HilightText, SensorName[Contador_1]);
	  /** Desenho dos led's indicadores. ****************************/
	  Contador_2 = 19 * Contador_1;
	  setcolor(HilightObject);
	  line(12 + MidScreen_x, 67 + Contador_2,
	       27 + MidScreen_x, 67 + Contador_2);
	  line(12 + MidScreen_x, 67 + Contador_2,
	       12 + MidScreen_x, 74 + Contador_2);
	  setcolor(ShadowObject);
	  line(13 + MidScreen_x, 74 + Contador_2,
	       27 + MidScreen_x, 74 + Contador_2);
	  line(27 + MidScreen_x, 68 + Contador_2,
	       27 + MidScreen_x, 74 + Contador_2);
	  setfillstyle(1, InactiveObject);
	  bar(13 + MidScreen_x, 68 + Contador_2,
	      26 + MidScreen_x, 73 + Contador_2);
       }
    }
    return(OK);
 }


 /** Fun‡ao: Sensores. *****************************************************/
 int sensor(int opcao)
 {
    int Contador_1 = 0, Contador_2 = 0;

    /** Exibe mapa de sensores. ********************************************/
    if(opcao == RESET)
    {
       LastSensor = LedNumbers * 10;
       sensomap();
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
		print(19, 4 + LastSensor, HilightText,
		      SensorName[LastSensor]);
		/** Desenho dos led's indicadores. *************************/
		Contador_2 = 19 * LastSensor;
		setcolor(HilightObject);
		line(12 + MidScreen_x, 67 + Contador_2,
		     27 + MidScreen_x, 67 + Contador_2);
		line(12 + MidScreen_x, 67 + Contador_2,
		     12 + MidScreen_x, 74 + Contador_2);
		setcolor(ShadowObject);
		line(13 + MidScreen_x, 74 + Contador_2,
		     27 + MidScreen_x, 74 + Contador_2);
		line(27 + MidScreen_x, 68 + Contador_2,
		     27 + MidScreen_x, 74 + Contador_2);
		setfillstyle(1, InactiveObject);
		bar(13 + MidScreen_x, 68 + Contador_2,
		    26 + MidScreen_x, 73 + Contador_2);
	     }
	     /** Ascende led e texto. **************************************/
	     /** Exibe mapa do sensor. *************************************/
	     print(19, 4 + Contador_1, ActiveObject,
		   SensorName[Contador_1]);
	     /** Desenho dos led's indicadores. ****************************/
	     Contador_2 = 19 * Contador_1;
	     setcolor(HilightObject);
	     line(12 + MidScreen_x, 67 + Contador_2,
		  27 + MidScreen_x, 67 + Contador_2);
	     line(12 + MidScreen_x, 67 + Contador_2,
		  12 + MidScreen_x, 74 + Contador_2);
	     setcolor(ShadowObject);
	     line(13 + MidScreen_x, 74 + Contador_2,
		  27 + MidScreen_x, 74 + Contador_2);
	     line(27 + MidScreen_x, 68 + Contador_2,
		  27 + MidScreen_x, 74 + Contador_2);
	     setfillstyle(1, ActiveObject);
	     bar(13 + MidScreen_x, 68 + Contador_2,
		 26 + MidScreen_x, 73 + Contador_2);
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
 int selectcontrol(int opcao)
 {
    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;
    int OldKeyboard = 0, OldMouse = 0, OldJoystick = 0, OldSerial = 0;
    char KeyboardWork[4], MouseWork[4], JoystickWork[4], SerialWork[4];

    OldKeyboard = Keyboard;
    OldMouse = Mouse;
    OldJoystick = Joystick;
    OldSerial = Serial;

    /** Define local de inicio da funcao. **********************************/
    Inicio_da_selecao_de_controle:
    OldRetorno = 0;
    Retorno = 1;
    Contador_1 = 1;
    Keyboard = OldKeyboard;
    Mouse = OldMouse;
    Joystick = OldJoystick;
    Serial = OldSerial;

    if(Serial == TRUE)
    {
       Keyboard = FALSE;
       Mouse = FALSE;
       Joystick = FALSE;
       strcpy(SerialWork, "Sim");
    }
    if(Serial == FALSE) strcpy(SerialWork, "Nao");
    if(Keyboard == TRUE) strcpy(KeyboardWork, "Sim");
    if(Keyboard == FALSE) strcpy(KeyboardWork, "Nao");
    if(Mouse == TRUE) strcpy(MouseWork, "Sim");
    if(Mouse == FALSE) strcpy(MouseWork, "Nao");
    if(Joystick == TRUE) strcpy(JoystickWork, "Sim");
    if(Joystick == FALSE) strcpy(JoystickWork, "Nao");


    if(opcao == RESET)
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

       /** Adapta‡ao aos meios de entrada. *********************************/
       chkcontrol();
       return(OK);
    }

    explica("Sele‡ao do dispositivo de entrada de dados.");
    janela(10, 150, 250, 340, 0, "Controles...");
    dimensao();
    /** Exibe op‡oes do menu. **********************************************/
    locate(0, 0, LEFT_TEXT, 1, "Teclado:");
    locate(0, 0, RIGHT_TEXT, 1, KeyboardWork);
    locate(0, 1, LEFT_TEXT, 0, "Mouse:");
    locate(0, 1, RIGHT_TEXT, 0, MouseWork);
    locate(0, 2, LEFT_TEXT, 0, "Joystick:");
    locate(0, 2, RIGHT_TEXT, 0, JoystickWork);
    locate(0, 3, LEFT_TEXT, 0, "Serial:");
    locate(0, 3, RIGHT_TEXT, 0, SerialWork);
    botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");

    while(TRUE)
    {
       /** Executa menu de opcoes. *****************************************/
       OldRetorno = Retorno;
       Retorno = options(5, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
       switch(Retorno)
       {
       case 1:
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
	  locate(0, 0, LEFT_TEXT, 1, "Teclado:");
	  locate(0, 0, RIGHT_TEXT, 1, KeyboardWork);
	  locate(0, 1, LEFT_TEXT, 0, "Mouse:");
	  locate(0, 1, RIGHT_TEXT, 0, MouseWork);
	  break;
       case 2:
	  locate(0, 0, LEFT_TEXT, 0, "Teclado:");
	  locate(0, 0, RIGHT_TEXT, 0, KeyboardWork);
	  locate(0, 1, LEFT_TEXT, 1, "Mouse:");
	  locate(0, 1, RIGHT_TEXT, 1, MouseWork);
	  locate(0, 2, LEFT_TEXT, 0, "Joystick:");
	  locate(0, 2, RIGHT_TEXT, 0, JoystickWork);
	  break;
       case 3:
	  locate(0, 1, LEFT_TEXT, 0, "Mouse:");
	  locate(0, 1, RIGHT_TEXT, 0, MouseWork);
	  locate(0, 2, LEFT_TEXT, 1, "Joystick:");
	  locate(0, 2, RIGHT_TEXT, 1, JoystickWork);
	  locate(0, 3, LEFT_TEXT, 0, "Serial:");
	  locate(0, 3, RIGHT_TEXT, 0, SerialWork);
	  break;
       case 4:
	  locate(0, 2, LEFT_TEXT, 0, "Joystick:");
	  locate(0, 2, RIGHT_TEXT, 0, JoystickWork);
	  locate(0, 3, LEFT_TEXT, 1, "Serial:");
	  locate(0, 3, RIGHT_TEXT, 1, SerialWork);
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
	  break;
       case 5:
	  locate(0, 3, LEFT_TEXT, 0, "Serial:");
	  locate(0, 3, RIGHT_TEXT, 0, SerialWork);
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");
	  locate(0, 0, LEFT_TEXT, 0, "Teclado:");
	  locate(0, 0, RIGHT_TEXT, 0, KeyboardWork);
	  break;
       default: break;
       }

       /** Verifica qual opcao foi escolhida e executa-a. ******************/
       switch(Retorno)
       {
	  case ENTER:
	     switch(OldRetorno)
	     {
		case 1:
		   if(KeyboardEnable != FALSE)
		   {
		      if(Keyboard == FALSE)
		      {
			 Keyboard = TRUE;
			 strcpy(KeyboardWork, "Sim");
		      }
		      else{
			 Keyboard = FALSE;
			 strcpy(KeyboardWork, "Nao");
		      }
		      locate(0, 0, LEFT_TEXT, 1, "Teclado:");
		      locate(0, 0, RIGHT_TEXT, 1, KeyboardWork);
		   }
		   Contador_1 = 1;
		   Retorno = 1;
		   break;
		case 2:
		   if(MousePermission != FALSE && MouseEnable != FALSE)
		   {
		      if(Mouse == FALSE)
		      {
			 Mouse = TRUE;
			 strcpy(MouseWork, "Sim");
		      }
		      else{
			 Mouse = FALSE;
			 strcpy(MouseWork, "Nao");
		      }
		      locate(0, 1, LEFT_TEXT, 1, "Mouse:");
		      locate(0, 1, RIGHT_TEXT, 1, MouseWork);
		   }
		   Contador_1 = 2;
		   Retorno = 2;
		   break;
		case 3:
		   if(JoystickPermission != FALSE && JoystickEnable != FALSE)
		   {
		      if(Joystick == FALSE)
		      {
			 Joystick = TRUE;
			 strcpy(JoystickWork, "Sim");
		      }
		      else{
			 Joystick = FALSE;
			 strcpy(JoystickWork, "Nao");
		      }
		      locate(0, 2, LEFT_TEXT, 1, "Joystick:");
		      locate(0, 2, RIGHT_TEXT, 1, JoystickWork);
		   }
		   Contador_1 = 3;
		   Retorno = 3;
		   break;
		case 4:
		   if(SerialPermission != FALSE && SerialEnable != FALSE)
		   {
		      if(Serial == FALSE)
		      {
			 Serial = TRUE;
			 strcpy(SerialWork, "Sim");
		      }
		      else{
			 Serial = FALSE;
			 strcpy(SerialWork, "Nao");
		      }
		      locate(0, 3, LEFT_TEXT, 1, "Serial:");
		      locate(0, 3, RIGHT_TEXT, 1, SerialWork);
		   }
		   Contador_1 = 4;
		   Retorno = 4;
		   break;
		case 5:
		   /** Adapta‡ao aos meios de entrada. *********************/
		   chkcontrol();
		   botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
			 0, 1, 1, "OK");
		   delay(50);
		   limpa();
		   if(Serial == TRUE)
		   {
		      explica("Aviso de inicia‡ao de servidor.");
		      janela(30, 50, 450, 230, 0, "Aviso de Servidor");
		      dimensao();
		      /** Exibe texto da janela. ******************************/
		      locate(0, 0, LEFT_TEXT, 0, "Aviso Importante:");
		      locate(0, 1, LEFT_TEXT, 0, "Habilitando a op‡ao controle serial,");
		      locate(0, 2, LEFT_TEXT, 0, "esta esta‡ao ter  a fun‡ao de servidor,");
		      locate(0, 3, LEFT_TEXT, 0, "recebendo os comandos do cliente.");
		      botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");
		      botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 0, "Cancelar");
		      OldRetorno = 0;
		      Retorno = 1;
		      Contador_1 = 1;
		      while(TRUE)
		      {
			 /** Executa menu de opcoes. ***********************/
			 OldRetorno = Retorno;
			 Retorno = options(2, Contador_1);
			 if(Retorno != ERROR) { Contador_1 = Retorno; }
			 /** Exibe a op‡ao atualmente selecionada. *********/
			 switch(Retorno)
			 {
			    case 1:
			       botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");
			       botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 0, "Cancelar");
			       break;
			    case 2:
			       botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
			       botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 1, "Cancelar");
			       break;
			    default: break;
			 }
			 /** Verifica qual opcao foi escolhida e executa. **/
			 switch(Retorno)
			 {
			    case ENTER:
			       switch(OldRetorno)
			       {
				  case 1:
				     botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 1, 1, "OK");
				     botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 0, "Cancelar");
				     delay(50);
				     limpa();
				     return(OK);
				  case 2:
				     botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
				     botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 1, 1, "Cancelar");
				     delay(50);
				     limpa();
				     goto Inicio_da_selecao_de_controle;
				  default: break;
			       }
			       break;
			    case ESC:
			       botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
			       botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 1, 1, "Cancelar");
			       delay(50);
			       limpa();
			       goto Inicio_da_selecao_de_controle;
			    case ERROR:
			       Retorno = OldRetorno;
			       beep(Speaker);
			       break;
			    default: break;
			 }
		      }
		   }
		   return(OK);
		default: break;
	     }
	     break;
	  case ESC:
	     Keyboard = OldKeyboard;
	     Mouse = OldMouse;
	     Joystick = OldJoystick;
	     Serial = OldSerial;
	     limpa();
	     return(OK);
	  case ERROR:
	     Retorno = OldRetorno;
	     beep(Speaker);
	     break;
	  default: break;
       }
    }
 }


 /** Fun‡ao: Configura dispositivos de entrada. ****************************/
 int configcontrol()
 {
    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;

    explica("Configura‡oes dos controles.");
    janela(60, 80, 340, 250, 0, "Controles...");
    dimensao();
    /** Exibe op‡oes do menu. **********************************************/
    locate(0, 0, LEFT_TEXT, 1, "Ajustar teclado...");
    locate(0, 1, LEFT_TEXT, 0, "Ajustar mouse...");
    locate(0, 2, LEFT_TEXT, 0, "Calibrar joystick...");
    botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");

    while(TRUE)
    {
       /** Executa menu de opcoes. *****************************************/
       OldRetorno = Retorno;
       Retorno = options(4, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
       switch(Retorno)
       {
       case 1:
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
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
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
	  break;
       case 4:
	  locate(0, 2, LEFT_TEXT, 0, "Calibrar joystick...");
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");
	  locate(0, 0, LEFT_TEXT, 0, "Ajustar teclado...");
	  break;
       default: break;
       }

       /** Verifica qual opcao foi escolhida e executa-a. ******************/
       switch(Retorno)
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
		   botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
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
    }
 }


 /** Fun‡ao: Configura‡oes do controlador. *********************************/
 int config()
 {
    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;
    char som[4], anim[16];
    if(Speaker == FALSE) strcpy(som, "Nao");
    if(Speaker == TRUE) strcpy(som, "Sim");

    itoa(Animate, anim, 10);
    strcat(anim, " passos");
    strcpy(AdressWork, Adress);
    strcat(AdressWork, " Hex");
    strcpy(TimeWork, Time);
    strcat(TimeWork, " miliseg.");
    strcpy(RepeatWork, Emulation);
    strcat(RepeatWork, " vezes.");

    explica("Configura‡oes do controlador.");
    janela(20, 50, 350, 312, 0, "Configurar...");
    dimensao();
    /** Exibe op‡oes do menu. **********************************************/
    locate(0, 0, LEFT_TEXT, 1, "Utilizar Sons:");
    locate(0, 0, RIGHT_TEXT, 1, som);
    locate(0, 1, LEFT_TEXT, 0, "Anima‡oes:");
    locate(0, 1, RIGHT_TEXT, 0, anim);
    locate(0, 2, LEFT_TEXT, 0, "Endere‡o:");
    locate(0, 2, RIGHT_TEXT, 0, AdressWork);
    locate(0, 3, LEFT_TEXT, 0, "Base de tempo:");
    locate(0, 3, RIGHT_TEXT, 0, TimeWork);
    locate(0, 4, LEFT_TEXT, 0, "Repeti‡ao:");
    locate(0, 4, RIGHT_TEXT, 0, RepeatWork);
    locate(0, 5, LEFT_TEXT, 0, "Comunica‡oes...");
    locate(0, 6, LEFT_TEXT, 0, "Controles...");
    locate(0, 7, LEFT_TEXT, 0, "Cores...");
    botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");

    while(TRUE)
    {
       /** Executa menu de opcoes. *****************************************/
       OldRetorno = Retorno;
       Retorno = options(9, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
       switch(Retorno)
       {
       case 1:
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
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
	  locate(0, 5, LEFT_TEXT, 0, "Comunica‡oes...");
	  break;
       case 6:
	  locate(0, 4, LEFT_TEXT, 0, "Repeti‡ao:");
	  locate(0, 4, RIGHT_TEXT, 0, RepeatWork);
	  locate(0, 5, LEFT_TEXT, 1, "Comunica‡oes...");
	  locate(0, 6, LEFT_TEXT, 0, "Controles...");
	  break;
       case 7:
	  locate(0, 5, LEFT_TEXT, 0, "Comunica‡oes...");
	  locate(0, 6, LEFT_TEXT, 1, "Controles...");
	  locate(0, 7, LEFT_TEXT, 0, "Cores...");
	  break;
       case 8:
	  locate(0, 6, LEFT_TEXT, 0, "Controles...");
	  locate(0, 7, LEFT_TEXT, 1, "Cores...");
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
	  break;
       case 9:
	  locate(0, 7, LEFT_TEXT, 0, "Cores...");
	  botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");
	  locate(0, 0, LEFT_TEXT, 0, "Utilizar Sons:");
	  locate(0, 0, RIGHT_TEXT, 0, som);
	  break;
       default: break;
       }

       /** Verifica qual opcao foi escolhida e executa-a. ******************/
       switch(Retorno)
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
		   base_Time();
		   return(OK);
		case 5:
		   correcao();
		   return(OK);
		case 6:
		   configcomunications();
		   return(OK);
		case 7:
		   configcontrol();
		   return(OK);
		case 8:
		   colors();
		   return(OK);
		case 9:
		   botao(MidWindow_x, MaxWindow_y - VerticalSizeButton,
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
    }
 }


 /** Fun‡ao: Configura porta de comunica‡oes. ******************************/
 int configcomunications()
 {
    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;

    int OldComunicationsPort = ComunicationsPort;
    int OldComunicationsBaudRate = ComunicationsBaudRate;
    int OldComunicationsParity = ComunicationsParity;
    int OldComunicationsStopBits = ComunicationsStopBits;
    int OldComunicationsWordLenght = ComunicationsWordLenght;

    char TextComunicationsPort[5];
    char TextComunicationsBaudRate[9];
    char TextComunicationsParity[8];
    char TextComunicationsStopBits[7];
    char TextComunicationsWordLenght[7];

    /** Atribui o valor texto a variavel texto. ****************************/
    /** Variavel de porta de comunica‡ao. **********************************/
    switch (ComunicationsPort)
    {
       case 1: strcpy(TextComunicationsPort, "COM1"); break;
       case 2: strcpy(TextComunicationsPort, "COM2"); break;
       case 3: strcpy(TextComunicationsPort, "COM3"); break;
       case 4: strcpy(TextComunicationsPort, "COM4"); break;
       default: strcpy(TextComunicationsPort, "Erro"); break;
    }
    /** Variavel de velocidade de comunica‡ao. *****************************/
    itoa(ComunicationsBaudRate, TextComunicationsBaudRate, 10);
    strcat(TextComunicationsBaudRate, " bps");
    /** Variavel de paridade de comunica‡ao. *******************************/
    switch (ComunicationsParity)
    {
       case 0: strcpy(TextComunicationsParity, "Nenhum"); break;
       case 1: strcpy(TextComunicationsParity, "Impar"); break;
       case 2: strcpy(TextComunicationsParity, "Par"); break;
       default: strcpy(TextComunicationsParity, "Erro"); break;
    }
    /** Variavel de bits de parada de comunica‡ao. *************************/
    itoa(ComunicationsStopBits, TextComunicationsStopBits, 10);
    if(ComunicationsStopBits == 1) strcat(TextComunicationsStopBits, " bit");
    if(ComunicationsStopBits == 2) strcat(TextComunicationsStopBits, " bits");
    /** Variavel de tamando da palavra de comunica‡ao. *********************/
    itoa(ComunicationsWordLenght, TextComunicationsWordLenght, 10);
    strcat(TextComunicationsWordLenght, " bits");

    /** Exibe texto explicativo e abre a janela. ***************************/
    explica("Configura parametros de comunica‡ao serial.");
    janela(250, 90, 600, 300, 0, "Configurar porta serial...");
    dimensao();
    /** Exibe op‡oes do menu. **********************************************/
    locate(0, 0, LEFT_TEXT, 1, "Porta:");
    locate(0, 0, RIGHT_TEXT, 1, TextComunicationsPort);
    locate(0, 1, LEFT_TEXT, 0, "Velocidade:");
    locate(0, 1, RIGHT_TEXT, 0, TextComunicationsBaudRate);
    locate(0, 2, LEFT_TEXT, 0, "Paridade:");
    locate(0, 2, RIGHT_TEXT, 0, TextComunicationsParity);
    locate(0, 3, LEFT_TEXT, 0, "Bits de parada:");
    locate(0, 3, RIGHT_TEXT, 0, TextComunicationsStopBits);
    locate(0, 4, LEFT_TEXT, 0, "Tamando da palavra:");
    locate(0, 4, RIGHT_TEXT, 0, TextComunicationsWordLenght);
    botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
    botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 0, "Cancelar");

    while(TRUE)
    {
       /** Executa menu de opcoes. *****************************************/
       OldRetorno = Retorno;
       Retorno = options(7, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
       switch(Retorno)
       {
       case 1:
	  botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 0, "Cancelar");
	  locate(0, 0, LEFT_TEXT, 1, "Porta:");
	  locate(0, 0, RIGHT_TEXT, 1, TextComunicationsPort);
	  locate(0, 1, LEFT_TEXT, 0, "Velocidade:");
	  locate(0, 1, RIGHT_TEXT, 0, TextComunicationsBaudRate);
	  break;
       case 2:
	  locate(0, 0, LEFT_TEXT, 0, "Porta:");
	  locate(0, 0, RIGHT_TEXT, 0, TextComunicationsPort);
	  locate(0, 1, LEFT_TEXT, 1, "Velocidade:");
	  locate(0, 1, RIGHT_TEXT, 1, TextComunicationsBaudRate);
	  locate(0, 2, LEFT_TEXT, 0, "Paridade:");
	  locate(0, 2, RIGHT_TEXT, 0, TextComunicationsParity);
	  break;
       case 3:
	  locate(0, 1, LEFT_TEXT, 0, "Velocidade:");
	  locate(0, 1, RIGHT_TEXT, 0, TextComunicationsBaudRate);
	  locate(0, 2, LEFT_TEXT, 1, "Paridade:");
	  locate(0, 2, RIGHT_TEXT, 1, TextComunicationsParity);
	  locate(0, 3, LEFT_TEXT, 0, "Bits de parada:");
	  locate(0, 3, RIGHT_TEXT, 0, TextComunicationsStopBits);
	  break;
       case 4:
	  locate(0, 2, LEFT_TEXT, 0, "Paridade:");
	  locate(0, 2, RIGHT_TEXT, 0, TextComunicationsParity);
	  locate(0, 3, LEFT_TEXT, 1, "Bits de parada:");
	  locate(0, 3, RIGHT_TEXT, 1, TextComunicationsStopBits);
	  locate(0, 4, LEFT_TEXT, 0, "Tamando da palavra:");
	  locate(0, 4, RIGHT_TEXT, 0, TextComunicationsWordLenght);
	  break;
       case 5:
	  locate(0, 3, LEFT_TEXT, 0, "Bits de parada:");
	  locate(0, 3, RIGHT_TEXT, 0, TextComunicationsStopBits);
	  locate(0, 4, LEFT_TEXT, 1, "Tamando da palavra:");
	  locate(0, 4, RIGHT_TEXT, 1, TextComunicationsWordLenght);
	  botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
	  break;
       case 6:
	  locate(0, 4, LEFT_TEXT, 0, "Tamando da palavra:");
	  locate(0, 4, RIGHT_TEXT, 0, TextComunicationsWordLenght);
	  botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");
	  botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 0, "Cancelar");
	  break;
       case 7:
	  botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 0, 0, "OK");
	  botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 0, 1, "Cancelar");
	  locate(0, 0, LEFT_TEXT, 0, "Porta:");
	  locate(0, 0, RIGHT_TEXT, 0, TextComunicationsPort);
	  break;
       default: break;
       }

       /** Verifica qual opcao foi escolhida e executa-a. ******************/
       switch(Retorno)
       {
	  case ENTER:
	     switch(OldRetorno)
	     {
		case 1:
		   Contador_1 = 1;
		   Retorno = 1;
		   break;
		case 2:
		   Contador_1 = 2;
		   Retorno = 2;
		   break;
		case 3:
		   Contador_1 = 3;
		   Retorno = 3;
		   break;
		case 4:
		   Contador_1 = 4;
		   Retorno = 4;
		   break;
		case 5:
		   Contador_1 = 5;
		   Retorno = 5;
		   break;
		case 6:
		   botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton, 0, 1, 1, "OK");
		   delay(50);
		   limpa();
		   return(OK);
		case 7:
		   goto Rotina_de_Escape;
		default: break;
	     }
	  break;
	  case ESC:
	     goto Rotina_de_Escape;
	  case ERROR:
	     Retorno = OldRetorno;
	     beep(Speaker);
	     break;
	  default: break;
       }
    }
    /** Rotina de escape. **************************************************/
    Rotina_de_Escape:
    ComunicationsPort = OldComunicationsPort;
    ComunicationsBaudRate = OldComunicationsBaudRate;
    ComunicationsParity = OldComunicationsParity;
    ComunicationsStopBits = OldComunicationsStopBits;
    ComunicationsWordLenght = OldComunicationsWordLenght;
    botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton, 10, 1, 1, "Cancelar");
    delay(50);
    limpa();
    return(OK);
 }


 /** Fun‡ao: Sobre o controlador. ******************************************/
 int sobre()
 {
    int tecla = 0;
    char dia[3], mes[3], ano[5];
    char hora[5], minuto[5], segundo[5];
    char horario[16], diario[16];
    int old_time = 0;
    struct time t;
    struct date d;

    explica("Informa‡oes sobre o produto. BUGs: Relate ao autor.");
    janela(290, 100, 630, 320, 1, "Sobre...");
    dimensao();
    locate(0, 0, LEFT_TEXT, 0, TITLE);
    locate(0, 1, LEFT_TEXT, 0, COMENTS);
    locate(0, 2, LEFT_TEXT, 0, "copyright (c) 1995-2000");
    locate(0, 3, LEFT_TEXT, 0, "email: marciosp@mailbr.com.br");
    botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 0, 1, "OK");

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
    botao(MidWindow_x, MaxWindow_y - VerticalSizeButton, 0, 1, 1, "OK");
    delay(50);
    limpa();
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
    int tecla1 = 0, tecla2 = 0, contador = 1, memoria = 0;

    explica("Sai do controlador.");
    janela(32, 42, 320, 159, 1, "Sair");
    dimensao();
    locate(0, 0, LEFT_TEXT, 0, "Deseja realmente sair?");
    botao(MidWindow_x - 40, MaxWindow_y - VerticalSizeButton,
	  0, 0, 1, "Sim");
    botao(MidWindow_x + 40, MaxWindow_y - VerticalSizeButton,
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
		   botao(MidWindow_x + 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 0, "Nao");
		   botao(MidWindow_x - 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 1, "Sim");
		}
		if(contador == 2)
		{
		   botao(MidWindow_x - 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 0, "Sim");
		   botao(MidWindow_x + 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 1, "Nao");
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
		   botao(MidWindow_x + 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 0, "Nao");
		   botao(MidWindow_x - 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 1, "Sim");
		}
		if(contador == 2)
		{
		   botao(MidWindow_x - 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 0, "Sim");
		   botao(MidWindow_x + 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 1, "Nao");
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
		   botao(MidWindow_x + 40,
			 MaxWindow_x - VerticalSizeButton, 0, 0, 0, "Nao");
		   botao(MidWindow_x - 40,
			 MaxWindow_y - VerticalSizeButton, 0, 1, 1, "Sim");
		   delay(100);
		   Quit = TRUE;
		   return(OK);
		}
		if(contador == 2)
		{
		   botao(MidWindow_x - 40,
			 MaxWindow_y - VerticalSizeButton, 0, 0, 0, "Sim");
		   botao(MidWindow_x + 40,
			 MaxWindow_y - VerticalSizeButton, 0, 1, 1, "Nao");
		   delay(100);
		   limpa();
		   return(OK);
		}
	     case ESC:
		botao(MidWindow_x - 40,
		      MaxWindow_y - VerticalSizeButton, 0, 0, 0, "Sim");
		botao(MidWindow_x + 40,
		      MaxWindow_y - VerticalSizeButton, 0, 1, 1, "Nao");
		delay(100);
		limpa();
		return(OK);
	     default: beep(Speaker);
	  }
    return(OK);
 }


 /** Fun‡ao: Menu do controlador. ******************************************/
 int menu()
 {
    int Retorno = 1, OldRetorno = 0;
    int Contador_1 = 1;
    explica("Selecione a op‡ao.");
    janela(MaxScreen_x / 4, MaxScreen_y / 4,
	   MaxScreen_x - MaxScreen_x / 4,
	   MaxScreen_y - MaxScreen_y / 4 , 0, "Op‡oes...");

    /** Exibe op‡oes do menu. **********************************************/
    locate(0, 0, LEFT_TEXT, 1, "Iniciar:");
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
       OldRetorno = Retorno;
       Retorno = options(6, Contador_1);
       if(Retorno != ERROR) { Contador_1 = Retorno; }

       /** Exibe a op‡ao atualmente selecionada. ***************************/
       switch(Retorno)
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
       switch(Retorno)
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
    }
 }


 /** Funcao: Apresentacao do controlador. **********************************/
 int apresentacao()
 {
    int tecla = 0;

    if(StartUpSerialInLogon == TRUE)
    {
       StartUpSerialInLogon = FALSE;
       iniciar();
    }

    explica("Pronto para iniciar.");
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
       if(kbhit()){
	  tecla = getch();
       }
    }
 }


 /** Fun‡ao: Inicia a utiliza‡ao do dispositivo. ***************************/
 int iniciar()
 {
    int tecla = RESET;
    char Ready[32];

    /** Exibe explica‡ao sobre a execussao do dispositivo. *****************/
    strcpy(Ready, "Executando ");
    strcat(Ready, DeviceName);
    strcat(Ready, ".");

    limpa();
    explica(Ready);
    while(TRUE){
       /** Se for pressionado enter chama menu. ****************************/
       if(tecla == ENTER)
       {
	  keyboard(RESET);
	  mouse(RESET);
	  joystick(RESET);
	  sensor(RESET);
	  menu();
	  return(OK);
       }
       /** Se for pressionado ESC, para execussao. *************************/
       if(tecla == ESC)
       {
	  keyboard(RESET);
	  mouse(RESET);
	  joystick(RESET);
	  sensor(RESET);
	  return(OK);
       }
       /** Executa os meios de entrada e de saida. *************************/
       keyboard(tecla);
       mouse(OK);
       joystick(OK);
       sensor(OK);
       /** Verifica qual caracter foi digitado. ****************************/
       tecla = RESET;
       if(kbhit()){
	  tecla = getch();
       }
    }
 }


 /** Fun‡ao: Carrega configuracoes do controlador. *************************/
 int configuracao()
 {
    int AuxScan = 0;
    printf("\n#Iniciando arquivos de configura‡ao.");
    /** Configura‡oes das cores exibidas. **********************************/
    if((AuxScan = load(ConfigurationFile, "AppWorkspace")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { AppWorkspace = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Background")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { Background = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Selector")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { Selector = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Frame")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { Frame = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Window")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { Window = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ActiveWindowText")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ActiveWindowText = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ActiveBorder")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ActiveBorder = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ActiveTitle")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ActiveTitle = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "InactiveBorder")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { InactiveBorder = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "InactiveTitle")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { InactiveTitle = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "InactiveWindowText")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { InactiveWindowText = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ActiveObject")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ActiveObject = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "InactiveObject")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { InactiveObject = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ButtonFace")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ButtonFace = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ButtonHilight")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ButtonHilight = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ButtonShadow")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ButtonShadow = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ButtonText")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ButtonText = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Hilight")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { Hilight = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "HilightText")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { HilightText = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "HilightWindow")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { HilightWindow = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "HilightObject")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { HilightObject = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Shadow")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { Shadow = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ShadowText")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ShadowText = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ShadowWindow")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ShadowWindow = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ShadowObject")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { ShadowObject = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "Menu")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { Menu = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "MenuText")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { MenuText = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "GrayText")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 15) { GrayText = AuxScan; }
    /** Configura‡oes de entretenimento. ***********************************/
    if((AuxScan = load(ConfigurationFile, "AnimateSteps")) != ERROR &&
	AuxScan >= 1 && AuxScan <= 99) { Animate = AuxScan; }
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
    /** Le do arquivo as configura‡oes de comunica‡ao serial. **************/
    if((AuxScan = load(ConfigurationFile, "ComunicationsPort")) != ERROR &&
	AuxScan >= 1 && AuxScan <= 4) { ComunicationsPort = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ComunicationsBaudRate")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 9600) { ComunicationsBaudRate = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ComunicationsParity")) != ERROR &&
	AuxScan >= 0 && AuxScan <= 2) { ComunicationsParity = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ComunicationsStopBits")) != ERROR &&
	AuxScan >= 1 && AuxScan <= 2) { ComunicationsStopBits = AuxScan; }
    if((AuxScan = load(ConfigurationFile, "ComunicationsWordLenght")) != ERROR &&
	AuxScan >= 7 && AuxScan <= 8) { ComunicationsWordLenght = AuxScan; }
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
    printf("\n#Iniciando arquivos de dispositivo.");
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


 /** Program notes. *********************************************************
 by: Marcio de Sousa Pessoa
 e-mail: marciomexicano@zipmail.com.br
 ***************************************************************************/
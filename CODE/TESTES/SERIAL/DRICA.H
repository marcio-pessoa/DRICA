# include <graphics.h>

/** Defini‡ao: Definicoes de constantes do controlador. ********************/
#define TRUE 1     /** Define verdadeiro. **********************************/
#define FALSE -1   /** Define falso. ***************************************/
#define OK 1       /** Define ok. ******************************************/
#define ERROR -1   /** Define erro. ****************************************/
#define RESET -10  /** Define valor de reset. ******************************/
#define CLIP_ON 1  /** Suprime dados para nao sair da janela. **************/
#define M_TEXTO 0  /** Exibi‡ao em modo texto. *****************************/
#define M_GRAPH 1  /** Exibi‡ao em modo grafico. ***************************/
#define TITLE "DRICA-Device Controler ver:0.1b" /** Titulo. ****************/
#define COMENTS "The Wizards InUtilities" /** Comentarios. *****************/
#define FONTTYPE SMALL_FONT /** Tipo da fonte utilizada pelo controlador. **/
#define WINDOW_BORDER 5
#define WINDOW_TITLEBAR 6

/** Definicoes do codigo ascii, com enfase em transmissao. *****************/
#define SOH  01
#define STX  02
#define ETX  03
#define EOT  04  /** End of text. ******************************************/
#define ENQ  05
#define ACK  06
#define BEL  07
#define BS   08
#define TAB  09  /** Tabula‡ao. ********************************************/
#define LF   10
#define VT   11
#define NP   12
#define CR   13
#define SO   14
#define SI   15
#define DLE  16
#define DC1  17
#define DC2  18
#define DC3  19
#define DC4  20
#define NAK  21
#define SYN  22
#define ETB  23
#define CAN  24
#define EM   25
/** #define EOF  26 (esta apagado pois EOF e' palavra reservada.) **********/
#define ESC  27  /** Tecla Escape. *****************************************/
#define FS   28
#define GS   29
#define RS   30
#define US   31
#define SP   32

/** Defini‡ao do mapa do teclado. ******************************************/
#define ENTER 13   /** Tecla Enter/Return. *********************************/
#define PGUP 73    /** Tecla Page-Up. **************************************/
#define PGDN 81    /** Tecla Page-Down. ************************************/
#define UP 72      /** Tecla para-cima. ************************************/
#define DOWN 80    /** Tecla para-baixo. ***********************************/
#define RIGHT 77   /** Tecla para-direira. *********************************/
#define LEFT 75    /** Tecla para-esquerda. ********************************/
#define INSERT 82  /** Tecla INSERT.****************************************/
#define DELETE 83  /** Tecla DELETE. ***************************************/
#define HOME 71    /** Tecla HOME. *****************************************/
#define END 79     /** Tecla END. ******************************************/
#define F1 59      /** Tecla F1. *******************************************/
#define F2 60      /** Tecla F2. *******************************************/
#define F3 61      /** Tecla F3. *******************************************/
#define F4 62      /** Tecla F4. *******************************************/
#define F5 63      /** Tecla F5. *******************************************/
#define F6 64      /** Tecla F6. *******************************************/
#define F7 65      /** Tecla F7. *******************************************/
#define F8 66      /** Tecla F8. *******************************************/
#define F9 67      /** Tecla F9. *******************************************/
#define F10 68     /** Tecla F10. ******************************************/
#define F11 133    /** Tecla F11. ******************************************/
#define F12 134    /** Tecla F12. ******************************************/
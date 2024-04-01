//Bibliotecas
#include<stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

//Defines usadas para a função textcolor
#define BLACK 0
#define BLUE 1
#define GRREN 2
#define GREENBLUE 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define GREENWATER 11
#define LIGHTRED 12
#define LILAC 13
#define LIGHTYELLOW 14
#define BRIGHTWHITE 15

//Código das telas (seta,cursor)
#define ENTER 13
#define CIMA 72
#define ESQUERDA 75
#define DIREITA 77
#define BAIXO 80
#define ESC 27

//Protótipo das funções

void titulo();//função que exibe o nome do sistema 

void textcolor(int i);//função que é usada da interface para colocar cores

void gotoxy(int x, int y);//função gotoxy para usar cursor

void inter();//função que exibe a interface do sistema (quadrado nos cantos)

void desenho();//função que exibe desenho da tela principal

void pacpizza();//função que exibe "PAC PIZZA" nas telas

void printafantasma();//função que imprime o fantasma 

void fantasminhamov();//função que imprime o fantasma em movimento na tela 

void gameover_2();//função que imprime "GAME OVER PARA A SUA FOME" nas telas

void cadast();//função que faz o cadastro principal

void caixacard(int x, int y, int tam_vertical, int tam_horizontal);//printa a caixa em qualquer tamanho

void caixinha(int x, int y, int tamanho, char *texto);//tem a mesma função da caixacard mas possui a opção de preencher com texto

void caixinha_verde(int x, int y, int tamanho, char *texto);//tem a mesma finalidade da caixinha, apenas muda de cor

void fantasminhamov2(); //"movimenta" o fantasma na tela do menuFuncionario

void printafantasma2();//printa o fantasma na tela do menuFuncionario

void desenho(); //desenho do pac man

void gameover();//interface 

void telalogin1();//imprime uma tela com duas opções (CADASTRAR OU LOGAR)

void telalogin2();//tela que possui a finalidade receber o codigo de acesso para entrar na conta do usuário (LOGAR)

void menuadmin();//função que exibe o menu de opções no gerente 

void consulta();//função que exibe os cadastros dos funcionários do sistema

void altera_login();//função que altera a as informações do funcionário

void excluir_conta();//função que exclui um cadastro 

void pesquisa_codigo(char campo[], int varc, int tam, int x, int y);//função que pesquisa se o código inserido na telalogin2 existe 

void existeArq(); //Função pra verificar se o arquivo existe

void menuFuncionario();//Menu do Funcionário

void incluirPedido(); //Função para incluir pedidos

void consultarPedido(); //Função para consultar pedidos

void alterarPedido(); //Função para alterar os pedidos

void excluirPedido(); //Função para excluir os pedidos

void saida(); //Função para saída do funcionário

void saidaAdm();//Função para saída do gerente

void sabores(); //Sabores das pizzas

int verifica_letra(char var[], int tam);//função que verifica se a string é letra ou número

void verifica_campo(char campo[], int var, int tam, int x, int y);//função que verifica se o campo foi preenchido corretamente


//----------------------------------------------

//Variavéis Globais
char nome[] = " Primeiro nome: ";
char sobrenome[]=  " Sobrenome: ";
char code[]= " Voce sera atendente ou gerente? (A ou G): ";
char codigo[5];
char nome1[20];
char sobrenome1[50];
char f_altera[]=" Entre com o codigo de acesso da sua conta: ";
char code2[5];
char cargo[10];
char cargoaux[]=" Voce sera funcionario ou gerente? ";
char cliente[] = " Cliente:";
char sabor[] = " Sabor:";
char tamanho [] = " Tamanho:";
char campo[]= "Quantidade:  ";
char qtd[3]; 

//Struct de Cadastros
typedef struct{
	char nome[20];
	char sobrenome[50];
	int idade;
	char codigo[5];
	char adm;
	
}cadastro_login;

typedef struct{
   int id;
   char nomec[30];
   char sabor[30];
   char tamanhop[30];
   int qtdp;
   float total;
}Pedidos;


//Variavél principal da struct
cadastro_login cad;

Pedidos  p;

//-------------------------------------------------------------


void printafantasma2(int x, int y)
{
	///printa o fantasma na tela do menuFuncionario
    gotoxy(x,y++);
    textcolor(LIGHTGREEN);
    printf("  .--.   ");
    gotoxy(x,y++);
    textcolor(BRIGHTWHITE);
    printf(" | oo |");
    gotoxy(x,y++);
    textcolor(LIGHTGREEN);
    printf(" | ~~ | ");
    gotoxy(x,y++);
    textcolor(LIGHTGREEN);
    printf(" '^^^^'");
}

//-----------------------------------------------------------
void textcolor(int i)
{ 
	//Função que é usada da interface para colocar cores
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	BOOL b = GetConsoleScreenBufferInfo(h1, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (h1, bufferInfo.wAttributes |= i);
}

//-----------------------------------------------------------
void fantasminhamov2()
{
	//"movimenta" o fantasma na tela do menuFuncionario
    int i;
   	int x = 26;

	for(i=0;i<29;i++){
	    printafantasma2(x, 33);
	    gotoxy(x-1, 33);
	   	printf("  ");
	    gotoxy(x-1, 34);
	    printf("  ");
	   	gotoxy(x-1, 35);
	    printf("  ");
	    gotoxy(x-1, 36);
	    printf("  ");
		x += 2;
	    Sleep(30);
	}
}

//-----------------------------------------------------------
void gameover()
{

	gotoxy(22,22);
	textcolor(LIGHTRED);
	printf("\xDA\xC4\xBF\xDA\xC4\xBF\xDA\xC2\xBF\xDA\xC4\xBF  \xDA\xC4\xBF\xC2  \xC2\xDA\xC4\xBF\xC2\xC4\xBF  \xDA\xC4\xBF\xDA\xC4\xBF\xC2\xC4\xBF\xDA\xC4\xBF  \xDA\xC4\xBF\xC2 \xC2\xDA\xC4\xBF  \xDA\xC4\xBF\xDA\xC4\xBF\xDA\xc2\xBF\xDA\xC4\xBF");
	gotoxy(22,23);
	textcolor(LIGHTRED);
	printf("\xB3\xC4\xC2\xC3\xC4\xB4\xB3\xB3\xB3\xC3\xB4   \xB3 \xB3\xC0\xBF\xDA\xD9\xC3\xB4 \xC3\xC2\xD9  \xC3\xC4\xD9\xC3\xC4\xB4\xC3\xC2\xD9\xC3\xC4\xB4  \xC0\xC4\xBF\xB3 \xB3\xC3\xC4\xB4  \xC3\xB4 \xB3 \xB3\xB3\xB3\xB3\xC3\xB4 ");
	gotoxy(22,24);
	textcolor(LIGHTRED);
	printf("\xC0\xC4\xD9\xC1 \xC1\xC1 \xC1\xC0\xC4\xD9  \xC0\xC4\xD9 \xC0\xD9 \xC0\xC4\xD9\xC1\xC0\xC4  \xC1  \xC1 \xC1\xC1\xC0\xC4\xC1 \xC1  \xC0\xC4\xD9\xC0\xC4\xD9\xC1 \xC1  \xC0  \xC0\xC4\xD9\xC1 \xC1\xC0\xC4\xD9");
}

//-----------------------------------------------------------
void gotoxy(int x, int y)
{
	//Função gotoxy para usar cursor
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
//-----------------------------------------------------------

void inter()
{
	//Função que exibe a interface do sistema (quadrado nos cantos)

	int i;
	//canto superior esquerda
	textcolor(LIGHTYELLOW);
	gotoxy(1,1);
	printf("%c",201);

	// Cima
	for(i = 2; i <= 110; i++){
	    gotoxy(i, 1);
	    textcolor(LIGHTYELLOW);
	    printf("%c", 205);
	}

	//canto inferior  esquerdo
	gotoxy(110,1);
	printf("%c",187);

	//canto superior direito
	gotoxy(1,40);
	printf("%c", 200);

	// baixo
	for(i = 2; i <= 110; i++){
	    gotoxy(i, 40);
	    printf("%c", 205);
	}

	//canto inferior esquerdo
	gotoxy(110,40);
	printf("%c", 188);

	//esquerda
	for(i = 2; i < 40; i++){
	    gotoxy(1,i);
	    printf("%c", 186);
	}

	//direita
	for(i = 2; i < 40; i++){
	    gotoxy(110,i);
		printf("%c", 186);
	}
	gotoxy(1,1);
}

//-----------------------------------------------------------
void desenho()
{
	//Função que imprime o desenho da pizza na tela principal
	//Vapor
 	gotoxy(5,6);
    textcolor(BRIGHTWHITE);
    printf("                )  ");
 	gotoxy(5,7);
    textcolor(BRIGHTWHITE);
    printf("            )  (  (");
	gotoxy(5,8);
    textcolor(BRIGHTWHITE);
    printf("           (   )   )");
	gotoxy(5,9);
    textcolor(BRIGHTWHITE);
    printf("           )      (");
    //Pizza
    gotoxy(5,11);
    textcolor(LIGHTYELLOW );
    printf("       o88888888888o  ");
    gotoxy(5,12);
    textcolor(LIGHTYELLOW );
    printf("    _o888888888888888o_  ");
    gotoxy(5,13);
    textcolor(LIGHTYELLOW );
    printf("  _o88   o    | o  '8888o.");
    gotoxy(5,14);
    textcolor(LIGHTYELLOW );
    printf(" ,88'  .      |   o '888o.");
    gotoxy(5,15);
    textcolor(LIGHTYELLOW );
    printf(",88'    .   o |      o    ®");
    gotoxy(5,16);
    textcolor(LIGHTYELLOW);
	printf("88'  o   .    |  o     ®");
    gotoxy(5,17);
    textcolor(LIGHTYELLOW );
    printf("88    o    . o|      ®");
    gotoxy(5,18);
	textcolor(LIGHTYELLOW );
    printf("88 __________.|    ®");
    gotoxy(5,19);
    textcolor(LIGHTYELLOW );
    printf("88       o   .| o®");
    gotoxy(5,20);
    textcolor(LIGHTYELLOW );
    printf("88,    o   .  |  .®");
    gotoxy(5,21);
	textcolor(LIGHTYELLOW );
    printf("'88,  o   . o | o . ®");
    gotoxy(5,22);
    textcolor(LIGHTYELLOW );
    printf("  '88,   .  o | o  .   ®");
    gotoxy(5,23);
    textcolor(LIGHTYELLOW );
    printf("   '88, .  o  |  o  .   ,®");
	gotoxy(5,24);
    textcolor(LIGHTYELLOW );
    printf("     '888   ,_|_,   888'");
    gotoxy(5,25);
    textcolor(LIGHTYELLOW );
    printf("        'o88888888o'");
    
    gotoxy(34,32);
    printf("o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o");

    gotoxy(26,34);
    textcolor(GREY);
    printf("_____________________________________________________________________");
}


//-----------------------------------------------------------
void printafantasma(int x, int y)
{
	//Função que imprime o fantasma
    gotoxy(x,y++);
    textcolor(LILAC);
    printf("  .--.   ");
       
    gotoxy(x,y++);
    textcolor(BRIGHTWHITE);
    printf(" | oo |");
    
    gotoxy(x,y++);
    textcolor(LILAC);
    printf(" | ~~ | ");
       
	gotoxy(x,y++);
    textcolor(LILAC);
    printf(" '^^^^'"); 
       
}

//-----------------------------------------------------------
void sabores()
{
	//Função que mostra os sabores das pizzas
	int esc;
	inter();

	caixacard(10,5,15,40);

	gotoxy(40,2);
	textcolor(LIGHTRED);
	printf("       ****  PAC PIZZA  ****\n\n");

	gotoxy(12,7);
	textcolor(LIGHTRED);
	printf("       ****  SABORES  ****\n\n");

	gotoxy(19,9);
	textcolor(GREENWATER);
	printf(" %c   MUSSARELA\n", 248);
	gotoxy(19,11);
	printf(" %c   CALABRESA \n", 248);
    gotoxy(19,13);
	printf(" %c   PORTUGUESA \n", 248);
    gotoxy(19,15);
	printf(" %c   FRANGO COM CATUPIRY \n", 248);
	gotoxy(19,17);
	printf(" %c   NAPOLITANA \n", 248);

	gotoxy(60,7);
	textcolor(LIGHTRED);
	printf("       ****  TABELA DE PRE%cOS  ****\n", 128);

	gotoxy(68,9);
	textcolor(GREENWATER);
	printf(" %c   PEQUENA RS 17.99 \n", 248);
	gotoxy(68,11);
	printf(" %c   MEDIA RS 24.99\n", 248);
	gotoxy(68,13);
	printf(" %c   GRANDE  RS 37.00 \n", 248);
	gotoxy(68,15);
	printf(" %c   FAMILIA RS 45.00 \n", 248);
	caixacard(60,5,15,40);
	gameover();
}
	
//-----------------------------------------------------------
void fantasminhamov()
{
	//Função que imprime o fantasma em movimento na tela 
   	int i;
   	int x = 26;

	for(i=0;i<32;i++){
       	printafantasma(x, 30);
       	gotoxy(x-1, 30);
       	printf("  ");
       	gotoxy(x-1, 31);
       	printf("  ");
       	gotoxy(x-1, 32);
       	printf("  ");
       	gotoxy(x-1, 33);
       	printf("  ");
       	x += 2;
       	Sleep(30);
	}

}
	
//-----------------------------------------------------------
void pacpizza(){
	
	//Função que exibe "PAC PIZZA" nas telas
	gotoxy(27,2);
	textcolor(LIGHTRED);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xBB  \xDB\xDB\xDB\xDB\xDB\xBB  \xDB\xDB\xDB\xDB\xDB\xDB\xBB    \xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xBB");
	gotoxy(27,3);
	textcolor(LIGHTRED);
	printf("\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC    \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xBA\xC8\xCD\xCD\xDB\xDB\xDB\xC9\xBC\xC8\xCD\xCD\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB");
	gotoxy(27,4);
	textcolor(LIGHTRED);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xBA         \xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xBA  \xDB\xDB\xDB\xC9\xBC   \xDB\xDB\xDB\xC9\xBC \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA");
	gotoxy(27,5);
	textcolor(LIGHTRED);
	printf("\xDB\xDB\xBA     \xDB\xDB\xBA  \xDB\xDB\xBA\xC8\xDB\xDB\xDB\xDB\xDB\xDB\xBB    \xDB\xDB\xBA     \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xBA  \xDB\xDB\xBA    ");
	gotoxy(27,6);
	textcolor(LIGHTRED);
	printf("\xC8\xCD\xBC     \xC8\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xCD\xCD\xCD\xCD\xBC    \xC8\xCD\xBC     \xC8\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC ");
	
}

//-----------------------------------------------------------
void titulo()
{
	//Função que exibe o nome do sistema 
	desenho();
	gotoxy(37,8);
    textcolor(BLUE);
	printf("\xDB\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDC     \xDC\xDF\xDF\xDC       \xDC\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDC   ");
	gotoxy(37,9);
	textcolor(BLUE);
	printf("\xDB              \xDB    \xDB  \xDB      \xDB         \xDF\xDC   ");
	gotoxy(37,10);
	textcolor(BLUE);
	printf("\xDB              \xDB   \xDB    \xDB    \xDB           \xDB    ");
	gotoxy(37,11);
	textcolor(BLUE);
	printf("\xDB      \x4F      \xDC\xFE  \xDB      \xDB   \xDB          \xDB  ");
	gotoxy(37,12);
	textcolor(BLUE);
	printf("\xDB             \xDB  \xDB        \xDB  \xDB         \xDB");
	gotoxy(37,13);
	textcolor(BLUE);
	printf("\xDB        \xFE\xDF\xDF\xDF\xDF  \xDB     \x4F    \xDB  \xDB       \xDC\xDC\xDC\xDC\xDC    ");
	gotoxy(37,14);
	textcolor(BLUE);
	printf("\xDB       \xDB      \xDB            \xDB  \xDB          \xDC ");
	gotoxy(37,15);
	textcolor(BLUE);
	printf("\xDB  ____ \xDB     \xDB ____________ \xDB  \xDB _____/ \xDC ");
	gotoxy(37,16);
	textcolor(BLUE);
	printf("\xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB    \xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC  \xDF\xDC\xDC\xDC\xDC\xDC\xDC\xDF   ");
	gotoxy(37,18);
    textcolor(LIGHTRED);
	printf("\xDB\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDC  \xDB\xDF\xDF\xDF\xDF\xDF\xDB \xDB\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDB \xDB\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDB         \xDC\xDF\xDF\xDC ");
	gotoxy(37,19);
	textcolor(LIGHTRED);
	printf("\xDB              \xDB \xDB ___ \xDB \xDB      ___ \xDB \xDB      ___ \xDB         \xDB  \xDB ");
	gotoxy(37,20);
	textcolor(LIGHTRED);
	printf("\xDB              \xDB \xDB |   \xDB \xDB\xDC\xDC\xDC\xDC\xDC\xDC    \xDB \xDB\xDC\xDC\xDC\xDC\xDC\xDC    \xDB        \xDB    \xDB");
	gotoxy(37,21);
	textcolor(LIGHTRED);
	printf("\xDB      \x4F      \xDC\xFE \xDB |   \xDB       \xDB   \xDB        \xDB   \xDB        \xDB      \xDB");
	gotoxy(37,22);
	textcolor(LIGHTRED);
	printf("\xDB             \xDB  \xDB |   \xDB      \xDB   \xDB        \xDB   \xDB        \xDB        \xDB");
	gotoxy(37,23);
	textcolor(LIGHTRED);
	printf("\xDB        \xFE\xDF\xDF\xDF\xDF   \xDB |   \xDB     \xDB   \xDB        \xDB   \xDB        \xDB     \x4F    \xDB");
	gotoxy(37,24);
	textcolor(LIGHTRED);
	printf("\xDB       \xDB        \xDB     \xDB    \xDB   \xDB        \xDB   \xDB        \xDB            \xDB");
	gotoxy(37,25);
	textcolor(LIGHTRED);
	printf("\xDB  ____ \xDB        \xDB     \xDB   \xDB    \xDF\xDF\xDF\xDF\xDB   \xDB    \xDF\xDF\xDF\xDF\xDB   \xDB ____________ \xDB");
	gotoxy(37,26);
	textcolor(LIGHTRED);
	printf("\xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB        \xDB\xDC\xDC\xDC\xDC\xDC\xDB  \xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB  \xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB  \xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC   ");
	getchar();
	fantasminhamov();
	gotoxy(38,36);
	textcolor(LIGHTYELLOW);
	printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR\n");
	getch();
}

//-----------------------------------------------------------
void gameover_2()
{
	//Função que imprime "GAME OVER PARA A SUA FOME" nas telas
	gotoxy(27,22);
	textcolor(LIGHTRED);
	printf("\xDA\xC4\xBF\xDA\xC4\xBF\xDA\xC2\xBF\xDA\xC4\xBF  \xDA\xC4\xBF\xC2  \xC2\xDA\xC4\xBF\xC2\xC4\xBF  \xDA\xC4\xBF\xDA\xC4\xBF\xC2\xC4\xBF\xDA\xC4\xBF  \xDA\xC4\xBF\xC2 \xC2\xDA\xC4\xBF  \xDA\xC4\xBF\xDA\xC4\xBF\xDA\xc2\xBF\xDA\xC4\xBF");
	gotoxy(27,23);
	textcolor(LIGHTRED);
	printf("\xB3\xC4\xC2\xC3\xC4\xB4\xB3\xB3\xB3\xC3\xB4   \xB3 \xB3\xC0\xBF\xDA\xD9\xC3\xB4 \xC3\xC2\xD9  \xC3\xC4\xD9\xC3\xC4\xB4\xC3\xC2\xD9\xC3\xC4\xB4  \xC0\xC4\xBF\xB3 \xB3\xC3\xC4\xB4  \xC3\xB4 \xB3 \xB3\xB3\xB3\xB3\xC3\xB4 ");
	gotoxy(27,24);
	textcolor(LIGHTRED);
	printf("\xC0\xC4\xD9\xC1 \xC1\xC1 \xC1\xC0\xC4\xD9  \xC0\xC4\xD9 \xC0\xD9 \xC0\xC4\xD9\xC1\xC0\xC4  \xC1  \xC1 \xC1\xC1\xC0\xC4\xC1 \xC1  \xC0\xC4\xD9\xC0\xC4\xD9\xC1 \xC1  \xC0  \xC0\xC4\xD9\xC1 \xC1\xC0\xC4\xD9");
}

//-----------------------------------------------------------
void caixacard(int x, int y, int tam_vertical, int tam_horizontal)
{
	//printa a caixa em qualquer tamanho
    // Variáveis de auxílio
	int i;
	int x_tam = x + tam_horizontal;
    int y_tam = y + tam_vertical;

    // Cor Default
	textcolor(LIGHTYELLOW);

	// Canto superior esquerdo.
    gotoxy(x,y);
    printf("%c", 254);

    // Canto superior direito.
    gotoxy(x_tam, y);
    printf("%c",254);

    // Canto inferior esquerdo.
    gotoxy(x, y_tam);
    printf("%c",254);

    // Canto inferior direito
    gotoxy(x_tam, y_tam);
    printf("%c", 254);

    // Barra de cima.
    for(i = x; i < tam_horizontal + x; i++){
        gotoxy(i, y);
        printf("%c  ", 254);
    }

    // Barra de baixo.
    for(i = x; i < x_tam; i++){
        gotoxy(i, y_tam);
        printf("%c", 254);
    }

    // Barra esquerda
    for(i =  y; i < y_tam; i++){
        gotoxy(x,i);
        printf("%c", 254);
    }

    // Barra direita
    for(i = y; i < y_tam; i++){
        gotoxy(x_tam, i);
        printf("%c", 254);
    }
}

//-----------------------------------------------------------
void caixinha(int x, int y, int tamanho, char *texto)
{
	//tem a mesma função da caixacard mas possui a opção de preencher com texto
	
    //canto superior esquerda
	textcolor(LIGHTYELLOW);
	gotoxy(x,y);
    printf("%c",254);
    //barra superior
    int i = x + 1;
    for(; i < tamanho; i++){
	    gotoxy(i,y);
	    printf("%c", 254);
    }
    //canto superior direito
    gotoxy(tamanho,y++);
    printf("%c", 254);
    
	//esquerda
    gotoxy(x,y);
    printf("%c", 254);
    
	//texto
    gotoxy(x+1, y);
    printf("%s", texto);
    
	//direita
	gotoxy(tamanho,y++);
    printf("%c",254);
   
    //canto inferior  esquerdo
    gotoxy(x,y);
    printf("%c",254);
    
	//barra inferior
    i = x + 1;
    for(; i < tamanho; i++){
        gotoxy(i,y);
        printf("%c", 254);
    }
   
    //canto inferior direito
    gotoxy(tamanho,y);
    printf("%c", 254);
}

//-----------------------------------------------------------
void caixinha_verde(int x, int y, int tamanho, char *texto)
{
	//tem a mesma finalidade da caixinha, apenas muda de cor
	
    //canto superior esquerda
	textcolor(LIGHTGREEN);
	gotoxy(x,y);
    printf("%c",254);
    
	//barra superior
    int i = x + 1;
    for(; i < tamanho; i++){
        gotoxy(i,y);
        printf("%c", 254);
    }
   
    //canto superior direito
    gotoxy(tamanho,y++);
    printf("%c", 254);
   
    //esquerda
    gotoxy(x,y);
    printf("%c", 254);
    
	//texto
    gotoxy(x+1, y);
    printf("%s", texto);
   
    //direita
    gotoxy(tamanho,y++);
    printf("%c",254);
    
	//canto inferior  esquerdo
    gotoxy(x,y);
    printf("%c",254);
   
    //barra inferior
    i = x + 1;
    for(; i < tamanho; i++){
        gotoxy(i,y);
        printf("%c", 254);
    }
    //canto inferior direito
    gotoxy(tamanho,y);
    printf("%c", 254);

}


//-----------------------------------------------------------
void telalogin1()
{
	//imprime uma tela com duas opções (CADASTRAR OU LOGAR)
	system("cls");
	inter();
	pacpizza();
	
    caixacard(42,10,6,35);
	gotoxy(55,13);
	textcolor(GREENWATER);
	printf("CADASTRAR-SE ");
	gotoxy(46,11);

	caixacard(42,18,6,35);
	gotoxy(58,21);
	textcolor(GREENWATER);
	printf("LOGAR");
	gotoxy(39,22);
	
	caixacard(42,26,6,35);
	gotoxy(59,29);
	textcolor(GREENWATER);
	printf("SAIR");
	gotoxy(52,33);
   
	//Variaveis da seta
	int x = 35, y = 13;
    char tecla;

    // Printa a seta pela primeira vez.
    gotoxy(x,y);
    printf("%c", 175);

	do{

		tecla=getch();
		switch(tecla){
	
			case CIMA:
				if (y >= 17) { // Verifica pra não passar da tela.
	                gotoxy(x, y);
	                printf(" ");
	                gotoxy(x, y-=8);
	                printf("%c", 175);
	            }
	
	            break;
	
			case BAIXO:
				if(y <= 21){
		           	gotoxy(x,y);
		           	printf(" ");
		           	gotoxy(x,y+= 8);
		            printf("%c", 175);
	    		}
	    		
	            break;
		        }
	
				}while(tecla!=ENTER);
	
	
	//Chama as funções de acordo com a posicao desejada
	if(x== 35 && y==13){
		system("cls");
		cadast();
	}
	
	if(x== 35 && y==21){
		system("cls");
		telalogin2();
		getchar();
		system("cls");
	}	
				
	if(x == 35 && y == 29){
		system("cls");
		exit(0);
	}
}
	

//-----------------------------------------------------------
void telalogin2(){
	
	inter();
	pacpizza();
	FILE *arq;
	char temp[5];
	int encont=FALSE;

	//ABRE O ARQUIVO EM MODO LEITURA
	arq=fopen("./arq.cadastro", "rb");


	//VERIFICAÇÃO
	if(arq==NULL){
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(42,11);
		textcolor(LIGHTRED);
		printf("  Nenhum cadastro realizado!\n");
	  	getchar();
	   	system("cls");
		telalogin1();
	}

	//COLETA A SENHA INSERIDA
	fflush(stdin);
	caixinha(30,9, 90,"");
	gotoxy(31,10);
	textcolor(GREENWATER);
	printf(" Digite seu codigo de acesso: ");
	gotoxy(61,10);
	gets(temp);
	fflush(stdin);

	//LAÇO PARA VERIFICAR A SENHA NO ARQUIVO
	while(fread(&cad, sizeof(cadastro_login), 1, arq)){
		if(strcmp(cad.codigo,temp)==0){
			encont=TRUE;
			fclose(arq);
			caixinha_verde(30,9,90, "");
			getchar();
			break;
		}
	}

	system("cls");
	setbuf(stdin, NULL);

	//CONDIÇÃO CASO NÃO FOR ENCONTRADO
	if(!encont){
		inter();
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(42,11);
		textcolor(LIGHTRED);	
		printf("C%cdigo de acesso n%co encontrado" ,162,198);
		getchar();
		system("cls");
		telalogin1();
	}

	if (cad.adm == 'G'){
		system("cls");
		menuadmin();
	}else
		if(cad.adm == 'A'){
			system("Cls");
			menuFuncionario();
		}	
}

//-----------------------------------------------------------
int verifica_letra(char campo[], int tam1)
{
	//Função que verifica se foi digitado letra ou numero
    int i;
    int aux;
    
    //LAÇO PARA VERIFICAR A QUANTIDADE DE CARACTERES
    for(i=0;i<tam1;i++){
        aux=campo[i];
        
		if(isalpha(aux)){
        	//RETORNA 1 SE FOR CARECTERE
        	return 1;
        	
	}else
	//RETORNA PARA 0 SE FOR NÚMERO
	return 0;
 }
}

//-----------------------------------------------------------
/*void verifica_num(char campo[],char varc[],int tam,int x , int y)
{
	int tamanho;
	int aux;
	
	do{
		setbuf(stdin,NULL);
    	gotoxy(x + strlen(campo),y);
        gets(varc);
        setbuf(stdin,NULL);
        tamanho=strlen(varc);
        aux=verifica_letra(varc, tam);
        
        //CONDIÇÃO CASO NÃO FOR DIGITADO NADA
        if(varc[0]=='\0'){
            gotoxy(x + strlen(campo),y);
            printf("                     ");
            textcolor(LIGHTRED);
            gotoxy(x + strlen(campo),y);
            printf("CAMPO OBRIGAT%cRIO", 224);
    		getchar();
    		textcolor(GREENWATER);
        }
        
        if(aux==1){
        	gotoxy(x + strlen(campo),y);
        	printf("                     ");
        	textcolor(LIGHTRED);
            gotoxy(x + strlen(campo),y);
            printf("LETRAS S%cO INVALIDAS", 224);
    		getchar();
    		textcolor(GREENWATER);
		}
		
		if(tamanho>tam){
            gotoxy(x + strlen(campo),y);
            printf("                      ");
            textcolor(LIGHTRED);
            gotoxy(x + strlen(campo),y);
            printf("INV%cLIDO", 181);
			getchar();
			textcolor(GREENWATER);
        }
        
      gotoxy(x + strlen(campo),y);
    	printf("                       ");
        
	}while(aux ==1 || tamanho>tam || varc[0] =='\0');
	
}
*/
//-----------------------------------------------------------
void verifica_campo(char *var, char campo[], int tam, int x, int y)
{
	//Função qu verifica a string do campo
	
    int aux;
    int tamanho;
    
    //LAÇO PARA COLETAR AS OS DADOS ENQUANTO NÃO ESTIVER TUDO CORRETO
    do{
    	
    	setbuf(stdin,NULL);
    	gotoxy(x + strlen(campo),y);
        gets(var);
        setbuf(stdin,NULL);
        tamanho=strlen(var);
        aux=verifica_letra(var, tam);
        
        //CONDIÇÃO CASO NÃO FOR DIGITADO NADA
        if(var[0]=='\0'){
            gotoxy(x + strlen(campo),y);
            printf("                     ");
            textcolor(LIGHTRED);
            gotoxy(x + strlen(campo),y);
            printf("CAMPO OBRIGAT%cRIO", 224);
    		getchar();
    		textcolor(GREENWATER);
            
        }
        
        //CONDIÇÃO CASO A QUANTIDADE DE CARACTERES FOR MAIOR QUE O LIMITE DISPONÍVEL
        if(tamanho>tam){
            gotoxy(x + strlen(campo),y);
            printf("                      ");
            textcolor(LIGHTRED);
            gotoxy(x + strlen(campo),y);
            printf("INV%cLIDO", 181);
			getchar();
			textcolor(GREENWATER);
        }
        	
    	gotoxy(x + strlen(campo),y);
    	printf("                       ");
        
    }while(var[0]=='\0' || aux==0 || tamanho>tam);

	//IMPRIME A VARIAVEL 
	gotoxy(x + strlen(campo),y);
	puts(var);
}

//--------------------------------------------------------------
void menuFuncionario(){
	
	//Função Menu Funcionário - MENU PRINCIPAL DO FUNCIONÁRIO
	system("cls");
	inter();
	pacpizza();
	caixinha(22,12,90," ");
	gotoxy(23,13);
	textcolor(GREENWATER);
	printf("                        -INCLUIR PEDIDO \n\n");
	caixinha(22,16,90," ");
	gotoxy(23,17);
	textcolor(GREENWATER);
	printf("                        -CONSULTAR PEDIDO \n\n");
	caixinha(22,20,90," ");
	gotoxy(23,21);
	textcolor(GREENWATER);
	printf("                        -ALTERAR PEDIDO \n\n");
	caixinha(22,24,90," ");
	gotoxy(23,25);
	textcolor(GREENWATER);
	printf("                        -CANCELAR PEDIDO \n\n");
	caixinha(22,28,90," ");
	gotoxy(23,29);
	textcolor(GREENWATER);
	printf("                            -SAIR \n\n");

    gotoxy(34,35);
    printf("o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o");
    gotoxy(22,37);
    textcolor(GREY);
    printf("_____________________________________________________________________");


	fantasminhamov2();
	int x = 20, y = 13;
    char tecla;

    // Printa a seta pela primeira vez.
    gotoxy(x,y);
    printf("%c", 175);


    do {
        tecla = getch();

        switch (tecla) {
	        case CIMA:
	            if (y >= 17) { // Verifica pra não passar da tela.
	                gotoxy(x, y);
	                printf(" ");
	                gotoxy(x, y-=4);
	                printf("%c", 175);
	            }
	
	            break;
	            
	        case BAIXO:
	        	if(y<=27){
		           	gotoxy(x,y);
		           	printf(" ");
		           	gotoxy(x,y+=4);
		            printf("%c", 175);
	        	}
	        	
	            break;
	        }

        }while (tecla != ENTER);


	if(x== 20 && y == 13){
		incluirPedido();
	}

	if(x== 20 && y == 17){
		consultarPedido();
	}

	if(x== 20 && y== 21){
		//system("cls");
		alterarPedido();
	}

	if(x== 20 && y== 25){
		//system("cls");
		excluirPedido();
	}

	if(x== 20 && y== 29){
		saida();
	}
}
//--------------------------------------------------------------
void existeArq()
{
	//Função pra verificar se o arquivo existe

	//Abrindo o arquivo
	FILE * file = fopen("./numero_pedido.dat","rb");

	int var = 0;

	// Cria o arquivo se ele não existir
	if (file == NULL) {
		fclose(file);
		file = fopen("./numero_pedido.dat","wb");
		fwrite(&var, sizeof(int), 1, file);
	}

	//Fechando arquivo principal
	fclose(file);
}

//--------------------------------------------------------------
void  incluirPedido()
{
	//----------------------------------------------------
	//Função inclusão - Inclui os pedidos via funcionario
	system("cls");
	int esc;

	//----------------------------------------------------
	//Abertura do  arquivo
	FILE* file = fopen("./pizza.dat","ab");
	FILE * fileVar = fopen("./numero_pedido.dat","rb");

	//verifição de erro na abertura do arquivo
	if(file == NULL && fileVar == NULL) {
		printf("erro\n");
		exit(1);
	}

	//-----------------------------------------------------
	sabores();
	//Função para mostrar os cardapio das pizza
	caixinha(10,26,50," Cliente: \n");
	gotoxy(41,27);
	textcolor(GREENWATER);
	verifica_campo(p.nomec, cliente, 20,11, 27);
	setbuf(stdin,NULL);
	
	caixinha(10,30,50," Sabor: \n");
	gotoxy(18,31);
	textcolor(GREENWATER);
	verifica_campo(p.sabor, sabor,18,11,31);
	setbuf(stdin, NULL);
	
	caixinha(60,26,100," Quantidade: \n");
	gotoxy(73,27);
	textcolor(GREENWATER);
	scanf("%d",&p.qtdp);
	setbuf(stdin, NULL);
	
	caixinha(60,30,100," Tamanho: \n");
	gotoxy(70,30);
	textcolor(GREENWATER);
	verifica_campo(p.tamanhop, tamanho,15,62,31);
	setbuf(stdin, NULL);
	if(strcmp(p.tamanhop,"Pequena")==0 || strcmp(p.tamanhop,"pequena")==0 ||strcmp(p.tamanhop,"PEQUENA")==0){
		p.total = (p.qtdp * 15.00);
	}
	if(strcmp(p.tamanhop,"Media")==0 || strcmp(p.tamanhop,"media")==0 ||strcmp(p.tamanhop,"MEDIA")==0){
		p.total = (p.qtdp * 25.00);
	}
	if(strcmp(p.tamanhop,"Grande")==0 || strcmp(p.tamanhop,"grande")==0 ||strcmp(p.tamanhop,"GRANDE")==0){
		p.total = (p.qtdp * 35.00);
	}
	if(strcmp(p.tamanhop,"Familia")==0 || strcmp(p.tamanhop,"familia")==0 ||strcmp(p.tamanhop,"FAMILIA")==0){
		p.total = (p.qtdp * 45.00);
	}

	caixinha(80,36,88," OKAY");
	gotoxy(85,37);

	// Colocando o ID na ordem correta.
	int var;

	fread(&var, sizeof(int), 1, fileVar);
	var++;
	
	printf("%d\n\n", var);
	
	p.id = var;

	fclose(fileVar);

	// Escrevendo o ID de volta no arquivo da variável.
	fileVar = fopen("./numero_pedido.dat", "wb");
	fwrite(&var, sizeof(int), 1, fileVar);

	//Leitura da struct no arquivo
	fwrite(&p,sizeof(Pedidos),1,file);

	//Fechando o arquivo principal
	fclose(file);
	fclose(fileVar);
	getchar();
	system("cls");

	//Mostra as informações do pedido pro usuário
	inter();
	pacpizza();
	caixacard(41,10,10,40);
	gotoxy(51,11);
	textcolor(LIGHTRED);
	
	printf("   PEDIDO %d",p.id);
	gotoxy(50,13);
	textcolor(GREENWATER);

	printf("Cliente: %s",p.nomec);
	gotoxy(50,14);
	textcolor(GREENWATER);

	printf("Sabor Pizza: %s",p.sabor);
	gotoxy(50,15);
	textcolor(GREENWATER);

	printf("Quantidade: %d",p.qtdp);
	gotoxy(50,16);
	textcolor(GREENWATER);

	printf("Tamanho: %s", p.tamanhop);
	gotoxy(50,17);
	textcolor(GREENWATER);


	//Condição para novo pedido
	gotoxy(40,22);
	textcolor(LIGHTYELLOW);
	printf("   Voc%c deseja fazer mais um pedido? \n", 136);
	gotoxy(50,23);
	textcolor(LIGHTGREEN);

	printf("     - SIM\n");
	gotoxy(50,24);
	textcolor(LIGHTRED);
	printf("     - N%cO\n", 199);

	int x = 48, y = 23;
    char tecla;

   // Printa a seta pela primeira vez.
   gotoxy(x,y);
   printf("%c", 175);


   do{
        tecla = getch();

        switch (tecla) {
        case CIMA:
            if (y == 24) { // Verifica pra não passar da tela.
                gotoxy(x, y--);
                printf(" ");
                gotoxy(x, y);
                printf("%c", 175);
            }
            break;
        case BAIXO:
        	if(y==23){ // Verifica para não passar da tela
	           	gotoxy(x,y++);
	           	printf(" ");
	           	gotoxy(x,y);
	            printf("%c", 175);
        	}
            break;
        }

    }while (tecla != ENTER);


	if(x == 48 && y == 23){
	   fflush(stdin);
	   incluirPedido();
	}
	if(x == 48 && y ==24){
      fflush(stdin);
      menuFuncionario();
	}
}

//--------------------------------------------------------------
void consultarPedido()
{
	//Função Consultar Pedido - consulta os pedidos via funcionário
	system("cls");
	inter();
	//Abertura do arquivo de pizza
	FILE* file = fopen("./pizza.dat","rb");

	//Verificação de erro
	if(file == NULL){
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(42,11);
		textcolor(LIGHTRED);
	    printf("  Nenhum pedido realizado!\n");
	    getchar();
	    system("cls");
	    menuFuncionario();
	}else{
	    int total = 0;
	    int cont = 1;

	    pacpizza();
	    gotoxy(41,28);
        textcolor(GREENWATER);
		printf("PRESSIONE ENTER PARA O PR%cXIMO PEDIDO\n", 224);
	
		//caixinha para ir ao pedido anterior
		caixacard(6,32,3,11);
        gotoxy(10,33);
        textcolor(GREENWATER);
        printf("<<");
        gotoxy(7,34);
        textcolor(GREENWATER);
        printf(" Anterior");
        
		//caixinha para sair da visualizção dos pedidos no momento que o usuário quiser
        caixacard(54,32,3,11);
        gotoxy(57,33);
        textcolor(GREENWATER);
        printf(" ESC ");
        gotoxy(57,34);
        textcolor(GREENWATER);
        printf(" SAIR");
       
	    //caixinha para ir ao próximo pedido
        caixacard(94,32,3,11);
        gotoxy(98,33);
        textcolor(GREENWATER);
        printf(">>");
        gotoxy(95,34);
        textcolor(GREENWATER);
        printf(" Proximo");

	    while(fread(&p,sizeof(Pedidos),1,file)) total++;
	    rewind(file);

        while(fread(&p,sizeof(Pedidos),1,file)) {
            caixacard(39,10,10,39);
            gotoxy(45,11);
            textcolor(LIGHTRED);
            printf("\t   PEDIDO %d",p.id);
            gotoxy(45,13);
            textcolor(GREENWATER);
            printf("Cliente: %s",p.nomec);
            gotoxy(45,14);
            textcolor(GREENWATER);
            printf("Sabor Pizza: %s",p.sabor);
            gotoxy(45,15);
            textcolor(GREENWATER);
            printf("Quantidade: %d",p.qtdp);
            gotoxy(45,16);
            textcolor(GREENWATER);
            printf("Tamanho: %s", p.tamanhop);
            gotoxy(45,17);
            textcolor(GREENWATER);
            printf("Total a pagar: %.2f", p.total);
            caixinha(65, 24, 54, "");
            gotoxy(56, 25);
            printf("%.2d / %.2d", cont, total);

            // Isso aqui apaga a tabela de pedidos.
            int tecla;
            do {
                tecla = getch();

                if (tecla == ESC) {
                    fclose(file);
                    menuFuncionario();
                } else 
				if (tecla == ESQUERDA && cont > 1) {
                    cont--; // Só pra contar a quantidade de pedidos.
                    fseek(file, -sizeof(Pedidos) * 2, SEEK_CUR); // Isso aqui é o que faz voltar.
                } else 
				if (tecla == DIREITA && cont < total) {
                    cont++; // Só pra contar a quantidade de pedidos.
                } else {
                    tecla = ENTER;
                }

            }while (tecla == ENTER);

            gotoxy(35, 10);
            printf("                                                            ");
            gotoxy(35, 11);
            printf("                                                            ");
            gotoxy(35, 12);
            printf("                                                            ");
            gotoxy(35, 13);
            printf("                                                            ");
            gotoxy(35, 14);
            printf("                                                            ");
            gotoxy(35, 15);
            printf("                                                            ");
        }
    }

	//Fechando arquivo principal
	fclose(file);
	menuFuncionario();
}

//-----------------------------------------------------
void alterarPedido()
{
	//Função Alterar Pedidos - Altera pedido via funcionário
	system("cls");
	inter();
	
	//Declaração dos ponteiros dos arquivos
	FILE *file; //arquivo principal
	FILE *arquivo_auxiliar; //arquivo auxiliar
	int encontra = FALSE; //teste de encontrado
	int pedido;
	
	//Abertura do arquivo
	file=fopen("./pizza.dat", "rb");
	
	// TODO cadê a verificação se o ponteiro retornou NULL?
	
	//Recebendo dados para comparação
	pacpizza();
	caixacard(36,10,3,40);
	gotoxy(42,11);
	textcolor(LIGHTRED);
	printf("Insira o numero do pedido?\n");
	gotoxy(70,11);
	scanf("%d", &pedido);
	getchar();
	system("cls");
	
	//Loop para verificar informações recebidas
	while(fread(&p, sizeof(Pedidos), 1, file)){
		if(p.id == pedido){
			encontra = TRUE;
			break;
		}
	}
	
	system("cls");
	setbuf(stdin, NULL);
	
	//Condição caso não seja encontrado
	if(!encontra){
		inter();
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(44,11);
	   	textcolor(LIGHTRED);
		printf("  Pedido n%co encontrado!\n", 198);
		getchar();
		//Retorna para menu do funcionário
		menuFuncionario();
	}
	
	//Exibe as informações do pedido
	inter();
	pacpizza();
	caixacard(41,10,10,40);
	gotoxy(48,11);
	textcolor(LIGHTRED);
	setbuf(stdin, NULL);
	
	printf("\t   PEDIDO %d\n ",p.id);
	gotoxy(47,13);
	textcolor(GREENWATER);
	
	printf("Cliente: %s \n",p.nomec);
	gotoxy(47,14);
	textcolor(GREENWATER);
	
	printf("Sabor Pizza: %s \n",p.sabor);
	gotoxy(47,15);
	textcolor(GREENWATER);
	
	printf("Quantidade: %d \n",p.qtdp);
	gotoxy(47,16);
	textcolor(GREENWATER);
	
	printf("Tamanho: %s \n", p.tamanhop);
	gotoxy(47,17);
	textcolor(GREENWATER);
	
	printf("Total a pagar: %.2f \n", p.total);
	printf("\n\n\n");
	getchar();
	system("cls");
	setbuf(stdin, NULL);
	
	sabores(); //Mostra cardapio
	//-----------------------------------------------------
	caixinha(10,26,50," Cliente: \n");
	gotoxy(41,27);
	textcolor(GREENWATER);
	verifica_campo(p.nomec, cliente, 200,11,27);
	setbuf(stdin,NULL);
	
	caixinha(10,30,50," Sabor: \n");
	gotoxy(18,31);
	textcolor(GREENWATER);
	verifica_campo(p.sabor, sabor,10,11,31);
	setbuf(stdin, NULL);
	
	caixinha(60,26,100," Quantidade: \n");
	gotoxy(73,27);
	textcolor(GREENWATER);
	scanf("%d",&p.qtdp);
	setbuf(stdin, NULL);
	
	caixinha(60,30,100," Tamanho: \n");
	gotoxy(70,30);
	textcolor(GREENWATER);
	verifica_campo(p.tamanhop, tamanho,10,62,31);
	setbuf(stdin, NULL);
	
	if(strcmp(p.tamanhop,"Pequena")==0 || strcmp(p.tamanhop,"pequena")==0 ||strcmp(p.tamanhop,"PEQUENA")==0){
		p.total = (p.qtdp * 15.00);
	}
	if(strcmp(p.tamanhop,"Media")==0 || strcmp(p.tamanhop,"media")==0 ||strcmp(p.tamanhop,"MEDIA")==0){
		p.total = (p.qtdp * 25.00);
	}
	if(strcmp(p.tamanhop,"Grande")==0 || strcmp(p.tamanhop,"grande")==0 ||strcmp(p.tamanhop,"GRANDE")==0){
		p.total = (p.qtdp * 35.00);
	}
	if(strcmp(p.tamanhop,"Familia")==0 || strcmp(p.tamanhop,"familia")==0 ||strcmp(p.tamanhop,"FAMILIA")==0){
		p.total = (p.qtdp * 45.00);
	}
	
	caixinha(80,38,88," OKAY");
	gotoxy(84,37);
	system("cls");

	//
	
	rewind(file);
	
	//Verificação sobre a criação do arquivo
	if(file == NULL){
		printf("Problemas na cria%c%co do arquivo", 135,198);
		exit(1);
		}else{
			//Declarando outra variável para a struct
			Pedidos p_aux;
			while(fread(&p_aux,sizeof(Pedidos), 1, file)){
				if(p.id == p_aux.id && p.id != pedido){
					system("cls");
					printf("Erro, login existente");
					//Fechando arquivo principal
					fclose(file);
					getchar();
					menuFuncionario();
				}
			}
 	}
 
	
	//fechando arquivo principal
	fclose(file);
	
	//Abre arquivo auxiliar em adição
	arquivo_auxiliar = fopen("./arquivo_auxiliar.dat", "ab");
	
	//Abre arquivo principal em leitura
	file =fopen("./pizza.dat", "rb"); 
	
	if( arquivo_auxiliar == NULL && file == NULL){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}else{
	//Pega da variavel alterada e passa pro arquivo auxiliar
	fwrite(&p,sizeof(Pedidos),1, arquivo_auxiliar);
	while(fread(&p,sizeof(Pedidos),1, file)){
		if(p.id != pedido){
			fwrite(&p,sizeof(Pedidos), 1,arquivo_auxiliar);
			}
	}
	}	
	//Fecha tudo(os dois arquivos)
	fclose(file);
	fclose(arquivo_auxiliar);
	
	//renomeia
	remove("./pizza.dat"); // Remove o arquivo principal
	rename("./arquivo_auxiliar.dat" ,"./pizza.dat"); // Renomeia o novo arquivo para o nome do arquivo principal
	
	inter();
	pacpizza();
	caixacard(36,10,3,40);
	gotoxy(44,11);
	textcolor(LIGHTGREEN);
	printf("  Altera%c%co concluida!\n", 135,198);
	getchar();
	system("cls");
	menuFuncionario();
	
}
	
//-----------------------------------------------------
void excluirPedido()
{
	//Função Excluir Pedidos - exclui pedidos via funcinário
	system("cls");
	inter();

	//Abertura do arquivo de pedidos
	FILE *file = fopen("./pizza.dat", "rb");
	int aux = FALSE; //Variavel para verificar se encontrou o arquivo
	int NumPedido;
	int Esc;

	pacpizza();
	caixacard(36,10,3,40);
	gotoxy(42,11);
	textcolor(LIGHTRED);
	printf("Insira o n%cmero do pedido: \n", 163);
	gotoxy(69,11);
	scanf("%d",&NumPedido);
	setbuf(stdin, NULL);

	while(fread(&p, sizeof(Pedidos), 1, file)){ //Lê todo o arquivo
		if(p.id == NumPedido){ //Verifica se o pedido informado foi encontrado
			aux = TRUE;
			break; //Sai do laço
		}
	}

	system("cls");
	setbuf(stdin, NULL);
	fclose(file);

	//Caso não encontre
	if(!aux){
		inter();	
		pacpizza();
		caixacard(28,10,4,60);
		gotoxy(45,11);
		textcolor(LIGHTRED);	
		printf("Pedido n%co encontrado\n", 198);
		gotoxy(38,12);
		printf(" Pressione entre para voltar ao menu\n");
		getchar();
		setbuf(stdin, NULL);
		menuFuncionario();
	}

	system("cls");
	setbuf(stdin, NULL);

	//Exibe informação do Pedido
	inter();
	pacpizza();
	caixacard(41,10,10,40);
	gotoxy(48,11);
	textcolor(LIGHTRED);
	
	printf("    PEDIDO %d",p.id);
	gotoxy(47,13);
	textcolor(GREENWATER);
	
	printf("Cliente: %s",p.nomec);
	gotoxy(47,14);
	textcolor(GREENWATER);
	
	printf("Sabor Pizza: %s",p.sabor);
	gotoxy(47,15);
	textcolor(GREENWATER);
	
	printf("Quantidade: %d",p.qtdp);
	gotoxy(47,16);
	textcolor(GREENWATER);
	
	printf("Tamanho: %s", p.tamanhop);
	gotoxy(47,17);
	textcolor(GREENWATER);
	
	printf("Total a pagar: %.2f", p.total);
	printf("\n\n\n");

	//Usuario tem certeza que deseja apagar?
	gotoxy(44,23);
	textcolor(GREENWATER);
	printf("  Deseja cancelar o pedido?\n");
	gotoxy(55,25);
	textcolor(LIGHTGREEN);
	
	printf("-SIM");
	gotoxy(55,26);
	textcolor(LIGHTRED);
	
	printf("-NAO\n");
	gotoxy(45,27);
	setbuf(stdin, NULL);
	
	int x = 53, y = 25;
    char tecla;

   // Printa a seta pela primeira vez.
   gotoxy(x,y);
   printf("%c", 175);


   do{
        tecla = getch();

        switch (tecla) {
        case CIMA:
            if (y == 26) { // Verifica pra não passar da tela.
                gotoxy(x, y--);
                printf(" ");
                gotoxy(x, y);
                printf("%c", 175);
            }
            break;
        case BAIXO:
        	if(y==25){ // Verifica para não passar da tela
	           	gotoxy(x,y++);
	           	printf(" ");
	           	gotoxy(x,y);
	            printf("%c", 175);
        	}
            break;
        }

    }while (tecla != ENTER);


	if(x == 53 && y == 25){
   fflush(stdin);
   
	//Cria novo arquivo
	FILE *fileAuxiliar = fopen("./arquivo_auxiliar.dat", "ab");
	
	//Reabre o arquivo principal
	file = fopen("./pizza.dat", "rb");

	//Verificação na criação do arquivo
	if(file == NULL || fileAuxiliar == NULL){
		printf("Problemas na cria%c%co do arquivo\n",135,198);
		setbuf(stdin, NULL);
		getchar();
		menuFuncionario();
	}else{
		while(fread(&p, sizeof(Pedidos), 1, file)){
		if(p.id != NumPedido){ //adiciona os registros no novo arquivo,menos o que nõo vai mais ser utilizado
			fwrite(&p, sizeof(Pedidos), 1, fileAuxiliar);
		}
		}
	}
	//Fechando todos os arquivos
	fclose(file);
	fclose(fileAuxiliar);

	//renomeia
	remove("./pizza.dat"); // Remove o arquivo principal
	rename("./arquivo_auxiliar.dat" ,"./pizza.dat"); // Renomeia o novo arquivo para o nome do arquivo principal
	
	system("cls");
	inter();
	pacpizza();
	caixacard(36,10,3,40);
	gotoxy(42,11);
	textcolor(LIGHTGREEN);
	printf("     Pedido Cancelado!\n");
	getchar();
	system("cls");
	menuFuncionario();
	}
	if(x == 53 && y ==26){
	    system("cls");
	    pacpizza();
		caixacard(28,10,4,60);
		gotoxy(45,11);
		textcolor(LIGHTRED);
		printf("Operac%co cancelada\n", 198);
		gotoxy(38,12);
		printf(" Pressione entre para voltar ao menu\n");
		setbuf(stdin, NULL);
		getchar();
		menuFuncionario();
	}
	
}
//-----------------------------------------------------
void saidaAdm(){
	//Função pra saída do gerente
	system("cls");
	int e;
	inter();
	pacpizza();
		
	caixacard(36,10,3,40);
   	gotoxy(37,11);
	textcolor(LIGHTYELLOW);
	printf("    Deseja sair da area do gerente?", 136);
	gotoxy(50,14);
	textcolor(LIGHTGREEN);

	printf("     - SIM\n");
	gotoxy(50,15);
	textcolor(LIGHTRED);
	printf("     - N%cO\n", 199);

	int x = 48, y = 14;
    char tecla;

   // Printa a seta pela primeira vez.
   gotoxy(x,y);
   printf("%c", 175);


   do{
        tecla = getch();

        switch (tecla) {
        case CIMA:
            if (y == 15) { // Verifica pra não passar da tela.
                gotoxy(x, y--);
                printf(" ");
                gotoxy(x, y);
                printf("%c", 175);
            }
            break;
        case BAIXO:
        	if(y==14){ // Verifica para não passar da tela
	           	gotoxy(x,y++);
	           	printf(" ");
	           	gotoxy(x,y);
	            printf("%c", 175);
        	}
            break;
        }

    }while (tecla != ENTER);


	if(x == 48 && y == 14){
	   fflush(stdin);
	   telalogin1();
	}
	if(x == 48 && y ==15){
      fflush(stdin);
      menuadmin();
	}
}
//-----------------------------------------------------
void saida(){
	//Função pra saída do funcionário
	system("cls");
	int e;
	inter();
	pacpizza();
		
	caixacard(36,10,3,40);
    gotoxy(37,11);
	textcolor(LIGHTYELLOW);
	printf("  Deseja sair da area do funcionario?", 136);
	gotoxy(50,14);
	textcolor(LIGHTGREEN);

	printf("     - SIM\n");
	gotoxy(50,15);
	textcolor(LIGHTRED);
	printf("     - N%cO\n", 199);

	int x = 48, y = 14;
    char tecla;

   // Printa a seta pela primeira vez.
   gotoxy(x,y);
   printf("%c", 175);


   do{
        tecla = getch();

        switch (tecla) {
        case CIMA:
            if (y == 15) { // Verifica pra não passar da tela.
                gotoxy(x, y--);
                printf(" ");
                gotoxy(x, y);
                printf("%c", 175);
            }
            break;
        case BAIXO:
        	if(y==14){ // Verifica para não passar da tela
	           	gotoxy(x,y++);
	           	printf(" ");
	           	gotoxy(x,y);
	            printf("%c", 175);
        	}
            break;
        }

    }while (tecla != ENTER);


	if(x == 48 && y == 14){
	   fflush(stdin);
	   telalogin1();
	}
	if(x == 48 && y ==15){
      fflush(stdin);
      menuFuncionario();
	}
	
}



//FUNÇÃO QUE PESQUISA SE O CODIGO INSERIDO EXISTE 
void pesquisa_codigo(char campo[], char varc[], int tam, int x, int y){
	
	FILE *arq;
    int tamanho;
    int aux;
    int encontrou=FALSE;
    
    //ABRE O ARQUIVO EM LEITURA BINÁRIA
    arq=fopen("./arq.cadastro", "rb");
    
    
    //CRIA UMA OUTRA VARIAVEL PARA FAZER AS DEVIDAS VERIFICAÇÕES
    cadastro_login cad2;
	   
    do{    	
    
    	textcolor(GREENWATER);
    	encontrou = FALSE;
    	setbuf(stdin,NULL);
    	gotoxy(x + strlen(campo),y);
        gets(varc);
        setbuf(stdin,NULL);
        tamanho=strlen(varc);
        aux=verifica_letra(varc, tam);
        
    
        //CONDIÇÃO PARA CASO O ARQUIVO NÃO FOR ABERTO
        if(arq!=NULL){
    	rewind(arq);
    	
    	//LAÇO PARA FAZER A PESQUISA DO CODIGO
    	while(fread(&cad2, sizeof(cadastro_login),1, arq)){
    	if(strcmp(varc,cad2.codigo)==0){
    	encontrou=TRUE;
    	break;
			}
		}	
	}
        
    setbuf(stdin, NULL);
        
    //CONDIÇÃO CASO O USUARIO NÃO DIGITAR NADA
    if(varc[0]=='\0'){
        
	gotoxy(x + strlen(campo),y);
    printf("                      ");
    textcolor(LIGHTRED);
	gotoxy(x + strlen(campo),y);
    printf("CAMPO OBRIGATORIO");
	getchar();	
        	
	}
	
	setbuf(stdin, NULL);
	
	//CONDIÇÃO CASO A VARIAVEL LOGICA RECEBER TRUE (SIGNIFICA QUE ENCONTROU O CODIGO EXISTENTE)
	if(encontrou==TRUE){
	
	gotoxy(x + strlen(campo),y);
    printf("                    ");
	textcolor(LIGHTRED);
    gotoxy(x + strlen(campo),y);
    printf("CODIGO EXISTENTE");
	getchar();
	
	}
	
	//CONDIÇÃO CASO FOR DIGITADO LETRA E NÃO NÚMERO
	if(aux==1){
	
	gotoxy(x + strlen(campo),y);
    printf("                    ");
    textcolor(LIGHTRED);
    gotoxy(x + strlen(campo),y);
    printf("LETRAS SAO INVALIDAS");
	getchar();	
	
	}
    
    	
    //CONDIÇÃO CASO O TAMANHO DA STRING FOR ULTRAPASSADO
    if(tamanho>tam){
        	
	    gotoxy(x + strlen(campo),y);
	    printf("                      ");
	    textcolor(LIGHTRED);
	    gotoxy(x + strlen(campo),y);
	    printf("INVALIDA");
		getchar();
        	
	}
     
	 gotoxy(x + strlen(campo),y);
    printf("                      ");
	    
    }while(encontrou==TRUE || aux==1 || tamanho>tam || varc[0]=='\0');

	//FECHA O ARQUIVO
	fclose(arq);

	gotoxy(x + strlen(campo),y);
	puts(varc);	
	

}

//----------------------------------------------------------------
//Cadastro principal
void cadast(){
	inter();

	FILE *arq;

	//ABRE O ARQUIVO EM ADIÇÃO BINÁRIA
	arq = fopen("./arq.cadastro", "ab");


	//VERIFICAÇÃO DE ABERTURA 
	if(arq==NULL){
		printf("Erro");
		exit(1);
	}
	
	//COLETA OS DADOS DO USUÁRIO
	caixinha(38,5,72, " ");
	gotoxy(39,6);
	textcolor(GREENWATER);
	printf("   DADOS CADASTRAIS DA EMPRESA\n\n\n");

	fflush(stdin);
	caixinha(30,9,90, " ");
	gotoxy(31,10);
	textcolor(GREENWATER);
	printf(" Primeiro nome: ");
	verifica_campo(nome1, nome, 20, 31 ,10);
	fflush(stdin);
	strcpy(cad.nome,nome1);
	fflush(stdin);
	
	caixinha(30,13,90, " "  );
	gotoxy(31,14);
	textcolor(GREENWATER);
	printf(" Sobrenome:");
	verifica_campo(sobrenome1, sobrenome, 50, 31, 14);
	fflush(stdin);
	strcpy(cad.sobrenome,sobrenome1);
	fflush(stdin);
	
	fflush(stdin);
	caixinha(30,17,90, " ");
	gotoxy(31,18);
	textcolor(GREENWATER);
	printf(" Idade: ");
	scanf("%d", &cad.idade);
	fflush(stdin);
	
	fflush(stdin);
	caixinha(30,21,90, " ");
	gotoxy(31,22);
	textcolor(GREENWATER);
	printf(" Insira novo codigo de acesso: ");
	gotoxy(60,22);
	pesquisa_codigo(code, codigo, 5, 19, 22);
	fflush(stdin);
	strcpy(cad.codigo,codigo);
	fflush(stdin);
 	
	caixinha(30, 25, 90, " ");
	gotoxy(31, 26);
	textcolor(GREENWATER);
	printf(" Voce sera atendente ou gerente? (G ou A): ");
	scanf("%c", &cad.adm);
	fflush(stdin);


	//PASSO OS DADOS PARA O ARQUIVO
    fwrite(&cad, sizeof(cadastro_login), 1, arq); // Salva os dados no arquivo.
    fclose(arq); // Fecha o arquivo.
    fflush(stdin);

	
    if(cad.adm=='G'){
    	system("cls");
    	menuadmin();

	}else
	if(cad.adm=='A'){
		system("cls");
	    menuFuncionario();
	}

}

//Função menu do administrador
void menuadmin(){
	system("cls");
	inter();
	pacpizza();
	caixinha(22,11,90," ");
	gotoxy(23,12);
	textcolor(GREENWATER);
	
	//EXIBE AS OPÇÕES DISPONIVEIS
	printf("                    -VISUALIZAR CADASTROS \n\n");
	caixinha(22,15,90," ");
	gotoxy(23,16);
	textcolor(GREENWATER);
	printf("                    -ALTERAR DADOS CADASTRAIS \n\n");
	caixinha(22,19,90," ");
	gotoxy(23,20);
	textcolor(GREENWATER);
	printf("                      -EXCLUIR CADASTROS   \n\n");
	caixinha(22,23,90," ");
	gotoxy(23,24);
	textcolor(GREENWATER);
	printf("                            -SAIR  \n\n");
	
	
	//IMPRIME UMA PARTE DA ANIMAÇÃO (INTERFACE)
	gotoxy(34,33);
    printf("o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o");	
    gotoxy(22,35);
    textcolor(GREY);
    printf("_____________________________________________________________________");


	fantasminhamov();


	//Variaveis da seta
	int x = 20, y = 12;
    char tecla;

    // Printa a seta pela primeira vez.
    gotoxy(x,y);
    printf("%c", 175);


	//LAÇO PARA UTILIZAR O CURSOR (INTERFACE)
    do {
        tecla = getch();

        switch (tecla) {
        case CIMA:
            if (y >= 14) { // Verifica pra não passar da tela.
                gotoxy(x, y);
                printf(" ");
                gotoxy(x, y-=4);
                printf("%c", 175);
            }

            break;
        case BAIXO:
        	if(y<=23){
	           	gotoxy(x,y);
	           	printf(" ");
	           	gotoxy(x,y+=4);
	            printf("%c ", 175);
        	}
            break;
        }

        }while (tecla != ENTER);

	
	//CONDIÇÕES PARA A OPÇÃO DESEJADA SER SELECIONADA COM ENTER
         if(x== 20 && y==12){
         	getchar();
         	system("cls");
	consulta();
	menuadmin();
	}

	if(x== 20 && y==16){
		system("cls");
		altera_login();
		system("cls");
		menuadmin();
	}
	if(x== 20 && y==20){
		system("cls");
		excluir_conta();
		getchar();
		system("cls");
		menuadmin();
	}
	if(x==20 && y==24){
		system("cls");
		saidaAdm();
	}
}

//---------------------------------------------------------
void consulta(){
	//Função que faz a consulta dos funcionarios
	system("cls");
	inter();
	pacpizza();
	FILE*arq;

	arq=fopen("./arq.cadastro", "rb");

	if(arq==NULL){
		pacpizza();
		caixacard(36,10,3,400);
		gotoxy(42,11);
		textcolor(LIGHTRED);
		printf("Problemas na abertura do arquivo \n");
		exit(1);
		system("cls");
		menuadmin();
		
	}else{
		
        		int total = 0;
	    		int cont = 1;
	    
    	    	pacpizza();
 
	         gotoxy(41,28);
            textcolor(GREENWATER);
		   	printf("PRESSIONE ENTER PARA O PR%cXIMO PEDIDO\n", 224);
		   	//caixinha para ir ao pedido anterior
			 	caixacard(6,32,3,11);
            gotoxy(10,33);
            textcolor(GREENWATER);
            printf("<<");
            gotoxy(7,34);
            textcolor(GREENWATER);
            printf(" Anterior");
            //caixinha para sair da visualizção dos pedidos no momento que o usuário quiser
            caixacard(54,32,3,11);
            gotoxy(57,33);
            textcolor(GREENWATER);
            printf(" ESC ");
            gotoxy(57,34);
            textcolor(GREENWATER);
            printf(" SAIR");
            //caixinha para ir ao próximo pedido
            caixacard(94,32,3,11);
            gotoxy(98,33);
            textcolor(GREENWATER);
            printf(">>");
            gotoxy(95,34);
            textcolor(GREENWATER);
            printf(" Proximo");

   while(fread(&cad,sizeof(cadastro_login),1,arq))total++;
		rewind(arq);
	
	while(fread(&cad, sizeof(cadastro_login), 1, arq)){

		caixacard(39,10,10,39);
		gotoxy(45,11);
      textcolor(LIGHTRED);
		printf("   DADOS CADASTRAIS: ");
		gotoxy(45,13);
      textcolor(GREENWATER);
		printf("Nome: ");
		puts(cad.nome);
		gotoxy(45,14);
      textcolor(GREENWATER);
		printf("Sobrenome: ");
		puts(cad.sobrenome);
		gotoxy(45,15);
      textcolor(GREENWATER);
		printf("Idade: %d\n", cad.idade);
		gotoxy(45,16);
      textcolor(GREENWATER);
		printf("Codigo de acesso:");
		puts(cad.codigo);
		printf("\n\n");
		
		fflush(stdin);
	   caixinha(65, 24, 54, "");
      gotoxy(56, 25);
      printf("%.2d / %.2d", cont, total);
        
        int tecla;
            do {
                tecla = getch();

                if (tecla == ESC) {
                    fclose(arq);
                    menuadmin();
                    
                }else 
							if(tecla == ESQUERDA && cont > 1) {
                    		cont--; // Só pra contar a quantidade de pedidos.
                    			fseek(arq, -sizeof(cad) * 2, SEEK_CUR); // Isso aqui é o que faz voltar.
                    			
                } else 
							if (tecla == DIREITA && cont < total) {
                    		cont++; // Só pra contar a quantidade de pedidos.
                    		
                } else {
                    tecla = ENTER;
                    
                }

            }while(tecla == ENTER);

            gotoxy(35, 10);
            printf("                                                            ");
            gotoxy(35, 11);
            printf("                                                            ");
            gotoxy(35, 12);
            printf("                                                            ");
            gotoxy(35, 13);
            printf("                                                            ");
            gotoxy(35, 14);
            printf("                                                            ");
            gotoxy(35, 15);
            printf("                                                            ");

	}
}
	fclose(arq);
	menuadmin();
}
//------------------------------------------------------
void altera_login()
{
	//FUNÇÃO QUE ALTERA OS DADOS DO USUARIO

	inter();
	pacpizza();
	FILE *arq;                 //arquivo principal
	FILE *arqAUX; 			  //arquivo auxiliar
	int encontrado=FALSE; 	 //variavel para indicar se foi encontrado
	char code[5];       		//recebe o codigo de acesso do funcionario para fazer a comparação

	//Abertura do arquivo principal
	arq=fopen("./arq.cadastro", "rb");

	//Recebendo dados de login para comparar
	setbuf(stdin, NULL);
	caixinha(30, 16, 90, " " );
	gotoxy(31,17);
	textcolor(GREENWATER);
	printf(" Entre com o codigo de acesso da sua conta: ");
	gotoxy(74,17);
	gets(code);

	//Loop para ler todos os dados do arquivo e pesquisa
	while(fread(&cad, sizeof(cadastro_login), 1, arq)){
		if(strcmp(cad.codigo, code)==0){ //pesquise se esse codigo de acesso existe
			encontrado=TRUE;
			break; //para tudo parsa
		}
	}

	system("cls");
	setbuf(stdin, NULL);

	//Condição caso não seja encontrado
	if(!encontrado){
		inter();
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(42,11);
		textcolor(LIGHTRED);
		printf("Usu%crio n%co encontrado!\n",160,198);
		gotoxy(50,13);
		getchar();
		system("cls");
		fclose(arq);
		
		//Retorna para menu adm
		
		menuadmin();
	}

	system("cls");

	//Exibe as informações do administrador
		inter();
		pacpizza();
		caixacard(39,10,10,39);
		gotoxy(45,11);
        textcolor(LIGHTRED);
		printf("INFORMACOES DE CADASTRO\n\n\n\n");
		gotoxy(45,13);
        textcolor(GREENWATER);
		printf("Nome: %s\n", cad.nome);
		gotoxy(45,14);
        textcolor(GREENWATER);
		printf("Sobrenome: %s\n", cad.sobrenome);
		gotoxy(45,15);
        textcolor(GREENWATER);
		printf("Idade: %d\n", cad.idade);
		gotoxy(45,16);
        textcolor(GREENWATER);
		printf("Codigo de acesso: %s\n", cad.codigo);
		printf("\n\n\n");
		gotoxy(47,23);
		textcolor(GREENWATER);
	    printf("PRESSIONE ENTER PARA ALTERAR\n");
		gotoxy(59,24);
		

		getchar();
		system("cls");
		setbuf(stdin, NULL);

		//novo mundo
		inter();
		pacpizza();
		caixinha(30, 13, 90, " ");
		gotoxy(31,14);
		textcolor(GREENWATER);
		printf(" Primeiro nome: ");
		gotoxy(46, 14);
		fflush(stdin);
		gets(cad.nome);
	
		caixinha(30, 17, 90, " ");
		gotoxy(31,18);
		textcolor(GREENWATER);
		printf(" Sobrenome: ");
		gotoxy(42,18);
		fflush(stdin);
		gets(cad.sobrenome);
	
		caixinha(30, 21, 90, " ");
		gotoxy(31,22);
		textcolor(GREENWATER);
		printf(" Idade: ");
		gotoxy(38, 22);
		fflush(stdin);
		scanf("%d", &cad.idade);
		fflush(stdin);
		
		system("cls");
		inter();
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(44,11);
		textcolor(LIGHTGREEN);
		printf("  Altera%c%co concluida!\n", 135,198);
		getch();
		system("cls");
		
	
		rewind(arq);
	
		if(arq==NULL){
		inter();
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(42,11);
		textcolor(LIGHTRED);
		printf("Problemas na criac%%co do arquivo",135,198);
		exit(1);

	//Else para verificar se existe login um login igual a este
		}else{
		cadastro_login cadAUX;

		while(fread(&cadAUX, sizeof(cadastro_login), 1, arq)){
			if(strcmp(cad.codigo,code)==0 &&  strcmp(cad.codigo,code)!=0){

				system("cls");
				inter();
				pacpizza();
				caixacard(36,10,3,40);
				gotoxy(42,11);
				textcolor(LIGHTRED);
				printf("Erro, login existente");
				fclose(arq);
				getchar();
				menuadmin();
			}
		}
	}


	fclose(arq);

	arqAUX=fopen("./arq.auxiliar", "ab"); //abre arquivo auxiliar em adição
	arq=fopen("./arq.cadastro", "rb");   //abre arquivo principal em leitura

	//Verifica se arquivo foi aberto
	if(arqAUX ==NULL && arq==NULL){
		printf("Erro na abertura do arquivo\n");
		exit(1);

	}else{

		//Pega os dados alterados e passa para o arquivo auxiliar
		fwrite(&cad, sizeof(cadastro_login), 1, arqAUX);
		while(fread(&cad, sizeof(cadastro_login), 1, arq)){
			if(strcmp(cad.codigo,code)!=0){
			fwrite(&cad, sizeof(cadastro_login), 1, arqAUX);

			}
		}
	}


	//Fecha a porra toda
	fclose(arq);
	fclose(arqAUX);

	//Renomeia (truque final)

	remove("./arq.cadastro");
	rename("./arq.auxiliar", "./arq.cadastro");
	
	menuadmin();
}

//-----------------------------------------------------
void excluir_conta(){
	//FUNÇÃO QUE EXCLUI OS DADOS DO USUARIO
	inter(); 
	
	FILE *arq;
	FILE *arqAUX;
	char resp;
	int encontrou=FALSE;
	char code[5];
	
	arq=fopen("./arq.cadastro", "rb");
	
	fflush(stdin);
	pacpizza();
	caixacard(36,10,3,40);
	gotoxy(38,11);
	textcolor(LIGHTRED);
	printf("Entre com o seu codigo de acesso: ");
	gotoxy(72,11);
	gets(code);
	setbuf(stdin, NULL);
	
	while(fread(&cad, sizeof(cadastro_login),1 , arq)){
		if(strcmp(cad.codigo, code)==0){
			encontrou=TRUE;
			break;
		}
	}
	
	system("cls");
	setbuf(stdin, NULL);
	fclose(arq);

    inter();
	pacpizza();
	caixacard(39,10,10,39);
	gotoxy(45,11);
    textcolor(LIGHTRED);
    printf("INFORMACOES DE CADASTRO\n\n\n\n");
	gotoxy(45,13);
    textcolor(GREENWATER);
	printf("Nome: %s\n", cad.nome);
	gotoxy(45,14);
    textcolor(GREENWATER);
	printf("Sobrenome: %s\n", cad.sobrenome);
	gotoxy(45,15);
   textcolor(GREENWATER);
   printf("Idade: %d\n", cad.idade);
	gotoxy(45,16);
   textcolor(GREENWATER);
	printf("Codigo de acesso: ");
	puts(cad.codigo);
	printf("\n\n\n");
	gotoxy(44,23);
	textcolor(GREENWATER);
	printf("Deseja mesmo desativar esta conta \n");
	gotoxy(55,25);
	textcolor(LIGHTGREEN);
	printf("  -SIM");
	gotoxy(55,26);
	textcolor(LIGHTRED);
	printf("  -NAO\n");
	setbuf(stdin, NULL);
	
	int x = 53, y = 25;
    char tecla;

   // Printa a seta pela primeira vez.
   gotoxy(x,y);
   printf("%c", 175);


   do{
        tecla = getch();

        switch (tecla) {
        case CIMA:
            if (y == 26) { // Verifica pra não passar da tela.
                gotoxy(x, y--);
                printf(" ");
                gotoxy(x, y);
                printf("%c", 175);
            }
            break;
        case BAIXO:
        	if(y==25){ // Verifica para não passar da tela
	           	gotoxy(x,y++);
	           	printf(" ");
	           	gotoxy(x,y);
	            printf("%c", 175);
        	}
            break;
        }

    }while (tecla != ENTER);


	if(x == 53 && y == 25){
		
		arq=fopen("./arq.cadastro", "rb");
		arqAUX=fopen("./arq.auxiliar", "ab");
	
		
	   if(arq==NULL && arqAUX==NULL){
			
			printf("Problemas na criação do arquivo. ");
			setbuf(stdin, NULL);
			Sleep(1000);
			menuadmin();
			
		}else{
			
			while(fread(&cad, sizeof(cadastro_login), 1, arq)){
				if(strcmp(cad.codigo,code)!=0){
					fwrite(&cad, sizeof(cadastro_login), 1, arqAUX);
				}
			}
		}
		
		fclose(arq);
		fclose(arqAUX);
		
		remove("./arq.cadastro");
		rename("./arq.auxiliar", "./arq.cadastro");
		
		system("cls");
		menuadmin();
	}
	if(x == 53 && y ==26){
		inter();
		pacpizza();
		caixacard(36,10,3,40);
		gotoxy(38,11);
		textcolor(LIGHTRED);
		printf("Clique para voltar para menu principal");
		system("cls");
		setbuf(stdin, NULL);
		menuadmin();
	}
	
	arq=fopen("./arq.cadastro", "rb");
	arqAUX=fopen("./arq.auxiliar", "ab");

	}


//main
int main(){

	system("title PAC PIZZA");
	system("mode 110, 40");
	inter();
	titulo();
	system("cls");
	existeArq();
	system("cls");
	telalogin1();
	system("cls");


	return 0;
}


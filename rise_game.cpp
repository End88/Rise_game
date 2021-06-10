
/* JOGNA2 - Entrega N1.C - Grupo Número 1
Participantes: 
Ednei Sell dos Santos Junior 
Luciano de Carvalho Lima
Marcelo Kazuaki Shimada
Matheus Ferrandes de Mayo Gomes Beato
Thiago Oliveira Monte Alves de Araujo
*/


#include<stdio.h>
#include<graphics.h>
#include<time.h>

#define ESC 27

int Larg, Alt; // Variáveis de largura e altura da tela

void barra(int Ponto_X1, int Ponto_Y1, int Ponto_X2, int Ponto_Y2, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	setfillstyle(1,RGB(cor[0],cor[1],cor[2]));
	bar(Ponto_X1,Ponto_Y1,Ponto_X2,Ponto_Y2);
}

void linha(int Ponto_X1, int Ponto_Y1, int Ponto_X2, int Ponto_Y2, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	line(Ponto_X1,Ponto_Y1,Ponto_X2,Ponto_Y2);
}

void elipse(int Ponto_X, int Ponto_Y, int Tamanho_X, int Tamanho_Y, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	setfillstyle(1,RGB(cor[0],cor[1],cor[2]));
	fillellipse(Ponto_X,Ponto_Y,Tamanho_X,Tamanho_Y);
}

void fundo(int inicio, int Larg, int Alt, int i, int X){
	
	int vermelho[3] = {255,0,0};
	int verde[3] = {0,255,0};
	int azulClaro[3] = {173,216,230};
	int azulCeu[3] = {135,206,235};
	int azulCeuClaro[3] = {135,206,250};
	int azulMeiaNoite[3] = {25,25,112};
	int azulMarinho[3] = {18,10,143};
	int azulMedio[3] = {0,0,205};
	int cianoClaro[3] = {224,255,255};
	int escarlate[3] = {255,36,0};
	int lima[3] = {255,215,0};	
	int marrom[3] = {147,92,41};
	int madeira[3] = {222,184,135};
	//_______________________________________________________________ Ceu 	
	for (i = 0; i < (Alt/2); i++){
	if (i%2 == 0) linha (0,i,Larg,i,azulMeiaNoite);
	else linha (0,i,Larg,i,azulMarinho);
	}
	
	elipse(inicio+(Larg/10*6),Alt/10*2,30,30,cianoClaro); // lua
 
	
	
	}

void GravaArq(char *NomeArq, unsigned char *V, int Tam) {
  FILE *Arq;
  int i;
  Arq = fopen(NomeArq, "w");
  for(i = 0; i < Tam; i++)
    if (V[i] != 10)
      fprintf(Arq, "(%4d) %d = '%c'\n", i, V[i], V[i]);
    else
      fprintf(Arq, "(%4d) %d = ''\n", i, V[i]);
  fclose(Arq);
}

void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk) {
// Tam é o tamanho dos ponteiros da imagem e da máscara
// Img é o ponteiro que aponta para o vetor que contém a imagem capturada com getimage(..)
// Msk é o ponteiro que será transformado em máscara
  int i;
  unsigned char B, G, R;
  B = Img[24];
  G = Img[25];
  R = Img[26];
  for(i=24; i < Tam; i+=4) {
    if (Img[i]==B and Img[i+1]==G and Img[i+2]==R) {
      Img[i] = 0;
      Img[i+1] = 0;
      Img[i+2] = 0;
      Msk[i] = 255;
      Msk[i+1] = 255;
      Msk[i+2] = 255;
    }
    else {
      Msk[i] = 0;
      Msk[i+1] = 0;
      Msk[i+2] = 0;
    }
  }
}

void FlipImg(int LargImg, int AltImag, unsigned char *Img) {
// LargImag é a largura total da iamgem, uma imagem 200x100 equivale a 200
// AltImag é a altura total da iamgem, uma imagem 200x100 equivale a 100
// Img é o ponteiro que aponta para o vetor que contém a imagem capturada com getimage(..)
	int i,n;
	unsigned char aux1,aux2,aux3;

	for (n = 1; n < AltImag; n++){
		for(i=1; i < (LargImg*4)/2; i+=4) {
		
			aux1 = Img[((i-1)+(LargImg*4*n-(LargImg*4)))+24];
			aux2 = Img[((i-1)+(LargImg*4*n-(LargImg*4)))+1+24];
			aux3 = Img[((i-1)+(LargImg*4*n-(LargImg*4)))+2+24];
			
			Img[((i-1)+(LargImg*4*n-(LargImg*4)))+24] = Img[((LargImg*4*n)-(i-1)+23-3)];
			Img[((i-1)+(LargImg*4*n-(LargImg*4)))+1+24] = Img[((LargImg*4*n)-(i-1)+1+23-3)];   
			Img[((i-1)+(LargImg*4*n-(LargImg*4)))+2+24] = Img[((LargImg*4*n)-(i-1)+2+23-3)];
			
			Img[((LargImg*4*n)-(i-1)+23-3)] = aux1;
			Img[((LargImg*4*n)-(i-1)+1+23-3)] = aux2;
			Img[((LargImg*4*n)-(i-1)+2+23-3)] = aux3;
		}
	}
}
	
struct TQUADRADO{
     double x;       
	 double y;       
	 double largura;       
	 double altura; 
};

TQUADRADO *colisao_chao;

void defineFundo(int Num_Quad,int x, int y, int largura, int altura){
	colisao_chao[Num_Quad].x = colisao_chao[Num_Quad].x + x;
	colisao_chao[Num_Quad].y = colisao_chao[Num_Quad].y - y;
	colisao_chao[Num_Quad].largura = colisao_chao[Num_Quad].largura+largura;
	colisao_chao[Num_Quad].altura = colisao_chao[Num_Quad].altura - altura;
}

#define QtdePsg  90
#define SpritePr  137 // Sprite parado
#define SpritePl  48 // Sprite Pulo
void fase1jogo(){
	char tecla = 0;
	//_____________________________________ Definições de images
	int tam,ande = 0;
	unsigned char *R[QtdePsg], *M[QtdePsg], *FlipR[QtdePsg], *FlipM[QtdePsg]; // Imagens de movimento
	unsigned char *St[SpritePr], *MSt[SpritePr], *FlipSt[SpritePr],*FlipMSt[SpritePr]; // Imagens parado
	unsigned char *Jp[SpritePl], *MJp[SpritePl], *FlipJp[SpritePl],*FlipMJp[SpritePl]; // Imagens pulando
	
	TQUADRADO *inimigos, psg, draw;
	int Qtde_chao, Qtde_inimigos;
	int passo_inimigos = 5, andando = 0;
	bool morte = false;
	
	int direcao = 1;
	int tempo = 1;
	double velocidade_pos = 1.0, velocidade_neg = 1.0, velocidade, Velocidade_Max = 1.5;
	double multiplicador;	
	
	int altura_psg, largura_psg;
	double altitude = 0.0;
	
	int i,X,cont; // Variáveis i, X e cont armezenam informações dinámicas.
	int imgcont;
	double refP;
	double inicio = 0; // Váriável Início define o início da tela
	int pg = 1; // Váriavel de pagina 
	double Passo_X,Passo_Y; // Variável do raio e passo das esferas móveis
	int stoped = 0, pulando = 0;
	bool chao = true,Pulo = false, animation = false;
	bool moved = false;
	bool inercia_Right = false, inercia_Left = false;
	
	unsigned long long gt1, gt2;
	
	int vermelho[3] = {255,0,0};
	int amarelo[3] = {255,255,0};
	int laranja[3] = {255,69,0};
	int jade[3] = {0,168,107};
	int orquidea[3] = {186,85,211};
	int cinzaArdosia[3] = {119,136,153};
	int escarlate[3] = {255,36,0};
	
	printf("Participantes: \n\n");
	printf("  Ednei Sell dos Santos Junior  \n");
	printf("  Luciano de Carvalho Lima  \n");
	printf("  Marcelo Kazuaki Shimada  \n");
	printf("  Matheus Ferrandes de Mayo Gomes Beato  \n");
	printf("  Thiago Oliveira Monte Alves de Araujo  \n\n");
	
	setbkcolor(RGB(0,0,0));
	cleardevice();
//_______________________________________________________________ Tratamento de imagens de movimento
	//Imagem de tamanho 128 por 128
	tam = imagesize(0,0,127, 127);
	for(i = 0; i < QtdePsg; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		R[i] = (unsigned char *)malloc(tam);
		M[i] = (unsigned char *)malloc(tam);
		FlipR[i] = (unsigned char *)malloc(tam);
		FlipM[i] = (unsigned char *)malloc(tam);
	} 	


	if(true){
	imgcont = 0;
		readimagefile(".\\images\\correndo\\Run00.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run01.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run02.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run03.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run04.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run05.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run06.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run07.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run08.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run09.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run10.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run11.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run12.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run13.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run14.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run15.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run16.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run17.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run18.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run19.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run20.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run21.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run22.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run23.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run24.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run25.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run26.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run27.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run28.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run29.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run30.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run31.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run32.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run33.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run34.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run35.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run36.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run37.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run38.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run39.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run40.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run41.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run42.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run43.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run44.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run45.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run46.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run47.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run48.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run49.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run50.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run51.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run52.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run53.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run54.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run55.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run56.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run57.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run58.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run59.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run60.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run61.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run62.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run63.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run64.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run65.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run66.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run67.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run68.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run69.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run70.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run71.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run72.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run73.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run74.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run75.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run76.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run77.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run78.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run79.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run80.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\correndo\\Run81.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run82.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run83.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run84.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run85.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run86.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run87.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run88.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\correndo\\Run89.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, R[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, M[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro R
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
}

	for(i = 0; i < QtdePsg; i++){
		PreparaImg(tam, R[i], M[i]); // configura as cores branca e preta em cada pixel para formar o recorte
		PreparaImg(tam, FlipR[i], FlipM[i]);} // configura as cores branca e preta em cada pixel para formar o recorte
	
	
	for (i = 0; i < QtdePsg; i++){
		FlipImg(128,128,FlipR[i]);
		FlipImg(128,128,FlipM[i]);
	}
	
	//_______________________________________________________________ Tratamento de imagens de psg parado
	//Imagem de tamanho 128 por 128

	for(i = 0; i < SpritePr; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		St[i] = (unsigned char *)malloc(tam);
		MSt[i] = (unsigned char *)malloc(tam);
		FlipSt[i] = (unsigned char *)malloc(tam);
		FlipMSt[i] = (unsigned char *)malloc(tam);
	} 


	if(true){
	imgcont = 0;
		
		readimagefile(".\\images\\parado\\Idle000.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle001.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle002.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle003.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle004.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle005.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle006.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle007.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle008.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle009.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle010.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipR[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle011.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle012.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle013.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle014.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle015.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle016.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle017.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle018.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle019.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle020.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle021.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle022.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle023.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle024.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle025.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle026.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle027.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle028.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle029.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle030.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle031.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle032.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle033.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle034.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle035.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle036.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle037.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle038.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle039.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle040.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle041.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle042.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle043.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle044.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle045.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle046.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle047.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle048.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle049.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle050.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle051.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle052.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle053.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle054.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle055.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle056.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle057.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle058.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle059.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipM[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle060.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle061.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle062.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle063.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle064.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle065.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle066.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle067.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle068.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle069.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle070.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle071.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle072.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle073.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle074.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle075.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle076.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle077.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle078.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle079.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle080.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle081.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle082.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle083.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle084.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle085.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle086.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle087.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle088.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle089.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle090.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle091.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle092.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle093.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle094.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle095.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle096.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle097.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle098.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle099.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle100.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;	
		readimagefile(".\\images\\parado\\Idle101.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle102.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle103.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle104.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle105.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle106.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle107.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle108.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle109.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle110.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle111.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle112.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle113.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle114.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle115.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle116.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle117.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle118.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle119.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle120.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle121.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle122.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle123.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle124.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle125.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle126.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle127.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle128.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle129.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle130.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle131.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle132.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle133.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle134.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle135.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\parado\\Idle136.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, St[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipSt[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMSt[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		
	}

	for(i = 0; i < SpritePr; i++){
		PreparaImg(tam, St[i], MSt[i]); // configura as cores branca e preta em cada pixel para formar o recorte
		PreparaImg(tam, FlipSt[i], FlipMSt[i]);} // configura as cores branca e preta em cada pixel para formar o recorte
	
	
	for (i = 0; i < SpritePr; i++){
		FlipImg(128,128,FlipSt[i]);
		FlipImg(128,128,FlipMSt[i]);
	}
	//_______________________________________________________________ Tratamento de imagens de psg parado
	//Imagem de tamanho 128 por 128

	for(i = 0; i < SpritePl; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		Jp[i] = (unsigned char *)malloc(tam);
		MJp[i] = (unsigned char *)malloc(tam);
		FlipJp[i] = (unsigned char *)malloc(tam);
		FlipMJp[i] = (unsigned char *)malloc(tam);
	} 


	if(true){
	imgcont = 0;
	
	
		readimagefile(".\\images\\pulando\\Jump00.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump01.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump02.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump03.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump04.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump05.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump06.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump07.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump08.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump09.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump10.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump11.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump12.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump13.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump14.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump15.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump16.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump17.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump18.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump19.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump20.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump21.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump22.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump23.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump24.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump25.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump26.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump27.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump28.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump29.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump30.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump31.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump32.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump33.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump34.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump35.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump36.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump37.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump38.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump39.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump40.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump41.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump42.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump43.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump44.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump45.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump46.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	imgcont++;
		readimagefile(".\\images\\pulando\\Jump47.bmp", 0, 0, 127, 127);
	getimage(0, 0, 127, 127, Jp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, MJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
	getimage(0, 0, 127, 127, FlipJp[imgcont]); // captura para o ponteiro St
	getimage(0, 0, 127, 127, FlipMJp[imgcont]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)

	}

	for(i = 0; i < SpritePl; i++){
		PreparaImg(tam, Jp[i], MJp[i]); // configura as cores branca e preta em cada pixel para formar o recorte
		PreparaImg(tam, FlipJp[i], FlipMJp[i]);} // configura as cores branca e preta em cada pixel para formar o recorte
	
	
	for (i = 0; i < SpritePl; i++){
		FlipImg(128,128,FlipJp[i]);
		FlipImg(128,128,FlipMJp[i]);
	}
//_______________________________________________________________ 
	
	altura_psg = 128;
	largura_psg = 128;
		
	draw.x = Larg/2-(largura_psg/2);
	draw.y = Alt-altura_psg-50; 
	draw.largura = psg.x + largura_psg;
	draw.altura = psg.y + altura_psg;
	
	altura_psg = 89;
	largura_psg = 70;
		
	psg.x = Larg/2-(largura_psg/2);
	psg.y = Alt-altura_psg-50; 
	psg.largura = psg.x + largura_psg;
	psg.altura = psg.y + altura_psg;
	
	Passo_X = 4;
	Passo_Y = 0.75;
	
	Qtde_chao = 9;
	colisao_chao = (TQUADRADO*)malloc(sizeof(TQUADRADO)*Qtde_chao);
	
	Qtde_inimigos = 1;
	inimigos = (TQUADRADO*)malloc(sizeof(TQUADRADO)*Qtde_inimigos);
	
	int FPS = 60;
	gt1 = GetTickCount();
	gt2 = gt1 * 2;
	
//___________________________________________________ Início do laço de movimento
	while (tecla != ESC){
		
		if (gt2 - gt1 > 1000/FPS){
			gt1 = gt2;
			
			// ______________________________________ Desenho do chão			
			for (i = 0; i < Qtde_chao; i++){
				colisao_chao[i].x = inicio+Larg;
				colisao_chao[i].y = Alt-altitude;	
				colisao_chao[i].largura = inicio+Larg;
				colisao_chao[i].altura = Alt-altitude;
			}
			
			defineFundo(0,-Larg,50,0,0);
			defineFundo(1,100,80,400,40);
			defineFundo(2,500,110,700,100);
			defineFundo(3,750,150,800,145);
			defineFundo(4,650,235,695,230);
			defineFundo(5,800,290,900,285);
			defineFundo(6,1000,340,1500,335);
			
			//_________________________________________ Desenho dos inimigos
			inimigos[0].x = inicio+Larg+1200+andando;
			inimigos[0].y = Alt-360-altitude;
			inimigos[0].largura = inicio+Larg+1220+andando;
			inimigos[0].altura = Alt-340-altitude;
			
			if (pg == 1) pg = 2; else pg = 1;
			setactivepage(pg);
			
			setbkcolor(RGB(0,0,205));
			cleardevice();	
			fundo(inicio,Larg,Alt,i,X);
			
			barra(psg.x, psg.y, psg.largura, psg.altura, vermelho);   // verificador de colisão do personagem
			
			switch(direcao){
				case 1: // personagem andando para a direita		
					putimage(psg.x-29, psg.y-29, M[ande], AND_PUT);
    				putimage(psg.x-29, psg.y-29, R[ande], OR_PUT);					
					break;
				
				case 2: // personagem andando para a esquerda
					putimage(psg.x-29, psg.y-29, FlipM[ande], AND_PUT);
    				putimage(psg.x-29, psg.y-29, FlipR[ande], OR_PUT);					
					break;
				case 3: // personagem parado para a direita
					putimage(psg.x-29, psg.y-29, MSt[stoped], AND_PUT);
    				putimage(psg.x-29, psg.y-29, St[stoped], OR_PUT);					
					break;
				case 4: // personagem parado para a esquerda
					putimage(psg.x-29, psg.y-29, FlipMSt[stoped], AND_PUT);
    				putimage(psg.x-29, psg.y-29, FlipSt[stoped], OR_PUT);					
					break;
				case 5: // personagem pulando para a direita
					putimage(psg.x-29, psg.y-29, MJp[pulando], AND_PUT);
    				putimage(psg.x-29, psg.y-29, Jp[pulando], OR_PUT);					
					break;
				case 6: // personagem pulando para a esquerda
					putimage(psg.x-29, psg.y-29, FlipMJp[pulando], AND_PUT);
    				putimage(psg.x-29, psg.y-29, FlipJp[pulando], OR_PUT);					
					break;
				
			}
			
			for (i = 0; i < Qtde_chao; i++){
				if ((colisao_chao[i].y <= Alt && colisao_chao[i].altura >= 0 && colisao_chao[i].x <= Larg && colisao_chao[i].largura >= 0)) // Controle de Render
				barra(colisao_chao[i].x,colisao_chao[i].y,colisao_chao[i].largura,colisao_chao[i].altura,jade);
			}	
			
			for (i = 0; i < Qtde_inimigos; i++){
				if ((inimigos[i].y <= Alt && inimigos[i].altura >= 0 && inimigos[i].x <= Larg && inimigos[i].largura >= 0)) // Controle de Render
				barra(inimigos[i].x, inimigos[i].y, inimigos[i].largura, inimigos[i].altura,escarlate);
			}
			
			linha(0,Alt-25,Larg,Alt-25,escarlate);	
			
			setvisualpage(pg);
			
	//___________________________________________________________________________________ Movimento de inimigos -> Inimigo 1
			andando = andando + passo_inimigos;
			if (inimigos[0].x < colisao_chao[7].x){
				andando = colisao_chao[7].x - (inimigos[0].x - andando) - passo_inimigos; 
				passo_inimigos = -passo_inimigos;
			} 
			if (inimigos[0].largura > colisao_chao[7].largura){
				andando = colisao_chao[7].largura - (inimigos[0].largura - andando) - passo_inimigos; 
				passo_inimigos = -passo_inimigos;	
			} 
	//___________________________________________________________________________________	Colisão com inimigos
	
			for (i = 0; i < Qtde_inimigos; i++){
				if (psg.x <= inimigos[i].largura && psg.largura >= inimigos[i].x){
					if(psg.y <= inimigos[i].altura && psg.altura >= inimigos[i].y) morte = true;
				}
			}
			
			
			
	//_________________________________________________________ Andar para esquerda e direita da tela		
			
			if (GetKeyState(VK_LEFT)&0x80 && !(GetKeyState(VK_RIGHT)&0x80)) {
				if (velocidade_pos < 1) velocidade_pos = 1;				
				inicio = inicio + (5*velocidade_pos);
				
				for (i = 0; i < Qtde_chao; i++){
					if (psg.x <= colisao_chao[i].largura + (5*velocidade_pos) && psg.largura >= colisao_chao[i].x + (5*velocidade_pos)){
						if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio - (5*velocidade_pos); break;}	
					}
				}
				
				moved = true;					
				if (pulando == 0) direcao = 2;
				if (ande != QtdePsg-1) ande += 2;
				if (ande > QtdePsg-1) ande = QtdePsg-1;
				else if (ande == QtdePsg-1) ande = 0;
					
			}else if (velocidade_pos > 0){
				if (Pulo == false && animation == false){
					inicio = inicio + (5*velocidade_pos);
					
					moved = false;
					if (ande != QtdePsg-1) ande += 2;
					if (ande > QtdePsg-1) ande = QtdePsg-1;
					else if (ande == QtdePsg-1) ande = 0;
					
					for (i = 0; i < Qtde_chao; i++){
						if (psg.x <= colisao_chao[i].largura + (5*velocidade_pos) && psg.largura >= colisao_chao[i].x + (5*velocidade_pos)){
							if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio - (5*velocidade_pos); break;}	
						}
					}				
				}
				velocidade_pos -= 0.5;
			}
			
			if (GetKeyState(VK_RIGHT)&0x80 && !(GetKeyState(VK_LEFT)&0x80)) {
				if (velocidade_neg < 1) velocidade_neg = 1;
				inicio = inicio - (5*velocidade_neg);		
				
				
				for (i = 0; i < Qtde_chao; i++){
					if (psg.x <= colisao_chao[i].largura - (5*velocidade_neg) && psg.largura >= colisao_chao[i].x - (5*velocidade_neg)){
						if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio + (5*velocidade_neg); break;}	
					}
				}
				
				moved = true;				
				if (pulando == 0) direcao = 1;
				if (ande != QtdePsg-1) ande += 2;
				if (ande > QtdePsg-1) ande = QtdePsg-1;
				else if (ande == QtdePsg-1) ande = 0;
	
			}else if(velocidade_neg > 0) {
				if (Pulo == false && animation == false){
					inicio = inicio - (5*velocidade_neg);	
					
					moved = false;
					if (ande != QtdePsg-1) ande += 2;
					if (ande > QtdePsg-1) ande = QtdePsg-1;
					else if (ande == QtdePsg-1) ande = 0;
						
					for (i = 0; i < Qtde_chao; i++){
						if (psg.x <= colisao_chao[i].largura - (5*velocidade_neg) && psg.largura >= colisao_chao[i].x - (5*velocidade_neg)){
							if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio + (5*velocidade_neg); break;}	
						}
					}
				}
				velocidade_neg -= 0.5;
			}
			
			if (moved == false){
				if(direcao == 1) direcao = 3;
				else if(direcao == 2) direcao = 4;
				
				stoped++;
				if (stoped > SpritePr-1) stoped = 0;
			}
						
			if (velocidade_pos == 1) velocidade = velocidade_neg;
			else velocidade = velocidade_pos;
	//________________________________________________________________________
			if (GetKeyState(VK_UP)&0x80){
				if (Pulo == false && tempo == 1 && chao == true && animation == false) Pulo = true;
			}
			
			if (Pulo == true){
				
				if(direcao == 1 || direcao == 3) direcao = 5;
				else if(direcao == 2 || direcao == 4) direcao = 6;
				animation = true;
				
				if (pulando < 17)pulando += 2;
				if (pulando > 17 && ((Passo_Y*(tempo*multiplicador)) < -(Passo_Y-15-(velocidade)))) pulando = 18;
				if (pulando > SpritePl-1) pulando = 0;
				if (pulando >11){
					
					
					psg.y = psg.y - Passo_Y-15-(velocidade);
					psg.altura = psg.altura - Passo_Y-15-(velocidade);
									
					for (i = 0; i < Qtde_chao; i++){
						if (psg.x <= colisao_chao[i].largura && psg.largura >= colisao_chao[i].x){
							if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y){
							psg.y = colisao_chao[i].altura;
							psg.altura = psg.y + altura_psg; 
							tempo = 0;
							Pulo = false;
							break;	
							} 	
						}
					}
					
					tempo++;
				}		
			}
			
			
			if (chao == false){
				if (tempo == 1) multiplicador = 5.0;
				else multiplicador = 1.5;
				psg.y = psg.y + (Passo_Y*(tempo*multiplicador)); // constantemente puxa para baixo, com valor menor crescente, até superar o valor do pulo
				psg.altura = psg.altura + (Passo_Y*(tempo*multiplicador));
				
				if(direcao == 1 || direcao == 3) direcao = 5;
				else if(direcao == 2 || direcao == 4) direcao = 6;
				
				if (Pulo == false){
					pulando = 19;
				}
				
				if ((Passo_Y*(tempo*multiplicador)) > -(Passo_Y-15-(velocidade))){
					if (pulando < 19) pulando = 19;
					else if (pulando < 44){
						 pulando += 0.125;	
					}	
				}
			}else if (pulando > 18 && (direcao == 5 || direcao == 6)){
				pulando += 2;
				animation = true;
			}
			if (pulando == SpritePl-1) {pulando = 0; animation = false;}
			printf("%d\n\n",animation);
						
			for (i = 0; i < Qtde_chao; i++){
				if (psg.x <= colisao_chao[i].largura && psg.largura >= colisao_chao[i].x){
					if(psg.y <= colisao_chao[i].altura && psg.altura >= colisao_chao[i].y) {chao = true; break;}
					else chao = false;
				}else chao = false;
			}
			
			if (chao == true && psg.x <= colisao_chao[i].largura && psg.largura >= colisao_chao[i].x){
				if(psg.altura - (Passo_Y*(tempo*multiplicador)) <= colisao_chao[i].y){
					psg.altura = colisao_chao[i].y; 
					psg.y = psg.altura-altura_psg;  
				} 
			} 				
					
			if (tempo >= 5 && chao == true){
			Pulo = false;
			tempo = 1;	
			inercia_Right = false;
			inercia_Left = false;
			} 
			
//			if (inicio < -150) {
//				if (psg.y <= Alt/2) altitude -= 2.0;
//				else if (psg.y <= Alt-Alt/4) altitude -= 1.0;
//				else altitude -= 0.5;
//			}
			
			if (psg.altura >= Alt-25) break; //End game por queda
			
			if (morte == true) break; //End game por encostar em inimigos
			
			gt2 = GetTickCount();
			
			fflush(stdin);
			if (kbhit())
				tecla = getch();
	
				
		}
			
	} 
	free(colisao_chao);
	free(inimigos);
	free(*R);
	free(*M);
}

# define efeito 11
void TelaInicial(){
	char tecla = 0;
	unsigned long long gt1, gt2;
	int FPS;
	int pg = 1; // Váriavel de pagina 
	int tam,tamBg,tamE, i, cont = 4;
	int C_on = 0, S_on = 0;
	unsigned char *R[2], *M[2], *S[2], *MS[2], *Bg[2], *E[efeito];
		
	tamE = imagesize(0,0,719, 479);
	for(i = 0; i < efeito; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		E[i] = (unsigned char *)malloc(tamE);
	}
	
	tam = imagesize(0,0,268, 83);
	for(i = 0; i < 2; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		R[i] = (unsigned char *)malloc(tam);
		M[i] = (unsigned char *)malloc(tam);
		S[i] = (unsigned char *)malloc(tam);
		MS[i] = (unsigned char *)malloc(tam);
	}
	
	tamBg = imagesize(0,0,719, 479);
	for(i = 0; i < 2; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		Bg[i] = (unsigned char *)malloc(tamBg);
	}

	readimagefile(".\\images\\efeitos\\Efeito.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[0]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito1.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[1]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito2.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[2]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito3.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[3]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito4.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[4]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito5.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[5]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito6.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[6]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito7.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[7]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito8.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[8]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito9.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[9]); // captura para o ponteiro R
	readimagefile(".\\images\\efeitos\\Efeito10.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, E[10]); // captura para o ponteiro R
//	readimagefile(".\\images\\efeitos\\Efeito11.bmp", 0, 0, 719, 479);
//	getimage(0, 0, 719, 479, E[11]); // captura para o ponteiro R
		
	readimagefile(".\\images\\bg_4.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, Bg[0]); // captura para o ponteiro R

	readimagefile(".\\images\\bg_3.bmp", 0, 0, 719, 479);
	getimage(0, 0, 719, 479, Bg[1]); // captura para o ponteiro R		
		
	readimagefile(".\\images\\comecar_on_2.bmp", 0, 0, 268, 83);
	getimage(0, 0, 268, 83, R[1]); // captura para o ponteiro R
	getimage(0, 0, 268, 83, M[1]); // captura para o ponteiro M
	
	readimagefile(".\\images\\sair_on_2.bmp", 0, 0, 268, 83);
	getimage(0, 0, 268, 83, S[1]); // captura para o ponteiro R
	getimage(0, 0, 268, 83, MS[1]); // captura para o ponteiro M
	
	readimagefile(".\\images\\comecar_off.bmp", 0, 0, 268, 83);
	getimage(0, 0, 268, 83, R[0]); // captura para o ponteiro R
	getimage(0, 0, 268, 83, M[0]); // captura para o ponteiro M
	
	readimagefile(".\\images\\sair_off.bmp", 0, 0, 268, 83);
	getimage(0, 0, 268, 83, S[0]); // captura para o ponteiro R
	getimage(0, 0, 268, 83, MS[0]); // captura para o ponteiro M
	
	for(i = 0; i < 2; i++){
	PreparaImg(tam, R[i], M[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	PreparaImg(tam, S[i], MS[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	
	FPS = 60;
	gt1 = GetTickCount();
	gt2 = gt1 * 2;
	
	while (tecla != ESC){
		
		if (gt2 - gt1 > 1000/FPS){
			gt1 = gt2;
			
			if (pg == 1) pg = 2; else pg = 1;
			setactivepage(pg);
			//________________
			setbkcolor(RGB(150,150,150));
			cleardevice();
			
			fundo(0,Larg,Alt,i,0);
			
			putimage(  0, 0, Bg[C_on], COPY_PUT);
			putimage(  0, 0, E[cont], AND_PUT);
			 
			putimage(720/1.5-268/2, 480/2, M[C_on], AND_PUT);
			putimage(720/1.5-268/2, 480/2, R[C_on], OR_PUT);
			
			putimage(720/1.5-268/2, 480/2+84, MS[S_on], AND_PUT);
			putimage(720/1.5-268/2, 480/2+84, S[S_on], OR_PUT);											
			
			//________________
			setvisualpage(pg);
			
			if (GetKeyState(VK_UP)&0x80){
				C_on = 1;
				S_on = 0;
//				cont = efeito; // reinicia contador de efeito de 
			}
			if (GetKeyState(VK_DOWN)&0x80){
				C_on = 0;
				S_on = 1;
				cont = efeito;
			}
			if (cont > 0){
				cont = cont - 0.25;
			}
			if (GetKeyState(VK_RETURN)&0x80){
				if (C_on == true) fase1jogo();
				if (S_on == true) break;
			}
			
			gt2 = GetTickCount();
			
			fflush(stdin);
			if (kbhit()) tecla = getch();
		}
	}
	free(*R);
	free(*M);
	free(*S);
	free(*MS);
}

int main(void){		

	Larg = 720;
	Alt = 480;
	initwindow(Larg, Alt,"Rise");
	
	TelaInicial();
	//fase1jogo();
	
	closegraph();
  	return(0);
}


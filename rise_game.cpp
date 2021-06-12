
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
#include <windows.h>

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
#define QtdeBg 67


void fase1jogo(){
	char tecla = 0;
	//_____________________________________ Definições de images
	int tam,ande = 0;
	unsigned char *R[QtdePsg], *M[QtdePsg], *FlipR[QtdePsg], *FlipM[QtdePsg]; // Imagens de movimento
	unsigned char *St[SpritePr], *MSt[SpritePr], *FlipSt[SpritePr],*FlipMSt[SpritePr]; // Imagens parado
	unsigned char *Jp[SpritePl], *MJp[SpritePl], *FlipJp[SpritePl],*FlipMJp[SpritePl]; // Imagens pulando
	
	unsigned char *Bg[QtdeBg];
	
	TQUADRADO *inimigos, psg, draw;
	int Qtde_chao, Qtde_inimigos;
	int passo_inimigos = 5, andando = 0;
	bool morte = false;
	
	int direcao = 1;
	int tempo = 1;
	double velocidade_pos = 1.0, velocidade_neg = 1.0, velocidade, Velocidade_Max = 3.0;
	double multiplicador;	
	
	int altura_psg, largura_psg;
	double Altdesenho = 29;
	double altitude = 0.0;
	
	int i,X,cont; // Variáveis i, X e cont armezenam informações dinámicas.
	int imgcont, volumcont = 0, passomusica = 1;
	bool switchmusic = false;
	double inicio = 0; // Váriável Início define o início da tela
	int colum, pilar;
	int pg = 1; // Váriavel de pagina 
	double Passo_X,Passo_Y; // Variável do raio e passo das esferas móveis
	int stoped = 0, pulando = 0;
	bool chao = true,Pulo = false, animation = false;
	bool moved = false;
	bool inercia_Right = false, inercia_Left = false;
	double z;
	
	unsigned long long gt1, gt2;
	
	int vermelho[3] = {255,0,0};
	int amarelo[3] = {255,255,0};
	int laranja[3] = {255,69,0};
	int jade[3] = {0,168,107};
	int orquidea[3] = {186,85,211};
	int cinzaArdosia[3] = {119,136,153};
	int escarlate[3] = {255,36,0};
	int volumes[16] = {0xFFFFFFFF,0xEEEEEEEE,0xDDDDDDDD,0xCCCCCCCC,0xBBBBBBBB,0xAAAAAAAA,0x99999999,0x88888888,0x77777777,0x66666666,0x55555555,0x44444444,
				   0x33333333,0x22222222,0x11111111,0x00000000};
	
	int total = -1;
	char load[5];
	total++;
	setactivepage(1);
	setfillstyle(1, RGB(0, 0, 0));
	bar(0,0,Larg,Alt);
	setbkcolor(RGB(0, 0, 0));	
	rectangle(100, Alt-50, Larg-100, Alt-40);
	rectangle(100, Alt-30, Larg-100, Alt-20);
	setfillstyle(1, RGB(190, 190, 255));
	bar(100, Alt-30, 100+total*((Larg-200)/4), Alt-20);
	setvisualpage(1);

//________________________________________________________________ carregando as músicas do jogo
	waveOutSetVolume(0,volumes[volumcont]); 
	mciSendString("open .\\songs\\musica_inicio_do_jogo.mp3 type MPEGVideo alias Music1", NULL, 0, 0); 
//	mciSendString("open .\\songs\\primeiro_efeito.mp3 type MPEGVideo alias Efect1", NULL, 0, 0); 
	mciSendString("open .\\songs\\segunda_musica_do_jogo.mp3 type MPEGVideo alias Music2", NULL, 0, 0); 
//	mciSendString("open .\\songs\\segundo_efeito.mp3 type MPEGVideo alias Efect2", NULL, 0, 0); 
	mciSendString("open .\\songs\\terceira_musica_do_jogo.mp3 type MPEGVideo alias Music3", NULL, 0, 0);
	mciSendString("open .\\songs\\musica_final_do_jogo.mp3 type MPEGVideo alias Ending", NULL, 0, 0);
	mciSendString("play Music1 repeat", NULL, 0, 0);
	double u = 5.84269663;
	if(true){ // facilitador para minimizar total de imagens para personagem
	
//_______________________________________________________________ Tratamento de imagens de movimento
	//Imagem de tamanho 128 por 128
	tam = imagesize(0,0,127, 127);
	for(i = 0; i < QtdePsg; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		
		R[i] = (unsigned char *)malloc(tam);
		M[i] = (unsigned char *)malloc(tam);
		FlipR[i] = (unsigned char *)malloc(tam);
		FlipM[i] = (unsigned char *)malloc(tam);

	} 	
	
	char ImgFile[35];
	
	for (i = 0; i < QtdePsg; i++){
		z = i;
		setactivepage(2);
		if (i < 10) sprintf(ImgFile,".\\images\\correndo\\Run0%d.bmp",i);
		else sprintf(ImgFile,".\\images\\correndo\\Run%d.bmp",i);

		readimagefile(ImgFile, 0, 0, 127, 127);
		getimage(0, 0, 127, 127, R[i]); // captura para o ponteiro R
		getimage(0, 0, 127, 127, M[i]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
		getimage(0, 0, 127, 127, FlipR[i]); // captura para o ponteiro R
		getimage(0, 0, 127, 127, FlipM[i]); // captura para a máscara M (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
		
		setactivepage(1);
		setfillstyle(1, RGB(190, 190, 255));
		bar(100, Alt-50, 100+(i*u), Alt-40);
		setvisualpage(1);
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
	u = 3.82352941;
		total++;
	setactivepage(1);
	setfillstyle(1, RGB(0, 0, 0));
	bar(0,0,Larg,Alt);
	setbkcolor(RGB(0, 0, 0));
	rectangle(100, Alt-50, Larg-100, Alt-40);
		rectangle(100, Alt-30, Larg-100, Alt-20);
		setfillstyle(1, RGB(190, 190, 255));
	bar(100, Alt-30, 100+total*((Larg-200)/4), Alt-20);
	setvisualpage(1);
	for(i = 0; i < SpritePr; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		St[i] = (unsigned char *)malloc(tam);
		MSt[i] = (unsigned char *)malloc(tam);
		FlipSt[i] = (unsigned char *)malloc(tam);
		FlipMSt[i] = (unsigned char *)malloc(tam);
	} 


	for (i = 0; i < SpritePr; i++){
		setactivepage(2);
		if (i < 10) sprintf(ImgFile,".\\images\\parado\\Idle00%d.bmp",i);
		else if (i < 100) sprintf(ImgFile,".\\images\\parado\\Idle0%d.bmp",i);
		else sprintf(ImgFile,".\\images\\parado\\Idle%d.bmp",i);

		readimagefile(ImgFile, 0, 0, 127, 127);
		getimage(0, 0, 127, 127, St[i]); // captura para o ponteiro St
		getimage(0, 0, 127, 127, MSt[i]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
		getimage(0, 0, 127, 127, FlipSt[i]); // captura para o ponteiro St
		getimage(0, 0, 127, 127, FlipMSt[i]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
		
		setactivepage(1);
		setfillstyle(1, RGB(190, 190, 255));
		bar(100, Alt-50, 100+(i*u), Alt-40);
		setvisualpage(1);
	}

	for(i = 0; i < SpritePr; i++){
		PreparaImg(tam, St[i], MSt[i]); // configura as cores branca e preta em cada pixel para formar o recorte
		PreparaImg(tam, FlipSt[i], FlipMSt[i]);} // configura as cores branca e preta em cada pixel para formar o recorte
	
	
	for (i = 0; i < SpritePr; i++){
		FlipImg(128,128,FlipSt[i]);
		FlipImg(128,128,FlipMSt[i]);
	}
	//_______________________________________________________________ Tratamento de imagens pulando
	//Imagem de tamanho 128 por 128
	u = 11.0638297;
		total++;
	setactivepage(1);
	setfillstyle(1, RGB(0, 0, 0));
	bar(0,0,Larg,Alt);
	setbkcolor(RGB(0, 0, 0));
	rectangle(100, Alt-50, Larg-100, Alt-40);
		rectangle(100, Alt-30, Larg-100, Alt-20);
		setfillstyle(1, RGB(190, 190, 255));
	bar(100, Alt-30, 100+total*((Larg-200)/4), Alt-20);
	setvisualpage(1);
	for(i = 0; i < SpritePl; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		Jp[i] = (unsigned char *)malloc(tam);
		MJp[i] = (unsigned char *)malloc(tam);
		FlipJp[i] = (unsigned char *)malloc(tam);
		FlipMJp[i] = (unsigned char *)malloc(tam);
	} 
	
	for (i = 0; i < SpritePl; i++){
		setactivepage(2);
		if (i < 10) sprintf(ImgFile,".\\images\\pulando\\Jump0%d.bmp",i);
		else sprintf(ImgFile,".\\images\\pulando\\Jump%d.bmp",i);

		readimagefile(ImgFile, 0, 0, 127, 127);
		getimage(0, 0, 127, 127, Jp[i]); // captura para o ponteiro St
		getimage(0, 0, 127, 127, MJp[i]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
		getimage(0, 0, 127, 127, FlipJp[i]); // captura para o ponteiro St
		getimage(0, 0, 127, 127, FlipMJp[i]); // captura para a máscara MSt (a mesma imagem de P, que depois será manipulada na rotina PreparaImg)
		
		setactivepage(1);
		setfillstyle(1, RGB(190, 190, 255));
		bar(100, Alt-50, 100+(i*u), Alt-40);
		setvisualpage(1);
	}

	for(i = 0; i < SpritePl; i++){
		PreparaImg(tam, Jp[i], MJp[i]); // configura as cores branca e preta em cada pixel para formar o recorte
		PreparaImg(tam, FlipJp[i], FlipMJp[i]);} // configura as cores branca e preta em cada pixel para formar o recorte
	
	
	for (i = 0; i < SpritePl; i++){
		FlipImg(128,128,FlipJp[i]);
		FlipImg(128,128,FlipMJp[i]);
	}
}

//________________________________________________________________ Inserção de background em layer 1
	u = 7.87878787;
			total++;

	setactivepage(1);
	setfillstyle(1, RGB(0, 0, 0));
	bar(0,0,Larg,Alt);
	setbkcolor(RGB(0, 0, 0));
	rectangle(100, Alt-50, Larg-100, Alt-40);
	rectangle(100, Alt-30, Larg-100, Alt-20);
	setfillstyle(1, RGB(190, 190, 255));
	bar(100, Alt-30, 100+total*((Larg-200)/4), Alt-20);
	setvisualpage(1);
	
	tam = imagesize(0,0,329, 329);
	for(i = 0; i < QtdeBg; i++){ // é necessário alocar memória para cada imagem contida no vetor de ponteiros
		Bg[i] = (unsigned char *)malloc(tam);
	}
	
	char ImgFile[35];
	for (i = 0; i < QtdeBg; i++){
		setactivepage(2);
		sprintf(ImgFile,".\\images\\background\\Bg (%d).bmp",i);
		
		readimagefile(ImgFile, 0, 0, 329, 329);
		getimage(0, 0, 329, 329, Bg[i]); // captura para o ponteiro R
		
		setactivepage(1);
		setfillstyle(1, RGB(190, 190, 255));
		bar(100, Alt-50, 100+(i*u), Alt-40);
		setvisualpage(1);
	}
	
/*
//________________________________________________________________ Inserção de background em layer 2 -> Rocha
	
	tam = imagesize(0,0,983,237);
		Bg[1] = (unsigned char *)malloc(tam);
		MBg[1] = (unsigned char *)malloc(tam);
	
		readimagefile(".\\images\\rock.bmp", 0, 0,983,237);
		getimage(0, 0,983,237, Bg[1]); // captura para o ponteiro R
		getimage(0, 0,983,237, Bg[1]); // captura para o ponteiro R

		PreparaImg(tam, R[1], M[1]); // configura as cores branca e preta em cada pixel para formar o recorte
		
//________________________________________________________________ Inserção de background em layer 2 -> Rocha
	
	tam = imagesize(0,0,1443,390);
		Bg[2] = (unsigned char *)malloc(tam);
		MBg[2] = (unsigned char *)malloc(tam);
	
		readimagefile(".\\images\\cloud.bmp", 0, 0,1443,390);
		getimage(0, 0,1443,390, Bg[2]); // captura para o ponteiro R
		getimage(0, 0,1443,390, Bg[2]); // captura para o ponteiro R

		PreparaImg(tam, R[2], M[2]); // configura as cores branca e preta em cada pixel para formar o recorte
*/
//_______________________________________________________________ 
	
	altura_psg = 89;
	largura_psg = 70;
		
	psg.x = Larg/2-(largura_psg/2);
	psg.y = Alt-altura_psg-50; 
	psg.largura = psg.x + largura_psg;
	psg.altura = psg.y + altura_psg;
	
	Passo_X = 4;
	Passo_Y = 0.5;
	
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
			defineFundo(1,-Larg/2+200,100,50,90);
			defineFundo(2,-Larg/2+50,150,-Larg/2+100,140);
			defineFundo(3,-Larg/2+200,250,50,240);
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
			
			pilar = 3960;
			colum = 0;
			for(i = QtdeBg-1; i >= 0; i--){
				
				if (colum+inicio-(Larg/2) <= Larg && Alt-pilar-altitude+330 >= 0) putimage(colum+inicio-(Larg/2), Alt-pilar-altitude, Bg[i], COPY_PUT); 
				if (i%6 == 0){
					colum = 0;
					pilar -= 330;	
				} 
				colum += 330;	
			}
		
			//barra(psg.x, psg.y, psg.largura, psg.altura, vermelho);   // verificador de colisão do personagem
			
			switch(direcao){
				case 1: // personagem andando para a direita		
					putimage(psg.x-29, psg.y-Altdesenho, M[ande], AND_PUT);
    				putimage(psg.x-29, psg.y-Altdesenho, R[ande], OR_PUT);					
					break;
				
				case 2: // personagem andando para a esquerda
					putimage(psg.x-29, psg.y-Altdesenho, FlipM[ande], AND_PUT);
    				putimage(psg.x-29, psg.y-Altdesenho, FlipR[ande], OR_PUT);					
					break;
				case 3: // personagem parado para a direita
					putimage(psg.x-29, psg.y-Altdesenho, MSt[stoped], AND_PUT);
    				putimage(psg.x-29, psg.y-Altdesenho, St[stoped], OR_PUT);					
					break;
				case 4: // personagem parado para a esquerda
					putimage(psg.x-29, psg.y-Altdesenho, FlipMSt[stoped], AND_PUT);
    				putimage(psg.x-29, psg.y-Altdesenho, FlipSt[stoped], OR_PUT);					
					break;
				case 5: // personagem pulando para a direita
					putimage(psg.x-29, psg.y-Altdesenho, MJp[pulando], AND_PUT);
    				putimage(psg.x-29, psg.y-Altdesenho, Jp[pulando], OR_PUT);					
					break;
				case 6: // personagem pulando para a esquerda
					putimage(psg.x-29, psg.y-Altdesenho, FlipMJp[pulando], AND_PUT);
    				putimage(psg.x-29, psg.y-Altdesenho, FlipJp[pulando], OR_PUT);					
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
	//___________________________________________________________________________________	Troca de música		
			if (GetKeyState(0x4D)&0x80){ // Tecla M
				switchmusic = true;
			}
			if (switchmusic == true){
				volumcont += passomusica;
				waveOutSetVolume(0,volumes[volumcont]); 
				
				if (volumcont == 15){
					mciSendString("close Music1", NULL, 0, 0);
					passomusica = -passomusica;
				}
				if (volumcont == 0){
					sndPlaySound(".\\songs\\primeiro_efeito1.wav", SND_ASYNC);
					mciSendString("play Music2 repeat", NULL, 0, 0);
					//mciSendString("play Efect1", NULL, 0, 0);
					switchmusic = false;
					passomusica = -passomusica;
				}
			}
			printf("volume: %d    switchmusic:%d \n",volumcont,switchmusic);

	//_________________________________________________________ Andar para esquerda e direita da tela		
			
			if (GetKeyState(VK_LEFT)&0x80 && !(GetKeyState(VK_RIGHT)&0x80)) {
				if (psg.x > Larg/2){
					psg.x -= Passo_X;
					psg.largura -= Passo_X;
					
					for (i = 0; i < Qtde_chao; i++){
						if (psg.x <= colisao_chao[i].largura + (5*velocidade_pos) && psg.largura >= colisao_chao[i].x + (5*velocidade_pos)){
							if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {
								psg.x += Passo_X;
								psg.largura += Passo_X; 
								break;
							}	
						}
					}
					
					moved = true;					
					if (pulando == 0) direcao = 2;
					if (ande != QtdePsg-1) ande += 2;
					if (ande > QtdePsg-1) ande = QtdePsg-1;
					else if (ande == QtdePsg-1) ande = 0;
					
				}else if (-inicio > 0){
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
				}else if(psg.x > 0){
					psg.x -= Passo_X;
					psg.largura -= Passo_X;
					
					for (i = 0; i < Qtde_chao; i++){
						if (psg.x <= colisao_chao[i].largura + (5*velocidade_pos) && psg.largura >= colisao_chao[i].x + (5*velocidade_pos)){
							if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {
								psg.x += Passo_X;
								psg.largura += Passo_X; 
								break;
							}	
						}
					}
					
					moved = true;					
					if (pulando == 0) direcao = 2;
					if (ande != QtdePsg-1) ande += 2;
					if (ande > QtdePsg-1) ande = QtdePsg-1;
					else if (ande == QtdePsg-1) ande = 0;
				}
				

					
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
				if(psg.x < Larg/2){
					psg.x += Passo_X;
					psg.largura += Passo_X;
					
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
					
				}else if (-inicio < 237 ||(altitude >= 1230 && -inicio < 1230)){
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
				}else if(psg.largura < Larg){
					psg.x += Passo_X;
					psg.largura += Passo_X;
					
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
				}

	
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
//					psg.y -= 4;
//					psg.altura -= 1;
	
					if (pulando <= 18 && Altdesenho > 2)Altdesenho -= 7;

									
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
			}else if(chao == true)Altdesenho = 29;
			
			
			if (chao == false){
				if (tempo == 1) multiplicador = 5.0;
				else multiplicador = 1.5;
				psg.y = psg.y + (Passo_Y*(tempo*multiplicador)); // constantemente puxa para baixo, com valor menor crescente, até superar o valor do pulo
				psg.altura = psg.altura + (Passo_Y*(tempo*multiplicador));
				
				if(direcao == 1 || direcao == 3) direcao = 5;
				else if(direcao == 2 || direcao == 4) direcao = 6;
				
				if (Pulo == false){
					pulando = 19;
//					altitude -= 10.0;
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
			
			if (psg.y <= Alt/2 && chao == true) {
				altitude -= Alt/3;
				psg.y += Alt/3;
				psg.altura += Alt/3;
			}
//			if (GetKeyState(VK_DOWN)&0x80) {
//				altitude -= 10.0;
//			}
			
//			if (psg.altura >= Alt-25) break; //End game por queda
			
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
	
	printf("Participantes: \n\n");
	printf("  Ednei Sell dos Santos Junior  \n");
	printf("  Luciano de Carvalho Lima  \n");
	printf("  Marcelo Kazuaki Shimada  \n");
	printf("  Matheus Ferrandes de Mayo Gomes Beato  \n");
	printf("  Thiago Oliveira Monte Alves de Araujo  \n\n");
	
	setactivepage(1);
	setfillstyle(1, RGB(0, 0, 0));
	bar(0,0,Larg,Alt);
	setbkcolor(RGB(0, 0, 0));
	setvisualpage(1);
		
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
	
	char ImgFile[35];
	for (i = 0; i < efeito; i++){
		setactivepage(2);
		sprintf(ImgFile,".\\images\\efeitos\\Efeito%d.bmp",i);

		readimagefile(ImgFile, 0, 0, 719, 479);
		getimage(0, 0, 719, 479, E[i]); // captura para o ponteiro R
		
	}
	
	setactivepage(2);
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
				if (C_on == true)fase1jogo();
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
	
//	TelaInicial();
	fase1jogo();
	
	closegraph();
  	return(0);
}


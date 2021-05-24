
/* JOGNA2 - Entrega N1.C - Grupo N�mero 1
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
#define QtdePsg  3

int Larg, Alt; // Vari�veis de largura e altura da tela

void quadrado(int Ponto_X1, int Ponto_Y1, int Ponto_X2, int Ponto_Y2, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	rectangle(Ponto_X1,Ponto_Y1,Ponto_X2,Ponto_Y2);
}

void barra(int Ponto_X1, int Ponto_Y1, int Ponto_X2, int Ponto_Y2, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	setfillstyle(1,RGB(cor[0],cor[1],cor[2]));
	bar(Ponto_X1,Ponto_Y1,Ponto_X2,Ponto_Y2);
}

void linha(int Ponto_X1, int Ponto_Y1, int Ponto_X2, int Ponto_Y2, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	line(Ponto_X1,Ponto_Y1,Ponto_X2,Ponto_Y2);
}

void circulo(int Ponto_X, int Ponto_Y, int Tamanho, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	circle(Ponto_X,Ponto_Y,Tamanho);
}

void elipse(int Ponto_X, int Ponto_Y, int Tamanho_X, int Tamanho_Y, int cor[]){
	setcolor(RGB(cor[0],cor[1],cor[2]));
	setfillstyle(1,RGB(cor[0],cor[1],cor[2]));
	fillellipse(Ponto_X,Ponto_Y,Tamanho_X,Tamanho_Y);
}

void poligono(int qtd_pontos, int pontos [], int cor[]){ 
	setcolor(RGB(cor[0],cor[1],cor[2]));
	setfillstyle(1,RGB(cor[0],cor[1],cor[2]));
	fillpoly(qtd_pontos, pontos);
}

void ponto(int Ponto_X, int Ponto_Y, int cor[]){
	putpixel(Ponto_X,Ponto_Y,RGB(cor[0],cor[1],cor[2]));
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
// Tam � o tamanho dos ponteiros da imagem e da m�scara
// Img � o ponteiro que aponta para o vetor que cont�m a imagem capturada com getimage(..)
// Msk � o ponteiro que ser� transformado em m�scara
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
// LargImag � a largura total da iamgem, uma imagem 200x100 equivale a 200
// AltImag � a altura total da iamgem, uma imagem 200x100 equivale a 100
// Img � o ponteiro que aponta para o vetor que cont�m a imagem capturada com getimage(..)
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

void fasejogo(){
	char tecla = 0;
	//_____________________________________ Defini��es de images
	int tam,ande = 0;
	unsigned char *R[QtdePsg], *M[QtdePsg], *FlipR[QtdePsg], *FlipM[QtdePsg];	
	
	TQUADRADO *inimigos, psg;
	int Qtde_chao, Qtde_inimigos;
	int passo_inimigos = 5, andando = 0;
	bool morte = false;
	
	int direcao = 1;
	int tempo = 1;
	double velocidade_pos = 1.0, velocidade_neg = 1.0, velocidade, Velocidade_Max = 1.5;
	double multiplicador;	
	
	int altura_psg, largura_psg;
	double altitude = 0.0;
	
	int i,X,cont; // Vari�veis i, X e cont armezenam informa��es din�micas.
	double inicio = 0; // V�ri�vel In�cio define o in�cio da tela
	int pg = 1; // V�riavel de pagina 
	int Passo_X,Passo_Y; // Vari�vel do raio e passo das esferas m�veis
	bool chao = true,Pulo = false;
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
	
//_______________________________________________________________ Tratamento de imagens
	//Imagem de tamanho 117 por 208
	tam = imagesize(0,0,44, 27);
	for(i = 0; i < QtdePsg; i++){ // � necess�rio alocar mem�ria para cada imagem contida no vetor de ponteiros
		R[i] = (unsigned char *)malloc(tam);
		M[i] = (unsigned char *)malloc(tam);
		FlipR[i] = (unsigned char *)malloc(tam);
		FlipM[i] = (unsigned char *)malloc(tam);
	} 	

	readimagefile(".\\images\\move_1.bmp", 0, 0, 44, 27);
	getimage(0, 0, 44, 27, R[0]); // captura para o ponteiro R
	getimage(0, 0, 44, 27, M[0]); // captura para a m�scara M (a mesma imagem de P, que depois ser� manipulada na rotina PreparaImg)
	getimage(0, 0, 44, 27, FlipR[0]); // captura para o ponteiro R
	getimage(0, 0, 44, 27, FlipM[0]); // captura para a m�scara M (a mesma imagem de P, que depois ser� manipulada na rotina PreparaImg)
	
	readimagefile(".\\images\\move_2.bmp", 0, 0, 44, 27);
	getimage(0, 0, 44, 27, R[1]); // captura para o ponteiro R
	getimage(0, 0, 44, 27, M[1]); // captura para a m�scara M (a mesma imagem de P, que depois ser� manipulada na rotina PreparaImg)
	getimage(0, 0, 44, 27, FlipR[1]); // captura para o ponteiro R
	getimage(0, 0, 44, 27, FlipM[1]); // captura para a m�scara M (a mesma imagem de P, que depois ser� manipulada na rotina PreparaImg)
	
	readimagefile(".\\images\\move_3.bmp", 0, 0, 44, 27);
	getimage(0, 0, 44, 27, R[2]); // captura para o ponteiro R
	getimage(0, 0, 44, 27, M[2]); // captura para a m�scara M (a mesma imagem de P, que depois ser� manipulada na rotina PreparaImg)
	getimage(0, 0, 44, 27, FlipR[2]); // captura para o ponteiro R
	getimage(0, 0, 44, 27, FlipM[2]); // captura para a m�scara M (a mesma imagem de P, que depois ser� manipulada na rotina PreparaImg)
	

	for(i = 0; i < QtdePsg; i++){
		PreparaImg(tam, R[i], M[i]); // configura as cores branca e preta em cada pixel para formar o recorte
		PreparaImg(tam, FlipR[i], FlipM[i]);} // configura as cores branca e preta em cada pixel para formar o recorte
	
	
	for (i = 0; i < QtdePsg; i++){
		FlipImg(45,28,FlipR[i]);
		FlipImg(45,28,FlipM[i]);
	}
//_______________________________________________________________ 
	
	altura_psg = 28;
	largura_psg = 40;
		
	psg.x = Larg/2-(largura_psg/2);
	psg.y = Alt-altura_psg-50; 
	psg.largura = psg.x + largura_psg;
	psg.altura = psg.y + altura_psg;
	
	Passo_X = 4;
	Passo_Y = 1;
	
	Qtde_chao = 9;
	colisao_chao = (TQUADRADO*)malloc(sizeof(TQUADRADO)*Qtde_chao);
	
	Qtde_inimigos = 1;
	inimigos = (TQUADRADO*)malloc(sizeof(TQUADRADO)*Qtde_inimigos);
	
	int FPS = 60;
	gt1 = GetTickCount();
	gt2 = gt1 * 2;
	
//___________________________________________________ In�cio do la�o de movimento
	while (tecla != ESC){
		
		if (gt2 - gt1 > 1000/FPS){
			gt1 = gt2;
			
			// ______________________________________ Desenho do ch�o			
			for (i = 0; i < Qtde_chao; i++){
				colisao_chao[i].x = inicio+Larg;
				colisao_chao[i].y = Alt-altitude;	
				colisao_chao[i].largura = inicio+Larg;
				colisao_chao[i].altura = Alt-altitude;
			}
			
			defineFundo(0,-Larg,50,0,0);
			defineFundo(1,100,80,400,40);
			defineFundo(2,-Larg/2+50,80,-Larg/2+70,40);
			defineFundo(3,500,110,700,100);
			defineFundo(4,750,150,800,145);
			defineFundo(5,650,235,695,230);
			defineFundo(6,800,290,900,285);
			defineFundo(7,1000,340,1500,335);
			defineFundo(8,-Larg/2-100,150,-Larg/2-50,140);
			
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
			
//			barra(psg.x, psg.y, psg.largura, psg.altura, vermelho);
			
			switch(direcao){
				case 1: 
					putimage(psg.x, psg.y, M[ande], AND_PUT);
    				putimage(psg.x, psg.y, R[ande], OR_PUT);					
					break;
				
				case 2: 
					putimage(psg.x, psg.y, FlipM[ande], AND_PUT);
    				putimage(psg.x, psg.y, FlipR[ande], OR_PUT);					
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
	//___________________________________________________________________________________	Colis�o com inimigos
	
			for (i = 0; i < Qtde_inimigos; i++){
				if (psg.x <= inimigos[i].largura && psg.largura >= inimigos[i].x){
					if(psg.y <= inimigos[i].altura && psg.altura >= inimigos[i].y) morte = true;
				}
			}
			
			
			
	//_________________________________________________________ Andar para esquerda e direita da tela		
			
			if (GetKeyState(VK_LEFT)&0x80) {
				if (velocidade_pos < 1) velocidade_pos = 1;				
				inicio = inicio + (5*velocidade_pos);
				
				for (i = 0; i < Qtde_chao; i++){
					if (psg.x <= colisao_chao[i].largura + (5*velocidade_pos) && psg.largura >= colisao_chao[i].x + (5*velocidade_pos)){
						if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio - (5*velocidade_pos); break;}	
					}
				}
												
				direcao = 2;
				ande++;
				if (ande > 2) ande = 0;
					
			}else if (velocidade_pos > 0){
				if (Pulo == false){
					inicio = inicio + (5*velocidade_pos);
					
					for (i = 0; i < Qtde_chao; i++){
						if (psg.x <= colisao_chao[i].largura + (5*velocidade_pos) && psg.largura >= colisao_chao[i].x + (5*velocidade_pos)){
							if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio - (5*velocidade_pos); break;}	
						}
					}				
				}
				velocidade_pos -= 0.5;
			}
			
			if (GetKeyState(VK_RIGHT)&0x80) {
				if (velocidade_neg < 1) velocidade_neg = 1;
				inicio = inicio - (5*velocidade_neg);		
				
				
				for (i = 0; i < Qtde_chao; i++){
					if (psg.x <= colisao_chao[i].largura - (5*velocidade_neg) && psg.largura >= colisao_chao[i].x - (5*velocidade_neg)){
						if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio + (5*velocidade_neg); break;}	
					}
				}
								
				direcao = 1;
				ande++;
				if (ande > 2) ande = 0;
	
			}else if(velocidade_neg > 0) {
				if (Pulo == false){
					inicio = inicio - (5*velocidade_neg);	
						
					for (i = 0; i < Qtde_chao; i++){
						if (psg.x <= colisao_chao[i].largura - (5*velocidade_neg) && psg.largura >= colisao_chao[i].x - (5*velocidade_neg)){
							if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio + (5*velocidade_neg); break;}	
						}
					}
				}
				velocidade_neg -= 0.5;
			}
					
			
			if (velocidade_pos == 1) velocidade = velocidade_neg;
			else velocidade = velocidade_pos;
	//________________________________________________________________________
			if (GetKeyState(VK_UP)&0x80){
				if (Pulo == false && tempo == 1 && chao == true) Pulo = true;
			}
			
			if (Pulo == true){		
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
			
			if (chao == false){
				if (tempo == 1) multiplicador = 5.0;
				else multiplicador = 1.5;
				psg.y = psg.y + (Passo_Y*(tempo*multiplicador)); // constantemente puxa para baixo, com valor menor crescente, at� superar o valor do pulo
				psg.altura = psg.altura + (Passo_Y*(tempo*multiplicador));
			}
						
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
			
			if (inicio < -150) {
				if (psg.y <= Alt/2) altitude -= 2.0;
				else if (psg.y <= Alt-Alt/4) altitude -= 1.0;
				else altitude -= 0.5;
			}
			
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

int main(void){		

	Larg = 640;
	Alt = 480;
	initwindow(Larg, Alt,"Rise");
	
	fasejogo();
	
	closegraph();
  	return(0);
}


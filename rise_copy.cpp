


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

void fundo(int inicio, int Larg, int Alt, int i, int X, int Linha_de_fim){
	
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
	
struct TQUADRADO{
     double x;       
	 double y;       
	 double largura;       
	 double altura; 
};


int main(void){
	
	char tecla = 0;
	
	TQUADRADO *colisao_chao,*inimigos, psg;
	int Qtde_chao, Qtde_inimigos;
	int passo_inimigos = 5, andando = 0;
	bool morte = false;
	
	int tempo = 1;
	int fim_tela;
	double velocidade_pos = 1.0, velocidade_neg = 1.0, velocidade, Velocidade_Max = 1.5;
	double ultima_Vel_pos, ultima_Vel_neg;
	double multiplicador;	
	
	int altura_psg, largura_psg, pos_ini_X, pos_ini_Y,pos_fin_X,pos_fin_Y;
	int jump = 0;
	double altitude = 0.0;
	
	int i,X,cont; // Variáveis i, X e cont armezenam informações dinámicas.
	int Larg, Alt; // Variáveis de largura e altura da tela
	double inicio = 0; // Váriável Início define o início da tela
	int pg = 1; // Váriavel de pagina 
	int raio,Passo_X,Passo_Y; // Variável do raio e passo das esferas móveis
	int Alt_atual,Prox_Alt,Posi_X;
	int Fim_de_curso = 0;
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
	
//__________________________________________________________ inicialização da área gráfica

	Larg = 640;
	Alt = 480;
	initwindow(Larg, Alt,"Movimento Uniforme");
	
	
//_______________________________________________________________ 
	
	raio = 8;
	altura_psg = 40;
	largura_psg = 30;
	pos_ini_X = Larg/2-(largura_psg/2);
	pos_fin_X = pos_ini_X + largura_psg;
	pos_ini_Y = Alt-altura_psg-50; 
	pos_fin_Y = pos_ini_Y + altura_psg;
		
	psg.x = Larg/2-(largura_psg/2);
	psg.y = Alt-altura_psg-50; 
	psg.largura = pos_ini_X + largura_psg;
	psg.altura = pos_ini_Y + altura_psg;
	
	Passo_X = 4;
	Passo_Y = 1;
	
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
			colisao_chao[0].x = inicio;
			colisao_chao[0].y = Alt-50-altitude;	
			colisao_chao[0].largura = inicio+Larg;
			colisao_chao[0].altura = Alt-altitude;
			
			colisao_chao[1].x = inicio+Larg+100;
			colisao_chao[1].y = Alt-80-altitude;	
			colisao_chao[1].largura = inicio+Larg+400;
			colisao_chao[1].altura = Alt-40-altitude;
			
			colisao_chao[2].x = inicio+Larg/2+50;
			colisao_chao[2].y = Alt-80-altitude;	
			colisao_chao[2].largura = inicio+Larg/2+70;
			colisao_chao[2].altura = Alt-40-altitude;
			
			colisao_chao[3].x = inicio+Larg+500;
			colisao_chao[3].y = Alt-110-altitude;	
			colisao_chao[3].largura = inicio+Larg+700;
			colisao_chao[3].altura = Alt-100-altitude;
			
			colisao_chao[4].x = inicio+Larg+750;
			colisao_chao[4].y = Alt-150-altitude;	
			colisao_chao[4].largura = inicio+Larg+800;
			colisao_chao[4].altura = Alt-145-altitude;
			
			colisao_chao[5].x = inicio+Larg+650;
			colisao_chao[5].y = Alt-235-altitude;	
			colisao_chao[5].largura = inicio+Larg+695;
			colisao_chao[5].altura = Alt-230-altitude;
			
			colisao_chao[6].x = inicio+Larg+800;
			colisao_chao[6].y = Alt-290-altitude;	
			colisao_chao[6].largura = inicio+Larg+900;
			colisao_chao[6].altura = Alt-285-altitude;
			
			colisao_chao[7].x = inicio+Larg+1000;
			colisao_chao[7].y = Alt-340-altitude;	
			colisao_chao[7].largura = inicio+Larg+1500;
			colisao_chao[7].altura = Alt-335-altitude;
			
			colisao_chao[8].x = inicio+Larg/2-100;
			colisao_chao[8].y = Alt-150-altitude;	
			colisao_chao[8].largura = inicio+Larg/2-50;
			colisao_chao[8].altura = Alt-140-altitude;
			
			//_________________________________________ Desenho dos inimigos
			inimigos[0].x = inicio+Larg+1200+andando;
			inimigos[0].y = Alt-360-altitude;
			inimigos[0].largura = inicio+Larg+1220+andando;
			inimigos[0].altura = Alt-340-altitude;
			
			if (pg == 1) pg = 2; else pg = 1;
			setactivepage(pg);
			
			setbkcolor(RGB(0,0,205));
			cleardevice();	
			fundo(inicio,Larg,Alt,i,X,Fim_de_curso);
			
			barra(psg.x, psg.y, psg.largura, psg.altura, vermelho);
			
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
			
			if (GetKeyState(VK_LEFT)&0x80) {
				if (velocidade_pos < 1) velocidade_pos = 1;				
				inicio = inicio + (5*velocidade_pos);
				
				for (i = 0; i < Qtde_chao; i++){
					if (psg.x <= colisao_chao[i].largura + (5*velocidade_pos) && psg.largura >= colisao_chao[i].x + (5*velocidade_pos)){
						if(psg.y < colisao_chao[i].altura && psg.altura > colisao_chao[i].y) {inicio = inicio - (5*velocidade_pos); break;}	
					}
				}
								
				if (velocidade_pos < Velocidade_Max) velocidade_pos += 0.1;			
				ultima_Vel_pos = velocidade_pos;
					
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
				
				if (velocidade_neg < Velocidade_Max) velocidade_neg += 0.1;
				ultima_Vel_neg = velocidade_neg;
	
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
				psg.y = psg.y + (Passo_Y*(tempo*multiplicador)); // constantemente puxa para baixo, com valor menor crescente, até superar o valor do pulo
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
	closegraph();	 
	return 0;
	
	
	
	
}


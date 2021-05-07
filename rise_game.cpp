


/* JOGNA2 - Entrega N1.C - Grupo Número 1
Participantes: 
Ednei Sell dos Santos Junior 
Luciano de Carvalho Lima
Marcelo Kazuaki Shimada
Matheus Ferrandes de Mayo Gomes Beato
Thiago Oliveira Monte Alves de Araujo
*/
/*

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

void fundo(int inicio, int Larg, int Alt, int V[], int Z[], int i, int X, int Linha_de_fim){
	
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
		
	barra(inicio,Alt-50+Linha_de_fim,inicio + Larg,Alt+Linha_de_fim,madeira);
	barra(inicio + Larg,Alt-80+Linha_de_fim,inicio + Larg+200,Alt+Linha_de_fim,madeira);
	barra(inicio + Larg+200,Alt-100+Linha_de_fim,inicio + Larg+400,Alt+Linha_de_fim,madeira);
	barra(inicio + Larg+500,Alt-130+Linha_de_fim,inicio + Larg+700,Alt+Linha_de_fim,madeira);
	barra(inicio + Larg+800,Alt-160+Linha_de_fim,inicio + Larg+850,Alt+Linha_de_fim,madeira);
	barra(inicio + Larg+950,Alt-190+Linha_de_fim,inicio + Larg+980,Alt+Linha_de_fim,madeira);
	barra(inicio + Larg+1050,Alt-230+Linha_de_fim,inicio + Larg+1100,Alt-220+Linha_de_fim,madeira);
	barra(inicio + Larg+1200,Alt-250+Linha_de_fim,inicio + Larg+1250,Alt-240+Linha_de_fim,madeira);
	barra(inicio + Larg+1280,Alt-320+Linha_de_fim,inicio + Larg+1450,Alt-310+Linha_de_fim,madeira);
	barra(inicio + Larg+1500,Alt-340+Linha_de_fim,inicio + Larg+1600,Alt-310+Linha_de_fim,madeira);
	barra(inicio + Larg+1700,Alt-360+Linha_de_fim,inicio + Larg+1750,Alt-310+Linha_de_fim,madeira);
	barra(inicio + Larg+1800,Alt-380+Linha_de_fim,inicio + Larg+1850,Alt-310+Linha_de_fim,madeira);
	barra(inicio + Larg+1900,Alt-400+Linha_de_fim,inicio + Larg+1950,Alt-310+Linha_de_fim,verde);
	barra(inicio + Larg+2000,Alt-420+Linha_de_fim,inicio + Larg+2050,Alt-310+Linha_de_fim,madeira);
	barra(inicio + Larg+2100,Alt-440+Linha_de_fim,inicio + Larg+2150,Alt-340+Linha_de_fim,madeira);

	linha(0,Alt-25+(Linha_de_fim/2),Larg,Alt-25+(Linha_de_fim/2),escarlate);
	
	elipse(inicio+(Larg/10*6),Alt/10*2,30,30,cianoClaro); // lua
 
	
	
	}

bool Colisao(int inicio, int PP_Y, int Altura_PP, int Larg_Tela, int Alt_tela, int Linha_de_fim){

	if (-inicio < Larg_Tela/2){
		if (PP_Y < (Alt_tela-Altura_PP-50+Linha_de_fim)) return true;
		else return false;	
	}else if (-inicio < (Larg_Tela/2)+200){
			if (PP_Y < (Alt_tela-80-Altura_PP+Linha_de_fim)) return true;
			else return false;	
		}else if (-inicio < (Larg_Tela/2)+400){
				if (PP_Y < (Alt_tela-100-Altura_PP+Linha_de_fim)) return true;
				else return false;
				}else if (-inicio > (Larg_Tela/2)+500 && -inicio < (Larg_Tela/2)+700){
					if (PP_Y < (Alt_tela-130-Altura_PP+Linha_de_fim)) return true;
					else return false;
					}else if (-inicio > (Larg_Tela/2)+800 && -inicio < (Larg_Tela/2)+850){
						if (PP_Y < (Alt_tela-160-Altura_PP+Linha_de_fim)) return true;
						else return false;
						}else if (-inicio > (Larg_Tela/2)+950 && -inicio < (Larg_Tela/2)+980){
							if (PP_Y < (Alt_tela-190-Altura_PP+Linha_de_fim)) return true;
							else return false;
								}else if (-inicio > (Larg_Tela/2)+1050 && -inicio < (Larg_Tela/2)+1100){
								if (PP_Y < (Alt_tela-230-Altura_PP+Linha_de_fim)) return true;
								else return false;
									}else if (-inicio > (Larg_Tela/2)+1200 && -inicio < (Larg_Tela/2)+1250){
									if (PP_Y < (Alt_tela-250-Altura_PP+Linha_de_fim)) return true;
									else return false;
										}else if (-inicio > (Larg_Tela/2)+1280 && -inicio < (Larg_Tela/2)+1450){
										if (PP_Y < (Alt_tela-320-Altura_PP+Linha_de_fim)) return true;
										else return false;
											}else if (-inicio > (Larg_Tela/2)+1500 && -inicio < (Larg_Tela/2)+1600){
											if (PP_Y < (Alt_tela-340-Altura_PP+Linha_de_fim)) return true;
											else return false;
												}else if (-inicio > (Larg_Tela/2)+1700 && -inicio < (Larg_Tela/2)+1750){
												if (PP_Y < (Alt_tela-360-Altura_PP+Linha_de_fim)) return true;
												else return false;
													}else if (-inicio > (Larg_Tela/2)+1800 && -inicio < (Larg_Tela/2)+1850){
													if (PP_Y < (Alt_tela-380-Altura_PP+Linha_de_fim)) return true;
													else return false;
														}else if (-inicio > (Larg_Tela/2)+1900 && -inicio < (Larg_Tela/2)+1950){
														if (PP_Y < (Alt_tela-400-Altura_PP+Linha_de_fim)) return true;
														else return false;
															}else if (-inicio > (Larg_Tela/2)+2000 && -inicio < (Larg_Tela/2)+2050){
															if (PP_Y < (Alt_tela-420-Altura_PP+Linha_de_fim)) return true;
															else return false;
																}else if (-inicio > (Larg_Tela/2)+2100 && -inicio < (Larg_Tela/2)+2150){
																if (PP_Y < (Alt_tela-440-Altura_PP+Linha_de_fim)) return true;
																else return false;
																}
}

int AltAtual(int inicio, int PP_Y, int Altura_PP, int Larg_Tela, int Alt_tela, int Linha_de_fim){
	int Atual;
	if (-inicio < Larg_Tela/2) return 50-Linha_de_fim;
	else if ((-inicio < (Larg_Tela/2)+200)) return 80-Linha_de_fim;
		else if ((-inicio < (Larg_Tela/2)+400)) return 100-Linha_de_fim;
				else if (-inicio > (Larg_Tela/2)+500 && -inicio < (Larg_Tela/2)+700) return 130-Linha_de_fim;
					else if (-inicio > (Larg_Tela/2)+800 && -inicio < (Larg_Tela/2)+850) return 160-Linha_de_fim;
						else if (-inicio > (Larg_Tela/2)+950 && -inicio < (Larg_Tela/2)+980) return 190-Linha_de_fim;
							else if (-inicio > (Larg_Tela/2)+1050 && -inicio < (Larg_Tela/2)+1100) return 230-Linha_de_fim;
								else if (-inicio > (Larg_Tela/2)+1200 && -inicio < (Larg_Tela/2)+1250) return 250-Linha_de_fim;
									else if (-inicio > (Larg_Tela/2)+1280 && -inicio < (Larg_Tela/2)+1450) return 320-Linha_de_fim;
										else if (-inicio > (Larg_Tela/2)+1500 && -inicio < (Larg_Tela/2)+1600) return 340-Linha_de_fim;
											else if (-inicio > (Larg_Tela/2)+1700 && -inicio < (Larg_Tela/2)+1750) return 360-Linha_de_fim;
												else if (-inicio > (Larg_Tela/2)+1800 && -inicio < (Larg_Tela/2)+1850) return 380-Linha_de_fim;
													else if (-inicio > (Larg_Tela/2)+1900 && -inicio < (Larg_Tela/2)+1950) return 400-Linha_de_fim;
														else if (-inicio > (Larg_Tela/2)+2000 && -inicio < (Larg_Tela/2)+2050) return 420-Linha_de_fim;
															else if (-inicio > (Larg_Tela/2)+2100 && -inicio < (Larg_Tela/2)+2150) return 440-Linha_de_fim;
																else return 0;
}

int main(void){
	
	char tecla = 0;
	
	int tempo = 1;
	int fim_tela;
	double velocidade_pos = 1.0, velocidade_neg = 1.0, velocidade, Velocidade_Max = 1.5;
	double ultima_Vel_pos, ultima_Vel_neg;
	double multiplicador;
	int i,X,cont; // Variáveis i, X e cont armezenam informações dinámicas.
	int Larg, Alt; // Variáveis de largura e altura da tela
	int inicio = 0; // Váriável Início define o início da tela
	int pg = 1; // Váriavel de pagina 
	int raio,Passo_X,Passo_Y; // Variável do raio e passo das esferas móveis
	int Alt_atual,Prox_Alt,Posi_X;
	int Fim_de_curso = 0;
	bool chao,Pulo = false;
	bool inercia_Right = false, inercia_Left = false;
	
	int *V; // vetor V = Posição X do ponto (estrelas)
	int *Z; // Vetor Z = Posição Y do ponto (estrela)
	
	int vermelho[3] = {255,0,0};
	int amarelo[3] = {255,255,0};
	int laranja[3] = {255,69,0};
	int jade[3] = {0,168,107};
	int orquidea[3] = {186,85,211};
	int cinzaArdosia[3] = {119,136,153};
	
	printf("Participantes: \n\n");
	printf("  Ednei Sell dos Santos Junior  \n");
	printf("  Luciano de Carvalho Lima  \n");
	printf("  Marcelo Kazuaki Shimada  \n");
	printf("  Matheus Ferrandes de Mayo Gomes Beato  \n");
	printf("  Thiago Oliveira Monte Alves de Araujo  \n\n");
	
//__________________________________________________________ Leitura e inicialização da área gráfica

	Larg = 640;
	Alt = 480;
	initwindow(Larg, Alt,"Movimento Uniforme");
	
	
		
//_______________________________________________________________ Definição da
	
	raio = 8;
	Passo_X = 4;
	Passo_Y = 1;
	int Bol_2[5] = {(Larg/2),(Alt-raio-50),raio,Passo_X,Passo_Y};
	
//___________________________________________________ Início do laço de movimento
	while (tecla != ESC){
		
		if (pg == 1) pg = 2; else pg = 1;
		setactivepage(pg);
		
		setbkcolor(RGB(0,0,205));
		cleardevice();	
		fundo(inicio,Larg,Alt,V,Z,i,X,Fim_de_curso);
		
		elipse(Bol_2[0],Bol_2[1],Bol_2[2],Bol_2[2],laranja);
		
		setvisualpage(pg);
		
		
//_________________________________________________________ Andar para esquerda e direita da tela		
		
		
		Alt_atual = AltAtual(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso);
		
		if (GetKeyState(VK_LEFT)&0x80) {
				if (velocidade_pos < 1) velocidade_pos = 1;
				inicio = inicio + (5*velocidade_pos);
				if (velocidade_pos < Velocidade_Max) velocidade_pos += 0.1;
				ultima_Vel_pos = velocidade_pos;
		}else if (velocidade_pos > 0){
			if (Pulo == false) inicio = inicio + (5*velocidade_pos);
			velocidade_pos -= 0.5;
		}
		Prox_Alt = AltAtual(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso);
		if (Prox_Alt > Alt_atual && Pulo == false) inicio = inicio - (5*(velocidade_pos)+raio);
		
		Alt_atual = AltAtual(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso);
		
		if (GetKeyState(VK_RIGHT)&0x80) {
				if (velocidade_neg < 1) velocidade_neg = 1;
				inicio = inicio - (5*velocidade_neg);	
				if (velocidade_neg < Velocidade_Max) velocidade_neg += 0.1;
				ultima_Vel_neg = velocidade_neg;	

		}else if(velocidade_neg > 0) {
			if (Pulo == false)inicio = inicio - (5*velocidade_neg);	
			velocidade_neg -= 0.5;
		}
		
		Prox_Alt = AltAtual(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso);	
		if (Prox_Alt > Alt_atual && Pulo == false) inicio = inicio + (5*(velocidade_neg)+raio);

//_________________________________________________________ Controle de velocidade para o pulo		
		if (velocidade_pos == 1) velocidade = velocidade_neg;
		else velocidade = velocidade_pos;
		
		if ((GetKeyState(VK_RIGHT)&0x80) && (GetKeyState(VK_UP)&0x80)) inercia_Right = true;
		if ((GetKeyState(VK_LEFT)&0x80) && (GetKeyState(VK_UP)&0x80)) inercia_Left = true;
		
//___________________________________ Inicio do laço de pulo || Bol_2[1] é igual a posição Y da bolinha
		if (GetKeyState(VK_UP)&0x80){
			if (Pulo == false && tempo == 1 && chao == true) Pulo = true;	// verificação se condição de pulo é aceita, eviando sinal caso possível
		} 
		
		if (Pulo == true){									// realiza o pulo caso sinal positivo
			Bol_2[1] = Bol_2[1] - Passo_Y-15-(velocidade); // pulo
			
			if (inercia_Right == true && !(GetKeyState(VK_RIGHT)&0x80)){
				Alt_atual = AltAtual(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso);
				inicio = inicio - (5*ultima_Vel_neg);
				Prox_Alt = AltAtual(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso);	
				if (Prox_Alt > Alt_atual) inicio = inicio + (5*(ultima_Vel_neg)+raio);
				
			} 
			else if (inercia_Left == true && !(GetKeyState(VK_LEFT)&0x80)) inicio = inicio + (5*ultima_Vel_pos);
			tempo++;
		}
		
		if (chao == false){
//			if (tempo == 1) multiplicador += 2;
//			else if(multiplicador < 5) multiplicador = 1.5;
			multiplicador = 1.5;
		/*	if (Bol_2[1] >= Alt-25-raio) Fim_de_curso -= Fim_de_curso + (Passo_Y*(tempo*multiplicador));
			else*//* Bol_2[1] = Bol_2[1] + (Passo_Y*(tempo*multiplicador)); // constantemente puxa para baixo, com valor menor crescente, até superar o valor do pulo
		}
		
		Alt_atual = AltAtual(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso);
		if (Bol_2[1] > (Alt-raio-Alt_atual)) Bol_2[1] = (Alt-raio-Alt_atual);				// para não ultrapassar o limite da tela, verifica o ultimo valor e o coloca no chão
		
		if (Colisao(inicio,Bol_2[1],raio,Larg,Alt,Fim_de_curso)) chao = false; 						// faz a verificação de se está ou não no chão
		else chao = true;
		
		if (tempo >= 5 && chao == true){								// E caso esteja no chão, com tempo maior, reinicia o tempo e torna outro pulo possível
		Pulo = false;
		tempo = 1;	
		inercia_Right = false;
		inercia_Left = false;
		} 
		
		if (Bol_2[1]<= Alt/2 && chao == true){
			Fim_de_curso += 2;
		}
		
		if (-inicio > 2220) Velocidade_Max = 2;

/*		
		if (Bol_2[1] >= Alt-raio){             // End game
			break;
		}
*//*		
		
		fflush(stdin);
		if (kbhit())
			tecla = getch();
			
	}
	closegraph();	 
	return 0;
	
	
	
	
}
*/

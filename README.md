# Rise_game
Repositório do jogo Rise
_____________________________________________________________________________________________________________________


### Repositório contém o Programa do jogo Rise, desenvolvido pelos alunos do segundo semestre da Fatec São Caetano do Sul
_____________________________________________________________________________________________________________________

Para acessar o jogo será necessário ou a abertura do arquivo .exe ou pelo Dev C++ conténdo a plataforma gráfica BGI


No uso da biblioteca gráfica BGI, será necessário adicionar os arquivos graphics.h e libbgi.a nos seguintes endereços:


| graphics.h | C:\Arquivos de Programas (x86)\Dev-Cpp\MinGW64\include |
|------------|--------------------------------------------------------|
| libbgi.a   | C:\Arquivos de Programas (x86)\Dev-Cpp\MinGW64\lib     |


Para então conseguir abrir o arquivo .dev
_____________________________________________________________________________________________________________________

Caso os parâmetros não estejam definidos, basta adicionar:


  -lbgi
  
  
  -lgdi32
  
  
  -lcomdlg32
  
  
  -luuid
  
  
  -loleaut32
  
  
  -lole32


Em opções de projeto -> Parâmetros -> Linker

![](https://i.pinimg.com/564x/70/23/b3/7023b37ec8d1f04ab08d4393a225b539.jpg)

Assim o jogo estará pronto para rodar

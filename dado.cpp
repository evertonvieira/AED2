#include <iostream>
using namespace std;
class  dado{
	public:
	int	cima;
	int baixo;
	int esquerda;
	int direita;

};


dado dado1[6];

int main(){


	dado1[0].cima= 5;
	dado1[0].baixo= 2;
	dado1[0].esquerda= 3;
	dado1[0].direita= 4;

	dado1[1].cima= 1;
	dado1[1].baixo= 6;
	dado1[1].esquerda= 3;
	dado1[1].direita= 4;

	dado1[2].cima= 5;
	dado1[2].baixo= 2;
	dado1[2].esquerda= 6;
	dado1[2].direita= 1;

	dado1[3].cima= 5;
	dado1[3].baixo= 2;
	dado1[3].esquerda= 1;
	dado1[3].direita= 6;

	dado1[4].cima= 6;
	dado1[4].baixo= 1;
	dado1[4].esquerda= 3;
	dado1[4].direita= 4;

	dado1[5].cima= 2;
	dado1[5].baixo= 5;
	dado1[5].esquerda= 3;
	dado1[5].direita= 4;


	int posicao=1;
	for(int i=0; i<=5; i++){
	posicao=dado1[posicao-1].cima;
		
		
		cout<<posicao;
	}
	return 0;
}

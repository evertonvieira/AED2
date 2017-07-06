#include <stdio.h>
#define ATIVIDADES 11
#define TERMINO 14
/*
i :      (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
começo = (1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12)
término = (4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14)
*/
typedef struct{
  int name;
  int inicio;
  int fim;
} No;

void preencheHorario(No [], int [][TERMINO] );
void exibeTabela(No [], int [][TERMINO]);
void ordenar(No []);
int listaSolucao(No []);


int main (){
  int i;

  No lista[ATIVIDADES]; //vetor de ATIVIDADES

  int tabela[ATIVIDADES][TERMINO] = {0}; // tabela com as atividades

  //complexidade Θ(n)
  for(i = 0; i < ATIVIDADES; i++){
    printf("Início da atividade %c: ", (65 + i) );
    scanf("%d", &lista[i].inicio);
    printf("Término da atividade %c: ", (65 + i) );
    scanf("%d", &lista[i].fim );
    lista[i].name = 65 + i;
  }

  preencheHorario(lista, tabela);
  exibeTabela(lista, tabela);

  listaSolucao(lista);

  printf("\n");


  return 0;
}

//complexidade Θ(n²)
void preencheHorario(No lista[], int tabela[][TERMINO] ){
  ordenar(lista);
  int i, j;
  for(i = 0; i < TERMINO ; i++){
    for(j = lista[i].inicio; j < lista[i].fim; j++)
      tabela[i][j] = 1;
  }
}

//complexidade Θ(n²)
void exibeTabela(No lista[], int tabela[][TERMINO]){
  int i,j;

  printf("\t\t");
  for(i = 0; i < TERMINO; i++){
    printf("%2d ",  i);
  }
  printf("\n");
  for(i = 0; i< ATIVIDADES; i++){
    printf("Atividade : %c | ", lista[i].name );
    for(j = 0; j< TERMINO; j++){
      if (tabela[i][j])
        printf(" X ");
      else
        printf(" 0 ");
    }
    printf("\n");
  }

}

//complexidade Θ(n²)
void ordenar(No lista[]){
  int i, j;
  No temp;
  for ( i = 0; i < ATIVIDADES; i++) {
    for (j = 0; j < ATIVIDADES; j++) {
      if (lista[i].fim < lista[j].fim) {
        temp = lista[i];
        lista[i] = lista[j];
        lista[j] = temp;
      }
    }
  }
}

int listaSolucao(No lista[]){
  int i;
  int ultimaSelecionada = 0;
  int selecionadas = 0;

  if (ATIVIDADES == 0)
    return 0;

  printf("%c ", lista[0].name );
  selecionadas++;

  for(i = 1; i < ATIVIDADES; i++){
    if (lista[i].inicio >= lista[ultimaSelecionada].fim) {
      printf("%c ", lista[i].name );
      selecionadas++;
      ultimaSelecionada = i;
    }

  }
}

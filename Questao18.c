#include <stdio.h>
#include <stdlib.h>

void multiplica(int **a, int **b, int **c, int linhasA, int colunasA, int colunasB){
  
  int termo;

  for(int i = 0; i < linhasA; i++) {
    for(int j = 0; j < colunasA; j++) {
      a[i][j]=rand() % 20;
    }
  }

  for(int i = 0; i < colunasA; i++) {
    for(int j = 0; j < colunasB; j++) {
      b[i][j]=rand() % 20;
    }
  }

  for(int i = 0; i < linhasA; i++) {
    for(int j = 0; j < colunasB; j++) {
      c[i][j]=0;
    }
  }

  for(int i = 0; i < linhasA; i++) {
    for(int j = 0; j < colunasB; j++) {
      termo = 0;

      for(int k = 0; k < colunasA; k++){
        termo += a[i][k] * b[k][j];
      }
      
      c[i][j] = termo;
    }
  }
}

int main() {
  int linhasA, colunasA, colunasB;
  int **a,**b, **c;

  printf("Linhas da matriz A: \n");
  scanf("%d",&linhasA);
  printf("Colunas da matriz A: \n");
  scanf("%d",&colunasA);
  printf("Colunas da matriz B: \n");
  scanf("%d",&colunasB);

  a = malloc(linhasA * sizeof (int*));
  b = malloc(colunasA * sizeof (int*));
  c = malloc(linhasA * sizeof (int*));

  for(int i=0; i < linhasA; i++){
    a[i] = malloc(colunasA * sizeof (int));
  }
  
  for(int i=0; i < colunasA; i++){
    b[i] = malloc(colunasB*sizeof (int));
  }

  for(int i=0; i < linhasA; i++){
    c[i] = malloc(colunasB*sizeof (int));
  }

  multiplica(a, b, c, linhasA, colunasA, colunasB);

  printf("\nMatriz A:\n");

  for(int i = 0; i < linhasA; i++) {
    for(int j = 0; j < colunasA; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz B:\n");
  for(int i = 0; i < colunasA; i++) {
    for(int j = 0; j < colunasB; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz C\n");

  for(int i = 0; i < linhasA; i++) {
    for(int j = 0; j < colunasB; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  free(a);
  free(b);
  free(c);

  return 0;
}

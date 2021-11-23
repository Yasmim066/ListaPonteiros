#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (float *a, float *b){  /*Funçao que compara os elementos de x e retorna para                                    a função qsort se os valores de a e b são iguais, a>b                                    ou a<b*/
 if ( *(float*)a == *(float*)b ){
      return 0;
    }else if (*(float*)a < *(float*)b ){
      return -1;
    }else{
      return 1;
    }
}

int main(void) {
  float *x; //Variável que guarda os valores inseridos pelo usuario
  int n; //Variável que armazena a quantidade de números que serão inseridos pelo usuário
  
  printf("Quantos números você deseja inserir? \n"); //Interação com o usuário
  scanf("%d",&n);
  
  x = malloc(n*sizeof(float)); //Define o tamanho de x
  
  
  for(int i=0;i<n;i++){     //Armazena os numeros inseridos em x
    printf("Insira o ");
    printf("%d",i+1);
    printf("ºnúmero\n");
    scanf("%f",&x[i]);
  }
  
  qsort(x,n,sizeof(float),(void *)compare); //Coloca os numeros em ordem crescente
      printf("\nOrdem crescente: ");
        for(int i=0;i<n;i++){ 
          printf("\n%f",x[i]);    //Imprime x após a ordenação
        }  
  free(x);

  return 0;
}
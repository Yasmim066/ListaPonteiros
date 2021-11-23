#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void minhaOrdenacao(int num){
  int comparador;

  int *numeros;
  numeros = malloc(num * sizeof(int));

  for(int i=0; i <= num; i++){
    numeros[i] = rand() % 100;
  }

  printf("Valores randomizados: \n");

  for(int i=0; i <= num; i++){
    printf("%d  ", numeros[i]);
  }

  for(int i=0; i <= num; i++){
    for(int j=0; j < num-i; j++){
      if(numeros[j] > numeros[j+1]){
        comparador = numeros[j+1];
        numeros[j+1] = numeros[j];
        numeros[j] = comparador;
      }
    }
  }

  printf("\nValores ordenados:\n");

  for(int i=0; i <= num; i++){
    printf("%d  ", numeros[i]);
  }
  free(numeros);
}

int compare (float *a, float *b){
  if ( *(float*)a == *(float*)b ){
      return 0;
  }else if (*(float*)a < *(float*)b ){
    return -1;
  }else{
    return 1;
  }
}

int main(){
  clock_t t = clock();
  int num;
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
  
  t = clock() - t;
  printf("\nTempo do qsort(): %lf \n", ((double)t)/((CLOCKS_PER_SEC/1000)));

  t = clock();  
  printf("Quantas comparações vão ser realizadas? \n");
  scanf("%d", &num);
 
  minhaOrdenacao(num);
  t = clock() - t;
  printf("\nTempo da função desenvolvida: %lf \n", ((double)t)/((CLOCKS_PER_SEC/1000)));

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

void ordenaVetor(int num){
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
int main(){
  int num;
    
  printf("Quantas comparações vão ser realizadas? \n");
  scanf("%d", &num);
 
  ordenaVetor(num);
  return 0;
}

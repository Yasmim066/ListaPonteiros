#include <stdio.h>
#include <stdlib.h>

void imprimeSomaVetores (float *vetor1, float *vetor2, float *soma,int tam){
  for(int i=0;i<tam;i++){
    soma[i] = vetor1[i] + vetor2[i];
  }
  
  printf("A soma dos vetores é: \n");

  for(int i=0;i<tam;i++){
    printf("%0.2f ", soma[i]);
  }
}


int main(void) {
  int tam;
	printf("Informe o tamanho dos vetores: ");
  scanf("%d",&tam);

  float *vetor1 = (float *) malloc(tam * sizeof(float));
  float *vetor2 = (float *) malloc(tam * sizeof(float));
  float *soma = (float *) malloc(tam * sizeof(float));
  float *a = (float *) malloc(tam * sizeof(float));
  
  printf("Informe os valores do vetor %d\n", 1);
  for(int i=0;i<tam;i++){
    printf("Valor %d:\n", i+1);
    scanf("%f", &vetor1[i]);
  }
  
  printf("Informe os valores do vetor %d\n", 2);
  for(int i=0;i<tam;i++){
    printf("Valor %d:\n", i+1);
    scanf("%f", &vetor2[i]);
  }
  printf("to chegando aqui: \n");

  imprimeSomaVetores(vetor1,vetor2,soma,tam);

  free(a);
  free(soma);
  free(vetor2);
  free(vetor1);

}
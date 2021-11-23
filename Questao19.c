#include "gc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  GC_INIT();

  float *x; 
  int n, a; 
  
  printf("Quantas posições terá o vetor? \n"); 
  scanf("%d",&n);
  
  x = (float*) GC_malloc_atomic(n*sizeof(float)); 
  printf("Digite o número que você deseja somar aos elementos do vetor \n");
  scanf("%d",&a);

  for(int i=0;i<n;i++){     
    printf("Insira o ");
    printf("%d",i+1);
    printf("ºnúmero\n");
    scanf("%f",&x[i]);
  }
  
  printf("Antes \n");  

  for(int i=0;i<n;i++){
    printf("%f ", x[i]);
  }

  for(int i=0;i<n;i++){     
    x[i] += a;
  }

  printf("Depois \n");

  for(int i=0;i<n;i++){
    printf("%f ", x[i]);
  }    
  
  GC_free(x);

  return 0;
}

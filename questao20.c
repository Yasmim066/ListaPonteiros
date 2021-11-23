#include "gc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void semColetor(){
 float *x;
 float aux;
 int n;
  printf("Quantos números você deseja inserir? \n");
 scanf("%d",&n);
  x = malloc(n*sizeof(float));
 
 for(int i=0;i<n;i++){
   printf("Insira o ");
   printf("%d",i+1);
   printf("ºnúmero\n");
   scanf("%f",&x[i]);
 }
 for( int i=0; i<n; i++ ){
   for( int j=i+1; j<n; j++ ){
      if( x[i] > x[j] ){
           aux = x[i];
           x[i] = x[j];
            x[j] = aux;
      }
    }
 }
     printf("Ordem crescente: \n");
       for(int i=0;i<n;i++){
         printf("\n%0.2f",x[i]);
       }
 
 free(x);
}

void comColetor(){
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

  printf("\nDepois \n");

  for(int i=0;i<n;i++){
    printf("%f ", x[i]);
  }    
  
  GC_free(x);
}


int main(void) {
  clock_t t = clock();
  
  semColetor();
  t = clock() - t;
  
  printf("\n%f segundos SEM O COLETOR DE LIXO\n", ((float)t)/CLOCKS_PER_SEC);

  t = clock();
  comColetor();  
  t = clock() - t;
  
  printf("\n%f segundos COM O COLETOR DE LIXO", ((float)t)/CLOCKS_PER_SEC);
  
  return 0;
}
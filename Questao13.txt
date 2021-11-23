#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {
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
         printf("\n%f",x[i]);
       }
 
 free(x);
 return 0;
}

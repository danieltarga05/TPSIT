#include <stdio.h>
#include <string.h>
#define MAX 100

void comuni (FILE *f1, FILE *f2, FILE *f3){
char P[MAX], S[MAX];
  int trovato=0,cont=0;
  f1=fopen("f1.txt", "r");
  f2=fopen("f2.txt", "r");
  f3=fopen("risultati.txt", "w");
  while (!feof(f1)){
    fscanf(f1, "%s", S);
    rewind(f2);
    trovato=0;
    while (!feof(f2)){
      fscanf(f2,"%s",P);
      if ((strcmp(S,P)==0)&& !trovato){ 
        cont++;
        printf("\nHo trovato \"%s\"!\n",P);
        trovato=1;
      }
    }
  } 
  printf("Le stringhe ripetute sono: %d",cont);
  fprintf(f3,"%d",cont);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  }

int main(){
  FILE *f1,*f2,*f3;
  comuni(f1,f2,f3);
  return 0;
}

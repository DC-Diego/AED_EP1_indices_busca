#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funcs.h"

// lower case:
// assumindo: s1 entre [A,Z] ou [a,z]
char * toLowerCase(char * s1){
  int i = 0;
  int n = strlen(s1);
  char * s2 = (char*) malloc(sizeof(char)*(n+1));
  while(i <= n){
    if(s1[i] >= 'A' && s1[i] <= 'Z') s2[i] = s1[i] +32;
    else s2[i] = s1[i];
    i++;
  }
  return s2;
}




// Consideremos que s1 e s2 sejam todos letras [a-z] e são todos letras minusculas.
int comparacaoString(char * s1, char * s2){ 
  if(s1 == NULL || s2 == NULL) return -5;
  int i = 0;
  while(s1[i] != '\0' && s2[i] != '\0'){
    if(s1[i]-s2[i] < 0) return -1; // s1 vem antes de s2: "a" antecede "b".
    if(s1[i]-s2[i] > 0) return 1; // s1 vem depois de s2: "b" depois de "a".
    i++;
  }  
  if(s1[i] == '\0' && s2[i] != '\0') return -1;// abc < abcc
  if(s1[i] != '\0' && s2[i] == '\0') return 1;// abcc > abc
  return 0; // são iguais.


}
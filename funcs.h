#ifndef FUNCS_H
#define FUNCS_H


char * toLowerCase(char * s1);
int comparacaoString(char * s1, char * s2);

typedef struct linhaNo{
  int linha;
  
  struct linhaNo * next;

} NoLinha;

NoLinha * criaLinhas();
int inserirLinhaLista(NoLinha * linhas, int linha);


#endif
#ifndef INDICELISTA_H
#define INDICELISTA_H

#include "funcs.h"

typedef struct linhaNo{
  int linha;
  
  struct linhaNo * next;

} NoLinha;

typedef struct palavraNo{
  char * palavra;
  NoLinha * linhas;
  struct palavraNo * next;
} NoPalavra;


NoLinha * criaLinhas();

NoPalavra * criaNo();

NoPalavra ** criaTabela();

int posicaoPalavraLista(char * palavra);

int inserirLinhaLista(NoLinha * linhas, int linha);

int inserirPalavraLista(NoPalavra**tabela, char*palavra, int linha, int * comp);

NoLinha * buscaLista(NoPalavra **tabela, char * palavra, int * qtdComp);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "indiceLista.h"


int tamanhoTabela = 26*4*4;




NoPalavra * criaNo(){
  NoPalavra * new = (NoPalavra*) malloc(sizeof(NoPalavra));
  new->linhas = criaLinhas();
  new->next = NULL;
  new->palavra = NULL;
  return new;
} 



NoPalavra ** criaTabela(){
 
  NoPalavra ** tabela = (NoPalavra**) malloc(sizeof(NoPalavra*)*tamanhoTabela);
  for (int i = 0; i < tamanhoTabela; i++)
  {
    tabela[i] = criaNo();
  }
  return tabela;
}


int posicaoPalavraLista(char *p){
  int id = 0;
  for (int i = 0; p[i] && i < 6; i++) {
    id = (id * 31 + (p[i] - 'a' + 1)) % tamanhoTabela;
  }
  return id;
}





int inserirPalavraLista(NoPalavra**tabela, char*palavra, int linha, int * comp){
  int qtd = 0;

  int id = posicaoPalavraLista(palavra);
  NoPalavra * anterior = tabela[id];
  NoPalavra * p = anterior->next;
  int c;
  while(p && (c = comparacaoString(palavra, p->palavra)) != 1){
    qtd++;
    if(c == 0){
      *comp += qtd; 
      return inserirLinhaLista(p->linhas, linha);
    }else{
      anterior = p;
      p = p->next;
    }
  }

  NoPalavra * new = criaNo();
  new->palavra = palavra;
  new->next = anterior->next;
  anterior->next = new;
  *comp += qtd;
  return inserirLinhaLista(new->linhas, linha);
}





NoLinha * buscaLista(NoPalavra **tabela, char * palavra, int * qtdComp){
  int qtd = 0;
  int id = posicaoPalavraLista(palavra);
  NoPalavra * p = tabela[id]->next;
  while(p){
    qtd++;
    if(comparacaoString(palavra, p->palavra) == 0){
      *qtdComp = qtd;
      return p->linhas;
    } 
    p = p->next;
  }
  *qtdComp = qtd;
  return NULL;
}
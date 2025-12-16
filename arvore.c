#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


NoArvore* criaNoArvore(char * palavra){
    NoArvore * novo = (NoArvore*)malloc(sizeof(NoArvore));
    novo->palavra = palavra;
    novo->linhas = criaLinhas();
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

int insereNoArvore(NoArvore **raiz, char *palavra, int linha, int * comp){
    if(*raiz == NULL){
        *raiz = criaNoArvore(palavra);
        inserirLinhaLista((*raiz)-> linhas, linha);
        return 1;
    }

    (*comp)++;

    int res = comparacaoString(palavra, (*raiz)->palavra);

    if (res ==0){
        inserirLinhaLista((*raiz)->linhas,linha);
        return 0;
    }

    else if(res < 0){
        return insereNoArvore(&(*raiz)->esq, palavra, linha, comp);
    }
    else{
        return insereNoArvore(&(*raiz)->dir, palavra, linha, comp);
    }
}

NoLinha* buscarnoArvore(NoArvore *raiz, char * palavra, int * comp){
    if(raiz == NULL){
        return NULL;
    }

    (*comp)++;
    int res = comparacaoString(palavra, raiz->palavra);

    if (res == 0 ){
        return raiz->linhas;
    }
    else if(res < 0){
        return buscarnoArvore(raiz->esq, palavra, comp);
    }
    else {
        return buscarnoArvore(raiz->dir, palavra, comp);
    }
}

int calcularAltura(NoArvore * raiz){
    if (raiz == NULL) return -1;

    int Esq = calcularAltura(raiz->esq);
    int Dir = calcularAltura(raiz->dir);

    if (Esq > Dir){
        return Esq + 1;
    }
    else {
        return Dir + 1;
    }
}

void liberaArvore(NoArvore * raiz){
    if(raiz != NULL){
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);

        free(raiz);
    }



}
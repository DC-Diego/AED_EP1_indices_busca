#ifndef ARVORE_H
#define ARVORE_H

#include "indiceLista.h"
#include "funcs.h"

typedef struct noArvore
{
    char *palavra;
    NoLinha * linhas;
    struct noArvore * esq;
    struct noArvore * dir;
} NoArvore;

NoArvore * criaNoArvore(char * palavra);
int insereNoArvore(NoArvore ** raiz, char * palavra, int linha, int * comp);
NoLinha* buscarnoArvore(NoArvore * raiz, char * palavra, int * comp);
int calcularAltura (NoArvore * raiz);
void liberaArvore (NoArvore * raiz);


#endif

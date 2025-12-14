#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "indiceLista.h"
#define TAMANHO 10000


int tipoLista = 0;
int alturaArvore = 0;
NoPalavra ** tabela;
char ** linhas;

int qtdLinhas(char * nomeArq);
int inserirIndice(char * palavra, int linha, int * qtdComp);
NoLinha * buscarIndice(char * palavra, int * qtdComp);

int commandLine(){
  while(1){
    char linha[100];
    char cmd[20];
    char palavra[80];
    printf("> ");
    if (!fgets(linha, sizeof(linha), stdin))
        break;  

    int n = sscanf(linha, "%s %s", cmd, palavra);
    if(comparacaoString(toLowerCase(cmd), "fim")==0){
     break;
    }
    if(comparacaoString(toLowerCase(cmd), "busca")==0 && n ==2){
      int comp = 0;
      NoLinha * buscaResult = buscarIndice(palavra, &comp);
      if(buscaResult == NULL){
        printf("Palavra '%s' nao encontrada.\n", palavra);
      }else{
        printf("Existem %d ocorrencias da palavra '%s' na(s) seguinte(s) linha(s):\n", buscaResult->linha, palavra);
        NoLinha * p = buscaResult->next;
        while(p){
          printf("%05d: %s", p->linha, linhas[p->linha-1]);
          p = p->next;
        }
      }
      printf("Numero de comparacoes: %d\n", comp);
    }else{
      printf("Opcao invalida!\n");
    } 
  }
  return 1;

}



int main(int argc, char ** argv){
  FILE * arquivo;
  
  if(argc == 3){
    arquivo = fopen(argv[1], "r");
    if(arquivo == NULL){
      printf("Não foi possivel abrir o arquivo: '%s'\n", argv[1]);
    }else{
      printf("Arquivo: '%s'\n", argv[1]);
    }

    if(comparacaoString(toLowerCase(argv[2]), "lista") == 0){
      tipoLista = 1;
      printf("Tipo de indice: 'lista'\n");
    }else if(comparacaoString(toLowerCase(argv[2]), "arvore") == 0){
      tipoLista = 0;
      printf("Tipo de indice: 'arvore'\n");
    }else{
      printf("Erro, tipo de indice '%s' nao disponivel.\nOs tipos de indice disponiveis sao: lista ou arvore \n", argv[2]);
    }

  }
  else{
    printf("Erro, faltam parametros para a execucao, abra o arquivo com o seguinte formato: \n'./ep [arquivo.txt] [tipo_estrutura]'\n");
    return 1;
  }


  int qtdLinha = qtdLinhas(argv[1]);

  printf("Numero de linhas no arquivo: %d\n", qtdLinha);

  linhas = (char**) malloc(sizeof(char*)*qtdLinha);

  for (int i = 0; i < qtdLinha; i++)
  {
    linhas[i] = malloc(TAMANHO);
    fgets(linhas[i], TAMANHO, arquivo);
  }
  fclose(arquivo);
  if(tipoLista == 1){
    tabela = criaTabela();
  }
  int palavrasUnicas = 0;
  int comp = 0;
  for (int i = 0; i < qtdLinha; i++)
  {
    char c;
    char palavra[100];
    palavra[0] = '\0';
    int contador = 0;
    int j = 0;

    while((c = linhas[i][j]) != '\0'){
      if((c>='a' && c <= 'z') || (c>='A' && c <= 'Z') ){
        palavra[contador] = c;
        contador++;
      }else if(contador){
        
        palavra[contador] = '\0';
        palavrasUnicas += inserirIndice( palavra, i+1, &comp);
        contador = 0;
      }
      j++;
    }
    if(contador && palavra[contador-1] != '\0'){
      palavra[contador] = '\0';
      palavrasUnicas += inserirIndice(palavra, i+1, &comp);
    }
    
  }

  printf("Total de palavras unicas indexadas: %d\n", palavrasUnicas);
  if(!tipoLista) printf("Altura da arvore: %d\n", alturaArvore);
  printf("Numero de comparacoes realizadas para a construcao do indice: %d\n", comp);

  commandLine();

  return 0;

}

int qtdLinhas(char * nomeArq){
  FILE * arquivo = fopen(nomeArq, "r");
  if(arquivo == NULL){
    printf("\nErro ao abrir o arquivo: %s\n", nomeArq);
    return -1;
  }

  int qtd = 0;
  int c;
  char lastVal = '\n';
  while((c = fgetc(arquivo))!=EOF){
    if((char)c=='\n')qtd++;
    lastVal = (char) c;
  }
  if(lastVal!='\n')qtd++;
  fclose(arquivo);
  return qtd;
}

int inserirIndice(char * palavra, int linha, int * qtdComp){
  if(tipoLista){
    
    return inserirPalavraLista(tabela, toLowerCase(palavra), linha, qtdComp);
  }else{
    printf("INSERIR ARVORE");
  }
}

NoLinha * buscarIndice(char * palavra, int * qtdComp){
  if(tipoLista){
    return buscaLista(tabela, palavra, qtdComp);


  }else{
    printf("BUSCAR ARVORE");
  }


}




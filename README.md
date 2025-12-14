# AED_EP1_indices_busca
EP1 de AED, indices busca de palavras por indices do tipo arvore binária de busca (bst) ou listas (lista ligada ou lista sequencial)

arquivo funcs.h:
  possui funções de strings que serão uteis para comparações de strings e transformações de strings:
    int comparacaoString(char * s1, char * s2)
      compara quais strings vem antes da outra retornando:
      -1 se s1 vem antes de s2
      0 se s1 e s2 são as mesmas strings
      1 se s1 vem depois de s2
      -5 se s1 ou s2 são nulas.
    
    char * toLowerCase(char * s1)
      transforma uma string totalmente em letras minusculas


  Essas funções são usadas para ordenar as strings para facilitar a ordenação e busca de strings, tais como para considerar palavras maiusculas como minusculas: SET === set === Set ....

arquivo indiceLista.h:
  Possui funções, structs focadas em listas, usadas para montar as listas e melhorar a eficiência do algoritmo:

  typedef struct linhaNo//NoLinha:  
    Usada como lista ligada para armazenar de forma ordenada as linhas que uma determinada palavras aparece, com o objetivo de diminuir a quantidade de espaço para armazenar palavras e melhor eficiencia nas buscas por palavras no indice.
  
  typedef struct palavraNo//NoPalavra:
    usada como lista ligada para armazenar as palavras de maneiras ordenada usando as funções de comparações de strings, utiliza o primeiro nó que aponta para a lista-ligada de linhas como cabeça e contador de ocorrencias dessa palavra no arquivo.

  NoPalavra ** criaTabela():
    Tabela com tamanho fixo e pré-definido onde usaremos uma função do "hashing" com o objetivo de aumentar a eficiencia da operação de busca (que é a operação principal do ep), a operação de inserção e espalhar as palavras.

  int posicaoPalavraLista(char * palavra):
    Função Hashing que multiplica e soma as 6 primeiras letras (se existirem) e retorna a posição em que a palavra deve ser inserida ou está na tabela.

  int inserirPalavraLista(NoPalavra**tabela, char*palavra, int linha, int * comp):
    Usa as funções de comparação de string e hashing para localizar a posição em que a palavra deve entrar na tabela, ordena-la, além de contar o número de comparações (pois iremos retornar o número de comparações necessárias para montar o indice).

  int inserirLinhaLista(NoLinha * linhas, int linha):
    Ao insere as linhas que a palavra aparece na lista ligada de maneira ordenada.

  NoLinha * buscaLista(NoPalavra **tabela, char * palavra, int * qtdComp):
    Utiliza a função de hashing para aumentar a eficiência da busca e retorna a lista ligada das linhas da palavra encontrada (retorna a cabeça também pois possui o número de ocorrencias da palavra)




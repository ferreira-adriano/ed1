#include <stdio.h>
#include <stdlib.h>
#define InicioArranjo   1
#define MaxTam          1000


typedef int TipoChave;

typedef int Apontador;

typedef char NomeItem[20];

typedef struct {
  TipoChave Chave;
  NomeItem nome;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MaxTam];
  Apontador Primeiro, Ultimo;
} TipoLista;

void verifica_ordem(TipoLista Lista);
TipoLista copiaLista(TipoLista Lista);
TipoLista copiaSemRepeticao(TipoLista lista);
TipoLista copiaListaInvertida(TipoLista lista);
void inverteLista(TipoLista *Lista);
TipoLista intercalarLista(TipoLista Lista1, TipoLista Lista2);

void FLVazia(TipoLista *Lista);
int LEhVazia(TipoLista Lista);
void LInsere(TipoItem x, TipoLista *Lista);
void LRetira(Apontador p, TipoLista *Lista, TipoItem *Item);
void LImprime(TipoLista Lista);
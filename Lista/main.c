#include <stdio.h>
#include <stdlib.h>
#include "arranjo.h"

int main(int argc, char *argv[])
{

  TipoLista lista;
  TipoItem item;
  int vetor[MaxTam];
  NomeItem nomes[MaxTam];
  int i, j, n, ver_vazia, op;

  do
  {
    printf("\n\n------------MENU------------");
    printf("\nCriar Lista (1)");
    printf("\nImprimir Lista (2)");
    printf("\nRemover Item (3)");
    printf("\nVerificar se a Lista está vazia (4)");
    printf("\nVerificar ordem (5)");
    printf("\nCopiar Lista (6)");
    printf("\nCopiar Lista sem elementos repetidos (7)");
    printf("\nCopiar Lista invertida (8)");
    printf("\nIntercalar Listas (9)");
    printf("\nSair (0)");
    printf("\n\nOpção: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      //Cria Lista
      FLVazia(&lista);
      printf("\nEntre com o numero de elemento na lista: \n");
      scanf("%d", &n);

      /*Lendo o vetor[i] */
      for (i = 0; i < n; i++)
      {
        printf("\nEntre com o nº do item: ");
        scanf("%d", &vetor[i]);
        printf("\nEntre com o nome do item: ");
        scanf("%s", nomes[i]);
      }

      for (i = 0; i < n; i++)
      {
        item.Chave = vetor[i];
        strcpy(item.nome, nomes[i]);
        LInsere(item, &lista);
      }

      printf("\nLista criada com sucesso!");
      break;

    case 2:
      //Imprime Lista
      printf("\nImprimindo a lista digitada. \n");
      LImprime(lista);
      break;

    case 3:
      //Remove Item
      printf("\nRemovendo um elemento da lista (se existir) ");

      /*Retira cada chave da lista */

      /*lendo o elemento escolhido para remocao pelo usuario  */
      printf("\nQual eh a posicao do elemento a ser removido ? \n");
      scanf("%d", &j);
      /*retira chave apontada */
      LRetira(j, &lista, &item);
      if (j <= lista.Ultimo)
        printf("\nRetirou o elemento %d que esta na posicao: %d da lista.\n", item.Chave, j);
      break;

    case 4:
      //Verificar se a lista está vazia
      printf("\nVerificando se a lista esta vazia.\n");
      ver_vazia = LEhVazia(lista);
      if (ver_vazia == 1) // 1 eh verdade
        printf("\nA lista esta vazia.\n");
      else
        printf("\nA lista nao esta vazia.\n");
      break;

    case 5:
      //Verificar se a lista está ordenada
      verifica_ordem(lista);
      break;

    case 6:
      //Copiar Lista
      printf("\nCopiando a lista L1 para a lista L2.\n");
      TipoLista lista2;
      lista2 = copiaLista(lista);
      LImprime(lista2);
      break;

    case 7:
      //Copiar Lista sem repetições
      printf("\nCopiando a lista L1 para a lista L2 sem elementos repetidos.\n");
      lista2 = copiaSemRepeticao(lista);
      LImprime(lista2);
      break;

    case 8:
      //Copiar Lista invertida
      printf("\nCopiando a lista L1 invertida para a lista L2\n");
      lista2 = copiaListaInvertida(lista);
      LImprime(lista2);
      printf("\nInvertendo L1\n");
      inverteLista(&lista);
      LImprime(lista);
      inverteLista(&lista);
      break;

    case 9:
      //Intercalar lista
      printf("\nIntercalando lista 1 e lista 2\n");
      TipoLista lista3;
      lista3 = intercalarLista(lista, lista2);
      LImprime(lista3);
      return (0);
      break;

    default:
      printf("\nOpção Inválida");
      break;
    }

  } while (op != 0);

  return 0;
}
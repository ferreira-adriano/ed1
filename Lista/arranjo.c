#include <stdio.h>
#include <stdlib.h>
#include "arranjo.h"

void verifica_ordem(TipoLista Lista)
{
    int n = Lista.Ultimo - 1;
    int decrescente = 0;
    int crescente = 0;
    int k, j, aux;
    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - k; j++)
        {

            if (Lista.Item[j].Chave <= Lista.Item[j + 1].Chave)
                decrescente = 1;

            if (Lista.Item[j].Chave >= Lista.Item[j + 1].Chave)
                crescente = 1;
        }
    }
    if (decrescente == 0)
    {
        printf("\nLista descrescente\n");
    }
    if (crescente == 0)
    {
        printf("\nLista crescente\n");
    }
    if ((decrescente == 1) && (crescente == 1))
    {
        printf("\nLista não ordenada em crescente ou descrescente\n");
    }
}

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
} /* FLVazia */

int LEhVazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
} /* Vazia */

void LInsere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo > MaxTam)
        printf("Lista esta cheia\n");
    else
    {
        Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo++;
    }
} /* Insere */

void LRetira(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if (LEhVazia(*Lista) || p >= Lista->Ultimo)
    {
        printf(" Erro   Posicao nao existe\n");
        return;
    }
    *Item = Lista->Item[p - 1];
    Lista->Ultimo--;
    for (Aux = p; Aux < Lista->Ultimo; Aux++)
        Lista->Item[Aux - 1] = Lista->Item[Aux];
} /* Retira */

void LImprime(TipoLista Lista)
{
    int Aux;

    for (Aux = Lista.Primeiro - 1; Aux <= (Lista.Ultimo - 2); Aux++)
        printf("%d\n", Lista.Item[Aux].Chave);
} /* Imprime */

TipoLista copiaLista(TipoLista Lista)
{
    TipoLista novaLista;
    TipoItem novoItem;
    int vetor[MaxTam];
    int i;

    FLVazia(&novaLista);
    /*Copia cada chave na nova lista */

    for (i = Lista.Primeiro - 1; i <= (Lista.Ultimo - 2); i++)
    {
        novoItem.Chave = Lista.Item[i].Chave;
        LInsere(novoItem, &novaLista);
    }

    return novaLista;
}

TipoLista copiaSemRepeticao(TipoLista Lista)
{
    //os elementos não podem ser repetidos em L1 e L2, ou, caso L1 possua elementos repetidos,
    //eles devem ser copiados apenas uma vez?

    TipoLista novaLista;
    TipoItem novoItem;
    int aux, b = 0;
    int i, j;

    FLVazia(&novaLista);
    /*Copia cada chave na nova lista */

    for (i = Lista.Primeiro - 1; i <= (Lista.Ultimo - 2); i++)
    {
        b = 0;
        aux = Lista.Item[i].Chave;

        for (j = i + 1; j <= (Lista.Ultimo - 2); j++)
        {
            if (aux == Lista.Item[j].Chave)
            {
                b = 1;
            }
        }
        if (b == 0)
        {
            novoItem.Chave = Lista.Item[i].Chave;
            LInsere(novoItem, &novaLista);
        }
    }

    printf("\nImprmindo a lista copiada sem elementos repetidos. \n");
    return novaLista;
}

TipoLista copiaListaInvertida(TipoLista Lista)
{
    TipoLista novaLista;
    TipoItem novoItem;
    int vetor[MaxTam];
    int i, j = 0;

    FLVazia(&novaLista);

    for (i = (Lista.Ultimo - 2); i >= Lista.Primeiro - 1; i--)
    {
        novoItem.Chave = Lista.Item[i].Chave;
        LInsere(novoItem, &novaLista);
    }

    printf("\nImprmindo a lista L2 invertida. \n");
    return novaLista;
}

void inverteLista(TipoLista *Lista)
{
    TipoLista listaCopia = copiaLista(*Lista);

    TipoItem novoItem;

    FLVazia(&Lista);
    int i, j = 0;
    for (i = (listaCopia.Ultimo - 2); i >= listaCopia.Primeiro - 1; i--)
    {
        novoItem.Chave = listaCopia.Item[i].Chave;
        Lista->Item[j] = novoItem;
        j++;
    }

    printf("\nImprmindo a lista L1 invertida. \n");
}

TipoLista intercalarLista(TipoLista Lista1, TipoLista Lista2)
{

    TipoLista lista3;
    TipoItem novoItem;

    FLVazia(&lista3);
    int i;
    /*Copia cada chave na nova lista */

    for (i = Lista1.Primeiro - 1; i <= (Lista1.Ultimo - 2); i++)
    {
        
        novoItem.Chave = Lista1.Item[i].Chave;
        LInsere(novoItem, &lista3);
        novoItem.Chave = Lista2.Item[i].Chave;
        LInsere(novoItem, &lista3);
    }
    return lista3;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO R[MAX];
    int numElem;
} LISTA;

void inicializaLista(LISTA *l)
{
    l->numElem = 0;
}

int tamanho(LISTA *l)
{
    return l->numElem;
}

void exibirLista(LISTA *l)
{
    int i;
    printf("Lista: \"\n");

    for (i = 0; i < l->numElem; i++)
    {
        printf("%i\n", l->R[i].chave);
    }

    printf("\"\n");
}

int buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
    int i;
    while (i < l->numElem)
    {
        if (ch == l->R[i].chave)
            return i;
        else
            i++;
    }
    return -1;
}

bool inserirElemLista(LISTA *l, REGISTRO registro, int posicao)
{
    int i;
    //é valido a posição?
    if (l->numElem == MAX || posicao < 0 || posicao > l->numElem)
        return false;

    for (i = l->numElem; i > posicao; i--)
        l->R[i] = l->R[i - 1];

    l->R[i] = registro;
    l->numElem++;
    return true;
}

bool removerElemLista(LISTA *l, TIPOCHAVE index)
{
    int pos, j;
    pos = buscaSequencial(l, index);
    if (pos == -1)
        return false;

    for (j = pos; j < l->numElem - 1; j++)
        l->R[j] = l->R[j + 1];

    return true;
}

int main()
{
    LISTA *l = (LISTA *)malloc(sizeof(LISTA));

    REGISTRO *r1 = (REGISTRO *)malloc(sizeof(REGISTRO));
    r1->chave = 100;

    REGISTRO *r2 = (REGISTRO *)malloc(sizeof(REGISTRO));
    r2->chave = 200;

    REGISTRO *r3 = (REGISTRO *)malloc(sizeof(REGISTRO));
    r3->chave = 300;

    inserirElemLista(l, *r3, 1);

    l->numElem = 2;
    l->R[0] = *r1;
    l->R[1] = *r2;

    exibirLista(l);
    inserirElemLista(l, *r3, 1);
    exibirLista(l);

    return 0;
}
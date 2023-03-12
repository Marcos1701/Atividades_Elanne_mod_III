
//Integrantes do grupo:
// - Daniel Luca
// - Marcos Eduardo
// - Gabriel
// - Gabriela
// - Gilderlane 
// - Israel
//Representante: Marcos Eduardo

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct arv
{
    char info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv *arvore(char x, Arv *e = NULL, Arv *d = NULL)
{
    Arv *novo = (Arv *)malloc(sizeof(Arv));
    novo->esq = e;
    novo->dir = d;
    novo->info = x;
    return novo;
}

void imprime(Arv *n)
{

    if (n != NULL)
    {

        cout << "<" << n->info;
        imprime(n->esq);
        imprime(n->dir);
        cout << ">";
    }
    else
        cout << "<>";
    return;
}

int calculaQuantNos(Arv *no)
{
    int qtd = 0;
    if (no != NULL)
    {
        qtd++;
        qtd += calculaQuantNos(no->esq);
        qtd += calculaQuantNos(no->dir);
    }
    return qtd;
}

int calculaQuantNosFolha(Arv *no)
{
    if (no == NULL)
    {
        return 0;
    }
    else if (no->dir == NULL && no->esq == NULL)
    {
        return 1;
    }

    return calculaQuantNosFolha(no->esq) + calculaQuantNosFolha(no->dir);
}

int alturaArvore(Arv *no)
{
    if (no == NULL)
    {
        return 0;
    }
    int esq = alturaArvore(no->esq);
    int dir = alturaArvore(no->dir);
    if (esq > dir)
    {
        return esq + 1;
    }
    return dir + 1;
}

Arv *procura(Arv *no, char valor)
{
    if (no == NULL)
    {
        return NULL;
    }
    if (no->info == valor)
    {
        return no;
    }
    Arv *retorno = procura(no->esq, valor);
    if (retorno)
    {
        return retorno;
    }
    return procura(no->dir, valor);
}

int libera_arvore(Arv *no)
{
    if (no == NULL)
    {
        return 0;
    }
    libera_arvore(no->esq);
    libera_arvore(no->dir);
    free(no);
    return 1;
}

// remove o nó procurado. Se o nó tiver filhos, remova também os filhos
int removeSubArvore(Arv *no, char valor)
{
    if (no == NULL)
    {
        return 0;
    }
    if (no->dir->info == valor)
    {
        libera_arvore(no->dir);
        no->dir = NULL;
        return 1;
    }
    else if (no->esq->info == valor)
    {
        libera_arvore(no->esq);
        no->esq = NULL;
        return 1;
    }
    int retorno = removeSubArvore(no->esq, valor);
    if (retorno)
    {
        return retorno;
    }
    return removeSubArvore(no->dir, valor);
}

main()
{

    Arv *c = arvore('c',
                    arvore('g',
                           arvore('d'), arvore('y')),
                    arvore('k',
                           arvore('t'), arvore('m')));

    cout << "\nArvore antes da remocao de k: " << endl;
    imprime(c);
    cout << "\n Qtd nos: " << calculaQuantNos(c);

    if (removeSubArvore(c, 'k'))
    {
        cout << "\n\nNo removido com sucesso, Arvore apos a remocao:"
             << endl;
        imprime(c);
        cout << "\n Qtd atual de nos: " << calculaQuantNos(c);
    }
    else
    {
        cout << "\nOps, o no nao foi encontrado..." << endl;
    }
}

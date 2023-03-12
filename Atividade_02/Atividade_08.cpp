
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


int ArvBinariaCheia(Arv *no){
    if (no == NULL)
    {
        return 1;
    }
    if (no->esq == NULL && no->dir == NULL)
    {
        return 1;
    }
    if (no->esq == NULL || no->dir == NULL)
    {
        return 0;
    }
    return ArvBinariaCheia(no->esq) && ArvBinariaCheia(no->dir);
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
    Arv *x = arvore('x',
                    arvore('h', NULL, arvore('y', arvore('k'))),
                    arvore('e',
                           arvore('w')));
    cout << "Arvore 'c': " << endl;
    imprime(c);

    cout << "\nArvore 'x': " << endl;
    imprime(x);

    if (ArvBinariaCheia(c, alturaArvore(c)))
        cout << endl
             << "\nA Arvore Binaria 'c' esta Cheia" << endl;
    else
        cout << endl
             << "\nOps, a Arvore Binaria 'c' nao esta Cheia" << endl;

    if (ArvBinariaCheia(x, alturaArvore(x)))
        cout << endl
             << "\nA Arvore Binaria 'x' esta Cheia" << endl;
    else
        cout << endl
             << "\nOps, a Arvore Binaria 'x' nao esta Cheia" << endl;
}

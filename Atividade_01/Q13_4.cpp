#include <iostream>
#include <stdlib.h>

using namespace std;

// Arvore versão struct

struct Arv
{
    int valor;
    Arv *esq;
    Arv *dir;
};

Arv *Cria_arv(int valor, Arv *esq, Arv *dir)
{
    Arv *New_arv = (Arv *)malloc(sizeof(Arv));
    New_arv->valor = valor;
    New_arv->esq = esq;
    New_arv->dir = dir;

    return New_arv;
}

int altura(Arv *arv)
{
    if (arv == NULL)
    {
        return 0;
    }
    int esq = altura(arv->esq);
    int dir = altura(arv->dir);
    if (esq > dir)
    {
        return esq + 1;
    }
    else
    {
        return dir + 1;
    }
}

int main()
{
    Arv *x = Cria_arv(1,
                      Cria_arv(3,
                               Cria_arv(2, NULL, NULL), Cria_arv(2, NULL, NULL)),
                      Cria_arv(6,
                               Cria_arv(0, NULL, NULL), NULL));

    int alt = altura(x);

    cout << "Altura: " << alt << endl;
}

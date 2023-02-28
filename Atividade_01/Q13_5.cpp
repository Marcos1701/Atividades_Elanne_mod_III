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

int tem(Arv *arv, int item)
{
    if (arv == NULL)
    {
        return 0;
    }
    // int esq, dir;
    if (arv->valor == item)
    {
        return 1;
    }
    // esq = tem(arv->esq, item);
    // dir = tem(arv->dir, item);

    return (tem(arv->esq, item) || tem(arv->dir, item));
}

int main()
{
    Arv *x = Cria_arv(1,
                      Cria_arv(3,
                               Cria_arv(2, NULL, NULL), Cria_arv(2, NULL, NULL)),
                      Cria_arv(6,
                               Cria_arv(0, NULL, NULL), NULL));

    int alt = tem(x, 6);
    if (alt)
    {
        cout << "O valor esta presente na arvore!!" << endl;
    }
    else
    {
        cout << "O valor nao esta presente na arvore" << endl;
    }
}

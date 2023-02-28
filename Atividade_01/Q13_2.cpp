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

int nos(Arv *arvore)
{
    int qtd = 0;
    if (arvore != NULL)
    {
        qtd++;
        qtd += nos(arvore->esq);
        qtd += nos(arvore->dir);
    }

    return qtd;
}

int main()
{
    Arv *x = Cria_arv(1,
                      Cria_arv(3,
                               Cria_arv(2, NULL, NULL), Cria_arv(2, NULL, NULL)),
                      Cria_arv(6,
                               Cria_arv(0, NULL, NULL), NULL));
                               

    int qtd = nos(x);

    cout << "Qtd nos: " << qtd << endl;
}

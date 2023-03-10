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

int eb(Arv *a){
    if(a->dir && a->esq){
        return (eb(a->dir) && eb(a->esq));
    }else if(a->dir == NULL && a->esq == NULL){
        return 1;
    }else{
        return 0;
    }
}

void imprime(Arv *raiz){
    if(raiz != NULL){
        
        cout << " < " << raiz->valor;
        imprime(raiz->esq);
        imprime(raiz->dir);
        cout << " >";

    }else{
        cout << " <> ";
    }
}


int main()
{
    Arv *x = Cria_arv(1,
                      Cria_arv(3,
                               Cria_arv(2, NULL, NULL), Cria_arv(2, NULL, NULL)),
                      Cria_arv(6,
                               Cria_arv(0, NULL, NULL), Cria_arv(7, NULL, NULL)));

    int alt = eb(x);
    imprime(x);

    if (alt)
    {
        cout << "\n\nA arvore é estritamente binaria!!" << endl;
    }
    else
    {
        cout << "\n\nA arvore nao é estritamente binaria!!" << endl;
    }
}

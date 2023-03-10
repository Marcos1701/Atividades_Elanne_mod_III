#include <iostream>
#include <stdlib.h>
#include "Q13_7.h"

using namespace std;

// Arvore versão struct

struct Arv
{
    int valor;
    Arv *esq;
    Arv *dir;
};

Arv *Cria_arv(int valor, Arv *esq = NULL, Arv *dir = NULL)
{
    Arv *New_arv = (Arv *)malloc(sizeof(Arv));
    New_arv->valor = valor;
    New_arv->esq = esq;
    New_arv->dir = dir;

    return New_arv;
}

Arv *exibe_dec(Arv *A){
    Arv *esq;
    Arv *dir;
    if(A->esq){
        esq = exibe_dec(A->esq);
    }
    if(A->dir){
        dir = exibe_dec(A->dir);
    }
    Arv *dec;
    if(esq->valor > dir->valor){
        dec->valor = esq
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
                               Cria_arv(2), Cria_arv(2)),
                      Cria_arv(6,
                               Cria_arv(0), Cria_arv(7)));


}

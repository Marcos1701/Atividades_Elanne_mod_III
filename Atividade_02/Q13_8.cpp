#include <iostream>
#include <stdlib.h>

using namespace std;

// Arvore versão struct

struct Arv
{
    char valor;
    Arv *esq;
    Arv *dir;
};

Arv *Cria_arv(char valor, Arv *esq = NULL, Arv *dir = NULL)
{
    Arv *New_arv = (Arv *)malloc(sizeof(Arv));
    New_arv->valor = valor;
    New_arv->esq = esq;
    New_arv->dir = dir;

    return New_arv;
}

int valor(Arv *A)
{
    if (A == NULL)
    {
        return 1;
    }
    if (A->dir == NULL && A->esq == NULL)
    {
        return isdigit(A->valor);
    }
    return (valor(A->dir) && (A->esq));
}

void imprime(Arv *raiz)
{
    if (raiz != NULL)
    {

        cout << " < " << raiz->valor;
        imprime(raiz->esq);
        imprime(raiz->dir);
        cout << " >";
    }
    else
    {
        cout << " <> ";
    }
}

int main()
{
    Arv *x = Cria_arv('*',
                      Cria_arv('/',
                               Cria_arv('+', Cria_arv('5'), Cria_arv('3')), Cria_arv('4')),
                      Cria_arv('-',
                               Cria_arv('6'), Cria_arv('-')));
    int aux = valor(x);
    cout << "Arv X: " << endl;
    imprime(x);


    if (aux)
    {
        cout << "\n\nA Espressao e valida!!" << endl;
    }
    else
    {
        cout << "\n\nA Espressao nao e valida!!" << endl;
    }
}

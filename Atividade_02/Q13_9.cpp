#include <iostream>
#include <stdlib.h>
#include <vector>

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

void ordena_vetor_decrescente(vector<int> &v)
{ // bubble sort
    int aux, tam = v.size(), k = 1;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam - k; j++)
        {
            if (v[j] >= v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        k++;
    }
}

void obter_valores_arv(Arv *A, vector<int> &v)
{
    if (A != NULL)
    {
        obter_valores_arv(A->esq, v);
        v.push_back(A->valor);
        obter_valores_arv(A->dir, v);
    }
}

void exibe_dec(Arv *raiz)
{
    vector<int> v;
    obter_valores_arv(raiz, v);
    ordena_vetor_decrescente(v);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
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
    Arv *x = Cria_arv(1,
                      Cria_arv(3,
                               Cria_arv(2), Cria_arv(2)),
                      Cria_arv(6,
                               Cria_arv(0), Cria_arv(7)));

    exibe_dec(x);
}

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

void intercala(vector<int> &vetor, int inicio, int meio, int fim)
{
    int w[int((fim - inicio) + 1)];
    int i = inicio, m = meio + 1, k = 0;
    while (i <= meio && m <= fim)
        if (vetor[i] >= vetor[m])
            w[k++] = vetor[i++];
        else
            w[k++] = vetor[m++];

    while (i <= meio)
        w[k++] = vetor[i++];
    while (m <= fim)
        w[k++] = vetor[m++];
    for (k = 0; k <= fim - inicio; k++)
        vetor[inicio + k] = w[k];
}

void ordena_vetor_decrescente(vector<int> &v, int inicio, int fim)
{ // merge sort
    if (inicio >= fim)
        return;
    int meio = int((inicio + fim) / 2);
    ordena_vetor_decrescente(v, inicio, meio);
    ordena_vetor_decrescente(v, meio + 1, fim);
    intercala(v, inicio, meio, fim);
}

// void ordena_vetor_decrescente(vector<int> &v)
// { // bubble sort
//     int aux, tam = v.size(), k = 1;
//     for (int i = 0; i < tam; i++)
//     {
//         for (int j = 0; j < tam - k; j++)
//         {
//             if (v[j] >= v[j + 1])
//             {
//                 aux = v[j];
//                 v[j] = v[j + 1];
//                 v[j + 1] = aux;
//             }
//         }
//         k++;
//     }
// }

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
    int tam = v.size();
    ordena_vetor_decrescente(v, 0, tam - 1);

    for (int valor : v) // for of c++ (:
    {
        cout << valor << " ";
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
                               Cria_arv(9), Cria_arv(2)),
                      Cria_arv(6,
                               Cria_arv(0), Cria_arv(7)));

    exibe_dec(x);
}

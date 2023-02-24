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

void imprime(Arv *raiz)
{
    if (raiz != NULL)
    {
        cout << "Valor: "<< raiz->valor<< '\n';
        imprime(raiz->esq);
        imprime(raiz->dir);
    }
}

void imprime_em_largura(Arv *raiz){
    if(raiz != NULL){
        
        cout << " < " << raiz->valor;
        imprime_em_largura(raiz->esq);
        imprime_em_largura(raiz->dir);
        cout << " >";

    }else{
        cout << " <> ";
    }
}

int main()
{

    cout << "----- Teste Arv -----\n";
    // printf("Digite a qtd de elementos serão inseridos: ");
    int qtd = 3;
    // scanf("%d", qtd);

    Arv *x = Cria_arv(1,
                     Cria_arv(3,
                              Cria_arv(2, NULL, NULL), NULL),
                     Cria_arv(6,
                              Cria_arv(0, NULL, NULL), NULL));

    //imprime(x);
    imprime_em_largura(x);


    return 0;
}

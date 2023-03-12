
//Integrantes do grupo:
// - Daniel Luca
// - Marcos Eduardo
// - Gabriel
// - Gabriela
// - Gilderlane 
// - Israel
//Representante: Marcos Eduardo

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


int igual(Arv *A, Arv *B){
    if((A != NULL && B == NULL) || (A == NULL && B != NULL)){
        return 0;
    }
    if(A && B){
    
        if(A->valor == B->valor){
           return (igual(A->dir, B->dir) && igual(A->esq, B->esq));
        }
        return 0;
    }
    return 1;

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

    Arv * y = Cria_arv(1,
                      Cria_arv(3,
                               Cria_arv(2, NULL, NULL), Cria_arv(2, NULL, NULL)),
                      Cria_arv(6,
                               Cria_arv(0, NULL, NULL), NULL));

    int aux = igual(x, y);
    cout << "Arv X: " << endl;
    imprime(x);
    cout << "Arv Y: " << endl;
    imprime(y);

    if (aux)
    {
        cout << "\n\nAs Arvores sao iguais!!" << endl;
    }
    else
    {
        cout << "\n\nAs Arvores nao sao iguais!!" << endl;
    }
}

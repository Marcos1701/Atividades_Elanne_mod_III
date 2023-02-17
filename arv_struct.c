#include <stdio.h>
#include <stdlib.h>

// Arvore versão struct

typedef struct arv{
    int valor;
    Arv *Esq;
    Arv *Dir;

} Arv;

Arv *Cria_arv(int valor, Arv *Esq, Arv *Dir){
    Arv *New_arv = (Arv*)malloc(sizeof(Arv));
    New_arv->valor = valor;
    New_arv->Esq = Esq;
    New_arv->Dir = Dir;
    
    return New_arv;
}

void imprime(Arv *raiz){
    if(raiz != NULL){
        printf("Valor: %d\n", raiz->valor);
        imprime(raiz->Esq);
        imprime(raiz->Dir);
    }
    
}

int main(){

    printf("----- Teste Arv -----\n");
    printf("Digite a qtd de elementos serão inseridos: ");
    int qtd;
    scanf("%d", qtd);


   return 0;
}

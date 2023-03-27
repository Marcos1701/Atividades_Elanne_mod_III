
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

int confere_exp(Arv *A)
{
    if (A == NULL)
    {
        return 1;
    }
    if (A->dir == NULL && A->esq == NULL)
    {
        return isdigit(A->valor);
    }
    return (confere_exp(A->dir) && (A->esq));
}


int valor(Arv *a){
    if(a == NULL){
        return 0;
    }

    if(a->valor == '*'){
        return valor(a->esq) * valor(a->dir);
    } else if(a->valor == '/'){
        return valor(a->esq) / valor(a->dir);
    }else if(a->valor == '+'){
        return valor(a->esq) + valor(a->dir);
     }else if(a->valor == '-'){
        return valor(a->esq) - valor(a->dir);
    }
    return a->valor;
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

Arv *Joga_exp_em_arv(string exp){
    Arv *raiz = NULL;
    Arv *pilha[exp.length()];
    int topo = -1;
    for(int i = 0; i < exp.length(); i++){
        if(isdigit(exp[i])){
            raiz = Cria_arv(exp[i]);
            pilha[++topo] = raiz;
        } else {
            Arv *t = Cria_arv(exp[i]);
            t->dir = pilha[topo--];
            t->esq = pilha[topo--];
            pilha[++topo] = t;
       }
    }
    return pilha[topo]; 
}

int main()
{
    //string exp;
    //cout << "Digite uma expressão a seguir: \n=> ";
    //cin >> exp;
    //Arv *x2 = Joga_exp_em_arv(exp);
    Arv *x = Cria_arv('*',
                      Cria_arv('/',
                               Cria_arv('+', Cria_arv('5'), Cria_arv('3')), Cria_arv('4')),
                      Cria_arv('-',
                               Cria_arv('6'), Cria_arv('1')));
    int aux = confere_exp(x);
    cout << "Arv X: " << endl;
    imprime(x);


    if (aux)
    {
        cout << "\n Valor resultante: " << valor(x) << "\n\n";
    }
    else
    {
        cout << "\n\nA Espressao nao e valida!!" << endl;
    }
}

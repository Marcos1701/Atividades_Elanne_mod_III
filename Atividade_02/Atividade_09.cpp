
//Integrantes do grupo:
// - Daniel Luca
// - Marcos Eduardo
// - Gabriel
// - Gabriela
// - Gilderlane 
// - Israel
//Representante: Marcos Eduardo

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct arv
{
    char info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv *arvore(char x, Arv *e = NULL, Arv *d = NULL)
{
    Arv *novo = (Arv *)malloc(sizeof(Arv));
    novo->esq = e;
    novo->dir = d;
    novo->info = x;
    return novo;
}

void imprime(Arv *n)
{

    if (n != NULL)
    {

        cout << " < " << n->info;
        imprime(n->esq);
        imprime(n->dir);
        cout << " > ";
    }
    else
        cout << " <> ";
    return;
}

int ArvBinariaCompleta(Arv *no, int altura)
{
    if (no == NULL)
    {
        return 1;
    }
    if (no->esq == NULL && no->dir == NULL)
    {
        return altura == 1;
    }
    if (no->esq == NULL || no->dir == NULL)
    {
        return 0;
    }
    return ArvBinariaCompleta(no->esq, altura - 1) && ArvBinariaCompleta(no->dir, altura - 1);
}

int alturaArvore(Arv *no)
{
    if (no == NULL)
    {
        return 0;
    }
    int esq = alturaArvore(no->esq);
    int dir = alturaArvore(no->dir);
    if (esq > dir)
    {
        return esq + 1;
    }
    return dir + 1;
}

main()
{

    Arv *c = arvore('c',
                    arvore('g',
                           arvore('d'), arvore('y')),
                    arvore('k',
                           arvore('t'), arvore('m')));

                           /* Arvore c
                             ('c')
                           /       \
                        ('g')       ('k')
                       /     \     /     \ 
                    ('d')  ('y')  ('t')   ('m')*/
    Arv *x = arvore('x',
                    arvore('h', NULL, arvore('y', arvore('k'))),
                    arvore('e',
                           arvore('w')));

 /*        Arvore x
            ('x')
           /      \
          /        \
      ('h')        ('e')
          \       /  
        ('y')   ('w') 
        /  
     ('k')
            */

    cout << "Arvore 'c': " << endl;
    imprime(c);

    cout << "\nArvore 'x': " << endl;
    imprime(x);

    if (ArvBinariaCompleta(c, alturaArvore(c)))
        cout << endl
             << "\nA Arvore Binaria 'c' esta completa" << endl;
    else
        cout << endl
             << "\nOps, a Arvore Binaria 'c' esta incompleta\n" << endl;

    if (ArvBinariaCompleta(x, alturaArvore(x)))
        cout << endl
             << "\nA Arvore Binaria 'x' esta completa" << endl;
    else
        cout << endl
             << "\nOps, a Arvore Binaria 'x' esta incompleta\n" << endl;
}

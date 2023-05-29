/*
    Respostas:

A)Qual o resultado do percurso PRE-Order (VLR) na arvore?

R - 10 -> 5 -> 3 -> 7 -> 20 -> 15 -> 24

B) Explique quais os passos realizados pelo algoritmo de Morris – Percurso PRE-ORDER:

   R- 1. Se o NO atual nao possui filho esquerdo, imprima-o e passe para o NO direito.
   R-     2. Se o NO atual tem um filho esquerdo:
   R-         2.1) Encontre o NO predecessor do NO atual.
   R-            1) Se o predecessor nao tem um filho direito:
   R-                1) O filho direito do predecessor passa a apontar para o NO atual.
   R-                     O NO atual passa para o NO filho da esquerda.
   R-             2) Se o predecessor tem um filho direito:
   R-                 1) O filho direito do predecessor passa a apontar para NULL.
   R-                    Imprime o NO atual. O NO atual passa para o NO filho da direita.
   R-     2.2) Repita os passos 2.1 e 2.2 até que o NO atual seja NULL.

C) Aplique a árvore no algoritmo e confira se o resultado está correto.
    R- retorno : Pre-order Morris:
                  10 5 3 7 20 15 24
*/

#include <queue>
#include <stack>
#include <iostream>

using namespace std;

template <class T>
class ArvoreNo
{
public:
    T el;
    ArvoreNo<T> *left, *right;
    ArvoreNo()
    {
        left = right = 0;
    }
    ArvoreNo(T e, ArvoreNo<T> *l = 0, ArvoreNo<T> *r = 0)
    {
        el = e;
        left = l;
        right = r;
    }
};

template <class T>
class Arvore
{
protected:
    ArvoreNo<T> *root;

public:
    Arvore()
    {
        root = 0;
    }
    ~Arvore()
    {
        clear();
    }
    void clear()
    {
        clear(root);
        root = 0;
    }

    ArvoreNo<T> *getRoot()
    {
        return root;
    }
    bool isEmpty() const
    {
        return root = 0;
    }

    void visit(ArvoreNo<T> *p)
    {
        cout << p->el << " ";
    }

    T search(T el)
    {
        ArvoreNo<T> *p = root;
        while (p != 0)
        {

            if (el == p->el)
                return p->el;
            else
            {
                if (el < p->el)
                    p = p->left;
                else
                    p = p->right;
            }
        }
        return 0;
    }

    void insert(T el)
    {
        ArvoreNo<T> *p = root, *prev = 0;
        while (p != 0)
        {
            prev = p;
            if (el < p->el)
                p = p->left;
            else
                p = p->right;
        }
        if (root == 0) // a arvore esta vazia
            root = new ArvoreNo<T>(el);
        else if (el < prev->el)
            prev->left = new ArvoreNo<T>(el);
        else
            prev->right = new ArvoreNo<T>(el);
    }
    void MorrisPreorder()
    {
        ArvoreNo<T> *p = root, *tmp;
        while (p != 0)
        {
            if (p->left == 0)
            {
                visit(p);
                p = p->right;
            }
            else
            {
                tmp = p->left;
                while (tmp->right != 0 && tmp->right != p)
                    tmp = tmp->right;
                if (tmp->right == 0)
                {
                    visit(p);
                    tmp->right = p;
                    p = p->left;
                }
                else
                {
                    tmp->right = 0;
                    p = p->right;
                } /*fim else*/
            }
        } /*fim while*/
    }
};

int main()
{

    Arvore<int> *a = new Arvore<int>();
    a->insert(10);
    a->insert(5);
    a->insert(20);
    a->insert(7);
    a->insert(3);
    a->insert(15);
    a->insert(24);

    cout << "\n\nPre-order Morris: " << endl;
    a->MorrisPreorder();
    cout << endl;
    return 0;
}

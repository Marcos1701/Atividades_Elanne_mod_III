/*
A) Qual o resultado do percurso In-Order (LVR) na árvore?
    R- 3 -> 5 -> 7 -> 10 -> 15 -> 20 -> 24
B) Explique quais os passos realizados pelo algoritmo de Morris – Percurso inORDER:
    R- 1. Se o NO atual nao possui filho esquerdo, imprima-o e passe para o NO direito(filho da direira).
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
    R- retorno : In-order Morris:
    R-           3 5 7 10 15 20 24
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

    void InorderMorris()
    {
        ArvoreNo<T> *atual = root;

        while (atual != 0)
        {
            if (atual->left == 0)
            {
                // Não há filho esquerdo, visite o nó e vá para o filho direito
                cout << atual->el << " ";
                atual = atual->right;
            }
            else
            {
                // Encontre o predecessor do nó atual
                ArvoreNo<T> *predecessor = atual->left;
                while (predecessor->right != 0 && predecessor->right != atual)
                {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == 0)
                {
                    // Estabeleça a ligação do predecessor para o nó atual
                    predecessor->right = atual;
                    atual = atual->left;
                }
                else
                {
                    // A ligação do predecessor para o nó atual já existe, remova-a
                    predecessor->right = 0;
                    cout << atual->el << " ";
                    atual = atual->right;
                }
            }
        }
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

    cout << "\n\nIn-order Morris: " << endl;
    a->InorderMorris();
    cout << endl;
    return 0;
}

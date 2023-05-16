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
    int sucessor;
    ArvoreNo()
    {
        left = right = 0;
    }
    ArvoreNo(T e, ArvoreNo<T> *l = 0, ArvoreNo<T> *r = 0)
    {
        el = e;
        left = l;
        right = r;
        sucessor = 1;
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
        ArvoreNo<T> *p = root, *prev = 0, *aux = new ArvoreNo<T>(el);
        while (p != 0)
        {
            prev = p;
            if (el < p->el)
                p = p->left;
            else
                p = p->right;
        }

        if (root == 0)
        { // a arvore esta vazia
            root = aux;
        }
        else if (el < prev->el)
        {
            aux->left = prev->left;
            prev->left = aux;
            aux->sucessor = 0;
        }
        else
        {
            aux->right = prev->right;
            prev->right = aux;
            aux->sucessor = 0;
        }

        cout << "Inserido: " << el << endl;
    }

    void preorder(ArvoreNo<T> *p)
    {
        if (p != nullptr)
        {
            visit(p);           // Visita o nó atual
            preorder(p->left);  // Percorre o filho à esquerda
            preorder(p->right); // Percorre o filho à direita
        }
    }

    void posorder(ArvoreNo<T> *p)
    {
        if (p != nullptr)
        {
            posorder(p->left);  // Percorre o filho à esquerda
            posorder(p->right); // Percorre o filho à direita
            visit(p);           // Visita o nó atual
        }
    }

    void inorder(ArvoreNo<T> *p)
    {
        if (p != nullptr)
        {
            inorder(p->left);  // Percorre o filho à esquerda
            visit(p);          // Visita o nó atual
            inorder(p->right); // Percorre o filho à direita
        }
    }
};

int main()
{

    Arvore<int> *a = new Arvore<int>();
    a->insert(13);
    a->insert(10);
    a->insert(25);
    a->insert(2);
    a->insert(12);
    a->insert(20);
    a->insert(4);
    a->insert(1);
    a->insert(3);
    a->insert(2);
    a->insert(6);
    a->insert(7);
    a->insert(5);
    a->insert(29);
    cout << "\n\nPre-order: " << endl;
    a->preorder(a->getRoot());
    cout << "\n\nPos-order: " << endl;
    a->posorder(a->getRoot());
    cout << "\n\nIn-order: " << endl;
    a->inorder(a->getRoot());
    cout << endl;
    return 0;
}

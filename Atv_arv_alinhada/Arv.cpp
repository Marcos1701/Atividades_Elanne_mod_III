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
            aux->sucessor = 0;
            root = aux;
        }
        else if (el < prev->el)
        {
            aux->right = prev;
            prev->left = aux;
        }
        else
        {
            aux->right = prev;
            prev->right = aux;
            prev->sucessor = 0;
        }

        cout << "Inserido: " << el << endl;
    }

    void preorder(ArvoreNo<T> *p)
    {
        while (p != 0)
        {
            // preorder
            visit(p);
            if (p->left != 0)
            {
                p = p->left;
            }
            else if (p->right != 0)
            {
                p = p->right;
            }
            else
            {
                break;
            }
        }
    }

    void posorder(ArvoreNo<T> *p)
    {
        while (p != 0)
        { // postorder
            if (p->left != 0)
            {
                p = p->left;
            }
            else if (p->right != 0)
            {
                if (p->sucessor == 0)
                    visit(p);
                p = p->right;
            }
            else
            {
                break;
            }
        }
    }

    void inorder(ArvoreNo<T> *p)
    {
        while (p != 0)
        { // inorder
            if (p->left != 0)
            {
                p = p->left;
            }
            else if (p->right != 0)
            {
                visit(p);
                p = p->right;
            }
            else
            {
                break;
            }
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

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
    // obs: pg 209 figura 6.23
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

    void percusoExtensao(ArvoreNo<T> *p)
    {
        queue<ArvoreNo<T> *> aux;
        aux.push(p);

        while (!aux.empty())
        {
            ArvoreNo<T> *q = aux.front();
            aux.pop();
            visit(q);

            if (q->left != 0)
                aux.push(q->left);
            if (q->right != 0)
                aux.push(q->right);
        }
    }

    void preorder(ArvoreNo<T> *p)
    {
        if (p == 0)
        {
            return;
        }

        stack<ArvoreNo<T> *> s;
        s.push(p);

        while (!s.empty())
        {
            ArvoreNo<T> *curr = s.top();
            s.pop();

            visit(curr);

            if (curr->right != 0)
            {
                s.push(curr->right);
            }

            if (curr->left != 0)
            {
                s.push(curr->left);
            }
        }
    }

    void posorder(ArvoreNo<T> *p)
    {
        queue<ArvoreNo<T> *> aux;
        aux.push(p);

        while (!aux.empty())
        {
            ArvoreNo<T> *q = aux.front();
            aux.pop();
            visit(q);

            if (q->left != 0)
                aux.push(q->left);
            if (q->right != 0)
                aux.push(q->right);
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
    // a->exibe_desenho_arv_sem_recursao(a->getRoot());
    cout << "\nPersurso em extensao: " << endl;
    a->percusoExtensao(a->getRoot());
    cout << "\n\nPre-order: " << endl;
    a->preorder(a->getRoot());
    cout << "\n\nPos-order: " << endl;
    a->posorder(a->getRoot());
    // int procurado= a->search(200);
    // if (procurado==0)
    //    cout<<"Nao achou ";
    // else
    //     cout<<procurado<<" encontrado!!";
}

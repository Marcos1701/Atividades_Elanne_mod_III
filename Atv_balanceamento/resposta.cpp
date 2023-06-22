#include <queue>
#include <stack>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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
    bool isEmpty() const
    {
        return root == 0;
    }
    ArvoreNo<T> *getRoot()
    {
        return root;
    }
    void insert(const T &el)
    {
        ArvoreNo<T> *no = new ArvoreNo<T>(el);
        ArvoreNo<T> *p = root, *prev = 0;
        while (p != 0)
        {
            prev = p;
            if (el < p->el)
                p = p->left;
            else
                p = p->right;
        }
        if (root == 0)
            root = no;
        else if (el < prev->el)
            prev->left = no;
        else
            prev->right = no;
    }

    void ImprimeArv(ArvoreNo<T> *p)
    {
        if (p != 0)
        {
            cout << p->el << " ";
            ImprimeArv(p->left);
            ImprimeArv(p->right);
        }
    }

    int altura(ArvoreNo<T> *p)
    {
        if (p == NULL)
        {
            return 0;
        }
        int alturaEsquerda = altura(p->left);
        int alturaDireita = altura(p->right);
        return max(alturaEsquerda, alturaDireita) + 1;
    }

    int quantNos(ArvoreNo<T> *p)
    {
        if (p == NULL)
        {
            return 0;
        }
        int quantEsquerda = quantNos(p->left);
        int quantDireita = quantNos(p->right);
        return quantEsquerda + quantDireita + 1;
    }

    vector<T> getElements()
    {
        vector<T> v;
        queue<ArvoreNo<T> *> fila;
        ArvoreNo<T> *p = root;
        if (p != 0)
        {
            fila.push(p);
            while (!fila.empty())
            {
                p = fila.front();
                fila.pop();
                v.push_back(p->el);
                if (p->left != 0)
                    fila.push(p->left);
                if (p->right != 0)
                    fila.push(p->right);
            }
        }
        return v;
    }

    void balancearporVetor()
    {
        vector<T> v = getElements();
        int inicio = 0;
        int fim = v.size() - 1;
        sort(v.begin(), v.end());
        root = 0;
        balancear(v, inicio, fim);
    }

    void balancearViaDSW()
    {
        // Passo 1: Converter a árvore em uma lista encadeada
        ArvoreNo<T> *tmp = root;
        vector<ArvoreNo<T> *> lista;

        while (tmp != nullptr)
        {
            if (tmp->left != nullptr)
            {
                ArvoreNo<T> *q = tmp->left;
                tmp->left = q->right;
                q->right = tmp;
                tmp = q;
            }
            else
            {
                lista.push_back(tmp);
                tmp = tmp->right;
            }
        }

        // Passo 2: Reorganizar a lista encadeada para formar uma árvore balanceada
        int n = lista.size();

        root = nullptr;
        reconstruirArvoreBalanceada(lista, 0, n - 1);
    }

    void InorderMorris()
    {
        ArvoreNo<T> *atual = root;

        while (atual != 0)
        {
            if (atual->left == 0)
            {
                cout << atual->el << " ";
                atual = atual->right;
            }
            else
            {
                ArvoreNo<T> *predecessor = atual->left;
                while (predecessor->right != 0 && predecessor->right != atual)
                {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == 0)
                {
                    predecessor->right = atual;
                    atual = atual->left;
                }
                else
                {
                    predecessor->right = 0;
                    cout << atual->el << " ";
                    atual = atual->right;
                }
            }
        }
    }

private:
    void balancear(vector<T> &v, int inicio, int fim)
    {
        if (inicio <= fim)
        {
            int meio = (inicio + fim) / 2;
            insert(v[meio]);
            balancear(v, inicio, meio - 1);
            balancear(v, meio + 1, fim);
        }
    }

    ArvoreNo<T> *rotacaoDireita(ArvoreNo<T> *p)
    {
        ArvoreNo<T> *q = p->left;
        p->left = q->right;
        q->right = p;
        return q;
    }

    ArvoreNo<T> *rotacaoEsquerda(ArvoreNo<T> *p)
    {
        ArvoreNo<T> *q = p->right;
        p->right = q->left;
        q->left = p;
        return q;
    }

    void reconstruirArvoreBalanceada(vector<ArvoreNo<T> *> &lista, int inicio, int fim)
    {
        if (inicio <= fim)
        {
            int meio = (inicio + fim) / 2;
            inserirElemento(lista[meio]);

            reconstruirArvoreBalanceada(lista, inicio, meio - 1);
            reconstruirArvoreBalanceada(lista, meio + 1, fim);
        }
    }

    void inserirElemento(ArvoreNo<T> *no)
    {
        if (root == nullptr)
        {
            root = no;
            no->left = nullptr;
            no->right = nullptr;
        }
        else
        {
            ArvoreNo<T> *p = root;
            ArvoreNo<T> *prev = nullptr;

            while (p != nullptr)
            {
                prev = p;
                if (no->el < p->el)
                    p = p->left;
                else
                    p = p->right;
            }

            if (no->el < prev->el)
                prev->left = no;
            else
                prev->right = no;

            no->left = nullptr;
            no->right = nullptr;
        }
    }
};

int main()
{
    Arvore<int> *a = new Arvore<int>();
    Arvore<int> *b = new Arvore<int>();
    a->insert(7);
    a->insert(6);
    a->insert(22);
    a->insert(14);
    a->insert(40);
    a->insert(63);

    b->insert(7);
    b->insert(6);
    b->insert(22);
    b->insert(14);
    b->insert(40);
    b->insert(63);

    cout << "Altura da arvore: " << a->altura(a->getRoot()) << endl;

    cout << "Arvore resultante: ";
    a->ImprimeArv(a->getRoot());
    cout << endl;

    cout << "A arvore resultante esta balanceada? ";
    if (a->altura(a->getRoot()->left) - a->altura(a->getRoot()->right) <= 1)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    cout << "Arvore A balanceada por vetor: ";
    a->balancearporVetor();
    a->InorderMorris();
    cout << endl;

    cout << "Arvore B balanceada por inorder: ";
    b->balancearViaDSW();
    b->InorderMorris();
    cout << endl;

    cout << "As arvores resultantes estao balanceadas? ";
    if (a->altura(a->getRoot()->left) - a->altura(a->getRoot()->right) <= 1)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    cout << "As arvores resultantes sao iguais? ";
    if (a->getElements() == b->getElements())
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    return 0;
}

// 1) Inclua os seguintes valores na seguinte ordem em uma árvore binária:
// 7, 6, 22, 14, 40, 63.
// 1.1) Qual a altura da árvore resultante?
// 1.2) Mostre a árvore resultante.
// 1.3) A árvore resultante está balanceada ou não?
// 1.4) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de
// reordenação dos dados para balancear a árvore.
// OBS: Use um método sort para ordenar o vetor resultante.

// 1.5) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de
// reordenação dos dados para balancear a árvore.
// OBS: Aplique o percurso in-order para montar o vetor resultante.

// 1.6) Compare os resultados em 1.4 e 1.5. As árvores resultantes estão balanceadas? Elas são
// iguais?

#include <queue>
#include <stack>
#include <iostream>
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

    int altura(ArvoreNo<T> *p, int h = 0)
    {
        if (p != 0)
        {
            h++;
            altura(p->left, h);
            altura(p->right, h);
        }
        return h;
    }
};

void balancear(ArvoreNo<int> *p, int *vet, int tam)
{
    int i = 0;
    queue<ArvoreNo<int> *> fila;
    fila.push(p);
    while (!fila.empty())
    {
        ArvoreNo<int> *no = fila.front();
        fila.pop();
        vet[i] = no->el;
        i++;
        if (no->left != 0)
            fila.push(no->left);
        if (no->right != 0)
            fila.push(no->right);
    }
    sort(vet, vet + tam);
    p->el = vet[tam / 2];
    p->left = 0;
    p->right = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] != p->el)
            p->el = vet[i];
    }
}

int main()
{

    Arvore<int> *a = new Arvore<int>();
    // 7, 6, 22, 14, 40, 63.
    a->insert(7);
    a->insert(6);
    a->insert(22);
    a->insert(14);
    a->insert(40);
    a->insert(63);

    // 1.1) Qual a altura da árvore resultante?
    // R- 3
    cout << "Altura da arvore: " << a->altura(a->getRoot()) << endl;

    // 1.2) Mostre a árvore resultante.
    // R- 7 6 22 14 40 63
    cout << "Arvore: " << endl;
    a->ImprimeArv(a->getRoot());

    // 1.3) A árvore resultante está balanceada ou não?
    // R- Não

    // 1.4) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de
    // reordenação dos dados para balancear a árvore.
    // OBS: Use um método sort para ordenar o vetor resultante.
    // R- 6 7 14 22 40 63

    cout << endl;
    return 0;
}

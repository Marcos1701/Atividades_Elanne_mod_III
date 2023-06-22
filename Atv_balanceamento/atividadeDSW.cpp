#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
Atividade Balanceamento 2:

1) Inclua os seguintes valores na seguinte ordem em uma árvore binária:
7, 22, 14, 40,30, 63,80.
1.1) Qual a altura da árvore resultante?
R- 3
1.2) Mostre a árvore resultante.
R- 7, 22, 14, 40,30, 63,80
1.3) A árvore resultante está balanceada ou não?
R- Não
1.4) Implemente a 1ª parte do algoritmo DWS, aonde a resultante da árvore após as
rotações deve ser uma árvore somente com filhos a esquerda.

1.5) Mostre a árvore resultante
R- 7, 22, 14, 40,30, 63,80
*/

class ArvoreNo
{
public:
    int el;
    ArvoreNo *left, *right;
    ArvoreNo()
    {
        left = right = 0;
    }
    ArvoreNo(int e, ArvoreNo *l = 0, ArvoreNo *r = 0)
    {
        el = e;
        left = l;
        right = r;
    }
};

class Arvore
{
protected:
    ArvoreNo *root;

public:
    Arvore()
    {
        root = 0;
    }
    bool isEmpty() const
    {
        return root == 0;
    }
    ArvoreNo *getRoot()
    {
        return root;
    }
    void insert(const int &el)
    {
        ArvoreNo *no = new ArvoreNo(el);
        ArvoreNo *p = root, *prev = 0;
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
    void visit(ArvoreNo *p)
    {
        cout << p->el << " ";
    }

    int altura(ArvoreNo *p)
    {
        if (p == 0)
            return -1;
        else
        {
            int left = altura(p->left);
            int right = altura(p->right);
            if (left > right)
                return left + 1;
            else
                return right + 1;
        }
    }

    int calculaQuantNos(ArvoreNo *p)
    {
        if (p == 0)
            return 0;
        else
            return 1 + calculaQuantNos(p->left) + calculaQuantNos(p->right);
    }

    void InorderMorris()
    {
        ArvoreNo *atual = root;

        while (atual != 0)
        {
            if (atual->left == 0)
            {
                cout << atual->el << " ";
                atual = atual->right;
            }
            else
            {
                ArvoreNo *predecessor = atual->left;
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

    void rotateRight(ArvoreNo *p)
    {
        ArvoreNo *tmp = p->left;
        p->left = tmp->left;
        p->left = tmp->right;
        tmp->right = p->right;
        p->right = tmp;
        /*Resumindo o algoritmo:
          1. tmp = p->left; -> tmp recebe o filho esquerdo de p
          2. p->left = tmp->left; -> o filho esquerdo de p recebe o filho esquerdo de tmp
          3. tmp->right = p->right; -> o filho direito de tmp recebe o filho direito de p
          4. p->right = tmp; -> o filho direito de p recebe tmp

          Dessa forma, tmp(que era o filho esquerdo de p) passa a ser o pai de p, e p passa a ser o filho direito de tmp
          */
    }

    void rotateLeft(ArvoreNo *p)
    {
        ArvoreNo *tmp = p->right;
        p->right = tmp->right;
        p->right = tmp->left;
        tmp->left = p->left;
        p->left = tmp;

        /*Resumindo o algoritmo:
          1. tmp = p->right; -> tmp recebe o filho direito de p
          2. p->right = tmp->left; -> o filho direito de p recebe o filho esquerdo de tmp
          3. tmp->left = p; -> o filho esquerdo de tmp recebe p
          4. p = tmp; -> p recebe tmp

          Dessa forma, tmp(que era o filho direito de p) passa a ser o pai de p, e p passa a ser o filho esquerdo de tmp
          */
    }

    void Backbone()
    {
        ArvoreNo *tmp = root;
        while (tmp != NULL)
        {
            while (tmp->left != NULL)
            {
                rotateRight(tmp);
            }
            tmp = tmp->right;
        }
    };
    /*createPerfectTree (n) {
    m = (2 elevado ao menor valor de lg(n+1)) -
    1;
    faça n –
    m rotações começando da raiz;
    while (m > 1) {
    m = m / 2;
    faça m rotações começando da raiz;
    }
    }*/

    void createPerfectTree(int n)
    {
        int m = pow(2, floor(log2(n + 1))) - 1;
        for (int i = 0; i < n - m; i++)
        {
            rotateRight(root);
        }
        while (m > 1)
        {
            m = m / 2;
            for (int i = 0; i < m; i++)
            {
                rotateRight(root);
            }
        }
    }

    void balancearViaDSW()
    {
        Backbone();
        createPerfectTree(calculaQuantNos(root));
    }

    void balancearViaDSW2()
    {
        // Passo 1: Converter a árvore em uma lista encadeada
        ArvoreNo *tmp = root;
        vector<ArvoreNo *> lista;

        while (tmp != nullptr)
        {
            if (tmp->left != nullptr)
            {
                ArvoreNo *q = tmp->left;
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

    void reconstruirArvoreBalanceada(vector<ArvoreNo *> &lista, int inicio, int fim)
    {
        if (inicio <= fim)
        {
            int meio = (inicio + fim) / 2;

            lista[meio]->left = nullptr;
            lista[meio]->right = nullptr;

            if (root == nullptr)
                root = lista[meio];
            else
                insert(lista[meio]->el);

            reconstruirArvoreBalanceada(lista, inicio, meio - 1);
            reconstruirArvoreBalanceada(lista, meio + 1, fim);
        }
    }
};

int main()
{
    Arvore arvore;
    arvore.insert(7); // 7, 22, 14, 40, 30, 63, 80
    arvore.insert(22);
    arvore.insert(14);
    arvore.insert(40);
    arvore.insert(30);
    arvore.insert(63);
    arvore.insert(80);

    cout << "Arvore Inicial: ";
    arvore.InorderMorris();
    cout << endl
         << "Altura: ";
    int h = arvore.altura(arvore.getRoot());
    cout << h << endl;
    cout << "Arvore Balanceada: ";
    arvore.balancearViaDSW();
    arvore.InorderMorris();
    cout << endl
         << "Altura: ";
    int h2 = arvore.altura(arvore.getRoot());
    cout << h2 << endl;
    return 0;
}
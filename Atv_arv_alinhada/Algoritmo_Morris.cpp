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
        /*O algoritmo de Morris percorre a árvore em ordem, visitando os nós em sequência, 
          sem usar uma pilha explícita ou recursão extra.
          
          caracteristicas do algoritmo de Morris:
          - Percurso sem uso de estruturas adicionais (pilha, fila..);
          - Abordagem baseada em predecessor;
          - Baixa complexidade
          */
        
     
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

    void MorrisPreorder()
    {
        ArvoreNo<T> *atual = root;

        while (atual != 0)
        {
            if (atual->left == 0)
            {
                // Não há filho esquerdo, visite o nó e vá para o filho direito
                visit(atual);
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
                    visit(atual); // Visite o nó antes de percorrer o filho esquerdo
                    predecessor->right = atual;
                    atual = atual->left;
                }
                else
                {
                    // A ligação do predecessor para o nó atual já existe, remova-a
                    predecessor->right = 0;
                    atual = atual->right;
                }
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
    cout << "\n\nPre-order Morris: " << endl;
    a->MorrisPreorder();
    cout << "\n\nIn-order Morris: " << endl;
    a->InorderMorris();
    cout << endl;
    return 0;
}

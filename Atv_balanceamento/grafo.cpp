#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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

class Grafo
{
protected:
vector<ArvoreNo *> Adj;

public:

    int confere_no_repetido(int valor){
        ArvoreNo *tmp;
        queue<ArvoreNo *> fila;
        for(int i = 0; i < Adj.size(); i++){
            tmp = Adj[i];
            if (tmp != 0)
            {
                fila.push(tmp);
                while (!fila.empty())
                {
                    tmp = fila.front();
                    fila.pop();
                    if(valor == tmp->el) return 1;
                    if (tmp->left != 0)
                        fila.push(tmp->left);
                    if (tmp->right != 0)
                        fila.push(tmp->right);
                }
            }
            return 0;
        }
    }

    void adicionar_No(ArvoreNo *p){
        if(p == nullptr) return;
        Adj.push_back(p);
    }

    void imprime_grafo(){
        
    }
    
};


int main()
{
    
}

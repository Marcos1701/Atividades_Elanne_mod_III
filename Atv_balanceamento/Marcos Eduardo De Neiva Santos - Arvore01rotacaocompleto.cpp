#include <queue>
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

	void percusoExtensao()
	{
		queue<ArvoreNo<T> *> f;
		ArvoreNo<T> *p = root;
		if (p != NULL)
		{
			f.push(p);
			while (!f.empty())
			{
				p = f.front();
				visit(p);
				f.pop();
				if (p->left != 0)
					f.push(p->left);
				if (p->right != 0)
					f.push(p->right);
			}
		}
	}

	void preorder(ArvoreNo<T> *p)
	{
		if (p != 0)
		{
			visit(p);
			preorder(p->left);
			preorder(p->right);
		}
	}

	void rotateRight(ArvoreNo<T> *p)
	{
		ArvoreNo<T> *tmp = p->left;
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

	void backbone()
	{
		ArvoreNo<T> *tmp = root;
		while (tmp != NULL)
		{
			while (tmp->left != NULL)
			{
				rotateRight(tmp);
			}
			tmp = tmp->right;
		}

		/*Resumindo o algoritmo:
		  1. tmp = root; -> tmp recebe a raiz da arvore
		  2. while(tmp != NULL) -> enquanto tmp for diferente de NULL
		  3. while(tmp->left != NULL) -> enquanto o filho esquerdo de tmp for diferente de NULL
		  4. rotateRight(tmp); -> rotaciona a arvore a direita
		  5. tmp = tmp->right; -> tmp recebe o filho direito de tmp

		  Dessa forma, a arvore é rotacionada a direita até que o filho esquerdo de tmp seja NULL,
		  e tmp passa a ser o filho direito de tmp
		*/
	}
};

main()
{

	Arvore<int> *a = new Arvore<int>();

	// 1) Inclua os seguintes valores na seguinte ordem em uma árvore binária: 7, 22, 14, 40,30, 63,80.
	a->insert(7);
	a->insert(22);
	a->insert(14);
	a->insert(40);
	a->insert(30);
	a->insert(63);
	a->insert(80);
	// 1.1) Qual a altura da árvore resultante?
	// R: 4
	// 1.2) Mostre a árvore resultante.
	cout << "---Antes das rotacoes -----" << endl;
	a->preorder(a->getRoot());

	// 1.3) A árvore resultante está balanceada ou não?
	// R: Não

	// 1.4) Implemente a 1ª parte do algoritmo DWS, aonde a resultante da árvore após as
	// rotações deve ser uma árvore somente com filhos a esquerda.
	a->backbone();
	cout << endl
		 << "---Apos as rotacoes -----" << endl;
	// 1.5) Mostre a árvore resultante
	a->preorder(a->getRoot());
}

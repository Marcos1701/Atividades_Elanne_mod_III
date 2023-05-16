#include <iostream>
using namespace std;

template <class T>
class ThreadedNode
{
public:
    ThreadedNode()
    {
        left = right = 0;
    }
    ThreadedNode(T el, ThreadedNode *l = 0, ThreadedNode *r = 0)
    {
        this->el = el;
        left = l;
        right = r;
        successor = 0;
    }
    T el;
    ThreadedNode *left, *right;
    unsigned int successor : 1;
};

template <class T>
class ThreadedTree
{
public:
    ThreadedTree()
    {
        root = 0;
    }
    void insert(T el); // Pigura 6.24
    void inorder();
    void preorder();
    void postorder();

protected:
    ThreadedNode<T> *root;
};

template <class T>
void ThreadedTree<T>::insert(T el)
{
    ThreadedNode<T> *p = root, *prev = 0, *tmp;
    while (p != 0)
    {
        if (p->successor == 0)
            prev = p;
        if (el < p->el)
        {
            if (p->left != 0)
                p = p->left;
            else
                break; // Exit the loop if there is no left node
        }
        else if (el > p->el)
            p = p->right;
        else
            return;
    }
    tmp = new ThreadedNode<T>(el);
    if (root != 0)
    {
        if (el < prev->el)
        {
            prev->left = tmp;
            tmp->right = prev;
            tmp->successor = 1;

            // Update the thread of the previous node
            ThreadedNode<T> *pred = prev;
            while (pred->right != prev)
                pred = pred->right;
            pred->right = tmp;
        }
        else
        {
            prev->right = tmp;
            // Update the thread of the current node
            ThreadedNode<T> *succ = p->right;
            tmp->right = succ;
            tmp->successor = 1;
            p->right = tmp;

            if (succ != 0)
            {
                // Find the leftmost node in the right subtree of tmp
                while (succ->left != 0)
                    succ = succ->left;

                // Update the thread of the successor node
                ThreadedNode<T> *pred = succ;
                while (pred->right != p)
                    pred = pred->right;
                pred->right = tmp;
            }
        }
    }
    else
    {
        root = tmp;
    }
    cout << "Inserido " << el << endl;
}

template <class T>
void ThreadedTree<T>::inorder()
{
    ThreadedNode<T> *p = root;
    if (p != 0)
    {
        while (p->left != 0)
            p = p->left;
        while (p != 0)
        {
            cout << p->el << ' ';
            if (p->successor == 1)
                p = p->right;
            else
            {
                p = p->right;
                while (p != 0 && p->successor == 0)
                    p = p->right;
            }
        }
    }
}

template <class T>
void ThreadedTree<T>::preorder()
{
    ThreadedNode<T> *p = root;
    while (p != 0)
    {
        cout << p->el << ' ';

        if (p->successor == 1)
            p = p->right;
        else
        {
            p = p->right;
            while (p != 0 && p->successor == 0)
                p = p->right;
        }
    }
}

template <class T>
void ThreadedTree<T>::postorder()
{
    ThreadedNode<T> *p = root;
    while (p != 0)
    {
        cout << p->el << ' ';
        if (p->successor == 1)
            p = p->right;
        else
        {
            p = p->right;
            while (p != 0 && p->successor == 0)
                p = p->right;
        }
    }
}

int main()
{
    ThreadedTree<int> t;
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(3);
    t.insert(7);
    t.insert(12);
    t.insert(17);
    t.insert(1);
    t.insert(4);
    t.insert(6);
    t.insert(8);
    t.insert(11);
    t.insert(13);
    t.insert(16);
    t.insert(18);
    t.insert(2);
    cout << "Inorder: ";
    t.inorder();
    cout << endl;
    cout << "Preorder: ";
    t.preorder();
    cout << endl;
    cout << "Postorder: ";
    t.postorder();
    cout << endl;
    return 0;
}
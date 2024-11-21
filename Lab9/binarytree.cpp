#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T> class BinaryTree
{
public:
    T *pinfo;
    BinaryTree<T> *left_son, *right_son, *parent, *root; // *level;

    BinaryTree()
    {
        pinfo = NULL;
        left_son = right_son = parent = NULL;
        root = this;
        /* if(parent != NULL)
            level = parent->level + 1
        else
            level = 0 */
    }

    void setInfo(T info)
    {
        pinfo = new T;
        *pinfo = info;
    }

    void setRoot(BinaryTree<T> *r)
    {
        root = r;
    }

    /// inserer un noeud
    void insert(T x)
    {
        ///si l'arbre est vide, celui-ci est le premier noeud
        if (pinfo == NULL)
            setInfo(x);
        ///sinon, on appelle insert recursif
        else
            insert_rec(x);
    }

    void insert_rec(T x)
    {
        ///choisit aleatoirement si c'est enfant gauche ou droit (0 ou 1)
        int next_son = rand() % 2; ///%100 -> 0..99
        if (next_son == 0) /// enfant gauche
        {
            ///si on n'a pas encore d'enfant gauche
            if (left_son == NULL)
            {
                left_son = new BinaryTree<T>;
                left_son->pinfo = new T;
                *(left_son->pinfo) = x;

                left_son->left_son = left_son->right_son = NULL;
                left_son->parent = this;
                left_son->root = root;
            }
            else
                left_son->insert_rec(x);
        }
        else /// enfant droit
        {
            if (right_son == NULL)
            {
                right_son = new BinaryTree<T>;
                right_son->pinfo = new T;
                *(right_son->pinfo) = x;

                right_son->left_son = right_son->right_son = NULL;
                right_son->parent = this;
                right_son->root = root;
            }
            else
                right_son->insert_rec(x);
        }
    }

    ///trouve un certain noeud qui contient info x
    BinaryTree<T>* find(T x)
    {
        BinaryTree<T> *rez;

        if (pinfo == NULL)
            return NULL;

        if ((*pinfo) == x)
            return this;

        ///cherche dans le sous-arbre gauche
        if (left_son != NULL)
            rez = left_son->find(x);
        else
            rez = NULL;

        if (rez != NULL)
            return rez;
        else ///si on NE trouve pas, cherche dans le sous-arbre droit
            if (right_son != NULL)
                return right_son->find(x);
            else
                return NULL;
    }

    ///cherche une feuille --> testons cette fonction!
    BinaryTree<T>* findLeaf()
    {
        if (left_son == NULL && right_son == NULL)
            return this;
        else if (left_son != NULL)
            return left_son->findLeaf();
        else
            return right_son->findLeaf();
    }

    ///appelle remove() avec le noeud qu'on veut effacer (this)
    void remove()
    {
        BinaryTree<T> *leaf;

        /// trouve une feuille dans le sous-arbre du noeud courant
        /// on va l'utiliser pour la mettre a la place du noeud qu'on veut effacer
        leaf = findLeaf();

        ///si le noeud courant est une feuille
        if (this == leaf)
        {
            ///on efface la racine (== feuille)
            if (parent == NULL) /// car this == root == leaf
            {
                if (this->pinfo != NULL)
                    delete this->pinfo;

                root->pinfo = NULL;
            }
            else
            {
                ///si ce qu'on efface est l'enfant gauche
                if (parent->left_son == this)
                    parent->left_son = NULL;
                else
                    ///si ce qu'on efface est l'enfant droit
                    parent->right_son = NULL;

                delete this->pinfo;
                delete this;
            }
        }

        ///si le noeud courant N'est PAS une feuille
        else
        {
            ///si la feuille est un enfant gauche
            if (leaf->parent->left_son == leaf)
                leaf->parent->left_son = NULL;
            else
                ///si la feuille est un enfant droit
                leaf->parent->right_son = NULL;

            //delete this->pinfo; //optionnel

            ///l'info du noeud courant devient l'info de la feuille
            this->pinfo = leaf->pinfo;
            delete leaf;
        }
    }

    void removeInfo(T x)
    {
        BinaryTree<T> *t = find(x);
        if (t != NULL)
            t->remove();
    }

    void preOrderTraversal()
    {
        ///affiche, gauche, droit
        cout<<*pinfo <<" ";
        if (left_son != NULL)
            left_son->preOrderTraversal();
        if (right_son != NULL)
            right_son->preOrderTraversal();
    }

    void postOrderTraversal()
    {
        ///gauche, droit, affiche
        if (left_son != NULL)
            left_son->postOrderTraversal();
        if (right_son != NULL)
            right_son->postOrderTraversal();
        cout<<*pinfo <<" ";
    }

    void inOrderTraversal()
    {
        ///gauche, affiche, droit
        if (left_son != NULL)
            left_son->inOrderTraversal();
        cout<<*pinfo <<" ";
        if (right_son != NULL)
            right_son->inOrderTraversal();
    }

    void preOrderTraversalLevels(int level)
    {
        int i;
        for (i = 0; i < level; i++)
            cout<<"-";
        cout<<*pinfo<<endl;

        if (left_son != NULL)
            left_son->preOrderTraversalLevels(level + 1);
        if (right_son != NULL)
            right_son->preOrderTraversalLevels(level + 1);
    }

        int max = 0;
        void findMaxLevel(int level)
    {
        int i;
        int aux = 0;
        for (i = 0; i < level; i++){
            cout<<"-";
            aux+=1;
        }
        cout<<aux<<endl;

        if (aux > max)
            max = aux;
        if (left_son != NULL)
            left_son->findMaxLevel(level + 1);
        if (right_son != NULL)
            right_son->findMaxLevel(level + 1);
    }
};

int main()
{
    BinaryTree<int> *r = new BinaryTree<int>;
    r->setRoot(r); /// optionnel
    r->insert(6);
    r->insert(8);
    r->insert(1);
    r->insert(9);
    r->insert(10);
    r->insert(4);
    r->insert(13);
    r->insert(1);
    r->insert(12);

    cout<<"Preorder1\n";
    r->preOrderTraversal();

    cout<<"\nPreorder2\n";
    r->preOrderTraversalLevels(0);

    cout<<"\nPostorder\n";
    r->postOrderTraversal();

    cout<<"\nInorder\n";
    r->inOrderTraversal();

    cout<<"\n\n";
    cout<<r->find(100)<<endl;
    cout<<r->find(10)<<endl;
    //(r->find(6))->remove();
    //cout<<"La racine: "<<*(r->pinfo)<<endl;

    cout<<"_______\n"<<*r->find(10)->pinfo;
    cout<<"\n"<<r->find(4);
    cout<<"\n"<<r->find(12);
    cout<<"\n"<<r->find(8)<<endl;

    r->findMaxLevel(0);
    return 0;
}

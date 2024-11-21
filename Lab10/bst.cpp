#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

//definition recursive (meme principe que pour l'arbre binaire classique)
template<typename T> class BinarySearchTree {
    public:
        //le noeud courant a des references vers:
        //root, left child, right child, parent
        BinarySearchTree<T> *root, *left_son, *right_son, *parent;
        //info du noeud courant
        T *pinfo;

        //constructeur
        BinarySearchTree() {
            left_son = right_son = NULL;
            root = this;
            pinfo = NULL;
        }

        void setInfo(T info) {
            pinfo = new T;
            *pinfo = info;
        }

        void insert(T x) {
            if (pinfo == NULL)
                setInfo(x);
            else
                insert_rec(x);
        }

        ///fonction d'insertion depend de la valeur qu'on veut ajouter
        ///si elle doit etre dans le sous-arbre gauche / droit
        void insert_rec(T x) {
            int next_son;
			if (x <= (*pinfo))
                next_son = 0; //0 -> gauche
            else
                next_son = 1; // 1 -> droit

            if (next_son == 0)
            {
                if (left_son == NULL)
                { ///enfant gauche
                    left_son = new BinarySearchTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;
                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                }
                else
                    left_son->insert_rec(x);

            }
            else
            { /// enfant droit
                if (right_son == NULL)
                {
                    right_son = new BinarySearchTree<T>;
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

		BinarySearchTree<T>* find(T x) {
            BinarySearchTree<T> *rez;

            if (pinfo == NULL)
                return NULL;

            if ((*pinfo) == x)
                return this;

            if (x <= (*pinfo))
            {
                if (left_son != NULL)
                    return left_son->find(x);
                else
                    return NULL;
            }
            else
            {
                if (right_son != NULL)
                    return right_son->find(x);
                else
                    return NULL;
            }
        }

        void removeInfo(T x) {
            BinarySearchTree<T> *t = find(x);
            if (t != NULL)
                t->remove();
        }


		void remove() {
            BinarySearchTree<T> *p;
            T *paux;

            if (left_son == NULL && right_son == NULL)
            {
                if (parent == NULL)
                { /// this == root
                    delete this->pinfo;
                    root->pinfo = NULL;
                }
                else ///leaf
                {
                    if (parent->left_son == this)
                        parent->left_son = NULL;
                    else
                        parent->right_son = NULL;

                    delete this->pinfo;
                    delete this;
                }
            }
            else
            {
                if (left_son != NULL)
                {
                    p = left_son;
                    while (p->right_son != NULL)
                        p = p->right_son;
                }
                else
                { /// right_son != NULL
                    p = right_son;
                    while (p->left_son != NULL)
                        p = p->left_son;
                }

                paux = p->pinfo;
                p->pinfo = this->pinfo;
                this->pinfo = paux;
                p->remove();
            }
        }

        void inOrderTraversal() {
            if (left_son != NULL)
                left_son->inOrderTraversal();

            cout<<*pinfo<<" ";

            if (right_son != NULL)
                right_son->inOrderTraversal();
        }


        void preOrderTraversal(){
            cout<<*pinfo<<" ";
            if (left_son != NULL)
                left_son->preOrderTraversal();

            if (right_son != NULL)
                right_son->preOrderTraversal();
        }

        void postOrderTraversal(){
            if (left_son != NULL){
                left_son->postOrderTraversal();}

            if (right_son != NULL){
                right_son->postOrderTraversal();}

            cout<<*pinfo<<" ";
        }

        int maximumHeight()
        {
            if(this==NULL)
                return -1;
            else
                return max(this->left_son->maximumHeight(),this->right_son->maximumHeight()) +1;
        }


        void displayLevel(int level)
        {
            if(this==NULL)
                return;

            if(level==0)
                cout<<*this->pinfo<<" ";
            else
            {
                this->left_son->displayLevel(level-1);
                this->right_son->displayLevel(level-1);
            }
        }

        void displayAllLevels()
        {
            for(int i=0; i<= maximumHeight(); i++)
            {
                cout<<"Level "<<i<<": ";
                displayLevel(i);
                cout<<endl;
            }
        }

        void displayMax(){
            BinarySearchTree<T> *p;

            p = this;
            while (p->right_son != NULL)
            {
                p = p->right_son;
            }

            cout << *p->pinfo << endl;
            
        }

        void RangeQuerySimple(T k1,T k2){
            if (this == NULL)
                return;
            else{
                if (*pinfo < k1)
                    right_son->RangeQuerySimple(k1, k2);
                else if (*pinfo > k2)
                    left_son->RangeQuerySimple(k1, k2);
                else {
                    left_son->RangeQuerySimple(k1, k2);
                    cout << *pinfo << endl;
                    right_son->RangeQuerySimple(k1, k2);
                }
            }
        }

};

template <typename T>
void rotateRight(BinarySearchTree<T>* r)
{
    //algo
    BinarySearchTree<T> *p = r;
    //r == noveau
    //p == ancien

    r = p->left_son;
    p->left_son = r->right_son;
    r->right_son = p;

    r->displayAllLevels();
}

int main(){

    BinarySearchTree<char> *r = new BinarySearchTree<char>();

    r->insert('G');
    r->insert('B');
    r->insert('A');
    r->insert('C');
    r->insert('D');
    r->insert('F');
    r->insert('E');
    r->insert('Z');

    cout<<"In order: ";
    r->inOrderTraversal();
    cout<<endl;
    cout<<"Pre order: ";
    r->preOrderTraversal();
    cout<<endl;
    cout<<"Post order: ";
    r->postOrderTraversal();


    cout<<endl;

    r->displayMax();

    cout<<endl;
    r->RangeQuerySimple('C', 'F');

    rotateRight(r);
}
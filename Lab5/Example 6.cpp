#include <iostream>
using namespace std;

void modify1 (int a[]){
    a[2] = 15;
}

void modify2 (int *a)
{
    *(a + 2) = 15; //meme effet que modiafy1
}

int main()
{
    int x[] = {1,2,3,4};
    cout<<"Avant l'appel de la fonction:"<< x[2] <<endl;
    modify1(x);

    int *p = x;//meme chose que
    /* int *p = &x[0]
        modify2(p)
        modify2(x) */
    cout<< "Apres l'appel de la fonction:"<< x[2] <<endl;
    
    return 0;
}
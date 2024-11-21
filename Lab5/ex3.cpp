#include <iostream>
using namespace std;

template<typename T>
void inverserP(T *tab, int tab_size) {
    T aux[tab_size];

    for (int i = 0; i < tab_size; i++)
    {   
        aux[i] = *(tab + i);
    }
     
     for (int i = 0; i < tab_size; i++)
    {   
        *(tab + i) = aux[tab_size - 1 - i];
    }
}

int main()
{
    
    int tab[3] = {1,2,3};
    int size = 3;

    inverserP(tab, size);

    for (int i = 0; i < 3; i++)
    {
        cout << tab[i];
    }
    
    
    
    return 0;
}
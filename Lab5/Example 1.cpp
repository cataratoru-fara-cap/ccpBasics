#include <iostream>
using namespace std;

int main() {
    int *px;
    int x = 5;
    px = &x;

    cout<<"Adresse de la variable x:" << &x << endl;
    cout<< "Valeure de la var x:" << x << endl;
    cout<<"Adresse de la variable px:" << &px << endl;
    cout<< "Valeur pointeur px:" << px << endl;
    cout<< "Px point a:" << *px << endl;
    
    return 0;
}
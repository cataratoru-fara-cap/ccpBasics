#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int tab[6];
    int *p;
    
    for (int i = 0; i < 6; i++)
    {   
        p = &tab[i];
        cout << "gimmie number: ";
        cin >> *p;

    }
    
    for (int i = 5; i >= 0; i--)
    {
        p = &tab[i];
        cout << *p << endl;
    }
    
    return 0;
}
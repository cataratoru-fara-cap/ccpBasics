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
    
    for (int i = 0; i < 6; i++)
    {
        cout << tab[i] << endl;
    }
    
    return 0;
}

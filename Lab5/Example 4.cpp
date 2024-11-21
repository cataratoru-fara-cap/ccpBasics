#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char s[] = "Hello world";

    char *ps;
    ps = &s[1];// if we initialise later the values before are lost, the pointing is liniar not circular

    char *pa;
    pa = s;

    cout<<"ps point a:"<<*ps<<endl;

    //Edge case: char* affiche une sequence de caracteres
    //on doit force la conversion au pointeru vide pout obtenir la adresse

    cout<<ps<<endl;
    cout<<(void*)ps<<endl;

    while (*ps)
    {
        cout<< "L'adresse"<<(void*)ps<<"et le contenu: "<<*ps<<endl;
        ps++;
    }
    
    return 0;
}

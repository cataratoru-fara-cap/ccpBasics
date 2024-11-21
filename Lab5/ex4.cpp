#include <iostream>
using namespace std;
const char* getDep(char *p){
    while (*p)
    {
        if (*p == ','){
            return p + 2;
        }
        p++;
    }
    return nullptr;
}

int main (){
    char tab[] = "Slatina, OT";
    char *p = &tab[0];
    cout << "Department est: " << getDep(p)<< endl;
    
    return 0;
}
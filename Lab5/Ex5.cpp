#include <iostream>
using namespace std;

char *commaReplacer(char *p){
    char *c = &p[0]; 
    while (*p)
    {
        if(*p == 'c')
            *p = ' ';
        p++
    }

    return c;
}

int main(int argc, char const *argv[])
{
    cout << commaReplacer(char *p)
    return 0;
}

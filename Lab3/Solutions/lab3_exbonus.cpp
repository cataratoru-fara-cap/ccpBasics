#include <iostream>
#include "mystack.h"
#include<cstring>
using namespace std;

int main()
{
    char s[1000],aux[1000];
    int j=0;
    cin.get(s, 1000);
    for(int i=0; i<strlen(s); i++)
        if(s[i]!=32)
            aux[j++]=s[i];

    Stack <char>t;
    for(int i=0; i<strlen(aux); i++)
        t.push(aux[i]);

        int sem=1;
        for(int i=0; i<strlen(aux); i++)
            if(aux[i]!=t.pop())
            sem=0;
    if(sem)
        cout<<"palyndrome";
    else
        cout<<"not palyndrome";
    return 0;
}

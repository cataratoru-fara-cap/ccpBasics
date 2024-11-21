#include <iostream>
#include <cstring>
#include "mystack.h"

using namespace std;

int main(){
    char s[50];
    Stack <char> princ, aux;

    cout << "Introduce a string to be checked, that is less than 50 chars \n";
    cin.get(s, 50);
    int len = strlen(s);
    int j = strlen(s) - 1;

    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') {
            princ.push(s[i]);
            }
        if (s[j] != ' '){
            aux.push(s[j]);
        }
        j--;

    }


    while (!aux.isEmpty() && !princ.isEmpty()){
        char aux_char = aux.pop();
        char princ_char = princ.pop();
            if (aux_char != princ_char)
            {
                cout << "not palindrome";
                return 1;
            }
    }

    cout << "Is palindrome";
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int mat [3][3] = {{2,3,4}, {5,6,7}, {8,9,10}};
    int *pmat = mat[0]; //mat[0] contient l'adresse du premier el

    //int *pmat = &mat[0][0]; la meme chose

    for (int i = 0; i < 9; i++)
        cout<< *(pmat++) << " ";
    
    return 0;

}
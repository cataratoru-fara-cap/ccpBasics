#include <iostream>

using namespace std;

template <typename T>
void swap_ab (T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

//bubble sort
template<typename T>
void bubbleSortMaxIsLast(T v[5]){
    //variable declar
    bool ok = false;
    int n = 5;

    while(!ok){
        ok = true;
        for (int i = 0; i < n - 1; i++) 
            if (v[i] > v[i+1]) {
                swap_ab (v[i], v[i+1]);
                ok = false;
                } // reset ok   
        //decrement for the max
        n--;
    }
}

int main()
{
    int a[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "give me numbers:\n";
        cin >> a[i];
    }

    bubbleSortMaxIsLast(a);
    std::cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
    

}

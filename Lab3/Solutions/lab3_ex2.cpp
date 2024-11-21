#include <iostream>

using namespace std;

template <typename T>
void mySwap(T &a, T &b)
{
    T aux;
    aux=a;
    a=b;
    b=aux;
}

template <typename T>
void mySort(T v[])
{
    for(int i=0; i<4; i++)
        for(int j=i+1; j<5; j++)
            if(v[i]>v[j])
                mySwap(v[i], v[j]);

}

int main()
{
    int a[5];

    for(int i=0; i<5; i++)
        cin>>a[i];

    mySort(a);

    for(int i=0; i<5; i++)
        cout<<a[i]<<" ";

    return 0;
}

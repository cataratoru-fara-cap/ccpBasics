#include <iostream>
#include "minHeap.h"
#include "maxHeap.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    minHeap<int> minHeap(n/2);
    maxHeap<int> maxHeap(n/2 - 1);

    for (size_t i = 0; i < n/2 ; i++)
    {
        minHeap.insertElement(arr[i]);
    }
    
    for (int i = n/2; i < n; i++)
    {
        maxHeap.insertElement(arr[i]);
    }
    
    for (size_t i = 0; i < n/2 ; i++)
    {
        arr[i] = minHeap.extractMin();
    }
    
    for (int i = n/2; i < n; i++)
    {
        arr[i] = maxHeap.extractMax();
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
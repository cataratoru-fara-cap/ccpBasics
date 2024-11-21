#include <iostream>
using namespace std;
template<typename T> class Heap {
    public:
        T *H;
        int currentDim, maxDim;

        Heap(int maxDim) {
            this->maxDim = maxDim;
            H = new T[this->maxDim];
            currentDim = -1;
        }

        void filterDown(int i) {
            T vaux;

            while(i) {
                int leftChild = 2 * i + 1;
                int rightChild = 2 * i + 2;
                int smallest = 1;
                if(leftChild <= currentDim && H[leftChild] < H[smallest])
                    smallest = leftChild;
                if(rightChild <= currentDim && H[rightChild] < H[smallest])
                    smallest = leftChild;

                if(smallest != i){
                    vaux = H[i];
                    H[i] = H[smallest];
                    H[smallest] = vaux;
                    i = smallest;
                } else
                break;
            }
        }
        int parent(int i){
            return (i-1) / 2;
        }

        int leftChild(int i){
            return 2*i + 1;
        }

        int rightChild(int i){
            return 2*i + 2;
        }

        void displayHeap() {
            int level = 0;
            int start = 0;
            int level_elements = 1;
            while (start <= currentDim) {
                cout << "Level " << level << ": ";
                for (int i = 0; i < level_elements && start <= currentDim; i++) {
                    cout << H[start] << " ";
                    start++;
                }
                cout << endl;
                level_elements *= 2;
                level++;
            }
        }

        void insertElement(T x) {
            if (currentDim == maxDim-1) {
                cout<< "Error!"<<endl;
                return;
            }
            currentDim++;
            H[currentDim] = x;
            filterUp(currentDim);
        }

	    T peek() {
            if (currentDim == -1) {
                cout<< "Error!"<<endl;
                T x;
                return x;
            }

            return H[0];
        }

        T deleteElement() {
            if (currentDim == -1) {
                cout<< "Error!"<<endl;
                T x;
                return x;
            }

            T minValue = H[0];
            H[0] = H[currentDim];
            currentDim--;
            if (currentDim > 0)
                filterDown();

            return minValue;
        }

        void filterUp(int l) {
            int parent;
            T vaux;

            parent = (l-1) / 2;
           while (l > 0 && H[parent] > H[l]) {
                vaux = H[parent];
                H[parent] = H[l];
                H[l] = vaux;

                l = parent;
                parent = (l-1) / 2;
            }
        }
        void filterDown() {
           int l = 0;
            T vaux;

            while (1) {
                if (2 * l + 1 > currentDim) {
                    if (2 * (l+1) > currentDim)
                        break;
                     else if (H[2 *(l+1)] < H[l]) {
                        vaux = H[2 * (l+1)];
                        H[2 * (l+1)] = H[l];
                        H[l] = vaux;
                        l = 2 * (l+1);
                    }
                    else
                        break;
                }
                else {

                    if (H[2 * (l+1) ] <= H[2 * l + 1] && H[2 * (l+1) ] < H[l]) {
                        vaux = H[2 * (l+1)];
                        H[2 * (l+1)] = H[l];
						H[l] = vaux;
                        l = 2 * (l+1);
                    }
                    else
                    if (H[2 * l + 1] <= H[2 * (l+1)] && H[2 * l + 1] < H[l]) {
                        vaux = H[2 * l + 1];
                        H[2 * l + 1] = H[l];
                        H[l] = vaux;
                        l = 2 * l + 1;
                    }
                    else
                        break;
                }
            }
        }
};

int main() {
    Heap<int> heap(100);

    int elements[] = {25,  17,  36,  2,  3, 100, 1, 17, 19};

    for(int i:elements){
        heap.insertElement(i);
    }
    heap.displayHeap();
    cout << endl;

    cout << heap.peek() << endl;
    cout << heap.deleteElement() << endl;
    cout << heap.deleteElement() << endl;
    cout << heap.peek() << endl;


    return 0;
}


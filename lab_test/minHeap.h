#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

///implementation du MIN HEAP a l'aide du vecteur
template<typename T> class minHeap {
    public:
        T *H;
        int currentDim, maxDim;

        Heap(int maxDim) {
            this->maxDim = maxDim;
            H = new T[this->maxDim];
            currentDim = -1;
        }


		///fonction pour inserer un element dans le tas
        void insertElement(T x) {
            if (currentDim == maxDim-1) {
                fprintf(stderr, "Error!\n");
                return;
            }
            currentDim++;
            H[currentDim] = x;
            filterUp(currentDim);
	    }


		///fonction qui retourne la racine, mais ne la supprime pas
		T peek() {
            if (currentDim == -1) {
                fprintf(stderr, "Error!\n");
                T x;
                return x;
            }

            return H[0];
        }

        ///fonction qui efface et affiche le plus petit element (la racine)
		T extractMin() {
            if (currentDim == -1) {
                fprintf(stderr, "Error!\n");
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

    }

		///fonction appelle par la fonction d'insertion pour maintenir les proprietes du heap
        void filterUp(int i) {
            int parent;
            T vaux;

            parent = (i-1) / 2;
            while (i > 0 && H[parent] > H[i]) {
                vaux = H[parent];
                H[parent] = H[i];
                H[i] = vaux;

                i = parent;
                parent = (i-1) / 2;
            }
        }
        
        ///fonction appelle par la fonction d'effacement pour maintenir les proprietes du heap
         void filterDown() {
            int i = 0;
            T vaux;

            while (1) {
                if (2 * (i + 1) > currentDim) {
                    if (2 * i + 1 > currentDim)
                        break;
                    else
                    ///Si on a un seul enfant - gauche
                        if (H[2 * i + 1] < H[i]) {
                            vaux = H[2 * i+1];
                            H[2 * i+1] = H[i];
                            H[i] = vaux;
                            i = 2 * i + 1;
                        }
                        else
                            break;

                    }
                else {
                        ///Voir lequel des enfants est le plus petit
                    if (H[2 * (i+1)] <= H[2 * i + 1] &&
                        H[2 * (i+1)] < H[i]) {
                        
                        vaux = H[2 * (i+1)];
                        H[2 * (i+1)] = H[i];
						H[i] = vaux;
                        i = 2 * (i+1);
                    }
                    else
                        if (H[2 * i + 1] <= H[2 * (i+1)] && H[2 * i + 1] < H[i]) {
                            vaux = H[2 * i + 1];
                            H[2 * i + 1] = H[i];
                            H[i] = vaux;
                            i = 2 * i + 1;
                        }
                        else
                            break;
                }
            }
         };

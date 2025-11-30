#include <iostream>
using namespace std;

int heapArr[100];
int heapSize = 0;

void insertPQ(int x) {
    heapArr[heapSize] = x;
    int i = heapSize;
    heapSize++;

    while (i != 0 && heapArr[(i - 1) / 2] < heapArr[i]) {
        swap(heapArr[i], heapArr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax() {
    if (heapSize == 0) return -1;

    int root = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;

    // heapify
    int i = 0;
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;

        if (l < heapSize && heapArr[l] > heapArr[largest]) largest = l;
        if (r < heapSize && heapArr[r] > heapArr[largest]) largest = r;

        if (largest != i) {
            swap(heapArr[i], heapArr[largest]);
            i = largest;
        } else break;
    }

    return root;
}

int main() {
    insertPQ(30);
    insertPQ(10);
    insertPQ(50);

    cout << extractMax() << endl; 
    cout << extractMax() << endl;

    return 0;
}

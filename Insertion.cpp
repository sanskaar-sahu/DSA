#include<iostream>
using namespace std;

class MaxHeap {
    int* arr;
    int size;         // Current size of heap
    int total_size;   // Capacity of heap

public:
    MaxHeap(int capacity) {
        total_size = capacity;
        arr = new int[total_size];
        size = 0;
    }

    void insert(int el) {
        if (size == total_size) {
            cout << "Heap is full\n";
            return;
        }

        // Place the element at the end
        int index = size;
        arr[index] = el;
        size++;

        // Heapify up (bubble up)
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

int main(){
    MaxHeap h(5);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.printHeap();
    return 0;
}
#include<iostream>
using namespace std;

class MaxHeap {
    int* arr;
    int size;
    int total_size;

public:
    MaxHeap(int cap) {
        arr = new int[cap];
        total_size = cap;
        size = 0;
    }

    void insert(int el) {
        if (size == total_size) {
            cout << "Heap is full\n";
            return;
        }

        int index = size;
        arr[index] = el;
        size++;

        // Bubble up
        while (index > 0 && arr[index] > arr[(index - 1) / 2]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }
        cout<<"The deleted element is " << arr[0]<<endl;
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
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
    MaxHeap h(10);
    h.insert(1);
    h.insert(4);
    h.insert(10);
    h.deleteMax();
    h.insert(40);
    h.insert(111);
    h.insert(400);
    h.deleteMax();
    h.printHeap();

}
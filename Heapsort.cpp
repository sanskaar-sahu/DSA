#include<iostream>
using namespace std;


void heapify(int arr[] , int i , int n){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && arr[largest] < arr[left] ){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right] ){
        largest = right;
    }
    if(largest!= i){
       swap(arr[largest] , arr[i]);
       heapify(arr,largest,n);
    }
}

void loopHeapify(int arr[], int i, int n) {
    while (i < n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;  // continue heapifying at the swapped child
        } else {
            break;  // heap property is satisfied
        }
    }
}


void buildHeap(int arr[], int n){
   for(int i = n/2 - 1; i>=0;i--){
     loopHeapify(arr , i , n);
   }
}


void heapSort(int arr[] , int n){
    for(int i = n-1 ; i >= 0 ; i--){
        swap(arr[0] , arr[i]);
        loopHeapify(arr,0,i);
    }
}

void printArr(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[6] = {1,3,5,6,10,8};
    buildHeap(arr,6);
    heapSort(arr,6);
    printArr(arr,6);

    return 0;
}
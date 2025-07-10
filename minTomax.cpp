#include<iostream>
#include<vector> 
using namespace std;

void heapify(vector<int>&nums , int i , int n){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && nums[left] > nums[largest]){
        largest = left;
    }
    if(right < n && nums[right] > nums[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(nums[largest] , nums[i]);
        heapify(nums , largest , n);
    }

}
void convertHeap(vector<int>&nums){
   int n = nums.size();
   for(int i = n/2 -1 ; i >= 0; i--){
      heapify(nums , i , n);
   }
}

int main(){
    vector<int>heapy = {20,30,40,50,60};
    convertHeap(heapy);
    return 0;
}
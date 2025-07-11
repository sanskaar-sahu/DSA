// User function Template for C++
#include<iostream>
class Solution {
  public:
    int heapHeight(int N, int arr[]) {
        int cnt = 0;
        while(N>1){
            N = N/2;
            cnt++;
        }
        return cnt;
        
    }
};
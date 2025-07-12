#include <bits/stdc++.h> 
int maximumChocolates(vector<int> &arr, int k){
    // Write your code here.
    priority_queue<int>q;
    for(int num : arr){
        q.push(num);
    }
    long long total_choc = 0;

    while(k>0){
        int choc = q.top();
        q.pop();
        total_choc+= choc;
        q.push(choc/2);
        k--;
    }
    return total_choc % 100007;
}
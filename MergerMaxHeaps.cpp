
#include<iostream>
#include<vector>
#include<queue>
class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int>q;
        int i = 0 , j=0;
        while(i < n && j < m){
            q.push(a[i]);
            q.push(b[j]);
             i++;
             j++;
        }
        
        while(i < n){
            q.push(a[i]);
            i++;
        }
        
        while(j < m){
            q.push(b[j]);
            j++;
        }
        
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
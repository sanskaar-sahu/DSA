#include<queue>
#include<iostream>
using namespace std;

int minCost(int arr[] , int N){
    priority_queue<int , vector<int> , greater<int>>q;
    for(int i = 0 ; i <N; i++){
        q.push(arr[i]);
    }
    int totalcost =0;
    while(q.size() >1){
       int top1 = q.top() ; q.pop();
       int top2 = q.top() ; q.pop();
       int cost = top1 +top2;
       totalcost+= cost;
    }
    return totalcost;
}
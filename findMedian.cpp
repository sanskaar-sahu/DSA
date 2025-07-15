/*
Problem link : https://leetcode.com/problems/find-median-from-data-stream/
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int , vector<int> , greater<int>>rightMinHeap;
    priority_queue<int>leftMaxHeap;
    MedianFinder(){
    }
    
    void addNum(int num) {
        if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            rightMinHeap.push(num);
        }

        balanceHeap();
    }

    void balanceHeap(){
        if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } else if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        } else {
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
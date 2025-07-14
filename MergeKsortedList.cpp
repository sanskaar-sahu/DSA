/*

problem link : https://leetcode.com/problems/merge-k-sorted-lists/submissions/1697480089/

*/




#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }

    Node() {
        this->next = nullptr;
    }
};

// Min-heap comparator
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;  // min-heap
    }
};

class Solution {
public:
    Node* mergeList(vector<Node*> arr) {
        priority_queue<Node*, vector<Node*>, Compare> q;

        // Push all non-null heads
        for (auto root : arr) {
            if (root) q.push(root);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!q.empty()) {
            Node* smallest = q.top();
            q.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                q.push(smallest->next);
            }
        }

        return dummy->next;
    }
};

/*
You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]

*/

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

#include<iostream>

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
    
    
    int totalNode(Node * root){
        if(!root ) return 0;
        
        return 1 + totalNode(root->left) + totalNode(root->right);
    }
    
    
    bool isCBT(Node * root , int index ,  int nodes){
        if(!root) return true;
        if(index >= nodes) return false;
        
        return isCBT(root->left , 2*index + 1 , nodes) && isCBT(root->right , 2*index + 2 , nodes);
        
    }
    
    bool isMaxHeap(Node*root){
        //No child exist
        if(!root->left && !root->right) return true;
        
        
        //left child exist
        if(root->left && !root->right){
            return root->data >= root->left->data && isMaxHeap(root->left);
        }
        
        //both child exist
        if(root->left&& root->right){
            return (
            root->data >= root->left->data && root->data >= root->right->data &&
            isMaxHeap(root->left) && isMaxHeap(root->right)
            );
            
        }
        
        //only right child exist 
        return false;
    }
    
    bool isHeap(Node* tree) {
        // code here
        
        //Calculate total nodes 
        int nodes = totalNode(tree);
        
        //check for index not greater than total nodes i.e is cbt
        bool ans = isCBT(tree ,0, nodes);
        
        if(!ans) return 0;
        
        //check for heap property
        
        return isMaxHeap(tree); 
    }
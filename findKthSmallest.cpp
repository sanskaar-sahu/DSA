/*

Problem Link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

*/

#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (k == 1) return matrix[0][0];
        if (k == n * n) return matrix[n - 1][n - 1];

        // Min heap: {value, {row, col}}
        priority_queue< pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> minHeap;

        // Initialize heap with first element of each row
        for (int i = 0; i < n; i++) {
            minHeap.push({matrix[i][0], {i, 0}});
        }
        int ans = 0;

        while (k--) {
            auto [val, coords] = minHeap.top(); minHeap.pop();
            int row = coords.first, col = coords.second;
            ans = val;

            // Push next element from the same row
            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], {row, col + 1}});
            }
        }

        return ans;

    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxUnit(vector<vector<int>>& boxes, int truckSize) {
        sort(boxes.begin(), boxes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1]; // Sort by units per box in descending order
        });

        int maxi = 0;
        int i = 0;
        while (truckSize > 0 && i < boxes.size()) {
            if (boxes[i][0] <= truckSize) {
                maxi += boxes[i][0] * boxes[i][1];
                truckSize -= boxes[i][0];
            } else {
                maxi += truckSize * boxes[i][1];
                truckSize = 0;
            }
            i++;
        }
        return maxi;
    }
};

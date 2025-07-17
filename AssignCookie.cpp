#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int content = 0;
        int i=0;  //greed array
        int j = 0; // cookie array
        while(i < g.size() && j < s.size()){
            int cookie = s[j];
            int greed = g[i];
            if(cookie >= greed){
                content++;
                i++;
            }
            j++;

        }
    
     return content;

    }
};
#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        if (stones.empty())
            return 0;
        if (stones.size() == 1)
            return stones[0];
        priority_queue<int> q;
        for (int num : stones)
        {
            q.push(num);
        }

        while (q.size() > 1)
        {
            int y = q.top();
            q.pop(); // heavy1
            int x = q.top();
            q.pop(); // heavy2;
            if (y > x)
            {
                q.push(y - x);
            }
        }

        return q.empty() ? 0 : q.top();
    }
};
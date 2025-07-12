
/**
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.

If there is more than one pile with the maximum number of gifts, choose any.

Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.

Return the number of gifts remaining after k seconds.

Example 1:

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:

- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.

 */
#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Solution
{

public:
    int floorSqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;

        int start = 1, end = x, ans = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            // Use division to avoid mid*mid overflow
            if (mid <= x / mid)
            {
                ans = mid;       // mid is a possible answer
                start = mid + 1; // try for a bigger value
            }
            else
            {
                end = mid - 1; // try for a smaller value
            }
        }

        return ans;
    }
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> q;
        for (int gift : gifts)
        {
            q.push(gift);
        }
        while (k > 0)
        {
            int pile = q.top();
            q.pop();
            q.push(floorSqrt(pile));
            k--;
        }
        long long total = 0;
        while (!q.empty())
        {
            total += q.top();
            q.pop();
        }
        return total;
    }
};
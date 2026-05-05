#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int cur = i%n;
            while (!st.empty() && nums[st.top()] <= nums[cur])
            {
                st.pop();
            }
            if(!st.empty())res[cur] = st.top();
            st.push(nums[cur]); 
        }
        return res;
    }
};
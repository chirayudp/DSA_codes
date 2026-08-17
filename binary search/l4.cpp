#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        int n = nums1.size(), m = nums2.size();
        int l = 0 ; int h = m; 
        while (l <= h)
        {
            int i = l + (h - l)/2;
            int j = (m + n + 1)/2 - i; // we always want the median to be in the left half of the partioned arrays 

            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == n)? INT_MAX : nums1[i];

            int left2 = (i == 0) ? INT_MIN : nums1[j - 1];
            int right2 = (i == n)? INT_MAX : nums1[j];

            if(left1 <= right2 && left2<= right1 ){
                if((m+n)%2 == 0)return max(left1,right2);
                return (left1+right2)/2.0;
            }
        }
        

    }
};

int main(){
int n; cin >> n;

}
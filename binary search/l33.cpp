#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int search(vector<int>& arr, int target) {
        int l=0,h=arr.size();
        while (l<h)
        {
            int mid = l + (h-l)/2;
            if(mid == target)return mid;
            if (arr[l]<arr[mid]){
                //left is sorted
                if(arr[l] < target && target < arr[mid]){
                    h= mid-1;
                }
                else l = mid + 1;
            }
            // right is sorted
            else{
                if(arr[mid] < target && target < arr[h]){
                    l = mid + 1;
                }
                else h= mid-1;
            }
        }
        return -1;
    }
};

int main(){
int n; cin >> n;

}

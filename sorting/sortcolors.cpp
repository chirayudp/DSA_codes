#include <iostream>
using namespace std;

void sortColors(int* nums, int n) {
    int nums2[3]={0};
    for (int i = 0; i < n; i++) {
        nums2[nums[i]]++;
    }
    int p=0;
    while(nums2[0]-- ){
    nums[p++]=0;
    }
    while(nums2[1]--){
    nums[p++]=1;
    }
    while(nums2[2]--){
    nums[p++]=2;
    }
}
int main(){
int narr[]={0,1,2,0,2,0,1,2};
int n = sizeof(narr)/sizeof(narr[0]);
sortColors(narr ,n) ;
for (int i = 0; i < n; i++)
{
    cout << narr[i] << " ";
}
}



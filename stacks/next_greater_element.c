
int* nextGreaterElement(int* nums1, int n1, int* nums2, int n2, int* returnSize) {
    int next[10001]={-1};
    for (int i = 1; i < 10001; i++)
    {
        next[i]=-1;
    }
    
    int top=-1;
    int stack[n2];
    for (int i = 0; i < n2; i++)
    {
        while (top>=0 && next[i] > stack[top])  next[stack[top--]]=nums2[i];
        stack[++top]=nums2[i];
    }
    
    for (int i = 0; i < 20; i++)
    {
        printf("%d ",next[i]);
    }
    int* arr = malloc(sizeof(int)*n1);
    for (int i = 0; i < n1; i++)
    {
        arr[i]=next[i+1];
    }
    return arr;
}
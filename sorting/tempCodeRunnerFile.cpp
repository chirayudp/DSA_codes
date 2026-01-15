int *merge(int a,int b, int* ar, int *br){
    int* cr = new int[a+b];
    int i=0,j=0;
    for (int k = 0; k < a+b; k++)
    {
        if (i>=a)
        {
            cr[k]=br[j++];
        }
        else if (j>=b)
        {
            cr[k]=ar[i++];
        }
        else if (ar[i]<=br[j])
        {
            cr[k]=ar[i++];
        }
        else cr[k]=br[j++];
        
    }
    return cr;
}
int* mergesort(int* arr,int n){
    if (n<=1)return arr;
    int mid=n/2;
    int* left=new int[mid];
    int* right = new int[n-mid];
    for (int i = 0; i < mid; i++)
    {
        left[i]=arr[i];
    }
    for (int i = mid; i < n; i++)   // Can also put them all in one loop with if condition block;
    {
        right[i-mid]=arr[i];
    }
    left = mergesort(left,mid);
    right = mergesort(right,n-mid);
    arr = merge(mid,n-mid,left , right);
    return arr;
}

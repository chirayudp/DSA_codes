void nextPermutation(int* nums, int n) {
    int p = 0;
    int piv = nums[n - 1];
    for (int i = n - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            p = 1;
            piv = i - 1;
            break;
        }
    }
    if (p == 0) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
        return;
    }
    int j = n ;
    while (j > piv) {
        if (nums[--j] > nums[piv]) {
            break;
        }
    }
    int tmp = nums[j];
    nums[j] = nums[piv];
    nums[piv] = tmp;

    int l = piv+1, r = n - 1;
    while (l <= r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
    }
    return;
}

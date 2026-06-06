int freq[201];

int compare(const void* a, const void* b) {
    int n1 = *(int*)a;
    int n2 = *(int*)b;

    int f1 = freq[n1 + 100];
    int f2 = freq[n2 + 100];

    if (f1 == f2)
        return n2 - n1;   // same frequency → decreasing value

    return f1 - f2;       // increasing frequency
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    for (int i = 0; i < 201; i++)
        freq[i] = 0;

    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + 100]++;

    qsort(nums, numsSize, sizeof(int), compare);

    return nums;
}

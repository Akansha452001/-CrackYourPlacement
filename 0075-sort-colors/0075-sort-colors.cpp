class Solution {
public:
int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start];
    int i = start + 1;
    int j = end;

    while (i <= j) {
        // Find the first element greater than the pivot
        while (i <= end && nums[i] <= pivot) {
            i++;
        }
        // Find the first element less than or equal to the pivot
        while (j >= start && nums[j] > pivot) {
            j--;
        }
        // Swap elements at i and j if i is less than j
        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }
    // Place the pivot element at its correct position
    swap(nums[start], nums[j]);

    return j;
}

void quicksort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int j = partition(nums, start, end);
        quicksort(nums, start, j - 1); // Sort left part
        quicksort(nums, j + 1, end);   // Sort right part
    }
}

void sortColors(vector<int>& nums) {
    quicksort(nums, 0, nums.size() - 1);
}
};
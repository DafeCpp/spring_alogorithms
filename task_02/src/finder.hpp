int FindIdOfBounder(int size, int* nums) {
    int left{0};
    int right{size - 1};
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (nums[mid] == 0) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
// ... (rest of the code)

// Assuming the input values are sorted in descending order
int findMaxCount(int target) {
    int left = 0, right = balls.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (balls[mid] <= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right;
}


for (int count : balls) {
    int maxCount = findMaxCount(count);
    // ... (rest of the logic using maxCount)
}
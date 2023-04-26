class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) {
        swap(nums1, nums2);
        swap(m, n);
    }
    int left = 0;
    int right = m;
    while (left <= right) {
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;
        if (i < right && nums2[j-1] > nums1[i]) {
            left = i + 1;
        } else if (i > left && nums1[i-1] > nums2[j]) {
            right = i - 1;
        } else {
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j-1];
            } else if (j == 0) {
                maxLeft = nums1[i-1];
            } else {
                maxLeft = max(nums1[i-1], nums2[j-1]);
            }
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }
            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = min(nums1[i], nums2[j]);
            }
            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}
};
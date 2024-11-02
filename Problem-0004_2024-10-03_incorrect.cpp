// Runtime: 23ms | 68.30%
// Memory:  95.58MB | 34.23%

// Approach 1: Merge the arrays and find the median of the result
// However, this is O(m + n), not O(log(m + n))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i1{0}, i2{0};

        while (i1 < nums1.size() && i2 < nums2.size()) {
            if (nums1[i1] < nums2[i2]) {
                nums3.push_back(nums1[i1]);
                ++i1;
            } else {
                nums3.push_back(nums2[i2]);
                ++i2;
            }
        }

        while (i1 < nums1.size()) {
            nums3.push_back(nums1[i1]);
            ++i1;
        }

        while (i2 < nums2.size()) {
            nums3.push_back(nums2[i2]);
            ++i2;
        }

        int medianIndex = nums3.size() / 2;
        if (nums3.size() % 2 == 0) {
            return (double)(nums3[medianIndex - 1] + nums3[medianIndex]) / 2.0;
        } else {
            return (double)nums3[medianIndex];
        }
    }
};
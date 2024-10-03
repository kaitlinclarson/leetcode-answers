// Runtime: 50ms | 32.86%
// Memory:  13.00MB | 72.12%

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i{-1};
        int j{-1};
        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
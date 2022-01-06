// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n);
        sums[0] = nums[0];
        for (int i = 1; i < n; i++){
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = sums[j] - sums[i] + nums[i];
                if (sum >= target) {
                    ans = min(ans, (j - i + 1));
                    break; 
                }
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
    
};
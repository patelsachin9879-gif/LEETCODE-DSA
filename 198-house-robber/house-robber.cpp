class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int prev1 = nums[0];               // Represents dp[i-2]
        int prev2 = max(nums[0], nums[1]); // Represents dp[i-1]
        int result = prev2;
        
        for (int i = 2; i < n; i++) {
            result = max(prev2, prev1 + nums[i]);
            prev1 = prev2;                 // Move prev1 forward
            prev2 = result;                // Move prev2 forward
        }
        
        return result;
    }
};
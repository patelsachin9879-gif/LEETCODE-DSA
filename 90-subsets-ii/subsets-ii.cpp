class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        if(i == nums.size()){
            allSubsets.push_back(ans);
            return;
        }
        
        // Include the current element
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);
        
        // Backtrack
        ans.pop_back(); 
        
        // Skip duplicates for the "exclude" branch
        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }

        // Exclude the current element and all its duplicates
        getAllSubsets(nums, ans, idx, allSubsets);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        
        // Sorting is crucial to bring duplicates together
        sort(nums.begin(), nums.end());
        getAllSubsets(nums, ans, 0, allSubsets);
        
        return allSubsets;
    }
};
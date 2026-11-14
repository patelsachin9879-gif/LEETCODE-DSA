class Solution {
public:
    // set<vector<int>> s;
    void getAllCombinations(vector<int>& arr,int idx, int tar, vector<vector<int>>& ans, vector<int>&combin){
        if(idx==arr.size()||tar<0){
            return;
        }
        if(tar==0){
            ans.push_back(combin);
            return;
        }
        combin.push_back(arr[idx]);
        getAllCombinations(arr,idx, tar- arr[idx],ans,combin);
        combin.pop_back();
        getAllCombinations(arr,idx+1,tar,ans,combin);

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(arr,0,target,ans,combin);
        return ans;
    }
};
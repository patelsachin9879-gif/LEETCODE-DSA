class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        // Sort the array to easily manage duplicates and use two pointers
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            // Skip duplicates for the first element
            if(i > 0 && arr[i] == arr[i-1]) continue; 
            
            for(int j = i + 1; j < n; j++) {
                // Skip duplicates for the second element
                if(j > i + 1 && arr[j] == arr[j-1]) continue; 
                
                int p = j + 1, q = n - 1;
                while(p < q) {
                    long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[p] + (long long)arr[q];
                    
                    if(sum < tar) {
                        p++;
                    } else if(sum > tar) {
                        q--;
                    } else {
                        ans.push_back({arr[i], arr[j], arr[p], arr[q]});
                        p++;
                        q--;
                        
                        // Skip duplicates for the third element
                        while(p < q && arr[p] == arr[p-1]) p++; 
                        
                        // Skip duplicates for the fourth element
                        while(p < q && arr[q] == arr[q+1]) q--; 
                    }
                }
            }
        }
        return ans;
    }
};
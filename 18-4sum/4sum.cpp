class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n; a++) {
            if(a>0 && nums[a]==nums[a-1]) continue;
            for (int b = a + 1; b < n; b++) {
                if(b!=a+1 && nums[b]==nums[b-1]) continue;
                int c = b+1;
                int d = n - 1;
                while (c < d) {
                    long long sum=nums[a];
                    sum+=nums[b];
                    sum+=nums[c];
                    sum+=nums[d];
                    if (sum < target) {
                        c++;
                    } else if (sum > target) {
                        d--;
                    } else {
                        vector<int>temp={nums[a] , nums[b] , nums[c] , nums[d]};
                        ans.push_back(temp);
                        c++;
                        d--;
                        while(c<d && nums[c]==nums[c-1]) c++;
                        while(c<d && nums[d]==nums[d+1]) d--;
                    }
                }
            }
        }
        return ans;
    }
};
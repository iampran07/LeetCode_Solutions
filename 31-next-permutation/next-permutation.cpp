class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1, n=nums.size();
        //longest prefix match
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        
        //check if idx is still -1 or not
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //swap the closest integer with it
        for(int i=n-1;i>idx;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        //sort the remaining part
        sort(nums.begin()+idx+1,nums.end());
    }
};
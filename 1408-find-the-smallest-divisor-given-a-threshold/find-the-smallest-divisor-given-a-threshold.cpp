class Solution {
public:

    bool possible(vector<int>nums, int threshold, int mid){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=ceil((double)nums[i]/(double)mid);
        }
        return ans<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
       int maxi=INT_MIN;
       for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
       } 

       int low=1, high=maxi;

       while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(nums,threshold,mid)==true){
            high=mid-1;
        }else{
            low=mid+1;
        }
       }
       return low;
    }
};
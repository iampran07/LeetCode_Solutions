class Solution {
public:
    int firstOccur(vector<int>& nums, int target){
        int n=nums.size();
        int low=0, high=n-1, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }

    int lastOccur(vector<int>& nums, int target){
        int n=nums.size();
        int low=0, high=n-1, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccur(nums,target);
        if(first==-1) return{-1,-1};
        int last=lastOccur(nums,target);
        return {first,last};
    }
};
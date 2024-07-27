class Solution {
public:

    bool canPossible(vector<int>arr,int k,int mid){
        int sum=arr[0], partition=1;
        for(int i=1;i<arr.size();i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                partition+=1;
                sum=arr[i];
            }
        }

        return partition<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum=0, maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);
        }

        int low=maxi, high=sum;

        while(low<=high){
            int mid=(low+high)/2;

            if(canPossible(nums,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }
};
class Solution {
public:
    bool possible(vector<int>arr, int days, int mid){
        int sum=0, reqdays=1;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                reqdays+=1;
                sum=arr[i];
            }else{
                sum+=arr[i];
            }
        }
        return reqdays<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }

        int low=maxi, high=sum;
        while(low<=high){
            int mid=(low+high)/2;

            if(possible(weights,days,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
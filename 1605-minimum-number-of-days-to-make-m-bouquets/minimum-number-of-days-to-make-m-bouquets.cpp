class Solution {
public:
    bool possible(vector<int>arr, int days, int m, int k){
        int noB=0, cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=days) cnt++;
            else{
                noB+=(cnt/k);
                cnt=0;
            }
        }
        noB+=(cnt/k);
        return noB>=m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(val>arr.size()) return -1;
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }

        int low=mini, high=maxi;

        while(low<=high){
            int mid=(low+high)/2;

            if(possible(arr,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
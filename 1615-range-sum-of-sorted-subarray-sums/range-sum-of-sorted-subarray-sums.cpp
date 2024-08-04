class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>arr;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                arr.push_back(sum);
            }
        }

        sort(arr.begin(),arr.end());
        const int mod= 1e9+7;
        int result=0;
        for(int i=left-1;i<right;i++){
            result=(result+arr[i]) % mod;
        }
        return result;
    }
};
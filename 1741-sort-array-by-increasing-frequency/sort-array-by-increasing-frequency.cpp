class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int i:nums){
            freq[i]++;
        }

        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if (freq[n1] != freq[n2]) {
                return freq[n1] < freq[n2];
            } else {
                
                return n2 < n1;
            }
        });
        return nums;
    }
};
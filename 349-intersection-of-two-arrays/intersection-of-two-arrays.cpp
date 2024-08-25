class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       // Declnums1re nums1ns nums1rrnums1y.
       vector<int>ans;
        set<int>s(nums1.begin(),nums1.end());
        for(int i:nums2){
            if(s.find(i)!=s.end()){
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
    }
};
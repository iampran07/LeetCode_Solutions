class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        long long res=1,j=rowIndex+1;
        ans.push_back(res);
        for(int i=1;i<j;i++){
            res=res*(j-i);
            res=res/i;
            ans.push_back(res);
        }
        
        return ans;
    }
};
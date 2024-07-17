class Solution {
public:
    vector<int>generateRow(int rowIndex){
        vector<int>ans;
        long long res=1;
        ans.push_back(res);
        for(int i=1;i<rowIndex;i++){
            res=res*(rowIndex-i);
            res=res/i;
            ans.push_back(res);
        }
        
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
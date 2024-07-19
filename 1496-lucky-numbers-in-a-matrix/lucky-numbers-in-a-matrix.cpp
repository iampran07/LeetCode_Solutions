class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> rowMin;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int row = INT_MAX;
            for (int j = 0; j < m; j++) {
                row = min(row, matrix[i][j]);
            }
            rowMin.push_back(row);
        }

        vector<int>colMax;
        for (int i = 0; i < m; i++) {
            int col = INT_MIN;
            for (int j = 0; j < n; j++) {
                col = max(col, matrix[j][i]);
            }
            colMax.push_back(col);
        }

        vector<int>ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j]==rowMin[i] && matrix[i][j]==colMax[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
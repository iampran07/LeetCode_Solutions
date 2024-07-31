class Solution {
public:
    int n,maxi;
    vector<vector<int>>tmp;
    int dp[1001][1001];
    int rec(int ind,int curr_height,int curr_width){
        //pruning
        //base case
        if(ind>=n)return curr_height;
        //cache check
        if(dp[ind][curr_width]!=-1)return dp[ind][curr_width];
        //transitions
        int a=1e6;
        if(curr_width+tmp[ind][0]<=maxi){
            a=rec(ind+1,max(curr_height,tmp[ind][1]),curr_width+tmp[ind][0]);
        }
        int b=curr_height+rec(ind+1,tmp[ind][1],tmp[ind][0]);
        //save and return
        int ans=min(a,b);
        return dp[ind][curr_width]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf) {
        memset(dp,-1,sizeof(dp));
        n=books.size();
        maxi=shelf;
        tmp=books;
        int ans=rec(0,0,0);
        return ans;
    }
};
class Solution {
public:
    int helper(string s, int i, int j){
        int cnt=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            cnt+=helper(s,i,i);
            cnt+=helper(s,i,i+1);
        }
        return cnt;
    }
};
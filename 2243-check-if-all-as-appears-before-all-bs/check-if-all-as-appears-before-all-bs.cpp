class Solution {
public:
    bool checkString(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[i]=='a' && st.top()=='b'){
                return false;
            }else{
                st.push(s[i]);
            } 
        }
        return true;
    }
};
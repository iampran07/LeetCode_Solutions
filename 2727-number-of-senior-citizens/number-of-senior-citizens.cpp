class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(const auto str:details){
            string age=str.substr(11,2);
            int num=stoi(age);
            if(num>60) count++;
        }
        return count;
    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(const auto str:details){
            if(str[11]==54 && str[12]==48) continue;
            else if(str[11]>=54 && str[12]>=48){
                count++;
            }
        }
        return count;
    }
};
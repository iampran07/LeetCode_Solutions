class Solution {
public:
    int findComplement(int num) {
        int helper=0;
        int temp=num;

        while(temp!=0){
            helper= (helper<<1)| 1;
            temp >>= 1;
        }

        return (~num) & helper;
    }
};
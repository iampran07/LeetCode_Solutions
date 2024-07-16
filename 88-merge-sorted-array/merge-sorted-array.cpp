class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());
        /*
        if(n==0) return;
        int end=nums1.size()-1;
        while(n>0 && m>0){
            if(nums2[n-1]>=nums1[m-1]){
                nums1[end]=nums2[n-1];
                n--;
            }
            else{
                nums1[end]=nums1[m-1];
                m--;
            }
            end--;
        }
        while(n>0){
            nums1[end]=nums2[n-1];
            n--;
            end--;
        }
        */
    }
};
class Solution {
public:
    int cnt = 0;
    void merge(vector<int>& a, int low, int mid, int high) {
        int left = low, right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {
            if (a[left] <= a[right]) {
                temp.push_back(a[left]);
                left++;
            } else {
                temp.push_back(a[right]);  
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(a[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(a[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }
    }

    void revpairs(vector<int>& a, int low, int mid, int high){
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)a[i]>(long long)2*a[right]){
                right++;
            }    
            cnt+=(right-(mid+1));
        }
    }

    void mergeSort(vector<int>& a, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        revpairs(a,low,mid,high);
        merge(a, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};
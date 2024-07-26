class Solution {
public:
    bool valid(vector<int>& piles, double mid, int h) {
        long long t = 0;
        for (auto x : piles) {
            t += ceil(x / mid);  
        }
        return t <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long ans = 0, high = 0;
        for (int i = 0; i < piles.size(); i++) {
            high = max(high, (long long)piles[i]);  
        }
        long long low = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (valid(piles, mid, h)) {
                // can be a possible answer
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
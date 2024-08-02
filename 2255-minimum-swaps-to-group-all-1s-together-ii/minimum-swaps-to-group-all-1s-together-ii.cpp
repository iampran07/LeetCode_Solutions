class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
    int countOnes = 0;

    for (int num : nums) {
        if (num == 1) countOnes++;
    }

    if (countOnes == 0) return 0;

    vector<int> extendedNums(nums.begin(), nums.end());
    extendedNums.insert(extendedNums.end(), nums.begin(), nums.end());

    int maxOnesInWindow = 0;
    int currentOnes = 0;

    for (int i = 0; i < extendedNums.size(); i++) {
        if (i < countOnes) {
            currentOnes += extendedNums[i];
        } else {
            currentOnes += extendedNums[i] - extendedNums[i - countOnes];
        }
        if (i >= countOnes - 1) {
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }
    }

    return countOnes - maxOnesInWindow;
    }
};
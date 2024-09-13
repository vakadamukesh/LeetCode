class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);  // Calculate the total sum of elements

        // Split the array into two halves
        vector<int> left(nums.begin(), nums.begin() + n / 2);  // Left half of the array
        vector<int> right(nums.begin() + n / 2, nums.end());   // Right half of the array

        // Find all possible subset sums of the left part using bitmasking
        vector<vector<int>> leftSums(left.size() + 1);

        for (int bitmask = 0; bitmask < (1 << left.size()); bitmask++) {
            int setbits = __builtin_popcount(bitmask);  // Count the set bits (elements) in bitmask
            int sum = 0;

            for (int i = 0; i < left.size(); i++) {
                if (bitmask & (1 << i)) sum += left[i];  // Add selected elements to the sum
            }

            leftSums[setbits].push_back(sum);  // Store the subset sum
        }

        // Find all possible subset sums of the right part and add them to hash sets
        vector<unordered_set<int>> rightSums(right.size() + 1);

        for (int bitmask = 0; bitmask < (1 << right.size()); bitmask++) {
            int setbits = __builtin_popcount(bitmask);  // Count the set bits (elements) in bitmask
            int sum = 0;

            for (int i = 0; i < right.size(); i++) {
                if (bitmask & (1 << i)) sum += right[i];  // Add selected elements to the sum
            }

            // Multiply sum with the size of nums before inserting into hashset for easier checking
            rightSums[setbits].insert(n * sum);
        }

        // Go through each sum in leftSums and check if there are subsets that satisfy the condition
        for (int i = 0; i <= left.size(); i++) {
            for (int sum : leftSums[i]) {
                // Check for all possible sizes of the subset
                for (int l = max(i, 1); l < i + right.size(); l++) {
                    int leftlen = i;
                    int rightlen = l - i;

                    // Check if the required value exists in the hashset of the right part
                    if (rightSums[rightlen].count((totalSum * l) - (n * sum))) {
                        return true;  // If found, return true
                    }
                }
            }
        }

        return false;  // If no valid subset is found, return false
    }
};
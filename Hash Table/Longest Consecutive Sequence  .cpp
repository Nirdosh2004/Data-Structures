class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Initialize variables
        int n = nums.size(); // Size of the input vector
        unordered_set<int> s; // Unordered set to store unique elements from the input vector
        
        // Insert all elements from the vector into the unordered set
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        
        // Initialize variable to store the longest consecutive sequence length
        int ans = 0;
        
        // Iterate through each element of the vector
        for(int i = 0; i < n; i++) {
            // If nums[i] - 1 exists in the set, then it's part of another sequence, so skip
            if(s.find(nums[i] - 1) != s.end()) {
                continue;
            } else {
                // If nums[i] - 1 doesn't exist, it is the start of a sequence
                int count = 0; // Initialize count for this sequence
                int current = nums[i]; // Set current to the start of the sequence
                
                // Keep incrementing current until no consecutive number exists in the set
                while(s.find(current) != s.end()) {
                    count++; // Increment count for each consecutive number
                    current++; // Move to the next consecutive number
                }
                
                // Update ans with the maximum count encountered
                ans = max(ans, count);
            }
        }
        
        // Return the length of the longest consecutive sequence
        return ans;
    }
};

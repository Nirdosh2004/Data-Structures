class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen; // Initialize an unordered set to store seen elements
        
        // Iterate through each element of the input vector
        for(auto x : nums) {
            // If the current element is already seen, return true (contains duplicate)
            if(seen.count(x) > 0) {
                return true;
            }
            seen.insert(x); // Otherwise, insert the current element into the set
        }
        
        // If no duplicates found, return false
        return false;
    }
};

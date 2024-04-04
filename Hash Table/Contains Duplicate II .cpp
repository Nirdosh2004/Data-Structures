class Solution {
public:
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//       time = O(N)
// space = O(N)
        unordered_map<int, int> mp; // Initialize an unordered map to store elements and their indices
        
        // Iterate through each element of the input vector
        for(int i = 0; i < nums.size(); i++) {
            // If the current element is already in the map
            if(mp.count(nums[i])) {
                // Check if the difference between the current index and the previous occurrence
                // of the same element is less than or equal to 'k'
                if(abs(i - mp[nums[i]]) <= k)
                    return true; // If yes, return true (there is a nearby duplicate)
            }
            
            mp[nums[i]] = i; // Update the index of the current element in the map
        }
        
        // If no nearby duplicates found, return false
        return false;
    }
};

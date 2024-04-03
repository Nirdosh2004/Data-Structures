class Solution {
public:
    // Function to group anagrams from a given vector of strings
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Time Complexity: O(n * k log k)
        // Space Complexity: O(n * k)
        vector<vector<string>> ans; // Initialize a vector to store the grouped anagrams
        unordered_map<string , vector<string>> mp; // Initialize an unordered_map to store sorted strings and their corresponding original strings
        
        // Iterate through each string in the input vector
        for(auto str : strs){
            string s = str; // Make a copy of the current string
            sort(s.begin() , s.end()); // Sort the characters of the string alphabetically
            
            // Add the original string to the corresponding group based on the sorted string
            mp[s].push_back(str);
        }
        
        // Iterate through the map and add each group of anagrams to the answer vector
        for(auto x : mp){
            ans.push_back(x.second); // Push back the vector of original strings for each group of anagrams
        }
        
        return ans; // Return the vector containing grouped anagrams
    }
};

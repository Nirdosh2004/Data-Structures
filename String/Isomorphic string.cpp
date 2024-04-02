class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Initialize two maps to store characters from strings and their corresponding positions
        map<char, int> mp1;
        map<char, int> mp2;
        
        // Iterate through the strings
        for (int i = 0; i < s.length(); i++) {
            // If the positions of characters in the two strings do not match, they are not isomorphic
            if (mp1[s[i]] != mp2[t[i]]) {
                return false;
            }
            // Update the position of the characters in the maps
            mp1[s[i]] = i + 1;
            mp2[t[i]] = i + 1;
        }
        // If all characters have matched positions, the strings are isomorphic
        return true;
    }
};

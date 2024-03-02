class Solution {
public:
    // Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        int n = s.length(); // Length of the input string
        int left = 0 , maxLength = 0; // Initialize variables for left pointer and maximum length
        unordered_set<char> charSet; // Set to keep track of characters in the current substring
        
        // Loop through the string from left to right
        for(int right = 0 ; right < n ;right++){
            // If the character at 'right' is not in the set
            if(charSet.count(s[right]) == 0){
                charSet.insert(s[right]); // Add the character to the set
                maxLength = max(maxLength , right - left + 1); // Update maximum length if needed
            }
            else{
                // If the character at 'right' is already in the set, we need to adjust the substring
                while(charSet.count(s[right])){
                    charSet.erase(s[left]); // Remove characters from the left until the duplicate character is removed
                    left++; // Move the left pointer
                }
            }
            charSet.insert(s[right]); // Add the current character to the set
        }
        return maxLength; // Return the maximum length of substring without repeating characters
    }
};

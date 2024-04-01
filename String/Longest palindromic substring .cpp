class Solution {
public:
    string longestPalindrome(string s) {
        // If the length of the string is less than or equal to 1, it is already a palindrome
        if(s.length() <= 1){
            return s;
        }
        // Lambda function to expand from the center of a palindrome
        auto expand_from_center = [&](int left , int right){
            // While characters at left and right pointers are equal and not out of bounds
            while(left >= 0 && right < s.length() && s[right] == s[left]){
                left--; // Move left pointer to the left
                right++; // Move right pointer to the right
            }
            // Return the substring which is the palindrome
            return s.substr(left+1 , right - left - 1);
        };
        // Initialize the maximum palindrome substring to the first character of the string
        string maxStr = s.substr(0,1);
        // Loop through each character of the string as potential center points
        for (int i=0 ; i<s.length()-1 ; i++){
            // Find the longest palindrome substring with odd length centered at current position
            string odd = expand_from_center(i,i);
            // Find the longest palindrome substring with even length centered at current position
            string even = expand_from_center(i , i+1);
            // Update the maximum palindrome substring if the current one is longer
            if(odd.length() > maxStr.length()){
                maxStr = odd;
            }
            if(even.length() > maxStr.length()){
                maxStr  = even;
            }
        }
        // Return the longest palindrome substring found
        return maxStr;
    }
};

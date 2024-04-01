class Solution {
public:
    // Function to convert the given string into ZigZag pattern with numRows rows
    string convert(string s, int numRows) {
        vector<string> ans(numRows); // Vector to store strings for each row
        if(numRows == 1){ // If numRows is 1, return the original string
            return s;
        }
        int i=0; // Index to track the current row
        bool flag = false; // Flag to indicate the direction of traversal

        // Loop through each character in the input string
        for(auto ch : s){
            ans[i] += ch; // Append the character to the current row string
            // Change direction when reaching the top or bottom row
            if(i == 0 || i == numRows-1){
                flag = !flag;
            }
            // Update the row index based on the direction
            if(flag){
                i+= 1; // Move down
            }
            else{
                i -= 1; // Move up
            }
        }

        string zigzag = ""; // String to store the ZigZag pattern

        // Concatenate all strings in the vector to form the ZigZag pattern
        for (auto str : ans){
            zigzag += str;
        }

        // Return the ZigZag pattern
        return zigzag;
    }
};

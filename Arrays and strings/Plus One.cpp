// Define a class Solution
class Solution {
public:
    // Function to add one to a number represented as an array of digits
    vector<int> plusOne(vector<int>& v) {
        // Get the size of the input vector
        int n = v.size();
        
        // Iterate through the vector from right to left
        for(int i = n - 1; i >= 0; i--) {
            // Increment the last digit by 1
            if(i == n - 1) {
                v[i]++;
            }
            
            // Handle carry if the digit becomes 10
            if(v[i] == 10) {
                v[i] = 0;
                
                // If not the leftmost digit, carry over to the next digit
                if(i != 0) {
                    v[i - 1]++;
                }
                // If leftmost digit, insert a new digit at the beginning
                else {
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        // Return the modified vector
        return v;
    }
};

class Solution {
public:
    // Function to convert a string to an integer
    int myAtoi(string s) 
    {

      //time -> O(N) space -> O(1)
        int i=0; // Initialize index for string traversal
        int sign=1; // Initialize sign for positive integer
        long ans=0; // Initialize variable to store the result

        // Skip leading whitespaces
        while(i<s.length() && s[i]==' ')
            i++;

        // Check for sign
        if(s[i]=='-')
        {
            sign=-1; // Set sign to negative
            i++; // Move to next character
        }
        else if(s[i]=='+')
            i++; // Move to next character

        // Convert characters to integer
        while(i<s.length())
        {
            // If character is a digit, convert it to integer and append to result
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+(s[i]-'0');
                // Check for overflow or underflow
                if(ans>INT_MAX && sign==-1)
                    return INT_MIN; // Return INT_MIN if result is too small
                else if(ans>INT_MAX && sign==1)
                    return INT_MAX; // Return INT_MAX if result is too large
                i++; // Move to next character
            }
            else
                return ans*sign; // Return result with sign if character is not a digit
        }
        return (ans*sign); // Return final result with sign
    }
};

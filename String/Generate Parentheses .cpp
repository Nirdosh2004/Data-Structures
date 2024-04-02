class Solution {
public:
    // Helper function to generate valid combinations of parentheses
    // curr: the current string being constructed
    // openPar: count of open parentheses in the current string
    // closedPar: count of closed parentheses in the current string
    // n: total number of pairs of parentheses to generate
    // res: vector to store valid combinations of parentheses
    // Time complexity: O(2^n) since at each position, we have two choices: to add an open or closed parenthesis
    // Space complexity: O(2^n) since the recursive tree can have a maximum of 2^n leaves
    void helper(string curr, int openPar, int closedPar, int& n, vector<string>& res) {
        // Base case: if the count of open and closed parentheses reaches n
        if (openPar == n && closedPar == n) {
            res.push_back(curr); // Add the current string to the result
            return;
        }
        // Add open parentheses if we haven't reached the limit of open parentheses
        if (openPar < n) {
            helper(curr + '(', openPar + 1, closedPar, n, res);
        }
        // Add closed parentheses if it doesn't exceed the count of open parentheses
        if (closedPar < openPar) {
            helper(curr + ')', openPar, closedPar + 1, n, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res; // Initialize the result vector
        helper("", 0, 0, n, res); // Call the helper function with initial parameters
        return res; // Return the result vector
    }
};

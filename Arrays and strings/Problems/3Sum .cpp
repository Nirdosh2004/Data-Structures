class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // time complexity : O(n^2), and  space complexity : O(n^2).
        vector<vector<int>> storage; // Vector to store the result triplets
        int n = nums.size(); // Size of the input vector
        
        sort(nums.begin(), nums.end()); // Sorting the input vector in ascending order
        
        for(int a = 0 ; a < n - 2 ; a++) { // Loop through each element until the third last element
            if(a > 0 && nums[a] == nums[a - 1]) { // Skip duplicate elements for 'a'
                continue;
            }
            int b = a + 1; // Pointer 'b' starts from the next element after 'a'
            int c = n - 1; // Pointer 'c' starts from the last element
            
            while(b < c) { // Loop until 'b' is less than 'c'
                int sum = nums[a] + nums[b] + nums[c]; // Calculate the sum of the triplet
                
                if(sum == 0) { // If sum is zero, it means we found a valid triplet
                    storage.push_back({nums[a], nums[b], nums[c]}); // Add the triplet to the result vector
                    
                    // Skip duplicate elements for 'b' and 'c'
                    while(b < c && nums[b] == nums[b + 1])
                        b++;
                    while(b < c && nums[c] == nums[c - 1])
                        c--;
                    
                    b++; // Move 'b' to the next unique element
                    c--; // Move 'c' to the next unique element
                } else if(sum < 0) { // If sum is less than zero, move 'b' forward
                    b++;
                } else { // If sum is greater than zero, move 'c' backward
                    c--;
                }
            }
        }
        return storage; // Return the result vector containing unique triplets
    }
};

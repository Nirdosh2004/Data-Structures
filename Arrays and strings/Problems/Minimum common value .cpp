class Solution {
public:
    // Time Complexity: O(min(n, m)), where n is the size of nums1 and m is the size of nums2.
    //                  Traverses through both arrays once.
    // Space Complexity: O(1), constant extra space used.
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common = INT_MAX; // Initialize common variable with maximum integer value
        int i = 0 , j= 0; // Initialize pointers for both arrays
        
        // Traverse both arrays until either of them is exhausted
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) { // If both elements are equal, we found the common element
                common = nums1[i]; // Update common variable with the common element
                break; // Break the loop as we found the common element
            }
            else if(nums1[i] < nums2[j]) { // If element in nums1 is less than element in nums2, move to the next element in nums1
                i++;
            }
            else { // If element in nums1 is greater than element in nums2, move to the next element in nums2
                j++;
            }
        }
        
        // Return common element if found, otherwise return -1
        return common != INT_MAX ? common : -1;
    }
};

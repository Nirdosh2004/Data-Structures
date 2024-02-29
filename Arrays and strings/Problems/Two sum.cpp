class Solution {
public:
    // Time complexity: O(n^2) - where n is the size of nums
    // Nested loop iterating over the elements of nums
    // Space complexity: O(1) - constant space for indices i and j
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size() ;i++){
            for(int j=i+1 ;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                   return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

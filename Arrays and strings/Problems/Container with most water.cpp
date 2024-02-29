class Solution {
public:
    int maxArea(vector<int>& height) {
        // Time complexity: O(n)
    // Space complexity: O(1)
         int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        // Loop until left and right pointers meet.
        while (left < right) {
            // Calculate the area between the lines.
            int area = (min(height[left], height[right]) * (right - left));
            // Update maxArea if current area is greater.
            maxArea = max(area, maxArea);
            // Move the pointer with smaller height towards the center.
            if (height[left] < height[right]) 
                left++;
            else
                right--;
        }
        return maxArea;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); //for size of the given string 
        int left = 0 ; //left pointer for counting the length till right
        int maxLength = 0; //for returning output
        unordered_set<char> charSet; //set that store all unrepeated charaters
        for(int right = 0 ; right < n ; right++){  //loop from beginning to end
            if(charSet.count(s[right])==0){ //if the character is not present in set than
                charSet.insert(s[right]);   //add to the set
                maxLength = max(maxLength , right - left + 1);  //update the maxLenght
            }
            else{   //else
                while(charSet.count(s[right])){ //if the character is already present in set than
                    charSet.erase(s[left]);  //erase from left of the string 
                    left++;  //increment the left pointer
                }
            }
            charSet.insert(s[right]);   //add to the set 
        }
        return maxLength;
    }
};

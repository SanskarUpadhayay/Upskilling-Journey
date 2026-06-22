/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:

Input: text = "nlaebolko"
Output: 1
Example 2:

Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
     vector<int> freq(26,0);
     for(int i=0;i<text.size();i++){
        freq[text[i]-'a']++;
     }   
     int res = INT_MAX;
     for(int i=0;i<26;i++){
        if(i ==0 || i==1 || i == 13 ){
            res=min(res,freq[i]);
        }
        else if(i==11 || i == 14 ){
            res=min(res, (freq[i]/2));
        }
     }
     return res;
    }
};

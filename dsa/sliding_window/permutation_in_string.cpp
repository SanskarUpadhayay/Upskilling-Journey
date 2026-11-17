/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n2<n1){
            return false;
        }
        vector<int> a1(26);
        vector<int> a2(26);
        int l=0,r=0;
        while(r<n1){
            a2[s2[r]-'a']++;
            a1[s1[r]-'a']++;
            r++;
        }
        if(a1==a2){
            return true;
        }
        while(r<n2){
            a2[s2[r]-'a']++;
            a2[s2[l]-'a']--;
            l++;
                if(a1 == a2){
                    return true;
                }
            r++;
        }
        return false;
    }
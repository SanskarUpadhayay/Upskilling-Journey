/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
*/

//Prefix and suffix array

vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]* nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(prefix[i]*suffix[i]);
        }
        return res;
    }

//Two pass using prefix and suffix variable

vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int prefix=1;
        for(int i=0;i<n;i++){
            res[i]=res[i]*prefix;
            prefix=nums[i]*prefix;
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            res[i]= res[i]*suffix;
            suffix=nums[i]*suffix;
        }
        return res;
    }
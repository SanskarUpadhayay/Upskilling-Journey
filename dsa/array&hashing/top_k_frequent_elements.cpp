/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/

//1. Hashmap + Sorting

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<vector<int>> temp;
        for(auto x: freq){
            temp.push_back({x.second,x.first});
        }
        sort(temp.begin(),temp.end(),[](vector<int> &a,vector<int>& b){
            return a[0]>b[0];
        });
        int i=0;
        vector<int> res;
        while(k--){
            res.push_back(temp[i][1]);
            i++;
        }
        return res;
    }

//2. Hashmap + Max heap

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x:freq){
            pair<int,int> cur= {x.second,x.first};
            pq.push(cur);
        }
        vector<int> res;
        while(k--){
            pair<int,int> top = pq.top();
            res.push_back(top.second);
            pq.pop();
        }
        return res;
    }

//3. Hashmap + Bucket Sort

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);

        for(auto &x:freq){
            bucket[x.second].push_back(x.first);
        }
        vector<int> res;
        for(int i=bucket.size()-1;i>=0;i--){
            if(k==0){
                break;
            }
            for(int num: bucket[i]){
                res.push_back(num);
                if(--k == 0){
                    break;
                }
            }
        }
        return res;
    }
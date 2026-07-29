/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

//Using prefix and suffix array

int trap(vector<int>& height) {
        int n=height.size();
        vector<int> px(n,0);
        px[0]=0;
        for(int i=1;i<n;i++){
            px[i]=max(height[i-1],px[i-1]);
        }
        vector<int> sx(n,0);
        sx[n-1]=0;
        for(int i=n-2;i>=0;i--){
            sx[i] = max(height[i+1],sx[i+1]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            int cur = min(px[i],sx[i])-height[i];
            res+=(cur>0) ? cur : 0;
        }
        return res;
    }

//Eliminating prefix array

int trap(vector<int>& height) {
        int n=height.size();
        int px=0;
        vector<int> sx(n,0);
        sx[n-1]=0;
        for(int i=n-2;i>=0;i--){
            sx[i] = max(height[i+1],sx[i+1]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            px=(i>0) ? max(height[i-1],px): 0;
            int cur = min(px,sx[i])-height[i];
            res+=(cur>0) ? cur : 0;
        }
        return res;
    }

//Eliminating both prefix and suffix array

int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int lmax=0,rmax=0;
        int res=0;
        while(left<=right){
            if(lmax<rmax){
                lmax=max(height[left],lmax);
                res+=lmax-height[left];
                left++;
            }
            else{
                rmax=max(height[right],rmax);
                res+=rmax-height[right];
                right--;
            }
        }
        return res;
    }
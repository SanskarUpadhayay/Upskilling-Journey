/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s=0,e=n-1;
        int row=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1] >=target){
                row=mid;
                break;
            }
            else if(matrix[mid][0]> target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        if(row==-1){
            return false;
        }
        int sc=0,ec=m-1;
                while(sc<=ec){
                    int midc = sc+(ec-sc)/2;
                    if(matrix[row][midc] == target){
                        return true;
                    }
                    else if(matrix[row][midc] > target){
                        ec=midc-1;
                    }
                    else{
                        sc=midc+1;
                    }
                }
        return false;
    }
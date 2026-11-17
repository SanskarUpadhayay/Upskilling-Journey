/*
Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one. 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,bool> helper(TreeNode* root){
        if(root==NULL){
            return {0,true};
        }
        pair<int,bool> left = helper(root->left);
        pair<int,bool> right = helper(root->right);
        if(left.second && right.second && abs(left.first-right.first) <=1){
            return {max(left.first,right.first)+1,true};
        }
        else{
            return {max(left.first,right.first)+1,false};
        }
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        pair<int,bool> ans=helper(root);
        return ans.second;
    }
};
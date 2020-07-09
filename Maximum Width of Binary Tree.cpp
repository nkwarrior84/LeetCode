/*

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        queue<pair<TreeNode*, pair<int, int>>> Q;
        signed int level = -1;
        unsigned int maxWidth = 0;
        unsigned int minIndx = 1, maxIndx = 1;
        Q.push({root, {0, 1}});
        while(!Q.empty()) {
            TreeNode* curr = Q.front().first;
            unsigned int currLevel = Q.front().second.first;
            unsigned int currIndx = Q.front().second.second;
            Q.pop();
            if(currLevel != level) {
                level = currLevel;
                maxWidth = max(maxWidth, maxIndx - minIndx + 1);
                minIndx = currIndx;
            }
            maxIndx = currIndx;
            if(curr->left) {
                Q.push({curr->left, {currLevel + 1, currIndx << 1}});
            }
            if(curr->right) {
                Q.push({curr->right, {currLevel + 1, ((currIndx << 1) | 1)}});
            }
        }
        maxWidth = max(maxWidth, maxIndx - minIndx + 1);
        return maxWidth;
        
    }
};
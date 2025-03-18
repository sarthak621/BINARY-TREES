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

    int findHeightOfLeft(TreeNode* root){
        int ans=0;
        while(root){
            ans++;
            root=root->left;
        }
        return ans;
    }

    int findHeightOfRight(TreeNode* root){
        int ans=0;
        while(root){
            ans++;
            root=root->right;
        }
        return ans;
    }

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int leftHt=findHeightOfLeft(root);
        int rightHt=findHeightOfRight(root);

        if(leftHt==rightHt) return (1<<leftHt)-1;

        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }

        
    }
};
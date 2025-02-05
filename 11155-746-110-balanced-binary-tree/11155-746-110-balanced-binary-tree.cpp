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

     int getHeight(TreeNode* root){
       if(root==NULL) return 0;

        int leftHt=getHeight(root->left);
        int rightHt=getHeight(root->right);

        return 1+max(leftHt,rightHt);
     }
    bool isBalanced(TreeNode* root) {
       if(root==NULL) return true;
        int leftHt=getHeight(root->left);
        int rightHt=getHeight(root->right);

        if(abs(leftHt-rightHt)>1) return false;
 
       // ab root ke left or right me ja kar check karo woh balanced h ya nahi  
       bool left=isBalanced(root->left);
       bool right=isBalanced(root->right);

       if(left==false|| right==false) return false;
       return true;


    }
};
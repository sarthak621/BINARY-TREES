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
    TreeNode* build(vector<int>& postorder,int postStart,int postEnd, 
                    vector<int>& inorder,int inStart,int inEnd, map<int,int>&inMap){
                        //base case
                        if(postStart>postEnd || inStart>inEnd) return NULL;

                        TreeNode* root= new TreeNode(postorder[postEnd]);

                        int inRoot=inMap[root->val];

                        int numsLeft=inRoot-inStart;

                        //recusive calls on left and right

                        root->left= build(postorder,postStart,postStart+numsLeft-1,
                                          inorder,inStart,inRoot-1,inMap);

                        root->right=build(postorder,postStart+numsLeft,postEnd-1,
                                          inorder,inRoot+1,inEnd,inMap);

                        return root;

                        
                    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        
        map<int,int>inMap;

        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }

        TreeNode* root= build(postorder,0,postorder.size()-1,
                              inorder,0,inorder.size()-1,inMap);
        return root;
        
    }

    
};
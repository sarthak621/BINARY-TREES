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
    vector<int> preorderTraversal(TreeNode* root) {
         //morris traversal T.C->O(n), S.C->O(1) 
         //copied from inorder code

        vector<int>result;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                result.push_back(curr->val);
                curr=curr->right;
            }
            else{
                // if current ka left child exist karta hai toh uspar jao or uske rightmost guy ko curr se connect kar do
                TreeNode* leftChild= curr->left;
                while(leftChild->right!=NULL){
                    leftChild=leftChild->right;
                }
                //ab rightmost guy tak pahunch gaye hai toh isko curr->right se connect kar do
                leftChild->right=curr->right; //change

                //curr->left ko null mark kar dete hai
                TreeNode* temp=curr; 
                result.push_back(temp->val); //change
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return result;
    
    }
};


// stack solution
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>preOrder;
//         if(root==NULL) return preOrder;
//         stack<TreeNode*>st;
//         st.push(root);

//         while(!st.empty()){
//                 TreeNode* topNode=st.top();
//                  preOrder.push_back(topNode->val);
//                 st.pop();
//                 if(topNode->right != NULL) st.push(topNode->right);
//                 if(topNode->left != NULL) st.push(topNode->left); 
//         }
//         return preOrder;
//     }
// };



//recursive solution
// class Solution {
// public:

//     void preOrder(TreeNode* root,vector<int>& ans){
//         if(root==NULL) return;

//         ans.push_back(root->val);
//         preOrder(root->left,ans);
//         preOrder(root->right,ans);

        
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
        
//         vector<int>ans;
//         preOrder(root,ans);

//         return ans;        
//     }
// };
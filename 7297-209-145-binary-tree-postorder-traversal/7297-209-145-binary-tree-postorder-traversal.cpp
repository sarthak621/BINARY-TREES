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

 //using 1 stack only
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         stack<TreeNode*>st1;
        vector<int>ans;

        if(root==NULL) return ans;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* top_el=st1.top();
            st1.pop();
            
            ans.push_back(top_el->val);

            if(top_el->left!=NULL) st1.push(top_el->left);
            if(top_el->right!=NULL) st1.push(top_el->right);
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};


//  //2 stack sol


// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         stack<TreeNode*>st1;
//         stack<TreeNode*>st2;
//         vector<int>ans;

//         if(root==NULL) return ans;
//         st1.push(root);
//         while(!st1.empty()){
//             TreeNode* top_el=st1.top();
//             st1.pop();
//             st2.push(top_el);

//             if(top_el->left!=NULL) st1.push(top_el->left);
//             if(top_el->right!=NULL) st1.push(top_el->right);
//         }

//         while(!st2.empty()){
//             TreeNode* top_el=st2.top();
//             st2.pop();
//             ans.push_back(top_el->val);
//         }
//         return ans;
//     }
// };


// // using recursion

// class Solution {
// public:
//     void postOrder(TreeNode* root,vector<int>&ans){
//         if(root==NULL) return;

//         postOrder(root->left,ans);
//         postOrder(root->right,ans);
//         ans.push_back(root->val);

//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>ans;

//         postOrder(root,ans);
//         return ans;
        
//     }
// };
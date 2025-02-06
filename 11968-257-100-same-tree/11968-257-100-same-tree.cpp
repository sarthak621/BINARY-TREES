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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //bfs approach
        if(p==NULL && q==NULL) return true;

        if(p==NULL || q==NULL) return false;
        
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            TreeNode* front1=q1.front();
            TreeNode* front2=q2.front();

            q1.pop();
            q2.pop();

            if(front1->val != front2->val) return false;

            if(front1->left!=NULL && front2->left!=NULL){
                q1.push(front1->left);
                q2.push(front2->left);
            } 
            else if(front1->left!=NULL || front2->left!=NULL) return false;


            if(front1->right!=NULL && front2->right!=NULL){
                q1.push(front1->right);
                q2.push(front2->right);
            }
            else if(front1->right!=NULL || front2->right!=NULL) return false;

        }
        return true;
    }
};


//recursive approach

//  bool isSameTree(TreeNode* p, TreeNode* q) {
//         //recusrsive approach
//         if(p==NULL && q==NULL) return true;
        
//         //agar dono me se ek bhi NULL ho jaye to return false
//         if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;

//         //value bhi same hona chaiye 
//         if(p->val != q->val) return false;

//         return isSameTree(p->left,q->left)&& isSameTree(p->right,q->right);
//     }
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
    int widthOfBinaryTree(TreeNode* root) {
        //using the level order traversal

        if(!root) return 0;
        long long int ans=0;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0}); //value of node and index of that node

        while(!q.empty()){

            long long int size=q.size();
            long long int minIndex=q.front().second; //for minimum index at that level
            
            long long int first,last;

            for(long long int i=0;i<size;i++){
                TreeNode* currNode=q.front().first;
                long long int currIndex=q.front().second-minIndex;

                q.pop();

                if(i==0){
                    //store the index of first node at that level
                    first=currIndex;
                }
                if(i==size-1){
                    //store the index of last node at that level
                    last=currIndex;
                }

                if(currNode->left) q.push({currNode->left,2*currIndex+1});
                if(currNode->right) q.push({currNode->right,2*currIndex+2});

            }
            ans=max(ans,last-first+1);
        }
        return ans;
        
    }
};
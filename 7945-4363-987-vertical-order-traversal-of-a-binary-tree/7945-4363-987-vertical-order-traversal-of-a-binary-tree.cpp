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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes; //vertical->lvl->nodes

        queue<pair<TreeNode*,pair<int,int>>>q; //node->vertical->lvl
        q.push({root,{0,0}});

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            //{1,{0,0}}
            TreeNode* frontNode=front.first;
            int x=front.second.first;
            int y=front.second.second;

            //map me dalna hai in values ko
            nodes[x][y].insert(frontNode->val);   //{ 0->0->1}
            if(frontNode->left){
                q.push({frontNode->left,{(x-1),(y+1)}});
            }
            if(frontNode->right){
                q.push({frontNode->right,{(x+1),(y+1)}});
            }
        }

        //map for tree
        //    3
        // 9     20
        //    15     7  

    //     //=> {
    //         0:{0:{3}},{2:{15}},
    //         -1:{1:{9}},
    //         1:{1:{20}},
    //         2:{2:{7}}
    //    }

    //now, we have to print the ans
    
    vector<vector<int>>ans;
    //applying the loop on the map
     
     
    for(auto m:nodes){
         vector<int>col;
         for(auto n:m.second){
            col.insert(col.end(),n.second.begin(),n.second.end());
         }
         ans.push_back(col);
    }
    return ans;


    }
};
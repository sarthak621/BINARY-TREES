/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s="";
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* frontNode=q.front();
                q.pop();

                if(frontNode==NULL) s.append("#,");
                else{
                    s.append(to_string(frontNode->val)+',');
                    q.push(frontNode->left);
                    q.push(frontNode->right);
                }
                
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* root= new TreeNode(stoi(str));

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int size=q.size();
            TreeNode* frontNode=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                frontNode->left=NULL;
            }
            else{
                TreeNode* leftNode=new TreeNode(stoi(str));
                frontNode->left=leftNode;
                q.push(frontNode->left);
            }

            getline(s,str,',');
            if(str=="#"){
                frontNode->right=NULL;
            }
            else{
                TreeNode* rightNode=new TreeNode(stoi(str));
                frontNode->right=rightNode;
                q.push(frontNode->right);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
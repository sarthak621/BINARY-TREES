/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    
    stack<pair<TreeNode*,int>>st;

    vector<int>pre,inOrder,post;
    vector<vector<int>>result;

    st.push({root,1});

    if(root==NULL) return result;

    while(!st.empty()){
        TreeNode* top_el=st.top().first;
        int state=st.top().second;
        st.pop();

        //num is 1
        // so its the case of preOrder
        if(state==1){
            pre.push_back(top_el->data);
            st.push({top_el,2});
            

            if(top_el->left!=NULL){
                st.push({top_el->left,1});
            }
        }

        //num is 2
        // so its the case of inOrder
        if(state==2){
            inOrder.push_back(top_el->data);
            
            st.push({top_el,3});
            

            if(top_el->right!=NULL){
                st.push({top_el->right,1});
            }
        }

        //num=3 postOrder case
        if(state==3){
            
            post.push_back(top_el->data);
        }



    }
    result.push_back(inOrder);
    result.push_back(pre);
    result.push_back(post);

    return result;
}

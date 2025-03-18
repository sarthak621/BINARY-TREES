//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    unordered_map<Node*,Node*>parent;
    
    void inOrder(Node* root){
        if(root==NULL) return;
        
        if(root->left){
            parent[root->left]=root;
        }
        inOrder(root->left);
        
        if(root->right){
            parent[root->right]=root;
        }
        inOrder(root->right);
    }
    
    void levelOrderTraversal(Node* root,int &ans){
        queue<Node*>q;
        q.push(root);
        unordered_set<int>isVisited;
        isVisited.insert(root->data);
        
        while(!q.empty()){
            int size=q.size();
            bool burned=false;
            
            while(size--){
                Node* frontNode=q.front();
                q.pop();
                
                if(frontNode->left && !isVisited.count(frontNode->left->data)){
                    q.push(frontNode->left);
                    isVisited.insert(frontNode->left->data);
                    burned=true;
                }
                
                if(frontNode->right && !isVisited.count(frontNode->right->data)){
                    q.push(frontNode->right);
                    isVisited.insert(frontNode->right->data);
                    burned=true;
                }
                
                if(parent.count(frontNode) && !isVisited.count(parent[frontNode]->data)){
                    q.push(parent[frontNode]);
                    isVisited.insert(parent[frontNode]->data);
                    burned=true;
                }
                
            }
            if(burned==true) ans++;
            
        }
        
    }
    
    Node* findTarget(Node* root, int target) {
    // Base case: if root is null or we found the target node, return root
    if (root == nullptr || root->data == target) {
        return root;
    }

    // Search in the left subtree
    Node* leftSearch = findTarget(root->left, target);
    if (leftSearch != nullptr) {
        return leftSearch; // If found in the left subtree, return it
    }

    // Search in the right subtree (simplified)
    Node* rightSearch = findTarget(root->right, target);
    return rightSearch; // Return whatever is found in the right subtree
}

    
    int minTime(Node* root, int target) {
        // code here
        int ans=0;
        inOrder(root);
        
        Node* targetNode= findTarget(root,target);
        if(!targetNode) return 0;
        
        levelOrderTraversal(targetNode,ans);
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
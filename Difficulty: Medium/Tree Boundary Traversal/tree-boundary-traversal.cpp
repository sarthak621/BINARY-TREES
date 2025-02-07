//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void addLeftBoundary(Node *root,vector<int>&res){
        Node* curr=root->left;
        
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            
            if(curr->left!=NULL) curr=curr->left;
            else if(curr->right!=NULL) curr=curr->right;
            
            else break;
        }
    }
    
    void addRightBoundary(Node *root,vector<int>&res){
        Node* curr=root->right;
        vector<int>temp;
        
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            
            if(curr->right) curr=curr->right;
            else if(curr->left) curr=curr->left;
            
            else break;
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    
    void addLeaves(Node *root,vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        
            if(root->left) addLeaves(root->left,res);
            if(root->right) addLeaves(root->right,res);
        
    }
    
    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL) return true;
        else return false;
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        
        return res;
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
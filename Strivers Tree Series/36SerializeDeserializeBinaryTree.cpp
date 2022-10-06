// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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
        if(!root)
            return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(!cur)
                s.append("#,");
            else
                s.append(to_string(cur->val)+',');
            if(cur)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                node->left=NULL;
            else
            {
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#")
                node->right=NULL;
            else
            {
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> ans;
        if(!root)
            return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* cur=q.front();
            q.pop();
            if(!cur)
                ans.push_back(0);
            else
                ans.push_back(cur->data);
            if(cur)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &a)
    {
       //Your code here
       if(a.size()==0) return NULL;
       Node* root=new Node(a[0]);
       queue<Node*> q;
       q.push(root);
       int i=1;
       while(!q.empty())
       {
           Node* node=q.front();
           q.pop();
           if(a[i]==0)
           {
               node->left=NULL;
               i++;
           }
           else
           {
               node->left=new Node(a[i++]);
               q.push(node->left);
           }
           if(a[i]==0)
           {
               node->right=NULL;
               i++;
           }
           else
           {
               node->right=new Node(a[i++]);
               q.push(node->right);
           }
       }
       return root;
    }

};

//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    _deleteTree(node->left);  
    _deleteTree(node->right);  
  
    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;  
    delete node;  
}  
  
/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        
        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        cout << "\n";

    }


    return 0;
}
// } Driver Code Ends
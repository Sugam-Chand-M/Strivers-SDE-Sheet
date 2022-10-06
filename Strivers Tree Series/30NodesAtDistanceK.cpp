// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parentTrack,TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(roo t);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left)
            {
                parentTrack[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right)
            {
                parentTrack[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentTrack;
        markParents(root,parentTrack,target);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int curLevel=0;
        while(!q.empty())
        {
            int size=q.size();
            if(curLevel++==k)
                break;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left and !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right and !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parentTrack[cur] and !vis[parentTrack[cur]])
                {
                    q.push(parentTrack[cur]);
                    vis[parentTrack[cur]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    void markParents(Node* root,unordered_map<Node*,Node*>& parentTrack,Node* target)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* cur=q.front();
            q.pop();
            if(cur->left)
            {
                parentTrack[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right)
            {
                parentTrack[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
    Node* tar(Node* root,int target){
       queue<Node*> q;
       q.push(root);
       Node* ans;
       while(!q.empty()){
           Node* node=q.front();
           q.pop();
           if(node->data==target) {
               ans=node;
               break;
           }
           if(node->left){
               q.push(node->left);
           }
           if(node->right){
               q.push(node->right);
           }
       }
       return ans;
   }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*,Node*> parentTrack;
        Node* t=tar(root,target);
        markParents(root,parentTrack,t);
        unordered_map<Node*,bool> vis;
        queue<Node*> q;
        q.push(t);
        vis[t]=true;
        int curLevel=0;
        while(!q.empty())
        {
            int size=q.size();
            if(curLevel++==k)
                break;
            for(int i=0;i<size;i++)
            {
                Node* cur=q.front();
                q.pop();
                if(cur->left and !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right and !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parentTrack[cur] and !vis[parentTrack[cur]])
                {
                    q.push(parentTrack[cur]);
                    vis[parentTrack[cur]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            Node* cur=q.front();
            q.pop();
            ans.push_back(cur->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
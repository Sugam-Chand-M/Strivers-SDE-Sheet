// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* build(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,map<int,int>& mp)
    {
        if(ps>pe or is>ie)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=mp[postorder[pe]];
        int numsLeft=inRoot-is;
        root->left=build(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,mp);
        root->right=build(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};

// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* build(int in[],int is,int ie,int post[],int ps,int pe,map<int,int>& mp)
{
    if(ps>pe or is>ie)
        return NULL;
    Node* root=new Node(post[pe]);
    int inRoot=mp[post[pe]];
    int numsLeft=inRoot-is;
    root->left=build(in,is,inRoot-1,post,ps,ps+numsLeft-1,mp);
    root->right=build(in,inRoot+1,ie,post,ps+numsLeft,pe-1,mp);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    if(n==0)
        return NULL;
    map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[in[i]]=i;
    return build(in,0,n-1,post,0,n-1,mp);
}

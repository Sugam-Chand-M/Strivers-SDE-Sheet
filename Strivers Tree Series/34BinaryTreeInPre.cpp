// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>& mp)
    {
        if(preStart>preEnd or inStart>inEnd)
            return 0;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mp[root->val];
        int numsLeft=inRoot-inStart;
        root->left=build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);
        root->right=build(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};



// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* partition(int in[],int pre[],int n,int instart, int inend, int &pIdx,unordered_map<int,int>&mp){
        if(pIdx==n)  return NULL;
        if(instart>inend)   return NULL;
        int val=pre[pIdx];
        pIdx++;
        Node* newNode=new Node(val);
        newNode->left=partition(in,pre,n,instart,mp[val]-1,pIdx,mp);
        newNode->right=partition(in,pre,n,mp[val]+1,inend,pIdx,mp);
        return newNode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        int pIdx=0;
        return partition(in,pre,n,0,n-1,pIdx,mp);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
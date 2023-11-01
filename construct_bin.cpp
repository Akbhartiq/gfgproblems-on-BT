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
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        Node *root=(Node*)malloc(sizeof(Node));
        root=build(in,pre,0,n-1,0,n-1);
        return root;
        
        
    }
    Node *build(int in[], int pre[], int i, int j, int a, int b)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = pre[a];
    int ind;
    for (int k = i; k <= j; k++)
    {
        if (pre[a] == in[k])

        {
            ind = k;
            break;
        }
    }
    if (i <= ind - 1)
        root->left = build(in, pre, i, ind - 1, a + 1, a + ind - i);
    if (ind + 1 <= j)
        root->right = build(in, pre, ind + 1, j, a + ind - i + 1, j + a - i);
    return root;
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

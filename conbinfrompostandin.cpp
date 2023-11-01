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
Node *build(int in[],int post[],int i,int j,int a,int b);
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    Node*root=(Node*)malloc(sizeof(Node));
    root=build(in,post,0,n-1,0,n-1);
    return root;
    
}
Node *build(int in[],int post[],int i,int j,int a,int b)
{
    Node*root=(Node*)malloc(sizeof(Node));
    root->data=post[b];
    int key=post[b];
    int ind;
    for(int k=i;k<=j;k++)
    {
        if(key==in[k])
        {
            ind=k;
            break;
        }
    }
    if(i<=ind-1)
    root->left=build(in,post,i,ind-1,a,a+ind-1-i);
    if(ind+1<=j)
    root->right=build(in,post,ind+1,j,a+ind-i,b-1);
    return root;
}

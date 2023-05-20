/*Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
value found in the tree, iv. Change a tree so that the roles of the left and right pointers are
swapped at every node, v. Search a value*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int data)
{
    node *newNode = new node;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

int findLongestPath(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = findLongestPath(root->left);
    int right = findLongestPath(root->right);

    return max(left, right) + 1;
}

void findmin(node* root){
    node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    cout<<"The minimum value is "<<temp->data<<endl;
}

node* swapLRpointer(node *root)
{
    node *temp;
	if(root==NULL)
		return NULL;
	else
	   {
		temp=root->left;
		root->left=swapLRpointer(root->right);
		root->right=swapLRpointer(temp);
		return root;
	   }
    
}

bool searchValue(node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == val)
    {
        return 1;
    }
    else if (val < root->data)
    {
        searchValue(root->left, val);
    }
    else if (val > root->data)
    {
        searchValue(root->right, val);
    }
    return false;
}

void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    node *root = NULL; // Empty BST

    // Insert values into the BST
    int values[] = {5, 3, 2, 4, 7, 8};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++)
    {
        root = insert(root, values[i]);
    }

    cout<<"Inorder traversal --> ";
    preorderTraversal(root);

    cout<<endl;
    findmin(root);

    cout<<"The longest path in the has "<<findLongestPath(root)<<" nodes"<<endl;

    cout<<"Searching for 10 in BST(1 if present, else 0) : "<<searchValue(root, 10)<<endl;
    
    swapLRpointer(root);
    cout<<"Swapping L&R Pointers :"<<endl;
    preorderTraversal(root);
    
    
    
    return 0;


}

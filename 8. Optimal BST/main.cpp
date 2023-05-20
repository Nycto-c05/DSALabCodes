#include <bits/stdc++.h>
using namespace std;

struct obst
{
    int key;
    double prob;
};

struct node
{
    obst data;
    node *left;
    node *right;
};

node *createNode(obst data)
{
    node *newNode = new node;

    newNode->data.key = data.key;
    newNode->data.prob = data.prob;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insert(node *root, obst data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data.key < root->data.key)
    {
        root->left = insert(root->left, data);
    }
    else if (data.key > root->data.key)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool compare(const obst &a, const obst &b)
{
    return a.prob > b.prob;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data.key << "        " << root->data.prob << endl;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    // sequence of key and its probability
    vector<obst> seq = {{2, 0.1}, {5, 0.8}, {6, 0.2}, {7, 1}, {10, 0.7}, {11, 0.3}};
    sort(seq.begin(), seq.end(), compare);

    node *root = NULL;

    for (auto i : seq)
    {
        root = insert(root, i);
    }

    cout << "PreOrder Traversal of Optimal BST:- " << endl
         << "Key      Probability" << endl;

    preorder(root);

    return 0;
}

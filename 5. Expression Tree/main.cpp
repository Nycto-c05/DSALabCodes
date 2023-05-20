#include <iostream>
#include <stack>
using namespace std;

class TreeNode
{
public:
    char val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char c)
    {
        val = c;
        left = NULL;
        right = NULL;
    }
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

TreeNode *exprTree(string prefix)
{
    stack<TreeNode *> st;

    // traversing from L-->R
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isOperator(c))
        {
            TreeNode *left = st.top();
            st.pop();
            TreeNode *right = st.top();
            st.pop();

            TreeNode *node = new TreeNode(c);

            node->left = left;
            node->right = right;

            st.push(node);
        }
        else
        {
            TreeNode *node = new TreeNode(c);
            st.push(node);
        }
    }
    return st.top();
}

string postOrder(TreeNode *root)
{
    string postOrder;
    stack<TreeNode *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left)
        {
            s1.push(root->left);
        }
        if (root->right)
        {
            s1.push(root->right);
        }
    }

    while (!s2.empty())
    {
        postOrder+=(s2.top())->val;
        s2.pop();
    }
    return postOrder;
}

void Inorder(TreeNode* root){
    if (root)
    {
        Inorder(root->left);
        cout<<root->val;
        Inorder(root->right);
    }
    
    
}

int main()
{

    string prefix = "+--a*bc/def";
    TreeNode *exprTreeRoot = exprTree(prefix);

    cout<<"Inorder Traversal : ";
    Inorder(exprTreeRoot);
    cout<<endl;

    cout << "PostOrder Traversal is : " << postOrder(exprTreeRoot)<<endl;
    
    return 0;
}

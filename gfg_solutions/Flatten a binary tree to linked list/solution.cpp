#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node *left, *right;
};


pair <Node*,Node*> helper(Node* root)
{
    pair <Node*,Node*> result;
    if( (root->left == NULL) and (root->right == NULL) )
    {
        result.first = result.second = root;
        return result;
    }
    if( (root->left != NULL) and (root->right == NULL) )
    {
        pair <Node*,Node*> T1 =  helper(root->left);
        root->left = NULL;
        root->right = T1.first;
        result.first = root;
        result.second = T1.second;
        return result;
    }
    if( (root->left == NULL) and (root->right != NULL) )
    {
        pair <Node*,Node*> T2 =  helper(root->right);
        root->left = NULL;
        root->right = T2.first;
        result.first = root;
        result.second = T2.second;
        return result;
    }
    pair < Node*,Node*> T1,T2;
    T1 = helper(root->left);
    T2 = helper(root->right);
    root->left = NULL;
    root->right = T1.first;
    T1.second->right = T2.first;
    result.first = root;
    result.second = T2.second;
    return result;
}

void flatten(Node *root)
{
    //code here
    if(root == NULL)
        return ;
    pair<Node*,Node*> result = helper(root);
}

int main()
{
    cout << "hello world" << endl;
    return 0;
}
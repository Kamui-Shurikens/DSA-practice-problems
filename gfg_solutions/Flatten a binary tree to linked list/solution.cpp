#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node *left, *right;
};

void flatten(Node *root)
{
    //code here
    Node * current = root;

    while(current != NULL)
    {
        if(current->left != NULL)
        {
            Node* rightmost = current->left;
            while(rightmost->right != NULL)
            {
                rightmost = rightmost->right;
            }
            rightmost->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}

int main()
{
    cout << "hello world" << endl;
    return 0;
}
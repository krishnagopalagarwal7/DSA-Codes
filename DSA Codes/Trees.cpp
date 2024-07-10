#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
        ;
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}

void print_nodes_at_distance_k(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->key << " ";
    }
    else
    {
        print_nodes_at_distance_k(root->left, k - 1);
        print_nodes_at_distance_k(root->right, k - 1);
    }
}
// Print the level order traversal in one line
void level_order_traversal_1(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}
// Print the level order traversal line by line, 1st Method
void level_order_traversal_2(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    cout << endl;
}
// Print the level order traversal line by line, 2nd Method
void level_order_traversal_3(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}
// Gives the number of nodes in the binary tree
int getsize(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getsize(root->left) + getsize(root->right);
    }
}
// Gives the maximum node in the tree
int getmax(Node *root)
{
    if (root == NULL)
    {
        return -INT_MAX;
    }
    else
    {
        return max(root->key, max(getmax(root->right), getmax(root->left)));
    }
}
// Printing the left view of a tree using recursion
void helper_for_print_left_view(Node *root, int level, int &maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        cout << root->key << " ";
        maxlevel = level;
    }
    helper_for_print_left_view(root->left, level + 1, maxlevel);
    helper_for_print_left_view(root->right, level + 1, maxlevel);
}

void print_left_view_1(Node *root)
{
    int maxlevel = 0;
    helper_for_print_left_view(root, 1, maxlevel);
}
// Printing the left view of a tree using iteraion
void print_left_view_2(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout << curr->key << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

bool children_sum_property(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum=0;
    if (root->left!=NULL)
    {
        sum+=root->left->key;
    }
    if (root->right!=NULL)
    {
        sum+=root->right->key;
    }
    return (root->key==sum && children_sum_property(root->left) && children_sum_property(root->right));
}
// Check whether tree is balanced or not
int isBalanced(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int lh=isBalanced(root->left);
    if (lh==-1)
    {
        return -1;
    }
    int rh=isBalanced(root->right);
    if (rh==-1)
    {
        return -1;
    }
    if (abs(lh-rh)>1)
    {
        return -1;
    }
    else
    {
        return max(lh, rh)+1;
    }
}

int maxwidth(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int res=0;
    while(q.empty()==false)
    {
        int count=q.size();
        res=max(res, count);
        for (int i=0; i<count; i++)
        {
            Node *curr=q.front();
            q.pop();
            if (curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if (curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
    return res;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << height(root) << endl;
    print_nodes_at_distance_k(root, 2);
    cout << endl;
    print_nodes_at_distance_k(root, 1);
    cout << endl;
    level_order_traversal_1(root);
    cout << endl;
    level_order_traversal_2(root);
    level_order_traversal_3(root);
    cout << getsize(root) << endl;
    cout << getmax(root) << endl;
    print_left_view_1(root);
    cout << endl;
    print_left_view_2(root);
    cout << endl;
    if (children_sum_property(root))
    {
        cout << "This tree follows children sum property" << endl;
    }
    else
    {
        cout << "This tree doesnot follow children sum property" << endl;
    }
    if (isBalanced(root)==-1)
    {
        cout << "The tree is not Balanced" << endl;
    }
    else
    {
        cout << "The Tree is balanced and it's height is " << isBalanced(root) << endl;
    }
    cout << maxwidth(root) << endl;
}

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
// By Recursion
bool search_1(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->key == x)
    {
        return true;
    }
    else if (root->key > x)
    {
        return search_1(root->left, x);
    }
    else
    {
        return search_1(root->right, x);
    }
}
// By Iteration
bool search_2(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x)
        {
            return true;
        }
        else if (root->key > x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}
// By Recursion
Node *insert_1(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (root->key < x)
    {
        root->right = insert_1(root->right, x);
    }
    else if (root->key > x)
    {
        root->left = insert_1(root->left, x);
    }
    return root;
}
// By Iteration
Node *insert_2(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
        {
            curr = curr->left;
        }
        else if (curr->key < x)
        {
            curr = curr->right;
        }
        else
        {
            return root;
        }
    }
    if (parent == NULL)
    {
        return temp;
    }
    if (parent->key > x)
    {
        parent->left = temp;
    }
    else
    {
        parent->right = temp;
    }
    return root;
}

Node *get_successor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *delNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->key > x)
    {
        root->left = delNode(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = delNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = get_successor(root);
            root->key = succ->key;
            root->right = delNode(root->right, succ->key);
        }
        return root;
    }
}

Node *floor(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }
        else if (root->key > x)
        {
            root = root->left;
        }
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}

Node *ceil(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }
        else if (root->key < x)
        {
            root = root->right;
        }
        else
        {
            res = root;
            root = root->left;
        }
    }
    return res;
}

int main()
{
    Node *root = new Node(10);
    return 0;
}

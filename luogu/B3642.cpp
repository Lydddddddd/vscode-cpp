#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node();
    node(int Data,struct node *Left=NULL,struct node *Right=NULL);
};

struct tree
{
    node *root;
    
};

node::node()
{
    left=right=NULL;
}

node::node(int Data,struct node *Left,struct node *Right)
{
    data=Data;
    left=Left;
    right=Right;
}

int main()
{

    return 0;
}
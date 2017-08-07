#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int mark;
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode,*Tree;

Tree createTree();
Tree input(Tree tree);
void printTree(Tree tree);
Tree addNode(int value,char *cur,Tree tree);

Tree createTree()
{
    Tree tree;
    tree=(Tree)malloc(sizeof(TreeNode));
    tree->mark=0;
    tree->data=-1;
    tree->left=NULL;
    tree->right=NULL;
    return tree;
}

Tree input(Tree tree)
{
    char a[200];
    int value;
    while(~scanf("%s",a) && strcmp(a,"()"))
    {
        sscanf(&a[1],"%d",&value);
        tree=addNode(value,strchr(a,',')+1,tree);
    }
    return tree;
}

void printTree(Tree tree)
{
    if(tree==NULL)
        return;
    if(tree->data==-1)
    {
        printf("%d ",tree->data);
        return;
    }
    printf("%d ",tree->data);
    printTree(tree->left);
    printTree(tree->right);
}

Tree addNode(int value,char *cur,Tree tree)
{
    if(tree==NULL)
        tree=createTree();
    if(*cur==')')
    {
        if(tree->data==-1 && !tree->mark)
            tree->data=value;
        else if(tree->data!=-1)
        {
            tree->data=-1;
            tree->mark=1;
        }
    }
    else if(*cur=='L')
        tree->left=addNode(value,cur+1,tree->left);
    else if(*cur=='R')
        tree->right=addNode(value,cur+1,tree->right);
    return tree;
}

int main()
{
    Tree tree;
    tree=createTree();
    tree=input(tree);
    printTree(tree);
    return 0;
}

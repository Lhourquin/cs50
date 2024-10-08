//implements a list of numbers as a binary search tree 
#include <stdio.h>
#include <stdlib.h>

//represents a node
typedef struct node 
{
    int number;//1
    struct node *left;//2
    struct node *right;//3
}
node;

void free_tree(node *root);
void print_tree(node *root);

int main(void)
{
    //tree of size 0
    node *tree = NULL;


    //Add number to list 
    node *n = malloc(sizeof(node));
    if (n ==NULL) {
        return 1;
    }

    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free_tree(tree);
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    //Add number to list 
    n = malloc(sizeof(node));
    if(n == NULL){
        free_tree(tree);
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    //print tree
    print_tree(tree);
    return 0;
}

void free_tree(node *root)
{
    if(root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node *root)
{
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

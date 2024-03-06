#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
} node_t;


struct node *newNode(int val){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void insertNode(node_t *root, node_t *node){
    if (NULL == root || NULL == node) return;

    node_t *current_node = root;

    while (true){
        if (node->val < current_node->val){
            if (NULL == current_node->left){
                current_node->left = node;
                break;
            }else current_node = current_node->left;
        }else{
            if (NULL == current_node->right){
                current_node->right = node;
                break;
            }else current_node = current_node->right;
        }
    }
}

struct node *search(struct node *root, int val) {
    if (!root) return false;

    if (root->val == val) return true;

    if (root->val < val) return search(root->right, val);

    if (root->val > val) return search(root->left, val);
}

//Fall 1 Element existiert nicht
//Fall 2 Element existiert und hat keine Kinder
//Fall 3 Element existiert und hat ein Kinder
//Fall 4 Element existiert und hat zwei Kinder

int main(){
    node_t *root = newNode(9);

    node_t *newval0 = newNode(0);
    insertNode(root, newval0);

    node_t *newval1 = newNode(5);
    insertNode(root, newval1);

    node_t *newval2 = newNode(7);
    insertNode(root, newval2);

    node_t *newval3 = newNode(12);
    insertNode(root, newval3);

    node_t *newval4 = newNode(2);
    insertNode(root, newval4);

    printf("%d",root->right->val);
    printf("\n%s", search(root, 2) ? "true" : "false");
}
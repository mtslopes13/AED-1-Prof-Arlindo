#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_node(Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void pre_order(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(Node* root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->value);
        in_order(root->right);
    }
}

void post_order(Node* root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->value);
    }
}

void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int i = 0; i < num_cases; i++) {
        int num_elements;
        scanf("%d", &num_elements);
        Node* root = NULL;
        for (int j = 0; j < num_elements; j++) {
            int value;
            scanf("%d", &value);
            root = insert_node(root, value);
        }
        printf("Case %d:\n", i + 1);
        printf("Pre.: ");
        pre_order(root);
        printf("\nIn..: ");
        in_order(root);
        printf("\nPost: ");
        post_order(root);
        printf("\n\n");
        free_tree(root);
    }
    return 0;
}

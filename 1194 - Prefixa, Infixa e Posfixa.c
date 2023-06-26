#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de uma estrutura de nó da árvore
typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
} Node;

// Função auxiliar para criar um novo nó
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para construir a árvore recursivamente
Node* buildTree(char* prefix, char* infix, int length) {
    if (length <= 0)
        return NULL;

    // Encontra a raiz na sequência prefixa
    char rootValue = prefix[0];
    int rootIndex = 0;
    while (infix[rootIndex] != rootValue)
        rootIndex++;

    // Cria um novo nó com o valor da raiz
    Node* root = createNode(rootValue);

    // Divide a sequência infixa em sub-sequências
    char* leftInfix = malloc(rootIndex * sizeof(char));
    strncpy(leftInfix, infix, rootIndex);
    leftInfix[rootIndex] = '\0';

    char* rightInfix = malloc((length - rootIndex - 1) * sizeof(char));
    strncpy(rightInfix, infix + rootIndex + 1, length - rootIndex - 1);
    rightInfix[length - rootIndex - 1] = '\0';

    // Divide a sequência prefixa em sub-sequências
    char* leftPrefix = malloc(rootIndex * sizeof(char));
    strncpy(leftPrefix, prefix + 1, rootIndex);
    leftPrefix[rootIndex] = '\0';

    char* rightPrefix = malloc((length - rootIndex - 1) * sizeof(char));
    strncpy(rightPrefix, prefix + rootIndex + 1, length - rootIndex - 1);
    rightPrefix[length - rootIndex - 1] = '\0';

    // Chama recursivamente a função para construir as sub-árvores esquerda e direita
    root->left = buildTree(leftPrefix, leftInfix, rootIndex);
    root->right = buildTree(rightPrefix, rightInfix, length - rootIndex - 1);

    free(leftInfix);
    free(rightInfix);
    free(leftPrefix);
    free(rightPrefix);

    return root;
}

// Função para percorrer a árvore em pós-ordem (posfixo)
void postOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%c", root->value);
}

int main() {
    int numCases;
    scanf("%d", &numCases);

    while (numCases > 0) {
        int numNodes;
        char prefix[53];
        char infix[53];
        scanf("%d %s %s", &numNodes, prefix, infix);

        Node* root = buildTree(prefix, infix, numNodes);

        postOrderTraversal(root);
        printf("\n");

        free(root);

        numCases--;
    }

    return 0;
}
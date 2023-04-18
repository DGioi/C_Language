#include <stdio.h>
#include <stdlib.h>

// ð?nh ngh?a c?u trúc c?a m?t nút trong cây nh? phân t?m ki?m
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// hàm t?o m?t nút m?i v?i giá tr? key ðý?c ch? ð?nh
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// hàm thêm m?t nút m?i vào cây nh? phân t?m ki?m
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

// hàm t?m ki?m m?t giá tr? trong cây nh? phân t?m ki?m
struct Node* search(struct Node* node, int key) {
    if (node == NULL || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return search(node->left, key);
    }

    return search(node->right, key);
}

// hàm in ra t?t c? các giá tr? trong cây nh? phân t?m ki?m
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->key);
        inorderTraversal(node->right);
    }
}

// hàm xóa m?t nút kh?i cây nh? phân t?m ki?m
struct Node* deleteNode(struct Node* node, int key) {
    if (node == NULL) {
        return node;
    }

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }

        struct Node* temp = node->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }

    return node;
}

// hàm chính
int main() {
    struct Node* root = NULL;

    // thêm các giá tr? vào cây nh? phân t?m ki?m
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

// in ra t?t c? các giá tr? trong cây nh? phân t?m ki?m
printf("Inorder traversal: ");
inorderTraversal(root);
printf("\n");

// t?m ki?m các giá tr? trong cây nh? phân t?m ki?m
struct Node* result = search(root, 60);
if (result != NULL) {
    printf("Found %d\n", result->key);
} else {
    printf("Not found\n");
}

result = search(root, 90);
if (result != NULL) {
    printf("Found %d\n", result->key);
} else {
    printf("Not found\n");
}

// xóa các giá tr? kh?i cây nh? phân t?m ki?m
root = deleteNode(root, 20);
root = deleteNode(root, 30);
root = deleteNode(root, 50);

// in ra t?t c? các giá tr? c?n l?i trong cây nh? phân t?m ki?m
printf("Inorder traversal after deletion: ");
inorderTraversal(root);
printf("\n");

return 0;
 
   


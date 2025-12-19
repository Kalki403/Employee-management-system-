#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Module 2: Singly Linked List (Employee)
typedef struct Employee {
    int id;
    char name[50];
    struct Employee* next;
} Employee;

// Module 4: Binary Search Tree (Search Index)
typedef struct BSTNode {
    int id;
    struct BSTNode *left, *right;
} BSTNode;

// Module 3: Doubly Linked List (Projects)
typedef struct Project {
    char p_name[30];
    struct Project *next, *prev;
} Project;

// Module 1: Stack (Recent Actions)
char stack[5][50];
int top = -1;

void push(char* msg) {
    if (top < 4) strcpy(stack[++top], msg);
}

// Logic to export BST in Pre-order for visualization
void printBST(BSTNode* root) {
    if (root == NULL) return;
    printf("{\"id\": %d},", root->id);
    printBST(root->left);
    printBST(root->right);
}

int main(int argc, char* argv[]) {
    // 1. Synthetic Data Setup
    Employee* head = (Employee*)malloc(sizeof(Employee));
    head->id = 101; strcpy(head->name, "Alice");
    head->next = (Employee*)malloc(sizeof(Employee));
    head->next->id = 102; strcpy(head->next->name, "Bob");
    head->next->next = NULL;

    push("Added Alice");
    push("Added Bob");

    // 2. Output handling for Flask
    if (argc > 1 && strcmp(argv[1], "get_all") == 0) {
        printf("{\"employees\": [");
        Employee* temp = head;
        while(temp) {
            printf("{\"id\": %d, \"name\": \"%s\"}%s", temp->id, temp->name, temp->next?",":"");
            temp = temp->next;
        }
        printf("], \"stack\": [");
        for(int i=top; i>=0; i--) {
            printf("\"%s\"%s", stack[i], i==0?"":",");
        }
        printf("]}");
    }
    return 0;
}

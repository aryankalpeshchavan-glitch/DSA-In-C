#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_CHILDREN 10

// Structure for a family member
struct Node {
    char name[MAX_NAME];
    struct Node *parent;
    struct Node *children[MAX_CHILDREN];
    int childCount;
};

struct Node *root = NULL;

// Create a new node
struct Node* createNode(char name[]) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->parent = NULL;
    newNode->childCount = 0;

    for (int i = 0; i < MAX_CHILDREN; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Find a member in the tree
struct Node* findMember(struct Node *current, char name[]) {
    if (current == NULL)
        return NULL;

    if (strcmp(current->name, name) == 0)
        return current;

    for (int i = 0; i < current->childCount; i++) {
        struct Node *result =
            findMember(current->children[i], name);

        if (result != NULL)
            return result;
    }

    return NULL;
}

// Create root member
void createRoot() {
    char name[MAX_NAME];

    if (root != NULL) {
        printf("Root already exists!\n");
        return;
    }

    printf("Enter root member name: ");
    scanf("%s", name);

    root = createNode(name);

    printf("Root member added successfully.\n");
}

// Add a family member
void addMember() {
    char parentName[MAX_NAME];
    char childName[MAX_NAME];

    printf("Enter parent name: ");
    scanf("%s", parentName);

    struct Node *parent = findMember(root, parentName);

    if (parent == NULL) {
        printf("Parent not found!\n");
        return;
    }

    if (parent->childCount == MAX_CHILDREN) {
        printf("Maximum number of children reached!\n");
        return;
    }

    printf("Enter child name: ");
    scanf("%s", childName);

    if (findMember(root, childName) != NULL) {
        printf("Member already exists!\n");
        return;
    }

    struct Node *child = createNode(childName);

    child->parent = parent;
    parent->children[parent->childCount] = child;
    parent->childCount++;

    printf("%s added under %s.\n", childName, parentName);
}

// Display family hierarchy
void displayHierarchy(struct Node *current, int level) {
    if (current == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("    ");

    printf("|-- %s\n", current->name);

    for (int i = 0; i < current->childCount; i++) {
        displayHierarchy(current->children[i], level + 1);
    }
}

void displayFamily() {
    if (root == NULL) {
        printf("Family tree is empty!\n");
        return;
    }

    printf("\nFamily Hierarchy:\n");
    displayHierarchy(root, 0);
}

// Find ancestors
void findAncestors() {
    char name[MAX_NAME];

    printf("Enter member name: ");
    scanf("%s", name);

    struct Node *member = findMember(root, name);

    if (member == NULL) {
        printf("Member not found!\n");
        return;
    }

    struct Node *current = member->parent;

    printf("Ancestors of %s: ", name);

    if (current == NULL) {
        printf("None");
    } else {
        while (current != NULL) {
            printf("%s", current->name);

            current = current->parent;

            if (current != NULL)
                printf(" -> ");
        }
    }

    printf("\n");
}

// Determine generation level
void generationLevel() {
    char name[MAX_NAME];

    printf("Enter member name: ");
    scanf("%s", name);

    struct Node *member = findMember(root, name);

    if (member == NULL) {
        printf("Member not found!\n");
        return;
    }

    int level = 0;
    struct Node *current = member;

    while (current->parent != NULL) {
        level++;
        current = current->parent;
    }

    printf("%s is at generation level %d.\n", name, level);
}

// Count descendants recursively
int countDescendants(struct Node *current) {
    if (current == NULL)
        return 0;

    int count = 0;

    for (int i = 0; i < current->childCount; i++) {
        count++;

        count += countDescendants(current->children[i]);
    }

    return count;
}

// Count descendants
void displayDescendantsCount() {
    char name[MAX_NAME];

    printf("Enter member name: ");
    scanf("%s", name);

    struct Node *member = findMember(root, name);

    if (member == NULL) {
        printf("Member not found!\n");
        return;
    }

    int count = countDescendants(member);

    printf("%s has %d descendant(s).\n", name, count);
}

int main() {
    int choice;

    do {
        printf("\n===== FAMILY TREE MANAGEMENT =====\n");
        printf("1. Add Root Member\n");
        printf("2. Add Family Member\n");
        printf("3. Display Family Hierarchy\n");
        printf("4. Find Ancestors\n");
        printf("5. Determine Generation Level\n");
        printf("6. Count Descendants\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createRoot();
                break;

            case 2:
                if (root == NULL)
                    printf("Create root member first!\n");
                else
                    addMember();
                break;

            case 3:
                displayFamily();
                break;

            case 4:
                if (root == NULL)
                    printf("Family tree is empty!\n");
                else
                    findAncestors();
                break;

            case 5:
                if (root == NULL)
                    printf("Family tree is empty!\n");
                else
                    generationLevel();
                break;

            case 6:
                if (root == NULL)
                    printf("Family tree is empty!\n");
                else
                    displayDescendantsCount();
                break;

            case 7:
                printf("Exiting...\n");
                break;  

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
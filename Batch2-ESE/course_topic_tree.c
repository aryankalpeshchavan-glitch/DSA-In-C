#include <stdio.h>
#include <string.h>

#define MAX 200
#define SIZE 60

struct Item {
    char name[SIZE];
    char type;
    int parent;
};

struct Item items[MAX];
int count = 0;

int findItem(char name[]) {
    int i;
    for (i = 0; i < count; i++)
        if (strcmp(items[i].name, name) == 0)
            return i;
    return -1;
}

void addItem(char type) {
    char name[SIZE], parentName[SIZE];
    int parent = -1;

    if (count == MAX) {
        printf("Course tree is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %59[^\n]", name);

    if (findItem(name) != -1) {
        printf("Name already exists.\n");
        return;
    }

    if (type == 'C' || type == 'T') {
        printf("Enter parent %s name: ", type == 'C' ? "unit" : "chapter");
        scanf(" %59[^\n]", parentName);
        parent = findItem(parentName);

        if (parent == -1 || (type == 'C' && items[parent].type != 'U') ||
            (type == 'T' && items[parent].type != 'C')) {
            printf("Parent not found or has the wrong type.\n");
            return;
        }
    }

    strcpy(items[count].name, name);
    items[count].type = type;
    items[count].parent = parent;
    count++;
    printf("Added successfully.\n");
}

void displayTree(int parent, int level) {
    int i, j;
    for (i = 0; i < count; i++) {
        if (items[i].parent == parent) {
            for (j = 0; j < level; j++)
                printf("  ");
            printf("%s\n", items[i].name);
            displayTree(i, level + 1);
        }
    }
}

void searchTopic() {
    char name[SIZE];
    int index;

    printf("Enter topic name: ");
    scanf(" %59[^\n]", name);
    index = findItem(name);

    if (index != -1 && items[index].type == 'T')
        printf("Topic found: %s\n", items[index].name);
    else
        printf("Topic not found.\n");
}

void courseDepth() {
    int i, depth = 0;

    for (i = 0; i < count; i++)
        if (items[i].type == 'T' && depth < 3)
            depth = 3;
        else if (items[i].type == 'C' && depth < 2)
            depth = 2;
        else if (items[i].type == 'U' && depth < 1)
            depth = 1;

    printf("Course depth: %d\n", depth);
}

int main() {
    int choice, i, topics = 0;

    while (1) {
        printf("\n1. Add unit\n2. Add chapter\n3. Add topic\n4. Display course hierarchy\n5. Search topic\n6. Calculate course depth\n7. Count topics\n8. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addItem('U');
        else if (choice == 2)
            addItem('C');
        else if (choice == 3)
            addItem('T');
        else if (choice == 4) {
            if (count == 0)
                printf("Course is empty.\n");
            else
                displayTree(-1, 0);
        } else if (choice == 5)
            searchTopic();
        else if (choice == 6)
            courseDepth();
        else if (choice == 7) {
            for (i = 0; i < count; i++)
                if (items[i].type == 'T')
                    topics++;
            printf("Total topics: %d\n", topics);
            topics = 0;
        } else if (choice == 8)
            break;
        else
            printf("Invalid choice.\n");
    }

    return 0;
}
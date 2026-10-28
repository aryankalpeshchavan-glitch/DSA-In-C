#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 50

struct Course {
    char name[SIZE];
    int parent;
};

struct Course courses[MAX];
int count = 0;

int findCourse(char name[]) {
    int i;
    for (i = 0; i < count; i++)
        if (strcmp(courses[i].name, name) == 0)
            return i;
    return -1;
}

void addCourse() {
    char name[SIZE], prerequisite[SIZE];
    int parent;

    if (count == MAX) {
        printf("Course list is full.\n");
        return;
    }

    printf("Enter course name: ");
    scanf(" %49[^\n]", name);

    if (findCourse(name) != -1) {
        printf("Course already exists.\n");
        return;
    }

    printf("Enter prerequisite course (or NONE): ");
    scanf(" %49[^\n]", prerequisite);

    if (strcmp(prerequisite, "NONE") == 0)
        parent = -1;
    else {
        parent = findCourse(prerequisite);
        if (parent == -1) {
            printf("Prerequisite not found. Add it first.\n");
            return;
        }
    }

    strcpy(courses[count].name, name);
    courses[count].parent = parent;
    count++;
    printf("Course added.\n");
}

void displayHierarchy(int parent, int level) {
    int i, j;
    for (i = 0; i < count; i++) {
        if (courses[i].parent == parent) {
            for (j = 0; j < level; j++)
                printf("  ");
            printf("%s\n", courses[i].name);
            displayHierarchy(i, level + 1);
        }
    }
}

void showPrerequisites() {
    char name[SIZE];
    int index, parent;

    printf("Enter course name: ");
    scanf(" %49[^\n]", name);
    index = findCourse(name);

    if (index == -1) {
        printf("Course not found.\n");
        return;
    }

    parent = courses[index].parent;
    if (parent == -1) {
        printf("No prerequisites.\n");
        return;
    }

    printf("Prerequisites: ");
    while (parent != -1) {
        printf("%s", courses[parent].name);
        parent = courses[parent].parent;
        if (parent != -1)
            printf(" -> ");
    }
    printf("\n");
}

void showDepth() {
    char name[SIZE];
    int index, depth = 0;

    printf("Enter course name: ");
    scanf(" %49[^\n]", name);
    index = findCourse(name);

    if (index == -1) {
        printf("Course not found.\n");
        return;
    }

    while (courses[index].parent != -1) {
        depth++;
        index = courses[index].parent;
    }
    printf("Course depth: %d\n", depth);
}

void showPaths(int index, char path[][SIZE], int level) {
    int i, children = 0;
    strcpy(path[level], courses[index].name);

    for (i = 0; i < count; i++)
        if (courses[i].parent == index) {
            children++;
            showPaths(i, path, level + 1);
        }

    if (children == 0) {
        for (i = 0; i <= level; i++) {
            if (i > 0)
                printf(" -> ");
            printf("%s", path[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, i;
    char path[MAX][SIZE];

    while (1) {
        printf("\n1. Add course\n2. Display prerequisite hierarchy\n3. Find prerequisites\n4. Find course depth\n5. Display learning paths\n6. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addCourse();
        else if (choice == 2) {
            if (count == 0)
                printf("No courses available.\n");
            else
                displayHierarchy(-1, 0);
        } else if (choice == 3)
            showPrerequisites();
        else if (choice == 4)
            showDepth();
        else if (choice == 5) {
            if (count == 0)
                printf("No courses available.\n");
            else
                for (i = 0; i < count; i++)
                    if (courses[i].parent == -1)
                        showPaths(i, path, 0);
        } else if (choice == 6)
            break;
        else
            printf("Invalid choice.\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

void create() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter Roll No: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);
    newNode->next = head;
    head = newNode;
    printf("Student added successfully!\n");
}

void display() {
    if (head == NULL) {
        printf("No records found!\n");
        return;
    }
    struct Student* temp = head;
    printf("\nRoll\tName\t\tMarks\n");
    printf("----------------------------\n");
    while (temp != NULL) {
        printf("%d\t%-15s\t%.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

void search() {
    int roll;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Found: Roll=%d, Name=%s, Marks=%.2f\n", temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);
    struct Student *temp = head, *prev = NULL;
    if (temp != NULL && temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("Deleted successfully!\n");
        return;
    }
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Create  2.Display  3.Search  4.Delete  5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
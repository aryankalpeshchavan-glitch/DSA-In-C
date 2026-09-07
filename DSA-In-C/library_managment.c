#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    struct Book* next;
};

struct Book* head = NULL;

void addBook() {
    struct Book* newNode = (struct Book*)malloc(sizeof(struct Book));
    printf("Enter Book ID: ");
    scanf("%d", &newNode->id);
    printf("Enter Title: ");
    scanf(" %[^\n]", newNode->title);
    printf("Enter Author: ");
    scanf(" %[^\n]", newNode->author);
    newNode->next = head;
    head = newNode;
    printf("Book added!\n");
}

void removeBook() {
    int id;
    printf("Enter Book ID to remove: ");
    scanf("%d", &id);
    struct Book *temp = head, *prev = NULL;
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Book removed!\n");
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Book removed!\n");
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Found: ID=%d, Title=%s, Author=%s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
}

void displayBooks() {
    if (head == NULL) {
        printf("No books available!\n");
        return;
    }
    struct Book* temp = head;
    printf("\nID\tTitle\t\tAuthor\n");
    printf("--------------------------------\n");
    while (temp != NULL) {
        printf("%d\t%-15s\t%s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Add  2.Remove  3.Search  4.Display  5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: removeBook(); break;
            case 3: searchBook(); break;
            case 4: displayBooks(); break;
            case 5: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}
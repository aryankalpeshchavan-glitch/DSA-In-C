#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    struct Product* next;
};

struct Product* head = NULL;

void addProduct() {
    struct Product* newNode = (struct Product*)malloc(sizeof(struct Product));
    printf("Enter Product ID: ");
    scanf("%d", &newNode->id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter Price: ");
    scanf("%f", &newNode->price);
    newNode->next = head;
    head = newNode;
    printf("Product added to cart!\n");
}

void removeProduct() {
    int id;
    printf("Enter Product ID to remove: ");
    scanf("%d", &id);
    struct Product *temp = head, *prev = NULL;
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Product removed!\n");
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Product not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Product removed!\n");
}

void displayCart() {
    if (head == NULL) {
        printf("Cart is empty!\n");
        return;
    }
    struct Product* temp = head;
    printf("\nID\tName\t\tPrice\n");
    printf("----------------------------\n");
    while (temp != NULL) {
        printf("%d\t%-15s\t%.2f\n", temp->id, temp->name, temp->price);
        temp = temp->next;
    }
}

void countProducts() {
    int count = 0;
    struct Product* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total products in cart: %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Add  2.Remove  3.Display  4.Count  5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: displayCart(); break;
            case 4: countProducts(); break;
            case 5: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}
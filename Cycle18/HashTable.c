#include <stdio.h>
#include <stdlib.h>

int size;

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[100];

void insert(int key) {
    int index = key % size;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) 
        hashTable[index] = newNode;
    else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    display();
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] : ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, key;
    printf("Enter size of hash table: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) 
        hashTable[i] = NULL;

    printf("1.Insert key\n2.Display\n0.Exit");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}

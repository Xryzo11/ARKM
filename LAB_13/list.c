#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    int size;
} List;

void initList(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int getListSize(List* list) {
    return list->size;
}

void addToList(List* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Nie można przydzielić pamięci\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (list->tail == NULL || list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void addToListOnIndex(List* list, int data, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Nie można przydzielić pamięci\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
        if (list->tail == NULL) {
            list->tail = newNode;
        }
        list->size++;
        return;
    }
    if (index < 0 || index >= getListSize(list)) {
        printf("Niepoprawny numer indeksu\n");
        return;
    }
    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == NULL) {
        list->tail = newNode;
    }
    list->size++;
}

void fillList(List* list, int elements) {
    for (int i = 0; i < elements; i++) {
        addToList(list, i);
    }
}

void printList(List* list) {
    Node* current = list->head;
    while (current->next != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void printIndexes(List* list) {
    int index = 0;
    Node* current = list->head;
    while (current->next != NULL) {
        printf("%i -> ", index);
        current = current->next;
        index++;
    }
    printf("%i\n", index);
}

int getFromList(List* list, int index) {
    if (index < 0 || index >= getListSize(list)) {
        printf("Niepoprawny numer indeksu\n");
        return -1;
    }
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

int removeFromList(List* list, int index) {
    if (index < 0 || index >= getListSize(list)) {
        printf("Niepoprawny numer indeksu\n");
        return -1;
    }
    Node* toDelete;
    int data;
    if (index == 0) {
        toDelete = list->head;
        data = toDelete->data;
        list->head = toDelete->next;
        if (list->head == NULL) list->tail = NULL;
        free(toDelete);
    } else {
        Node* prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        toDelete = prev->next;
        data = toDelete->data;
        prev->next = toDelete->next;
        if (prev->next == NULL) list->tail = prev;
        free(toDelete);
    }
    list->size--;
    return data;
}

void freeList(List* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void testList(List* list) {
    initList(list);
    addToList(list, 1);
    printf("Dodano element: %d\n", getFromList(list, 0));
    addToList(list, 2);
    printf("Dodano element: %d\n", getFromList(list, 1));
    addToList(list, 3);
    printf("Dodano element: %d\n", getFromList(list, 2));
    addToList(list, 4);
    printf("Dodano element: %d\n", getFromList(list, 3));
    addToList(list, 5);
    printf("Dodano element: %d\n", getFromList(list, 4));
    addToListOnIndex(list, 6, 0);
    printf("Dodano element: %d na indeksie 0\n", getFromList(list, 0));
    addToListOnIndex(list, 7, 5);
    printf("Dodano element: %d na indeksie 5\n", getFromList(list, 5));
    printf("\n");
    printIndexes(list);
    printList(list);
    printf("\n");
    printf("Usunięto element: %d z indeksu 6\n", getFromList(list, 6));
    removeFromList(list, 6);
    printf("Usunięto element: %d z indeksu 3\n", getFromList(list, 3));
    removeFromList(list, 3);
    printf("Usunięto element: %d z indeksu 0\n", getFromList(list, 0));
    removeFromList(list, 0);
    printf("\n");
    printIndexes(list);
    printList(list);
    freeList(list);
    printf("\n");
}
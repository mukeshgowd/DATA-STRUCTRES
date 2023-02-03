#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int hash(int key) {
    return key % MAX_SIZE;
}

int probe(int hashIndex, int key, int* hashTable) {
    int index = hashIndex;
    int i = 0;
    while (hashTable[index] != -1 && hashTable[index] != key) {
        index = (hashIndex + ++i) % MAX_SIZE;
    }
    return index;
}

void insert(int key, int* hashTable) {
    int hashIndex = hash(key);
    int index = probe(hashIndex, key, hashTable);
    if (hashTable[index] == -1) {
        hashTable[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
    } else {
        printf("Key %d already exists at index %d\n", key, index);
    }
}

int search(int key, int* hashTable) {
    int hashIndex = hash(key);
    int index = probe(hashIndex, key, hashTable);
    if (hashTable[index] == -1) {
        return -1;
    }
    return index;
}

int main() {
    int hashTable[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable[i] = -1;
    }

    int n;
    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int key;
        printf("Enter key %d: ", i+1);
        scanf("%d", &key);
        insert(key, hashTable);
    }

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = search(key, hashTable);
    if (index == -1) {
        printf("Key %d not found\n", key);
    } else {
        printf("Key %d found at index %d\n", key, index);
    }

    return 0;
}

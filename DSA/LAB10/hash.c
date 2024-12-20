#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // Maximum number of keys in the file
#define EMPTY -1 // Sentinel value to indicate an empty location

// Function to initialize the hash table
void initializeHashTable(int hashTable[], int m) {
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }
}

// Hash function: H(K) = K mod m
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert a key into the hash table using linear probing
void insertKey(int hashTable[], int m, int key) {
    int address = hashFunction(key, m);
    int originalAddress = address;

    // Linear probing to resolve collisions
    while (hashTable[address] != EMPTY) {
        address = (address + 1) % m;
        if (address == originalAddress) { // Table is full
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }
    hashTable[address] = key;
    printf("Key %d inserted at address %d\n", key, address);
}

// Function to search for a key in the hash table
bool searchKey(int hashTable[], int m, int key) {
    int address = hashFunction(key, m);
    int originalAddress = address;

    // Linear probing to search for the key
    while (hashTable[address] != EMPTY) {
        if (hashTable[address] == key) {
            return true;
        }
        address = (address + 1) % m;
        if (address == originalAddress) { // Table is fully traversed
            break;
        }
    }
    return false;
}

// Function to display the hash table
void displayHashTable(int hashTable[], int m) {
    printf("Hash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == EMPTY) {
            printf("Address %d: EMPTY\n", i);
        } else {
            printf("Address %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int m, n;

    printf("Enter the number of memory locations (m): ");
    scanf("%d", &m);

    int hashTable[m];
    initializeHashTable(hashTable, m);

    printf("Enter the number of employee keys (n): ");
    scanf("%d", &n);

    int keys[n];
    printf("Enter %d keys (4-digit integers):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    // Insert keys into the hash table
    for (int i = 0; i < n; i++) {
        insertKey(hashTable, m, keys[i]);
    }

    displayHashTable(hashTable, m);

    int search;
    printf("Enter a key to search: ");
    scanf("%d", &search);

    if (searchKey(hashTable, m, search)) {
        printf("Key %d found in the hash table.\n", search);
    } else {
        printf("Key %d not found in the hash table.\n", search);
    }

    return 0;
}


// Enter the number of memory locations (m): 10
// Enter the number of employee keys (n): 5
// Enter 5 keys (4-digit integers):
// 1234
// 5678
// 9101
// 1123
// 1456
// Enter a key to search: 5678

// Key 1234 inserted at address 4
// Key 5678 inserted at address 8
// Key 9101 inserted at address 1
// Key 1123 inserted at address 3
// Key 1456 inserted at address 6
// Hash Table:
// Address 0: EMPTY
// Address 1: 9101
// Address 2: EMPTY
// Address 3: 1123
// Address 4: 1234
// Address 5: EMPTY
// Address 6: 1456
// Address 7: EMPTY
// Address 8: 5678
// Address 9: EMPTY
// Key 5678 found in the hash table.

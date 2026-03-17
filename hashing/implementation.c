#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101  // Prime number for better distribution

// ─── Node for chaining (collision handling) ───────────────────────────────────
typedef struct Node {
    char *key;
    int   value;
    struct Node *next;
} Node;

// ─── Hash Table ───────────────────────────────────────────────────────────────
typedef struct {
    Node *buckets[TABLE_SIZE];
} HashTable;

// ─── Hash Function (fixed) ────────────────────────────────────────────────────
unsigned int hash(const char *key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = hashValue * 31 + (unsigned char)*key;
        key++;
    }
    return hashValue % TABLE_SIZE;
}

// ─── Create Table ─────────────────────────────────────────────────────────────
HashTable *createTable(void) {
    HashTable *table = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
        table->buckets[i] = NULL;
    return table;
}

// ─── Insert ───────────────────────────────────────────────────────────────────
void insert(HashTable *table, const char *key, int value) {
    unsigned int index = hash(key);
    Node *curr = table->buckets[index];

    // Update if key already exists
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    // Insert new node at head
    Node *newNode = malloc(sizeof(Node));
    newNode->key   = strdup(key);
    newNode->value = value;
    newNode->next  = table->buckets[index];
    table->buckets[index] = newNode;
}

// ─── Search ───────────────────────────────────────────────────────────────────
int search(HashTable *table, const char *key, int *outValue) {
    unsigned int index = hash(key);
    Node *curr = table->buckets[index];

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            *outValue = curr->value;
            return 1;   // found
        }
        curr = curr->next;
    }
    return 0;           // not found
}

// ─── Delete ───────────────────────────────────────────────────────────────────
void delete(HashTable *table, const char *key) {
    unsigned int index = hash(key);
    Node *curr = table->buckets[index];
    Node *prev = NULL;

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            if (prev) prev->next = curr->next;
            else       table->buckets[index] = curr->next;
            free(curr->key);
            free(curr);
            printf("Deleted key: \"%s\"\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key \"%s\" not found.\n", key);
}

// ─── Display ──────────────────────────────────────────────────────────────────
void display(HashTable *table) {
    printf("\n%-6s  %-15s  %s\n", "Index", "Key", "Value");
    printf("------  ---------------  -----\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = table->buckets[i];
        while (curr) {
            printf("%-6u  %-15s  %d\n", hash(curr->key), curr->key, curr->value);
            curr = curr->next;
        }
    }
}

// ─── Free Table ───────────────────────────────────────────────────────────────
void freeTable(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = table->buckets[i];
        while (curr) {
            Node *tmp = curr;
            curr = curr->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(table);
}

// ─── Main ─────────────────────────────────────────────────────────────────────
int main(void) {
    HashTable *table = createTable();

    // Insert key-value pairs
    insert(table, "apple",  10);
    insert(table, "banana", 20);
    insert(table, "cherry", 30);
    insert(table, "date",   40);
    insert(table, "elderberry", 50);

    // Update existing key
    insert(table, "apple", 99);

    // Display all entries
    printf("=== Hash Table Contents ===\n");
    display(table);

    // Search
    int val;
    const char *keys[] = {"banana", "mango"};
    for (int i = 0; i < 2; i++) {
        if (search(table, keys[i], &val))
            printf("\nFound  \"%s\" => %d\n", keys[i], val);
        else
            printf("\n\"%s\" not found.\n", keys[i]);
    }

    // Delete
    printf("\n");
    delete(table, "cherry");
    delete(table, "mango");    // non-existent

    printf("\n=== After Deletion ===\n");
    display(table);

    freeTable(table);
    return 0;
}
/*
**Sample Output:**
```
=== Hash Table Contents ===
Index  Key              Value
------  ---------------  -----
72      apple            99
15      banana           20
55      date             40
88      elderberry       50
38      cherry           30

Found  "banana" => 20
"mango" not found.

Deleted key: "cherry"
Key "mango" not found.

=== After Deletion ===
...
*/


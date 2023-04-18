#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct HashEntry {
    char* key;
    int value;
    struct HashEntry* next;
};

struct HashMap {
    struct HashEntry** entries;
    int size;
};

struct HashMap* create_map(int size) {
	int i; 
    struct HashMap* map = (struct HashMap*) malloc(sizeof(struct HashMap));
    map->entries = (struct HashEntry**) malloc(sizeof(struct HashEntry*) * size);
    for (i= 0; i < size; i++) {
        map->entries[i] = NULL;
    }
    map->size = size;
    return map;
}

void free_map(struct HashMap* map) {
	int i; 
    for (i = 0; i < map->size; i++) {
        struct HashEntry* entry = map->entries[i];
        while (entry != NULL) {
            struct HashEntry* prev = entry;
            entry = entry->next;
            free(prev->key);
            free(prev);
        }
    }
    free(map->entries);
    free(map);
}

int hash(char* key, int size) {
    int hash_value = 0;
    int i; 
    for (i = 0; i < strlen(key); i++) {
        hash_value += key[i];
    }
    return hash_value % size;
}

void put(struct HashMap* map, char* key, int value) {
    int index = hash(key, map->size);
    struct HashEntry* entry = map->entries[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    struct HashEntry* new_entry = (struct HashEntry*) malloc(sizeof(struct HashEntry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = map->entries[index];
    map->entries[index] = new_entry;
}

int get(struct HashMap* map, char* key) {
    int index = hash(key, map->size);
    struct HashEntry* entry = map->entries[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

int main() {
    struct HashMap* map = create_map(SIZE);
    put(map, "apple", 3);
    put(map, "banana", 2);
    put(map, "cherry", 5);
    printf("apple = %d\n", get(map, "apple"));
    printf("banana = %d\n", get(map, "banana"));
    printf("cherry = %d\n", get(map, "cherry"));
    free_map(map);
    return 0;
}


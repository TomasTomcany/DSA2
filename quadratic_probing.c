#include <stdio.h>
#include <stdlib.h>

// item of hash table
typedef struct ht_item {
    unsigned long key;
    unsigned long value;
}ht_item;

typedef struct hash_table {
    ht_item** items;
    unsigned long size;                        // size of the table
}hash_table;

// hash function
unsigned long hash_function(unsigned long key, unsigned long size){
    return key % size;                         // getting index for item to hash table
}

ht_item* create_item(unsigned long key, unsigned long value){
    ht_item* item = (ht_item*) malloc(sizeof(ht_item));
    item->key = key;
    item->value = value;
    return item;
}

// function for initializing table
hash_table* init_table(unsigned long size){
    hash_table* table = (hash_table*) malloc(sizeof(hash_table));
    table->size = size;
    // creating an array of hash table items
    table->items = (struct ht_item**)malloc(size*sizeof(ht_item*));
    for(unsigned long i=0;i<size;i++){
        // setting each element value to NULL to indicate free element in hash table
        table->items[i]=NULL;
    }
    return table;
}

// quadratic probing search
int search_quad(hash_table* table, unsigned long key){
    unsigned long index = hash_function(key, table->size);     // calculating hash index
    unsigned long iteration = 0;
    ht_item **items = table->items;
    while (items[index] != NULL){
        if (items[index]->key == key){
            return 1;
        }
        iteration++;
        // formula for getting the next index to search with quadratic probing
        index = (index + iteration*iteration)%table->size;
    }
    return 0;            // if NULL value was found, item is not located in hash table

}

// quadratic probing insert
void insert_quad(hash_table* table, unsigned long key, unsigned long value){
    ht_item* item = create_item(key, value);               // creating item
    unsigned long index = hash_function(key, table->size); // calculating hash index
    unsigned long base_index = index;                      // for checking if table is full
    unsigned long iteration = 0;
    ht_item **items = table->items;
    while(items[index] != NULL){
        if (items[index]->key == key){          // if key is already in hash table
            items[index]->key = key;            // overwrite item's value
            return;
        }

        iteration++;
        // formula for getting the next index to search with quadratic probing
        index = (index + iteration*iteration)%table->size;

        if (index == base_index){
            printf("No space in hash table.");
            return;
        }
    }
    items[index] = item;                // insert new item
}

// function for resizing hash table
hash_table* resize_table(hash_table *table, unsigned long size) {
    ht_item ** old = table->items;
    // allocation of new array with new size
    table->items = (struct ht_item **) realloc(table->items, size * sizeof(ht_item *));
    for (unsigned long i = size; i < size; i++) {
        // setting the newly allocated element to NULL to indicate free space in hash table
        table->items[i] = NULL;
    }

    for(unsigned long i = 0; i<table->size;i++){
        insert_quad(table,old[i]->key, old[i]->value);       // reinserting the values from previous table
    }

    table->size = size;                                 // changing the size value
    return table;
}

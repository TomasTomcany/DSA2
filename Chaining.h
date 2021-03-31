#ifndef DSA_TREES_HASHES_CHAINING_H
#define DSA_TREES_HASHES_CHAINING_H

unsigned long hash_f(unsigned long i, unsigned long size);
typedef struct Ht_item Ht_item;
struct Ht_item;
typedef struct LinkedList LinkedList;
struct LinkedList {
    Ht_item* item;
    LinkedList* next;
};
typedef struct HashTable HashTable;
struct HashTable {
    // Contains an array of pointers
    // to items
    Ht_item** items;
    LinkedList** overflow_buckets;
    unsigned long size;
    unsigned long count;
};
static LinkedList* allocate_list ();
static LinkedList* linkedlist_insert(LinkedList* list, Ht_item* item);
static void free_linkedlist(LinkedList* list);
static LinkedList** create_overflow_buckets(HashTable* table);
static void free_overflow_buckets(HashTable* table);
Ht_item* create_item_ch(unsigned long key, unsigned long value);
HashTable* create_table(unsigned long size);
void free_item(Ht_item* item);
void free_table(HashTable* table);
void handle_collision(HashTable* table, unsigned long index, Ht_item* item);
void ht_insert(HashTable* table, unsigned long key, unsigned long value);
int ht_search(HashTable* table, unsigned long key);


#endif //DSA_TREES_HASHES_CHAINING_H

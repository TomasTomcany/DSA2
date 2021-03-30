#ifndef DSA_TREES_HASHES_QUADRATIC_PROBING_H
#define DSA_TREES_HASHES_QUADRATIC_PROBING_H

typedef struct ht_item {
    unsigned long key;
    unsigned long value;
}ht_item;
typedef struct hash_table {
    ht_item** items;
    unsigned long size;                        // size of the table
}hash_table;

unsigned long hash_function(unsigned long key, unsigned long size);
ht_item* create_item(unsigned long key, unsigned long value);
hash_table* init_table(unsigned long size);
int search_quad(hash_table* table, unsigned long key);
void insert_quad(hash_table* table, unsigned long key, unsigned long value);


#endif //DSA_TREES_HASHES_QUADRATIC_PROBING_H

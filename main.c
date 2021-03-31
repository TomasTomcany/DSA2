#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "AVL.h"
#include "Red-Black.h"
#include "quadratic_probing.h"
#include "Chaining.h"

void tree_tester(long size){
    node *root1 = NULL;                         // initializing root of the tree
    struct node *root2 = NULL;
    srand(time(NULL));                 // setting random number generator

    // test insert avl
    clock_t start = clock();
    for(long i=0;i<size;i++)
    {
        root1=insert(root1,((rand()%size)+1)*((rand()%10)+1));
    }
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation insert of AVL tree in ms: %f\n", elapsed);

    // test insert red-black
    start = clock();
    for (int i = 0; i < size; ++i)
        insert_rb(&root2, ((rand()%size)+1)*((rand()%10)+1));
    stop = clock();
    elapsed = (double)(stop - start)  * 1000/ CLOCKS_PER_SEC;
    printf("Operation insert of Red_Black tree in ms: %f\n",elapsed);

    // test search avl
    start = clock();
    for(long i=0;i<size;i++)
    {
        search(root1, ((rand()%size)+1)*((rand()%10)+1));
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation search of AVL tree in ms: %f\n", elapsed);

    // test search red-black
    start = clock();
    for(long i=0;i<size;i++)
    {
        search_rb(root2, ((rand()%size)+1)*((rand()%10)+1));
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation search of Red-Black tree in ms: %f\n", elapsed);
}

void hash_table_tester(long size){
    // quadratic probing
    hash_table *table = init_table(size);
    srand(time(NULL));

    clock_t start = clock();
    for(long i=0;i<size;i++)
    {
        insert_quad(table, ((rand()%size)+1)*((rand()%10)+1), i+1);
    }
    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation insert of quadratic probing in ms: %f\n", elapsed);

    start = clock();
    for(long i=0;i<size;i++)
    {
        search_quad(table, ((rand()%size)+1)*((rand()%10)+1));
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation search of quadratic probing in ms: %f\n", elapsed);

    free_ht_table(table);

    // separate chaining
    HashTable* ht = create_table(size);
    start = clock();
    for(long i=0;i<size;i++)
    {
        ht_insert(ht, ((rand()%size)+1)*((rand()%10)+1), i+1);
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation insert of separate chaining in ms: %f\n", elapsed);

    start = clock();
    for(long i=0;i<size;i++)
    {
        ht_search(ht, ((rand()%size)+1)*((rand()%10)+1));
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Operation search of separate chaining in ms: %f\n", elapsed);
    free_table(ht);

}

int main(void){
    //tree_tester(10000000);
    hash_table_tester(10000);
    return 0;
}
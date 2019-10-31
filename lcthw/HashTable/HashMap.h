#ifndef _lcthw_Hashmap_h
#define _lcthw_Hashmap_h

#include<stdint.h>
#include<../DMA/darray.h>

#define DEFAULT_NUMBER_OF_BUCKETS 100

typedef int(*Hashmap_compare)(void *a, void *b); // 
typedef uint32_t (* Hashmap_hash)(void *key); // receive keys, then output a uint32_t index 

typedef struct Hashmap {
    Darray *buckets;
    Hashmap_compare compare;
    Hashmap_hash hash;
}Hashmap;

typedef struct HashmapNode {
    void *key;
    void *data;
    uint32_t hash;
} HashmapNode;

typedef int(*Hashmao_traverse_cb)(HashmapNode *node); //

typedef *Hashmap_create(Hashmap_compare compare, Hashmap_hash);
void *Hashmap_destroy(Hashmap *map);

int Hashmao_set(Hashmap *map, void *key, void *data);
void *Hashmap_get(Hashmap *map, void *key);

int Hashmap_traverse(Hashmap *map, void *key);

#endif
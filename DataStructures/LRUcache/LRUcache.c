/**
 * source: https://leetcode.com/problems/lru-cache/
 * ToDo: need to implement some data structure from scratch
 **/

#include<stdio.h>
#include<stdlib.h>
#define HASH_SIZE 500

typedef struct node{
    int key;
    int value;
    struct node *prev;
    struct node *next;
}Node; 

Node *newNode(int key, int value){
    Node *tem = malloc(sizeof(Node));
    tem -> prev = NULL;
    tem -> next = NULL;
    tem -> key = key;
    tem -> value = value;
    return tem; 
}

void printDLL(Node *head) {
    if(!head) {
        printf("Empty linked list\n");
        return;
    }
    Node *tem = head;
    printf("double linked list: ");
    while (tem -> next) {
        printf ("(%d, %d) -> ", tem -> key, tem -> value );
        tem = tem -> next;
    }
    printf("(%d, %d)\n", tem -> key, tem -> value );
}

void freeList(Node *head){
    Node *tem = NULL;
    while( (tem=head) != NULL) {
        head = head -> next;
        free(tem);
    }
}

typedef struct {
    Node *head;
    Node *tail;
} List;

// by pass in an key, you can verify that whether this key existed in the DLL or not
// hash function output an index to a key.
typedef struct {
    Node *table[HASH_SIZE];
    int capacity;
    int size;
}Hash;


typedef struct {
    List *l;
    Hash *h;
}LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache * hash_DLL = malloc(sizeof(LRUCache)); // ! what happens hash_DLL = NULL;

    // Initialize hash table
    Hash *hash = malloc(sizeof(Hash));
    hash -> capacity = capacity;
    for (int i = 0; i < HASH_SIZE; ++i){
        hash->table[i] = NULL;
    }
    hash -> size = 0;

    List * root = malloc(sizeof(List));
    root -> head  = NULL;
    root -> tail = NULL;

    hash_DLL -> l = root;
    hash_DLL -> h = hash;

    return hash_DLL;
}

int hashFunction(int key){
    int address;
    address = key % HASH_SIZE;
    return address;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Hash *hash = obj -> h;
    if (!hash->table[hashFunction(key)]) return -1;

    // find the corresponding node in DLL corresponds to this node
    Node * tem = hash->table[hashFunction(key)];

    if (tem -> key == obj -> l -> head -> key) return tem -> value;
    int res = tem -> value;
    Node * prevNode = tem -> prev;
    Node * nextNode = tem -> next;

    // Not the last node of DLL
    if(nextNode != NULL){
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

    if (!nextNode){
        obj -> l -> tail = obj -> l -> tail -> prev;
        prevNode -> next = NULL;
    }

    tem -> next =  obj -> l -> head;
    obj -> l -> head -> prev = tem;
    obj -> l -> head = tem;
    //hash->table[hashFunction(key)] = NULL;
    //printDLL(obj -> l -> head); 
    printf("res = %d\n", res);
    return res;
}



void lRUCachePut(LRUCache* obj, int key, int value) {
    Node *headNode = obj -> l -> head;
    Node *tailNode = obj -> l -> head;
    Node *tem = newNode(key, value);

    // update the prime node of DLL
    if (!headNode){
        headNode = tem;
        tailNode = headNode;
        obj -> l -> tail = tailNode;
    }
    else{
        tem -> next = headNode;
        headNode -> prev = tem;
        headNode = tem;
    }

    Hash *hash = obj -> h;
    hash -> table[hashFunction(key)] = tem;
    ++(hash -> size);
    obj -> l -> head = headNode;
    printDLL(obj -> l -> head);
    //evict the tail node in DLL 
    if((hash -> size) > (hash -> capacity)){
        Node * originTailNode = obj -> l -> tail;
        obj -> h -> table[hashFunction(originTailNode -> key)] = NULL;
        obj -> l -> tail = obj -> l -> tail -> prev; 
        free(originTailNode);
    }
}

void lRUCacheFree(LRUCache* obj) {
    freeList(obj -> l -> head);
    free(obj -> l);
    free(obj -> h);
    free(obj);
}

int main(){
    int capacity = 2;
    LRUCache* obj = lRUCacheCreate(capacity);
    printf("lRUCacheCreate Completed\n");

    int param_1 = lRUCacheGet(obj, 1);
    printf("key: %d value: %d\n", 1, param_1);

    lRUCachePut(obj, 1, 1);
    printDLL(obj -> l -> head);
    lRUCachePut(obj, 2, 2);
    printDLL(obj -> l -> head);

    param_1 = lRUCacheGet(obj, 1);
    printf("key: %d value: %d\n", 1, param_1);
    printDLL(obj -> l -> head);

    lRUCachePut(obj, 3, 3);
    printDLL(obj -> l -> head);
    param_1 = lRUCacheGet(obj, 2);
    printf("key: %d value: %d\n", 2, param_1);
    

    lRUCacheFree(obj);
    return 0;
}
/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
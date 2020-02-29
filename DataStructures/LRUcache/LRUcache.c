/**
 * @file
 * 
 * source: https://leetcode.com/problems/lru-cache/
 * 
 * ![](https://www.interviewcake.com/images/svgs/lru_cache__doubly_linked_list.svg?bust=204)
 * 
 * What if the key is greater than HASH_SIZE, there exists confliction, what will happens then?
 * 
 * Clearly, my code doesn't put this case into consideration, so I need to make HASH_SIZE as large as possible
 */

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
    Node *nodePtr = malloc(sizeof(Node));
    nodePtr -> prev = NULL;
    nodePtr -> next = NULL;
    nodePtr -> key = key;
    nodePtr -> value = value;
    return nodePtr; 
}

/**
 * Display the `double linked list` from head node to tail node
 */ 
void printDLL(Node *head) {
    if(!head) {
        printf("Empty linked list\n");
        return;
    }
    Node *nodePtr = head;
    printf("double linked list: ");
    while (nodePtr -> next) {
        printf ("(%d, %d) -> ", nodePtr -> key, nodePtr -> value );
        nodePtr = nodePtr -> next;
    }
    printf("(%d, %d)\n", nodePtr -> key, nodePtr -> value );
}

void freeDLL(Node *head){
    Node *nodePtr = NULL;
    while( (nodePtr=head) != NULL) {
        head = head -> next;
        free(nodePtr);
    }
}

typedef struct {
    Node *head;
    Node *tail;
}List;

/* by pass in an key, you can verify that whether this key existed in the DLL or not*/
typedef struct {
    Node *table[HASH_SIZE];
    int capacity;
    int size;
}HashTable;

typedef struct {
    List *l;
    HashTable *h;
}LRUCache;


/**
 * Initialize the data structure of `LRUCache`, which includes
 * * `List` part, which again includes 2 parts
 * * `HashTable` part, which again include 3 parts
 */ 
LRUCache*lRUCacheCreate(int capacity) {
    LRUCache * hash_DLL = malloc(sizeof(LRUCache)); // ! what happens hash_DLL = NULL;

    HashTable *ptrToHashTable = malloc(sizeof(HashTable));
    ptrToHashTable -> capacity = capacity;
    for(int i = 0; i < HASH_SIZE; ++i){
        ptrToHashTable->table[i] = NULL;
    }
    ptrToHashTable -> size = 0;

    List * ptrToDLL = malloc(sizeof(List));
    ptrToDLL -> head  = NULL;
    ptrToDLL -> tail = NULL;

    hash_DLL -> l = ptrToDLL;
    hash_DLL -> h = ptrToHashTable;

    return hash_DLL;
}

/**
 * hashFunction convert the key to a specifc index, which you can use to access 
 * the corresponding value in the array
 */ 
int hashFunction(int key){
    int address;
    address = key % HASH_SIZE;
    return address;
}

/**
 * If the key is in the LRU cache, return the corresponding value, return -1 otherwise, 
 * meanwhile, adjust the position of items in LRUCache
 */ 
int lRUCacheGet(LRUCache* obj, int key) {
    if (!obj -> h->table[hashFunction(key)]) return -1;

    // find the corresponding node in DLL corresponds to this key
    Node * nodePtr = obj -> h->table[hashFunction(key)];

    //in a case you don't need to adjust the node order in DLL
    if (nodePtr == obj -> l -> head) return nodePtr -> value;

    int res = nodePtr -> value;
    // Not getting the last node of DLL
    if(nodePtr -> next){
        nodePtr -> prev -> next = nodePtr -> next;
        nodePtr -> next -> prev = nodePtr -> prev;
    }
    else{
        obj -> l -> tail = obj -> l -> tail -> prev;
        nodePtr -> prev -> next = NULL;
    }

    // update the new head node of DLL
    nodePtr -> next =  obj -> l -> head;
    nodePtr -> prev = NULL; // what if we dismiss this operation, it cause problem if we display the DLL from tail to head
    obj -> l -> head -> prev = nodePtr;
    obj -> l -> head = nodePtr;
    return res;
}

/**
 * When you put a pair of key and value, update the DLL(both the order and total number of nodes)
 * and hashtable 
 */
// I'm amazed by what I implemented before if that on earth was coded line by line by myself.
void lRUCachePut(LRUCache* obj, int key, int value) {
    //In a case DLL already got key existed, no need to update obj -> h
    Node *existedNode = obj -> h -> table[hashFunction(key)];
    if (existedNode){
        existedNode -> value = value;      
        // update head node of DLL
        if(existedNode != obj -> l -> head) {
            if(existedNode -> next){     
                existedNode -> prev -> next = existedNode -> next;
                existedNode -> next -> prev = existedNode -> prev;
            }
            else{        
                existedNode -> prev -> next  = NULL;
                obj -> l -> tail = existedNode -> prev;
            }
            obj -> l -> head -> prev = existedNode;
            existedNode -> next = obj -> l -> head;
            existedNode -> prev = NULL; //what happens if this operation is omitted?
            obj -> l -> head = existedNode;
        }
    }
    else{
        // In a case there is no such node in the DLL
        Node *nodePtr = newNode(key, value);

        // In the case of put into an empty DLL
        if (!obj -> l -> head){
            obj -> l -> head = nodePtr; 
            obj -> l -> tail = nodePtr;
        }
        // In the case of putting into an non-empty DLL, insert new node as head node
        else{
            nodePtr -> next = obj -> l -> head;
            obj -> l -> head -> prev = nodePtr;
            obj -> l -> head = nodePtr;
        }
        obj -> h -> table[hashFunction(key)] = nodePtr;
        ++(obj -> h -> size);
    }
    //printDLL(obj -> l -> head);

    //evict the tail node in DLL 
    if((obj -> h -> size) > (obj -> h -> capacity)){
        Node * originTailNode = obj -> l -> tail;
        obj -> h -> table[hashFunction(originTailNode -> key)] = NULL;
        --(obj -> h -> size);
        obj -> l -> tail = obj -> l -> tail -> prev; 
        obj -> l -> tail -> next = NULL;
        free(originTailNode);
    }
}

void lRUCacheFree(LRUCache* obj) {
    freeDLL(obj -> l -> head);
    free(obj -> l);
    free(obj -> h);
    free(obj);
}

int main(){
    int capacity = 2;
    LRUCache* obj =lRUCacheCreate(capacity);
    printf("createLRUCache Completed\n");


    lRUCachePut(obj, 2, 1);
    printDLL(obj -> l -> head);

    lRUCachePut(obj, 1, 1);
    printDLL(obj -> l -> head);

    lRUCachePut(obj, 2, 3);
    printDLL(obj -> l -> head);
 
    lRUCachePut(obj, 4, 1);
    printDLL(obj -> l -> head);

     int param_1 = lRUCacheGet(obj, 1);
    printf("key: %d value: %d\n", 1, param_1);
    param_1 = lRUCacheGet(obj, 2);
    printf("key: %d value: %d\n", 2, param_1);


    lRUCacheFree(obj);
    return 0;
}
/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj =lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
*/
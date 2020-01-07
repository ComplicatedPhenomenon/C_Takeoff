/**
 * source: https://leetcode.com/problems/lru-cache/
 * ToDo: need to implement some data structure from scratch
 **/


typedef struct node {
    int key;
    int value;
    struct node *prev;
    struct node *next;
}Node;
typedef struct {
    int key;
}Map;

typedef struct  {
    int capicity;
    Node *ptrToDLL;
    Map *ptrToMap;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    
}

int lRUCacheGet(LRUCache* obj, int key) {
  
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  
}

void lRUCacheFree(LRUCache* obj) {
    
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
// all credit goes to git@github.com:wcarss/lru-cache.git
// better to demonstrate this code to animation
// takes long time to figure out how it actually works
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define perror(x) fprintf(stderr, "%s\n", x)
#define STRING_SIZE 64

typedef struct node {
   struct node *next;
   struct node *prev;
   int value;
   void *ptr;
   char key[STRING_SIZE];
}Node;

Node *node_create(char *key, int value, void *ptr);
void node_destroy(Node *n);

typedef struct List {
   Node *root;
   Node *current;
}List;

List *list_create();
void list_destroy(List *l);
void list_remove_node(List *l, Node *n);
void list_print(List *l);
void list_push(List *l, char *key, int value, void *ptr);
Node *list_find(List *l, char *key);

#define KEY_SIZE 64
#define HASH_SIZE 100

typedef struct Hash {
   List *storage[HASH_SIZE]; // Node *head;
   int size;
}Hash;

Hash *hash_create();
void hash_destroy(Hash *h);
void hash_add(Hash *h, char *key, int value, Node *ptr);
Node *hash_get(Hash *h, char *key);
void hash_del(Hash *h, char *key);
int hash_function(char *key);

int get(Hash *h, List *l, char *key);
void set(Hash *h, List *l, char *key, int value);
void del(Hash *h, List *l, char *key);

int main(){
    /**
    List *ptrToList = list_create();
    //printf("%ld\n", sizeof("Complicated"));
    char *key = "ComplicatedPhenomenon";
    void *ptr = NULL;
    list_push(ptrToList, key, 4, ptr);
    list_print(ptrToList);
    key = "CZFZDXX";
    list_push(ptrToList, key, 5, ptr);
    list_print(ptrToList);
    key = "WALLE1000000001";
    list_push(ptrToList, key, 6, ptr);
    list_print(ptrToList);
    list_destroy(ptrToList);

    Hash *h = hash_create();
    key = "CZFZDXX";
    Node *ptrNode = NULL;
    hash_add(h, key, 4, ptrNode);
    key = "WALLE1000000001";
    hash_add(h, key, 6, ptr);
    key = "CZFZDXX";
    hash_get(h, key);
    hash_destroy(h);
    **/
    Hash *h = hash_create();
    List *l = list_create();

    set(h, l, "a", 1);
    set(h, l, "b", 2);
    set(h, l, "c", 3);
    printf("%d\n", get(h, l, "a"));
    list_print(l);
    del(h, l, "b");
    list_print(l);

    list_destroy(l);
    hash_destroy(h);
    
    return 0;
}

/* */
Node *node_create(char *key, int value, void *ptr) {
    Node *n = NULL;
    if (NULL == key) {
        perror("Null key passed into node_create.");
        return NULL;
    }
    
    if(NULL == (n = calloc(sizeof(Node), 1))) {
        perror("Failed to allocate nEew node in node_create.");
        return NULL;
    }
    
    n->next = NULL;
    n->prev = NULL;
    n->value = value;
    n->ptr = ptr;
    strncpy(n->key, key, STRING_SIZE);

    return n;
}

void node_destroy(Node *n) {
    if (NULL == n) {
        perror("Null node passed into node_destroy.");
        return;
    }
    n->next = NULL;
    n->prev = NULL;
    n->value = 0;
    n->ptr = NULL;
    memset(n->key, 0, STRING_SIZE);
    free(n);
}

List *list_create() {
    List *l = NULL;
    
    if (NULL == (l = calloc(sizeof(List), 1))) {
        perror("Failed to allocate new list in list_create.");
        return NULL;
    }
    
    l->root = NULL;
    l->current = NULL;

    return l;
}

void list_destroy(List *l) {
    if (NULL == l) {
        perror("Null list passed into list_destroy.");
        return;
    }
    
    while(NULL != l->root)
        list_remove_node(l, l->root);

    free(l);
}

void list_remove_node(List *l, Node *n) {
    Node *prev = NULL, *next = NULL;

    if (NULL == l) {
        perror("Null list passed to remove_node.");
        return;
    }
    if (NULL == l->root) {
        perror("Empty list passed to remove_node.");
        return;
    }
    if (NULL == n) {
        perror("Null node passed to remove_node.");
        return;
    }

    prev = n->prev;
    next = n->next;

    if (NULL == prev) {
        l->root = next;
    }
    else {
        prev->next = next;
    }
    if (NULL != next) {
        next->prev = prev;
    }

    node_destroy(n);
    l->current = l->root;
}

void list_print(List *l) {
    if (NULL == l) {
        perror("Null list passed into print_list.");
        return;
    }

    if (NULL == l->root) { 
        perror("Empty list passed into print_list.");
        return;
    }
    
    l->current = l->root;
    while(l->current != NULL) {
        printf("(%s, %d)", l->current->key, l->current->value);
        if(l->current->next != NULL) printf(", ");
        l->current = l->current->next;
    }
    printf("\n");
    l->current = l->root;
}

void list_push(List *l, char *key, int value, void *ptr) {
    Node *n = NULL;
    if (NULL == l) {
        perror("Null list passed into list_push.");
        return;
    }

    if (NULL == key) {
        perror("Null key passed into list_push.");
        return;
    }

    if (NULL == (n = node_create(key, value, ptr))) {
        perror("Failed to allocate new node in list_push.");
        return;
    }

    if(NULL != l->root)
        l->root->prev = n;
        
    n->next = l->root;
    l->root = n;
    l->current = l->root;
}

Node *list_find(List *l, char *key) {
    Node *n = NULL;
    if(NULL == l) {
        perror("Null list passed into list_find.");
        return NULL;
    }

    if(NULL == key) {
        perror("Null key passed into list_find.");
        return NULL;
    }

    l -> current = l -> root;
    while(l->current != NULL && 0 != strcmp(key, l->current->key)) {
        l->current = l->current->next;
    }

    n = l->current;
    l->current = l->root;
    return n;
}

Hash *hash_create() {
    int i = 0;
    Hash *h = NULL;
    if(NULL == (h = calloc(sizeof(Hash), 1))) {
        perror("Failed to allocate hash in hash_create.");
        return NULL;
    }

    h->size = HASH_SIZE;
    for (i = 0; i < h->size; i++) {
        if(NULL == (h->storage[i] = list_create())) {
            perror("Failed to allocate list in hash_create.");
            return NULL;
        }
    }
    return h;
}

void hash_destroy(Hash *h) {
    int i;
    if(NULL == h) {
        perror("Null hash passed into hash_destroy.");
        return;
    }

    for (i = 0; i < h->size; i++) {
        list_destroy(h->storage[i]);
        h->storage[i] = NULL;
    }
    h->size = 0;
    free(h);
}

void hash_add(Hash *h, char *key, int value, Node *ptr) {
    int access_value = hash_function(key);
    list_push(h->storage[access_value], key, value, ptr);
}

Node *hash_get(Hash *h, char *key) {
    Node *n = NULL;
    int access_value = hash_function(key);
    n = list_find(h -> storage[access_value], key);
    return n ? n->ptr : NULL;
}

void hash_del(Hash *h, char *key) {
    int access_value = hash_function(key);
    Node *n = list_find(h->storage[access_value], key);
    list_remove_node(h->storage[access_value], n);
}

/*find the corresponding value to  a key*/
int hash_function(char *key) {
    int i;
    int hash_value = 0;
    for (i = 0; key[i] != '\0'; i++) {
        hash_value += key[i] % 2 == 0 ? key[i] * 3 : key[i] * 7;
    }
    hash_value = hash_value % HASH_SIZE;
    return hash_value;
}

int get(Hash *h, List *l, char *key) {
    int value = 0;
    Node *n = NULL;
    if(NULL != (n = hash_get(h, key))) {
        value = n->value;
        list_remove_node(l, n);
        list_push(l, key, value, NULL);
        hash_add(h, key, value, l->root); 
    }
    return value;
}

void set(Hash *h, List *l, char *key, int value) {
    Node *n = NULL;
    if(NULL != (n = hash_get(h, key))) {
        list_remove_node(l, n);
    }
    list_push(l, key, value, NULL);
    hash_add(h, key, value, l->root);
}

void del(Hash *h, List *l, char *key) {
    Node *n = NULL;
    if(NULL != (n = hash_get(h, key)))
    {
        list_remove_node(l, n);
    }
    hash_del(h, key);
}

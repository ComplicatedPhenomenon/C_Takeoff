typedef struct Cell {
    int data;
    struct Cell * next;
} listNode;

listNode * newNode(int val);
int lengthOfSLL(listNode *head);
void printSLL(listNode *head);
void freeSLL(listNode *head);
listNode * reverseSLL(listNode *head);
listNode * reversePartOfSLL(listNode  *head, int m, int n);
listNode * insertToSLL(listNode  *head, int postion, int val);
listNode * removeElementsOfSLL(listNode* head, int val);
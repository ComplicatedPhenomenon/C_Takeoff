#include"singleLinkedList.h"

int main(){
    listNode *head = newNode(1);
    listNode *tem = head;
    int i = 2;
    while(i < 6){
        tem -> next = newNode(i);
        tem = tem -> next;
        i += 1;
    }
    printSLL(head);

    head = reverseSLL(head);
    printSLL(head);

    head = reverseSLL(head);
    printSLL(head);

    head = insertToSLL(head, 2, 2);
    printSLL(head);

    head = removeElementsOfSLL(head, 2);
    printSLL(head);

    head = removeElementsOfSLL(head, 1);
    printSLL(head);
    head = removeElementsOfSLL(head, 3);
    printSLL(head);
    head = removeElementsOfSLL(head, 4);
    printSLL(head);
    head = removeElementsOfSLL(head, 5);
    printSLL(head);

    freeSLL(head);
}
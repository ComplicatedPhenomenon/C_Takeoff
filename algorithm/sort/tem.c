/**
  https://leetcode.com/problems/sort-list/
  Runtime: 12 ms, faster than 99.01% of C online submissions for Sort List.
  Memory Usage: 9.7 MB, less than 100.00% of C online submissions for Sort List.
 **/

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *s = NULL, *t = NULL, *l = NULL , *r = NULL, *go = NULL;
    int mid, max = -9999,min = 9999;

    if(head != NULL){
        s = head;
        go = head;
        r = head;
        mid = s->val;
        while(go->next != NULL){
            go = go->next;
            if(go->val < mid){
                if(go->val < min) min = go->val;
                if(l == NULL){
                    l = go;
                    t = go;
                }
                else{
                    l->next = go;
                    l = l->next;
                }
            }
            else{
                if(go->val > max) max = go->val;
                r->next = go;
                r = r->next;
            }
        }
        if(r!=NULL)
            if(r->next != NULL) r->next = NULL;

        if(l!=NULL)
            if(l->next != NULL) l->next = NULL;

        if(s->next != NULL){
            if(s->val != max){
                go = head;
                s = s->next;
                s = sortList(s);
                go ->next = s;
                s = go;
            }
            if(t != NULL){
                if(t->next != NULL) t = sortList(t);
                l = t;
                while(l->next !=NULL) l = l->next;
                l->next = s;
                return t;
            }
            return s;
        }
        else if(t!=NULL){
            if(t->next!=NULL) t = sortList(t);
            l = t;
            while(l->next !=NULL)
                l = l->next;
            l->next = s;
            return t;
        }
        return head;
    }

    else return head;
}

#include<iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * cur = head;
        RandomListNode *next, *tmp, *res;
        if(head == NULL)
            return NULL;
        //create the copy of every node in the list and insert 
        //it in original list between current and next node.
        while(cur) {
            tmp = new RandomListNode(cur->label);
            //tmp->label = cur->label;
            tmp->random = NULL;
            next = cur->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = next;
        }

        //save result pointer
        res = head->next; 

        //copy the arbitrary link for result
        cur = head;
        while(cur) {
            tmp = cur->next;
            if(cur->random != NULL)
                tmp->random = cur->random->next;
            cur = tmp->next;
        }

        //restore the original and copy linked lists
        cur = head;
        tmp = head->next;
        while(cur && tmp) {
            cur->next = cur->next->next;
            cur = cur->next;
            if(tmp->next) {
                tmp->next = tmp->next->next;
                tmp = tmp->next;
            }
        }
        return res;
    }
};

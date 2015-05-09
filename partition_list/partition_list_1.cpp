#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* partition(ListNode* head, int x){
        ListNode node1(0), node2(0);
        ListNode *p1 = &node1, *p2 = &node2;
        while(head) {
            if(head->val < x)
            p1 = p1->next = head;
            else
            p2 = p2->next = head;
            head = head->next;
        }
        p2->next = NULL;
        p1->next = node2.next;
        return node1.next;
    }
};


int main(){
    ListNode *input = new ListNode(1);
    ListNode *tmp = input;
    ListNode *new_node = new ListNode(4);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(3);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(2);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(5);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(2);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(3);
    tmp->next = new_node;
    tmp = tmp->next;
    Solution s;
    ListNode *output;
    output = s.partition(input, 3);
    tmp = output;
    while(tmp != NULL){
        cout << tmp->val << "\t";
        tmp = tmp->next;
    }
    return 0;
}

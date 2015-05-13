#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while(cur != NULL){
            while(cur->next != NULL && cur->val == cur->next->val){
                cur = cur->next;
            }
            if(cur == pre->next){
                pre->next = cur;
                pre = cur;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main() {
    ListNode *input = new ListNode(1);
    ListNode *tmp = input;
    ListNode *new_node = new ListNode(1);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(1);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(2);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(3);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(3);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(4);
    tmp->next = new_node;
    tmp = tmp->next;
    new_node = new ListNode(5);
    tmp->next = new_node;
    tmp = tmp->next;
    tmp->next = NULL;
    Solution s;
    ListNode *output;
    output = s.deleteDuplicates(input);
    while(output != NULL){
        cout << output->val << "\t";
        output = output->next;
    }
    return 0;
}

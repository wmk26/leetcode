#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        ListNode* tmp;
        while(cur != NULL){
            tmp = cur->next;
            if(cur->next == NULL)
                break;
            cur->next = cur->next->next;
            tmp->next = cur;
            pre->next = tmp;
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main() {
    ListNode* input = new ListNode(1);
    ListNode* tmp = input;
    //ListNode* new_node = new ListNode(2);
    //tmp->next = new_node;
    //tmp = tmp->next;
    //new_node = new ListNode(3);
    //tmp->next = new_node;
    //tmp = tmp->next;
    //new_node = new ListNode(4);
    //tmp->next = new_node;
    //tmp = tmp->next;
    //new_node = new ListNode(5);
    //tmp->next = new_node;
    //tmp = tmp->next;
    //new_node = new ListNode(6);
    //tmp->next = new_node;
    //tmp = tmp->next;
    tmp->next = NULL;

    Solution s;
    ListNode *output = s.swapPairs(input);
    while(output != NULL){
        cout << output->val << "\t";
        output = output->next;
    }
    return 0;
}

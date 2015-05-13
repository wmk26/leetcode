#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        if(head == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(n){
            fast = fast->next;
            n--;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main() {
    ListNode* input = new ListNode(1);
    ListNode* tmp = input;
    ListNode* new_node = new ListNode(2);
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
    ListNode* output;
    output = s.removeNthFromEnd(input, 2);
    while(output != NULL){
        cout << output->val << "\t";
        output = output->next;
    }
    return 0;
}

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* reverseKGroup(ListNode *head, int k){
        if(head == NULL)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* tmp = head;
        int len = 1;
        ListNode* pre;
        ListNode* cur;
        while(tmp->next != NULL){
            len++;
            tmp = tmp->next;
        }
        for(pre = &dummy, cur = head; len / k != 0; len -= k){
            int step = k-1;
            ListNode* before = cur;
            while(step){
                tmp = cur->next;
                cur->next = cur->next->next;
                tmp->next = before;
                pre->next = tmp;
                step--;
                before = pre->next;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
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
    ListNode* output = s.reverseKGroup(input, 3);
    while(output != NULL) {
        cout << output->val << "\t";
        output = output->next;
    }
    return 0;
}

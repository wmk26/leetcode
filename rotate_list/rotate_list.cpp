#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* rotateRight(ListNode* head, int k){
        if(head == NULL || k == 0)
            return head;
        int len = 1;
        ListNode *cur = head;
        while(cur->next != NULL){
            len++;
            cur = cur->next;
        }
        cur->next = head;
        k = k % len;
        int step = len - k - 1;
        ListNode *tmp = head;
        while(step > 0){
            tmp = tmp->next;
            step--;
        }
        head = tmp->next;
        tmp->next = NULL;
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
    
    Solution s;
    ListNode* output;
    output = s.rotateRight(input, 2);
    while(output != NULL){
        cout << output->val << "\t";
        output = output->next;
    }
    return 0;
}

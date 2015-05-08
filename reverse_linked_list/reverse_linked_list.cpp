#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):
    val(x),
    next(NULL){}
};

class Solution {
    public:
    ListNode *reverseBetween(ListNode *head, int m, int n){
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;

        for(int i = 0; i < m-1; i++){
            pre = pre->next;
        }
        ListNode *start = pre->next;
        ListNode *then = start->next;

        for(int i = m; i < n; i++){
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }
        return dummy.next; 
    }
};

int main(){
    ListNode *head = new ListNode(1);
    ListNode *input = head;
    for(int i = 2; i <= 5; i++){
        ListNode *new_node = new ListNode(i);
        input->next = new_node;
        input = input->next;
    }
    ListNode *tmp = head;
    while(tmp != NULL){
        cout << tmp->val << "\t";
        tmp = tmp->next;
    }
    cout << endl;
    Solution s;
    ListNode *output;
    output = s.reverseBetween(head, 2, 4); 
    while(output != NULL){
        cout << output->val << "\t";
        output = output->next;
    }
    cout << endl;
    return 0;
}

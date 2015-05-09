//has some error
#include <iostream>
//#include </home/wmk/leetcode/solution_cpp/github/linked_list/linked_list.hpp>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* partition(ListNode* head, int x){
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *start = pre;
        ListNode *first = pre;
        ListNode *tmp;
        int first_flag = 0;
        int begin = 0;
        while(pre->next != NULL){
            if(pre->next->val < x){
                if(first_flag == 0){
                    first = pre->next;
                    first_flag = 1;
                }
            }
            if(pre->next->val == x)
                begin = 1;
            if(begin == 1 && pre->next->val < x){
                tmp = pre->next;
                pre = tmp->next;
                tmp->next = first->next;
                first->next = tmp;
            }
            pre = pre->next;
        }
        return dummy.next;
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

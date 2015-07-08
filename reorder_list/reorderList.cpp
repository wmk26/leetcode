#include<iostream.
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;

        //find the median node;
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse second half of link List
        ListNode *mid = slow->next;
        ListNode *last = mid;
        ListNode *pre = NULL;
        while(last != NULL) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        slow->next = NULL;

        while(head != NULL && pre != NULL) {
            ListNode next1 = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next1;
            head = next1;
        }
    }
};

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    bool hasCycle(ListNode *head) { 
        ListNode *fast, *slow; 
        fast = slow = head;
        while(fast && slow) {
            if(fast->next == NULL or slow->next == NULL) 
                return false;
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow && slow != NULL) 
                return true;
        }
        return false;
    }
}

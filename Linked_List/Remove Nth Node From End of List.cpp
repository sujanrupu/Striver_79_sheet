class Solution {
public:
    int getLength(ListNode *head) {
        int length = 0;
        ListNode *curr = head;
        while(curr) {
            length++;
            curr = curr->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)   return NULL;
        int length = getLength(head);
        int pos = length - n;
        int count = 0;
        vector<int>ans;
        ListNode *curr = NULL;
        if(pos == 0) {
            head = head->next;
            curr = head;
        }
        else    curr = head;
        while(curr) {
            if(count != pos-1)    curr = curr->next;
            else    curr->next = curr->next->next;
            count++;
        }
        return head;
    }
};

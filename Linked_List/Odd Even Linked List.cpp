class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *curr = head;
        int index = 0;
        vector<int> a, b;
        while(curr) {
            if(index % 2 == 0)  a.push_back(curr->val);
            else    b.push_back(curr->val);
            index++;
            curr = curr->next;
        }
        vector<int>ans;
        for(int i = 0; i < a.size(); i++)   ans.push_back(a[i]);
        for(int i = 0; i < b.size(); i++)   ans.push_back(b[i]);
        curr = head;
        for(int i = 0; i < ans.size(); i++) {
            curr->val = ans[i];
            curr = curr->next;
        }
        return head;
    }
};

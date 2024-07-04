ListNode* mergeNodes(ListNode* head) 
{
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        ListNode* iterator = head->next;
        int sum = 0;

        while (iterator != NULL) 
        {
            if (iterator->val != 0) 
            {
                sum += iterator->val;
            } else 
            {
                current->next = new ListNode(sum);
                current = current->next;
                
                sum = 0;
            }
            iterator = iterator->next;
        }
        
        return dummy->next;
}

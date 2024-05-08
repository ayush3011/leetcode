/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *p = head, *q = head;
        int flag = 0;

        do
        {
            p = p->next;
            q = q->next;
            q = q ? q->next : q;
        } while (p && q && p != q);

        if (p == q)
            return true;
        return false;
    }
};
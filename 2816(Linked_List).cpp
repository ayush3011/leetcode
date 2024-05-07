/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *p = head, *q = NULL;
        while (p != NULL)
        {
            int newVal = p->val * 2;
            if (newVal < 10)
            {
                p->val = newVal;
            }
            else
            {
                p->val = newVal % 10;
                if (q == NULL)
                {
                    ListNode *t = new ListNode(1);
                    head = t;
                    head->next = p;
                }
                else
                {
                    q->val += 1;
                }
            }
            q = p;
            p = p->next;
        }
        return head;
    }
};
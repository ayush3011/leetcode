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
    ListNode *Reverse(ListNode *head)
    {
        ListNode *p = head, *q = NULL, *r = NULL;
        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
        return head;
    }

    ListNode *removeNodes(ListNode *head)
    {
        head = Reverse(head);

        ListNode *p = head, *temp = NULL;
        int maxx = head->val;

        while (p && p->next)
        {
            if (p->next->val < maxx)
            {

                temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else
            {
                maxx = p->next->val;
                p = p->next;
            }
        }
        head = Reverse(head);
        return head;
    }
};
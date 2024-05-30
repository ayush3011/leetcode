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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *l = &dummy;

        for (int i = 1; i < left; ++i)
        {
            l = l->next;
        }

        ListNode *head2 = l->next;
        ListNode *p = head2;
        ListNode *q = nullptr;
        ListNode *r = nullptr;

        for (int i = 0; i <= right - left; ++i)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        l->next = q;
        head2->next = p;

        return dummy.next;
    }
};
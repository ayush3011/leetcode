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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string binaryString = "";

        while (head) {
            int value = head->val;
            binaryString.push_back('0' + value);
            head = head->next;
        }

        int decimalInteger = 0;
        int powerFactor = 0;

        for (int i = binaryString.size() - 1; i >= 0; i--) {
            char bit = binaryString[i];
            if (bit == '1') {
                decimalInteger = decimalInteger + pow(2, powerFactor);
            }
            powerFactor++;
        }
        return decimalInteger;
    }
};

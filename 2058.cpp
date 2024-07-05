vector<int> nodesBetweenCriticalPoints(ListNode* head) 
{
        if (!head || !head->next || !head->next->next) return {-1, -1};
        
        vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        
        while (curr->next) 
        {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) 
            {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        if (criticalPoints.size() < 2) return {-1, -1};
        
        int minDistance = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); i++) 
        {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        return {minDistance, maxDistance};
}

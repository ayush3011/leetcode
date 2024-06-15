int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
{

        int n = profits.size();

        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) 
            vp.push_back({capital[i], profits[i]}); // capital first because we have to sort on the basis of capital.
        sort(vp.begin(), vp.end());

        priority_queue<int> pq;

        int totalProfit = w, j = 0;
        
        for (int i = 0; i < k; i++) 
        {
            while (j < n && vp[j].first <= totalProfit) 
            {
                pq.push(vp[j].second);
                j++;
            }
            if (pq.size() == 0)
                break;
            totalProfit += pq.top();
            pq.pop();
        }
        return totalProfit;
}

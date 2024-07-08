int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i + 1);
        }

        while (q.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                int x = q.front();
                q.push(x);
                q.pop();
            }
            q.pop();
        }

        return q.front();
}

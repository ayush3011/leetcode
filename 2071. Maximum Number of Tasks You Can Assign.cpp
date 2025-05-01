class Solution {
public:
    // Helper function to check if 'mid' number of tasks can be assigned to workers
    bool check(vector<int>& tasks, vector<int>& workers, int pills,
               int strength, int mid) {
        int pillsUsed = 0;

        // Using multiset to maintain a sorted set of the 'mid' strongest workers
        multiset<int> st(begin(workers),
                         begin(workers) + mid); // choose best 'mid' workers

        // Assign tasks from hardest to easiest among the selected 'mid' tasks
        for (int i = mid - 1; i >= 0; i--) {
            int reqrd = tasks[i];
            auto it = prev(st.end()); // get the strongest available worker

            // Task can be done without pill
            if (*it >= reqrd) {
                st.erase(it); // assign and remove the worker
            } 
            // No pills left and worker can't do the task
            else if (pillsUsed >= pills) {
                return false; // task can't be completed
            } 
            // Use a pill to boost a weaker worker
            else {
                // Find the weakest worker who can do the task with strength boost
                auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                if (weakestWorkerIt == st.end()) { // no suitable worker even with pill
                    return false;
                }
                st.erase(weakestWorkerIt); // assign the task
                pillsUsed++; // consume a pill
            }
        }
        return true; // all 'mid' tasks can be assigned successfully
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int m = tasks.size();
        int n = workers.size();

        int l = 0;
        int r = min(m, n); // maximum possible tasks to assign

        // Sort tasks in ascending order so we process easiest ones first
        sort(tasks.begin(), tasks.end());
        // Sort workers in descending order so strongest workers are considered first
        sort(workers.begin(), workers.end(), greater<int>());

        int result = 0;

        // Binary search to find the maximum number of tasks that can be assigned
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // If it's possible to assign 'mid' tasks
            if (check(tasks, workers, pills, strength, mid)) {
                result = mid; // update result and try for more
                l = mid + 1;
            } else {
                r = mid - 1; // try fewer tasks
            }
        }
        return result;
    }
};

string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for (auto it : arr)
            m[it]++;

        int flag = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (m[arr[i]] == 1)
                flag++;
            if (flag == k)
                return arr[i];
        }

        return "";
}

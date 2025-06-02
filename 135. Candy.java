class Solution {
    public int candy(int[] ratings) {
        int ans = 0, n = ratings.length;
        ArrayList<Integer> arr = new ArrayList<Integer>(Collections.nCopies(n, 1));
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1] && arr.get(i) <= arr.get(i - 1)) {
                arr.set(i, arr.get(i - 1) + 1);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && arr.get(i) <= arr.get(i + 1)) {
                arr.set(i, arr.get(i + 1) + 1);
            }
            ans += arr.get(i);
        }
        ans += arr.get(n - 1);
        return ans;
    }
}

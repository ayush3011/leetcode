bool lemonadeChange(vector<int>& bills) {
        int changes[3] = {0, 0, 0};
        for (int i = 0; i < bills.size(); i++) {

            if (bills[i] == 5)
                changes[0]++;

            else if (bills[i] == 10) {
                if (changes[0] > 0) {
                    changes[1]++;
                    changes[0]--;
                } else
                    return false;
            }

            else {
                if (changes[0] > 0 && changes[1] > 0) {
                    changes[0]--;
                    changes[1]--;
                } else if (changes[0] >= 3) {
                    changes[0] = changes[0] - 3;
                } else
                    return false;
            }
        }
        return true;
}

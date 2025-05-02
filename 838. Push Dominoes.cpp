class Solution {
public:
    string pushDominoes(string dominoes) {
        // queue storing char and index for simulation
        queue<pair<char, int>> q;

        // pushing "R" and "L" in the queue
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.') {
                q.push(make_pair(dominoes[i], i));
            }
        }

        while (!q.empty()) {
            pair<char, int> current = q.front();
            char c = current.first;
            int i = current.second;
            q.pop();

            // iterating on dominoes from right to left and building the logic accoringly
            if (c == 'L' && i > 0 && dominoes[i - 1] == '.') {
                q.push(make_pair('L', i - 1));
                dominoes[i - 1] = 'L';
            } else if (c == 'R' && i + 1 < dominoes.size() &&
                       dominoes[i + 1] == '.') {
                if (i + 2 < dominoes.size() && dominoes[i + 2] == 'L') {
                    q.pop();
                } else {
                    q.push(make_pair('R', i + 1));
                    dominoes[i + 1] = 'R';
                }
            }
        }

        return dominoes;
    }
};

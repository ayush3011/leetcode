class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        int n = answers.size(), result = 0;

        for (int i = 0; i < n; i++) {
            m[answers[i]]++;
        }

        for (auto it : m) {
            int answerOfRabbit = it.first;
            int howManyAnsweredSame = it.second;
            int groupSize = answerOfRabbit + 1;
            int possibleGroups = (howManyAnsweredSame + groupSize - 1) /
                                 groupSize; // ceil division
            int numberOfGroups = possibleGroups * groupSize;
            result += numberOfGroups;
        }

        return result;
    }
};

// This is the first approach using pair method and not the maps

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<pair<int, int>> scoresWithIndices;
        for (int i = 0; i < n; ++i)
        {
            scoresWithIndices.push_back({score[i], i});
        }

        sort(scoresWithIndices.begin(), scoresWithIndices.end(), greater<pair<int, int>>());

        vector<string> result(n);
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                result[scoresWithIndices[i].second] = "Gold Medal";
            }
            else if (i == 1)
            {
                result[scoresWithIndices[i].second] = "Silver Medal";
            }
            else if (i == 2)
            {
                result[scoresWithIndices[i].second] = "Bronze Medal";
            }
            else
            {
                result[scoresWithIndices[i].second] = to_string(i + 1);
            }
        }

        return result;
    }
};



// This is the second approach using hashing

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        map<int, int, greater<int>> m;
        int n = score.size();

        for (int i = 0; i < n; i++)
            m[score[i]] = i;

        vector<string> result(n);
        int rank = 1;

        for (auto it = m.begin(); it != m.end(); ++it)
        {
            int index = it->second;
            if (rank == 1)
                result[index] = "Gold Medal";
            else if (rank == 2)
                result[index] = "Silver Medal";
            else if (rank == 3)
                result[index] = "Bronze Medal";
            else
                result[index] = to_string(rank);
            ++rank;
        }
        return result;
    }
};
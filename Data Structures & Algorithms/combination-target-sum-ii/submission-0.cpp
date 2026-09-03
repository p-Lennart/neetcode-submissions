class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> candidateHistogram(51, 0);
        for (int c : candidates) candidateHistogram[c]++;

        vector<int> sortedUniques;
        for (int c = 1; c < 51; c++) {
            if (candidateHistogram[c] > 0) sortedUniques.push_back(c);
        }

        vector<vector<int>> solutions;
        vector<int> unusedCanHist = vector<int>(candidateHistogram);
        
        brancher(0, unusedCanHist, target, solutions, sortedUniques);
        
        vector<vector<int>> result(solutions.size(), vector<int>());
        for (int s = 0; s < solutions.size(); s++) {
            auto unusedHist = solutions[s];
            for (int c = 1; c < candidateHistogram.size(); c++) {
                for (int i = 0; i < (candidateHistogram[c] - unusedHist[c]); i++) {
                    result[s].push_back(c);
                }
            }
        }
        return result;
    }
private:
    void brancher(int i, vector<int>& unusedCanHist, int target,
                  vector<vector<int>> &solutions, vector<int>& sortedUniques) {
        for (; i < sortedUniques.size(); i++) {
            int can = sortedUniques[i];
            int newTarget = target - can;
            if (newTarget < 0) break; // overshot target, future nums will only be bigger
            
            if (unusedCanHist[can] == 0) continue; // candidate used up

            if (newTarget == 0) {
                unusedCanHist[can]--;
                solutions.push_back(unusedCanHist);
                unusedCanHist[can]++;
                break;
            } else {
                unusedCanHist[can]--;
                brancher(i, unusedCanHist, newTarget, solutions, sortedUniques);
                unusedCanHist[can]++;
            }
        }   
    }
};

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int numQuestions = questions.size();
        vector<long long> maxPointsAtQuestion(numQuestions + 1); // initialize dynamic programming array
        for (int i = 0; i < numQuestions; i++) { // loop through each question
            maxPointsAtQuestion[i+1] = max(maxPointsAtQuestion[i+1], maxPointsAtQuestion[i]); // update dp if skipping current question results in more points
            int maxPossibleIndex = min(numQuestions, i + 1 + questions[i][1]); // calculate maximum possible index of last question that can be answered after current question
            maxPointsAtQuestion[maxPossibleIndex] = max(maxPointsAtQuestion[maxPossibleIndex], maxPointsAtQuestion[i] + questions[i][0]); // update dp if solving current question results in more points
        }
        return maxPointsAtQuestion[numQuestions]; // return maximum points that can be earned
    }
};

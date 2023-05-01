class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int sum = 0;
        int maxSalary = INT_MIN;
        int minSalary = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            maxSalary = max(maxSalary, salary[i]);
            minSalary = min(minSalary, salary[i]);
            sum+=salary[i];
        }
        sum = sum - maxSalary - minSalary;
        double avg = (double)(sum) / (n-2);
        
        return avg;
    }
};
/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)

    Where N is the number of jobs.
*/

#include <algorithm>

struct job
{
    int startTime;
    int endTime;
    int jobProfit;
};

bool compare(job a, job b)
{
    return a.endTime < b.endTime;
}

// Function to find the latest non conflicting job.
int nonConflictingJob(vector<job> &jobs, int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (jobs[j].endTime <= jobs[i].startTime)
        {
            return j;
        }
    }

    return -1;
}

long long int maxProfitHelper(vector<job> &jobs, vector<long long int> &lookUp, int current)
{
    if (current == 0)
        return jobs[0].jobProfit;

    // If the answer already exist.
    if (lookUp[current] != -1)
    {
        return lookUp[current];
    }

    // First finding the profit by excluding the current job.
    long long int excProfit = maxProfitHelper(jobs, lookUp, current - 1);

    // Then, finding the profit by including the current job.
    long long int incProfit = jobs[current].jobProfit;

    // Finding the index of closest non conflicting job to current job.
    int index = nonConflictingJob(jobs, current);

    // If the index is not equal to -1, recursively calling for that job.
    if (index != -1)
    {
        incProfit += maxProfitHelper(jobs, lookUp, index);
    }

    // Storing the answer for further use.
    lookUp[current] = max(incProfit, excProfit);

    return lookUp[current];
}

long long int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    int n = start.size();

    // Creating jobs array of size N.
    vector<job> jobs(n);

    for (int i = 0; i < n; i++)
    {
        jobs[i].startTime = start[i];
        jobs[i].endTime = end[i];
        jobs[i].jobProfit = profit[i];
    }

    // Sorting the jobs in the increasing order of end time.
    sort(jobs.begin(), jobs.end(), compare);

    // Creating a lookUp array of size N.
    vector<long long int> lookUp(n, -1);

    long long int maxProfit = maxProfitHelper(jobs, lookUp, n - 1);

    return maxProfit;
}


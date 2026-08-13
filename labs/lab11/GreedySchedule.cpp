#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id; // 客户的编号  1 开始
    int t;  // 服务时间
    int d;  // ddl
};

bool compareJobs(const Job &a, const Job &b)
{
    return a.d < b.d;

}

int main()
{
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].t;
        jobs[i].id = i + 1;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].d;
    }

    sort(jobs.begin(), jobs.end(), compareJobs);

    long long currentTime = 0;
    int maxDelay = 0;
    vector<int> scheduleOrder;
    scheduleOrder.reserve(n);       // 预分配空间，提高效率（可选）

    for (int i = 0; i < n; ++i)
    {
        currentTime += jobs[i].t;

        int currentDelay = max(0LL, currentTime - jobs[i].d);

        maxDelay = max(maxDelay, currentDelay);

        scheduleOrder.push_back(jobs[i].id);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << scheduleOrder[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    cout << maxDelay << endl;

    return 0;
}

/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task
{
    int id;
    int t;  // 服务时间
    int d;  // 期望完成时间
};

void minDelayScheduling(int n, vector<int> &t, vector<int> &d)
{
    // 创建任务数组
    vector<Task> tasks(n);
    for (int i = 0; i < n; i++)
    {
        tasks[i].id = i + 1; // 客户编号从1开始
        tasks[i].t = t[i];
        tasks[i].d = d[i];
    }

    // 所有可能的任务排列
    vector<int> indices(n);
    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }

    int minMaxDelay = INT_MAX; // 最小的最大延迟
    vector<int> bestSchedule;  // 最佳调度顺序

    // 计算给定顺序的最大延迟
    auto calculateMaxDelay = [&](const vector<int> &order)
    {
        int currentTime = 0;
        int maxDelay = 0;
        vector<int> schedule(n);

        for (int i = 0; i < n; i++)
        {
            int idx = order[i];
            currentTime += tasks[idx].t;                    // 完成时间
            int delay = max(0, currentTime - tasks[idx].d); // 延迟时间
            maxDelay = max(maxDelay, delay);
            schedule[i] = tasks[idx].id;
        }

        if (maxDelay < minMaxDelay)
        {
            minMaxDelay = maxDelay;
            bestSchedule = schedule;
        }

        return maxDelay;
    };


    // 最早截止时间优先 (EDD - Earliest Due Date)
    vector<int> eddOrder(n);
    for (int i = 0; i < n; i++)
        eddOrder[i] = i;
    sort(eddOrder.begin(), eddOrder.end(),
         [&](int a, int b)
         { return tasks[a].d < tasks[b].d; });
    calculateMaxDelay(eddOrder);

    // 最短处理时间优先 (SPT - Shortest Processing Time)
    vector<int> sptOrder(n);
    for (int i = 0; i < n; i++)
        sptOrder[i] = i;
    sort(sptOrder.begin(), sptOrder.end(),
         [&](int a, int b)
         { return tasks[a].t < tasks[b].t; });
    calculateMaxDelay(sptOrder);

    // 最小松弛时间优先 (MST - Minimum Slack Time)
    vector<int> mstOrder(n);
    for (int i = 0; i < n; i++)
        mstOrder[i] = i;
    sort(mstOrder.begin(), mstOrder.end(),
         [&](int a, int b)
         { return (tasks[a].d - tasks[a].t) < (tasks[b].d - tasks[b].t); });
    calculateMaxDelay(mstOrder);

    //动态选择策略
    vector<bool> used(n, false);
    vector<int> dynamicOrder;
    int currentTime = 0;

    for (int step = 0; step < n; step++)
    {
        int bestTask = -1;
        int minDelay = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                int completionTime = currentTime + tasks[i].t;
                int delay = max(0, completionTime - tasks[i].d);

                if (delay < minDelay)
                {
                    minDelay = delay;
                    bestTask = i;
                }
            }
        }

        used[bestTask] = true;
        dynamicOrder.push_back(bestTask);
        currentTime += tasks[bestTask].t;
    }

    calculateMaxDelay(dynamicOrder);

    if (n <= 10)
    {
        do
        {
            calculateMaxDelay(indices);
        } while (next_permutation(indices.begin(), indices.end()));
    }

    for (int i = 0; i < n; i++)
    {
        cout << bestSchedule[i] << (i < n - 1 ? " " : "");
    }
    cout << endl;

    cout << minMaxDelay << endl;
}

int main()
{
    int n;
    cin >> n;

    // 输入服务时间和期望完成时间
    vector<int> t(n);
    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    // 调用最小延迟调度算法
    minDelayScheduling(n, t, d);

    return 0;
} */
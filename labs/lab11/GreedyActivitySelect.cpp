#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool compareFinishTime(const Activity &a, const Activity &b) {
    return a.finish < b.finish;
}

vector<int> greedyActivitySelection(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), compareFinishTime);

    int n = activities.size();
    vector<int> selectedActivities;

    if (n > 0) {
        selectedActivities.push_back(activities[0].id);
    }

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[j].finish) {
            selectedActivities.push_back(activities[i].id);
            j = i;
        }
    }

    return selectedActivities;
}

int main() {
    int n;
    cin >> n;

    vector<Activity> activities(n);

    for (int i = 0; i < n; i++) {
        cin >> activities[i].id >> activities[i].start >> activities[i].finish;
    }

    vector<int> result = greedyActivitySelection(activities);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
//贪心法实现活动选择,lab011

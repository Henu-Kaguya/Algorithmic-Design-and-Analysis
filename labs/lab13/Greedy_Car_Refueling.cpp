#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> distances(k + 1);
    for (int i = 0; i <= k; i++)
    {
        cin >> distances[i];
    }

    for (int i = 0; i <= k; i++)
    {
        if (distances[i] > n)
        {
            cout << "No Solution" << endl;
            return 0;
        }
    }

    vector<int> refill_stations;
    int remaining_fuel = n;

    // 尽可能往前走，只在必要时加油
    for (int i = 0; i < k; i++)
    {
        remaining_fuel -= distances[i];

        // 如果剩余油量不足以到达下一个加油站，就在当前加油站加油
        if (remaining_fuel < distances[i + 1])
        {
            refill_stations.push_back(i + 1);
            remaining_fuel = n;
        }
    }

    cout << refill_stations.size() << endl;
    for (size_t i = 0; i < refill_stations.size(); i++)
        cout << refill_stations[i] << " ";
    cout << endl;

    return 0;
}

/* #include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;  // n为加满油后可行驶的距离，k为加油站数量

    vector<int> distances(k + 1);  // 存储相邻加油站之间的距离
    for (int i = 0; i <= k; i++) {
        cin >> distances[i];
    }

    // 检查是否有一段距离大于n，如果有则无法到达目的地
    for (int i = 0; i <= k; i++) {
        if (distances[i] > n) {
            cout << "No Solution" << endl;
            return 0;
        }
    }

    vector<int> refill_stations;  // 存储加油的站点
    int remaining_fuel = n;       // 剩余油量，初始为满油

    // 贪心算法：尽可能往前走，只在必要时加油
    for (int i = 0; i < k; i++) {
        // 减去当前路段的距离
        remaining_fuel -= distances[i];

        // 如果剩余油量不足以到达下一个加油站，就在当前加油站加油
        if (remaining_fuel < distances[i + 1]) {
            refill_stations.push_back(i + 1);  // 加油站编号从1开始
            remaining_fuel = n;  // 加满油
        }
    }

    // 输出结果
    cout << refill_stations.size() << endl;
    for (int station : refill_stations) {
        cout << station << " ";
    }
    cout << endl;

    return 0;
} */
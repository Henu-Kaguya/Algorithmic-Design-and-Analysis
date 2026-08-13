#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N_containers;
int Capacity1, Capacity2;
vector<int> ItemWeights;
vector<int> Sol_Ship1_Items, Sol_Ship2_Items;
bool found_solution_flag = false;

void find_loading_solution(int item_k_idx, int current_s1_weight, vector<int> &current_s1_item_indices_0based)
{
    if (found_solution_flag)
    {
        return;
    }

    if (item_k_idx == N_containers)
    {
        int current_s2_weight = 0;
        vector<int> current_s2_item_indices_1based;
        vector<bool> is_on_ship1(N_containers, false);

        for (int idx_0based : current_s1_item_indices_0based)
        {
            is_on_ship1[idx_0based] = true;
        }

        for (int i = 0; i < N_containers; ++i)
        {
            if (!is_on_ship1[i])
            {
                current_s2_item_indices_1based.push_back(i + 1);
                current_s2_weight += ItemWeights[i];
            }
        }

        if (current_s1_weight <= Capacity1 && current_s2_weight <= Capacity2)
        {
            Sol_Ship1_Items.clear();
            for (int idx_0based : current_s1_item_indices_0based)
            {
                Sol_Ship1_Items.push_back(idx_0based + 1);
            }
            Sol_Ship2_Items = current_s2_item_indices_1based;
            found_solution_flag = true;
        }
        return;
    }

    if (current_s1_weight + ItemWeights[item_k_idx] <= Capacity1)
    {
        current_s1_item_indices_0based.push_back(item_k_idx);
        find_loading_solution(item_k_idx + 1, current_s1_weight + ItemWeights[item_k_idx], current_s1_item_indices_0based);
        current_s1_item_indices_0based.pop_back();
        if (found_solution_flag)
        {
            return;
        }
    }

    find_loading_solution(item_k_idx + 1, current_s1_weight, current_s1_item_indices_0based);
}

int main()
{
    cin >> N_containers >> Capacity1 >> Capacity2;
    ItemWeights.resize(N_containers);
    for (int i = 0; i < N_containers; ++i)
    {
        cin >> ItemWeights[i];
    }

    vector<int> path_for_s1_0based;
    find_loading_solution(0, 0, path_for_s1_0based);

    if (found_solution_flag)
    {
        for (size_t i = 0; i < Sol_Ship1_Items.size(); ++i)
        {
            cout << Sol_Ship1_Items[i] << (i == Sol_Ship1_Items.size() - 1 ? "" : " ");
        }
        cout << endl;
        for (size_t i = 0; i < Sol_Ship2_Items.size(); ++i)
        {
            cout << Sol_Ship2_Items[i] << (i == Sol_Ship2_Items.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    else
    {
        cout << "No Solution" << endl;
    }

    return 0;
}
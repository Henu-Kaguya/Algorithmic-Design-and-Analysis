
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /*---------- 变量声明与输入处理 ----------*/
    int itemCount;        // 物品种类数量n
    int backpackCapacity; // 背包容量C
    cout<<"输入背包物品种类数量:";
    cin >> itemCount;
    cout << "输入背包容量:";
    cin >> backpackCapacity;

    vector<int> itemWeights(itemCount); // 物品重量数组w（索引0对应物品1）
    vector<int> itemValues(itemCount);  // 物品价值数组v（索引0对应物品1）

    // 读取物品重量数据
    cout << "输入物品重量:";
    for (int i = 0; i < itemCount; ++i)
    {
        cin >> itemWeights[i];
    }
    // 读取物品价值数据
    cout << "输入物品价值:";
    for (int i = 0; i < itemCount; ++i)
    {
        cin >> itemValues[i];
    }

    /*---------- 动态规划表初始化 ----------*/
    // maxValueTable[k][y]: 前k个物品在容量y时的最大价值
    vector<vector<int>> maxValueTable(itemCount + 1, vector<int>(backpackCapacity + 1, 0));

    // 初始化边界条件（伪代码第1-2行）
    for (int currentItem = 0; currentItem <= itemCount; ++currentItem)
    {
        maxValueTable[currentItem][0] = 0; // 容量为0时价值为0
    }
    for (int currentCapacity = 0; currentCapacity <= backpackCapacity; ++currentCapacity)
    {
        maxValueTable[0][currentCapacity] = 0; // 物品数为0时价值为0
    }

    /*---------- 动态规划填表过程 ----------*/
    // 遍历所有物品（伪代码第3-7行）
    for (int currentItem = 1; currentItem <= itemCount; ++currentItem)
    {
        // 遍历所有背包容量
        for (int currentCapacity = 1; currentCapacity <= backpackCapacity; ++currentCapacity)
        {
            // 当前物品重量超过剩余容量
            if (currentCapacity < itemWeights[currentItem - 1])
            {
                // 继承前k-1个物品的最优解
                maxValueTable[currentItem][currentCapacity] = maxValueTable[currentItem - 1][currentCapacity];
            }
            else
            {
                // 计算不选/选当前物品的两种情况
                int valueWithoutItem = maxValueTable[currentItem - 1][currentCapacity];
                int valueWithItem = maxValueTable[currentItem - 1][currentCapacity - itemWeights[currentItem - 1]] + itemValues[currentItem - 1];
                // 取最大值更新状态表
                maxValueTable[currentItem][currentCapacity] = max(valueWithoutItem, valueWithItem);
            }
        }
    }

    /*---------- 回溯选择物品 ----------*/
    vector<int> selectedItems;                // 存储被选中的物品编号（1-based）
    int remainingCapacity = backpackCapacity; // 剩余背包容量

    // 逆向遍历所有物品（伪代码第9-14行）
    for (int currentItem = itemCount; currentItem >= 1; --currentItem)
    {
        // 检查当前物品是否被选中
        if (maxValueTable[currentItem][remainingCapacity] > maxValueTable[currentItem - 1][remainingCapacity])
        {
            selectedItems.push_back(currentItem);              // 记录选中物品
            remainingCapacity -= itemWeights[currentItem - 1]; // 更新剩余容量
        }
    }

    /*---------- 输出结果 ----------*/
    // 输出最大总价值（伪代码第8行）
    cout << maxValueTable[itemCount][backpackCapacity] << endl;

    // 按升序排列选中物品编号
    sort(selectedItems.begin(), selectedItems.end());
    // 格式化输出选中物品（x1 x2 x5格式）
    for (size_t i = 0; i < selectedItems.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << "x" << selectedItems[i];
    }
    cout << endl;

    return 0;
}
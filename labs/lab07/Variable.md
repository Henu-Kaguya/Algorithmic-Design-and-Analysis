------

### 变量说明表

| 变量名称            | 类型/结构             | 说明                                                         |
| ------------------- | --------------------- | ------------------------------------------------------------ |
| `itemCount`         | `int`                 | 物品种类数量（对应输入n）                                    |
| `backpackCapacity`  | `int`                 | 背包最大容量（对应输入C）                                    |
| `itemWeights`       | `vector<int>`         | 物品重量数组，索引0对应物品1（对应输入w数组）                |
| `itemValues`        | `vector<int>`         | 物品价值数组，索引0对应物品1（对应输入v数组）                |
| `maxValueTable`     | `vector<vector<int>>` | 动态规划表，maxValueTable[k][y]表示前k个物品在容量y时的最大价值 |
| `currentItem`       | `int`                 | 循环变量，表示当前处理的物品编号（1-based）                  |
| `currentCapacity`   | `int`                 | 循环变量，表示当前背包容量                                   |
| `remainingCapacity` | `int`                 | 回溯过程中剩余的背包容量                                     |
| `selectedItems`     | `vector<int>`         | 存储被选中的物品编号（1-based，例如x1对应索引0的物品）       |
| `valueWithoutItem`  | `int`                 | 临时变量，表示不选当前物品时的最大价值                       |
| `valueWithItem`     | `int`                 | 临时变量，表示选择当前物品时的总价值                         |

------

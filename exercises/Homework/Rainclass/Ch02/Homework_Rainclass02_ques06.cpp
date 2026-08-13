// 利用分治法求两个等长有序数组 A 和 B 的中位数
findMedian(数组 A,A数组左端的索引 leftA, A数组右端 rightA, 数组 B, B数组左端 leftB, B数组右端 rightB):
    // 终止条件：当两个数组各剩下一个元素
    if leftA == rightA and leftB == rightB:
        return (A[leftA] + B[leftB]) / 2.0

    // 计算 k（中间索引，向下取整）
    k = (rightA - leftA + 1) / 2
    midA = A[leftA + k]
    midB = B[leftB + k]

    // 如果 A[k] == B[k]，则 A[k] 就是中位数
    if midA == midB:
        return midA
    // 如果 A[k] < B[k]，舍弃 A 的前 k 部分和 B 的后 k 部分
    else if midA < midB:
        return findMedian(A, leftA + k, rightA, B, leftB, leftB + k)
    else:
        return findMedian(A, leftA, leftA + k, B, leftB + k, rightB)

// 计算两个等长数组 A 和 B 的中位数
findMedianSortedArrays(数组 A, 数组 B, 整数 n):
    return findMedian(A, 0, n-1, B, 0, n-1)
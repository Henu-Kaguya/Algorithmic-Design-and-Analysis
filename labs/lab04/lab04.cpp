#include <iostream>
using namespace std;

void Quicksort(int* arr,int begin,int end);
int Partition(int *arr, int begin, int end);
void swap(int *arr, int i, int j);

int main()
{
    int n;
    //cout<<"输入元素个数n: ";
    cin >> n;
    int arr[n];
    //cout<<"请输入"<<n<<"个元素: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}

void Quicksort(int* arr,int begin,int end){
    if(begin < end){
        int temp = Partition(arr,begin,end);
        swap(arr, begin, temp); //在这里交换或者Partition函数里交换都行,但是只能交换一个
        Quicksort(arr,begin,temp - 1);
        Quicksort(arr,temp + 1,end);//temp已经排好位置了,所以不用再对temp进行Quicksort了
    }
}

int Partition(int* arr,int begin,int end){
    int temp = arr[begin];
    int i = begin;
    int j = end;
    while(i < j){
        while (i <= end && arr[i] <= temp) // 如果去掉等号会死循环,测试数据10个:100 20 3000 40 500 6000 70000 8 90 100,注意最后一个数需与第一个数相等,或者在能查到的另一个数的前面
            i++;
        while (j >= begin && arr[j] > temp)
            j--;
        if(i < j){
            swap(arr,i,j);
        }
        else{
            return j;
        }
    }
    //swap(arr,begin,j);//在这里交换或者main函数里交换都行,但是只能交换一个
    return j;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
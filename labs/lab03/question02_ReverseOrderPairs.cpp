#include <iostream>

using namespace std;

void Merge(int *a, int left, int mid, int right);
void MergeSort(int *a, int left, int right);
int MergeSort_Count(int *a, int left, int right);
int Merge_Count(int *a, int left,int mid, int right);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = MergeSort_Count(arr,0,n - 1);
/*     for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } */
    cout<<sum<<endl;
}

int MergeSort_Count(int *a, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        return MergeSort_Count(a,left,mid) + MergeSort_Count(a,mid + 1,right) + Merge_Count(a,left,mid,right);
    }
    else
        return 0;
}

int Merge_Count(int *a, int left, int mid, int right){
    int sum_temp = 0;

    int x_len = mid - left + 1;
    int y_len = right - (mid + 1) + 1;
    int x[x_len];
    int y[y_len];

    for (int i = 0; i < x_len; i++)
    {
        x[i] = a[left + i];
    }
    for (int i = 0; i < y_len; i++)
    {
        y[i] = a[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < x_len && j < y_len)
    {
        if (x[i] <= y[j]) // 改这里的符号为>=即可实现逆序
            a[k++] = x[i++];
        else
        {
            a[k++] = y[j++];
            sum_temp += x_len - i;//后面的都要统计
        }
    }

    while (i < x_len)
    {
        a[k++] = x[i++];
    }
    while (j < y_len)
    {
        a[k++] = y[j++];
    }
    return sum_temp;
}

void MergeSort(int *a, int left, int right){
    if(left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(a,left,mid);
        MergeSort(a, mid + 1, right);
        Merge(a,left,mid,right);
    }
}

void Merge(int* a,int left,int mid,int right){
    int x_len = mid - left + 1;
    int y_len = right - (mid + 1) + 1;
    int x[x_len];
    int y[y_len];

    for(int i = 0;i < x_len;i++){
        x[i] = a[left + i];
    }
    for(int i = 0;i < y_len;i++){
        y[i] = a[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < x_len && j < y_len){
        if(x[i] <= y[j])//改这里的符号为>=即可实现逆序
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }

    while(i < x_len){
        a[k++] = x[i++];
    }
    while(j < y_len){
        a[k++] = y[j++];
    }
}

/*test MergeSort
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
} */
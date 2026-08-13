#include <iostream>
#include <vector>

using namespace std;

int n_temp;

int question_majority(const vector<int>& arr, int l,int r){
    if(l == r){
        return arr[l] * n_temp + 1;
    }

    int mid = (l + r) / 2;
    int pre = question_majority(arr,l,mid);
    int pos = question_majority(arr,mid+1,r);

    int pre_num = pre / n_temp;
    int pre_count = pre % n_temp;
    int pos_num = pos / n_temp;
    int pos_count = pos % n_temp;

    if(pre_num == pos_num)
    {
        return pre_num * n_temp + (pre_count + pos_count);
    }
    else
    {
        int pre_sum = 0;
        int pos_sum = 0;
        for(int i = l; i <= r; i++){
            if(arr[i] == pre_num){
                pre_sum++;
            }
            if(arr[i] == pos_num){
                pos_sum++;
            }
        }
        return (pre_sum >= pos_sum) ? (pre_num * n_temp + pre_sum) : (pos_num * n_temp + pos_sum);
    }
}

int main(){
    int n;
    cin>>n;
    n_temp = n + 1;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    int num = question_majority(arr,0,n - 1);
    int majority_num = num / n_temp;
    int majority_count = num % n_temp;

    cout<<majority_num<<endl;
    cout<<majority_count<<endl;

    return 0;
}

// https://blog.csdn.net/Tulip_Alice/article/details/135377225 C++处理多返回值的4种方法
//下次可以尝试使用pair返回两个值
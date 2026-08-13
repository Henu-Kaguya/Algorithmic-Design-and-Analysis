#include <iostream>

using namespace std;

void Merge(int* a,int p,int q,int r);
void MergeSort(int*a,int p,int r);

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    MergeSort(a,0,n - 1);
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";
    }
}

void MergeSort(int*a,int p,int r){
    if(p < r){
        int q = (p + r) / 2;
        MergeSort(a,p,q);
        MergeSort(a,q + 1,r);
        Merge(a,p,q,r);
    }
}

void Merge(int* a,int p,int q,int r){
    int x = q-p+1;
    int y = r-q;
    int b[x];
    int c[y];

    for(int i = 0;i < x;i++){
        b[i] = a[p + i];
    }
    for(int i = 0;i < y;i++){
        c[i] = a[q + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i < x && j < y){
        if(b[i] <= c[j]){
            a[k] = b[i];
            i++;
        }
        else{
            a[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < x) {
        a[k++] = b[i++];
    }
    while (j < y) {
        a[k++] = c[j++];
    }
/*
    if(i >= x){
        for(int t = 0;t < y - j + 1;t++){
            a[k] = c[j];
            k++;
            j++;
        }
    }
    else
    {
        for(int t = 0;t < x - i;t++){
            a[k] = b[i];
            k++;
            i++;
        }
    }*/
}

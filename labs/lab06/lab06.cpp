#include <iostream>
using namespace std;

#define MAXMatrix 100
#define INT_MAX 0x7fffffff

int times[MAXMatrix][MAXMatrix] = {0};
int divide[MAXMatrix][MAXMatrix] = {0};

void MatrixChain(int* mat,int n){
    for(int len = 2;len <= n;len++){
        for(int begin_pos = 1;begin_pos <= n - len + 1;begin_pos++){
            int end_pos = begin_pos + len - 1;
            times[begin_pos][end_pos] = INT_MAX;

            for(int div_pos = begin_pos;div_pos < end_pos;div_pos++){
                int newtimes = times[begin_pos][div_pos] + times[div_pos + 1][end_pos] + mat[begin_pos - 1] * mat[div_pos] * mat[end_pos];
                if(newtimes < times[begin_pos][end_pos]){
                    times[begin_pos][end_pos] = newtimes;
                    divide[begin_pos][end_pos] = div_pos;
                }
            }
        }
    }
}

void PrintMatrix(int beg, int end, bool isTopLevel)
{
    if (beg == end)
        cout << "A" << beg;
    else{
        int div = divide[beg][end];
        if (isTopLevel){
            PrintMatrix(beg, div, false);
            PrintMatrix(div + 1, end, false);
        }
        else{
            cout << "(";
            PrintMatrix(beg, div, false);
            PrintMatrix(div + 1, end, false);
            cout << ")";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int mat[n + 1];
    for (int i = 0; i < n + 1; i++)
        cin >> mat[i];
    MatrixChain(mat, n);
    cout << times[1][n] << endl;
    PrintMatrix(1, n, true);
    cout << endl;
    return 0;
}

/* int main(){
    int n;
    cin>>n;
    int* arr = new int[n + 1];
    for(int i = 0;i < n + 1;i++){
        cin>>arr[i];
    }
    if(n == 3)
        cout<<4680<<endl <<"(A1A2)A3"<<endl;
    else if(n == 4)
        cout << 7560<<endl <<"((A1A2)A3)A4"<<endl;
    else if(n == 5)
        cout << 11875<< endl << "(A1(A2A3))(A4A5)"<<endl;
    else if (n == 6)
        cout << 83532 << endl<< "((A1A2)((A3A4)A5))A6" << endl;
    else if (n == 7)
        cout << 23748 << endl<< "(A1A2)(((A3A4)(A5A6))A7)" << endl;
    delete[] arr;
    return 0;
}

 */
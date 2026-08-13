#include <iostream>
#include <vector>
using namespace std;

int main()
{

    /*int y = -1;
    for(y;y<=33;y++){
        for(int z=-1;z<100;z++){
            if(3*y + 7*z == 600 && y+z<=100){
                cout<<100-y-z<<" "<<y<<" "<<z<<endl;
            }
        }
    }*/
    /*
    int x = 0;
    for(x;x<=20;x++){
        for(int y =0;y<=33;y++){
            if(7*x+4*y == 100){
                cout<<x<<" "<<y<<" "<<100-x-y<<endl;
            }
        }
    }*/
    int y = 0;

    int rows = 1;
    int columns = 3;
    int ** a = new int* [rows];
    for(int i = 0;i < rows;i++){
        a[i] = new int [columns];
    }
    int temp = 0;


    for(y;y<=33;y++){
        for(int z=0;z<100;z++){
            if(3*y + 7*z == 600 && y+z<=100){
                //cout<<100-y-z<<" "<<y<<" "<<z<<endl;
                rows++;
                a[temp][0] = 100-y-z;
                a[temp][1] = y;
                a[temp][2] = z;
                temp++;
            }
        }
    }

    for(int i = 0;i < rows;i++){
        cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
    }



    for(int i = 0;i < rows;i++){
        delete[]a[i];
    }
    delete []a;

    return 0;
}

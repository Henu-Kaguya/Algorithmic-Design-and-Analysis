#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    /*int y = 0;
    for(y;y<=33;y++){
        for(int z=0;z<100;z++){
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
    vector<vector<int>>a;

    for(y;y<=33;y++){
        for(int z=0;z<100;z++){
            if(3*y + 7*z == 600 && y+z<=100){
                //cout<<100-y-z<<" "<<y<<" "<<z<<endl;
                a.push_back({100-y-z,y,z});
            }
        }
    }

    sort( a.begin(),a.end(),[](const vector<int>& m,const vector<int>& n) {return m[0]<n[0];} );

    for(const auto&row : a){
        cout<< row[0]<<" "<<row[1]<<" "<<row[2]<<endl;
    }

    return 0;
}

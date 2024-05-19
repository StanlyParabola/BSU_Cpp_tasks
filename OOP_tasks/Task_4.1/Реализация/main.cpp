#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    const int INF_NUM = 1e4;
    const int INF_LENGTH = 1e9;
    int n;
    int tmp;
    bool flag = true;

    Vector vec(INF_NUM);
    for(int i = 1; i <= INF_NUM; i++){
        vec[i-1] = i;
    }

    while(flag) {
        cout << "input the length of initial sequence (<= 10^9):\n";
        cin >> n;
        flag = false;
        if(n > INF_LENGTH){
            flag = true;
            cout<< "inputed number exceeded limitations, please, try again\n";
        }
    }


    flag = true;
    while(flag){
        flag = false;
        cout << "fill sequence (each element <= 10^4):\n";
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if(tmp <= INF_NUM)
                vec[tmp - 1] = 0;
            else{
                cout<<"invalid element detected. Please, try again.\n";
                flag = true;
                break;
            }
        }
    }
    cout<<"all positive integers <= 10^4 that weren't present in inputed seqence:\n";
    for(int i = 0; i < INF_NUM; i++){
        if(vec[i]!=0)
            cout<<vec[i]<<" ";
    }

    return 0;
}

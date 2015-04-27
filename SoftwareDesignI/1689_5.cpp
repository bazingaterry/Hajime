#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int n,num[10010];
    memset(num,0,sizeof(num));
    cin >> n;
    //cout << num[8] << endl;
    while(n--){
        int a,b;
        cin >> a >> b;
        for(int i = a;i < b;++i){
            num[i] = 1;
        }
        //cout << num[8] << endl;
    }
    int flag = 0;
    for(int i = 1;i <= 10001;++i){
        if(!flag && num[i]) {cout << i <<" "; flag = 1;}
        if(flag && !num[i]) {cout << i  << endl; flag = 0;}
    }
    return 0;
}
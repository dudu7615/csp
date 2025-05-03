#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;

int nums[maxn];

int getNum(int n,int intNum=1){
    if(n == 1){
        nums[0] = -1;
        return -1;
    }
    if(n == 0){
        nums[0] = 0;
        return 0;
    }
    for(int k=1;k<=maxn;k++){
        if(n<pow(2,k)){
            // cout << pow(2, k-1);
            nums[intNum] = pow(2, k-1);
            getNum(n-pow(2,k-1),intNum+1);
            return 0;
        }
    }
    return -1;
}


int main(){
    int n;
    cin >> n; 
    getNum(n);
    if(nums[0] == -1){
        cout << "-1";
        return 0;
    }
    for(int i = 1;i<maxn;i++){
        if(nums[i] == 0){
            break;
        }
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
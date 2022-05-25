#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n){
    int currSq = 0, i=1;

    do {
        currSq = i*i;
        i++;
    }while(currSq<n);

    if(currSq == n){
        return i-1;
    }else{
        return i-2;
    }
}

int main(){
    int n = 16;
    cout<<squareRoot(n);
    return 0;
}
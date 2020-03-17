#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,ct;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            ct = 0;
            while(n%i==0)
            {
                n=n/i;
                ct++;
            }
            cout<<i<<"^"<<ct<<endl;
        }
    }
    if(n!=1)
        cout<<n<<"^"<<1;
}
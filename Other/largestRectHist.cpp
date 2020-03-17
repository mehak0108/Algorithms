#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int task(vector<int> &v){
    stack<int>s;
    int max=0;
    int area,i=0;
    while(i<v.size()){
        if(s.empty() || v[s.top()]<=v[i])
            s.push(i++);
        else{
            int tp = s.top(); s.pop();
            if(s.empty())
                area = v[tp]*i;
            else
                area = v[tp]*(i-s.top()-1);
            if(max<area)
                max = area;
        }
    }

    while(!s.empty()){
        int tp = s.top(); s.pop();
        if(s.empty())
            area = v[tp]*i;
        else
            area = v[tp]*(i-s.top()-1);
        if(max<area)
            max = area;
    }
    return max;
}

int main(){
    vector<int> v{6,2,5,4,5,1,6};
    cout<<task(v);
}
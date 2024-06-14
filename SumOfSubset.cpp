#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int capacity = 31;
vector<int>arr  { 15 , 16 , 13 , 31 , 30 , 1};
int n = arr.size();
vector<int>x(n,0);
void sumSubset(int i , int ans){
       if( ans == capacity ){
              //cout<<ans;
       for (int k = 0; k < n; ++k)
             {
                    cout<<x[k]<<" ";
             } 
             cout<<endl; 
             return;    
       }
        if(ans > capacity) return;
       if(i >= n) return ;

       x[i] = 1;
       //cout<<arr[i]<<endl;
       sumSubset(i+1 , ans + arr[i]);
       if(ans + arr[i+1] <= capacity){
       x[i] = 0;
       sumSubset(i+1 , ans);
}
}

int main(){
 sumSubset(0,0);
}

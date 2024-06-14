#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>p={1,2,5,6};
vector<int>w={2,2,4,5};
int capacity = 6;
int n = 4;
int dp[50][50];
int knapsack(int i,int weight){
  if(weight >= capacity){
    return 0;
  }
  if(i >= n){
    return 0;
  }
  if(dp[i][weight] != -1) return dp[i][weight];
  int profit;
  profit = knapsack(i+1,weight);
  if(weight+w[i] <= capacity)
  profit = max(profit ,knapsack(i+1,weight+w[i])+p[i]);
    return dp[i][weight] = profit;
}

int main(){
  memset(dp,-1,sizeof(dp));
     cout<<"Total profit earned: "<<knapsack(0,0);
}

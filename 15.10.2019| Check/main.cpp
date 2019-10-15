#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <fstream>
using namespace std;
int x,y,ts[100],tender[100],t=0,n,a[100][100];

ifstream in("input.txt");
ofstream out("output.txt");

void dfs(int x){
  ts[x]=++t;
  for(int i=0;i<n;i++){
    if(a[x][i]==1&&ts[i]==0)
    dfs(i);
  }
  tender[x]=++t;
}

void check_nomber(){
    cin>>x>>y;
    if(ts[x]<ts[y]&&tender[x]>tender[y]){
      cout<< "true";
    }else{
      cout<< "false";
    }
}

int main(){
  in>>n;
  for(int i=0;i<n;i++){
    ts[i]=0;tender[i]=0;
    for(int j=0;j<n;j++)
    in>>a[i][j];
  }
  dfs(0);
  while(true){
    check_nomber();
  }
return 0;
}

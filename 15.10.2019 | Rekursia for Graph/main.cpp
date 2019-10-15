#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");

int a[100][100];
int tbegin[100],tend[100];
int t=0;
int n;

void dfs(int now_v){
    tbegin[now_v]=++t;
    for(int i=0;i<n;i++){
        if(tbegin[i]!=0&&a[now_v][i]==1){
            cout<<"I find cycle Bro!"<<endl;
        }
        if(a[now_v][i]==1&&tbegin[i]==0){
            dfs(i);
        }
    }
    tend[now_v]=++t;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(tbegin[i]==0){
            dfs(i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<tbegin[i]<<" "<<tend[i]<<endl;
    }
    return 0;
}

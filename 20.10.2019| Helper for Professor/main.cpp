#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <vector>

using namespace std;

int all;
string words[1000];
int arr[1000][1000],tbegin[1000],tend[1000],t=0;
vector <int> answer;
ifstream in("input.txt");
ofstream out("professor.out");

void dfo(int x){
    tbegin[x]=++t;

    for(int i=0;i<all;i++){
        if(arr[x][i]==1&&tbegin[x]==0){
            dfo(x);
        }
    }

    tend[x]=++t;
    answer.push_back(x);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    in>>all;
    for(int i=0;i<all;i++){
        tbegin[i]=0;tend[i]=0;
        in>>words[i];
    }
    for(int i=0;i<all;i++){
        for(int j=0;j<all;j++){
            in>>arr[i][j];
        }
    }
    for(int i=0;i<all;i++){
        if(tbegin[i]==0){
            dfo(i);
        }
    }
    for(int i=0;i<all;i++){
        out<<i<<" шаг, надень "<<words[answer[i]]<<endl;

    }
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int n,len;
int used[100];
string words[100];
string f[100];

void check(){
    string answer="";
    for(int p=0;p<len;p++){
        answer=answer+" "+f[p];
        if(p>=2)cout<<answer<<endl;
    }
}

void R(int x){
    int i;
    if(len==x){check();return;}

    for(i=0;i<n;i++){
        if(used[i]==0){
            f[x]=words[i];
            used[i]=1;
            R(x+1);
            used[i]=0;
            f[x]="";
        }
    }
}

int main()
{
    cin>>n>>len;
    for(int u=0;u<n;u++){
        cin>>words[u];
    }
    R(0);
    return 0;
}

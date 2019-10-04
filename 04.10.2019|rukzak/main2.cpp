#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int N;
long long W;
int w[900000],p[900000];
int ma=-1;int km=-1;
int used[900000];
int ans[90000];
string answer="";
string oo;

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}
void dd( string dd){
    oo=dd;
}

void r(int we, int zn,int k, string answer ){
    if(we==W&&(zn>ma||(zn==ma&&km>k))){dd(answer);ma=zn;km=k;return;}
    
    for(int i=0;i<N;i++){
        if(we+w[i]<=W&&used[i]==0){
            used[i]=1;
            ans[zn]=i+1;
            string str = toString(ans[zn]);
            answer=answer+" "+str;
            r(we+w[i],zn+p[i],k+1,answer);
            answer="";
            ans[zn]=0;
            used[i]=0;
        }
    }
}

int main()
{
    cin>>N>>W;
    for(int i=0;i<N;i++){
        cin>>w[i]>>p[i];
    }
    r(0,0,0,"");
    cout<<km<<" "<<ma<<endl;
    oo=oo.substr(1);
    cout<<oo;
    return 0;
}

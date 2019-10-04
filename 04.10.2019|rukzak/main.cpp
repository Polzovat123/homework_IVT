#include <iostream>
#include <vector>
using namespace std;
long long pol=0,col=21;
vector<int>ans(21,0);
vector<int>p(21,0);
vector<int>po(21);
vector<int>w(21);
int n,s;
void r(int i,int wes,long long polez,int tpcol)
{
    if(wes>s) return;
    if(polez>pol || (polez==pol && tpcol<col))
    {
        pol=polez;
        col=tpcol;
        ans=p;
 
    }
    if(i>n)
    {
        return;
    }
    p[i]=1;
    r(i+1,wes+w[i],polez+po[i],tpcol+1);
    p[i]=0;
    r(i+1,wes,polez,tpcol);
}
 
int main()
{
 
 
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        cin>>po[i];
    }
    r(1,0,0,0);
    cout<<col<<' '<<pol<<endl;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}

#include <iostream>
#include <functional>
#include <string>



using namespace std;

string code[101];

int var[1000];

string text;

char l;

unsigned long long pw[1000],hash_input[1000],hash_codir[1000];

int n=0,maxs=-1;

void create_hash_input(string word){
    pw[0]=1;hash_input[0]=word[0];
    for(int i=1;i<word.length();i++){
        pw[i]=pw[i-1]*257;
        hash_input[i]=hash_input[i-1]+pw[i]*word[i];
    }
}

void create_one_element_hash_codir(int now){
    hash_codir[now]=code[now][0];
    for(int i=1;i<code[now].length();i++){
        hash_codir[now]=hash_codir[now]+code[now][i]*pw[i];
    }
}

void  start(){
    cout<<"Write Number:";
    cin>>n;
    for(int i=0; i < n; i++){
        cout<<"Write pair: ";
        cin>>l>>code[i];
        if(code[i].length()>maxs){
            maxs=code[i].length();
        }
    }
    cout<<"CODE ::: ";
    cin>>text;
    create_hash_input(text);
    for(int i=0;i<n;i++){
        create_one_element_hash_codir(i);
    }
}


bool gvs(string ishod,int now_simbol, int now_code){
    if(hash_input[now_simbol+ishod.length()-1]-hash_input[now_simbol-1]==hash_codir[now_code]*pw[now_simbol]){return true;}else{return false;}
}

void start_chek(int now, int first_var){
    for(int i=0;i<n;i++){
        if(gvs(code[i],now, i)){
            var[now+code[i].length()]+=first_var;
        }
    }
}

void medium(){

    var[0]=1;
    for(int i=0;i<=text.length();i++){
        start_chek(i,var[i]);
    }
    cout<<var[text.length()]<<endl<<text.length()<<endl;
}

void ends(){
    cout<<"Thank very much!!!"<<endl;
}
int main(){

    start();
    medium();
    ends();
    return 0;
}

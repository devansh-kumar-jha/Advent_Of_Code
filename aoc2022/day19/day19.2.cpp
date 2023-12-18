#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define time 24

void dkj() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i) {
    if(i>=s.length()) return 0;
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

int calculator(int a,int b,pair<int,int> c,pair<int,int> d)
{
    
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;  int ctr=1,ans=0;
    fstream fin("day19.txt", fstream::in);
    while(getline(fin, s)) {
        int a=0,b=0,i=34;
        pair<int,int> c={0,0},d={0,0};
        a=read_num(s,i); i+=28;
        b=read_num(s,i); i+=32;
        c.first=read_num(s,i); i+=9;
        c.second=read_num(s,i); i+=30;
        d.first=read_num(s,i); i+=9;
        d.second=read_num(s,i);
        int num=calculator(a,b,c,d);
        ans+=(ctr*num); ctr++;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

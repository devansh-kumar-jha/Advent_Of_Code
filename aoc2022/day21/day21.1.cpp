#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define width 7

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

int vals_calc(vector<vector<int>>& adj,vector<int>& vals,vector<int>& inst,int i)
{
    if(vals[i]==-1) {
        int fir=adj[i][0],sec=adj[i][1];
        int num1=vals_calc(adj,vals,inst,fir);
        int num2=vals_calc(adj,vals,inst,sec);
        if(inst[i]==-1) vals[i]=0;
        else if(inst[i]==0) vals[i]=num1+num2;
        else if(inst[i]==1) vals[i]=num1-num2;
        else if(inst[i]==2) vals[i]=num1*num2;
        else vals[i]=num1/num2;
    }
    return vals[i];
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s; fstream fin1("day21.txt", fstream::in);
    map<string,int> mp; int cnt=0,ans=0;
    while(getline(fin1, s)) {
        string name=s.substr(0,4);
        mp[name]=cnt; cnt++;
    }
    vector<vector<int>> adj(cnt);
    vector<int> vals(cnt,-1),inst(cnt,-1);
    fin1.close(); fstream fin2("day21.txt", fstream::in);
    while(getline(fin2, s)) {
        string name=s.substr(0,4);
        int x=mp[name],i=6;
        if(s[i]>='0' && s[i]<='9') { int y=read_num(s,i); vals[x]=y; }
        else {
            string first=s.substr(6,4),second=s.substr(13,4);
            if(s[11]=='+') inst[x]=0; else if(s[11]=='-') inst[x]=1;
            else if(s[11]=='*') inst[x]=2; else inst[x]=3;
            int y=mp[first],z=mp[second];
            adj[x].push_back(y); adj[x].push_back(z);
        }
    }
    vals_calc(adj,vals,inst,mp["root"]);
    ans=vals[mp["root"]];
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

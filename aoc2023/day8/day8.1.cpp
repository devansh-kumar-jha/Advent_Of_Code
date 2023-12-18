#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i)
{
    int num=0;
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    return num;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s,ins,cur="AAA"; map<string,vector<string>> graph;
    fstream fin("day8.txt", fstream::in);
    getline(fin, ins); getline(fin, s);
    int n=ins.length();
    while(getline(fin, s)) {
        string a=s.substr(0,3);
        string r=s.substr(12,3);
        string l=s.substr(7,3);
        graph[a]={l,r};
    }
    while(cur!="ZZZ") {
        if(ins[ans%n]=='L') cur=graph[cur][0];
        else cur=graph[cur][1];
        ans++;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

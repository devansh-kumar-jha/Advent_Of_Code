#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i)
{
    if(i>=s.length()) return 0;
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

void simulate(map<pair<int,int>,char>& cave,pair<int,int> s,pair<int,int> b,int& ans,int counter)
{
    if(s.first==counter) {
        if(cave.find(s)==cave.end()) ans++;
        if(cave[s]!='B') cave[s]='S';
    }
    if(b.first==counter) {
        if(!(cave.find(b)==cave.end()) && cave[b]!='B') ans--;
        cave[b]='B';
    }
    int man=abs(s.first-b.first)+abs(s.second-b.second);
    for(int j=s.second-man;j<=s.second+man;j++) {
        int mk=abs(s.first-counter)+abs(s.second-j);
        if(mk>man) continue;
        if(cave.find({counter,j})==cave.end()) ans++;
        if(cave[{counter,j}]!='S' && cave[{counter,j}]!='B') cave[{counter,j}]='#';
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day16.txt", fstream::in);
    vector<vector<int>> adj;
    vector<int> flows;
    map<string,int> encoder; map<int,string> decoder;
    int cur_num=0;
    while(getline(fin, s)) {
        string st=s.substr(6,2); int i=23;
        int flow=read_num(s,i);
        if(s[i+8]=='s') i+=25;
        else i+=24;
        vector<string> valves;
        while(i<s.length()) {
            valves.push_back(s.substr(i,2));
            i+=4;
        }
        if(encoder.find(st)==encoder.end()) {
            encoder[st]=cur_num; decoder[cur_num]=st;
            cur_num++;
        }
        for(auto it:valves) {
            if(encoder.find(it)==encoder.end()) {
                encoder[it]=cur_num; decoder[cur_num]=it;
                cur_num++;
            }
        }
        while(encoder[st]>=adj.size()) adj.push_back({});
        while(encoder[st]>=flows.size()) flows.push_back(0);
        flows[encoder[st]]=flow;
        for(auto it:valves) adj[encoder[st]].push_back(encoder[it]);
    }
    
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

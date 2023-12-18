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
    fstream fin("day15.txt", fstream::in);
    vector<vector<pair<int,int>>> mat;
    map<pair<int,int>,char> cave;
    int max_x=-1*inf,min_x=inf,max_y=-1*inf,min_y=inf,ans=0;
    // int counter=10;
    int counter=2000000;
    while(getline(fin, s)) {
        vector<pair<int,int>> vec(2); int i=12;
        vec[0].second=read_num(s,i); i+=4;
        vec[0].first=read_num(s,i); i+=25;
        vec[1].second=read_num(s,i); i+=4;
        vec[1].first=read_num(s,i);
        int man=abs(vec[0].first-vec[1].first)+abs(vec[0].second-vec[1].second);
        max_x = __max(max_x,vec[0].first+man);
        min_x = __min(min_x,vec[0].first-man);
        max_y = __max(max_y,vec[0].second+man);
        min_y = __min(min_y,vec[0].second-man);
        mat.push_back(vec);
    }
    // cerr<<min_x<<" "<<max_x<<"\n";
    // cerr<<min_y<<" "<<max_y<<"\n";
    for(int i=0;i<mat.size();i++) simulate(cave,mat[i][0],mat[i][1],ans,counter);
    // for(auto it:cave) {
    //     if(it.second!='#') cerr<<it.first.first<<" "<<it.first.second<<" "<<it.second<<"\n";
    //     else cerr<<it.first.first<<" "<<it.first.second<<" "<<it.second<<"\n";
    // }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

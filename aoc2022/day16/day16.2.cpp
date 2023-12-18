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

vector<vector<int>> floyd_warshall(vector<vector<int>>& adj)
{
    int n=adj.size();
    vector<vector<int>> shortest(n,vector<int>(n,inf));
    for(int i=0;i<n;i++) {
        shortest[i][i]=0;
        for(int j=0;j<adj[i].size();j++) {
            shortest[i][adj[i][j]]=1;
            shortest[adj[i][j]][i]=1;
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) shortest[i][j] = __min(shortest[i][j],shortest[i][k]+shortest[k][j]);
        }
    }
    return shortest;
}

int solve(vector<vector<int>>& adj,vector<int>& flows,vector<bool>& open,int cur=0,int left=30)
{
    int n=adj.size();
    vector<vector<int>> shortest=floyd_warshall(adj);
    vector<int> values(n,-1);
    while(left) {
        int id=-1,max=0;
        for(int i=0;i<n;i++) {
            if(open[i]==false && left>=shortest[cur][i]+1) values[i]=flows[i]*(left-1-shortest[cur][i]);
            else values[i]=-1;
            if(values[i]>max) { max=values[i]; id=i; }
        }
    }
    return 0;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    // This is the best problem till now in the whole of AOC++ //
    // By the way it is a NP Complete TSP Problem to be solved. //
    string s;
    fstream fin("day16.txt", fstream::in);
    vector<vector<int>> adj;
    map<string,int> mp;
    vector<int> flows;
    while(getline(fin, s)) {
        string x=s.substr(6,2); int i=23;
        int num=read_num(s,i); i+=25;
        // cerr<<x<<" ";
        if(mp.find(x)==mp.end()) { mp[x]=adj.size(); adj.push_back({}); flows.push_back(num); }
        else flows[mp[x]]=num;
        while(i<s.length()) {
            if(i==s.length()-1) i--;
            string y=s.substr(i,2); i+=4;
            // cerr<<y<<" ";
            if(mp.find(y)==mp.end()) { mp[y]=adj.size(); adj.push_back({}); flows.push_back(-1); }
            adj[mp[x]].push_back(mp[y]);
        }
    }
    // cerr<<"\n";
    // for(int i=0;i<adj.size();i++) {
    //     cerr<<flows[i]<<" ";
    //     for(int j=0;j<adj[i].size();j++) cerr<<adj[i][j]<<" ";
    //     cerr<<"\n";
    // }
    vector<bool> open(flows.size(),false);
    int ans=solve(adj,flows,open,0,30);
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

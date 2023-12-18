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

vector<pair<int,int>> valid_moves(vector<vector<int>>& mat,int n,int m,int i,int j)
{
    vector<pair<int,int>> ans;
    bool flag1=(i==0),flag2=(j==0),flag3=(i==n-1),flag4=(j==m-1);
    if(flag1==false && mat[i-1][j]>=(mat[i][j]-1)) ans.push_back({i-1,j});
    if(flag2==false && mat[i][j-1]>=(mat[i][j]-1)) ans.push_back({i,j-1});
    if(flag3==false && mat[i+1][j]>=(mat[i][j]-1)) ans.push_back({i+1,j});
    if(flag4==false && mat[i][j+1]>=(mat[i][j]-1)) ans.push_back({i,j+1});
    return ans;
}

void dijkstra(vector<vector<int>>& mat,vector<vector<int>>& ans,int n,int m,pair<int,int> end)
{
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,end.first,end.second});
    while(!pq.empty()) {
        vector<int> pass=pq.top(); pq.pop();
        if(visited[pass[1]][pass[2]]==false) ans[pass[1]][pass[2]]=pass[0];
        else continue;
        vector<pair<int,int>> valid=valid_moves(mat,n,m,pass[1],pass[2]);
        for(auto it:valid) pq.push({pass[0]+1,it.first,it.second});
        visited[pass[1]][pass[2]]=true;
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day12.txt", fstream::in);
    vector<vector<int>> mat;
    pair<int,int> start={0,0},end={0,0};
    while(getline(fin, s)) {
        vector<int> ans;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='S') { start={mat.size(),i}; ans.push_back(0); }
            else if(s[i]=='E') { end={mat.size(),i}; ans.push_back('z'-'a'); }
            else ans.push_back(s[i]-'a');
        }
        mat.push_back(ans);
    }
    int n=mat.size(),m=mat[0].size();
    vector<vector<int>> ans(n,vector<int>(m,inf));
    dijkstra(mat,ans,n,m,end);
    int find=inf;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]==0 && find>ans[i][j]) find=ans[i][j];
        }
    }
    cout<<find<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

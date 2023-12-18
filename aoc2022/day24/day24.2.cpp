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

vector<vector<string>> ahead(vector<vector<string>>& bliz,int& n,int& m) {
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) cerr<<bliz[i][j][0];
    //     cerr<<"\n";
    // }
    vector<vector<string>> new_bliz(n,vector<string>(m,""));
    for(int i=0;i<n;i++) { new_bliz[i][0]="#"; new_bliz[i][m-1]="#"; }
    for(int i=0;i<m;i++) { new_bliz[0][i]="#"; new_bliz[n-1][i]="#"; }
    new_bliz[0][1]="."; new_bliz[n-1][m-2]=".";
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) cerr<<new_bliz[i][j];
    //     cerr<<"\n";
    // }
    // cerr<<n<<" "<<m<<"\n";
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<m-1;j++) {
            string ch=bliz[i][j];
            // cerr<<bliz[i][j]<<"   ";
            // continue;
            // #>>.<^<#  #>v.><>#
            for(char x:ch) {
                // cerr<<x;
                if(x=='.' || x=='#') continue;
                if(x=='>') {
                    if(j==m-2) new_bliz[i][1].push_back(x);
                    else new_bliz[i][j+1].push_back(x);
                }
                else if(x=='v') {
                    if(i==n-2) new_bliz[1][j].push_back(x);
                    else new_bliz[i+1][j].push_back(x);
                }
                if(x=='<') {
                    if(j==1) new_bliz[i][m-2].push_back(x);
                    else new_bliz[i][j-1].push_back(x);
                }
                else if(x=='^') {
                    if(i==1) new_bliz[n-2][j].push_back(x);
                    else new_bliz[i-1][j].push_back(x);
                }
                // cerr<<i<<" "<<j<<" moved"<<"\n";
            }
            // cerr<<"   ";
        }
        // cerr<<"\n";
    }
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<m-1;j++) {
            if(new_bliz[i][j].size()==0) new_bliz[i][j]=".";
        }
    }
    // cerr<<"Completed ahead once"<<"\n";
    return new_bliz;
}

// void behind(map<pair<int,int>,vector<int>>& bliz,int n,int m)
// {
//     map<pair<int,int>,vector<int>> new_bliz;
//     for(auto it:bliz) {
//         int i=it.first.first,j=it.first.second;
//         for(auto x:it.second) {
//             if(x==2) { if(j==m-1) j=0; new_bliz[{i,j+1}].push_back(0); }
//             else if(x==3) { if(i==n-1) i=0; new_bliz[{i+1,j}].push_back(1); }
//             else if(x==0) { if(j==1) j=m; new_bliz[{i,j-1}].push_back(2); }
//             else { if(i==1) i=n; new_bliz[{i-1,j}].push_back(3); }
//         }
//     }
//     bliz=new_bliz;
//     return;
// }

// int f(char x) {
//     if(x=='>') return 0;
//     else if(x=='v') return 1;
//     else if(x=='<') return 2;
//     else if(x=='^') return 3;
//     else return -1;
// }

bool check(vector<pair<int,int>>& start,pair<int,int>& end) {
    for(auto it:start) {
        if(it==end) return true;
    }
    return false;
}

vector<pair<int,int>> best_path(vector<vector<string>>& valley,vector<pair<int,int>>& st,int& n,int& m) {
    vector<pair<int,int>> new_start;
    for(auto start:st) {
        int i=start.first,j=start.second;
        if(valley[i][j]==".") new_start.push_back({i,j});
        if(i>0 && valley[i-1][j]==".") new_start.push_back({i-1,j});
        if(j>0 && valley[i][j-1]==".") new_start.push_back({i,j-1});
        if(i<n-1 && valley[i+1][j]==".") new_start.push_back({i+1,j});
        if(j<m-1 && valley[i][j+1]==".") new_start.push_back({i,j+1});
    }
    sort(new_start.begin(), new_start.end());
    new_start.erase(unique(new_start.begin(), new_start.end()), new_start.end());
    // for(auto it:new_start) cerr<<"("<<it.first<<","<<it.second<<")"<<" ";
    return new_start;
}

int32_t main() {
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day24.txt", fstream::in);
    vector<vector<string>> valley;
    while(getline(fin, s)) {
        vector<string> p;
        for(int i=0;i<s.length();i++) {
            string t(1,s[i]);
            p.push_back(t);
        }
        valley.push_back(p);
    }
    int n=valley.size(),m=valley[0].size(),ctr=0;
    // cerr<<n<<" "<<m<<"\n";
    vector<pair<int,int>> start;
    start.push_back({0,1});
    pair<int,int> end={n-1,m-2};
    while(check(start,end)==false) {
        // cerr<<"No path in "<<ctr<<" minutes"<<"\n";
        ctr++;
        valley=ahead(valley,n,m);
        start=best_path(valley,start,n,m);
    }
    start={end}; end={0,1};
    while(check(start,end)==false) {
        // cerr<<"No path in "<<ctr<<" minutes"<<"\n";
        ctr++;
        valley=ahead(valley,n,m);
        start=best_path(valley,start,n,m);
    }
    start={end}; end={n-1,m-2};
    while(check(start,end)==false) {
        // cerr<<"No path in "<<ctr<<" minutes"<<"\n";
        ctr++;
        valley=ahead(valley,n,m);
        start=best_path(valley,start,n,m);
    }
    cout<<ctr<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

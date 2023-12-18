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
    int num=0;
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    return num;
}

void add_walls(vector<vector<char>>& cave,vector<vector<pair<int,int>>>& mat)
{
    vector<char> p(cave[0].size(),'#'); cave[cave.size()-1]=p;
    for(auto vec:mat) {
        if(vec.size()==1) cave[vec[0].second][vec[0].first]='#';
        for(int i=1;i<vec.size();i++) {
            if(vec[i-1].first==vec[i].first) {
                int start=__min(vec[i-1].second,vec[i].second);
                int end=__max(vec[i-1].second,vec[i].second);
                for(int j=start;j<=end;j++) cave[j][vec[i].first]='#';
            }
            else {
                int start=__min(vec[i-1].first,vec[i].first);
                int end=__max(vec[i-1].first,vec[i].first);
                for(int j=start;j<=end;j++) cave[vec[i].second][j]='#';
            }
        }
    }
    return;
}

void simulate(vector<vector<char>>& cave,int& x,int& y)
{
    int n=cave.size(),m=cave[0].size();
    while(1) {
        if(y!=n-1 && cave[y+1][x]=='.') y++;
        else if(y!=n-1 && x!=0 && cave[y+1][x-1]=='.') { y++; x--; }
        else if(y!=n-1 && x!=m-1 && cave[y+1][x+1]=='.') { y++; x++; }
        else break;
    }
    cave[y][x]='o';
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day14.txt", fstream::in);
    vector<vector<pair<int,int>>> mat;
    int max_x=-1*inf,min_x=inf,max_y=-1*inf,min_y=inf;
    while(getline(fin, s)) {
        vector<pair<int,int>> vec;
        int i=0;
        while(i<s.length()) {
            int x,y;
            x=read_num(s,i); i++;
            y=read_num(s,i); i+=4;
            max_x = __max(max_x,x); min_x = __min(min_x,x);
            max_y = __max(max_y,y); min_y = __min(min_y,y);
            vec.push_back({x,y});
        }
        mat.push_back(vec);
    }
    // cerr<<min_x<<" "<<max_x<<"\n";
    // cerr<<min_y<<" "<<max_y<<"\n";
    max_x = __max(max_x,500+max_y+3);
    min_x = __min(min_x,500-max_y-3);
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<mat[i].size();j++) mat[i][j].first-=min_x;
    }
    int n=max_y+3,m=max_x-min_x+1;
    vector<vector<char>> cave(n,vector<char>(m,'.'));
    add_walls(cave,mat);
    int ans=0;
    while(1) {
        int start_x=500,start_y=0; start_x-=min_x;
        simulate(cave,start_x,start_y);
        if(start_y==0 && start_x==(500-min_x)) { ans++; break; }
        else ans++;
    }
    // for(int i=0;i<cave.size();i++) {
    //     for(int j=0;j<cave[i].size();j++) cerr<<cave[i][j];
    //     cerr<<"\n";
    // }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

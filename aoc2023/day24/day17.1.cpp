#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define INF 1e18
#define pvi pair<int,vector<int>>

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i)
{
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

void prints(map<vector<int>,int>& next_dir, vector<int> s,int n,int m) {
    vector<vector<char>> paths(n,vector<char>(m,'.'));
    // > - 0 v - 1 < - 2 ^ - 3 (Directional Encoding)
    while(s[0]!=n-1 || s[1]!=m-1) {
        // cout<<s[0]<<" "<<s[1]<<"\n";
        int dir=next_dir[s]; s[3]=dir;
        if(dir==0) { paths[s[0]][s[1]]='>'; s[1]++; }
        else if(dir==1) { paths[s[0]][s[1]]='v'; s[0]++; }
        else if(dir==2) { paths[s[0]][s[1]]='<'; s[1]--; }
        else { paths[s[0]][s[1]]='^'; s[0]--; }
        if(s[3]==dir) s[2]++; else s[2]=0;
    }
    fstream fout("day17_out.txt", fstream::out);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) fout<<paths[i][j]<<" ";
        fout<<"\n";
    }
    return;
}

int dijkstra_algo(vector<vector<int>>& mat,int max_motion, vector<int> start) {
    int n=mat.size(),m=mat[0].size(),ret=INF;
    map<vector<int>,int> dp; map<vector<int>,int> next_dir;
    priority_queue<pvi,vector<pvi>,greater<pvi>> pq;
    pq.push({0,start});
    // > - 0 v - 1 < - 2 ^ - 3 (Directional Encoding)
    // fstream fout("day17_out.txt", fstream::out);
    while(!pq.empty()) {
        pvi px=pq.top(); pq.pop();
        vector<int> p=px.second;
        if(dp.find(p)!=dp.end()) continue;
        dp[p]=px.first; int i=p[0],j=p[1],mot=p[2],dir=p[3];
        if(i==0 && j==0) ret=min(ret,dp[p]);
        // fout<<i<<" "<<j<<" "<<mot<<" "<<dir<<" "<<mat[i][j]<<" ";
        vector<vector<int>> next;
        if(mot==max_motion-1) {
            if(dir==0 || dir==2) { next.push_back({i+1,j,0,1}); next.push_back({i-1,j,0,3}); }
            else { next.push_back({i,j+1,0,0}); next.push_back({i,j-1,0,2}); }
        }
        else {
            if(dir==0 || dir==2) { next.push_back({i+1,j,0,1}); next.push_back({i-1,j,0,3}); next.push_back({i,j+1-dir,mot+1,dir}); }
            else { next.push_back({i,j+1,0,0}); next.push_back({i,j-1,0,2}); next.push_back({i+2-dir,j,mot+1,dir}); }
        }
        for(auto it:next) {
            int i1=it[0],j1=it[1],mot1=it[2],dir1=it[3];
            if(i1<0 || j1<0 || i1>=n || j1>=m) continue;
            else if(dp.find(it)!=dp.end()) continue;
            else pq.push({mat[i][j]+dp[p],it});
        }
    }
    // cout<<next_dir[{1,2,0,1}]<<"\n";
    // prints(next_dir,start,n,m);
    // for(auto it:dp) fout<<it.first[0]<<" "<<it.first[1]<<" "<<it.first[2]<<" "<<it.first[3]<<" "<<it.second<<"\n";
    return ret;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    cout<<"Please wait this code will take a few seconds!!!"<<endl;
    int ans=INF,max_motion=3;
    string s; vector<vector<int>> mat;
    fstream fin("day17.txt", fstream::in);
    while(getline(fin, s)) {
        vector<int> nums;
        for(auto it:s) nums.push_back(it-'0');
        mat.push_back(nums);
    }
    int n=mat.size(),m=mat[0].size();
    vector<vector<int>> start={{n-1,m-1,0,2},{n-1,m-1,0,3}};
    for(auto st:start) {
        int num=dijkstra_algo(mat,max_motion,st); ans=min(ans,num);
        // cout<<num<<"\n";
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

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

int paths_explored=0;

int dijkstra_algo(vector<vector<int>>& mat,int max_motion, int min_motion, vector<int> start) {
    int n=mat.size(),m=mat[0].size(),ret=INF;
    map<vector<int>,int> dp; map<vector<int>,int> next_dir;
    priority_queue<pvi,vector<pvi>,greater<pvi>> pq;
    pq.push({0,start});
    // > - 0 v - 1 < - 2 ^ - 3 (Directional Encoding)
    while(!pq.empty()) {
        pvi px=pq.top(); pq.pop();
        vector<int> p=px.second;
        if(dp.find(p)!=dp.end()) continue;
        dp[p]=px.first; int i=p[0],j=p[1],mot=p[2],dir=p[3];
        // cout<<i<<" "<<j<<" "<<mot<<" "<<dir<<" "<<dp[p]<<"\n";
        if(i==0 && j==0 && mot>=min_motion-1) {
            ret=min(ret,dp[p]); paths_explored++;
            if(paths_explored%3==0) cout<<"Explored "<<paths_explored<<" paths to the start"<<endl;
        }
        vector<vector<int>> next;
        if(mot==max_motion-1) {
            if(dir==0 || dir==2) { next.push_back({i+1,j,0,1}); next.push_back({i-1,j,0,3}); }
            else { next.push_back({i,j+1,0,0}); next.push_back({i,j-1,0,2}); }
        }
        else if(mot<min_motion-1) {
            if(dir==0 || dir==2) next.push_back({i,j+1-dir,mot+1,dir});
            else next.push_back({i+2-dir,j,mot+1,dir});
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
    return ret;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    cout<<"Please wait this code will take a few seconds!!!"<<endl;
    int ans=INF,max_motion=10,min_motion=4;
    string s; vector<vector<int>> mat;
    fstream fin("day17.txt", fstream::in);
    while(getline(fin, s)) {
        vector<int> nums;
        for(auto it:s) nums.push_back(it-'0');
        mat.push_back(nums);
    }
    cout<<"We will explore around 30 paths to the start"<<endl;
    int n=mat.size(),m=mat[0].size();
    vector<vector<int>> start={{n-1,m-1,-1,2},{n-1,m-1,-1,3}};
    for(auto st:start) {
        int num=dijkstra_algo(mat,max_motion,min_motion,st); ans=min(ans,num);
        // cout<<num<<endl;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

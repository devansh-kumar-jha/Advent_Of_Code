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
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

int find_energy(vector<string>& mat,vector<int> start) {
    int n=mat.size(),m=mat[0].length(),ans=0;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    map<vector<int>,bool> state_visit;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int d=0;d<4;d++) state_visit[{i,j,d}]=false;
        }
    }
    stack<vector<int>> st; st.push(start); state_visit[start]=true;
    while(!st.empty()) {
        vector<int> p=st.top(); st.pop();
        int i=p[0],j=p[1],d=p[2];
        // cout<<i<<" "<<j<<" "<<state_visit[p]<<"\n";
        if(i<0 || i>=n || j<0 || j>=m) continue;
        if(visited[i][j]==false) ans++;
        visited[i][j]=true;
        // > - 0 v - 1 < - 2 ^ - 3 (Directional Codes)
        if(mat[i][j]=='.' || (mat[i][j]=='|' && (d==1 || d==3)) || (mat[i][j]=='-' && (d==0 || d==2))) {
            if(d==0 && state_visit[{i,j+1,d}]==false) { st.push({i,j+1,d}); state_visit[{i,j+1,d}]=true; }
            else if(d==1 && state_visit[{i+1,j,d}]==false) { st.push({i+1,j,d}); state_visit[{i+1,j,d}]=true; }
            else if(d==2 && state_visit[{i,j-1,d}]==false) { st.push({i,j-1,d}); state_visit[{i,j-1,d}]=true; }
            else if(d==3 && state_visit[{i-1,j,d}]==false) { st.push({i-1,j,d}); state_visit[{i-1,j,d}]=true; }
        }
        else if(mat[i][j]=='/') {
            if(d==0 && state_visit[{i-1,j,3}]==false) { st.push({i-1,j,3}); state_visit[{i-1,j,3}]=true; }
            else if(d==1 && state_visit[{i,j-1,2}]==false) { st.push({i,j-1,2}); state_visit[{i,j-1,2}]=true; }
            else if(d==2 && state_visit[{i+1,j,1}]==false) { st.push({i+1,j,1}); state_visit[{i+1,j,1}]=true; }
            else if(d==3 && state_visit[{i,j+1,0}]==false) { st.push({i,j+1,0}); state_visit[{i,j+1,0}]=true; }
        }
        else if(mat[i][j]=='\\') {
            if(d==2 && state_visit[{i-1,j,3}]==false) { st.push({i-1,j,3}); state_visit[{i-1,j,3}]=true; }
            else if(d==3 && state_visit[{i,j-1,2}]==false) { st.push({i,j-1,2}); state_visit[{i,j-1,2}]=true; }
            else if(d==0 && state_visit[{i+1,j,1}]==false) { st.push({i+1,j,1}); state_visit[{i+1,j,1}]=true; }
            else if(d==1 && state_visit[{i,j+1,0}]==false) { st.push({i,j+1,0}); state_visit[{i,j+1,0}]=true; }
        }
        else if(mat[i][j]=='|') {
            if(state_visit[{i+1,j,1}]==false) { st.push({i+1,j,1}); state_visit[{i+1,j,1}]=true; }
            if(state_visit[{i-1,j,3}]==false) { st.push({i-1,j,3}); state_visit[{i-1,j,3}]=true; }
        }
        else {
            if(state_visit[{i,j+1,0}]==false) { st.push({i,j+1,0}); state_visit[{i,j+1,0}]=true; }
            if(state_visit[{i,j-1,2}]==false) { st.push({i,j-1,2}); state_visit[{i,j-1,2}]=true; }
        }
    }
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    cout<<"Please wait this code will take a few minutes!!!"<<endl;
    int ans=0;
    // cin>>num_cycles;
    string s; vector<string> mat;
    fstream fin("day16.txt", fstream::in);
    while(getline(fin, s)) mat.push_back(s);
    int n=mat.size(),m=mat[0].length();
    cout<<"Execution will take place in "<<(n+m)<<" phases."<<endl;
    for(int i=0;i<n;i++) {
        // cout<<i<<endl;
        ans=max(ans,find_energy(mat,{i,0,0}));
        ans=max(ans,find_energy(mat,{i,m-1,2}));
        if(i%10==0) cout<<"Execution till phase "<<(i+1)<<" is completed"<<endl;
    }
    for(int j=0;j<m;j++) {
        // cout<<j<<endl;
        ans=max(ans,find_energy(mat,{0,j,1}));
        ans=max(ans,find_energy(mat,{n-1,j,3}));
        if(j%10==0) cout<<"Execution till phase "<<(n+j+1)<<" is completed"<<endl;
    }
    // cout<<"\n";
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

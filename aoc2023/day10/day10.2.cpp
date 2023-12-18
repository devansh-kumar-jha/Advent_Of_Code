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

vector<vector<int>> fill_context(int i,int j,vector<string>& mat) {
    switch (mat[i][j]) {
        case '|' : {
            if(i==0 || i==mat.size()-1) return {};
            else {
                if(mat[i-1][j]!='|' && mat[i-1][j]!='7' && mat[i-1][j]!='F') return {};
                else if(mat[i+1][j]!='|' && mat[i+1][j]!='L' && mat[i+1][j]!='J') return {};
                else return {{-1,0},{1,0}};
            }
        }
        case '-' : {
            if(j==0 || j==mat[i].length()-1) return {};
            else {
                if(mat[i][j-1]!='-' && mat[i][j-1]!='L' && mat[i][j-1]!='F') return {};
                else if(mat[i][j+1]!='-' && mat[i][j+1]!='7' && mat[i][j+1]!='J') return {};
                else return {{0,-1},{0,1}};
            }
        }
        case 'L' : {
            if(i==0 || j==mat[i].length()-1) return {};
            else {
                if(mat[i-1][j]!='|' && mat[i-1][j]!='7' && mat[i-1][j]!='F') return {};
                else if(mat[i][j+1]!='-' && mat[i][j+1]!='7' && mat[i][j+1]!='J') return {};
                else return {{-1,0},{0,1}};
            }
        }
        case 'J' : {
            if(i==0 || j==0) return {};
            else {
                if(mat[i-1][j]!='|' && mat[i-1][j]!='7' && mat[i-1][j]!='F') return {};
                else if(mat[i][j-1]!='-' && mat[i][j-1]!='L' && mat[i][j-1]!='F') return {};
                else return {{-1,0},{0,-1}};
            }
        }
        case '7' : {
            if(i==mat.size()-1 || j==0) return {};
            else {
                if(mat[i+1][j]!='|' && mat[i+1][j]!='L' && mat[i+1][j]!='J') return {};
                else if(mat[i][j-1]!='-' && mat[i][j-1]!='L' && mat[i][j-1]!='F') return {};
                else return {{1,0},{0,-1}};
            }
        }
        case 'F' : {
            if(i==mat.size()-1 || j==mat[i].length()-1) return {};
            else {
                if(mat[i+1][j]!='|' && mat[i+1][j]!='L' && mat[i+1][j]!='J') return {};
                else if(mat[i][j+1]!='-' && mat[i][j+1]!='7' && mat[i][j+1]!='J') return {};
                else return {{1,0},{0,1}};
            }
        }
        case '.' : return {};
        default: return {};
    }
    return {};
}

pair<bool,int> dfs(int start_x,int start_y,vector<string>& mat,vector<vector<bool>>& visited) {
    stack<vector<int>> st;
    map<vector<int>,pair<bool,int>> mp;
    st.push({start_x,start_y}); vector<int> prev;
    while(!st.empty()) {
        vector<int> p=st.top();
        int i=p[0],j=p[1];
        // cout<<i<<" "<<j<<" "<<counter<<" "; counter++;
        if(visited[i][j]==true) { mp[{i,j}]={mp[prev].first,mp[prev].second+1}; st.pop(); mat[i][j]='O'; }
        else {
            visited[i][j]=true;
            vector<vector<int>> flag=fill_context(i,j,mat);
            if(flag.size()==0) { mp[{i,j}]={false,0}; st.pop(); }
            else if(visited[i+flag[0][0]][j+flag[0][1]]==false) {
                // cout<<"here1 "<<flag[0][0]<<" "<<flag[0][1]<<endl;
                st.push({i+flag[0][0],j+flag[0][1]});
            }
            else if(visited[i+flag[1][0]][j+flag[1][1]]==false) {
                // cout<<"here2 "<<flag[1][0]<<" "<<flag[1][1]<<endl;
                st.push({i+flag[1][0],j+flag[1][1]});
            }
            else { mp[{i,j}]={true,1}; st.pop(); mat[i][j]='O'; }
        }
        prev=p;
    }
    return mp[{start_x,start_y}];
}

int bfs(vector<string>& mat,vector<vector<bool>>& visited,int start_x,int start_y) {
    queue<vector<int>> q; int flag=0,ans=0;
    q.push({start_x,start_y}); ans++; visited[start_x][start_y]=true;
    while(!q.empty()) {
        vector<int> p=q.front(); q.pop();
        int i=p[0],j=p[1]; mat[i][j]='.';
        if(i==0 || j==0 || i==mat.size()-1 || j==mat[i].length()-1) flag=1;
        if(i>0 && visited[i-1][j]==false && mat[i-1][j]!='O') { q.push({i-1,j}); ans++; visited[i-1][j]=true; }
        if(j>0 && visited[i][j-1]==false && mat[i][j-1]!='O') { q.push({i,j-1}); ans++; visited[i][j-1]=true; }
        if(i<mat.size()-1 && visited[i+1][j]==false && mat[i+1][j]!='O') { q.push({i+1,j}); ans++; visited[i+1][j]=true; }
        if(j<mat[i].length()-1 && visited[i][j+1]==false && mat[i][j+1]!='O') { q.push({i,j+1}); ans++; visited[i][j+1]=true; }
    }
    if(flag==1) return 0;
    else return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s; vector<string> mat;
    fstream fin("day10.txt", fstream::in);
    // fstream fout("day10_out.txt", fstream::out);
    vector<char> choices={'|','-','L','J','7','F','.'};
    while(getline(fin, s)) mat.push_back(s);
    int start_x=-1,start_y=-1;
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<mat[i].length();j++) {
            if(mat[i][j]=='S') {
                start_x=i; start_y=j;
                break;
            }
        }
        if(start_x!=-1) break;
    }
    int n=mat.size(),m=mat[0].length();
    for(auto it:choices) {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<string> mat1=mat;
        mat1[start_x][start_y]=it;
        pair<bool,int> p=dfs(start_x,start_y,mat1,visited);
        if(p.first==false) continue;
        for(int i=0;i<n;i++) {
            int parity=0,prev=0;
            for(int j=0;j<m;j++) {
                if(mat1[i][j]=='O') mat1[i][j]=((mat[i][j]=='S')?(it):(mat[i][j]));
                else mat1[i][j]='.';
                if(mat1[i][j]=='.') ans+=(parity%2);
                else if(mat1[i][j]=='-') continue;
                else if(mat1[i][j]=='|') parity++;
                else if(mat1[i][j]=='L' || mat1[i][j]=='J') {
                    if(prev==0 || prev==1) prev=(1-prev);
                    else { prev=0; parity++; } 
                }
                else {
                    if(prev==0 || prev==2) prev=(2-prev);
                    else { prev=0; parity++; }
                }
            }
        }
        break;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

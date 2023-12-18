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

bool view(vector<vector<int>>& mat,int i,int j,int n,int m)
{
    bool flag1=true,flag2=true,flag3=true,flag4=true;
    for(int k=i-1;k>-1;k--) { if(mat[k][j]>=mat[i][j]) flag1=false; }
    for(int k=i+1;k<n;k++) { if(mat[k][j]>=mat[i][j]) flag2=false; }
    for(int k=j-1;k>-1;k--) { if(mat[i][k]>=mat[i][j]) flag3=false; }
    for(int k=j+1;k<m;k++) { if(mat[i][k]>=mat[i][j]) flag4=false; }
    return (flag1 || flag2 || flag3 || flag4);
}

int solve(vector<vector<int>>& mat)
{
    int ans=0;
    int n=mat.size(),m=mat[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(view(mat,i,j,n,m)==true) ans++;
        }
    }
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day8.txt", fstream::in);
    vector<vector<int>> mat;
    while(getline(fin, s)) {
        vector<int> row;
        for(auto it:s) row.push_back(it-'0');
        mat.push_back(row);
    }
    int ans=solve(mat);
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

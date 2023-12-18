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

int view(vector<vector<int>>& mat,int i,int j,int n,int m)
{
    int flag1=0,flag2=0,flag3=0,flag4=0;
    for(int k=i-1;k>-1;k--) { flag1++; if(mat[k][j]>=mat[i][j]) break; }
    for(int k=i+1;k<n;k++) { flag2++; if(mat[k][j]>=mat[i][j]) break; }
    for(int k=j-1;k>-1;k--) { flag3++; if(mat[i][k]>=mat[i][j]) break; }
    for(int k=j+1;k<m;k++) { flag4++; if(mat[i][k]>=mat[i][j]) break; }
    return (flag1*flag2*flag3*flag4);
}

int solve(vector<vector<int>>& mat)
{
    int ans=0;
    int n=mat.size(),m=mat[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int num=view(mat,i,j,n,m);
            if(ans<num) ans=num;
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

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
    int num=0;
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    return num;
}

// num_decode is used to get the number to be considered here.
int num_decode(vector<string>& mat,int i, int j,vector<vector<bool>>& visited) {
    // if(visited[i][j]==true) return 0;
    string number="";
    number.push_back(mat[i][j]); visited[i][j]=true;
    int cur_j=j-1;
    while(cur_j>-1 && mat[i][cur_j]>='0' && mat[i][cur_j]<='9') {
        string x(1,mat[i][cur_j]); number=x+number;
        visited[i][cur_j]=true; cur_j--;
    }
    cur_j=j+1;
    while(cur_j<mat[0].length() && mat[i][cur_j]>='0' && mat[i][cur_j]<='9') {
        number.push_back(mat[i][cur_j]); visited[i][cur_j]=true;
        cur_j++;
    }
    int ans=0;
    for(int i=0;i<number.length();i++) ans=(ans*10)+(number[i]-'0');
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s; vector<string> mat;
    fstream fin("day3.txt", fstream::in);
    while (getline(fin, s)) mat.push_back(s);
    int n=mat.size(),m=mat[0].length();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='.') continue;
            if(mat[i][j]>='0' && mat[i][j]<='9') continue;
            vector<int> nums;
            if(i>0 && mat[i-1][j]>='0' && mat[i-1][j]<='9' && visited[i-1][j]==false) nums.push_back(num_decode(mat,i-1,j,visited));
            if(i<n-1 && mat[i+1][j]>='0' && mat[i+1][j]<='9' && visited[i+1][j]==false) nums.push_back(num_decode(mat,i+1,j,visited));
            if(j>0 && mat[i][j-1]>='0' && mat[i][j-1]<='9' && visited[i][j-1]==false) nums.push_back(num_decode(mat,i,j-1,visited));
            if(j<m-1 && mat[i][j+1]>='0' && mat[i][j+1]<='9' && visited[i][j+1]==false) nums.push_back(num_decode(mat,i,j+1,visited));
            if(i>0 && j>0 && mat[i-1][j-1]>='0' && mat[i-1][j-1]<='9' && visited[i-1][j-1]==false) nums.push_back(num_decode(mat,i-1,j-1,visited));
            if(i<n-1 && j<m-1 && mat[i+1][j+1]>='0' && mat[i+1][j+1]<='9' && visited[i+1][j+1]==false) nums.push_back(num_decode(mat,i+1,j+1,visited));
            if(i<n-1 && j>0 && mat[i+1][j-1]>='0' && mat[i+1][j-1]<='9' && visited[i+1][j-1]==false) nums.push_back(num_decode(mat,i+1,j-1,visited));
            if(i>0 && j<m-1 && mat[i-1][j+1]>='0' && mat[i-1][j+1]<='9' && visited[i-1][j+1]==false) nums.push_back(num_decode(mat,i-1,j+1,visited));
            if(mat[i][j]=='*' && nums.size()==2) ans+=(nums[0]*nums[1]);
        }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

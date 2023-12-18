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

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s; vector<string> mat;
    fstream fin("day11.txt", fstream::in);
    while(getline(fin, s)) mat.push_back(s);
    int n=mat.size(),m=mat[0].length();
    vector<int> nums1(n,0),nums2(m,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='.') continue;
            nums1[i]++; nums2[j]++;
        }
    }
    vector<vector<int>> galaxies;
    int cur_i=0;
    for(int i=0;i<n;i++) {
        int cur_j=0;
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='#') galaxies.push_back({cur_i,cur_j});
            if(nums2[j]==0) cur_j+=2;
            else cur_j++;
        }
        if(nums1[i]==0) cur_i+=2;
        else cur_i++;
    }
    for(int i=0;i<galaxies.size();i++) {
        for(int j=i+1;j<galaxies.size();j++) {
            vector<int> a=galaxies[i],b=galaxies[j];
            ans+=(abs(b[1]-a[1])+abs(b[0]-a[0]));
        }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

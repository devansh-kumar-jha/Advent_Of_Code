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

int add_next(vector<int> nums) {
    vector<vector<int>> mat; mat.push_back(nums);
    while((mat.back().size())>0) {
        vector<int> last=mat.back();
        int flag=0;
        for(auto it:last) {
            if(it!=0) { flag=1; break; }
        }
        if(flag==0) break;
        vector<int> next;
        for(int i=1;i<last.size();i++) next.push_back(last[i]-last[i-1]);
        mat.push_back(next);
    }
    for(int i=mat.size()-1;i>-1;i--) {
        if(i==mat.size()-1) mat[i].push_back(0);
        else mat[i].push_back(mat[i].back()+mat[i+1].back());
    }
    // for(auto it:mat) {
    //     for(auto f:it) cout<<f<<" ";
    //     cout<<"\n";
    // }
    return mat[0].back();
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s;
    fstream fin("day9.txt", fstream::in);
    while(getline(fin, s)) {
        int i=0; vector<int> nums;
        while(i<s.length()) {
            nums.push_back(read_num(s,i));
            i++;
        }
        int new_num=add_next(nums);
        ans+=new_num;
        // cout<<new_num<<" ";        
    }
    // cout<<"\n";
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define width 7
#define mult 811589153

void dkj() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i) {
    if(i>=s.length()) return 0;
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

void mover(vector<pair<int,int>>& arr,int i,map<pair<int,int>,int>& mp) {
    int n=arr.size(),mv=arr[i].first;
    // if(mv<=(-1*n) || mv>=n) {
    //     if(mv>=n) mv=mv%n;
    //     else mv=-1*(abs(mv)%n);
    // }
    // if(mv>0 && mv>n-1-i) mv=mv-n+1;
    // else if(mv<0 && abs(mv)>i) mv=n-1-abs(mv);
    int p=1; if(mv<0) p=-1;
    for(int c=0;c<abs(mv);c++) {
        swap(mp[arr[i]],mp[arr[(i+n+p)%n]]);
        swap(arr[i],arr[(i+n+p)%n]); i=(i+n+p)%n;
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;  int ctr=0;
    fstream fin("day20.txt", fstream::in);
    map<int,int> cor;
    map<pair<int,int>,int> mp;
    vector<pair<int,int>> nums,fins;
    while(getline(fin, s)) {
        int i=0,num=read_num(s,i);
        num=num*mult;
        nums.push_back({num,cor[num]}); fins.push_back({num,cor[num]});
        mp[{num,cor[num]}]=ctr; ctr++; cor[num]++;
    }
    int n=nums.size();
    cout<<n<<"\n";
    exit(0);
    for(int t=0;t<10;t++) {
        for(int i=0;i<n;i++) {
            mover(fins,mp[nums[i]],mp);
            // for(auto it:fins) cerr<<it<<" ";
            // cerr<<"\n";
        }
        cerr<<"Iterations completed "<<(t+1)<<"\n";
    }
    int ans=fins[(mp[{0,0}]+1000)%n].first+fins[(mp[{0,0}]+2000)%n].first+fins[(mp[{0,0}]+3000)%n].first;
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

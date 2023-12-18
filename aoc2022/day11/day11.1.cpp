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

int get_num(string& s,int& ctr)
{
    int num=0;
    while(ctr<s.length() && s[ctr]>='0' && s[ctr]<='9') { num=num*10+(s[ctr]-'0'); ctr++; }
    return num;
}

void round(vector<queue<int>>& monkeys,vector<vector<int>>& ops,vector<vector<int>>& test,vector<int>& nums)
{
    int n=monkeys.size();
    // for(auto it:monkeys) cerr<<it.size()<<" "; cerr<<"\n";
    for(int i=0;i<n;i++) {
        while(!monkeys[i].empty()) {
            int num=monkeys[i].front();
            monkeys[i].pop();
            if(ops[i][0]==0) num=num+ops[i][1];
            else if(ops[i][1]!=-1) num=num*ops[i][1];
            else num=num*num;
            num=num/3;
            if(num%test[i][0]==0) monkeys[test[i][1]].push(num);
            else monkeys[test[i][2]].push(num);
            nums[i]++;
        }
    }
    // for(auto it:nums) cerr<<it<<" "; cerr<<"\n";
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0; string s;
    fstream fin("day11.txt", fstream::in);
    vector<queue<int>> monkeys;
    vector<vector<int>> ops,test;
    while(getline(fin, s)) {
        queue<int> q; vector<int> a(2,0),b(3,0);
        for(int i=0;i<5;i++) {
            getline(fin, s);
            if(i==0) {
                int ctr=18;
                while(ctr<s.length()) { q.push(get_num(s,ctr)); ctr+=2; }
            }
            else if(i==1) {
                if(s[23]=='+') a[0]=0;
                else a[0]=1;
                if(s[25]=='o') a[1]=-1;
                else { int ctr=25; a[1]=get_num(s,ctr); }
            }
            else if(i==2) { int ctr=21; b[0]=get_num(s,ctr); }
            else if(i==3) { int ctr=29; b[1]=get_num(s,ctr); }
            else { int ctr=30; b[2]=get_num(s,ctr); }
        }
        monkeys.push_back(q);
        ops.push_back(a);
        test.push_back(b);
        getline(fin, s);
    }
    // for(int i=0;i<ops.size();i++) cerr<<test[i][0]<<" "<<test[i][1]<<" "<<test[i][2]<<"\n";
    vector<int> nums(monkeys.size(),0);
    for(int i=0;i<20;i++) round(monkeys,ops,test,nums);
    for(auto it:monkeys) cerr<<it.size()<<" "; cerr<<"\n";
    // for(auto it:nums) cerr<<it<<" "; cerr<<"\n";
    sort(nums.rbegin(),nums.rend());
    cout<<(nums[0]*nums[1])<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

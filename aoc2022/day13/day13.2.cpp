#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int i)
{
    int num=0;
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    return num;
}

void make_tree(string& s,int i,int id,vector<int>& mapping,vector<vector<int>>& ans,vector<int>& nodes)
{
    // cerr<<"here "<<i<<"\n";
    if(i>=s.length()) return;
    else if(s[i]=='[') {
        int cur=ans.size();
        if(id>-1 && id<ans.size()) { ans[id].push_back(cur); ans.push_back({id}); }
        else ans.push_back({});
        nodes.push_back(-1);
        int j=i+1;
        while(i<mapping.size() && j<mapping[i]) {
            make_tree(s,j,cur,mapping,ans,nodes);
            if(j<mapping.size()) j=mapping[j]+2;
        }
    }
    else {
        int num=read_num(s,i),cur=ans.size();
        if(id>-1 && id<ans.size()) { ans[id].push_back(cur); ans.push_back({id}); }
        else ans.push_back({});
        nodes.push_back(num);
    }
    return;
}

vector<int> mapping(string s)
{
    int n=s.length();
    vector<int> ans(n,-1); stack<int> st;
    for(int i=0;i<n;i++) {
        if(s[i]=='[') st.push(i);
        else if(s[i]==']') {
            if(!st.empty()) { ans[st.top()]=i; st.pop(); }
        }
        else if(s[i]>='0' && s[i]<='9') {
            if(s[i-1]<'0' || s[i-1]>'9') st.push(i);
            if((s[i+1]<'0' || s[i+1]>'9') && !st.empty()) { ans[st.top()]=i; st.pop(); }
        }
    }
    return ans;
}

int compare(vector<vector<int>>& tree1,vector<vector<int>>& tree2,vector<int>& nodes1,vector<int>& nodes2,int i,int par1,int j,int par2)
{
    if(i>=nodes1.size() || j>=nodes2.size()) return 1;
    else if(nodes1[i]!=-1 && nodes2[j]!=-1) {
        if(nodes1[i]<nodes2[j]) return 0;
        else if(nodes1[i]>nodes2[j]) return 2;
        else return 1;
    }
    else if(nodes2[j]!=-1) {
        int cur=tree2.size();
        tree2.push_back({j}); tree2[j].push_back(cur);
        nodes2.push_back(nodes2[j]);
        nodes2[j]=-1;
    }
    else if(nodes1[i]!=-1) {
        int cur=tree1.size();
        tree1.push_back({i}); tree1[i].push_back(cur);
        nodes1.push_back(nodes1[i]);
        nodes1[i]=-1;
    }
    int cur1=0,cur2=0;
    while(cur1<tree1[i].size() && cur2<tree2[j].size()) {
        if(tree1[i][cur1]==par1 && tree2[j][cur2]==par2) { cur1++; cur2++; continue; }
        else if(tree1[i][cur1]==par1) { cur1++; continue; }
        else if(tree2[j][cur2]==par2) { cur2++; continue; }
        else {
            int p=compare(tree1,tree2,nodes1,nodes2,tree1[i][cur1],i,tree2[j][cur2],j);
            if(p==0) return 0;
            else if(p==2) return 2;
            else { cur1++; cur2++; }
        }
    }
    if(cur1==tree1[i].size() && cur2==tree2[j].size()) return 1;
    else if(cur1==tree1[i].size()) return 0;
    else return 2;
}

void print_tree(vector<vector<int>>& tree,vector<int>& nodes)
{
    for(int i=0;i<tree.size();i++) {
        cerr<<nodes[i]<<" ";
        for(auto it:tree[i]) cerr<<it<<" ";
        cerr<<"\n";
    }
    cerr<<"\n";
    return;
}

bool check(string s,string p)
{
    vector<vector<int>> tree1,tree2;
    vector<int> nodes1,nodes2;
    vector<int> map1=mapping(s),map2=mapping(p);
    // for(auto it:map1) cerr<<it<<" ";
    make_tree(s,0,-1,map1,tree1,nodes1);
    make_tree(p,0,-1,map2,tree2,nodes2);
    // print_tree(tree1,nodes1);
    // print_tree(tree2,nodes2);
    int result=compare(tree1,tree2,nodes1,nodes2,0,-1,0,-1);
    // cerr<<result<<" ";
    if(result<2) return true;
    else return false;
    // return true;
}

void bubble_sort(vector<string>& data)
{
    int n=data.size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(check(data[j],data[j+1])==false) {
                string x=data[j];
                data[j]=data[j+1];
                data[j+1]=x;
            }
        }
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day13.txt", fstream::in);
    vector<string> data;
    data.push_back("[[2]]");
    data.push_back("[[6]]");
    while(getline(fin, s)) {
        data.push_back(s);
        // cerr<<s<<"\n"<<p<<"\n";
        getline(fin, s);
        data.push_back(s);
        getline(fin, s);
        // cerr<<"here"<<"\n";
    }
    bubble_sort(data);
    int ans=1;
    for(int i=0;i<data.size();i++) {
        // cerr<<data[i]<<"\n";
        if(data[i]=="[[2]]" || data[i]=="[[6]]") ans=ans*(i+1);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}

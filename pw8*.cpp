// https://binarysearch.com/problems/Longest-Strictly-Increasing-Then-Decreasing-Sublist
int solve(vector<int>&v) {
    int n=v.size(),ans=0,flag=1,id=-1,i=1;
    while(i<n)
    {
        int id=i;
        while(id<n and v[id]>v[id-1])
            id++;
        if(id==i)
        {
            i++;
            continue;
        }
        if(id==n)
            break;
        int x=id;
        while(id<n and v[id]<v[id-1])
            id++;
        if(id>x)
            ans=max(ans,id-i+1);
        i=id;
    }
    return ans;
}
// https://binarysearch.com/problems/K-Unique-String
int solve(string s, int k) {
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++)
        mp[s[i]]++;
    if(mp.size()<=k)
        return 0;
    vector<int>v;
    for(auto it:mp)
        v.push_back(it.second);
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<v.size()-k;i++)
        ans+=v[i];
    return ans;
}
// https://binarysearch.com/problems/Number-of-Fractions-that-Sum-to-1
int solve(vector<vector<int>>&v) {
    map<vector<int>,int>mp;
    int ans=0,sum=0;
    for(int i=0;i<v.size();i++)
    {
        int x=__gcd(v[i][0],v[i][1]);
        while(x!=1)
        {
            v[i][0]/=x;
            v[i][1]/=x;
            x=__gcd(v[i][0],v[i][1]);
        }
        if(v[i][0]==1 and v[i][1]==2)
            sum++;
        else
            mp[{v[i][0],v[i][1]}]++;
    }
    for(auto it:mp)
    if(mp.find({it.first[1]-it.first[0],it.first[1]})!=mp.end())
        ans+=it.second*mp[{it.first[1]-it.first[0],it.first[1]}];
    ans/=2;
    ans+=sum*(sum-1)/2;
    return ans;
}
// https://leetcode.com/problems/candy/submissions/
int candy(vector<int>&A) {
    int n=A.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
        v.push_back({A[i],i});
    sort(v.begin(),v.end());
    vector<int>w(n,1);
    for(int i=0;i<n;i++)
    {
        if(v[i].second-1>=0 and A[v[i].second-1]<v[i].first)
            w[v[i].second]=w[v[i].second-1]+1;
        if(v[i].second+1<n and A[v[i].second+1]<v[i].first and w[v[i].second]<=w[v[i].second+1])
            w[v[i].second]=w[v[i].second+1]+1;
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=w[i];
    return ans;
}
// https://binarysearch.com/problems/Repeated-Deletion-Sequel
string solve(string s, int k) {
    if(k==1)
        return "";
    stack<pair<char,int>>st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty() or st.top().first!=s[i])
            st.push({s[i],1});
        else if(st.top().first==s[i])
        {
            auto it=st.top();
            st.pop();
            it.second++;
            if(it.second<k)
                st.push(it);
        }
    }
    string ans="";
    while(!st.empty())
    {
        auto it=st.top();
            st.pop();
        while(it.second>0)
        {
            ans+=it.first;
            it.second--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
// https://binarysearch.com/problems/Longest-Repeating-Sublist-After-K-Updates*****
int solve(vector<int>&v, int k) {
    unordered_map<int,int>mp;
    multiset<int>s;
    int ans=0,j=0;
    for(int i=0;i<v.size();i++)
    {
        mp[v[i]]++;
        s.insert(mp[v[i]]);
        int x=*s.rbegin();
        while((x+k) < (i-j+1))
        {
             auto it2=s.lower_bound(mp[v[j]]);
            s.erase(it2);
            mp[v[j]]--;
            if(mp[v[j]]>0)
                s.insert(mp[v[j]]);
            x=*s.rbegin();
            j++;
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}

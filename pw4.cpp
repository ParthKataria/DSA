// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
long long merge(long long arr[],long long temp[],int l,int md,int r)
{
    if(l==r)
        return 0;
    long long a=l,b=md,c=l,sum=0;
    while(a<md && b<=r)
    {
        if(arr[a]<=arr[b])
            temp[c++]=arr[a++];
        else
        {
            sum+=md-a;
            temp[c++]=arr[b++];
        }
    }
    while(a<md)
        temp[c++]=arr[a++];
    while(b<=r)
        temp[c++]=arr[b++];
    for(int i=l;i<=r;i++)
        arr[i]=temp[i];
    return sum;
}
long long merge_sort(long long arr[],long long temp[],int l,int r)
{
    if(l>=r)
        return 0;
    int md=(l+r)/2;
    long long x=merge_sort(arr,temp,l,md);
    long long y=merge_sort(arr,temp,md+1,r);
    long long z=merge(arr,temp,l,md+1,r);
    return x+y+z;
}
long long int inversionCount(long long arr[], long long n)
{
    long long temp[n];
    return merge_sort(arr,temp,0,n-1);
}
// https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1#
vector<pair<int,int>> allPairs(int A[], int B[], int n, int m, int X)
    {
        sort(A,A+n);
        sort(B,B+m);
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
            if(binary_search(B,B+m,X-A[i]))
                ans.push_back({A[i],X-A[i]});
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0#
#include <bits/stdc++.h>
using namespace std;
static bool compare(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second>p2.second)
        return true;
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return false;
}
int main() {
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mp[x]++;
        }
        vector<pair<int,int>>m;
        for(auto it:mp)
            m.push_back({it.first,it.second});
        sort(m.begin(),m.end(),compare);
        for(int i=0;i<m.size();i++)
            while(m[i].second>0)
            {
                cout<<m[i].first<<" ";
                m[i].second--;
            }
       cout<<endl;
    }
    return 0;
}
// https://practice.geeksforgeeks.org/problems/common-elements5420/1#
vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        vector<int>v;
        int n=v1.size(),m=v2.size(),i=0,j=0;
        while(i<n and j<m)
        {
            if(v1[i]==v2[j])
            {
                v.push_back(v1[i]);
                i++;
                j++;
            }
            else if(v1[i]>v2[j])
                j++;
            else
                i++;
        }
        return v;
    }
// https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1#
int findSwapValues(int A[], int n, int B[], int m)
    {
        sort(A,A+n);
        sort(B,B+m);
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
            sum1+=A[i];
        for(int i=0;i<m;i++)
            sum2+=B[i];
        int i=0,j=0;
        while(i<n and j<m)
            {
                int x=sum1-A[i]+B[j];
                int y=sum2-B[j]+A[i];
                if(x==y)
                    return 1;
                if(x<y)
                    j++;
                else
                    i++;
            }
        return -1;
    }
// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1,a1+n);
    for(int i=0;i<m;i++)
        if(!binary_search(a1,a1+n,a2[i]))
            return "No";
    return "Yes";
}
// https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1#
 int minIndexChar(string str, string patt)
    {
        map<char,int>mp;
        for(int i=0;i<patt.size();i++)
            if(mp.find(patt[i])==mp.end())
                mp[patt[i]]=i;
        int mx=INT_MAX;
        for(int i=0;i<str.size();i++)
            if(mp.find(str[i])!=mp.end())
                mx=min(mx,i);
        if(mx<INT_MAX)
            return mx;
        return -1;
    }
// https://practice.geeksforgeeks.org/problems/check-frequencies4211/1#
bool sameFreq(string s)
    {
        map<char,int>m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
       map<int,int>mp;
       for(auto it:m)
            mp[it.second]++;
       if(mp.size()>=3)
            return false;
       if(mp.size()==2)
       {
           vector<vector<int>>v;
           for(auto it:mp)
            v.push_back({it.first,it.second});
            if(v[0][1]>1 and v[1][1]>1)
                return false;
           if(v[1][1]==1 and (v[1][0]-1==v[0][0] or v[1][0]-1==0))
                return true;
           if(v[0][1]==1 and (v[0][0]-1==v[1][0] or v[0][0]-1==0))
                return true;
           return false;
       }
       return true;
    }

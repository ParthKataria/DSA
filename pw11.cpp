// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
int removeDuplicates(vector<int>&v) {
        int i=1,j=0,n=v.size();
        if(n<=1)
            return n;
        while(i<n and v[i]!=v[i-1])
            i++;
        j=i;
        while(i<n)
        {
            while(i<n and v[i]==v[i-1])
                i++;
            if(i<n)
            {
                v[j]=v[i];
                j++;
            }
            i++;
        }
        return j;
    }
// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1#
vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++)
            mp[A[i]]++;
        ans.push_back(mp.size());
        int j=0;
        for(int i=k;i<n;i++)
        {
            mp[A[i]]++;
            mp[A[j]]--;
            if(mp[A[j]]==0)
                mp.erase(A[j]);
            ans.push_back(mp.size());
            j++;
        }
        return ans;
    }
// https://leetcode.com/problems/search-a-2d-matrix/submissions/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=0;
        while(i<matrix.size() and j<matrix[0].size())
        {
            if(matrix[i][j]==target)
                return true;
            else if(i<matrix.size()-1 and matrix[i+1][j]<=target)
                i++;
            else if(j<matrix[0].size()-1 and matrix[i][j+1]<=target)
                j++;
            else
            return false;
        }
        return false;
    }
// https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/
int numberOfSubarrays(vector<int>&v, int k) {
        unordered_map<int,int>mp;
        int ans=0,j=0,sum=0,n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]%2)
                sum++;
            if(sum==k)
                ans++;
            if(mp.find(sum-k)!=mp.end())
                ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1
vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<N;i++)
            mp[A1[i]]++;
        for(int i=0;i<M;i++)
            if(mp.find(A2[i])!=mp.end())
                while(mp[A2[i]]>0)
                {
                    ans.push_back(A2[i]);
                    mp[A2[i]]--;
                }
        for(auto it:mp)
            while(it.second>0)
            {
                ans.push_back(it.first);
                it.second--;
            }
        return ans;
    } 
// https://leetcode.com/problems/number-of-matching-subsequences/
int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0,n=words.size();
        map<char,set<int>>mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]].insert(i);
        for(int i=0;i<n;i++)
        {
            int j=-1,k;
            for(k=0;k<words[i].size();k++)
            {
                if(mp.find(words[i][k])==mp.end())
                    break;
                auto it=mp[words[i][k]].upper_bound(j);
                if(it==mp[words[i][k]].end())
                    break;
                j=*it;
            }
            if(k==words[i].size())
                ans++;
        }
        return ans;
    }
// https://leetcode.com/problems/max-points-on-a-line/solution/
int maxPoints(vector<vector<int>>&v) {
        int n=v.size(),ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[v[i][0]]++;
            ans=max(ans,mp[v[i][0]]);
        }    
        for(int i=0;i<n-1;i++)
        {
            map<vector<int>,int>m;
            for(int j=i+1;j<n;j++)
            {
                int a=v[j][1]-v[i][1],b=v[j][0]-v[i][0],c=v[j][0]*v[i][1]-v[i][0]*v[j][1],d=b,e=0;
                if(b!=0)
                {
                    if(a*b<0)
                        e=1;
                    a=abs(a),b=abs(b),c=abs(c),d=abs(d);
                    int l=__gcd(a,b),q=__gcd(c,d);
                    while(l>1)
                    {
                        a/=l;
                        b/=l;
                        l=__gcd(a,b);
                    }
                    while(q>1)
                    {
                        c/=q;
                        d/=q;
                        q=__gcd(c,d);
                    }
                    m[{a,b,c,d,e}]++;
                    ans=max(ans,m[{a,b,c,d,e}]+1);
                }
            }
        }
        return ans;
    }
// https://leetcode.com/problems/longest-repeating-character-replacement/submissions/
int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size(),j=0,ans=0,mx=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            mx=max(mx,mp[s[i]]);
            while(mx+k<i-j+1)
            {
                mp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }

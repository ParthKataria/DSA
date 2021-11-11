// https://leetcode.com/problems/unique-number-of-occurrences/submissions/
bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m,m1;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        for(auto it:m)
            m1[it.second]++;
        for(auto it:m1)
            if(it.second>1)
                return false;
        return true;
    }
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/submissions/
 int countCharacters(vector<string>& words, string chars) {
        vector<int>m(26);
        for(int i=0;i<chars.size();i++)
            m[chars[i]-'a']++;
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            unordered_map<char,int>mp;
            for(int j=0;j<words[i].size();j++)
                mp[words[i][j]]++;
            int flag=1;
            for(auto it:mp)
                if(m[it.first-'a']<it.second)
                {
                    flag=0;
                    break;
                }    
            if(flag)
                ans+=words[i].size();
        }
        return ans;
    }
// https://leetcode.com/problems/find-common-characters/submissions/
vector<string> commonChars(vector<string>& words) {
        vector<int>v(26,1e8);
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            vector<int>w(26);
            for(int j=0;j<words[i].size();j++)
                w[words[i][j]-'a']++;
            for(int j=0;j<26;j++)
                v[j]=min(v[j],w[j]);
        }
        vector<string>ans;
        for(int i=0;i<26;i++)
            while(v[i]>0)
            {
                string c="";
                c+='a'+i;
                ans.push_back(c);
                v[i]--;
            }
        return ans;
    }
// https://leetcode.com/problems/uncommon-words-from-two-sentences/submissions/
vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        string a="";
        int i=0,n=s1.size();
        while(i<n)
        {
            if(s1[i]>' ')
                a+=s1[i];
            else
            {
                mp[a]++;
                a="";
            }
            i++;
        }
        if(a.size()>0)
        {
            mp[a]++;
            a="";
        }    
        int m=s2.size(),j=0;
        while(j<m)
        {
            if(s2[j]>' ')
                a+=s2[j];
            else
            {
                mp[a]++;
                a="";
            }
            j++;
        }
        if(a.size()>0)
        {
            mp[a]++;
            a="";
        }  
        vector<string>ans;
        for(auto it:mp)
            if(it.second==1)
                ans.push_back(it.first);
        return ans;
    }
// https://leetcode.com/problems/longest-palindrome/submissions/
int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        int odd=0,sum=0;
        for(auto it:mp)
        {
            sum+=2*(it.second/2);
            if((it.second%2)==1)
                odd=1;
        }
        return odd+sum;
    }
// https://leetcode.com/problems/jewels-and-stones/submissions/
int numJewelsInStones(string jewels, string stones) {
        map<char,int>mp;
        for(int i=0;i<jewels.size();i++)
            mp[jewels[i]]=1;
        int ans=0;
        for(int i=0;i<stones.size();i++)
            if(mp.find(stones[i])!=mp.end())
                ans++;
        return ans;
    }
// https://leetcode.com/problems/happy-number/submissions/***********
int func(int n)
    {
        int x=0;
        while(n)
        {
            int y=n%10;
            n/=10;
            x+=y*y;
        }
        return x;
    }
bool isHappy(int n) {
        set<int> st;
        while (1)
        {
            n = func(n);
            if (n == 1)
                return true;
            if (st.find(n) != st.end())
                return false;
            st.insert(n);
        }
    }

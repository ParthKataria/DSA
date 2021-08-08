// Sort array having 0,1 and 2
void sort012(int a[], int n)
    {
        int l=0,md=0,h=n-1;
        while(md<h)
        {
            if(a[md]==0)
                swap(a[l++],a[md++]);
            else if(a[md]==1)
                md++;
            else if(a[md]==2)
                swap(a[md],a[h--]);
        }
    }
// group array in neagtive and positive
void rearrange(vector<int>&v)
{
	int l=0,h=v.size()-1;
	while(l<=h)
	{
		if(v[l]<0 and v[h]<0)
			l++;
		else if(v[l]<0 and v[h]>0)
		{
		    l++;
		    h--;
		}
		else if(v[l]>0 and v[h]<0)
			swap(v[l],v[h--]);
		else
		    h--;
	}
}

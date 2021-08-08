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

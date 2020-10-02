bool sorted(int ar[], int n)
{
   if(n==0 || n==1)
        return true;
    
    if(ar[0] < ar[1] and sorted(ar+1, n-1))
    {
        return true;
    }
    return false;


}
 int k=0;
    for(int i=0;i<c;i++)
    {
        if(input[i] == ' ')
        {
            for(int j=i-1;j>=k;j--)
            {
                char temp ;
                temp = input[j];
                input[j] = input[k-j];
                input[k-j] = temp;
            }
            k = i;
        }
        else 
            continue;
    }
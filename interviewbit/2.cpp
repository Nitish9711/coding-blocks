 while(cnt < B && e < n){
        if(m[ar[e]].isp== false){
            m[ar[e]].isp = true;
            cnt++;
            e++;
        }
        else{
           e++; 
        }
    }
    if(e == n && cnt == 0)
        return 0;
    ans =1;
    cout<<s<<" "<<e<<endl;
    while(e<n){
      if(m[ar[e]].isp == true){
         ans++; 
         e++;
      }  
      
      else if(m[ar[e]].isp == false){
         m[ar[s]].isp = false;
         s++;
         ans++;
         m[ar[e]].isp = true;
         e++;
      }
      cout<<s<<" "<<e<<endl;
    }
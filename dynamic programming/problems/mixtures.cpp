// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.
// You can find the original problem here.

// Input Format
// The first line of each input file will contain n, the number of mixtures. The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

// Constraints
// 1 <= n <= 100

// Output Format
// Output the minimum amount of smoke.

// Sample Input
// 3
// 40 60 20
// Sample Output
// 2400
// Explanation
// There are two possibilities: first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400. first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400. The first scenario is a much better way to proceed.

// The first thing to notice here is that if we mix mixtures i..j into a single mixture, irrespective of the steps taken to achieve this, the final color of the mixture is same and equal to sum(i, j) = sum(color[i]..color[j]) mod 100.
// So, we define dp(i,j) as the most optimum solution where least amount of smoke is produced while mixing the mixtures from i..j intro a single mixture, For achieving this, at the previous steps, we would have had to combine the two mixtures which are resultant of the range i..k and k+1..j where i<=k<=j.
// So, its about splitting the mixture into 2 subsets and each subset into 2 more subsets and so on such that smoke produced is minimised, Hence the recurrence relation will be: dp(i,j) = min(k: i<= k < j) { dp(i,k)+dp(k+1, j)+sum(i,k)*sum(k+1,j) }



#include<bits/stdc++.h>
using namespace std;

long long n,i,j,a[110],dp[110][110],temp,k,l,sum[110][110];

int main(){
//    freopen("input5.txt","r",stdin);
//    freopen("output5.txt","w",stdout);
//    ios::sync_wth_stdio(0);

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++){
        sum[i][i]=temp = a[i];
        for(j=i+1;j<n;j++){
            temp += a[j];
            sum[i][j] = temp%100;
        }
    }
    for(i=0;i<n;i++)
        dp[i][i] = 0;
    for(j=1;j<n;j++){
        for(i=0;i<n-j;i++){
            dp[i][i+j] = INT_MAX;
            for(k=i;k<i+j;k++){
                dp[i][i+j] = min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+sum[i][k]*sum[k+1][i+j]);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";

    return 0;
}
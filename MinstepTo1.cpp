#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE METHOD USING RECURSSION
int countMinTo1(int n){
    if(n<=1){
        return 0;
    }
    int x = countMinTo1(n-1);
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%2==0){
        y = countMinTo1(n/2);
    }
    if(n%3==0){
        z = countMinTo1(n/3);
    }

    return min( x , min( y,z)) + 1 ;
}

//  Memoization Approach .. bottom to top
int countMinToOne_mem(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    // base case
    if(n<=1){
        return 0;
    }

    // check if number already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    // calculation part if number has come first time.
    int x = countMinToOne_mem(n-1);
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%2==0){
        y = countMinToOne_mem(n/2 );
    }
    if(n%3==0){
        z = countMinToOne_mem(n/3 );
    }

    int output = min( x , min( y,z)) +1;
    // save for future use
    ans[n] = output;
    return ans[n];
}

// DP krna hai


int countStepsToOne_DP(int n){
  int *minsteps = new int[n+1];
  minsteps[1]=0;
  for(int i=2;i<=n;i++){
    int substraction = minsteps[i-1];
    int DividebyTwo = INT_MAX;
    int DividebyThree = INT_MAX;
    if(i%2==0){
      DividebyTwo = minsteps[i/2];
    }
    if(i%3==0){
      DividebyThree = minsteps[i/3];
    }
    minsteps[i] = 1+ min(substraction , min(DividebyThree , DividebyTwo));
  }
  return minsteps[n];
}


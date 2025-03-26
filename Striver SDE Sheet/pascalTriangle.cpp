#include<bits/stdc++.h>
using namespace std;

// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
//variation 1 - > to find a element in the pascal triangle

//brute force - > find n! r! and (n-r)!

int factorial(int n){
    int result = 1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    return result;
}

int bruteForceSolution(int row,int col){
    int ans = 0;
    ans =  factorial(row-1)/(factorial(col-1)*factorial(row-col));
    return ans;
    
}

int optimalApproach(int n,int r){
    int ans = 1;
    for(int i=0;i<r;i++){
        ans = ans * (n-i);
        ans = ans / (i+1);
    }
    return ans;
}

//variation 2 - > find the nth row of pascal triangle 

//approach 1 - find all the row through the brute force approach

void bruteForceSolution2(int n){
    for(int i=1;i<=n;i++){
        cout<<bruteForceSolution(n,i)<<" ";
    }
}

void optimalApproach2(int n){
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans = ans * (n-i);
        ans = ans / i;
        cout<<ans<<" ";
    }
    cout<<endl;
}

void fullPascalTriangle(int n){
    for(int i=1;i<=n;i++){
        optimalApproach2(i);
    }
}
int main(){
    int row=  5;
    int col =3;
    cout<<bruteForceSolution(row,col)<<endl;
    cout<<optimalApproach(row-1,col-1)<<endl;
    bruteForceSolution2(5);
    cout<<endl;
    optimalApproach2(5);
    fullPascalTriangle(5);
    return 0;
}
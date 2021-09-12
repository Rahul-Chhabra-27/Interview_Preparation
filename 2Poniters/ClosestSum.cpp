#include<bits/stdc++.h>

using namespace std;

//Time complexity is O(n+m) and space complexity is constant..
int closestSum(vector<int> A,vector<int>B,int n,int m,int k) {

    if( n == 0 or m == 0){
        return 0;
    }
    else {
        int i = 0;
        int j = m-1;
        int closestSum = INT_MAX;
        while(i < n and j >= 0) {
            int currentSum = A[i] + B[j];
            if(currentSum > k) {
                if(abs(currentSum-k) < abs(closestSum-k)) {
                    closestSum = currentSum;
                }
                j--;
            } 
            else if(currentSum == k){
                closestSum = k;
                return closestSum;
            }
            else {
                if(abs(currentSum-k) < abs(closestSum-k)) {
                    closestSum = currentSum;
                }
                i++;
            }
        }
        return closestSum;
    }
}
int main(int argc, char const *argv[])
{
    
    int n , m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    vector<int> B(m);
    for(int i = 0;i<n;i++) cin>>A[i];
    for(int i = 0;i<m;i++) cin>>B[i];
    cout << closestSum(A,B,n,m,k) << " \n";
    return 0;
}

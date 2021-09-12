#include<bits/stdc++.h>
#define ll long long int

using namespace std;
// Time complexity is O(n);
void slidingWindowMaximum( vector<ll> nums,int n,int k) {
    
    if(n < k) {
        return;
    }

    deque<ll> window;
    for(int i = 0;i<k;i++) {
        while(!window.empty() and nums[window.back()] <= nums[i]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    vector<ll> maximums;

    for(int i = k;i<n;i++) {
        // print the maximum element of recent window
        maximums.push_back(nums[window.front()]);

        // validate front index...
        if(window.front() <= i-k) {
            window.pop_front();
        }

        while(!window.empty() and nums[window.back()] <= nums[i]) {
            window.pop_back();
        }

        window.push_back(i);
    }
    maximums.push_back(nums[window.front()]);

    for(int i : maximums) cout << i << " ";
    cout << "\n";
}
int main() {

    int n,k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(int i = 0;i<n;i++) cin >>nums[i];
    slidingWindowMaximum(nums,n,k);
}
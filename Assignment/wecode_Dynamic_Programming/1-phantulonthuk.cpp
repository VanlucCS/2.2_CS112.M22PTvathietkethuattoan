#include<iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <climits>
using namespace std;
vector<int> arr;
int n, k;
int count(vector <int>& arr, int& mid)
{
        int c = 0;
         
        for(int i = 0; i < arr.size(); i++)
           if(arr[i] <= mid)
              c++;
        return c;
}
 
int kbiggest(vector <int> nums, int& k)
{
        int l = INT_MAX;
        int h = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            l = min(l, nums[i]);
            h = max(h, nums[i]);
        }
        while(l < h)
        {
            int mid = l + (h - l) / 2;
            if(count(nums, mid) < n - k + 1)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
}
 
int main()
{
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i <n ; i++)
        cin >> arr[i];
    cout<<kbiggest(arr, k)<<endl;
    return 0;
}
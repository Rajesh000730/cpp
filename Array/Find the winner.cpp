//https://leetcode.com/problems/find-the-winner-of-an-array-game

class Solution{
	public:
		int winner(vector<int>&arr, int k){
			int n = arr.size();
			int ans = 0;
			int j = 1;
			map<int,int>mp;
			int maxi = *max_element(arr.begin(),arr.end());
			while(1){
				if(maxi == arr[0]){
					if(ans < k){
						ans = maxi;
						break;
					}
				}
				if(j == n) j = 1;	
				if(arr[0] < arr[j]){
					swap(arr[0], arr[j]);
				}
				mp[arr[0]]++;
				ans = max(mp[arr[0]], ans);
				if(ans == k){
					ans = arr[0];
					break;
				}
				j++;
				}
			return ans;
		}

};


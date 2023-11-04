class Solution{
	public:
		int maxPoints(vector<vector<int>>& points){
			int m = points.size();
			if(m==1) return 1;
			int ans = -1;
			for(int i = 0; i < m - 1;i++){
				unordered_map<double,int>mp;
				double slope;
				for(int j = i+1;j < m;j++){
					if( points[j][0] - points[i][0] == 0){
						mp[90]++;
						break;
					}
					double num = points[j][1] - points[i][1];
					double den = points[j][0] - points[i][0];
	
					slope = num/den;
					mp[slope]++;
					ans = max(ans, mp[slope]);
	
				}
			}
			return ans+1;
		}
};

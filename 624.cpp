int maxDistance(vector<vector<int>>& arrays) {
        int minValue=arrays[0][0], maxValue=arrays[0].back(), maxDistance=0;
        for(int i=1; i<arrays.size(); i++){
            maxDistance=max(maxDistance, abs(minValue-arrays[i].back()));
            maxDistance=max(maxDistance, abs(maxValue-arrays[i][0]));

            minValue=min(minValue, arrays[i][0]);
            maxValue=max(maxValue, arrays[i].back());
        }
        return maxDistance;
}

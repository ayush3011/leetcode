class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // // Brute force - O(m*n)
        // for(int i=0; i<matrix.size(); i++){ 
        //     for(int j=0; j<matrix[i].size(); j++){
        //         if(matrix[i][j]==target)  return true;
        //     }
        // }
        // return false;

        // // Using matrix like a binary search tree starting from the top right of the matrix - O(m+n)
        // int n=matrix.size(), m=matrix[0].size(), row=0, col=m-1; // finding rows and columns and setting the current element to the top right element

        // while(row<=n-1 && col>=0){
        //     int cur=matrix[row][col];
        //     if(cur==target) return true;
        //     if(target>cur) row++; // shifting down
        //     else col--;
        // }
        // return false;
    

        // Binary Search Approac (!important) - O(logn)
        int n=matrix.size(), m=matrix[0].size();
        int l=0, h=(n*m)-1;

        while(l<=h){
            int mid = l + (h - l) / 2;

            if(matrix[mid/m][mid%m]==target) return true;
            else if(matrix[mid/m][mid%m]<target)
                l=mid+1;
            else
                h=mid-1;
        }   
        return false;
    }
};
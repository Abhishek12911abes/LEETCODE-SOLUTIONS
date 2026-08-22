class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int top=0,bottom=n-1;
        int left=0,right=m-1;

        int dir=0;

        vector<int>ans;

        while(top<=bottom && left<=right){
            if(dir==0){ // left se right constant-> row(top)
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){ // top se bottom constant-> col(right)
                for(int j=top;j<=bottom;j++){
                    ans.push_back(matrix[j][right]);

                }
                right--;
            }
            if(dir==2){ // right se left constant-->row(left)
                 for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                 }
                 bottom--;
            }
            if(dir==3){ // bottom se top constant -->col(bottom)
                for(int j=bottom;j>=top;j--){
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return ans;

    }
};
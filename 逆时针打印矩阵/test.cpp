class Solution 
{
public:
    void PrintMatrixInCircle(vector<vector<int>>& matrix,vector<int>& result,int row,int col,int start)
    {
        int end_x=col-1-start;
        int end_y=row-1-start;
        for(int i=start;i<=end_x;i++)
        {
            result.push_back(matrix[start][i]);
        }
        //从上到下打印一列
        if(start<end_y)
        {
            for(int i=start+1;i<=end_y;i++)
            {
                result.push_back(matrix[i][end_x]);
            }
        }
        //从右到左打印一行
        if(start<end_x&&start<end_y)
        {
            for(int i=end_x-1;i>=start;i--)
            {
                result.push_back(matrix[end_y][i]);
            }
        }
        //从下到上打印一列
        if(start<end_x&&start<end_y-1)
        {
            for(int i=end_y-1;i>=start+1;i--)
            {
                result.push_back(matrix[i][start]);
            }
        }
    }
    vector<int> printMatrix(vector<vector<int> > matrix) 
	{
        vector<int> result;
        if(matrix.empty())
        {
            return result;
        }
        for(auto e:matrix)
        {
            if(e.empty())
            {
                return result;
            }
        }
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0;
        while(start*2<row&&start*2<col)
        {
            PrintMatrixInCircle(matrix,result,row,col,start);
            start++;
        }
        return result;
    }
};
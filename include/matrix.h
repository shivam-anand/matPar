#include <vector>
#include <fstream>

typedef matrix vector<vector<int>>;

matrix getMatrix(ifsteam in,int count)
{
    matrix mat(count,vector<int> (count));

    for(int i = 0;i < count;++i)
    {
        for(int j = 0;j < count;++j)
        {
            in>>mat[i][j];
        }
    }
    return mat;
}

void printMatrix(ofstream out,const matrix &mat)
{
    int count = mat.size();

    for(int i = 0;i < count;++i)
    {
        for(int j = 0;j < count;++j)
        {
            out<<mat[i][j]<<' ';
        }
        out<<endl;
    }
}

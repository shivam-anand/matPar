#include <vector>
#include <fstream>

typedef std::vector<std::vector<int>> matrix;

matrix getMatrix(std::ifstream &in,int count)
{
    matrix mat(count,std::vector<int> (count));

    for(int i = 0;i < count;++i)
    {
        for(int j = 0;j < count;++j)
        {
            in>>mat[i][j];
        }
    }
    return mat;
}

void printMatrix(std::ofstream &out,const matrix &mat)
{
    int count = mat.size();

    for(int i = 0;i < count;++i)
    {
        for(int j = 0;j < count;++j)
        {
            out<<mat[i][j]<<' ';
        }
        out<<std::endl;
    }
}

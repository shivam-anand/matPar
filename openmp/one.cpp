#include <fstream>
#include <vector>
#include "../include/matrix.h"

using namespace std;

int main()
{
    ifstream in("in");

    int count;
    in>>count;

    matrix a = getMatrix(in,count);
    matrix b = getMatrix(in,count);
    matrix c(count,vector<int>(count));

    in.close();

    #pragma omp parallel for
    for(int i = 0;i < count;++i)
    {
        for(int j = 0;j < count;++j)
        {
            for(int k = 0;k<count;++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    ofstream out("out");
    printMatrix(out,c);
    out.close();

    return 0;
}

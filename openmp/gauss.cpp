#include <fstream>
#include "../include/matrix.h"

using namespace std;

int main()
{
    ifstream in("in");

    int count;
    in>>count;

    matrix a = getMatrix(in,count);
    vector<int> b(count);

    for(int i = 0;i < count;++i)
    {
        in>>b[i];
    }

    in.close();

    vector<int> y(count);

    for(int k = 0;k < count ;++k)
    {
        #pragma omp parallel for
        for(int j = k+1;j < count;++j)
        {
            a[k][j] = a[k][j]/a[k][k];
        }

        y[k] = b[k]/a[k][k];
        a[k][k] = 1;

        #pragma omp parallel for
        for(int i = k+1;i < count;++i)
        {
            for(int j = k+1;j < count;++j)
            {
                a[i][j] -= a[i][k] * a[k][j];
            }
            b[i] -= a[i][k] * y[k];
            a[i][k] = 0;
        }
    }

    ofstream out("out");
    printMatrix(out,a);

    for(int i = 0;i<count;++i)
    {
        out<<y[i]<<endl;
    }

    out.close();

    return 0;
}

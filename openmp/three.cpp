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

    int countCubed = count * count * count;
    int countSquared = count * count;

    #pragma omp parallel for
    for(int x = 0;x < countCubed;++x)
    {
        int i = x/countSquared;
        int j = (x%countSquared)/count;
        int k = x%count;

        #pragma omp atomic
            c[i][j] += a[i][k] * b[k][j];
    }

    ofstream out("out");
    printMatrix(out,c);
    out.close();

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <functional>

using namespace std;

const int generatedNumberMin = 1;
const int generatedNumberMax = 1000;

int stringToInt(char *str);

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        cerr<<"Usage: generator count\nGenerate an instance of gaussian\
        elimination problem of size count";

        return -1;
    }

    int count = stringToInt(argv[1]);

    ofstream out("in");

    out<<count<<endl;

    default_random_engine engine(time(NULL));
    uniform_int_distribution<int> dist(generatedNumberMin,generatedNumberMax);
    auto gen = bind(dist,engine);

    //The A matrix
    for(int i = 0;i<count;++i)
    {
        for(int j = 0;j<count;++j)
        {
            out<<gen()<<' ';
        }
        out<<endl;
    }
    //The b matrix
    for(int i = 0;i < count;++i)
    {
        out<<gen()<<endl;
    }

    out.close();

    return 0;
}

int stringToInt(char *str)
{
    istringstream in(str);
    int num;
    in>>num;
    return num;
}

#include "layer.h"
#include <cstdlib>

layer::layer(int nodeCount)
{
    srand(time(NULL));
    double nodes [nodeCount];
    
    for (double n : nodes)
    {
        n = rand()/RAND_MAX;
        //cout << n << endl;
    }
}

void layer::setNode(int index, double value)
{
    nodes[index] = value;
}
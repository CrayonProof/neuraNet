#pragma once
#include "layer.h"

layer::layer(int nodeCount)
{
    srand(time(NULL));
    double[nodeCount] nodes;
    
    for (double n : nodes)
    {
        n = srand();
        //cout << n << endl;
    }
}

layer::setNode(int index, double value)
{
    nodes[index] = value;
}
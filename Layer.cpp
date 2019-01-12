#include "Layer.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

Layer::Layer(int nodeCount)
{
    /*
    srand(time(NULL));
    
    for (double n : nodes)
    {
        n = rand()/RAND_MAX;
        //cout << n << endl;
    }
    */
}

Layer::Layer(std::vector<double> weights)
{
    this->weights = weights;
}

std::string Layer::toString()
{
    std::ostringstream s;
    for (double w : weights)
    {
        s << w << ",";
    }
    return s.str();
}

void Layer::setWeight(int index, double value)
{
    weights.at(index) = value;
}
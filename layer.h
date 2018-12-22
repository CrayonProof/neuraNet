#pragma once
#include<ctime>

class layer
{
    public:
    layer(int nodeCount);
    void setNode(int index, double value);
    private:
    double nodes [];
}
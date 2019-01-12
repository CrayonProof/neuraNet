#pragma once
#include<ctime>
#include<vector>
#include<string>

class Layer
{
    public:
    Layer(int nodeCount);
    Layer(std::vector<double> weights);
    void setWeight(int index, double value);
    std::string toString();
    private:
    std::vector<double> weights;
    std::vector<double> biases;
};
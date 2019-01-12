#include "Layer.h"
#include "Network.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

Network::Network()
{
    //idk do i even want a parametrized constructor?
}

Network::~Network()
{
    //idk do i even want a parametrized constructor?
}

Network::Network(std::string netFilename)
{
    //TODO: same functionality as load function
}

bool is_of_some(string encompassing_string, const string s){return s.find_first_not_of(encompassing_string) == std::string::npos;}
bool is_of_some(string encompassing_string, char c)
{
    string s;
    s = s + c;
    return s.find_first_not_of(encompassing_string) == std::string::npos;
}

void Network::initialize(std::string configFilename)
{
    fstream file;
    file.open(configFilename);
    int lineIndex = 0;
    std::string layerSize = "";
    std::string learningRateString = "";
    std::string biasesString = "";
    std::vector<int> layerSizes;
    double learningRate;
    bool biases;
    std::string s;
    char c;
    while (file >> noskipws >> c)
    {
        //std::cout << c << std::endl;
        if (lineIndex == 0)
        {
            if (c == '\n' || c == ' ' || c == ',')
            {
                if (layerSize != "")
                {
                    layerSizes.push_back(atof(layerSize.c_str()));
                    layerSize = "";
                }
            }
            if(is_of_some("1234567890", c))
            {
                layerSize = layerSize + c;
            }
        }
        else if (lineIndex == 1)
        {
            if (c == '\n' || c == ' ' || c == ',')
            {
                learningRate = (atof(learningRateString.c_str()));
            }
            if(is_of_some("1234567890.", c))
            {
                learningRateString = learningRateString + c;
            }
        }
        else if (lineIndex == 2)
        {
            if (c == '\n')
            {
                std::cout << "biasesString: " << biasesString << std::endl;
                if (biasesString == "biases: true")
                {
                    biases = true;
                }
                else
                {
                    biases = false;
                }
            }
            else
            {
                biasesString = biasesString + c;
            }
        }
        if (c == '\n')
        {
            lineIndex++;
        }
    }
    std::cout << "layerSizes: " << std::endl;
    for (int i : layerSizes)
    {
        std::cout << i << std::endl;
    }
    std::cout << "learningRate: " << learningRate << std::endl;
    std::cout << "biases: " << biases << std::endl;
}
void Network::load(std::string netFilename)
{
    fstream file;
    file.open(netFilename);
    bool config = true;
    string nodeWeight;
    int layerIndex = 0;
    vector<double> layer;
    char c;
    while (file >> noskipws >> c)
    {
        //std::cout << c << std::endl;
        if (!config)
        {
            
            if (c == ',' || c == ' ' || c == '\n')
            {
                //begin parsing next weight
                //std::cout << atof(nodeWeight.c_str()) << std::endl;
                if (nodeWeight != "")
                {
                    //std::cout << "string: " << nodeWeight << " --- " << "double: " << atof(nodeWeight.c_str()) << std::endl;
                    layer.push_back(atof(nodeWeight.c_str()));
                    nodeWeight = "";
                }
                if (c == '\n')
                {
                    //populate next layer
                    if (layer.size() > 0)
                    {
                        layers.push_back(new Layer(layer));
                        layer.clear();
                        layerIndex ++;
                    }
                }
            }
            else
            {
                nodeWeight = nodeWeight + c;
            }
        }
        if (c == '|')
        {
            config = false;
        }
    }
}

void Network::print()
{
    //std::cout << "loppers" << std::endl;
    int layerIndex = 0;
    for (Layer * l : layers)
    {
        std::cout << "layer " << layerIndex << ": "<< (*l).toString() << std::endl;
        layerIndex++;
    }
}
#pragma once
#include "Layer.h"
#include <string>

class Network
{
    public:
        Network();
       Network(std::string netFilename);
       ~Network();
       void load(std::string netFilename);
       void initialize(std::string configFilename);
       std::vector<double> run(std::string dataFilename);
       void print();
       
    private:
        std::vector<Layer*> layers;
    
};
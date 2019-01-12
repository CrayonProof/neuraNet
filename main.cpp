#include "Network.h"
#include <iostream>

int main()
{
    //createNet(netParameterFile) neurons in "[layer1, layer2, layer3, ...layer n]"
    //trainNet(networkFile, repititions, trainingDataset)
    //testNet(networkFile, repititions, testDataset)
    Network net;
    net.initialize("testNet_init.txt");
    //net.load("testNet_01.txt");
    //std::cout << "printing network..." << std::endl;
    //net.print();
    return 0;
}
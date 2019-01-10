#pragma once
#include "layer.h"

class network
{
    public :
    network(string netFilename);
    
    private:
    layer[] layers;
    
};
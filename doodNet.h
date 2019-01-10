#pragma once

class doodNet
{
    public:
    virtual doodNet();
    void newNet(string netFilename);
    void loadNet(string netFilename);
    private:
    double nodes [];
};
#pragma once

#include <vector>

class Main {
    public:
        std::vector<Carte *> main;
        std::vector<Carte *>::const_iterator begin() { return main.begin(); }
        std::vector<Carte *>::const_iterator end() { return main.end(); }        
};
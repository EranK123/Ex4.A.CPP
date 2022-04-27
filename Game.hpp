#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;
class Game{
         public:
         Game();
         static string turn();
         static vector<string > players();
         static string winner();    
};

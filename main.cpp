#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "server_side.h"

using namespace server_side;
using namespace std;

int main() {
    map <string , string> myMap;
    string line = "prob,sol";
    int k = (int) line.find(',');
    string key = line.substr(0, k);
    string value = line.substr(k + 1, line.size());
    myMap.insert(pair<string, string>(key, value));
    return 0;
}
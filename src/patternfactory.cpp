#include "patternfactory.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>

PatternFactory::PatternFactory()
{
    // Do nothing
}

Pattern PatternFactory::stringToPattern(const std::string str)
{
    // Parse input string to vector
    std::vector<std::string> stringVector;
    std::istringstream strStream(str);
    std::string temp;
    while (std::getline(strStream, temp, ';')) {
        stringVector.push_back(temp);
    }

    // Validate input string
    int numOfParams = stringVector.size();
    if (numOfParams < 4) {
        throw "ERROR: lack of parameter to create a pattern.";
    } else {
        if (numOfParams > 4) {
            std::cout << "WARN: redundant parameter will be ignored." << std::endl;
        }

        Pattern result;
        result.setId(std::atoi(stringVector[0].c_str()));
        std::cout << "Reading ID: " << result.getId() << std::endl;
        result.setName(stringVector[1]);
        std::cout << "Reading Name: " << result.getName() << std::endl;
        result.setPath(stringVector[2]);
        std::cout << "Reading Path: " << result.getPath() << std::endl;
        result.setFlag(stringVector[3] != "0");
        std::cout << "Reading Flag: " << result.getFlag() << std::endl;
        return result;
    }
    return Pattern();
}

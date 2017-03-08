#ifndef __PATTERNFACTORY__
#define __PATTERNFACTORY__

#include "pattern.h"

class PatternFactory
{
private:
    PatternFactory(); // prevent to create the instance of factory
public:
    static Pattern stringToPattern(const std::string str);
};

#endif

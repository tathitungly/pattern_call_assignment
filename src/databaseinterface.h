#ifndef __DATABASEINTERFACE__
#define __DATABASEINTERFACE__

#include <string>
#include <vector>
#include "pattern.h"

class DatabaseInterface
{
public:
    virtual void importDatabase(std::string fileName) = 0;
    virtual void exportDatabase(std::string fileName) = 0;
    virtual void addPattern(Pattern *pattern) = 0;
    virtual Pattern* getPatternById(int id) = 0;
    virtual std::vector<Pattern*> getPatternsByName(std::string name) = 0;
    virtual std::vector<Pattern*> getPatternsByPath(std::string path) = 0;
    virtual std::vector<Pattern*> getPatternsByFlag(bool flag) = 0;
};

#endif

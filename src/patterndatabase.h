#ifndef __PATTERNDATABASE__
#define __PATTERNDATABASE__

#include "databaseinterface.h"
#include <map>

class PatternDatabase: public DatabaseInterface
{
public:
    PatternDatabase();
    ~PatternDatabase();

    virtual void importDatabase(std::string fileName){};
    virtual void exportDatabase(std::string fileName){};
    virtual void addPattern(Pattern *pattern);
    virtual Pattern* getPatternById(int id);
    virtual std::vector<Pattern*> getPatternsByName(std::string name) { return std::vector<Pattern*>(); };
    virtual std::vector<Pattern*> getPatternsByPath(std::string path) { return std::vector<Pattern*>(); };
    virtual std::vector<Pattern*> getPatternsByFlag(bool flag) { return std::vector<Pattern*>(); };

private:
    std::map<int, Pattern*> data;
};

#endif

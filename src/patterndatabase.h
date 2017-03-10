#ifndef __PATTERNDATABASE__
#define __PATTERNDATABASE__

#include "databaseinterface.h"
#include <map>

class PatternDatabase: public DatabaseInterface
{
public:
    PatternDatabase();
    ~PatternDatabase();

    virtual void importDatabase(std::string fileName);
    virtual void exportDatabase(std::string fileName);
    virtual void addPattern(Pattern *pattern);
    virtual Pattern* getPatternById(int id);
    virtual std::vector<Pattern*> getPatternsByName(std::string name);
    virtual std::vector<Pattern*> getPatternsByPath(std::string path);
    virtual std::vector<Pattern*> getPatternsByFlag(bool flag);

private:
    std::vector<Pattern*> filterAsCondition(bool (PatternDatabase::*filter)(Pattern*, Pattern*), Pattern *sample);
    bool isSameName(Pattern *pat1, Pattern *pat2);
    bool isSamePath(Pattern *pat1, Pattern *pat2);
    bool isSameFlag(Pattern *pat1, Pattern *pat2);
    std::map<int, Pattern*> data;
};

#endif

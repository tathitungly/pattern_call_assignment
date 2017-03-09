#include "patterndatabase.h"

PatternDatabase::PatternDatabase()
{
}

PatternDatabase::~PatternDatabase()
{
    for(std::map<int, Pattern*>::iterator it = data.begin(); it != data.end(); ++it) {
        delete it->second;
    }
}

void PatternDatabase::addPattern(Pattern *pattern)
{
    if (pattern != NULL) {
        data[pattern->getId()] = pattern;
    }
}

Pattern* PatternDatabase::getPatternById(int id)
{
    std::map<int, Pattern*>::iterator it = data.find(id);
    if (it == data.end()) {
        return NULL;
    }
    return it->second;
}

#include <iostream>
#include <fstream>

#include "patterndatabase.h"
#include "patternfactory.h"

PatternDatabase::PatternDatabase()
{
}

PatternDatabase::~PatternDatabase()
{
    for(std::map<int, Pattern*>::iterator it = data.begin(); it != data.end(); ++it) {
        delete it->second;
    }
}

void PatternDatabase::importDatabase(std::string fileName)
{
    std::ifstream importFile(fileName.c_str());
    if (importFile.is_open()) {
        std::string line;
        while (getline(importFile,line))
        {
            Pattern *pattern = PatternFactory::stringToPattern(line);
            if (pattern != NULL) {
                this->addPattern(pattern);
                std::cout << "Pattern inserted: " << line << std::endl;
            } else {
                std::cout << "Wrong format: " << line << std::endl;
            }
        }
        importFile.close();
    } else {
        throw "Cannot open file for reading.";
    }
}

void PatternDatabase::exportDatabase(std::string fileName)
{
    std::ofstream exportFile(fileName.c_str());
    if (exportFile.is_open()) {
        for(std::map<int, Pattern*>::iterator it = data.begin(); it != data.end(); ++it) {
            exportFile << it->second->toString() << std::endl;
        }
        exportFile.close();
    } else {
        throw "Cannot open file for writing.";
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

std::vector<Pattern*> PatternDatabase::getPatternsByName(std::string name)
{
    Pattern sample;
    sample.setName(name);
    return filterAsCondition(&PatternDatabase::isSamePath, &sample);
};

std::vector<Pattern*> PatternDatabase::getPatternsByPath(std::string path)
{
    Pattern sample;
    sample.setPath(path);
    return filterAsCondition(&PatternDatabase::isSamePath, &sample);
};

std::vector<Pattern*> PatternDatabase::getPatternsByFlag(bool flag)
{
    Pattern sample;
    sample.setFlag(flag);
    return filterAsCondition(&PatternDatabase::isSameFlag, &sample);
};

std::vector<Pattern*> PatternDatabase::filterAsCondition(bool (PatternDatabase::*filter)(Pattern*, Pattern*), Pattern *sample)
{
    std::vector<Pattern*> result;
    for(std::map<int, Pattern*>::iterator it = data.begin(); it != data.end(); ++it) {
        if ((this->*filter)(it->second, sample)) {
            result.push_back(it->second);
        }
    }
    return result;
};

bool PatternDatabase::isSameName(Pattern *pat1, Pattern *pat2)
{
    return pat1->getName() == pat2->getName();
}

bool PatternDatabase::isSamePath(Pattern *pat1, Pattern *pat2)
{
    return pat1->getPath() == pat2->getPath();
}

bool PatternDatabase::isSameFlag(Pattern *pat1, Pattern *pat2)
{
    return pat1->getFlag() == pat2->getFlag();
}


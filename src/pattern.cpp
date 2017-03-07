#include "pattern.h"

Pattern::Pattern()
{
    id = 0;
    name = "";
    path = "";
    flag = false;
}

Pattern::Pattern(const int id, const std::string name, const std::string path, const bool flag)
{
    this->id = id;
    this->name = name;
    this->path = path;
    this->flag = flag;
}

void Pattern::setId(const int id)
{
    this->id = id;
}

int Pattern::getId() const
{
    return this->id;
}

void Pattern::setName(std::string name)
{
    this->name = name;
}

std::string Pattern::getName() const
{
    return this->name;
}

void Pattern::setPath(std::string path)
{
    this->path = path;
}

std::string Pattern::getPath() const
{
    return this->path;
}

void Pattern::setFlag(bool flag)
{
    this->flag = flag;
}

bool Pattern::getFlag() const
{
    return this->flag;
} 

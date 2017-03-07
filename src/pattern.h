#ifndef __PATTERN__
#define __PATTERN__

#include <string>

class Pattern {
private:
    int id;
    std::string name;
    std::string path;
    bool flag;
public:
    Pattern(const int id, const std::string name, const std::string path, const bool flag);
    Pattern();
    void setId(const int id);
    int getId() const;
    void setName(std::string name);
    std::string getName() const;
    void setPath(std::string path);
    std::string getPath() const;
    void setFlag(bool flag);
    bool getFlag() const; 
};

#endif

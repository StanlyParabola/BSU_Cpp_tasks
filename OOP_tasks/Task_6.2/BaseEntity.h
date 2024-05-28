#ifndef BASEENTITY_H
#define BASEENTITY_H

#include <iostream>

class BaseEntity {
public:
    BaseEntity(const char* type);
    virtual ~BaseEntity() {}

    virtual void Print() const = 0; // Чистый виртуальный метод

protected:
    char type[50];

    void copyString(char* dest, const char* src, size_t maxLen);
};

#endif // BASEENTITY_H

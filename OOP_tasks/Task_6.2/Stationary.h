#ifndef STATIONARY_H
#define STATIONARY_H

#include "BaseEntity.h"

class Stationary : public BaseEntity {
public:
    Stationary(const char* name, double temperature, bool hasSolidSurface);

    void Print() const override;

    // Геттеры и сеттеры
    const char* getName() const;
    double getTemperature() const;
    bool getHasSolidSurface() const;

    void setName(const char* name);
    void setTemperature(double temperature);
    void setHasSolidSurface(bool hasSolidSurface);

protected:
    char name[100];
    double temperature;
    bool hasSolidSurface;
};

class Star : public Stationary {
public:
    Star(const char* name, double temperature);

    void Print() const override;
};

class Planet : public Stationary {
public:
    Planet(const char* name, double temperature, bool hasSolidSurface);

    void Print() const override;
};

#endif // STATIONARY_H

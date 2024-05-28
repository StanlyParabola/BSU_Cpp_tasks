#ifndef MOVABLE_H
#define MOVABLE_H

#include "BaseEntity.h"

class Movable : public BaseEntity {
public:
    Movable(double x, double y, double z, double vx, double vy, double vz);

    void Print() const override;

    double getX() const;
    double getY() const;
    double getZ() const;
    double getVx() const;
    double getVy() const;
    double getVz() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setVx(double vx);
    void setVy(double vy);
    void setVz(double vz);

protected:
    double x, y, z; // Координаты
    double vx, vy, vz; // Скорости
};

class Asteroid : public Movable {
public:
    Asteroid(double x, double y, double z, double vx, double vy, double vz, double maxDiameter);

    void Print() const override;

    // Геттеры и сеттеры
    double getMaxDiameter() const;
    void setMaxDiameter(double maxDiameter);

private:
    double maxDiameter;
};

class SpaceShip : public Movable {
public:
    SpaceShip(const char* name, double x, double y, double z, double vx, double vy, double vz, double vmax, int ammo);

    void Print() const override;

    // Геттеры и сеттеры
    const char* getName() const;
    double getVmax() const;
    int getAmmo() const;

    void setName(const char* name);
    void setVmax(double vmax);
    void setAmmo(int ammo);

private:
    char name[100];
    double vmax;
    int ammo;
};

class Rocket : public Movable {
public:
    Rocket(double x, double y, double z, double vx, double vy, double vz, double explosivePower, double fuelTime);

    void Print() const override;

    // Геттеры и сеттеры
    double getExplosivePower() const;
    double getFuelTime() const;

    void setExplosivePower(double explosivePower);
    void setFuelTime(double fuelTime);

private:
    double explosivePower;
    double fuelTime;
};

#endif // MOVABLE_H

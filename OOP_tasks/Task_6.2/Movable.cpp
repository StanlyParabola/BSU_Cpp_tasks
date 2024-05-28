#include "Movable.h"

Movable::Movable(double x, double y, double z, double vx, double vy, double vz)
        : BaseEntity("Movable"), x(x), y(y), z(z), vx(vx), vy(vy), vz(vz) {}

void Movable::Print() const {
    std::cout << "Type: " << type << ", Coordinates: (" << x << ", " << y << ", " << z
              << "), Velocity: (" << vx << ", " << vy << ", " << vz << ")" << std::endl;
}

Asteroid::Asteroid(double x, double y, double z, double vx, double vy, double vz, double maxDiameter)
        : Movable(x, y, z, vx, vy, vz), maxDiameter(maxDiameter) {
    copyString(this->type, "Asteroid", sizeof(this->type));
}

void Asteroid::Print() const {
    Movable::Print();
    std::cout << "Max Diameter: " << maxDiameter << std::endl;
}

SpaceShip::SpaceShip(const char* name, double x, double y, double z, double vx, double vy, double vz, double vmax, int ammo)
        : Movable(x, y, z, vx, vy, vz), vmax(vmax), ammo(ammo) {
    copyString(this->type, "SpaceShip", sizeof(this->type));
    copyString(this->name, name, sizeof(this->name));
}

void SpaceShip::Print() const {
    Movable::Print();
    std::cout << "Name: " << name << ", Max Speed: " << vmax << ", Ammo: " << ammo << std::endl;
}

Rocket::Rocket(double x, double y, double z, double vx, double vy, double vz, double explosivePower, double fuelTime)
        : Movable(x, y, z, vx, vy, vz), explosivePower(explosivePower), fuelTime(fuelTime) {
    copyString(this->type, "Rocket", sizeof(this->type));
}

void Rocket::Print() const {
    Movable::Print();
    std::cout << "Explosive Power: " << explosivePower << ", Fuel Time: " << fuelTime << " seconds" << std::endl;
}

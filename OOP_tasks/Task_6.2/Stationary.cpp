#include "Stationary.h"

Stationary::Stationary(const char* name, double temperature, bool hasSolidSurface)
        : BaseEntity("Stationary"), temperature(temperature), hasSolidSurface(hasSolidSurface) {
    if (temperature < -273.15) {
        throw std::invalid_argument("Temperature cannot be below absolute zero");
    }
    copyString(this->name, name, sizeof(this->name));
}

void Stationary::Print() const {
    std::cout << "Type: " << type << ", Name: " << name << ", Temperature: " << temperature
              << ", Has Solid Surface: " << (hasSolidSurface ? "Yes" : "No") << std::endl;
}

const char* Stationary::getName() const {
    return name;
}

double Stationary::getTemperature() const {
    return temperature;
}

bool Stationary::getHasSolidSurface() const {
    return hasSolidSurface;
}

void Stationary::setName(const char* name) {
    copyString(this->name, name, sizeof(this->name));
}

void Stationary::setTemperature(double temperature) {
    if (temperature < -273.15) {
        throw std::invalid_argument("Temperature cannot be below absolute zero");
    }
    this->temperature = temperature;
}

void Stationary::setHasSolidSurface(bool hasSolidSurface) {
    this->hasSolidSurface = hasSolidSurface;
}

Star::Star(const char* name, double temperature)
        : Stationary(name, temperature, false) {
    copyString(this->type, "Star", sizeof(this->type));
}

void Star::Print() const {
    Stationary::Print();
    std::cout << "This is a star." << std::endl;
}

Planet::Planet(const char* name, double temperature, bool hasSolidSurface)
        : Stationary(name, temperature, hasSolidSurface) {
    copyString(this->type, "Planet", sizeof(this->type));
}

void Planet::Print() const {
    Stationary::Print();
    std::cout << "This is a planet." << std::endl;
}

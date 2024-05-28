#include "DynamicArray.h"
#include <iostream>
//#include <utility>

DynamicArray::DynamicArray()
        : data(nullptr), size(0), capacity(0) {}

DynamicArray::~DynamicArray() {
    Clear();
}

DynamicArray::DynamicArray(const DynamicArray& other)
        : data(nullptr), size(0), capacity(0) {
    CopyFrom(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        Clear();
        CopyFrom(other);
    }
    return *this;
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        Clear();
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

void DynamicArray::Add(BaseEntity* entity) {
    if (size >= capacity) {
        Resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = entity;
}

void DynamicArray::Remove(int index) {
    if (index >= 0 && index < size) {
        delete data[index];
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        --size;
    }
}

void DynamicArray::Print() const {
    for (size_t i = 0; i < size; ++i) {
        data[i]->Print();
    }
}

void DynamicArray::Clear() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

/*
void DynamicArray::Resize(size_t newCapacity) {
    BaseEntity** newData = new BaseEntity*[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void DynamicArray::CopyFrom(const DynamicArray& other) {
    data = new BaseEntity*[other.capacity];
    for (size_t i = 0; i < other.size; ++i) {
        data[i] = other.data[i]; //
    }
    size = other.size;
    capacity = other.capacity;
}*/

// Копирование из другого массива
void DynamicArray::CopyFrom(const DynamicArray& other) {
    data = new BaseEntity*[other.capacity];
    capacity = other.capacity;
    size = other.size;
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Изменение ёмкости массива
void DynamicArray::Resize(size_t newCapacity) {
    BaseEntity** newData = new BaseEntity*[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
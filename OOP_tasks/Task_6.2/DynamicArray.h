#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "BaseEntity.h"

class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    void Add(BaseEntity* entity);
    void Remove(int index);
    void Print() const;
    void Clear();
    void CopyFrom(const DynamicArray& other);
    void Resize(size_t newCapacity);

private:
    BaseEntity** data;
    size_t size;
    size_t capacity;



};

#endif // DYNAMICARRAY_H

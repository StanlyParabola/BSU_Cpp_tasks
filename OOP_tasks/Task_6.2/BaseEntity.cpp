#include "BaseEntity.h"

BaseEntity::BaseEntity(const char* type) {
    copyString(this->type, type, sizeof(this->type));
}

void BaseEntity::copyString(char* dest, const char* src, size_t maxLen) {
    size_t i;
    for (i = 0; i < maxLen - 1 && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

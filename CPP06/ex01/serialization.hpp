#include <stdint.h>
#include "Data.hpp"
#include <iostream>

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer &operator = (const Serializer &other);
};

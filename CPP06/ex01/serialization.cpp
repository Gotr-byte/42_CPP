#include "serialization.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t universalPointer = reinterpret_cast<uintptr_t>(ptr);
    return (universalPointer);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* dataPointer = reinterpret_cast<Data*>(raw);
    return (dataPointer);
}
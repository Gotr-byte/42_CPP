#include "serialization.hpp"

int main()
{
    Data *dataBeforeSerialize = new Data();

    std::cout << "Default data\n";
    (*dataBeforeSerialize).printValues();
    (*dataBeforeSerialize).setXy(33,3);
    std::cout << "Data values before serialization\n";
    (*dataBeforeSerialize).printValues();
    uintptr_t dataInUintptr_t = Serializer::serialize(dataBeforeSerialize);
    std::cout << "Serialized address in uintptr_t: " << dataInUintptr_t << std::endl;
    Data *dataAfterSerialize = Serializer::deserialize(dataInUintptr_t);
    std::cout << "Data values after serialization\n";
    (*dataAfterSerialize).printValues();
    delete dataBeforeSerialize;
}

#include <iostream>

template <typename FuncPtr>
void callFunc(FuncPtr funcPtr) {
    (*funcPtr)(42);
}

template <typename ArgType, template <typename> class Func>
void callGenericFunc(ArgType arg) {
    Func<ArgType> funcPtr = &print<ArgType>;
    (*funcPtr)(arg);
}

template <typename T>
void print(T val) {
    std::cout << val << std::endl;
}

int main() {
    callGenericFunc<int, print>(42);
    return 0;
}
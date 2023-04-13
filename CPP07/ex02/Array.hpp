#pragma once
#include <iostream>

template <typename T>
class Array {
    public:
        T* arrayPtr;
        unsigned int _size;
        Array(){
            _size = 0;
        }
        Array(unsigned int n){
            arrayPtr = new T[n];
            _size = n;
        }
        Array(Array &other){
            if(this != &other)
            {   
                this->arrayPtr = new T[other.size()];
                this->_size = other.size();
            }
        }
        Array & operator = (Array &other)
        {
            if(this != &other)
            {   
                this->arrayPtr = new T[other.size()];
                this->_size = other.size();
            }
            return *this;
        }
        ~Array(){
            if(arrayPtr)
                delete []arrayPtr;
            std::cout << "Memory freed\n";
        }
        class				OutOfIndexBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Index out of bounds\n");
				}
		};
        unsigned int size(){
            return(this->_size);
        }
        T& operator[](unsigned int index) {
            if(index < 0) {
                throw OutOfIndexBoundsException();
            }
            if(index >= size()) {
                throw OutOfIndexBoundsException();
            }
            // std::cout << "Accessing element at index " << index << std::endl;
            return arrayPtr[index];
        }
};

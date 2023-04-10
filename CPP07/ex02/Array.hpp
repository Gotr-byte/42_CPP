#pragma once

template <typename T>
class Array {
    public:
        T* arrayPtr;
        Array(){
            arrayPtr = NULL;
        }
        Array(unsigned int n){
            this->numbElements = n;
            arrayPtr = new T[n];
            arrayPtr[n + 1] = NULL;
        }
        Array(const Array &other)const{
            if(this != &other)
            {   
                int i = 0;
                this->arrayPtr = new T[other.size()];
                // while (i < other.size())
                //     this->arrayPtr[i]->numbElements = other.arrayPtr[i]->numbElements;
            }
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
            unsigned int size = 0;
            while(arrayPtr[size])
                size++;
            return(size);
        }

    private:
};

    // if(this != &other)
    // {
    //     _type = "Cat";
    //     _brain = new Brain();
    //     for(int i = 0; i < 100; i++)
    //         _brain->setIdea(i, other._brain->getIdea(i));
    //     std::cout << "Copy cat constructor has been called" << std::endl;
    // }
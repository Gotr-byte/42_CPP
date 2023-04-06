#pragma once
#include <sys/time.h>
#include <iostream>
#include <stdexcept>


class Base
{
    public:
        virtual ~Base();

        static int	generateRandomVal(void);
        static void identify(Base& p);
        static void identify(Base* p);
        static Base *generate(void);
        
    protected:
        Base();
        Base(const Base& other);
        Base & operator=(const Base & other);
};
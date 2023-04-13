#include "iter.hpp"

// template <typename T>
// void iter(T *arrPtr, unsigned int len, void (* fun)(T const &)){
//     while (len--)
//         fun(arrPtr[len]);
// }

// template <typename T>
// void iter(T *arrPtr, unsigned int len, void (* fun)(T &)){
//     while (len--)
//         fun(arrPtr[len]);
// }

// void print(std::string & a)
// {
//     std::cout << "Armour type: " << a << "\n";
// }

// void enchant(std::string & a)
// {
//     std::cout << "Armour type: " << a + "_enchanted" << "\n";
// }

// int main()
// {
   
//     std::string* armour_types = new std::string[3]; // assign the address of the first element to ptr
//     armour_types[0] = "light";
//      armour_types[1] = "medium";
//       armour_types[2] = "heavy";
//     int i  = 3;

//     iter(armour_types, i, &print);
//      iter(armour_types, i, &enchant);
//     delete []armour_types;
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

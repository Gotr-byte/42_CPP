#include "Array.hpp"

int main(){
    std::cout << "+++ Empty array test +++" << "\n";
    Array<int> emptyArr;
    std::cout << emptyArr.size() << "\n";
    std::cout << "+++ End of empty array test +++" << "\n";
    std::cout << "\n";
    std::cout << "+++ Array of size constructor test +++\n";
    Array<int>arrOfSize(5);
    std::cout << arrOfSize.size() << "\n";
    std::cout << "+++ End of array of size test +++" << "\n";
    std::cout << "\n";
    std::cout << "+++ Array created by copy constructor test +++\n";
    Array<int>copyArr(arrOfSize);
    std::cout <<"Origin array size: " << arrOfSize.size() << "\n";
    std::cout <<"Copy array size: " << copyArr.size() << "\n";
    std::cout << "+++ End of copy constructor test +++" << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "+++ Array assignment operator test +++\n";
    Array <int>assignmentOpTest;
    assignmentOpTest = copyArr;
    std::cout << "Origin array size: "  << arrOfSize.size() << "\n";
    std::cout << "Copy array size: " << assignmentOpTest.size() << "\n";
    std::cout << "+++ End of assignment operator test +++" << "\n";
    std::cout << "\n";
    std::cout << "+++ Accesing array test +++\n";
    try
    {
    // copyArr[-1]; //does not compute
    copyArr[0];
    copyArr[1];
    copyArr[2];
    copyArr[3];
    copyArr[4];
    copyArr[5];
    }
    catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
    std::cout << "+++ End of accesing test +++" << "\n";
    std::cout << "\n";

}

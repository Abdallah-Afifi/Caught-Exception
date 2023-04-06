#include <iostream>
using namespace std;

class ExceptionA : public exception {
public:
    const char* what() const throw() {
        return "Exception A";
    }
};

class ExceptionB : public ExceptionA {
public:
    const char* what() const throw() {
        return "Exception B";
    }
};

class ExceptionC : public ExceptionB {
public:
    const char* what() const throw() {
        return "Exception C";
    }
};

class ExceptionTester {
public:
    void test() {
        try {
            throw ExceptionC();
        }
        catch (ExceptionA& ex) {
            cout << "Caught Exception: " << ex.what() << endl;
        }
    }
};

int main() {
    ExceptionTester tester;
    tester.test();
    return 0;
}

//
// Created by alessio on 06/08/19.
//

#ifndef ALL_ULTIMO_GAS_LOAD_EXCEPTION_H
#define ALL_ULTIMO_GAS_LOAD_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class Load_exception : public exception {

public:
    Load_exception(const string &Message = ""){}
};
#endif //ALL_ULTIMO_GAS_LOAD_EXCEPTION_H

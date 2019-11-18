//
// Created by ArcziPT on 29.07.2019.
//

#ifndef CL_CALCULATOR_FUNCTIONFACTORY_H
#define CL_CALCULATOR_FUNCTIONFACTORY_H

#include "CalcFunction.h"
#include <iostream>
#include <vector>
#include "RPN_Converter.h"

class FunctionFactory {
public:
    FunctionFactory(RPN_Converter* converter): converter(converter){};

    CalcFunction* get_function(const std::string& func, int arg_num);

private:
    RPN_Converter* converter;
};


#endif //CL_CALCULATOR_FUNCTIONFACTORY_H

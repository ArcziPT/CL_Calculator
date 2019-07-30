//
// Created by ArcziPT on 29.07.2019.
//

#ifndef CL_CALCULATOR_FUNCTIONFACTORY_H
#define CL_CALCULATOR_FUNCTIONFACTORY_H

#include "CalcFunction.h"
#include <iostream>
#include <vector>
#include "RPN_Converter.h"
#include "RPN_Calculator.h"

class FunctionFactory {
public:
    FunctionFactory(RPN_Converter* converter, RPN_Calculator* calculator): calculator(calculator), converter(converter){};

    CalcFunction* get_function(const std::string& func, int arg_num);

private:
    RPN_Converter* converter;
    RPN_Calculator* calculator;
};


#endif //CL_CALCULATOR_FUNCTIONFACTORY_H

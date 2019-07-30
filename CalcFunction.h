//
// Created by ArcziPT on 29.07.2019.
//

#ifndef CL_CALCULATOR_CALCFUNCTION_H
#define CL_CALCULATOR_CALCFUNCTION_H


#include <vector>
#include <iostream>
#include <memory>
#include "RPN_Calculator.h"


class CalcFunction {
public:
    double operator()(const std::vector<double>& args);

    CalcFunction(std::unique_ptr<RPN> rpn, int arg_num, RPN_Calculator* calculator): rpn(std::move(rpn)), arg_num(arg_num), calculator(calculator){};
    CalcFunction(const CalcFunction& calcFunction);

    std::string get_info();

private:
    std::unique_ptr<RPN> rpn;
    int arg_num;

    RPN_Calculator* calculator;
};


#endif //CL_CALCULATOR_CALCFUNCTION_H

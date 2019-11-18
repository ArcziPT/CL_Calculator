//
// Created by ArcziPT on 29.07.2019.
//

#ifndef CL_CALCULATOR_CALCFUNCTION_H
#define CL_CALCULATOR_CALCFUNCTION_H


#include <vector>
#include <memory>
#include "RPN_Calculator.h"

/*
 * used to represent dynamic function and hold its data:
 * -args_num
 * -info
 */
class CalcFunction {
public:
    std::unique_ptr<RPN> operator()(const std::vector<double>& args);

    CalcFunction(std::unique_ptr<RPN> rpn, int arg_num): rpn(std::move(rpn)), arg_num(arg_num){};
    CalcFunction(const CalcFunction& calcFunction);

    std::string get_info();

private:
    std::unique_ptr<RPN> rpn;
    int arg_num;
};


#endif //CL_CALCULATOR_CALCFUNCTION_H

//
// Created by ArcziPT on 29.07.2019.
//

#include "FunctionFactory.h"

//creates dynamic function by converting expression into rpn
CalcFunction* FunctionFactory::get_function(const std::string &func, int arg_num) {
    auto rpn = converter->convert(func);

    return new CalcFunction(std::move(rpn), arg_num);
}

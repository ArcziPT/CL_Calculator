//
// Created by ArcziPT on 09.07.2019.
//

#ifndef CL_CALCULATOR_RPN_CALCULATOR_H
#define CL_CALCULATOR_RPN_CALCULATOR_H

#include "RPN_Converter.h"
#include "default_functions.h"
#include <functional>

struct func_def{
    int arg_num;
    std::function<double(const std::vector<double>&)> func_ptr;

    bool dynamic = false;
    std::string info = "";
};


class RPN_Calculator {
public:
    double calculate(const RPN& rpn);
    void config(const std::map<std::string, func_def>& func_map, bool var_mode);

    bool error();

private:
    bool var_mode = false;
    bool err = false;
    std::map<std::string, func_def> func_map;
};


#endif //CL_CALCULATOR_RPN_CALCULATOR_H

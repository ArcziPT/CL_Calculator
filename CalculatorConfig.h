//
// Created by ArcziPT on 09.07.2019.
//

#ifndef CL_CALCULATOR_CALCULATORCONFIG_H
#define CL_CALCULATOR_CALCULATORCONFIG_H

#include "RPN_Converter.h"
#include <functional>
#include "RPN_Calculator.h"

/*
 * it holds definitions of dynamic functions added during runtime and hardcoded function in func_map, precedence, associativity..
 */

class CalculatorConfig {
public:
    CalculatorConfig();

    //print info
    void print_function_data(const std::string& name);

    //config
    CalculatorConfig& set_function(const std::string& name, int args_num, const func_ptr_variant& func_ptr, bool dynamic = false, const std::string& info = "");
    //CalculatorConfig& set_operator(const std::string& op, std::function<double(const std::vector<double>&)> func_ptr, int precedence, bool left_associativity, bool dynamic = false, const std::string& info = "");
    CalculatorConfig& remove_function(const std::string& name);
    CalculatorConfig& set_var_mode(bool var_mode);

    //reset config
    CalculatorConfig& reset();

    //apply config to converter and calculator
    CalculatorConfig& apply(RPN_Converter& converter);
    CalculatorConfig& apply(RPN_Calculator& calculator);

private:
    void init_default();

    std::map<std::string, func_def> func_map;
    std::map<std::string, int> precedence;
    std::map<std::string, bool> left_associativity;
    //std::map<std::string, bool> operators;
    bool var_mode = false;
};


#endif //CL_CALCULATOR_CALCULATORCONFIG_H

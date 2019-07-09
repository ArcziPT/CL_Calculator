//
// Created by ArcziPT on 09.07.2019.
//

#ifndef CL_CALCULATOR_CALCULATORCONFIG_H
#define CL_CALCULATOR_CALCULATORCONFIG_H

#include "RPN_Converter.h"
#include "RPN_Calculator.h"

class CalculatorConfig {
public:
    CalculatorConfig();

    //config
    CalculatorConfig& set_function(const std::string& name, int args_num, double (*func_ptr)(const std::vector<double>&));
    CalculatorConfig& set_operator(const std::string& op, double (*func_ptr)(const std::vector<double>&), int precedence, bool left_associativity);
    CalculatorConfig& remove_function(const std::string& name);

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
};


#endif //CL_CALCULATOR_CALCULATORCONFIG_H

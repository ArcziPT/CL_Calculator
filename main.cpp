#include <iostream>
#include "CalculatorConfig.h"

double my_func(const std::vector<double>& args){
    return 2*args[0];
}

int main() {
    RPN_Converter converter;
    RPN_Calculator calculator;
    CalculatorConfig config;

    config.set_function("my_func", 1, my_func).apply(calculator).apply(converter);

    std::string input = "120*my_func(15-3)-abc(2)";
    auto rpn = converter.convert(input);

    std::cout<<calculator.calculate(*rpn);

    return 0;
}
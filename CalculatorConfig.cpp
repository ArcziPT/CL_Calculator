//
// Created by ArcziPT on 09.07.2019.
//

#include "CalculatorConfig.h"

CalculatorConfig::CalculatorConfig() {
    init_default();
}

CalculatorConfig &
CalculatorConfig::set_function(const std::string &name, int args_num, double (*func_ptr)(const std::vector<double> &)) {
    if(!func_map.count(name)){
        func_def def;
        def.arg_num = args_num;
        def.func_ptr = func_ptr;

        func_map.insert(std::pair<std::string, func_def>(name, def));

        return *this;
    }

    func_map[name].arg_num = args_num;
    func_map[name].func_ptr = func_ptr;

    return *this;
}

CalculatorConfig &
CalculatorConfig::set_operator(const std::string &op, double (*func_ptr)(const std::vector<double> &), int precedence,
                               bool left_associativity) {
    if(!func_map.count(op)){
        func_def def;
        def.arg_num = 2;
        def.func_ptr = func_ptr;

        func_map.insert(std::pair<std::string, func_def>(op, def));
        this->left_associativity.insert(std::pair<std::string, bool>(op, left_associativity));
        this->precedence.insert(std::pair<std::string, int>(op, precedence));

        return *this;
    }

    func_map[op].func_ptr = func_ptr;
    func_map[op].arg_num = 2;

    this->left_associativity[op] = left_associativity;
    this->precedence[op] = precedence;

    return *this;
}

CalculatorConfig &CalculatorConfig::remove_function(const std::string &name) {
    func_map.erase(name);
    precedence.erase(name);
    left_associativity.erase(name);

    return *this;
}

CalculatorConfig &CalculatorConfig::reset() {
    init_default();

    return *this;
}

CalculatorConfig &CalculatorConfig::apply(RPN_Converter &converter) {
    converter.config(precedence, left_associativity);

    return *this;
}

CalculatorConfig &CalculatorConfig::apply(RPN_Calculator &calculator) {
    calculator.config(func_map);

    return *this;
}

void CalculatorConfig::init_default() {
    left_associativity = {
        {"+", 1},
        {"-", 1},
        {"/", 1},
        {"*", 1},
        {"^", 0}
    };

    precedence = {
        {"+", 1},
        {"-", 1},
        {"/", 2},
        {"*", 2},
        {"^", 3}
    };

    func_map = {
            {"+", {2, &add}},
            {"-", {2, &sub}},
            {"/", {2, &div}},
            {"*", {2, &mul}},
            {"^", {2, &poww}}
    };
}

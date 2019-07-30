//
// Created by ArcziPT on 09.07.2019.
//

#include "CalculatorConfig.h"

CalculatorConfig::CalculatorConfig() {
    init_default();
}

CalculatorConfig &
CalculatorConfig::set_function(const std::string &name, int args_num, const std::function<double(const std::vector<double>&)>& func_ptr, bool dynamic, const std::string& info) {
    if(!func_map.count(name)){
        func_def def;
        def.arg_num = args_num;
        def.func_ptr = func_ptr;
        def.dynamic = dynamic;
        def.info = info;

        func_map.insert(std::pair<std::string, func_def>(name, def));

        return *this;
    }

    func_map[name].arg_num = args_num;
    func_map[name].func_ptr = func_ptr;

    return *this;
}

/*CalculatorConfig &
CalculatorConfig::set_operator(const std::string &op, std::function<double(const std::vector<double>&)> func_ptr, int precedence,
                               bool left_associativity, bool dynamic, const std::string& info) {
    if(!func_map.count(op)){
        func_def def;
        def.arg_num = 2;
        def.func_ptr = func_ptr;
        def.dynamic = dynamic;
        def.info = info;

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
}*/

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
    converter.config(precedence, left_associativity, var_mode);

    return *this;
}

CalculatorConfig &CalculatorConfig::apply(RPN_Calculator &calculator) {
    calculator.config(func_map, var_mode);

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
            {"+", {2, &default_func::d_add}},
            {"-", {2, &default_func::d_sub}},
            {"/", {2, &default_func::d_div}},
            {"*", {2, &default_func::d_mul}},
            {"^", {2, &default_func::d_pow}},
            {"sin", {1, &default_func::d_sin}},
            {"cos", {1, &default_func::d_cos}},
            {"tg", {1, &default_func::d_tg}},
            {"ctg", {1, &default_func::d_ctg}}
    };

    var_mode = false;
}

CalculatorConfig &CalculatorConfig::set_var_mode(bool var_mode) {
    this->var_mode = var_mode;

    return *this;
}

void CalculatorConfig::print_function_data(const std::string &name) {
    if(func_map.count(name) == 0){
        std::cout<<"\""<<name<<"\" not defined\n";
        return;
    }

    auto def = func_map[name];

    if(!def.dynamic){
        std::cout<<"\""<<name<<"\" is hardcoded function\n";
        return;
    }

    std::cout<<def.info;
}

//
// Created by ArcziPT on 09.07.2019.
//

#ifndef CL_CALCULATOR_RPN_CALCULATOR_H
#define CL_CALCULATOR_RPN_CALCULATOR_H

#include "RPN_Converter.h"
#include "default_functions.h"
#include <functional>
#include <variant>

//calc_func_ptr is used by hardcoded function whereas dynamic ones make use of rpn_func_ptr
using calc_func_ptr = std::function<double (const std::vector<double>&)>;
using rpn_func_ptr = std::function<std::unique_ptr<RPN> (const std::vector<double>&)>;
using func_ptr_variant = std::variant<calc_func_ptr , rpn_func_ptr>;

struct func_def{
    func_def() = default;
    func_def(int arg_num, const func_ptr_variant& func_ptr, bool dynamic = false, const std::string& info = ""){
        this->func_ptr = func_ptr;
        this->arg_num = arg_num;
        this->dynamic = dynamic;
        this->info = info;
    }

    func_ptr_variant func_ptr;
    int arg_num;
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

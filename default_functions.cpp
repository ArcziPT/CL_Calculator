//
// Created by ArcziPT on 09.07.2019.
//

#include "default_functions.h"
#include <cmath>

double default_func::d_add(const std::vector<double>& args){
    return args[1] + args[0];
}

double default_func::d_sub(const std::vector<double>& args){
    return args[1] - args[0];
}

double default_func::d_div(const std::vector<double>& args){
    return args[1] / args[0];
}

double default_func::d_mul(const std::vector<double>& args){
    return args[1] * args[0];
}

double default_func::d_pow(const std::vector<double>& args){
    return pow(args[1], args[0]);
}

double default_func::d_sin(const std::vector<double>& args){
    return sin(args[0]/180*M_PI);
}

double default_func::d_cos(const std::vector<double>& args){
    return cos(args[0]/180*M_PI);
}

double default_func::d_tg(const std::vector<double>& args){
    return tan(args[0]/180*M_PI);
}

double default_func::d_ctg(const std::vector<double>& args){
    return 1/tan(args[0]/180*M_PI);
}
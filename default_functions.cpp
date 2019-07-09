//
// Created by ArcziPT on 09.07.2019.
//

#include "default_functions.h"
#include <cmath>

double add(const std::vector<double>& args){
    return args[1] + args[0];
}

double sub(const std::vector<double>& args){
    return args[1] - args[0];
}

double div(const std::vector<double>& args){
    return args[1] / args[0];
}

double mul(const std::vector<double>& args){
    return args[1] * args[0];
}

double poww(const std::vector<double>& args){
    return pow(args[1], args[0]);
}
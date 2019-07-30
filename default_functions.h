//
// Created by ArcziPT on 09.07.2019.
//

#ifndef CL_CALCULATOR_DEFAULT_FUNCTIONS_H
#define CL_CALCULATOR_DEFAULT_FUNCTIONS_H

#include <vector>

namespace default_func{
    double d_add(const std::vector<double>& args);

    double d_sub(const std::vector<double>& args);

    double d_div(const std::vector<double>& args);

    double d_mul(const std::vector<double>& args);

    double d_pow(const std::vector<double>& args);

    double d_sin(const std::vector<double>& args);

    double d_cos(const std::vector<double>& args);

    double d_tg(const std::vector<double>& args);

    double d_ctg(const std::vector<double>& args);
}


#endif //CL_CALCULATOR_DEFAULT_FUNCTIONS_H

#include "black_scholes.h"
#include <cmath>

static double norm_cdf(double x) {
    const double inv_sqrt2 = 1.0 / std::sqrt(2.0);
    return 0.5 * std::erfc(-x * inv_sqrt2);
}

double call_price(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T)
                / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    return S * norm_cdf(d1)
         - K * std::exp(-r * T) * norm_cdf(d2);
}

double put_price(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T)
                / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    return K * std::exp(-r * T) * norm_cdf(-d2)
         - S * norm_cdf(-d1);
}

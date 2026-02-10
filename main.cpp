#include <iostream>
#include "black_scholes.h"
#include "monte_carlo.h"

int main() {
    const double S = 100.0;
    const double K = 100.0;
    const double T = 1.0;
    const double r = 0.01;
    const double sigma = 0.2;

    const auto bs_call = call_price(S, K, T, r, sigma);
    const auto bs_put  = put_price(S, K, T, r, sigma);

    const std::int64_t paths = 200000;

    const auto mc_call = mc_call_price(S, K, T, r, sigma, paths, 123);
    const auto mc_put  = mc_put_price(S, K, T, r, sigma, paths, 123);

    std::cout << "Black-Scholes Call: " << bs_call << "\n";
    std::cout << "Monte Carlo  Call: " << mc_call.price
              << "  (std err: " << mc_call.std_error << ")\n\n";

    std::cout << "Black-Scholes Put:  " << bs_put << "\n";
    std::cout << "Monte Carlo  Put:  " << mc_put.price
              << "  (std err: " << mc_put.std_error << ")\n";

    return 0;
}

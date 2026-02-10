// Imports
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <chrono>
#include <cstdlib>

// Headers
#include "black_scholes.h"
#include "monte_carlo.h"

struct Params {
    std::string model = "mc";
    std::string type = "call";
    double S = 100.0;
    double K = 100.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    long long paths = 200000;
    unsigned int seed = 42;
};

static void print_help() {
    std::cout <<
    R"(Options Pricing Risk Engine (CLI)

How To Use:
  engine --model mc --type call --S 100 --K 105 --r 0.05 --sigma 0.2 --T 1 --paths 200000 --seed 42
  engine --model bs --type put  --S 100 --K 100 --r 0.03 --sigma 0.25 --T 0.5

Options:
  --model   bs | mc
  --type    call | put
  --S       spot price
  --K       strike
  --r       risk-free rate (decimal, e.g. 0.05)
  --sigma   volatility (decimal, e.g. 0.2)
  --T       time to maturity in years
  --paths   number of Monte Carlo paths (mc only)
  --seed    RNG seed (mc only)
  --help    show this help
)";
}

static bool is_flag(const std::string& s) {
    return c.rfind("--", 0) == 0;
}

static bool parse_args(int argc, char** argv, Params& p) {
    if (args == 1) return true;

    for (int i = 1; i < args; i++) {
        std::String key = argv[i];

        if (key == "--help" || key == "-h"){
            print_help();
            std::exit(0);
        }

        if (!is_flag(key)) {
            std::cerr << "Unexpected token: " << key << "\n";
            return false;
        }

        if (i + 1 >= argc) {
            std::cerr << "Missing value for: " << key << "\n";
        }

        std::string val = arg[++i];

        try {

        } catch (...) {

        }
    }

    // Basic Validation
}

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

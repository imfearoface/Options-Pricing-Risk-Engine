#include "monte_carlo.h"
#include <cmath>
#include <random>
#include <algorithm>

static double simulate_ST(double S, double T, double r, double sigma, double Z) {
    const double drift = (r - 0.5 * sigma * sigma) * T;
    const double diff  = sigma * std::sqrt(T) * Z;
    return S * std::exp(drift + diff);
}

static MCResult mc_option_price(
    bool is_call,
    double S, double K, double T, double r, double sigma,
    std::int64_t num_paths,
    std::uint64_t seed
) {
    std::mt19937_64 rng(seed);
    std::normal_distribution<double> normal(0.0, 1.0);

    const double discount = std::exp(-r * T);

    double mean = 0.0;
    double m2 = 0.0;
    std::int64_t n = 0;

    for (std::int64_t i = 0; i < num_paths; ++i) {
        const double Z = normal(rng);
        const double ST = simulate_ST(S, T, r, sigma, Z);

        const double payoff = is_call
            ? std::max(ST - K, 0.0)
            : std::max(K - ST, 0.0);

        const double x = discount * payoff;

        ++n;
        const double delta = x - mean;
        mean += delta / static_cast<double>(n);
        const double delta2 = x - mean;
        m2 += delta * delta2;
    }

    const double variance = (n > 1) ? (m2 / static_cast<double>(n - 1)) : 0.0;
    const double stddev = std::sqrt(variance);
    const double std_error = stddev / std::sqrt(static_cast<double>(n));

    return MCResult{mean, std_error};
}

MCResult mc_call_price(double S, double K, double T, double r, double sigma,
                       std::int64_t num_paths, std::uint64_t seed) {
    return mc_option_price(true, S, K, T, r, sigma, num_paths, seed);
}

MCResult mc_put_price(double S, double K, double T, double r, double sigma,
                      std::int64_t num_paths, std::uint64_t seed) {
    return mc_option_price(false, S, K, T, r, sigma, num_paths, seed);
}

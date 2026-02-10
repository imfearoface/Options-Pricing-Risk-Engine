#pragma once
#include <cstdint>

struct MCResult {
    double price;
    double std_error;
};

MCResult mc_call_price(
    double S, double K, double T, double r, double sigma,
    std::int64_t num_paths,
    std::uint64_t seed = 42
);

MCResult mc_put_price(
    double S, double K, double T, double r, double sigma,
    std::int64_t num_paths,
    std::uint64_t seed = 42
);

# Options Pricing & Risk Engine

## Overview

This project is a high-performance options pricing and risk analysis engine implemented in C++ and Python. It combines analytical Black–Scholes valuation with Monte Carlo simulation to estimate option prices under a stochastic stock price model.

The focus is on uncertainty-aware pricing, numerical methods in finance, and scalable system design rather than price prediction or automated trading.

---

## Motivation

Modern options markets rely on mathematical pricing models and simulation-based risk analysis to evaluate uncertainty and manage exposure. Black–Scholes provides a foundational analytical benchmark, while Monte Carlo methods generalize pricing to more complex payoffs and scenarios.

This project explores how these techniques are implemented in production-style systems using performance-oriented C++ with modular design.

---

## Features

- Black–Scholes analytical call and put pricing  
- Monte Carlo simulation with statistical error estimates  
- Modular C++ pricing core  
- Validation of simulation results against closed-form solutions  
- Reproducible simulations using seeded random generators  

---

## Project Structure

cpp_pricing/
├── black_scholes.h  
├── black_scholes.cpp  
├── monte_carlo.h  
├── monte_carlo.cpp  
└── main.cpp  

---

## Build & Run

### Requirements
- C++17 compatible compiler (g++ or MSVC)

### Compile

g++ -std=c++17 *.cpp*

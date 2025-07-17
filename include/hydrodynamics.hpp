// hydrodynamics.hpp
#ifndef INCLUDE_HYDRODYNAMICS_HPP_H
#define INCLUDE_HYDRODYNAMICS_HPP_H

/*
TO DO:
- 
*/

#include <array>
#include <complex>

#include "profile.hpp"

namespace Hydrodynamics {

/**
 * @brief Computes the bubble lifetime distribution at the normalized time Ttilde.
 *
 * @param Ttilde Normalized time (T * β).
 * @param nuc_type Nucleation type: "exp" for exponential or "sim" for simultaneous.
 *
 * @return Lifetime distribution.
 */
double lifetime_dist(double Ttilde, const std::string& nuc_type);

/**
 * @brief Computes the bubble lifetime distribution over a vector of normalized times Ttilde.
 *
 * @param Ttilde Normalized time (T * β).
 * @param nuc_type Nucleation type: "exp" for exponential or "sim" for simultaneous.
 * 
 * @return Lifetime distribution.
 */
std::vector<double> lifetime_dist2(const std::vector<double>& Ttilde, const std::string& nuc_type);

std::function<double(double)> lifetime_dist_func(const std::string& nuc_type);

/**
 * @brief Computes the integrated profile functions f'(χ) and l(χ) defined in Eq. (30), (31) of Pol, Procacci, Caprini (2024).
 *
 * @param chi χ=k*T_n (k = momentum, T_n = lifetime of n'th bubble)
 * @param prof FluidProfile object
 * 
 * @return Pair of vector of the integrated profile functions f' and l.
 */
std::pair<std::vector<double>, std::vector<double>> prof_ints_fl(const std::vector<double>& chi_vals, const FluidProfile& prof);

/**
 * @brief Computes |A₊(χ)|², defined in Eq. (29) of Pol, Procacci, Caprini (2024).
 *
 * @param chi χ=k*T_n (k = momentum, T_n = lifetime of n'th bubble)
 * @param prof Fluid profile object.
 * 
 * @return Vector of squared modulus |A₊(χ)|² values
 */
std::vector<double> Ap_sq(const std::vector<double>& chi_vals, const FluidProfile& prof);

} // namespace Hydrodynamics

#endif // INCLUDE_HYDRODYNAMICS_HPP_H

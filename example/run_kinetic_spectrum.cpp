#include "deepphase.hpp"

int main() {

    // define PT parameters
    const auto vw = PhaseTransition::dflt_PTParams::vw;
    const auto alN = PhaseTransition::dflt_PTParams::alpha;
    const auto beta = PhaseTransition::dflt_PTParams::beta;
    const auto dtau = PhaseTransition::dflt_PTParams::dtau;
    const auto wN = PhaseTransition::dflt_PTParams::wN;
    const auto model = PhaseTransition::dflt_PTParams::model;
    const auto nuc_type = PhaseTransition::dflt_PTParams::nuc_type;

    // Create default universe parameters (temperature, Hubble and DoF today and at PT)
    const PhaseTransition::Universe un;

    // Momentum values
    const auto kRs_vals = logspace(1e-1, 1e+3, 500);

    // Create hydrodynamic profile of bubble
    const PhaseTransition::PTParams params(vw, alN, beta, dtau, wN, model, nuc_type, un);
    const Hydrodynamics::FluidProfile profile(params);

    // Kinetic spectrum
    Spectrum::PowerSpec Ek = Spectrum::Ekin(kRs_vals, profile);
    Spectrum::PowerSpec Eks = Spectrum::zetaKin(Ek); // Normalised spectrum

    Eks.write("kinetic_spectrum.csv");

    #ifdef ENABLE_MATPLOTLIB
    Eks.plot("kinetic_spectrum.png");
    #endif

    return 0;
}
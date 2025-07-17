#include "deepphase.hpp"

int main() {

    const auto vw = PhaseTransition::dflt_PTParams::vw;
    const auto alN = PhaseTransition::dflt_PTParams::alpha;
    const auto beta = PhaseTransition::dflt_PTParams::beta;
    const auto dtau = PhaseTransition::dflt_PTParams::dtau;
    const auto wN = PhaseTransition::dflt_PTParams::wN;
    const auto model = PhaseTransition::dflt_PTParams::model;
    const auto nuc_type = PhaseTransition::dflt_PTParams::nuc_type;

    const PhaseTransition::Universe un;
    const PhaseTransition::PTParams params(vw, alN, beta, dtau, wN, model, nuc_type, un);
    const Hydrodynamics::FluidProfile profile(params);

    const auto kRs_vals = logspace(1e-3, 1e+3, 100);
    Spectrum::PowerSpec OmegaGW = Spectrum::GWSpec(kRs_vals, params);

    OmegaGW.write("gw_spectrum.csv");

    #ifdef ENABLE_MATPLOTLIB
    OmegaGW.plot("gw_spectrum.png");
    #endif

    return 0;
}
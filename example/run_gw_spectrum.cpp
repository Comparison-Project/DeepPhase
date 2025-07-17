#include "deepphase.hpp"

int main(int argc, char* argv[]) {
    // Defaults
    double vw = PhaseTransition::dflt_PTParams::vw;
    double alN = PhaseTransition::dflt_PTParams::alpha;
    double beta = PhaseTransition::dflt_PTParams::beta;
    double dtau = PhaseTransition::dflt_PTParams::dtau;
    const auto wN = PhaseTransition::dflt_PTParams::wN;
    const auto model = PhaseTransition::dflt_PTParams::model;
    const auto nuc_type = PhaseTransition::dflt_PTParams::nuc_type;

    if (argc == 4) {;
        alN = std::stod(argv[1]);
        beta = std::stod(argv[2]);
        vw = std::stod(argv[3]);
        dtau = 1/beta;
    }

    const PhaseTransition::Universe un;
    const PhaseTransition::PTParams params(vw, alN, beta, dtau, wN, model, nuc_type, un);
    if(argc == 4) {
        params.print();
    }
    const Hydrodynamics::FluidProfile profile(params);

    const auto kRs_vals = logspace(1e-3, 1e+3, 100);
    Spectrum::PowerSpec OmegaGW = Spectrum::GWSpec(kRs_vals, params);

    OmegaGW.write("gw_spectrum.csv");

    #ifdef ENABLE_MATPLOTLIB
    OmegaGW.plot("gw_spectrum.png");
    #endif

    return 0;
}
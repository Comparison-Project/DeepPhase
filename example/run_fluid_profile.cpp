#include "deepphase.hpp"

int main() {

    const PhaseTransition::Universe un;

    const PhaseTransition::PTParams params(0.5, 0.1, 1.0, 10.0, 1.71, "bag", "exp", un);

    const Hydrodynamics::FluidProfile profile(params);

    profile.write("fluid_profile.csv");

    #ifdef ENABLE_MATPLOTLIB
    profile.plot("fluid_profile.png");
    #endif

    return 0;
}
#ifndef __CPU_O3_COMP_SIMP_HH__
#define __CPU_O3_COMP_SIMP_HH__

#include "cpu/o3/dyn_inst.hh"

namespace gem5
{

namespace o3
{

/**

 */
class CompSimp
{
  private:

    enum IntMultOpSupported
    {
        smaddl,
        smsubl,
        umaddl,
        umsubl,
        madd,
        msub,
        smulh,
        umulh,
        error_intmult
    };

    IntMultOpSupported intmult_hashit(std::string const& inString) {
        if (inString == "smaddl") return smaddl;
        if (inString == "smsubl") return smsubl;
        if (inString == "umaddl") return umaddl;
        if (inString == "umsubl") return umsubl;
        if (inString == "madd") return madd;
        if (inString == "msub") return msub;
        if (inString == "smulh") return smulh;
        if (inString == "umulh") return umulh;

        return error_intmult;
    };

    enum IntDivOpSupported
    {
        sdiv,
        udiv,
        error_intdiv
    };

    IntDivOpSupported intdiv_hashit(std::string const& inString) {
        if (inString == "sdiv") return sdiv;
        if (inString == "udiv") return udiv;

        return error_intdiv;
    };

    bool IntMultOpAnalysis(DynInstPtr issuing_inst, Cycles* override_latency);
    bool IntDivOpAnalysis(DynInstPtr issuing_inst, Cycles* override_latency);

  public:
    CompSimp();
    ~CompSimp();

    bool Anaylze(DynInstPtr issuing_inst, Cycles* override_latency);
};

} // namespace o3
} // namespace gem5

#endif // __CPU_O3_COMP_SIMP_HH__

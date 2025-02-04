#include "cpu/o3/comp_simp.hh"

#include "debug/IQ.hh"

namespace gem5
{

namespace o3
{

// Constructor
CompSimp::CompSimp()
{

}

// Destructor
CompSimp::~CompSimp()
{

}

bool
CompSimp::IntMultOpAnalysis(DynInstPtr issuing_inst, Cycles* override_latency)
{
    StaticInstPtr static_inst = issuing_inst->staticInst;
    bool override = false;

    DPRINTF(IQ, "IQ: Processing instruction: %s\n",
      issuing_inst->staticInst->
      disassemble(issuing_inst->pcState().instAddr()));
    DPRINTF(IQ, "SRC Regs %d\n", issuing_inst->numSrcRegs());

    switch(hashit(static_inst->getName())) {
      case smaddl:
      case smsubl:
      case umaddl:
      case umsubl:
      case madd:
      case msub:
        for (int i = 0; i < issuing_inst->numSrcRegs(); ++i) {
          RegVal src_reg_val = issuing_inst->
            getRegOperand(issuing_inst->staticInst.get(), i);
          DPRINTF(IQ, "Src Reg %i: %d\n", i, src_reg_val);
          // fast pass if src reg 1 or 2 is 0
          if (i == 1 || i == 2) {
              if (src_reg_val == 0 || src_reg_val == 1) {
                  *override_latency = Cycles(1);
                  return true;
              }
          }
        }
        break;
      case smulh:
      case umulh:
        for (int i = 0; i < issuing_inst->numSrcRegs(); ++i) {
          RegVal src_reg_val = issuing_inst->
            getRegOperand(issuing_inst->staticInst.get(), i);
          DPRINTF(IQ, "Src Reg %i: %d\n", i, src_reg_val);
          // fast pass if src reg 0 or 1 is 0
          if (i == 0 || i == 1) {
              if (src_reg_val == 0 || src_reg_val == 1) {
                  *override_latency = Cycles(1);
                  return true;
              }
          }
        }
        break;
      default:
          panic("IntMultOpAnalysis: Unsupported instruction type\n");
          break;
    }

    return override;
}

bool
CompSimp::Anaylze(DynInstPtr issuing_inst, Cycles* override_latency)
{
    bool override = false;

    if (issuing_inst->opClass() == IntMultOp) {
        override = IntMultOpAnalysis(issuing_inst, override_latency);
    }


    return override;
}

} // namespace o3
} // namespace gem5

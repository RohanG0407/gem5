#include "cpu/o3/comp_simp.hh"
#include "cpu/o3/thread_context.hh"
#include "arch/arm/regs/misc.hh"


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
CompSimp::IntDivOpAnalysis(DynInstPtr issuing_inst, Cycles* override_latency)
{
    StaticInstPtr static_inst = issuing_inst->staticInst;
    bool override = false;

    DPRINTF(IQ, "SRC Regs %d\n", issuing_inst->numSrcRegs());

    switch(intdiv_hashit(static_inst->getName())) {
      case sdiv:
      case udiv:
        for (int i = 0; i < issuing_inst->numSrcRegs(); ++i) {
          RegVal src_reg_val = issuing_inst->
            getRegOperand(issuing_inst->staticInst.get(), i);
          DPRINTF(IQ, "Src Reg %i: %d\n", i, src_reg_val);
          // fast pass if src reg 1 (dividend) is 0
          if (i == 0) {
              if (src_reg_val == 0) {
                  *override_latency = Cycles(1);
                  return true;
              }
          } else if (i == 1) { // fast pass if src reg 2 (divisor) is 1
              if (src_reg_val == 1) {
                  *override_latency = Cycles(1);
                  return true;
              }
          }
        }
        break;
      default:
          panic("IntDivOpAnalysis: Unsupported instruction type\n");
          break;
    }

    return override;
}

bool
CompSimp::IntMultOpAnalysis(DynInstPtr issuing_inst, Cycles* override_latency)
{
    StaticInstPtr static_inst = issuing_inst->staticInst;
    bool override = false;

    DPRINTF(IQ, "SRC Regs %d\n", issuing_inst->numSrcRegs());

    switch(intmult_hashit(static_inst->getName())) {
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
CompSimp::Anaylze(DynInstPtr issuing_inst, Cycles* override_latency, uint8_t ditInflight)
{
    bool override = false;
    return false;

    gem5::ThreadContext *tc = issuing_inst->thread->getTC();
    const ArmISA::CPSR cpsr = tc->readMiscRegNoEffect(gem5::ArmISA::MISCREG_CPSR);

    DPRINTF(IQ, "CompSimp: Analyzing instruction: %s\n",
      issuing_inst->staticInst->
          disassemble(issuing_inst->pcState().instAddr()));

    DPRINTF(IQ, "CompSimp: DIT inflight: %d\n", ditInflight);

    if(cpsr.dit) {
        DPRINTF(IQ, "CompSimp: DIT is set skipping fast pass!\n");
        return false;
    } else if (ditInflight > 0) {
        DPRINTF(IQ, "CompSimp: DIT inflight skipping fast pass! Counter value is %d\n", ditInflight);
        return false;
    }

    if (issuing_inst->opClass() == IntMultOp) {
        override = IntMultOpAnalysis(issuing_inst, override_latency);
    } else if (issuing_inst->opClass() == IntDivOp) {
        override = IntDivOpAnalysis(issuing_inst, override_latency);
    }


    return override;
}

} // namespace o3
} // namespace gem5

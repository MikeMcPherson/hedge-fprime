// ======================================================================
// \title  Gps.cpp
// \author kq9p
// \brief  cpp file for Gps component implementation class
// ======================================================================

#include "Components/Gps/Gps.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Gps ::
    Gps(const char* const compName) :
      GpsComponentBase(compName)
  {

  }

  Gps ::
    ~Gps()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void Gps ::
    gpsSetState_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::On gpsNewState
    )
  {
    // TODO Code to enable/disable GPS receiver
    if(this->gpsState != gpsNewState) this->gpsTransitions += 1;
    this->gpsState = gpsNewState;
    this->log_ACTIVITY_HI_gpsStateSet(gpsNewState);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}

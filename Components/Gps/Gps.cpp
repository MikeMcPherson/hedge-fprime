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
    this->gpsState = gpsNewState;
    // TODO Code to enable/disable GPS receiver
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}

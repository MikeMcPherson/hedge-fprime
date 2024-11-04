// ======================================================================
// \title  Gps.hpp
// \author kq9p
// \brief  hpp file for Gps component implementation class
// ======================================================================

#ifndef Components_Gps_HPP
#define Components_Gps_HPP

#include "Components/Gps/GpsComponentAc.hpp"

namespace Components {

  class Gps :
    public GpsComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Gps object
      Gps(
          const char* const compName //!< The component name
      );

      //! Destroy Gps object
      ~Gps();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command gpsSetState
      void gpsSetState_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On gpsNewState
      ) override;
    
    Fw::On gpsState = Fw::On::OFF;  //! GPS enable/disable state
    U64 gpsTransitions = 0;         //! Number of enable/disable transitions since last reset

  };

}

#endif

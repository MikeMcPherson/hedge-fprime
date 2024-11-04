module Components {
    @ Component for F Prime FSW framework.
    active component Gps {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        async command gpsSetState(gpsNewState: Fw.On) opcode 0

        # @ Example telemetry counter
        telemetry gpsLatitude: F32
        telemetry gpsLongitude: F32
        telemetry gpsAltitude: F32
        telemetry gpsSatCount: F32

        # @ Example event
        event gpsLockAcquired() \
            severity activity high \
            format "GPS lock acquired"

        event gpsLockLost() \
            severity warning high \
            format "GPS lock lost"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}
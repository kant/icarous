//
// Created by Swee Balachandran on 12/22/17.
//

#ifndef ICAROUS_CFS_TRAJECTORY_H
#define ICAROUS_CFS_TRAJECTORY_H

/// Required header files.
#include "cfe.h"
#include "cfe_error.h"
#include "cfe_evs.h"
#include "cfe_sb.h"
#include "cfe_es.h"
#include <string.h>

#include "TrajectoryPlanner_proxy.h"
#include "msgids/msgids.h"
#include "Icarous_msg.h"

#define TRAJECTORY_STARTUP_INF_EID 0
#define TRAJECTORY_COMMAND_ERR_EID 1
#define TRAJECTORY_PIPE_DEPTH 100
#define TRAJECTORY_PIPE_NAME "TRAJECTORY_PIPE"
#define TRAJECTORY_MAJOR_VERSION 1
#define TRAJECTORY_MINOR_VERSION 0

/**
 * \struct TrajectoryAppData
 * Structure to hold app data
 */
typedef struct{
    CFE_SB_PipeId_t    Trajectory_Pipe;       ///< pipe variable
    CFE_SB_MsgPtr_t    Trajectory_MsgPtr;     ///< msg pointer to SB message
    FlightData* fdata;                      ///< opaque pointer to store FlightDataManager
    PathPlanner* pplanner;             ///< opaque pointer to TrajectoryMonitor
}TrajectoryAppData_t;


void TRAJECTORY_AppMain(void);

void TRAJECTORY_AppInit(void);

void TRAJECTORY_AppCleanUp();

void TRAJECTORY_ProcessPacket();

void TrajServiceHandler(service_t* msg);

TrajectoryAppData_t TrajectoryAppData;
service_t trajServiceResponse;


#endif //ICAROUS_CFS_TRAJECTORY_H
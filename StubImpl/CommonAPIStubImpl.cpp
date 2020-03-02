#include "CommonAPIStubImpl.h"
#include <QDebug>
CommonAPIStubImpl::CommonAPIStubImpl()
{
}

void CommonAPIStubImpl::updateAdasInfo(int value)
{

    if (value % 2 == 1) {
        qDebug() << Q_FUNC_INFO << "value : " << value;
        //[0]
        MCUManagerType::StAdasInfo adas_info;
        adas_info.setDisp_type(MCUManagerType::EnumADASDispType::ADAS_DISP_ON);
        qDebug() << Q_FUNC_INFO << "setDisp_type(MCUManagerType::EnumADASDispType::ADAS_DISP_ON) - [1]";

        //[1]
        MCUManagerType::StCCObject ccobject;
        ccobject.setX(100);
        ccobject.setY(200);
        ccobject.setScale(30);

        qDebug() << Q_FUNC_INFO << "ccobject.setX(100);    ";
        qDebug() << Q_FUNC_INFO << "ccobject.setY(200);    ";
        qDebug() << Q_FUNC_INFO << "ccobject.setScale(30); ";

        MCUManagerType::StADASVehicleInfo vehicleInfo;
        vehicleInfo.setVehicle_id(MCUManagerType::EnumADASVehicleId::VEHICLE_ID_FRONT);
        vehicleInfo.setVehicle_info(ccobject);
        vehicleInfo.setVehicle_status(MCUManagerType::EnumADASVehicleStatus::VEHICLE_STATUS_WARNING);
        vehicleInfo.setTarget_dist_type(MCUManagerType::EnumSCCTargetDispType::TARGET_DISP_SCC_ML);

        qDebug() << Q_FUNC_INFO << "setVehicle_id(MCUManagerType::EnumADASVehicleId::VEHICLE_ID_FRONT);               - [1]";
        qDebug() << Q_FUNC_INFO << "setVehicle_info(ccobject);                                                        - [x]";
        qDebug() << Q_FUNC_INFO << "setVehicle_status(MCUManagerType::EnumADASVehicleStatus::VEHICLE_STATUS_WARNING); - [2]";
        qDebug() << Q_FUNC_INFO << "setTarget_dist_type(MCUManagerType::EnumSCCTargetDispType::TARGET_DISP_SCC_ML);   - [3]";

        MCUManagerType::VehicleInfoList vehicleInfoList;
        vehicleInfoList.push_back(vehicleInfo);

        adas_info.setVehicle_info_list(vehicleInfoList);

        //[2]
        MCUManagerType::StADASLaneInfo adasLaneInfo;

        adasLaneInfo.setL_lane_x(40);
        adasLaneInfo.setR_lane_x(50);
        adasLaneInfo.setLane_type(MCUManagerType::EnumADASLaneType::LANE_TYPE_STRAIGHT);
        adasLaneInfo.setL_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);
        adasLaneInfo.setR_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);
        adasLaneInfo.setLane_curve_ratio(11);
        adasLaneInfo.setLane_active_status(MCUManagerType::EnumADASLaneActive::LANE_ACTIVE_RIGHT);

        qDebug() << Q_FUNC_INFO << "setL_lane_x(40);                                                             -[40]";
        qDebug() << Q_FUNC_INFO << "setR_lane_x(50);                                                             -[50]";
        qDebug() << Q_FUNC_INFO << "setLane_type(MCUManagerType::EnumADASLaneType::LANE_TYPE_STRAIGHT);          -[1]";
        qDebug() << Q_FUNC_INFO << "setL_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);   -[1]";
        qDebug() << Q_FUNC_INFO << "setR_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);   -[1]";
        qDebug() << Q_FUNC_INFO << "setLane_curve_ratio(11);                                                     -[11]";
        qDebug() << Q_FUNC_INFO << "setLane_active_status(MCUManagerType::EnumADASLaneActive::LANE_ACTIVE_RIGHT);-[1]";

        adas_info.setLane_info(adasLaneInfo);

        setAdasInfoAttribute(adas_info);

    } else {
        qDebug() << Q_FUNC_INFO << "value : " << value;

        qDebug() << Q_FUNC_INFO << "ccobject.setX(10);    ";
        qDebug() << Q_FUNC_INFO << "ccobject.setY(20);    ";
        qDebug() << Q_FUNC_INFO << "ccobject.setScale(3); ";

        //[0]
        MCUManagerType::StCCObject ccobject;
        ccobject.setX(10);
        ccobject.setY(20);
        ccobject.setScale(3);

        qDebug() << Q_FUNC_INFO << "setVehicle_id(MCUManagerType::EnumADASVehicleId::VEHICLE_ID_FRONT);               - [1]";
        qDebug() << Q_FUNC_INFO << "setVehicle_info(ccobject);                                                        - [x]";
        qDebug() << Q_FUNC_INFO << "setVehicle_status(MCUManagerType::EnumADASVehicleStatus::VEHICLE_STATUS_WARNING); - [2]";
        qDebug() << Q_FUNC_INFO << "setTarget_dist_type(MCUManagerType::EnumSCCTargetDispType::TARGET_DISP_SCC_ML);   - [3]";

        MCUManagerType::StADASVehicleInfo vehicleInfo;
        vehicleInfo.setVehicle_id(MCUManagerType::EnumADASVehicleId::VEHICLE_ID_FRONT);
        vehicleInfo.setVehicle_info(ccobject);
        vehicleInfo.setVehicle_status(MCUManagerType::EnumADASVehicleStatus::VEHICLE_STATUS_WARNING);
        vehicleInfo.setTarget_dist_type(MCUManagerType::EnumSCCTargetDispType::TARGET_DISP_SCC_ML);

        MCUManagerType::VehicleInfoList vehicleInfoList;
        vehicleInfoList.push_back(vehicleInfo);

        MCUManagerType::StAdasInfo adas_info;

        adas_info.setVehicle_info_list(vehicleInfoList);

        //[1]
        adas_info.setDisp_type(MCUManagerType::EnumADASDispType::ADAS_DISP_ON);
        qDebug() << Q_FUNC_INFO << "setDisp_type(MCUManagerType::EnumADASDispType::ADAS_DISP_ON) - [1]";

        //[2]
        MCUManagerType::StADASLaneInfo adasLaneInfo;

        adasLaneInfo.setL_lane_x(40);
        adasLaneInfo.setR_lane_x(50);
        adasLaneInfo.setLane_type(MCUManagerType::EnumADASLaneType::LANE_TYPE_STRAIGHT);
        adasLaneInfo.setL_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);
        adasLaneInfo.setR_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);
        adasLaneInfo.setLane_curve_ratio(11);
        adasLaneInfo.setLane_active_status(MCUManagerType::EnumADASLaneActive::LANE_ACTIVE_RIGHT);

        qDebug() << Q_FUNC_INFO << "setL_lane_x(40);                                                             -[40]";
        qDebug() << Q_FUNC_INFO << "setR_lane_x(50);                                                             -[50]";
        qDebug() << Q_FUNC_INFO << "setLane_type(MCUManagerType::EnumADASLaneType::LANE_TYPE_STRAIGHT);          -[1]";
        qDebug() << Q_FUNC_INFO << "setL_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);   -[1]";
        qDebug() << Q_FUNC_INFO << "setR_lca_status(MCUManagerType::EnumADASLCAvailStatus::LANE_STATUS_READY);   -[1]";
        qDebug() << Q_FUNC_INFO << "setLane_curve_ratio(11);                                                     -[11]";
        qDebug() << Q_FUNC_INFO << "setLane_active_status(MCUManagerType::EnumADASLaneActive::LANE_ACTIVE_RIGHT);-[1]";

        adas_info.setLane_info(adasLaneInfo);

        setAdasInfoAttribute(adas_info);
    }
}

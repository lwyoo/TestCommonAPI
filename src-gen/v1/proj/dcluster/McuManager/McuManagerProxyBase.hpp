/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v202001100728.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_PROJ_DCLUSTER_MCUMANAGER_Mcu_Manager_PROXY_BASE_HPP_
#define V1_PROJ_DCLUSTER_MCUMANAGER_Mcu_Manager_PROXY_BASE_HPP_

#include <v1/proj/dcluster/McuManager/McuManager.hpp>


#include <v1/proj/dcluster/McuManager/McuManagerTypes.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/ByteBuffer.hpp>
#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <cstdint>
#include <vector>

#include <CommonAPI/Attribute.hpp>
#include <CommonAPI/Event.hpp>
#include <CommonAPI/Proxy.hpp>
#include <functional>
#include <future>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace proj {
namespace dcluster {
namespace McuManager {

class McuManagerProxyBase
    : virtual public CommonAPI::Proxy {
public:
    typedef CommonAPI::ObservableAttribute< bool> MainContentsDisplayControlAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumDrivingState> DrivingStateAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveModeInfo> DriveModeAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StVariantInfo> VariantAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StEOLInfo> EOLAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StSWVariantInfo> SWVariantAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumIGNState> IGN1StateAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumIGNState> IGN3StateAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumSpeedoUnit> SpeedoUnitAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTripDriveModeInfo> TripDriveModeAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTripDTEInfo> TripDTEAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTripFuelEconomyInfo> TripFuelEconomyAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTripAccumulatedInfo> TripAccumulatedAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTripDriveInfo> TripDriveInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTripSpeedMeter> TripDigitalSpeedMeterAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumPowerFlow> TripPowerFlowDiagramAttribute;
    typedef CommonAPI::ObservableAttribute< uint8_t> TripUREALevelAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumTransmissionTempLevel> TripTransmissionTempAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StEngineCoolantTemp> TripEngineCoolantTempAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StEnergyFlowInfo> EnergyFlowAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StMyDrvModeInfo> MyDrivingModeAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumTBTDisplayType> TBTDisplayTypeAttribute;
    typedef CommonAPI::ObservableAttribute< bool> TBTDisplayTollgateAttribute;
    typedef CommonAPI::ObservableAttribute< uint8_t> TBTPreliminaryInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumTBTPageState> TBTDestInfoPageStateAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumTBTPointType> TBTPointTypeAttribute;
    typedef CommonAPI::ObservableAttribute< uint8_t> TBTDirectionAttribute;
    typedef CommonAPI::ObservableAttribute< uint16_t> TBTRoadDisplayAttribute;
    typedef CommonAPI::ObservableAttribute< uint8_t> TBTSideRoadDisplayAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTBTDistDestInfo> TBTDistanceToDestinationAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTBTTurnInfo> TBTDistanceUntilTurnAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTBTDestinationTime> TBTExpectedDestTimeAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StTBTRemainTime> TBTExpectedRemainTimeAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> TBTGuideTPInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> TBTDestTPInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> TBTViaPoint1TPInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> TBTViaPoint2TPInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> TBTViaPoint3TPInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> TBTViaPoint4TPInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveAssistCCInfoTTC> DriveAssistCruiseControlTTCAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveAssistCCInfoReal> DriveAssistCruiseControlRealAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveAssistLaneInfo> DriveAssistLaneAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveAssistDAWInfo> DriveAssistDAWAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveAssistISLWInfo> DriveAssistISLWAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveAssistAWDInfo> DriveAssistAWDAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StDriveAssistTPMSInfo> DriveAssistTPMSAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo> AdasInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsGearInfo> ContentsGearAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsCCInfo> ContentsCCAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsSCCInfo> ContentsSCCAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsCoasting> ContentsCoastingAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsDISInfo> ContentsDISAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsDTE> ContentsDTEInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsISLWInfo> ContentsISLWAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsOAT> ContentsOATAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsODO> ContentsODOMeterAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumEcoPwrDispState> EcoPowerDisplayInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsRSBRInfo> ContentsRSBRAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsSpdLimitInfo> ContentsSpeedLimitAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumMasterWarnCmd> MasterWarnCmdAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpAMFMInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpXMInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpDABInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpDMBInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpJukeBoxInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpIpodInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpUSBInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpBlueToothInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpAppleCarPlayInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpAndroidAutoInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpIboxInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpCDInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::TPData> AvTpBaiduMInfoAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StEventContentsInfo> EventContentsFullAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::StEventContentsInfo> EventContentsMiniAttribute;
    typedef CommonAPI::ObservableAttribute< bool> EventAccessoryAttribute;
    typedef CommonAPI::ObservableAttribute< bool> PowerTailGateWarnStateAttribute;
    typedef CommonAPI::ObservableAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USM_LANGUAGE_VALUE> DisplayLanguageAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_SccReactionAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_DrivingAssist_LeadingVehicleDepartureAlertAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_DrivingAssist_LaneFollowingAssistAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_DrivingAssist_HighwayDrivingAssistAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_DrivingAssist_HighwayAutoSpeedZoneSlowDownAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_DrivingAssist_HighwayAutoCurveSlowDownAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_DrivingAssist_SpeedLimitWarningAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_DriverAttentionWarningAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_WarningTimingAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_WarningVolumeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_LaneSafetyAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_LaneSafety_ModeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_ForwardSafetyAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_BlindSpotSafety_SpotViewAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_BlindSpotSafety_SafetyExitAssistAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_BlindSpotSafety_WarningOnlyAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDriverAssist_BlindSpotSafety_RearCrossTrafficSafetyAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDoor_AutoLockAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDoor_AutoUnlock_KeyOrPowerAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDoor_AutoUnlockAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDoor_HornFeedbackAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDoor_PowerTailgateAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDoor_PowerTailgateSpeedAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmDoor_SmartTailgateAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmLights_OneTouchTurnSignalAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmLights_AmbientLightAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmLights_HeadlightDelayAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmLights_HighBeamAssistAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmSound_ClusterVoiceGuidanceVolumeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmSound_ParkAssistVolumeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmSound_WelcomeSoundAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_SeatEasyAccessAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_WelcomeMirrorLight_TitleAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_WelcomeMirrorLight_OnDoorUnlockAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_WelcomeMirrorLight_OnDriverApproachAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_MirrorAutoFoldingAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_WirelessChargingSystemAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_TrafficInformationAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_WipreLightsDisplayAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_AutoRearWiperInRAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_GearPositionPopupAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmConvenience_IcyRoadWarningAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmServiceInterval_ModeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmServiceInterval_EnableServiceIntervalAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmServiceInterval_ResetAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmOther_FuelEconomyResetAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmOther_FuelEconomyUnitAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmOther_TemperatureUnitAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmOther_TirePressureUnitAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmOther_SpeedUnitAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmOther_TorqueUnitAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmOther_TurboBoostPressureUnitAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_GreenZoneEVDriveAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_CoastingGuideEnableAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_CoastingGuideSoundAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_StartCoastingAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_ChargingConnectorLockingModeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_ChargingConnectorConditionAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_AuxiliaryBatterySaverPlusAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmLanguageAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMServiceReminder> UsmService_ReminderAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::USMItem32> UsmEcoVehicle_VolumeControlFunctionForVESSAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::dcluster::McuManager::McuManagerTypes::GroupTabInfo> LastTabInfoAttribute;
    typedef CommonAPI::Event<
        ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumStreerWheelKey
    > NotifySteerWheelKeyEvent;
    typedef CommonAPI::Event<
        ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumIGNState
    > NotifyIGNStateEvent;
    typedef CommonAPI::Event<
        ::v1::proj::dcluster::McuManager::McuManagerTypes::StContentsGearInfo
    > NotifyContentsGearStateEvent;
    typedef CommonAPI::Event<
        ::v1::proj::dcluster::McuManager::McuManagerTypes::StEventContentsInfo
    > NotifyEventContentsEvent;
    typedef CommonAPI::Event<
    > NotifyMasterWarnInfoEvent;
    typedef CommonAPI::Event<
        ::v1::proj::dcluster::McuManager::McuManagerTypes::EnumMasterWarnCmd
    > NotifyMasterWarnCmdEvent;
    typedef CommonAPI::Event<
        ::v1::proj::dcluster::McuManager::McuManagerTypes::StSoundInfo, ::v1::proj::dcluster::McuManager::McuManagerTypes::StSoundInfo, ::v1::proj::dcluster::McuManager::McuManagerTypes::StSoundInfo, ::v1::proj::dcluster::McuManager::McuManagerTypes::StSoundInfo
    > NotifySoundEvent;

    typedef std::function<void(const CommonAPI::CallStatus&, const bool&)> CommandAsyncCallback;

    virtual MainContentsDisplayControlAttribute& getMainContentsDisplayControlAttribute() = 0;
    virtual DrivingStateAttribute& getDrivingStateAttribute() = 0;
    virtual DriveModeAttribute& getDriveModeAttribute() = 0;
    virtual VariantAttribute& getVariantAttribute() = 0;
    virtual EOLAttribute& getEOLAttribute() = 0;
    virtual SWVariantAttribute& getSWVariantAttribute() = 0;
    virtual IGN1StateAttribute& getIGN1StateAttribute() = 0;
    virtual IGN3StateAttribute& getIGN3StateAttribute() = 0;
    virtual SpeedoUnitAttribute& getSpeedoUnitAttribute() = 0;
    virtual TripDriveModeAttribute& getTripDriveModeAttribute() = 0;
    virtual TripDTEAttribute& getTripDTEAttribute() = 0;
    virtual TripFuelEconomyAttribute& getTripFuelEconomyAttribute() = 0;
    virtual TripAccumulatedAttribute& getTripAccumulatedAttribute() = 0;
    virtual TripDriveInfoAttribute& getTripDriveInfoAttribute() = 0;
    virtual TripDigitalSpeedMeterAttribute& getTripDigitalSpeedMeterAttribute() = 0;
    virtual TripPowerFlowDiagramAttribute& getTripPowerFlowDiagramAttribute() = 0;
    virtual TripUREALevelAttribute& getTripUREALevelAttribute() = 0;
    virtual TripTransmissionTempAttribute& getTripTransmissionTempAttribute() = 0;
    virtual TripEngineCoolantTempAttribute& getTripEngineCoolantTempAttribute() = 0;
    virtual EnergyFlowAttribute& getEnergyFlowAttribute() = 0;
    virtual MyDrivingModeAttribute& getMyDrivingModeAttribute() = 0;
    virtual TBTDisplayTypeAttribute& getTBTDisplayTypeAttribute() = 0;
    virtual TBTDisplayTollgateAttribute& getTBTDisplayTollgateAttribute() = 0;
    virtual TBTPreliminaryInfoAttribute& getTBTPreliminaryInfoAttribute() = 0;
    virtual TBTDestInfoPageStateAttribute& getTBTDestInfoPageStateAttribute() = 0;
    virtual TBTPointTypeAttribute& getTBTPointTypeAttribute() = 0;
    virtual TBTDirectionAttribute& getTBTDirectionAttribute() = 0;
    virtual TBTRoadDisplayAttribute& getTBTRoadDisplayAttribute() = 0;
    virtual TBTSideRoadDisplayAttribute& getTBTSideRoadDisplayAttribute() = 0;
    virtual TBTDistanceToDestinationAttribute& getTBTDistanceToDestinationAttribute() = 0;
    virtual TBTDistanceUntilTurnAttribute& getTBTDistanceUntilTurnAttribute() = 0;
    virtual TBTExpectedDestTimeAttribute& getTBTExpectedDestTimeAttribute() = 0;
    virtual TBTExpectedRemainTimeAttribute& getTBTExpectedRemainTimeAttribute() = 0;
    virtual TBTGuideTPInfoAttribute& getTBTGuideTPInfoAttribute() = 0;
    virtual TBTDestTPInfoAttribute& getTBTDestTPInfoAttribute() = 0;
    virtual TBTViaPoint1TPInfoAttribute& getTBTViaPoint1TPInfoAttribute() = 0;
    virtual TBTViaPoint2TPInfoAttribute& getTBTViaPoint2TPInfoAttribute() = 0;
    virtual TBTViaPoint3TPInfoAttribute& getTBTViaPoint3TPInfoAttribute() = 0;
    virtual TBTViaPoint4TPInfoAttribute& getTBTViaPoint4TPInfoAttribute() = 0;
    virtual DriveAssistCruiseControlTTCAttribute& getDriveAssistCruiseControlTTCAttribute() = 0;
    virtual DriveAssistCruiseControlRealAttribute& getDriveAssistCruiseControlRealAttribute() = 0;
    virtual DriveAssistLaneAttribute& getDriveAssistLaneAttribute() = 0;
    virtual DriveAssistDAWAttribute& getDriveAssistDAWAttribute() = 0;
    virtual DriveAssistISLWAttribute& getDriveAssistISLWAttribute() = 0;
    virtual DriveAssistAWDAttribute& getDriveAssistAWDAttribute() = 0;
    virtual DriveAssistTPMSAttribute& getDriveAssistTPMSAttribute() = 0;
    virtual AdasInfoAttribute& getAdasInfoAttribute() = 0;
    virtual ContentsGearAttribute& getContentsGearAttribute() = 0;
    virtual ContentsCCAttribute& getContentsCCAttribute() = 0;
    virtual ContentsSCCAttribute& getContentsSCCAttribute() = 0;
    virtual ContentsCoastingAttribute& getContentsCoastingAttribute() = 0;
    virtual ContentsDISAttribute& getContentsDISAttribute() = 0;
    virtual ContentsDTEInfoAttribute& getContentsDTEInfoAttribute() = 0;
    virtual ContentsISLWAttribute& getContentsISLWAttribute() = 0;
    virtual ContentsOATAttribute& getContentsOATAttribute() = 0;
    virtual ContentsODOMeterAttribute& getContentsODOMeterAttribute() = 0;
    virtual EcoPowerDisplayInfoAttribute& getEcoPowerDisplayInfoAttribute() = 0;
    virtual ContentsRSBRAttribute& getContentsRSBRAttribute() = 0;
    virtual ContentsSpeedLimitAttribute& getContentsSpeedLimitAttribute() = 0;
    virtual MasterWarnCmdAttribute& getMasterWarnCmdAttribute() = 0;
    virtual AvTpAMFMInfoAttribute& getAvTpAMFMInfoAttribute() = 0;
    virtual AvTpXMInfoAttribute& getAvTpXMInfoAttribute() = 0;
    virtual AvTpDABInfoAttribute& getAvTpDABInfoAttribute() = 0;
    virtual AvTpDMBInfoAttribute& getAvTpDMBInfoAttribute() = 0;
    virtual AvTpJukeBoxInfoAttribute& getAvTpJukeBoxInfoAttribute() = 0;
    virtual AvTpIpodInfoAttribute& getAvTpIpodInfoAttribute() = 0;
    virtual AvTpUSBInfoAttribute& getAvTpUSBInfoAttribute() = 0;
    virtual AvTpBlueToothInfoAttribute& getAvTpBlueToothInfoAttribute() = 0;
    virtual AvTpAppleCarPlayInfoAttribute& getAvTpAppleCarPlayInfoAttribute() = 0;
    virtual AvTpAndroidAutoInfoAttribute& getAvTpAndroidAutoInfoAttribute() = 0;
    virtual AvTpIboxInfoAttribute& getAvTpIboxInfoAttribute() = 0;
    virtual AvTpCDInfoAttribute& getAvTpCDInfoAttribute() = 0;
    virtual AvTpBaiduMInfoAttribute& getAvTpBaiduMInfoAttribute() = 0;
    virtual EventContentsFullAttribute& getEventContentsFullAttribute() = 0;
    virtual EventContentsMiniAttribute& getEventContentsMiniAttribute() = 0;
    virtual EventAccessoryAttribute& getEventAccessoryAttribute() = 0;
    virtual PowerTailGateWarnStateAttribute& getPowerTailGateWarnStateAttribute() = 0;
    virtual DisplayLanguageAttribute& getDisplayLanguageAttribute() = 0;
    virtual UsmDriverAssist_SccReactionAttribute& getUsmDriverAssist_SccReactionAttribute() = 0;
    virtual UsmDriverAssist_DrivingAssist_LeadingVehicleDepartureAlertAttribute& getUsmDriverAssist_DrivingAssist_LeadingVehicleDepartureAlertAttribute() = 0;
    virtual UsmDriverAssist_DrivingAssist_LaneFollowingAssistAttribute& getUsmDriverAssist_DrivingAssist_LaneFollowingAssistAttribute() = 0;
    virtual UsmDriverAssist_DrivingAssist_HighwayDrivingAssistAttribute& getUsmDriverAssist_DrivingAssist_HighwayDrivingAssistAttribute() = 0;
    virtual UsmDriverAssist_DrivingAssist_HighwayAutoSpeedZoneSlowDownAttribute& getUsmDriverAssist_DrivingAssist_HighwayAutoSpeedZoneSlowDownAttribute() = 0;
    virtual UsmDriverAssist_DrivingAssist_HighwayAutoCurveSlowDownAttribute& getUsmDriverAssist_DrivingAssist_HighwayAutoCurveSlowDownAttribute() = 0;
    virtual UsmDriverAssist_DrivingAssist_SpeedLimitWarningAttribute& getUsmDriverAssist_DrivingAssist_SpeedLimitWarningAttribute() = 0;
    virtual UsmDriverAssist_DriverAttentionWarningAttribute& getUsmDriverAssist_DriverAttentionWarningAttribute() = 0;
    virtual UsmDriverAssist_WarningTimingAttribute& getUsmDriverAssist_WarningTimingAttribute() = 0;
    virtual UsmDriverAssist_WarningVolumeAttribute& getUsmDriverAssist_WarningVolumeAttribute() = 0;
    virtual UsmDriverAssist_LaneSafetyAttribute& getUsmDriverAssist_LaneSafetyAttribute() = 0;
    virtual UsmDriverAssist_LaneSafety_ModeAttribute& getUsmDriverAssist_LaneSafety_ModeAttribute() = 0;
    virtual UsmDriverAssist_ForwardSafetyAttribute& getUsmDriverAssist_ForwardSafetyAttribute() = 0;
    virtual UsmDriverAssist_BlindSpotSafety_SpotViewAttribute& getUsmDriverAssist_BlindSpotSafety_SpotViewAttribute() = 0;
    virtual UsmDriverAssist_BlindSpotSafety_SafetyExitAssistAttribute& getUsmDriverAssist_BlindSpotSafety_SafetyExitAssistAttribute() = 0;
    virtual UsmDriverAssist_BlindSpotSafety_WarningOnlyAttribute& getUsmDriverAssist_BlindSpotSafety_WarningOnlyAttribute() = 0;
    virtual UsmDriverAssist_BlindSpotSafety_RearCrossTrafficSafetyAttribute& getUsmDriverAssist_BlindSpotSafety_RearCrossTrafficSafetyAttribute() = 0;
    virtual UsmDoor_AutoLockAttribute& getUsmDoor_AutoLockAttribute() = 0;
    virtual UsmDoor_AutoUnlock_KeyOrPowerAttribute& getUsmDoor_AutoUnlock_KeyOrPowerAttribute() = 0;
    virtual UsmDoor_AutoUnlockAttribute& getUsmDoor_AutoUnlockAttribute() = 0;
    virtual UsmDoor_HornFeedbackAttribute& getUsmDoor_HornFeedbackAttribute() = 0;
    virtual UsmDoor_PowerTailgateAttribute& getUsmDoor_PowerTailgateAttribute() = 0;
    virtual UsmDoor_PowerTailgateSpeedAttribute& getUsmDoor_PowerTailgateSpeedAttribute() = 0;
    virtual UsmDoor_SmartTailgateAttribute& getUsmDoor_SmartTailgateAttribute() = 0;
    virtual UsmLights_OneTouchTurnSignalAttribute& getUsmLights_OneTouchTurnSignalAttribute() = 0;
    virtual UsmLights_AmbientLightAttribute& getUsmLights_AmbientLightAttribute() = 0;
    virtual UsmLights_HeadlightDelayAttribute& getUsmLights_HeadlightDelayAttribute() = 0;
    virtual UsmLights_HighBeamAssistAttribute& getUsmLights_HighBeamAssistAttribute() = 0;
    virtual UsmSound_ClusterVoiceGuidanceVolumeAttribute& getUsmSound_ClusterVoiceGuidanceVolumeAttribute() = 0;
    virtual UsmSound_ParkAssistVolumeAttribute& getUsmSound_ParkAssistVolumeAttribute() = 0;
    virtual UsmSound_WelcomeSoundAttribute& getUsmSound_WelcomeSoundAttribute() = 0;
    virtual UsmConvenience_SeatEasyAccessAttribute& getUsmConvenience_SeatEasyAccessAttribute() = 0;
    virtual UsmConvenience_WelcomeMirrorLight_TitleAttribute& getUsmConvenience_WelcomeMirrorLight_TitleAttribute() = 0;
    virtual UsmConvenience_WelcomeMirrorLight_OnDoorUnlockAttribute& getUsmConvenience_WelcomeMirrorLight_OnDoorUnlockAttribute() = 0;
    virtual UsmConvenience_WelcomeMirrorLight_OnDriverApproachAttribute& getUsmConvenience_WelcomeMirrorLight_OnDriverApproachAttribute() = 0;
    virtual UsmConvenience_MirrorAutoFoldingAttribute& getUsmConvenience_MirrorAutoFoldingAttribute() = 0;
    virtual UsmConvenience_WirelessChargingSystemAttribute& getUsmConvenience_WirelessChargingSystemAttribute() = 0;
    virtual UsmConvenience_TrafficInformationAttribute& getUsmConvenience_TrafficInformationAttribute() = 0;
    virtual UsmConvenience_WipreLightsDisplayAttribute& getUsmConvenience_WipreLightsDisplayAttribute() = 0;
    virtual UsmConvenience_AutoRearWiperInRAttribute& getUsmConvenience_AutoRearWiperInRAttribute() = 0;
    virtual UsmConvenience_GearPositionPopupAttribute& getUsmConvenience_GearPositionPopupAttribute() = 0;
    virtual UsmConvenience_IcyRoadWarningAttribute& getUsmConvenience_IcyRoadWarningAttribute() = 0;
    virtual UsmServiceInterval_ModeAttribute& getUsmServiceInterval_ModeAttribute() = 0;
    virtual UsmServiceInterval_EnableServiceIntervalAttribute& getUsmServiceInterval_EnableServiceIntervalAttribute() = 0;
    virtual UsmServiceInterval_ResetAttribute& getUsmServiceInterval_ResetAttribute() = 0;
    virtual UsmOther_FuelEconomyResetAttribute& getUsmOther_FuelEconomyResetAttribute() = 0;
    virtual UsmOther_FuelEconomyUnitAttribute& getUsmOther_FuelEconomyUnitAttribute() = 0;
    virtual UsmOther_TemperatureUnitAttribute& getUsmOther_TemperatureUnitAttribute() = 0;
    virtual UsmOther_TirePressureUnitAttribute& getUsmOther_TirePressureUnitAttribute() = 0;
    virtual UsmOther_SpeedUnitAttribute& getUsmOther_SpeedUnitAttribute() = 0;
    virtual UsmOther_TorqueUnitAttribute& getUsmOther_TorqueUnitAttribute() = 0;
    virtual UsmOther_TurboBoostPressureUnitAttribute& getUsmOther_TurboBoostPressureUnitAttribute() = 0;
    virtual UsmEcoVehicle_GreenZoneEVDriveAttribute& getUsmEcoVehicle_GreenZoneEVDriveAttribute() = 0;
    virtual UsmEcoVehicle_CoastingGuideEnableAttribute& getUsmEcoVehicle_CoastingGuideEnableAttribute() = 0;
    virtual UsmEcoVehicle_CoastingGuideSoundAttribute& getUsmEcoVehicle_CoastingGuideSoundAttribute() = 0;
    virtual UsmEcoVehicle_StartCoastingAttribute& getUsmEcoVehicle_StartCoastingAttribute() = 0;
    virtual UsmEcoVehicle_ChargingConnectorLockingModeAttribute& getUsmEcoVehicle_ChargingConnectorLockingModeAttribute() = 0;
    virtual UsmEcoVehicle_ChargingConnectorConditionAttribute& getUsmEcoVehicle_ChargingConnectorConditionAttribute() = 0;
    virtual UsmEcoVehicle_AuxiliaryBatterySaverPlusAttribute& getUsmEcoVehicle_AuxiliaryBatterySaverPlusAttribute() = 0;
    virtual UsmLanguageAttribute& getUsmLanguageAttribute() = 0;
    virtual UsmService_ReminderAttribute& getUsmService_ReminderAttribute() = 0;
    virtual UsmEcoVehicle_VolumeControlFunctionForVESSAttribute& getUsmEcoVehicle_VolumeControlFunctionForVESSAttribute() = 0;
    virtual LastTabInfoAttribute& getLastTabInfoAttribute() = 0;

    virtual NotifySteerWheelKeyEvent& getNotifySteerWheelKeyEvent() = 0;
    virtual NotifyIGNStateEvent& getNotifyIGNStateEvent() = 0;
    virtual NotifyContentsGearStateEvent& getNotifyContentsGearStateEvent() = 0;
    virtual NotifyEventContentsEvent& getNotifyEventContentsEvent() = 0;
    virtual NotifyMasterWarnInfoEvent& getNotifyMasterWarnInfoEvent() = 0;
    virtual NotifyMasterWarnCmdEvent& getNotifyMasterWarnCmdEvent() = 0;
    virtual NotifySoundEvent& getNotifySoundEvent() = 0;

    virtual void Command(const uint8_t &_id, const ::v1::proj::dcluster::McuManager::McuManagerTypes::CmdData &_data, CommonAPI::CallStatus &_internalCallStatus, bool &_result, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> CommandAsync(const uint8_t &_id, const ::v1::proj::dcluster::McuManager::McuManagerTypes::CmdData &_data, CommandAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
};

} // namespace McuManager
} // namespace dcluster
} // namespace proj
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_PROJ_DCLUSTER_MCUMANAGER_Mcu_Manager_PROXY_BASE_HPP_
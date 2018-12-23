/**
 ****************************************************************************************
 *
 * @file bletype.h
 *
 * @brief ble data structure definition
 *
 * Copyright (C) ViewTool 2018
 *
 * $Rev: 1.0$
 *
 * Change History:
 * 12/21/18: Initial release, working on capturing BLE data, see captured data in file: 2018.12.21-14.52.34.txt
 *
 ****************************************************************************************
 */

#ifndef _BLETYPE_H
#define _BLETYPE_H

#include <QtCore>

#if defined   (  __GNUC__  )
#include <stdint.h>
#else

/* exact-width signed integer types */
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

/* exact-width unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

#endif // __GNUC__ 

#define EVT_MASK_LEN        0x08
#define BD_ADDR_LEN         0x06
#define ACCESS_ADDR_LEN     0x04
#define BD_NAME_SIZE        0x20
#define ADV_DATA_LEN        0x1F
#define BLE_DATA_LEN        0x1B
#define SCAN_RSP_DATA_LEN   0x1F

/// Common 16-bit Universal Unique Identifier
enum {
    ATT_INVALID_UUID = 0,
    /*----------------- SERVICES ---------------------*/
    /// Generic Access Profile
    ATT_SVC_GENERIC_ACCESS              = 0x1800,
    /// Attribute Profile
    ATT_SVC_GENERIC_ATTRIBUTE,
    ///Immediate alert service
    ATT_SVC_IMMEDIATE_ALERT,
    ///Link Loss Service
    ATT_SVC_LINK_LOSS,
    ///Tx Power Service
    ATT_SVC_TX_POWER,
    ///Current Time Service
    ATT_SVC_CURRENT_TIME,
    ///Reference Time Update
    ATT_SVC_REF_TIME_UPDATE,
    ///Next DST Change
    ATT_SVC_NEXT_DST_CHANGE,
    ///Glucose
    ATT_SVC_GLUCOSE                             = 0x1808,
    ///Health Thermometer Service
    ATT_SVC_HEALTH_THERMOM                      = 0x1809,
    ///Device Information Service
    ATT_SVC_DEVICE_INFO                         = 0x180A,
    ///Network availability - draft
    ATT_SVC_NETWORK_AVAIL_SVC,
    ///Watchdog - draft
    ATT_SVC_WATCHDOG,
    ///Heart Rate - draft
    ATT_SVC_HEART_RATE,
    ///Phone Alert Status - draft
    ATT_SVC_PHONE_ALERT_STATUS,
    ///Battery Service - draft
    ATT_SVC_BATTERY_SERVICE,
    ///Blood pressure
    ATT_SVC_BLOOD_PRESSURE                      = 0x1810,
    ///HID
    ATT_SVC_HID                                 = 0x1812,
    ///Scan Parameters
    ATT_SVC_SCAN_PARAMETERS,

    /*------------------- UNITS ---------------------*/
    /// No defined unit
    ATT_UNIT_UNITLESS                       = 0x2700,
    /// Length Unit - Metre
    ATT_UNIT_METRE,
    //Mass unit - Kilogram
    ATT_UNIT_KG,
    ///Time unit - second
    ATT_UNIT_SECOND,
    ///Electric current unit - Ampere
    ATT_UNIT_AMPERE,
    ///Thermodynamic Temperature unit - Kelvin
    ATT_UNIT_KELVIN,
    /// Amount of substance unit - mole
    ATT_UNIT_MOLE,
    ///Luminous intensity unit - candela
    ATT_UNIT_CANDELA,
    ///Area unit - square metres
    ATT_UNIT_SQ_METRE                       = 0x2710,
    ///Colume unit - cubic metres
    ATT_UNIT_CUBIC_METRE,
    ///Velocity unit - metres per second
    ATT_UNIT_METRE_PER_SECOND,
    ///Acceleration unit - metres per second squared
    ATT_UNIT_METRES_PER_SEC_SQ,
    ///Wavenumber unit - reciprocal metre
    ATT_UNIT_RECIPROCAL_METRE,
    ///Density unit - kilogram per cubic metre
    ATT_UNIT_DENS_KG_PER_CUBIC_METRE,
    ///Surface density unit - kilogram per square metre
    ATT_UNIT_KG_PER_SQ_METRE,
    ///Specific volume unit - cubic metre per kilogram
    ATT_UNIT_CUBIC_METRE_PER_KG,
    ///Current density unit - ampere per square metre
    ATT_UNIT_AMPERE_PER_SQ_METRE,
    ///Magnetic field strength unit - Ampere per metre
    ATT_UNIT_AMPERE_PER_METRE,
    ///Amount concentration unit - mole per cubic metre
    ATT_UNIT_MOLE_PER_CUBIC_METRE,
    ///Mass Concentration unit - kilogram per cubic metre
    ATT_UNIT_MASS_KG_PER_CUBIC_METRE,
    ///Luminance unit - candela per square metre
    ATT_UNIT_CANDELA_PER_SQ_METRE,
    ///Refractive index unit
    ATT_UNIT_REFRACTIVE_INDEX,
    ///Relative permeability unit
    ATT_UNIT_RELATIVE_PERMEABILITY,
    ///Plane angle unit - radian
    ATT_UNIT_RADIAN                         = 0x2720,
    ///Solid angle unit - steradian
    ATT_UNIT_STERADIAN,
    ///Frequency unit - Hertz
    ATT_UNIT_HERTZ,
    ///Force unit - Newton
    ATT_UNIT_NEWTON,
    ///Pressure unit - Pascal
    ATT_UNIT_PASCAL,
    ///Energy unit - Joule
    ATT_UNIT_JOULE,
    ///Power unit - Watt
    ATT_UNIT_WATT,
    ///electric Charge unit - Coulomb
    ATT_UNIT_COULOMB,
    ///Electric potential difference - Volt
    ATT_UNIT_VOLT,
    ///Capacitance unit - Farad
    ATT_UNIT_FARAD,
    ///electric resistance unit - Ohm
    ATT_UNIT_OHM,
    ///Electric conductance - Siemens
    ATT_UNIT_SIEMENS,
    ///Magnetic flux unit - Weber
    ATT_UNIT_WEBER,
    ///Magnetic flux density unit - Tesla
    ATT_UNIT_TESLA,
    ///Inductance unit - Henry
    ATT_UNIT_HENRY,
    ///Temperature unit - degree Celsius
    ATT_UNIT_CELSIUS,
    ///Luminous flux unit - lumen
    ATT_UNIT_LUMEN,
    //Illuminance unit - lux
    ATT_UNIT_LUX,
    ///Activity referred to a radionuclide unit - becquerel
    ATT_UNIT_BECQUEREL,
    ///Absorbed dose unit - Gray
    ATT_UNIT_GRAY,
    ///Dose equivalent unit - Sievert
    ATT_UNIT_SIEVERT,
    ///Catalytic activity unit - Katal
    ATT_UNIT_KATAL,
    ///Synamic viscosity unit - Pascal second
    ATT_UNIT_PASCAL_SECOND                      = 0x2740,
    ///Moment of force unit - Newton metre
    ATT_UNIT_NEWTON_METRE,
    ///surface tension unit - Newton per metre
    ATT_UNIT_NEWTON_PER_METRE,
    ///Angular velocity unit - radian per second
    ATT_UNIT_RADIAN_PER_SECOND,
    ///Angular acceleration unit - radian per second squared
    ATT_UNIT_RADIAN_PER_SECOND_SQ,
    ///Heat flux density unit - Watt per square metre
    ATT_UNIT_WATT_PER_SQ_METRE,
    ///HEat capacity unit - Joule per Kelvin
    ATT_UNIT_JOULE_PER_KELVIN,
    ///Specific heat capacity unit - Joule per kilogram kelvin
    ATT_UNIT_JOULE_PER_KG_KELVIN,
    ///Specific Energy unit - Joule per kilogram
    ATT_UNIT_JOULE_PER_KG,
    ///Thermal conductivity - Watt per metre Kelvin
    ATT_UNIT_WATT_PER_METRE_KELVIN,
    ///Energy Density unit - joule per cubic metre
    ATT_UNIT_JOULE_PER_CUBIC_METRE,
    ///Electric field strength unit - volt per metre
    ATT_UNIT_VOLT_PER_METRE,
    ///Electric charge density unit - coulomb per cubic metre
    ATT_UNIT_COULOMB_PER_CUBIC_METRE,
    ///Surface charge density unit - coulomb per square metre
    ATT_UNIT_SURF_COULOMB_PER_SQ_METRE,
    ///Electric flux density unit - coulomb per square metre
    ATT_UNIT_FLUX_COULOMB_PER_SQ_METRE,
    ///Permittivity unit - farad per metre
    ATT_UNIT_FARAD_PER_METRE,
    ///Permeability unit - henry per metre
    ATT_UNIT_HENRY_PER_METRE,
    ///Molar energy unit - joule per mole
    ATT_UNIT_JOULE_PER_MOLE,
    ///Molar entropy unit - joule per mole kelvin
    ATT_UNIT_JOULE_PER_MOLE_KELVIN,
    ///Exposure unit - coulomb per kilogram
    ATT_UNIT_COULOMB_PER_KG,
    ///Absorbed dose rate unit - gray per second
    ATT_UNIT_GRAY_PER_SECOND,
    ///Radiant intensity unit - watt per steradian
    ATT_UNIT_WATT_PER_STERADIAN,
    ///Radiance unit - watt per square meter steradian
    ATT_UNIT_WATT_PER_SQ_METRE_STERADIAN,
    ///Catalytic activity concentration unit - katal per cubic metre
    ATT_UNIT_KATAL_PER_CUBIC_METRE,
    ///Time unit - minute
    ATT_UNIT_MINUTE                         = 0x2760,
    ///Time unit - hour
    ATT_UNIT_HOUR,
    ///Time unit - day
    ATT_UNIT_DAY,
    ///Plane angle unit - degree
    ATT_UNIT_ANGLE_DEGREE,
    ///Plane angle unit - minute
    ATT_UNIT_ANGLE_MINUTE,
    ///Plane angle unit - second
    ATT_UNIT_ANGLE_SECOND,
    ///Area unit - hectare
    ATT_UNIT_HECTARE,
    ///Volume unit - litre
    ATT_UNIT_LITRE,
    ///Mass unit - tonne
    ATT_UNIT_TONNE,
    ///Pressure unit - bar
    ATT_UNIT_BAR                            = 0x2780,
    ///Pressure unit - millimetre of mercury
    ATT_UNIT_MM_MERCURY,
    ///Length unit - angstrom
    ATT_UNIT_ANGSTROM,
    ///Length unit - nautical mile
    ATT_UNIT_NAUTICAL_MILE,
    ///Area unit - barn
    ATT_UNIT_BARN,
    ///Velocity unit - knot
    ATT_UNIT_KNOT,
    ///Logarithmic radio quantity unit - neper
    ATT_UNIT_NEPER,
    ///Logarithmic radio quantity unit - bel
    ATT_UNIT_BEL,
    ///Length unit - yard
    ATT_UNIT_YARD                           = 0x27A0,
    ///Length unit - parsec
    ATT_UNIT_PARSEC,
    ///length unit - inch
    ATT_UNIT_INCH,
    ///length unit - foot
    ATT_UNIT_FOOT,
    ///length unit - mile
    ATT_UNIT_MILE,
    ///pressure unit - pound-force per square inch
    ATT_UNIT_POUND_FORCE_PER_SQ_INCH,
    ///velocity unit - kilometre per hour
    ATT_UNIT_KM_PER_HOUR,
    ///velocity unit - mile per hour
    ATT_UNIT_MILE_PER_HOUR,
    ///angular velocity unit - revolution per minute
    ATT_UNIT_REVOLUTION_PER_MINUTE,
    ///energy unit - gram calorie
    ATT_UNIT_GRAM_CALORIE,
    ///energy unit - kilogram calorie
    ATT_UNIT_KG_CALORIE,
    /// energy unit - kilowatt hour
    ATT_UNIT_KILOWATT_HOUR,
    ///thermodynamic temperature unit - degree Fahrenheit
    ATT_UNIT_FAHRENHEIT,
    ///percentage
    ATT_UNIT_PERCENTAGE,
    ///per mille
    ATT_UNIT_PER_MILLE,
    ///period unit - beats per minute)
    ATT_UNIT_BEATS_PER_MINUTE,
    ///electric charge unit - ampere hours
    ATT_UNIT_AMPERE_HOURS,
    ///mass density unit - milligram per decilitre
    ATT_UNIT_MILLIGRAM_PER_DECILITRE,
    ///mass density unit - millimole per litre
    ATT_UNIT_MILLIMOLE_PER_LITRE,
    ///time unit - year
    ATT_UNIT_YEAR,
    ////time unit - month
    ATT_UNIT_MONTH,


    /*---------------- DECLARATIONS -----------------*/
    /// Primary service Declaration
    ATT_DECL_PRIMARY_SERVICE                     = 0x2800,
    /// Secondary service Declaration
    ATT_DECL_SECONDARY_SERVICE,
    /// Include Declaration
    ATT_DECL_INCLUDE,
    /// Characteristic Declaration
    ATT_DECL_CHARACTERISTIC,


    /*----------------- DESCRIPTORS -----------------*/
    /// Characteristic extended properties
    ATT_DESC_CHAR_EXT_PROPERTIES                 = 0x2900,
    /// Characteristic user description
    ATT_DESC_CHAR_USER_DESCRIPTION,
    /// Client characteristic configuration
    ATT_DESC_CLIENT_CHAR_CFG,
    /// Server characteristic configuration
    ATT_DESC_SERVER_CHAR_CFG,
    /// Characteristic Presentation Format
    ATT_DESC_CHAR_PRES_FORMAT,
    /// Characteristic Aggregate Format
    ATT_DESC_CHAR_AGGREGATE_FORMAT,
    /// Valid Range
    ATT_DESC_VALID_RANGE,
    /// External Report Reference
    ATT_DESC_EXT_REPORT_REF,
    /// Report Reference
    ATT_DESC_REPORT_REF,


    /*--------------- CHARACTERISTICS ---------------*/
    /// Device name
    ATT_CHAR_DEVICE_NAME                        = 0x2A00,
    /// Appearance
    ATT_CHAR_APPEARANCE                         = 0x2A01,
    /// Privacy flag
    ATT_CHAR_PRIVACY_FLAG                       = 0x2A02,
    /// Reconnection address
    ATT_CHAR_RECONNECTION_ADDR                  = 0x2A03,
    /// Peripheral preferred connection parameters
    ATT_CHAR_PERIPH_PREF_CON_PARAM              = 0x2A04,
    /// Service handles changed
    ATT_CHAR_SERVICE_CHANGED                    = 0x2A05,
    /// Alert Level characteristic
    ATT_CHAR_ALERT_LEVEL                        = 0x2A06,
    /// Tx Power Level
    ATT_CHAR_TX_POWER_LEVEL                     = 0x2A07,
    /// Date Time
    ATT_CHAR_DATE_TIME                          = 0x2A08,
    /// Day of Week
    ATT_CHAR_DAY_WEEK                           = 0x2A09,
    /// Day Date Time
    ATT_CHAR_DAY_DATE_TIME                      = 0x2A0A,
    /// Exact time 256
    ATT_CHAR_EXACT_TIME_256                     = 0x2A0C,
    /// DST Offset
    ATT_CHAR_DST_OFFSET                         = 0x2A0D,
    /// Time zone
    ATT_CHAR_TIME_ZONE                          = 0x2A0E,
    /// Local time Information
    ATT_CHAR_LOCAL_TIME_INFO                    = 0x2A0F,
    /// Time with DST
    ATT_CHAR_TIME_WITH_DST                      = 0x2A11,
    /// Time Accuracy
    ATT_CHAR_TIME_ACCURACY                      = 0x2A12,
    ///Time Source
    ATT_CHAR_TIME_SOURCE                        = 0x2A13,
    /// Reference Time Information
    ATT_CHAR_REFERENCE_TIME_INFO                = 0x2A14,
    /// Time Update Control Point
    ATT_CHAR_TIME_UPDATE_CNTL_POINT             = 0x2A16,
    /// Time Update State
    ATT_CHAR_TIME_UPDATE_STATE                  = 0x2A17,
    /// Glucose Measurement
    ATT_CHAR_GLUCOSE_MEAS                       = 0x2A18,
    /// Battery Level
    ATT_CHAR_BATTERY_LEVEL                      = 0x2A19,
    /// Temperature Measurement
    ATT_CHAR_TEMPERATURE_MEAS                   = 0x2A1C,
    /// Temperature Type
    ATT_CHAR_TEMPERATURE_TYPE                   = 0x2A1D,
    /// Intermediate Temperature
    ATT_CHAR_INTERMED_TEMPERATURE               = 0x2A1E,
    /// Measurement Interval
    ATT_CHAR_MEAS_INTERVAL                      = 0x2A21,
    /// Boot Keyboard Input Report
    ATT_CHAR_BOOT_KB_IN_REPORT                  = 0x2A22,
    /// System ID
    ATT_CHAR_SYS_ID                             = 0x2A23,
    /// Model Number String
    ATT_CHAR_MODEL_NB                           = 0x2A24,
    /// Serial Number String
    ATT_CHAR_SERIAL_NB                          = 0x2A25,
    /// Firmware Revision String
    ATT_CHAR_FW_REV                             = 0x2A26,
    /// Hardware revision String
    ATT_CHAR_HW_REV                             = 0x2A27,
    /// Software Revision String
    ATT_CHAR_SW_REV                             = 0x2A28,
    /// Manufacturer Name String
    ATT_CHAR_MANUF_NAME                         = 0x2A29,
    /// IEEE Regulatory Certification Data List
    ATT_CHAR_IEEE_CERTIF                        = 0x2A2A,
    /// CT Time
    ATT_CHAR_CT_TIME                            = 0x2A2B,
    /// Scan Refresh
    ATT_CHAR_SCAN_REFRESH                       = 0x2A31,
    /// Boot Keyboard Output Report
    ATT_CHAR_BOOT_KB_OUT_REPORT                 = 0x2A32,
    /// Boot Mouse Input Report
    ATT_CHAR_BOOT_MOUSE_IN_REPORT               = 0x2A33,
    /// Glucose Measurement Context
    ATT_CHAR_GLUCOSE_MEAS_CTX                   = 0x2A34,
    /// Blood Pressure Measurement
    ATT_CHAR_BLOOD_PRESSURE_MEAS                = 0x2A35,
    /// Intermediate Cuff Pressure
    ATT_CHAR_INTERMEDIATE_CUFF_PRESSURE         = 0x2A36,
    /// Heart Rate Measurement
    ATT_CHAR_HEART_RATE_MEAS                    = 0x2A37,
    /// Body Sensor Location
    ATT_CHAR_BODY_SENSOR_LOCATION               = 0x2A38,
    /// Heart Rate Control Point
    ATT_CHAR_HEART_RATE_CNTL_POINT              = 0x2A39,
    /// Alert Status
    ATT_CHAR_ALERT_STATUS                       = 0x2A3F,
    /// Ringer Control Point
    ATT_CHAR_RINGER_CNTL_POINT                  = 0x2A40,
    /// Ringer Setting
    ATT_CHAR_RINGER_SETTING                     = 0x2A41,
    /// Alert Category ID Bit Mask
    ATT_CHAR_ALERT_CAT_ID_BIT_MASK              = 0x2A42,
    /// Alert Category ID
    ATT_CHAR_ALERT_CAT_ID                       = 0x2A43,
    /// Alert Notification Control Point
    ATT_CHAR_ALERT_NTF_CTNL_PT                  = 0x2A44,
    /// Unread Alert Status
    ATT_CHAR_UNREAD_ALERT_STATUS                = 0x2A45,
    /// New Alert
    ATT_CHAR_NEW_ALERT                          = 0x2A46,
    /// Supported New Alert Category
    ATT_CHAR_SUP_NEW_ALERT_CAT                  = 0x2A47,
    /// Supported Unread Alert Category
    ATT_CHAR_SUP_UNREAD_ALERT_CAT               = 0x2A48,
    /// Blood Pressure Feature
    ATT_CHAR_BLOOD_PRESSURE_FEATURE             = 0x2A49,
    /// HID Information
    ATT_CHAR_HID_INFO                           = 0x2A4A,
    /// Report Map
    ATT_CHAR_REPORT_MAP                         = 0x2A4B,
    /// HID Control Point
    ATT_CHAR_HID_CTNL_PT                        = 0x2A4C,
    /// Report
    ATT_CHAR_REPORT                             = 0x2A4D,
    /// Protocol Mode
    ATT_CHAR_PROTOCOL_MODE                      = 0x2A4E,
    /// Scan Interval Window
    ATT_CHAR_SCAN_INTV_WD                       = 0x2A4F,
    /// PnP ID
    ATT_CHAR_PNP_ID                             = 0x2A50,
    /// Glucose Feature
    ATT_CHAR_GLUCOSE_FEATURE                    = 0x2A51,
    /// Record access control point
    ATT_CHAR_REC_ACCESS_CTRL_PT                 = 0x2A52,
    /// RSC Measurement
    ATT_CHAR_RSC_MEAS                           = 0x2A53,
    /// RSC Feature
    ATT_CHAR_RSC_FEAT                           = 0x2A54,
    /// SC Control Point
    ATT_CHAR_SC_CNTL_PT                         = 0x2A55,
    /// CSC Measurement
    ATT_CHAR_CSC_MEAS                           = 0x2A5B,
    /// CSC Feature
    ATT_CHAR_CSC_FEAT                           = 0x2A5C,
    /// Sensor Location
    ATT_CHAR_SENSOR_LOC                         = 0x2A5D,

    /* Test UUIDs */
    /// Manufacturer Service
    ATT_SVC_MANUF                               = 0xB000,
    /// Last define
    ATT_LAST,
};



/*
   HCI response type definition (inherite from BLE stack)
*/
/** ATT Error Response PDU */
#define ATT_ERROR_RSP				0x01
/** ATT Exchange MTU Request PDU */
#define ATT_XCNHG_MTU_REQ		  0x02
/** ATT Exchange MTU Response PDU */
#define ATT_XCHNG_MTU_RSP 		 0x03
/** ATT Find Information Request PDU */
#define ATT_FIND_INFO_REQ		   0x04
/** ATT Find Information Response PDU */
#define ATT_FIND_INFO_RSP		  0x05
/** ATT Find By Type Value Request PDU */
#define ATT_FIND_BY_TYPE_VAL_REQ   0x06
/** ATT Find By Type Value Response PDU */
#define ATT_FIND_BY_TYPE_VAL_RSP   0x07
/** ATT Read By Type Request PDU */
#define ATT_READ_BY_TYPE_REQ		 0x08
/** ATT Read By Type Response PDU */
#define ATT_READ_BY_TYPE_RSP		0x09
/** ATT Read Request PDU */
#define ATT_READ_REQ 	  0x0A
/** ATT Read Response PDU */
#define ATT_READ_RSP				 0x0B
/** ATT Read Blob Request PDU */
#define ATT_READ_BLOB_REQ			0x0C
/** ATT Read Blob Response PDU */
#define ATT_READ_BLOB_RSP			0x0D
/** ATT Read Multiple Request PDU */
#define ATT_READ_MULTIPLE_REQ	   0x0E
/** ATT Read Multiple Response PDU */
#define ATT_READ_MULTIPLE_RSP	   0x0F
/** ATT Read Group Type Request PDU */
#define ATT_READ_BY_GROUP_REQ		0x10
/** ATT Read Group Type Response PDU */
#define ATT_READ_BY_GROUP_RSP	  0x11
/** ATT Write Request PDU */
#define ATT_WRITE_REQ 			 0x12
/** ATT Write Response PDU */
#define ATT_WRITE_RSP 			 0x13
/** ATT Write Command PDU */
#define ATT_WRITE_CMD				0x52
/** ATT Write Command - Transmission Complete - Locally generated event */
#define ATT_WRITE_CMD_TX_COMPLETE  0x53
/** ATT Signed Write Command PDU */
#define ATT_SIGNED_WRITE_CMD	   0xD2
/** ATT Signed Write Command - Transmission Complete - Locally generated event */
#define ATT_SIGNED_WRITE_CMD_TX_COMPLETE 	 0xD3
/** ATT Prepare Write Request PDU */
#define ATT_PREPARE_WRITE_REQ		0x16
/** ATT Prepare Write Response PDU */
#define ATT_PREPARE_WRITE_RSP		0x17
/** ATT Execute Write Request PDU */
#define ATT_EXECUTE_WRITE_REQ	   0x18
/** ATT Execute Write Response PDU */
#define ATT_EXECUTE_WRITE_RSP	   0x19
/** ATT Handle Value Notification PDU */
#define ATT_HANDLE_VALUE_NTF 	  0x1B
/** ATT Handle Value Notification - Transmission Complete - Locally generated event */
#define ATT_HANDLE_VALUE_NTF_TX_COMPLETE 			 0x1C
/** ATT Handle Value Indication PDU */
#define ATT_HANDLE_VALUE_IND 	  0x1D
/** ATT Handle Value Confirmation PDU */
#define ATT_HANDLE_VALUE_CNF		 0x1E
/** Unknown or Unhandled PDU */
#define ATT_UNKNOWN_PDU_IND 	   0xFF

#define ATT_DISCONNECTION_IND  0x82

#define BLE_CONNECTION_MAX          8
/// Maximum number of discovered addresses
#define GAP_MAX_DISC_ADDR                       BLE_CONNECTION_MAX

/// Invalid connection index
#define GAP_INVALID_CONIDX                      0xFF

/// Maximum number of discovered addresses
#define GAP_MAX_DISC_ADDR                       BLE_CONNECTION_MAX

/// Default encryption key size
#define GAP_ENC_KEYSIZE_DEFAULT                 0x07

#define VT_GATT_MAX_HDL_NB		(2 * GATT_MAX_HDL_LIST)
#define APP_GATT_MAX_HDL_LIST 0x08
#define GATT_MAX_HDL_LIST 0x08

#define GAP_CONN_EST_MAX_CE_LEN                             0x0140
#define GAP_CONN_EST_MIN_CE_LEN                             0x0000
#define GAP_UND_CONN_ADV_INT_MAX                            0x00A0
#define GAP_DIR_CONN_ADV_INT_MIN                            0x0100


/** GATT Characteristic Properties Bit Field */
/** Broadcast */
#define GATT_CH_PROP_BIT_BROADCAST    0x01
/** Read */
#define GATT_CH_PROP_BIT_READ         0x02
/** Write Without Response */
#define GATT_CH_PROP_BIT_WRITE_WO_RSP    0x04
/** Write */
#define GATT_CH_PROP_BIT_WRITE            0x08
/** Notify */
#define GATT_CH_PROP_BIT_NOTIFY     0x10
/** Indicate */
#define GATT_CH_PROP_BIT_INDICATE     0x20
/** Authenticated Signed Write */
#define GATT_CH_PROP_BIT_SIGN_WRITE   0x40
/** Extended Properties */
#define GATT_CH_PROP_BIT_EXT_PROPERTY   0x80

#define BLE_SVC_REC_MAX      16
#define BLE_CONNECTION_MAX    8
#define BLE_SCAN_DEVICE_MAX    200
#define BLE_ADDR_LEN         0x06

#define CMD_PACKET_PARAM_MAX          512
#define BLE_SVC_REC_MAX     16

#define LE_FEATS_LEN        0x08
#define ADV_DATA_LEN        0x1F
#define GAP_MAX_DISC_ADDR    16
#define SCAN_RSP_DATA_LEN   0x1F

#define GATT_MAX_HDL_LIST                            0x08
#define VT_GATT_MAX_HDL_NB		(2 * GATT_MAX_HDL_LIST)


enum {
    UUID_TYPE_0,
    UUID_TYPE_16,
    UUID_TYPE_128,
};

#define VT_MSG_DATA_SIZE        (4096+256)   // before is 512

/// Message structure.
struct vt_msg
{
    uint16_t     id;         ///< Message id.
    uint16_t        param_len;  ///< Parameter embedded struct length.
    uint32_t        param[1];   ///< Parameter embedded struct. Must be word-aligned.
    uint8_t          param_data[VT_MSG_DATA_SIZE]; 
};

/// OOB Data Present Flag Values
enum
{
    ///OOB Data not present
    SMP_OOB_AUTH_DATA_NOT_PRESENT = 0x00,
    ///OOB data from remote device present
    SMP_OOB_AUTH_DATA_FROM_REMOTE_DEV_PRESENT,
    SMP_OOB_AUTH_DATA_LAST,
};

/// Authentication Requirements
enum
{
    ///No MITM No Bonding
    SMP_AUTH_REQ_NO_MITM_NO_BOND = 0x00,
    ///No MITM Bonding
    SMP_AUTH_REQ_NO_MITM_BOND,
    ///MITM No Bonding
    SMP_AUTH_REQ_MITM_NO_BOND = 0x04,
    ///MITM and Bonding
    SMP_AUTH_REQ_MITM_BOND,
    SMP_AUTH_REQ_LAST
};

//connection to peer parameters
struct CONNECTINFO
{
    uint16_t MinconInterval;
    uint16_t MaxconInterval;
    uint16_t slaveLatency;
    uint16_t superTimeOut;
};


typedef struct 
{
   int processed; 
   int rx_cur;  // receiving data current position 
   int size;      // buf size
   int rx_end;      // buf end position
   int cs_cur; // consuming data current position
   int cur_cmd_size;  // current cmd packet size
   int cmd_count; 
   uint8_t *rx_buf; 
}rx_round_buf; 

typedef struct 
{
   int size;  // 
   int flag;
   uint8_t cmd ;      //  protocol command 
   uint8_t header;      // protocol header
   uint8_t packetID; // packet index (00-ff)
   uint16_t param_len;  //  2 bytes of parameters length
   uint8_t param[CMD_PACKET_PARAM_MAX]; 
}cmd_buf; 

struct bd_addr
{
    ///6-byte array address value
    uint8_t  addr[BLE_ADDR_LEN];
};

/// Common GAP complete event for higher layer
struct gap_event_common_cmd_complete
{
    /// Command complete status
    uint8_t status;
};

struct gap_read_ver_req_cmp_evt
{
    /// Status
    uint8_t status;
    /// fw version
    uint8_t fw_ver;
    /// fw sub version
    uint8_t fw_subver;
    /// hw version
    uint8_t hw_ver;
    /// hw sub version
    uint8_t hw_subver;
    /// HCI revision
    uint8_t hci_ver;
    /// HCI sub revision
    uint8_t hci_subver;
    /// Manufacture
    char manu[16];
    /// year
    uint8_t year;
    /// month
    uint8_t month;
    /// year
    uint8_t day;
};

struct gap_read_bdaddr_req_cmp_evt
{
    /// status
    uint8_t status;
    /// Device BD Address
    struct bd_addr addr;
};

///Advertising report structure
struct adv_report
{
    ///Event type
    uint8_t        evt_type;
    ///Advertising address type: public/random
    uint8_t        adv_addr_type;
    ///Advertising address value
    struct bd_addr adv_addr;
    ///Data length in advertising packet
    uint8_t        data_len;
    ///Data of advertising packet
    uint8_t        data[ADV_DATA_LEN];
    ///RSSI value for advertising packet
    uint8_t        rssi;
};

///Advertising report structure
struct adv_rep
{
    ///Event type
    uint8_t        evt_type;
    ///Advertising address type: public/random
    uint8_t        adv_addr_type;
    ///Advertising address value
    struct bd_addr adv_addr;
    ///Data length in advertising packet
    uint8_t        data_len;
    uint8_t        data2_len;
    ///Data of advertising packet
    uint8_t        data[ADV_DATA_LEN];
    uint8_t        data2[ADV_DATA_LEN];
    ///RSSI value for advertising packet
    uint8_t        rssi;
};

/// Device discovery event result
struct gap_dev_inq_result_evt
{
    ///Number of responses
    uint8_t nb_resp;
    /// advertising report
    struct adv_report adv_rep;
};

/// Connection Parameter update
struct gap_conn_param_update
{
    /// Connection interval minimum
    uint16_t intv_min;
    /// Connection interval maximum
    uint16_t intv_max;
    /// Latency
    uint16_t latency;
    /// Supervision timeout
    uint16_t time_out;
};

/// Connection Parameter update
struct gap_conn_param
{
    // scan interval 
    uint16_t scan_interval; 
   // scan window
    uint16_t scan_window;
   // filter policy
   uint8_t filter; 
   // peer_address_type
    uint8_t peer_address_type; 
    // peer address
    uint8_t peer_addree[6];
    // own address type
    uint8_t own_address_type; 
    /// Connection interval minimum
    uint16_t intv_min;
    /// Connection interval maximum
    uint16_t intv_max;
    /// Latency
    uint16_t latency;
    /// Supervision timeout
    uint16_t time_out;
    // minimum ce length
    uint16_t minimum_ce_len; 
    // maximum ce length
    uint16_t maxium_ce_len; 	
};

/// GAP Connection information @ref GAP_LE_CREATE_CONN_REQ_CMP_EVT message
struct gap_link_info
{
    /// Confirmation status
    uint8_t status;
    /// Connection handle
    uint16_t conhdl;
    /// Peer address type
    uint8_t peer_addr_type;
    /// Peer BT address
    struct bd_addr peer_addr;
    /// Connection interval
    uint16_t con_interval;
    /// Connection latency
    uint16_t con_latency;
    /// Link supervision timeout
    uint16_t sup_to;
    uint8_t role; 
    /// local RPA  address
    struct bd_addr local_rpa_addr;
    /// Peer RPA address
    struct bd_addr peer_rpa_addr;
    uint16_t timeout; 
    uint8_t clock_accuracy; 
    
};

/// Parameters of the @ref GAP_LE_CREATE_CONN_REQ_CMP_EVT message
struct gap_le_create_conn_req_cmp_evt
{
    /// Connection establishment information
    struct gap_link_info conn_info;
};

/// Connection request
struct gap_conn_rec
{
    /// BD Address bearer to connect
    struct bd_addr tmp_bdaddr;
    /// Own address type
    uint8_t own_addr_type;
};

/// Device controller version
struct gap_dev_version
{
    /// HCI version
    uint8_t hci_ver;
    /// HCI revision
    uint16_t hci_rev;
    /// HCI LMP version
    uint8_t lmp_ver;
    /// Manufacturing name
    uint16_t manuf_name;
    /// LMP subversion
    uint16_t lmp_subver;
};

/// Random Address Structure
struct random_address
{
    /// Static random address
    struct bd_addr static_addr;
    /// Private non-resolvable address
    struct bd_addr priv_nrsvble;
    /// Private resolvable address
    struct bd_addr priv_rsvble;
    /// Temporary address
    struct bd_addr tmp_bdaddr;
};

/// GAP Local Device Record Structure
struct gap_loc_dev_rec
{
    /// flag for discovery, connectivity
    uint16_t flag;
    /// random device address
    struct random_address random_addr;
    /// public device address
    struct bd_addr public_addr;
    /// device local version
    struct gap_dev_version ver;
    /// present device role
    uint8_t role;
    /// event mask
};

/// Connected Device Record Structure
struct gap_dev_record
{
    /// peer address
    struct bd_addr peer_addr;
    /// connection handle
    uint16_t conhdl;
    /// Peer address type
    uint8_t peer_addr_type;
    /// Local address type used to connect
    uint8_t own_addr_type;
    /// Local random address type used to connect
    uint8_t own_rand_addr_type;
    /// encryption key size
    uint8_t enc_key_size;
    /// bonding status
    uint8_t lk_sec_stat;
    /// status of the device record
    bool free;
    /// local and remote supports encryption
    bool enc_support;
};

///Advertising data structure
struct adv_data
{
    ///Maximum length data bytes array
    uint8_t        data[ADV_DATA_LEN];
};

/// Advertising Settings Structure
struct gap_adv_rec
{
    /// advertising channel power level
    uint8_t adv_pwr_lvl;
    /// minimum advertising interval
    uint16_t adv_intv_min;
    /// maximum advertising interval
    uint16_t adv_intv_max;
    /// advertising type */
    uint8_t adv_type;
    /// advertising channel map
    uint8_t adv_chnl_map;
    /// advertising filter policy
    uint8_t adv_filt_policy;
    /// advertising data length
    uint8_t adv_data_len;
    /// advertising data
    struct adv_data adv_data;
    /// scanning response data length
    uint8_t scan_rsp_data_len;
    /// own address type
    uint8_t own_addr_type;
    /// direct address type
    uint8_t direct_addr_type;
    /// peer address ?
    struct bd_addr peer_addr;
    /// advertising flag: enable or disable
    uint8_t adv_en;
};

/// Scanning Settings Structure
struct gap_scan_rec
{
    /// 0=passive, 1=active
    uint8_t scan_type;
    /// scanning interval
    uint16_t scan_intv;
    /// scanning window
    uint16_t scan_window;
    /// address type
    uint8_t own_addr_type;
    /// scanning filter policy
    uint8_t scan_filt_policy;
    /// scanning flag: enable or disable
    uint8_t scan_en;
    /// filtering duplicate
    uint8_t filter_duplic_en;
};

/// Bonding Settings Structure
struct gap_bond_rec
{
    /// Bonding flag
    uint8_t bondflag;
    /// OOB information
    uint8_t oob;
    /// IO capabilities
    uint8_t iocap;
    /// Authentication requirements
    uint8_t auth;
    /// Encryption key size
    uint8_t key_size;
    ///Initiator key distribution
    uint8_t ikey_dist;
    ///Responder key distribution
    uint8_t rkey_dist;
};

/// Address holder
struct gap_discovered_addr
{
    /// BD address
    struct bd_addr addr;
};

/// Device discovery address holder
struct gap_address_disc_keeper
{
    /// Number of addresses
    uint8_t nb;
    /// Discovered addresses holder
    struct gap_discovered_addr addr_keeper[GAP_MAX_DISC_ADDR];
};

/// GAP Manager environment structure
struct gap_env_tag
{
    /// Record for each connected device
    struct gap_dev_record dev_rec[BLE_CONNECTION_MAX];
    /// Local device settings
    struct gap_loc_dev_rec ble_dev;
    /// Advertising settings
    struct gap_adv_rec adv_rec;
    /// Scanning settings
    struct gap_scan_rec scan_rec;
    /// Connection settings
    struct gap_conn_rec conn_rec;
    /// Discovery Address holder
    struct gap_address_disc_keeper disc_addr;
    /// Response id
    uint16_t rspid;
    /// ATTS service start handle
    uint16_t svc_start_hdl;
    /// Current device operational flag
    uint16_t opflag[BLE_CONNECTION_MAX];
    /// Name request connection handle
    uint16_t name_req_hdl;
    /// Parameter update indication connection handle
    uint16_t param_upd_hdl;
    /// Number of connected devices
    uint16_t device_cnt;
    /// Inquiry type set during discovery process
    uint8_t inq_type;
    /// White list size
    uint8_t whitelist_sz;
    /// Address type
    uint8_t rand_type;
    /// GAP status
    uint8_t status;
    /// Number of bonded device
    uint8_t bond_cnt;
    /// State of device privacy
    uint8_t priv_stat_flag;
    /// Flag for host start
    bool start;
    /// Flag for reset
    bool reset_flag;
    /// Flag that signifies disconnection initiator
    bool disc_init;
    /// Flag that requires address renewal
    bool renew_addr;
    /// Flag allowing/disallowing a peripheral initiated parameter update procedure
    bool param_update_disallowed;
    /// Flag for name request
    bool name_req_con_est;
};


/// Data list for service result
/// Service record
struct gatt_svc_record
{
    /// attribute handle
    uint16_t start_hdl;
    uint16_t end_hdl;
    uint16_t attr_hdl;
    uint8_t attr128_hdl[16];
    uint8_t uuid_type; 
    uint8_t deviceID; 
    uint8_t attID; 
};

struct gatt_svc_rec
{
    uint8_t status; 
    uint8_t state; 
    uint16_t current_handle; 
    uint16_t svc_cnt; 
    struct gatt_svc_record svc[BLE_SVC_REC_MAX];
    struct gatt_svc_record svc_disc;
};

struct gatt_char_disc
{
    /// attribute handle
    uint16_t start_hdl;
    uint16_t end_hdl;
    uint16_t attr_hdl;
    uint8_t attr128_hdl[16];
    uint8_t uuid_type; 
    uint8_t deviceID; 
    uint8_t attID; 
};

/// Data list for characteristic result - 16-bit
struct gatt_char_list
{
    /// database element handle
    uint16_t attr_hdl;
    /// properties
    uint8_t prop;
    /// pointer handle to UUID
    uint16_t pointer_hdl;
    /// uuid type: 0, 1: 16 bits,  2: 128 bits
    uint8_t uuid_type;    
    /// characteristic UUID
    uint16_t uuid;
    /// characteristic UUID 128 bits 
    uint8_t uuid128[16];	
};

/// Discovery All Characteristic Complete Event Structure
struct gatt_disc_char_rec
{
    /// complete event status
    uint8_t status;
    uint16_t current_handle; 
    uint16_t notify_handle; 
    uint16_t write_handle; 
    /// number of entries
    uint8_t nb_entry;
    /// list of found characteristics
    struct gatt_char_disc char_disc;
    struct gatt_char_list list[256];
};

struct gap_dev_inq_result_rep
{
    ///Number of responses
    uint8_t num_of_dev;
    /// advertising report
    struct adv_rep adv_rep[BLE_SCAN_DEVICE_MAX];
};

/// Data list for service result
/// Service record
struct app_svc_record
{
    /// attribute handle
    uint16_t start_hdl;
    uint16_t end_hdl;
    uint16_t attr_hdl;
    uint8_t attr128_hdl[16];
    uint8_t uuid_type;
    uint8_t deviceID;
    uint8_t attID;
};

/// Connected Device Record Structure
struct app_dev_record
{
    /// bond information
    uint8_t bonded;
    uint8_t sec_prop;

    /// number of svc, not include GAP, GATT
    uint8_t nb_svc;
    /// discoveried service record list
    struct app_svc_record svc_rec[VT_GATT_MAX_HDL_NB];

    /// peer address
    struct bd_addr peer_addr;
    /// connection handle
    uint16_t conhdl;
    /// status of the device record
    bool free;
};

/// application environment structure
struct app_env_tag
{
    // Advertising data
    uint8_t adv_data[ADV_DATA_LEN];
    // Scan Response data
    uint8_t scanrsp_data[SCAN_RSP_DATA_LEN];

    /// Selected Dev Idx
    uint8_t select_idx;
    uint8_t deviceID; 
    uint8_t instanceID; 
    uint16_t mtu; 
    /// Inquired Device Record
    uint8_t inq_idx;
    int state; 
    uint8_t addr_type[BLE_SCAN_DEVICE_MAX];
    struct bd_addr inq_addr[BLE_SCAN_DEVICE_MAX];
    /// Connected Device Record
    uint8_t cn_idx;
    struct app_dev_record dev_rec[BLE_SCAN_DEVICE_MAX];

    /// Service setup Flag
    uint16_t srv_flag;

};

///llc command complete event structure for the read remote information version command
struct rem_info
{
    ///Status for command reception
    uint8_t status;
    ///Connection handle
    uint16_t conhdl;
    ///LMP version
    uint8_t     vers;
    ///Manufacturer name
    uint16_t    compid;
    ///LMP subversion
    uint16_t    subvers;
};

///Supported LE Features structure
struct le_features
{
    ///8-byte array for LE features
    uint8_t feats[1];
};

/// Event parameter for @ref GAP_LE_RD_REMOTE_FEAT_REQ_CMP_EVT event message
struct gap_le_rd_remote_feat_req_cmp_evt
{
    ///Status of read remote feature request command
    uint8_t status;
    ///Connection handle
    uint16_t conhdl;
    ///LE Features used
    struct le_features feats_used;
};

/// Parameters of the @ref GAP_SET_SEC_REQ_CMP_EVT message
struct gap_set_sec_req_cmp_evt
{
    /// status
    uint8_t status;
    /// security mode
    uint8_t sec;
};

struct S_GENERIC
{
    QString deviceName;
    int setGeneratedAddress;
    int setRandomAddress;
};

//mode tab parameters
enum deviceDiscovery {limited, general, known};
enum DiscoveringMode {nonDiscoverable = 0x001,  nonConnectable = 0x002,
                      nonBondable = 0x004, broadcaster = 0x008,
                      limitDiscoverable = 0x010,  undirectedConnectable = 0x020,
                      bondable = 0x040,  observer = 0x080,
                      generalDiscoverable = 0x100, directedConnectable = 0x200,
                      autoConnectable = 0x400, selectConnectable = 0x800};

enum advertisingType {_nonConnectable, scannable, connectable, directed};
enum scanType {passive, active, filterDuplicates};
enum directedPeer {Public, Random};
enum scanPolicy {allowAllAdvertisers, allowAdvertisersFromWL};
enum advertisingPolicy {button_1, button_2, button_3, button_4};
enum advertisingChannels {channel_37 = 0x001, channel_38 = 0x002, channel_39 = 0x004};

//mode tab parameters
struct S_DISCOVERING_MODE
{
    deviceDiscovery devDisc;
    DiscoveringMode disMode;
    advertisingType advType;
    scanType scan;
    directedPeer dirPeer;
    scanPolicy scanPol;
    advertisingPolicy advPol;
    advertisingChannels advChan;
    int nb_response;
    int peer_bd_address;
    int scan_interval;
    int scan_window;
    int adv_interval_min;
    int adv_interval_max;
    int set_ad;
    int set_srd;
};

// Peer ATT parameters
struct SERVICE_DISCOVERY
{
    QString svcType;
    QString svcShortUUID;
    QString svcLongUUID;
};

struct CHAR_DISCOVERY
{
    QString charType;
    QString charShortUUID;
    QString charLongUUID;
};

struct READ_CHAR
{
    QString readType;
    int handleUUIN;
    int expectSize;
    QString readValue;
};

struct WRITE_CHAR
{
    QString writeType;
    int handle;
    QString writeValue;
    bool autoExecuteOrNot;
};
#endif // _BLETYPE_H

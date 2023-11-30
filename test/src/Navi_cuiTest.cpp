// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  Navi_cuiTest.cpp
 * @brief navigation using cui (test code)
 *
 */
// </rtc-template>

#include "Navi_cuiTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const navi_cui_spec[] =
#else
static const char* navi_cui_spec[] =
#endif
  {
    "implementation_id", "Navi_cuiTest",
    "type_name",         "Navi_cuiTest",
    "description",       "navigation using cui",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "User Interface",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.place1", "Home",
    "conf.default.place2", "Reception desk",
    "conf.default.place3", "Examination room",
    "conf.default.place4", "Operation room",
    "conf.default.place5", "Hospital room",

    // Widget
    "conf.__widget__.place1", "text",
    "conf.__widget__.place2", "text",
    "conf.__widget__.place3", "text",
    "conf.__widget__.place4", "text",
    "conf.__widget__.place5", "text",
    // Constraints

    "conf.__type__.place1", "string",
    "conf.__type__.place2", "string",
    "conf.__type__.place3", "string",
    "conf.__type__.place4", "string",
    "conf.__type__.place5", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Navi_cuiTest::Navi_cuiTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_cui_inOut("cui_in", m_cui_in),
    m_cui_outIn("cui_out", m_cui_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Navi_cuiTest::~Navi_cuiTest()
{
}



RTC::ReturnCode_t Navi_cuiTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("cui_out", m_cui_outIn);
  
  // Set OutPort buffer
  addOutPort("cui_in", m_cui_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("place1", m_place1, "Home");
  bindParameter("place2", m_place2, "Reception desk");
  bindParameter("place3", m_place3, "Examination room");
  bindParameter("place4", m_place4, "Operation room");
  bindParameter("place5", m_place5, "Hospital room");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Navi_cuiTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t Navi_cuiTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_cuiTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t Navi_cuiTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_cuiTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_cuiTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t Navi_cuiTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_cuiTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_cuiTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_cuiTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_cuiTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool Navi_cuiTest::runTest()
{
    return true;
}


extern "C"
{
 
  void Navi_cuiTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(navi_cui_spec);
    manager->registerFactory(profile,
                             RTC::Create<Navi_cuiTest>,
                             RTC::Delete<Navi_cuiTest>);
  }
  
}

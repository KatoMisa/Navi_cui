// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  Navi_cui.cpp
 * @brief navigation using cui
 *
 */
// </rtc-template>

#include "Navi_cui.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const navi_cui_spec[] =
#else
static const char* navi_cui_spec[] =
#endif
  {
    "implementation_id", "Navi_cui",
    "type_name",         "Navi_cui",
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
Navi_cui::Navi_cui(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_cui_inIn("cui_in", m_cui_in),
    m_cui_outOut("cui_out", m_cui_out)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Navi_cui::~Navi_cui()
{
}



RTC::ReturnCode_t Navi_cui::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("cui_in", m_cui_inIn);
  
  // Set OutPort buffer
  addOutPort("cui_out", m_cui_outOut);

  
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
RTC::ReturnCode_t Navi_cui::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t Navi_cui::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t Navi_cui::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t Navi_cui::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_cui::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Navi_cui::onExecute(RTC::UniqueId /*ec_id*/)
{
  if (m_cui_inIn.isNew())
     {
       m_cui_inIn.read();
       std::cout << "Received: " << m_cui_in.data << std::endl;

      if(m_cui_in.data==1){
        int num;
        std::cout << "Please place number: "<< std::endl;
        std::cout << "1:"<< m_place1 << std::endl;
        std::cout << "2:"<< m_place2 << std::endl;
        std::cout << "3:"<< m_place3 << std::endl;
        std::cout << "4:"<< m_place4 << std::endl;
        std::cout << "5:"<< m_place5 << std::endl;
    
        std::cin >> num;
        std::cout << "Input:"<< num << std::endl;

        if(num==1){
          m_cui_out.data = 1;
          m_cui_outOut.write();
        }
        else if(num==2){
          m_cui_out.data = 2;
          m_cui_outOut.write();
        }
          else if(num==3){
          m_cui_out.data = 3;
          m_cui_outOut.write();
        }
          else if(num==4){
          m_cui_out.data = 4;
          m_cui_outOut.write();
        }
          else if(num==5){
          m_cui_out.data = 5;
          m_cui_outOut.write();
        }
        else {
          std::cout << "Please  number: "<< std::endl;
        }
      }  
     }

    return RTC::RTC_OK;
}






extern "C"
{
 
  void Navi_cuiInit(RTC::Manager* manager)
  {
    coil::Properties profile(navi_cui_spec);
    manager->registerFactory(profile,
                             RTC::Create<Navi_cui>,
                             RTC::Delete<Navi_cui>);
  }
  
}

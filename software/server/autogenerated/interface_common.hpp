/// interfacecommon.hpp
///
/// Autogenerated DO NOT EDIT
///
/// (c) Koheron

#ifndef __INTERFACECOMMON_HPP__
#define __INTERFACECOMMON_HPP__

#include <memory>
#include <mutex>

#include <driver.hpp>

#include "././drivers/common.hpp"
namespace koheron {

template<>
class Driver<driver_id_of<Common>> : public DriverAbstract
{
  public:
    int execute(Command& cmd);
    template<int op> int execute_operation(Command& cmd);

    Driver(Server *server_, Common& __Common_)
    : DriverAbstract(driver_id_of<Common>, server_)
    , __Common(__Common_)
    {}

    enum Operation {
        SET_LED = 0,
        GET_LED = 1,
        INIT = 2,
        GET_INSTRUMENT_CONFIG = 3,
        IP_ON_LEDS = 4,
        common_op_num
    };

    std::mutex mutex;

    Common& __Common;

struct Argument_set_led {uint32_t value;
} args_set_led;

struct Argument_get_led {} args_get_led;

struct Argument_init {} args_init;

struct Argument_get_instrument_config {} args_get_instrument_config;

struct Argument_ip_on_leds {} args_ip_on_leds;

}; // class Interface_Common

} // namespace koheron

#endif //__INTERFACECOMMON_HPP__

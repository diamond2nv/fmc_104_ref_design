/// Autogenerated DO NOT EDIT
///
/// (c) Koheron

#ifndef __DRIVERS_TABLE_HPP__
#define __DRIVERS_TABLE_HPP__

#include <array>
#include <tuple>
#include <memory>

#include <string_utils.hpp>
#include <meta_utils.hpp>

using driver_id = std::size_t;

class NoDriver;
class Server;

class Common;

class SSFifoController;

class DmaSG;

class xQSPI;

class TopLevelDriver;
constexpr driver_id device_num = 7;

constexpr auto drivers_names = koheron::make_array(
    koheron::str_const("NoDriver"),
    koheron::str_const("Server"),
    koheron::str_const("Common"),
    koheron::str_const("SSFifoController"),
    koheron::str_const("DmaSG"),
    koheron::str_const("xQSPI"),
    koheron::str_const("TopLevelDriver")
);

static_assert(std::tuple_size<decltype(drivers_names)>::value == device_num, "");

// Drivers are stored as unique_ptr ensuring single
// instantiation of each driver.

using drivers_tuple_t = std::tuple<std::unique_ptr<Common>,std::unique_ptr<SSFifoController>,std::unique_ptr<DmaSG>,std::unique_ptr<xQSPI>,std::unique_ptr<TopLevelDriver>>;

static_assert(std::tuple_size<drivers_tuple_t>::value == device_num - 2, "");

// Driver id from driver type

template<class Driver>
constexpr driver_id driver_id_of = Index_v<std::unique_ptr<Driver>, drivers_tuple_t> + 2;

template<> constexpr driver_id driver_id_of<NoDriver> = 0;
template<> constexpr driver_id driver_id_of<Server> = 1;

// Driver type from driver id

template<driver_id driver>
using device_t = std::remove_reference_t<decltype(*std::get<driver - 2>(std::declval<drivers_tuple_t>()))>;

#endif // __DRIVERS_TABLE_HPP__
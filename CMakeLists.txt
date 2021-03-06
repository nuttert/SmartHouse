cmake_minimum_required(VERSION 3.5)
project(TestProject VERSION 0.1.0)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED) 
find_package(Boost 1.67 REQUIRED)
find_package(spdlog REQUIRED) 
find_package(fmt REQUIRED) 

if(${TEST_MODE})
  add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/Tests/main.cpp
  )
else()
  add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/modules/data_parser.cc
    ${CMAKE_SOURCE_DIR}/modules/matching.cc
    ${CMAKE_SOURCE_DIR}/modules/reader.cc
    ${CMAKE_SOURCE_DIR}/modules/types.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/device_interface.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/devices_list.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/conditioner.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/pipe_heating.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/garden_light.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/home_heating.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/home_energy.cc
    ${CMAKE_SOURCE_DIR}/modules/devices/home_light.cc
    ${CMAKE_SOURCE_DIR}/main.cpp
  )
endif()

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${GTEST_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${Threads_INCLUDE_DIR}
  ${spdlog_INCLUDE_DIR}
  ${fmt_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/modules
)


target_link_libraries(${PROJECT_NAME} 
    ${GTEST_BOTH_LIBRARIES} 
    ${Boost_BOTH_LIBRARIES}
    Threads::Threads
    ${spdlog_LIBRARIES}
    ${fmt_LIBRARIES}
)
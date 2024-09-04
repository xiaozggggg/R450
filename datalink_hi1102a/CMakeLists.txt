
cmake_minimum_required (VERSION 3.10)

project (datalink)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_CTRL_IFACE -DCONFIG_CTRL_IFACE_UNIX")

if(DEFINED ODID_AUTH_MAX_PAGES)
    message(STATUS "Using externally defined ODID_AUTH_MAX_PAGES value")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DODID_AUTH_MAX_PAGES=${ODID_AUTH_MAX_PAGES}")
endif()

if(DEFINED ODID_BASIC_ID_MAX_MESSAGES)
    message(STATUS "Using externally defined ODID_BASIC_ID_MAX_MESSAGES value")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DODID_BASIC_ID_MAX_MESSAGES=${ODID_BASIC_ID_MAX_MESSAGES}")
endif()

include_directories(
        core-c/libopendroneid
        bluez
        include
        common
        lte_common
        lte_common/SIM7500
)

file(GLOB_RECURSE CXX_SRCS CONFIGURE_DEPENDS lte_common/*.cpp)

file(GLOB_RECURSE C_SRCS CONFIGURE_DEPENDS common/*.c)

add_executable(datalink
        core-c/libopendroneid/opendroneid.c
        bluez/lib/hci.c
        bluez/lib/bluetooth.c
)

target_sources(datalink PRIVATE ${CXX_SRCS} ${C_SRCS})

target_link_libraries(datalink
        ${PROJECT_SOURCE_DIR}/lib/sqlite3/libsqlite3.so
        pthread
        m
)

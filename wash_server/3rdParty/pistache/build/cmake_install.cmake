# Install script for directory: /home/incu/work/pistache/pistache

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pistache" TYPE FILE FILES
    "/home/incu/work/pistache/pistache/include/async.h"
    "/home/incu/work/pistache/pistache/include/client.h"
    "/home/incu/work/pistache/pistache/include/common.h"
    "/home/incu/work/pistache/pistache/include/cookie.h"
    "/home/incu/work/pistache/pistache/include/description.h"
    "/home/incu/work/pistache/pistache/include/endpoint.h"
    "/home/incu/work/pistache/pistache/include/flags.h"
    "/home/incu/work/pistache/pistache/include/http.h"
    "/home/incu/work/pistache/pistache/include/http_defs.h"
    "/home/incu/work/pistache/pistache/include/http_header.h"
    "/home/incu/work/pistache/pistache/include/http_headers.h"
    "/home/incu/work/pistache/pistache/include/iterator_adapter.h"
    "/home/incu/work/pistache/pistache/include/listener.h"
    "/home/incu/work/pistache/pistache/include/mailbox.h"
    "/home/incu/work/pistache/pistache/include/mime.h"
    "/home/incu/work/pistache/pistache/include/net.h"
    "/home/incu/work/pistache/pistache/include/optional.h"
    "/home/incu/work/pistache/pistache/include/os.h"
    "/home/incu/work/pistache/pistache/include/peer.h"
    "/home/incu/work/pistache/pistache/include/prototype.h"
    "/home/incu/work/pistache/pistache/include/reactor.h"
    "/home/incu/work/pistache/pistache/include/router.h"
    "/home/incu/work/pistache/pistache/include/stream.h"
    "/home/incu/work/pistache/pistache/include/tcp.h"
    "/home/incu/work/pistache/pistache/include/timer_pool.h"
    "/home/incu/work/pistache/pistache/include/transport.h"
    "/home/incu/work/pistache/pistache/include/typeid.h"
    "/home/incu/work/pistache/pistache/include/view.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/incu/work/pistache/pistache/build/src/cmake_install.cmake")
  include("/home/incu/work/pistache/pistache/build/examples/cmake_install.cmake")
  include("/home/incu/work/pistache/pistache/build/googletest-release-1.7.0/cmake_install.cmake")
  include("/home/incu/work/pistache/pistache/build/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/incu/work/pistache/pistache/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

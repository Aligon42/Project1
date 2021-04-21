# Install script for directory: C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/ifc2x3_sdk")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Step" TYPE FILE FILES
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/ASCII_codes.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/Aggregation.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/Array.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/Bag.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseCopyOp.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseEntity.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseExpressDataSet.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseObject.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseSPFObject.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseSPFReader.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseSPFWriter.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/BaseVisitor.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/Binary.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/CallBack.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/ClassType.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/ClientData.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/ClientDataHandler.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/IntegerTypes.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/List.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/RefLinkedList.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/Referenced.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/SPFData.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/SPFFunctions.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/SPFHeader.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/Set.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/SimpleTypes.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/StepLogger.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/String.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/src/Step/../../include/Step/Types.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/src/Step/Step/Export.h"
    "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/src/Step/Step/Config.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/Debug/Step_debug.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/Release/Step.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/MinSizeRel/Step.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/RelWithDebInfo/Step.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/Debug/Step_debug.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/Release/Step.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/MinSizeRel/Step.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/RelWithDebInfo/Step.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/Debug/Step_debug.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Users/AntoineCACHEUX/source/repos/ifc-sdk/build/bin/RelWithDebInfo/Step.pdb")
  endif()
endif()


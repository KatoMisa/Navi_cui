# Navi_cui CMake config file
#
# This file sets the following variables:
# Navi_cui_FOUND - Always TRUE.
# Navi_cui_INCLUDE_DIRS - Directories containing the Navi_cui include files.
# Navi_cui_IDL_DIRS - Directories containing the Navi_cui IDL files.
# Navi_cui_LIBRARIES - Libraries needed to use Navi_cui.
# Navi_cui_DEFINITIONS - Compiler flags for Navi_cui.
# Navi_cui_VERSION - The version of Navi_cui found.
# Navi_cui_VERSION_MAJOR - The major version of Navi_cui found.
# Navi_cui_VERSION_MINOR - The minor version of Navi_cui found.
# Navi_cui_VERSION_REVISION - The revision version of Navi_cui found.
# Navi_cui_VERSION_CANDIDATE - The candidate version of Navi_cui found.

message(STATUS "Found Navi_cui-1.0.0")
set(Navi_cui_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(Navi_cui_INCLUDE_DIRS
#    "/usr/local/include/navi_cui-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(Navi_cui_IDL_DIRS
#    "/usr/local/include/navi_cui-1/idl")
set(Navi_cui_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(Navi_cui_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(Navi_cui_LIBRARIES
        "/usr/local//libnavi_cui.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(Navi_cui_LIBRARIES
        "/usr/local//libnavi_cui.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(Navi_cui_DEFINITIONS ${<dependency>_DEFINITIONS})

set(Navi_cui_VERSION 1.0.0)
set(Navi_cui_VERSION_MAJOR 1)
set(Navi_cui_VERSION_MINOR 0)
set(Navi_cui_VERSION_REVISION 0)
set(Navi_cui_VERSION_CANDIDATE )


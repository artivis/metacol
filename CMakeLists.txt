cmake_minimum_required(VERSION 3.0.0)
project(metacol CXX)

# Check that the compoiler has c++11 support
# Crash otherwise.
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has C++11 support.")
else()
  message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} "
    "has no C++11 support. Please use a different C++ compiler.")
endif()

###########
## Build ##
###########

add_library(${PROJECT_NAME} INTERFACE)

# @todo export c++11 dependency
# @note A per-feature basis does
# not seems to work

# CMake 3.8 ...
#set_target_properties(${PROJECT_NAME} PROPERTIES
#  INTERFACE_COMPILE_FEATURES cxx_std_11
#)

target_include_directories(${PROJECT_NAME} INTERFACE
  "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include;>"
  "$<INSTALL_INTERFACE:include>"
)

#############
## Install ##
#############

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(config_install_dir "share/${PROJECT_NAME}/cmake")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Targets:
install(
  TARGETS  ${PROJECT_NAME}
  EXPORT   ${PROJECT_NAME}Targets
  INCLUDES DESTINATION include
)

install(
  EXPORT      ${PROJECT_NAME}Targets
  NAMESPACE   ${PROJECT_NAME_CAPS}::
  DESTINATION "${config_install_dir}"
)

export(
  TARGETS ${PROJECT_NAME}
  NAMESPACE ${PROJECT_NAME_CAPS}::
  FILE ${PROJECT_NAME}Targets.cmake
)

export(PACKAGE ${PROJECT_NAME})

## Configuration

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${generated_dir}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION "${config_install_dir}"
)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
write_basic_package_version_file(
  "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake"
  VERSION 0.0.0
  COMPATIBILITY AnyNewerVersion
)

# Config

install(
  FILES       "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake"
              "${generated_dir}/${PROJECT_NAME}Config.cmake"
  DESTINATION "${config_install_dir}"
)

# Headers:

install(
  DIRECTORY "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}"
  DESTINATION include
)

install(FILES package.xml
  DESTINATION share/${PROJECT_NAME}
#  DESTINATION "${config_install_dir}"
)

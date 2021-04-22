
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

include(CMakeFindDependencyMacro)

find_dependency(Boost 1.71 COMPONENTS thread chrono)

if (OFF)
    find_dependency(OpenSSL)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/hazelcast-cpp-client-targets.cmake)

set_and_check(hazelcast-cpp-client_INCLUDE_DIRS ${PACKAGE_PREFIX_DIR}/include)
set_and_check(hazelcast-cpp-client_LIBRARY_DIRS ${PACKAGE_PREFIX_DIR}/lib)
set(hazelcast-cpp-client_LIBRARIES hazelcast-cpp-client::hazelcast-cpp-client)

check_required_components(hazelcast-cpp-client)

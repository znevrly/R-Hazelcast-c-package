#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hazelcast-cpp-client::hazelcast-cpp-client" for configuration "Release"
set_property(TARGET hazelcast-cpp-client::hazelcast-cpp-client APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(hazelcast-cpp-client::hazelcast-cpp-client PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libhazelcast-cpp-client.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS hazelcast-cpp-client::hazelcast-cpp-client )
list(APPEND _IMPORT_CHECK_FILES_FOR_hazelcast-cpp-client::hazelcast-cpp-client "${_IMPORT_PREFIX}/lib/libhazelcast-cpp-client.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

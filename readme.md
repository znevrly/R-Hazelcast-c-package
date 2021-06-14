# Requirements

    Hazelcast c++ client requires Boost library which MUST be compiled as Position Independent Code (fpic flag). 
    Build to custom folder in this case /home/boost.

    1. download current version https://www.boost.org/users/history/version_1_75_0.html
    2. cd path/to/boost_1_75_0
    3. ./bootstrap.sh --prefix=/home/boost         (prefix is home target directory, there might be warnings e.g. warning: ignoring return value of ‘int fscanf)
    4. ./b2 cxxflags=-fPIC -a --with-thread --with-chrono install

# Hazelcast C++ client compilation

    First you need need compile as static library with fpic flag to custom installation. In this case /home/hz.

    1. curl -Lo hazelcast-cpp-client-4.1.1.tar.gz https://github.com/hazelcast/hazelcast-cpp-client/archive/v4.1.1.tar.gz (or other available version)
    2. tar xzf hazelcast-cpp-client-4.1.1.tar.gz
    3. cd hazelcast-cpp-client-4.1.1
    4. mkdir build
    5. cd build
    6. cmake .. -DBUILD_SHARED_LIBS=OFF -DCMAKE_CXX_FLAGS=-fPIC -DCMAKE_INSTALL_PREFIX=/home/hz
    7. cmake --build . --config Release
    8. cmake --build . --target install --config Release

# Linking compiled static libraries as depedencies for R package

    In package source code /src is file MakeVars. There must be set up static libraries as dependencies and all needed flags. For example if libs are in package root in folder 'hz-libs'

        PKG_CPPFLAGS=-I../hz-libs/include -DBOOST_THREAD_VERSION=5 -std=c++11 -pthread
        PKG_LIBS=../hz-libs/lib/libhazelcast-cpp-client.a ../hz-libs/lib/libboost_thread.a ../hz-libs/lib/libboost_chrono.a


# Development - Adding new method
    When adding new method, do not forget to add RCCP export to hazelcastclient_export.cpp otherwise there will be exception like Error in envRefInferField(x, what, getClass(class(x)), selfEnv)

# Install R package (relative path)

    R CMD INSTALL .

# Build R package (relative path)

    R CMD INSTALL . --build


# Implementation

    Adding new method - when adding new method to client, do not forget to add export to hazelcastclient_export.cpp.
    Types - all hazelcast objects are smart pointers (std::unique_ptr). 

# Methods

  std::vector<hazelcast::byte> Get(std::string key);
  void Put(std::string key, std::vector<hazelcast::byte> value);
  void SetMap(std::string mapName);
  std::string GetUrl();
  void SetVerboseMode(bool verboseMode); 

# Usage in R

    library(HazelcastClient)
    hz <- new(HazelcastClient, ip = "10.30.100.180", clusterName = "DEV", port = 5701)
    hz$SetMap('binarymap') # default map name is 'map'

    hz$Put('test1', serialize(list(1,2,3), NULL))
    data <- unserialize(hz$Get('0:active_stat_codes'), NULL)

    hz$GetUrl() # to get actual ip:port/mapName

    hz$SetVerboseMode(TRUE)  # default value is false



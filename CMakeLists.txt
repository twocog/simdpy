cmake_minimum_required( VERSION 2.6 )

file( GLOB pysrcs "*.cpp" )

macro( buildidl inputidl )
set( ${inputidl}outfiles gen/ccpp_${inputidl}.h gen/${inputidl}.cpp gen/${inputidl}Dcps.cpp gen/${inputidl}Dcps.h gen/${inputidl}Dcps_impl.cpp gen/${inputidl}Dcps_impl.h gen/${inputidl}.h gen/${inputidl}SplDcps.cpp gen/${inputidl}SplDcps.h )

add_custom_command( OUTPUT ${${inputidl}outfiles}
                    COMMAND idlpp -I ${CMAKE_SOURCE_DIR} -S -l cpp -d gen ${CMAKE_SOURCE_DIR}/${inputidl}.idl
                    DEPENDS ${CMAKE_SOURCE_DIR}/${inputidl}.idl )

add_library( ${inputidl}ddsdata ${${inputidl}outfiles} )
endmacro()

add_definitions( -DNDEBUG -O5 -pipe -std=c++0x )

include_directories( /usr/include/python2.6 ${CMAKE_BINARY_DIR} $ENV{SIMD_INSTALL_DIR}/include $ENV{OSPL_HOME}/include/dcps/C++/SACPP $ENV{OSPL_HOME}/include $ENV{OSPL_HOME}/include/sys )

buildidl( hello )

link_directories( ${CMAKE_SOURCE_DIR} $ENV{OSPL_HOME}/lib $ENV{SIMD_INSTALL_DIR}/lib )
add_library( simdpy SHARED ${pysrcs} )
target_link_libraries( simdpy SimD dcpsgapi dcpssacpp ddsdatabase ddsos boost_python boost_system helloddsdata )
set_target_properties( simdpy PROPERTIES PREFIX "" )


#include <boost/python.hpp>

#include "dds/dds.hpp"
#include "ddsbase_py.h"

namespace bpython = boost::python;

void create_ddsstrings()
{
  DDS::String_var& ( DDS::String_var::*op_equals )( const char * ) = &DDS::String_var::operator=;

  bpython::class_< DDS::String_var >( "StringVar", bpython::init<>() )
    .def( "get", &DDS::String_var::in )
    .def( "__str__", &DDS::String_var::in )
    .def( "set", op_equals, bpython::return_value_policy<bpython::reference_existing_object>() )
  ;

  bpython::class_< DDS::String_mgr, bpython::bases< DDS::String_var > >( "StringMgr", bpython::init<>() );
  
}


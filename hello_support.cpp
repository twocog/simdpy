#include "hello_support.h"

swatch::hello create_hello( const std::string& str )
{
   swatch::hello data;
   data.name = DDS::String_mgr( str.c_str() );
   return data;
}


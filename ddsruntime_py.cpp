#include <boost/python.hpp>

#include "dds/runtime.hpp"

void create_ddsruntime()
{
  namespace bpython = boost::python;
  bpython::class_<dds::Runtime>("DDSRuntime", bpython::init<std::string>());
}


#include <boost/python.hpp>

#include "dds/traits.hpp"
#include "gen/ccpp_hello.h"
#include "hello-traits.hpp"
#include "dds/writer.hpp"
#include "dds/topic.hpp"

namespace bpython = boost::python;

typedef dds::DataWriter< swatch::hello > HelloWriter;

void create_ddswriter()
{
  dds::ReturnCode_t (HelloWriter::*hello_write)(const swatch::hello&) = &HelloWriter::write;

  bpython::class_< swatch::hello >( "SwatchHello", bpython::init<>() );

  bpython::class_< dds::Topic< swatch::hello > >( "HelloTopic", bpython::init< const std::string&, const dds::TopicQos& >() );

  bpython::class_< HelloWriter >( "HelloWriter", bpython::init< const dds::Topic< swatch::hello >&, const dds::DataWriterQos& >())
    .def( "write", hello_write )
  ;
}


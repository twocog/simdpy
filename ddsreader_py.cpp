#include <boost/python.hpp>

#include <tuple>
#include "dds/traits.hpp"
#include "gen/ccpp_hello.h"
#include "hello-traits.hpp"
#include "dds/writer.hpp"
#include "dds/reader.hpp"
#include "dds/topic.hpp"
#include "dds/types.hpp"

namespace bpython = boost::python;

typedef dds::DataWriter< swatch::hello > HelloWriter;
typedef dds::DataReader< swatch::hello > HelloReader;

void create_hellotype()
{
  DDS::ULong ( swatch::helloSeq::*helloseq_length )() const = &swatch::helloSeq::length;

  bpython::class_< swatch::hello >( "SwatchHello", bpython::init<>() )
    .def_readwrite( "name", &swatch::hello::name )
  ;

  bpython::class_< dds::Topic< swatch::hello > >( "HelloTopic", bpython::init< const std::string&, const dds::TopicQos& >() );

  bpython::class_< swatch::helloSeq_uniq_ >( "HelloSeqUniq", bpython::init<>() );

  bpython::class_< swatch::helloSeq >( "HelloSeq", bpython::init<>() )
    .def( "__len__", helloseq_length )
    .def( "length", helloseq_length )
  ;

  bpython::class_< DDS::SampleInfoSeq >( "SampleInfoSeq", bpython::init<>() );
}


void create_ddswriter()
{
  dds::ReturnCode_t (HelloWriter::*hello_write)(const swatch::hello&) = &HelloWriter::write;

  bpython::class_< HelloWriter >( "HelloWriter", bpython::init< const dds::Topic< swatch::hello >&, const dds::DataWriterQos& >())
    .def( "write", hello_write )
  ;
}

void create_ddsreader()
{
  dds::ReturnCode_t (HelloReader::*hello_read)( dds::peer::DataReaderImpl< swatch::hello >::TSeq& , dds::SampleInfoSeq& ) = &HelloReader::read;

  bpython::class_< HelloReader >( "HelloReader", bpython::init< const dds::Topic< swatch::hello >&, const dds::DataReaderQos& >())
    .def( "read", hello_read )
  ;
}


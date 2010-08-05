#include <boost/python.hpp>
#include <boost/function.hpp>

#include "dds/topic.hpp"

namespace bpython = boost::python;

typedef dds::BaseTopicQos< DDS::TopicQos, dds::TopicQosInitializer > RegularTopicQos;
typedef dds::BaseTopicQos< DDS::DataWriterQos, dds::NullInitializer > RegularWriterQos;
typedef dds::BaseTopicQos< DDS::DataReaderQos, dds::NullInitializer > RegularReaderQos;

void create_ddsbaseqos()
{
  void (RegularTopicQos::*topic_set_reliable)(void) = &RegularTopicQos::set_reliable;
  void (RegularWriterQos::*writer_set_reliable)(void) = &RegularWriterQos::set_reliable;

  bpython::class_< RegularTopicQos >("BaseTopicQos", bpython::init<>())
    .def( "set_transient", &RegularTopicQos::set_transient )
    .def( "set_reliable", topic_set_reliable)
  ;

  bpython::class_< RegularWriterQos >("BaseWriterQos", bpython::init<>())
    .def( "set_transient", &RegularWriterQos::set_transient )
    .def( "set_reliable", writer_set_reliable)
    .def( "set_keep_last", &RegularWriterQos::set_keep_last )
  ;
}

void create_ddstopicqos()
{
  bpython::class_<dds::TopicQos, bpython::bases< RegularTopicQos > >("DDSTopicQos", bpython::init<>());
}

void create_ddswriterqos()
{
  bpython::class_<dds::DataWriterQos, bpython::bases< RegularWriterQos > >("DDSWriterQos", bpython::init< const dds::TopicQos& >())
    .def( "set_auto_dispose", &dds::DataWriterQos::set_auto_dispose )
  ;
}


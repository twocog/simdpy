#include <boost/python.hpp>

#include "ddsruntime_py.h"
#include "ddswriter_py.h"
#include "ddsqos_py.h"
#include "hello_support.h"

namespace bpython = boost::python;

BOOST_PYTHON_MODULE(simdpy)
{
  create_ddsruntime();
  create_ddsbaseqos();
  create_ddstopicqos();
  create_ddswriterqos();
  create_ddswriter();

  bpython::def( "create_hello", create_hello );
}


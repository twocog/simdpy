#include <boost/python.hpp>

#include "ddsbase_py.h"
#include "ddsruntime_py.h"
#include "ddsreader_py.h"
#include "ddsqos_py.h"
#include "hello_support.h"

namespace bpython = boost::python;

BOOST_PYTHON_MODULE(simdpy)
{
  create_ddsstrings();
  create_hellotype();
  create_ddsruntime();
  create_ddsbaseqos();
  create_ddstopicqos();
  create_ddswriterqos();
  create_ddsreaderqos();
  create_ddswriter();
  create_ddsreader();

  bpython::def( "create_hello", create_hello );
}


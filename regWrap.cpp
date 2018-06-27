#include <boost/python.hpp>
#include "SignUpManually.cpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(regWrap)
{
    class_<SignUpManually>("SignUpManually", init<>())
    	.def("registration", &SignUpManually::registration);
    	// .def("goToPage", &Application::goToPage);
      // .add_property("msg", &Bonjour::get_msg, &Bonjour::set_msg);
}
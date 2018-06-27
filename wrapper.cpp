#include <boost/python.hpp>
#include "Application.cpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(wrapper)
{
    class_<Application>("Application", init<>())
    	.def("start", &Application::start);
    	//.def("goToPage", &Application::goToPage);
      // .add_property("msg", &Bonjour::get_msg, &Bonjour::set_msg);
}

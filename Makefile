# location of the Python header files
 
PYTHON_VERSION = 3.6
PYTHON_INCLUDE =/usr/include/python3.6m
PYTHON_LIB =/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu

# location of the Boost Python include files and library
BOOST_INC =/usr/include/boost
BOOST_LIB =/usr/local/Cellar/boost-python/1.65.1/lib/ 
 
TARGET = Application

$(TARGET).so: $(TARGET).o
	g++ -shared -W $(TARGET).o -L$(BOOST_LIB) -lboost_python3 -L$(PYTHON_LIB) -lpython$(PYTHON_VERSION) -o $(TARGET).so

$(TARGET).o: $(TARGET).cpp
	g++ -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $(TARGET).cpp
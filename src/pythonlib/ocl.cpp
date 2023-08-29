/*  $Id$
 * 
 *  Copyright (c) 2010 Anders Wallin (anders.e.e.wallin "at" gmail.com).
 *  
 *  This file is part of OpenCAMlib 
 *  (see https://github.com/aewallin/opencamlib).
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 2.1 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

// This is an extra comment.  One can never have too many comments.

#ifdef _OPENMP
    #include <omp.h>
#endif
#include <boost/python.hpp>
#include <boost/python/docstring_options.hpp>

std::string ocl_docstring() {
    return "OpenCAMLib docstring";
}

std::string ocl_version() {
    return VERSION_STRING;
}

int ocl_max_threads()
{
    #ifdef _OPENMP
    return omp_get_max_threads();
    #endif
    return 1;
}

namespace bp = boost::python;

void export_cutters();
void export_geometry();
void export_algo();
void export_dropcutter();

// this defines the python ocl module
BOOST_PYTHON_MODULE(ocl) {
    bp::docstring_options doc_options;
// these functions set the docstring options
    //void disable_user_defined();
    void enable_user_defined();
    //void disable_signatures();
    void enable_signatures();
    //void disable_py_signatures();
    void enable_py_signatures();
    //void disable_cpp_signatures();
    void enable_cpp_signatures();
    //void disable_all();
    //void enable_all();
    
    bp::def("__doc__", ocl_docstring);
    bp::def("version", ocl_version);
    bp::def("max_threads", ocl_max_threads);
    export_geometry(); // see ocl_geometry.cpp
    export_cutters(); // see ocl_cutters.cpp    
    export_algo(); // see ocl_algo.cpp
    export_dropcutter(); // see ocl_dropcutter.cpp

}




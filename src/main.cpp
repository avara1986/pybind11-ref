#include <pybind11/embed.h> // everything needed for embedding
# include "Python.h"
# include <string>
# include <iostream>

namespace py = pybind11;

py::object loop_list() {
    py::list my_object = py::list();
    my_object.append(1);
    my_object.append(2);
    my_object.append(3);
    int n = py::len(my_object);
    for (int i = 0; i < n; i++) {
        // BAD
        //std::cout << my_object[py::int_(i)].cast<py::str>()  << std::endl;
        // OK 1
        py::print(my_object[py::int_(i)]);
        // OK 2
        //auto my_str = my_object[py::int_(i)].cast<py::str>();
        //printf("my_object[%s]: %s", i, my_str);
    }
    return my_object;
}

void list_stuffs(){
    // Create list
    py::list my_object = py::list();
    // C way
    auto my_object_c = PyList_New(0);
    PyObject *python_val = Py_BuildValue("i", 1);

    // Append
    my_object.append(1);
    my_object.append(2);
    // Append C
    PyList_Append(my_object_c, python_val);


    // PRINT
    py::print(my_object);
    // TODO printf(my_object_c)
    // std::string a = my_object[0].cast<py::str>();
    // change_data(my_object);
}

int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive
    printf("****************\n");
    printf("List stuffs\n");
    printf("****************\n");
    list_stuffs();
    printf("****************\n");
    printf("Loops stuffs\n");
    printf("****************\n");
    loop_list();
    py::print("END!"); // use the Python API
    return 0;
}
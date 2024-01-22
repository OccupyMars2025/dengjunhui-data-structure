// #include <python3.10/Python.h>
// #include <iostream>

// /*
// g++ -o your_program_name your_program_name.cpp -lpython3.10
// TODO: sth is wrong, find out where is the bug
// */
// int main() {
//     // Initialize the Python interpreter
//     Py_Initialize();

//     // Run a Python script with eval()
//     const char pythonCode[] = "result = eval('3.14 + 2.0 * 5.0')";
//     PyRun_SimpleString(pythonCode);

//     // Access the result variable from Python
//     PyObject* result = PyDict_GetItemString(PyEval_GetLocals(), "result");

//     // Check if the result is a float
//     if (PyFloat_Check(result)) {
//         // Convert the result to a C++ double
//         double resultValue = PyFloat_AsDouble(result);
//         std::cout << "Result: " << resultValue << std::endl;
//     } else {
//         std::cerr << "Failed to get result." << std::endl;
//     }

//     // Finalize the Python interpreter
//     Py_Finalize();

//     return 0;
// }

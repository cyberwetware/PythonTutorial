/*
 * Referred from https://csl.name/post/c-functions-python/
 */
#include <Python.h>

/*
 * Function to be called from Python
*/
static PyObject* py_regardFunction(PyObject* self, PyObject* args)
{
	char *s = "Hello from C Code";
	//  Convert C datatypes into Python objects
	return Py_BuildValue("s", s);
}

/*
 * Another native function 
 */
static PyObject* py_multiplyFunction(PyObject* self, PyObject* args)
{
	double x, y;
	// Convert Python objects into C datatypes
	PyArg_ParseTuple(args, "dd", &x, &y);
	return Py_BuildValue("d", x * y);
}

/*
 * Bind Python function names to our C functions
*/
static PyMethodDef native_methods[] = {
	{"regardFunction",		py_regardFunction,		METH_VARARGS},
	{"multiplyFunction",	py_multiplyFunction,	METH_VARARGS},
	{NULL,					NULL}
};

/*
 * Called by Python with initializing native module
 */
void initpyfoo()
{
	(void) Py_InitModule("pyfoo", native_methods);
}


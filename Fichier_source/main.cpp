//#coding = <encoding name>
#include <Python.h>
#include "Video.h"
#include <sstream> 

static PyObject* goBackToStart(PyObject* self, PyObject* args)
{
	Video*video;

	PyArg_ParseTuple(args, "O", &video);

	video->retourDepart();

	PyObject * py_build_value = Py_BuildValue("i", 0);
	return py_build_value;
}

static PyObject* acceleration(PyObject* self, PyObject* args)
{
	Video*video;

	PyArg_ParseTuple(args, "O", &video);

	video->avanceRapide();

	PyObject * py_build_value = Py_BuildValue("i", 0);
	return py_build_value;
}

static PyObject* playPause(PyObject* self, PyObject* args)
{
	Video*video;

	PyArg_ParseTuple(args, "O", &video);

	video->jouerArreter();

	PyObject * py_build_value = Py_BuildValue("i", 0);
	return py_build_value;
}

static PyObject* openVideo(PyObject* self, PyObject* args)
{
	Video*video = new Video();

	if (SUCCEEDED(video->ouvrir("rue.avi"))) 
		std::cout << "Video is open";
	else
		std::cout << "Video couldnt open";

	PyObject * py_build_value = Py_BuildValue("O", video);
	return py_build_value;
}

static PyMethodDef methods[] = {

		{
		"goBackToStart",(PyCFunction)goBackToStart, METH_VARARGS,
		"Restart the video" },
		{
		"acceleration",(PyCFunction)acceleration, METH_VARARGS,
		"Run video faster" },
		{
		"playPause",(PyCFunction)playPause, METH_VARARGS,
		"Stop or run video" },
		{
		"openVideo",(PyCFunction)openVideo, METH_NOARGS,
		"Generate random number betweeen 0-9" },
		{ NULL, NULL, 0, NULL }
};
static struct PyModuleDef my_video =
{
	PyModuleDef_HEAD_INIT,
	"my_math", /* name of module */
	NULL,          /* module documentation, may be NULL */
	-1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
	methods
};

PyMODINIT_FUNC PyInit_my_video(void)
{
	return PyModule_Create(&my_video);
}
// This file implements the IPersistFolder2 Interface and Gateway for Python.
// Generated by makegw.py

#include "shell_pch.h"
#include "PyIPersist.h"
#include "PyIPersistFolder.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIPersistFolder2::PyIPersistFolder2(IUnknown *pdisp):
	PyIPersistFolder(pdisp)
{
	ob_type = &type;
}

PyIPersistFolder2::~PyIPersistFolder2()
{
}

/* static */ IPersistFolder2 *PyIPersistFolder2::GetI(PyObject *self)
{
	return (IPersistFolder2 *)PyIPersistFolder::GetI(self);
}

// @pymethod |PyIPersistFolder2|GetCurFolder|Description of GetCurFolder.
PyObject *PyIPersistFolder2::GetCurFolder(PyObject *self, PyObject *args)
{
	IPersistFolder2 *pIPF2 = GetI(self);
	if ( pIPF2 == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":GetCurFolder") )
		return NULL;
	HRESULT hr;
	PIDLIST_ABSOLUTE pidl;
	PY_INTERFACE_PRECALL;
	hr = pIPF2->GetCurFolder( &pidl );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPF2, IID_IPersistFolder2 );
	return PyObject_FromPIDL(pidl, TRUE);
}

// @object PyIPersistFolder2|Description of the interface
static struct PyMethodDef PyIPersistFolder2_methods[] =
{
	{ "GetCurFolder", PyIPersistFolder2::GetCurFolder, 1 }, // @pymeth GetCurFolder|Description of GetCurFolder
	{ NULL }
};

PyComTypeObject PyIPersistFolder2::type("PyIPersistFolder2",
		&PyIPersistFolder::type,
		sizeof(PyIPersistFolder2),
		PyIPersistFolder2_methods,
		GET_PYCOM_CTOR(PyIPersistFolder2));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGPersistFolder2::GetClassID(CLSID __RPC_FAR *pClassID) {return PyGPersistFolder::GetClassID(pClassID);}

STDMETHODIMP PyGPersistFolder2::Initialize(LPCITEMIDLIST pidl) {return PyGPersistFolder::Initialize(pidl);}

STDMETHODIMP PyGPersistFolder2::GetCurFolder(
		/* [out] */ PIDLIST_ABSOLUTE * ppidl)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetCurFolder", &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyObject_AsPIDL(result, ppidl, TRUE))
		hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetCurFolder");
	else
		hr = *ppidl ? S_OK : S_FALSE; // this is what the docs say!
	Py_DECREF(result);
	return hr;
}


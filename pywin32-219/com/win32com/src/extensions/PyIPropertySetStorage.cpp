// This file implements the IPropertySetStorage Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PythonCOM.h"
#include "PythonCOMServer.h"

#ifndef NO_PYCOM_IPROPERTYSETSTORAGE
#include "PyIPropertySetStorage.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIPropertySetStorage::PyIPropertySetStorage(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIPropertySetStorage::~PyIPropertySetStorage()
{
}

/* static */ IPropertySetStorage *PyIPropertySetStorage::GetI(PyObject *self)
{
	return (IPropertySetStorage *)PyIUnknown::GetI(self);
}

// @pymethod <o PyIPropertyStorage>|PyIPropertySetStorage|Create|Creates a new property set in the storage object
PyObject *PyIPropertySetStorage::Create(PyObject *self, PyObject *args)
{
	IPropertySetStorage *pIPSS = GetI(self);
	if ( pIPSS == NULL )
		return NULL;
	FMTID rfmtid;
	PyObject *obrfmtid;
	CLSID pclsid;
	PyObject *obpclsid;
	// @pyparm <o PyIID>|fmtid||GUID identifying a property set, pythoncom.FMTID_*
	// @pyparm <o PyIID>|clsid||CLSID of property set handler, usually same as fmtid
	// @pyparm int|Flags||Specifies behaviour of property set, storagecon.PROPSETFLAG_*
	// @pyparm int|Mode||Access mode, combination of storagecon.STGM_* flags
	DWORD grfFlags;
	DWORD grfMode;
	IPropertyStorage * ppprstg;
	if ( !PyArg_ParseTuple(args, "OOll:Create", &obrfmtid, &obpclsid, &grfFlags, &grfMode) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyWinObject_AsIID( obrfmtid, &rfmtid )) bPythonIsHappy = FALSE;
	if (bPythonIsHappy && !PyWinObject_AsIID( obpclsid, &pclsid )) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPSS->Create( rfmtid, &pclsid, grfFlags, grfMode, &ppprstg );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPSS, IID_IPropertySetStorage);

	return PyCom_PyObjectFromIUnknown(ppprstg, IID_IPropertyStorage, FALSE);
}

// @pymethod <o PyIPropertyStorage>|PyIPropertySetStorage|Open|Opens an existing property set
PyObject *PyIPropertySetStorage::Open(PyObject *self, PyObject *args)
{
	IPropertySetStorage *pIPSS = GetI(self);
	if ( pIPSS == NULL )
		return NULL;
	FMTID rfmtid;
	PyObject *obrfmtid;
	// @pyparm <o PyIID>|fmtid||GUID of a property set, pythoncom.FMTID_*
	// @pyparm int|Mode|STGM_READ \| STGM_SHARE_EXCLUSIVE|Access mode, combination of storagecon.STGM_* flags
	DWORD grfMode=STGM_READ | STGM_SHARE_EXCLUSIVE;
	IPropertyStorage * ppprstg;
	if ( !PyArg_ParseTuple(args, "O|l:Open", &obrfmtid, &grfMode) )
		return NULL;
	if (!PyWinObject_AsIID( obrfmtid, &rfmtid ))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPSS->Open( rfmtid, grfMode, &ppprstg );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPSS, IID_IPropertySetStorage);

	return PyCom_PyObjectFromIUnknown(ppprstg, IID_IPropertyStorage, FALSE);
}

// @pymethod |PyIPropertySetStorage|Delete|Removes a property set from this storage object
PyObject *PyIPropertySetStorage::Delete(PyObject *self, PyObject *args)
{
	IPropertySetStorage *pIPSS = GetI(self);
	if ( pIPSS == NULL )
		return NULL;
	FMTID rfmtid;
	PyObject *obrfmtid;
	// @pyparm <o PyIID>|fmtid||GUID of a property set, pythoncom.FMTID_*
	if ( !PyArg_ParseTuple(args, "O:Delete", &obrfmtid) )
		return NULL;
	if (!PyWinObject_AsIID( obrfmtid, &rfmtid ))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPSS->Delete( rfmtid );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPSS, IID_IPropertySetStorage);
	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod <o PyIEnumSTATPROPSETSTG>|PyIPropertySetStorage|Enum|Creates an iterator to enumerate contained property sets
PyObject *PyIPropertySetStorage::Enum(PyObject *self, PyObject *args)
{
	IPropertySetStorage *pIPSS = GetI(self);
	if ( pIPSS == NULL )
		return NULL;
	IEnumSTATPROPSETSTG * ppenum;
	if ( !PyArg_ParseTuple(args, ":Enum") )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPSS->Enum( &ppenum );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPSS, IID_IPropertySetStorage);

	return PyCom_PyObjectFromIUnknown(ppenum, IID_IEnumSTATPROPSETSTG, FALSE);
}

// @object PyIPropertySetStorage|Container for a collection of property sets.
//	Can be iterated over to enumerate property sets. 
static struct PyMethodDef PyIPropertySetStorage_methods[] =
{
	{ "Create", PyIPropertySetStorage::Create, 1 }, // @pymeth Create|Creates a new property set in the storage object
	{ "Open", PyIPropertySetStorage::Open, 1 }, // @pymeth Open|Opens an existing property set
	{ "Delete", PyIPropertySetStorage::Delete, 1 }, // @pymeth Delete|Removes a property set from this storage object
	{ "Enum", PyIPropertySetStorage::Enum, 1 }, // @pymeth Enum|Creates an iterator to enumerate contained property sets
	{ NULL }
};

PyComEnumProviderTypeObject PyIPropertySetStorage::type("PyIPropertySetStorage",
		&PyIUnknown::type,
		sizeof(PyIPropertySetStorage),
		PyIPropertySetStorage_methods,
		GET_PYCOM_CTOR(PyIPropertySetStorage),
		"Enum");

// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGPropertySetStorage::Create(
		/* [in] */ REFFMTID rfmtid,
		/* [unique][in] */ const CLSID * pclsid,
		/* [in] */ DWORD grfFlags,
		/* [in] */ DWORD grfMode,
		/* [out] */ IPropertyStorage ** ppprstg)
{
	PY_GATEWAY_METHOD;
	if (ppprstg==NULL) return E_POINTER;
	HRESULT hr;
	PyObject *result;
	{
	TmpPyObject obclsid;
	if (pclsid){
		obclsid = PyWinObject_FromIID(*pclsid);
		if (obclsid==NULL)
			return MAKE_PYCOM_GATEWAY_FAILURE_CODE("Create");
		}
	else{
		Py_INCREF(Py_None);
		obclsid = Py_None;
		}
	TmpPyObject obfmtid = PyWinObject_FromIID(rfmtid);
	if (obfmtid==NULL)
		return MAKE_PYCOM_GATEWAY_FAILURE_CODE("Create");
	hr = InvokeViaPolicy("Create", &result, "OOkk", obfmtid, obclsid, grfFlags, grfMode);
	}
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyCom_InterfaceFromPyInstanceOrObject(result, IID_IPropertyStorage, (void **)ppprstg, FALSE))
		hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("Create");
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGPropertySetStorage::Open(
		/* [in] */ REFFMTID rfmtid,
		/* [in] */ DWORD grfMode,
		/* [out] */ IPropertyStorage ** ppprstg)
{
	PY_GATEWAY_METHOD;
	TmpPyObject obfmtid = PyWinObject_FromIID(rfmtid);
	if (obfmtid==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE("Open");
	if (ppprstg==NULL) return E_POINTER;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("Open", &result, "Ok", obfmtid, grfMode);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyCom_InterfaceFromPyInstanceOrObject(result, IID_IPropertyStorage, (void **)ppprstg, FALSE))
		hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("Open");
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGPropertySetStorage::Delete(
		/* [in] */ REFFMTID rfmtid)
{
	PY_GATEWAY_METHOD;
	PyObject *obrfmtid = PyWinObject_FromIID(rfmtid);
	if (obrfmtid==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE("Delete");
	HRESULT hr=InvokeViaPolicy("Delete", NULL, "O", obrfmtid);
	Py_DECREF(obrfmtid);
	return hr;
}

STDMETHODIMP PyGPropertySetStorage::Enum(
		/* [out] */ IEnumSTATPROPSETSTG ** ppenum)
{
	PY_GATEWAY_METHOD;
	if (ppenum==NULL) return E_POINTER;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("Enum", &result);
	if (FAILED(hr))
		return hr;
	// Process the Python results, and convert back to the real params
	if (!PyCom_InterfaceFromPyInstanceOrObject(result, IID_IEnumSTATPROPSETSTG, (void **)ppenum, FALSE))
		hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("Enum");
	Py_DECREF(result);
	return hr;
}

#endif // NO_PYCOM_IPROPERTYSETSTORAGE

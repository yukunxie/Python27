// This file declares the IPersistStorage interface for Python.
// Generated by makegw.py

class PyIPersistStorage : public PyIPersist
{
public:
	MAKE_PYCOM_CTOR(PyIPersistStorage);
	static IPersistStorage *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *IsDirty(PyObject *self, PyObject *args);
	static PyObject *InitNew(PyObject *self, PyObject *args);
	static PyObject *Load(PyObject *self, PyObject *args);
	static PyObject *Save(PyObject *self, PyObject *args);
	static PyObject *SaveCompleted(PyObject *self, PyObject *args);
	static PyObject *HandsOffStorage(PyObject *self, PyObject *args);

protected:
	PyIPersistStorage(IUnknown *pdisp);
	~PyIPersistStorage();
};

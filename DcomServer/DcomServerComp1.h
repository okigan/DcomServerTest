// DcomServerComp1.h : Declaration of the CDcomServerComp1

#pragma once
#include "resource.h"       // main symbols



#include "DcomServer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CDcomServerComp1

class ATL_NO_VTABLE CDcomServerComp1 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDcomServerComp1, &CLSID_DcomServerComp1>,
    public IDispatchImpl<IDcomServerComp1, &IID_IDcomServerComp1, &LIBID_DcomServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDcomServerComp1()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DCOMSERVERCOMP1)


BEGIN_COM_MAP(CDcomServerComp1)
    COM_INTERFACE_ENTRY(IDcomServerComp1)
    COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



    STDMETHOD(Func1)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(DcomServerComp1), CDcomServerComp1)

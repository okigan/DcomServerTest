// dllmain.h : Declaration of module class.

class CDcomServerModule : public ATL::CAtlDllModuleT< CDcomServerModule >
{
public :
	DECLARE_LIBID(LIBID_DcomServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DCOMSERVER, "{D3B68D9F-AE51-40A1-91D7-8F22C8A44B0E}")
};

extern class CDcomServerModule _AtlModule;

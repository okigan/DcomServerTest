// DcomServerTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define HRCALL(hr, __VA_ARGS__)     if(FAILED(hr = __VA_ARGS__)){ \
                                        _tprintf(_T("Error: %x on line %d: %s.\n"), hr, __LINE__, _T(#__VA_ARGS__)); \
                                        return hr; \
                                    }

class CCoInit{
public:
    CCoInit(){
    }
    ~CCoInit(){
        CoUninitialize();
    }

    HRESULT Init(LPVOID pvReserved = NULL){
        return CoInitialize(pvReserved);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    CCoInit coi;
    HRESULT hr = S_OK;

    HRCALL(hr, coi.Init(NULL));

    {
        CComPtr<IDispatch> piUnknown;

        TCHAR* pszCLSID = _T("{4BB55D7E-B362-41F8-9555-6328B6D4B703}");
        CLSID   clsid = CLSID_NULL;
        //CLSCTX  clsctx= static_cast<CLSCTX>(CLSCTX_ALL);
        CLSCTX  clsctx= static_cast<CLSCTX>(CLSCTX_LOCAL_SERVER);

        HRCALL(hr, CLSIDFromString(CT2OLE(pszCLSID), &clsid));
        HRCALL(hr, piUnknown.CoCreateInstance(clsid, NULL, clsctx));
    }
    return hr;
}


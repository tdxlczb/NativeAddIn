// dllmain.h : 模块类的声明。

class CNativeAddInModule : public ATL::CAtlDllModuleT< CNativeAddInModule >
{
public :
	DECLARE_LIBID(LIBID_NativeAddInLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_NATIVEADDIN, "{3940F9DF-FE9A-4678-9CCD-169EE106B58B}")
};

extern class CNativeAddInModule _AtlModule;

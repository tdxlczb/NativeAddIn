// Connect.h : CConnect 的声明

#pragma once
#include "resource.h"       // 主符号



#include "NativeAddIn_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CConnect
typedef IDispatchImpl<_IDTExtensibility2, &__uuidof(_IDTExtensibility2), &__uuidof(__AddInDesignerObjects), /* wMajor = */ 1>
	IDTImpl;
typedef IDispatchImpl<IRibbonExtensibility, &__uuidof(IRibbonExtensibility), &__uuidof(__Office), /* wMajor = */ 2, /* wMinor = */ 5>
	RibbonImpl;
typedef IDispatchImpl<IRibbonCallback, &__uuidof(IRibbonCallback)> 
	CallbackImpl;
class ATL_NO_VTABLE CConnect :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CConnect, &CLSID_Connect>,
	public IDispatchImpl<IConnect, &IID_IConnect, &LIBID_NativeAddInLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	//public IDispatchImpl<_IDTExtensibility2, &__uuidof(_IDTExtensibility2), &LIBID_AddInDesignerObjects, /* wMajor = */ 1>,
	public IDTImpl,
	public RibbonImpl,
	public CallbackImpl
{
public:
	CConnect()
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_CONNECT)


	BEGIN_COM_MAP(CConnect)
		COM_INTERFACE_ENTRY(IConnect)
		//COM_INTERFACE_ENTRY2(IDispatch, _IDTExtensibility2)
		COM_INTERFACE_ENTRY2(IDispatch, IRibbonCallback)
		COM_INTERFACE_ENTRY(_IDTExtensibility2)
		COM_INTERFACE_ENTRY(IRibbonExtensibility)
		COM_INTERFACE_ENTRY(IRibbonCallback)
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




	// _IDTExtensibility2 Methods
public:
	STDMETHOD(OnConnection)(LPDISPATCH Application, ext_ConnectMode ConnectMode, LPDISPATCH AddInInst, SAFEARRAY * * custom)
	{
		//MessageBoxW(NULL,L"OnConnection",L"Native Addin",MB_OK);
		return S_OK;
	}
	STDMETHOD(OnDisconnection)(ext_DisconnectMode RemoveMode, SAFEARRAY * * custom)
	{
		return S_OK;
	}
	STDMETHOD(OnAddInsUpdate)(SAFEARRAY * * custom)
	{
		return S_OK;
	}
	STDMETHOD(OnStartupComplete)(SAFEARRAY * * custom)
	{
		return S_OK;
	}
	STDMETHOD(OnBeginShutdown)(SAFEARRAY * * custom)
	{
		return S_OK;
	}

	// IRibbonExtensibility Methods
public:
	STDMETHOD(GetCustomUI)(BSTR RibbonID, BSTR * RibbonXml)
	{
		if(!RibbonXml)
			return E_POINTER;
		//*RibbonXml = CComBSTR("XML GOES HERE");
		*RibbonXml = GetXMLResource(IDR_XML1);
		return S_OK;
	}

	HRESULT HrGetResource(int nId, 
		LPCTSTR lpType, 
		LPVOID* ppvResourceData,       
		DWORD* pdwSizeInBytes)
	{
		HMODULE hModule = _AtlBaseModule.GetModuleInstance();
		if (!hModule)
			return E_UNEXPECTED;
		HRSRC hRsrc = FindResource(hModule, MAKEINTRESOURCE(nId), lpType);
		if (!hRsrc)
			return HRESULT_FROM_WIN32(GetLastError());
		HGLOBAL hGlobal = LoadResource(hModule, hRsrc);
		if (!hGlobal)
			return HRESULT_FROM_WIN32(GetLastError());
		*pdwSizeInBytes = SizeofResource(hModule, hRsrc);
		*ppvResourceData = LockResource(hGlobal);
		return S_OK;
	}

	BSTR GetXMLResource(int nId)
	{
		LPVOID pResourceData = NULL;
		DWORD dwSizeInBytes = 0;
		HRESULT hr = HrGetResource(nId, TEXT("XML"), 
			&pResourceData, &dwSizeInBytes);
		if (FAILED(hr))
			return NULL;
		// Assumes that the data is not stored in Unicode.
		CComBSTR cbstr(dwSizeInBytes, reinterpret_cast<LPCSTR>(pResourceData));
		return cbstr.Detach();
	}

	SAFEARRAY* GetOFSResource(int nId)
	{
		LPVOID pResourceData = NULL;
		DWORD dwSizeInBytes = 0;
		if (FAILED(HrGetResource(nId, TEXT("OFS"), 
			&pResourceData, &dwSizeInBytes)))
			return NULL;
		SAFEARRAY* psa;
		SAFEARRAYBOUND dim = {dwSizeInBytes, 0};
		psa = SafeArrayCreate(VT_UI1, 1, &dim);
		if (psa == NULL)
			return NULL;
		BYTE* pSafeArrayData;
		SafeArrayAccessData(psa, (void**)&pSafeArrayData);
		memcpy((void*)pSafeArrayData, pResourceData, dwSizeInBytes);
		SafeArrayUnaccessData(psa);
		return psa;
	}

	// IRibbonCallback Methods
public:
	STDMETHOD(ButtonClicked)(IDispatch* ribbon)
	{
		MessageBoxW(NULL,L"Button Clicked!",L"NativeAddin",MB_OK);
		return S_OK;
	}

	//STDMETHOD(Invoke)(DISPID dispidMember, 
	//	const IID &riid, 
	//	LCID lcid, 
	//	WORD wFlags, 
	//	DISPPARAMS *pdispparams, 
	//	VARIANT *pvarResult, 
	//	EXCEPINFO *pexceptinfo, 
	//	UINT *puArgErr)
	//{
	//	HRESULT hr=DISP_E_MEMBERNOTFOUND;
	//	if(dispidMember==42)
	//	{
	//		hr  = CallbackImpl::Invoke(dispidMember, 
	//			riid, 
	//			lcid, 
	//			wFlags,       
	//			pdispparams, 
	//			pvarResult, 
	//			pexceptinfo, 
	//			puArgErr);
	//	}
	//	if (DISP_E_MEMBERNOTFOUND == hr)
	//		hr = IDTImpl::Invoke(dispidMember, 
	//		riid, 
	//		lcid, 
	//		wFlags, 
	//		pdispparams, 
	//		pvarResult, 
	//		pexceptinfo, 
	//		puArgErr);
	//	return hr;
	//}
};

OBJECT_ENTRY_AUTO(__uuidof(Connect), CConnect)

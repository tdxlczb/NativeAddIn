

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Fri Mar 16 16:28:33 2018
 */
/* Compiler settings for NativeAddIn.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IConnect,0x536F896B,0x6A01,0x426E,0x88,0x83,0xA7,0xB7,0x0D,0xD5,0x16,0xFF);


MIDL_DEFINE_GUID(IID, LIBID_NativeAddInLib,0x2B9C3447,0x43AA,0x404E,0xBD,0xD9,0xCB,0x3F,0x57,0x8E,0x5E,0x06);


MIDL_DEFINE_GUID(CLSID, CLSID_Connect,0xCE757FEF,0x8C53,0x4956,0xBB,0xEF,0x5F,0x41,0x21,0x74,0x30,0xA5);


MIDL_DEFINE_GUID(IID, IID_IRibbonCallback,0x9ADEC42E,0x0687,0x4377,0xAD,0x70,0x5D,0x9F,0x81,0x02,0xF6,0x77);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




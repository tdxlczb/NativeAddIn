// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED

#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯��������ʽ��


#define ATL_NO_ASSERT_ON_DESTROY_NONEXISTENT_WINDOW

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
//#import "C:\Program Files (x86)\Common Files\Designer\MSADDNDR.DLL" raw_interfaces_only, raw_native_types, no_namespace, named_guids, auto_search

#import "libid:AC0714F2-3D04-11D1-AE7D-00A0C90F26F4"\
	auto_rename auto_search raw_interfaces_only rename_namespace("AddinDesign")
using namespace AddinDesign;

// Office type library (i.e., mso.dll).
#import "..\office\mso.dll"\
	auto_rename auto_search raw_interfaces_only rename_namespace("Office")
using namespace Office;
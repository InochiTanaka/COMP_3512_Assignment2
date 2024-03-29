#pragma once

#ifndef __ASN2_UI_GETPATIENT_H__
#define __ASN2_UI_GETPATIENT_H__

//====================================================================================================
//	UI_GetPatient.h
//
//	The Act of Attending to a Patient
//----------------------------------------------------------------------------------------------------
//	Inochi Tanaka		Joseph Yang
//	A00978984			A00950913
//====================================================================================================


//----------------------------------------------------------------------------------------------------
//-- Dependency --------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#include "ProjectIncludes.h"

//----------------------------------------------------------------------------------------------------
//-- Class Declerations ------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

class UI_GetPatient : public UIBase
{
public:
	UI_GetPatient(Triage& Triageptr);
	virtual ~UI_GetPatient() {}

public:
	virtual void Print();
	virtual void Action();

};

#endif
#pragma once
#ifndef __ASN2_UIBASE_H__
#define __ASN2_UIBASE_H__

#include "Triage.h"

class UIBase
{
public:
	UIBase() {}
	virtual ~UIBase() {}

public:
	virtual void Print() {}		// Print if needed
	virtual void Action() {}		// Action Based on state


public:
	Triage mPrimaryTriage;

};


#endif // !__ASN2_UIBASE_H__

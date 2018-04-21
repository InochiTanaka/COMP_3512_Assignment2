#pragma once
#ifndef __ASN2_PRIORITYLVL_H__
#define __ASN2_PRIORITYLVL_H__

//====================================================================================================
//	Priority Level Enum
//
//	Enum for Condition Levels
//----------------------------------------------------------------------------------------------------
//	Inochi Tanaka		Joseph Yang
//	A00978984			A00950913
//====================================================================================================

enum PriorityLevel
{
	CRITICAL,
	CRITICAL_STABLE,
	SEVERE,	
	SERIOUS,
	GOOD,
	COMFORTABLE,
	END	// Used for iteration loop
};

#endif
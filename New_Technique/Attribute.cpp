#include "stdafx.h"
#include "Attribute.h"

string GetAttributeTypeString(ATTRIBUTE_TYPE attriType){
	switch(attriType){
	case ATTRIBUTE_TYPE::HP:
		return "HP";
	case ATTRIBUTE_TYPE::MP:
		return "MP";
	case ATTRIBUTE_TYPE::DAMAGE:
		return "DAMAGE";
	default:
		return "ATTRIBUTE_TYPE Unknown";
	}
}

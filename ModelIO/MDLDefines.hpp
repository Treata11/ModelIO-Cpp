/*
 MDLDefines.hpp

 Created by Treata Norouzi on 8/12/24.
 
 Based on: MTLDefines.hpp
*/

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "Foundation/NSDefines.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#define _MDL_EXPORT _NS_EXPORT
#define _MDL_EXTERN _NS_EXTERN
#define _MDL_INLINE _NS_INLINE
#define _MDL_PACKED _NS_PACKED

#define _MDL_CONST(type, name) _NS_CONST(type, name)
#define _MDL_ENUM(type, name) _NS_ENUM(type, name)
#define _MDL_OPTIONS(type, name) _NS_OPTIONS(type, name)

#define _MDL_VALIDATE_SIZE(ns, name) _NS_VALIDATE_SIZE(ns, name)
#define _MDL_VALIDATE_ENUM(ns, name) _NS_VALIDATE_ENUM(ns, name)

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

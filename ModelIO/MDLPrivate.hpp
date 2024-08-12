/*
 MDLPrivate.hpp

 Created by Treata Norouzi on 8/11/24.
 
 Based on: Metal/MTLPrivate.hpp
*/


#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "MDLDefines.hpp"

#include <objc/runtime.h>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#define _MDL_PRIVATE_CLS(symbol) (Private::Class::s_k##symbol)
#define _MDL_PRIVATE_SEL(accessor) (Private::Selector::s_k##accessor)

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#if defined(MDL_PRIVATE_IMPLEMENTATION)

// TODO: ...
#define _MDL_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define _MDL_PRIVATE_IMPORT __attribute__((weak_import))

#if __OBJC__
#define _MDL_PRIVATE_OBJC_LOOKUP_CLASS(symbol) ((__bridge void*)objc_lookUpClass(#symbol))
#else
#define _MDL_PRIVATE_OBJC_LOOKUP_CLASS(symbol) objc_lookUpClass(#symbol)
#endif // __OBJC__

#define _MDL_PRIVATE_DEF_CLS(symbol) void* s_k##symbol _MDL_PRIVATE_VISIBILITY = _MDL_PRIVATE_OBJC_LOOKUP_CLASS(symbol);
#define _MDL_PRIVATE_DEF_PRO(symbol)
#define _MDL_PRIVATE_DEF_SEL(accessor, symbol) SEL s_k##accessor _MDL_PRIVATE_VISIBILITY = sel_registerName(symbol);

#if defined(__MAC_10_16) || defined(__MAC_11_0) || defined(__MAC_12_0) || defined(__IPHONE_14_0) || defined(__IPHONE_15_0) || defined(__TVOS_14_0) || defined(__TVOS_15_0)

#define _MDL_PRIVATE_DEF_STR(type, symbol)                  \
    _MDL_EXTERN type const MDL##symbol _MDL_PRIVATE_IMPORT; \
    type const                         MDL::symbol = (nullptr != &MDL##symbol) ? MDL##symbol : nullptr;

#else

#include <dlfcn.h>

namespace MDL
{
namespace Private
{

    template <typename _Type>
    inline _Type const LoadSymbol(const char* pSymbol)
    {
        const _Type* pAddress = static_cast<_Type*>(dlsym(RTLD_DEFAULT, pSymbol));

        return pAddress ? *pAddress : nullptr;
    }

} // Private
} // MDL

#define _MDL_PRIVATE_DEF_STR(type, symbol) \
    _MDL_EXTERN type const MDL##symbol;    \
    type const             MDL::symbol = Private::LoadSymbol<type>("MDL" #symbol);

#endif // defined(__MAC_10_16) || defined(__MAC_11_0) || defined(__MAC_12_0) || defined(__IPHONE_14_0) || defined(__IPHONE_15_0) || defined(__TVOS_14_0) || defined(__TVOS_15_0)

#else

// FIXME: No member named 's_k##symbol' in namespace 'MDL::Private::Selector'
#define _MDL_PRIVATE_DEF_CLS(symbol) extern void* s_k##symbol;
#define _MDL_PRIVATE_DEF_PRO(symbol)
// FIXME: No member named 's_k##accessor' in namespace 'MDL::Private::Selector'
#define _MDL_PRIVATE_DEF_SEL(accessor, symbol) extern SEL s_k##accessor;
#define _MDL_PRIVATE_DEF_STR(type, symbol)

#endif // MDL_PRIVATE_IMPLEMENTATION

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace MDL
{
namespace Private
{
    namespace Class
    {

    } // Class
} // Private
} // MDL

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace MDL
{
namespace Private
{
    namespace Protocol
    {

    } // Protocol
} // Private
} // MDL

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace MDL
{
namespace Private
{
    namespace Selector
    {

        _MDL_PRIVATE_DEF_SEL(beginScope,
            "beginScope");
        _MDL_PRIVATE_DEF_SEL(endScope,
            "endScope");
    } // Class
} // Private
} // MDL

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


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

#define _MDL_PRIVATE_DEF_CLS(symbol) extern void* s_k##symbol;
#define _MDL_PRIVATE_DEF_PRO(symbol)
#define _MDL_PRIVATE_DEF_SEL(accessor, symbol) extern SEL s_k##accessor;
#define _MDL_PRIVATE_DEF_STR(type, symbol)

#endif // MDL_PRIVATE_IMPLEMENTATION

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//namespace MDL
//{
//namespace Private
//{
//    namespace Class
//    {
//
//    } // Class
//} // Private
//} // MDL

namespace MDL::Private::Class
{
// MDLValueTypes.hpp
    _MDL_PRIVATE_DEF_CLS( MTLMatrix4x4Array );

// MDLVertexDescriptor.hpp
    _MDL_PRIVATE_DEF_CLS( MDLVertexBufferLayout );
    _MDL_PRIVATE_DEF_CLS( MDLVertexAttribute );
    _MDL_PRIVATE_DEF_CLS( MDLVertexDescriptor );

// MDLObject.hpp
    _MDL_PRIVATE_DEF_CLS( MDLObject );
    _MDL_PRIVATE_DEF_CLS( MDLObjectContainer );


} // Class

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//namespace MDL
//{
//namespace Private
//{
//    namespace Protocol
//    {
//
//    } // Protocol
//} // Private
//} // MDL

// TODO: Add the remaining Protocols 
namespace MDL::Private::Protocol
{
// MDLTypes.hpp
    _MDL_PRIVATE_DEF_PRO(MDLNamed);
    _MDL_PRIVATE_DEF_PRO(MDLComponent);
    _MDL_PRIVATE_DEF_PRO(MDLObjectContainerComponent);


}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//namespace MDL
//{
//namespace Private
//{
//    namespace Selector
//    {
//
//    } // Selector
//} // Private
//} // MDL

namespace MDL::Private::Selector
{
// MDLTypes.hpp
    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( setName_, "setName_" );
    _MDL_PRIVATE_DEF_SEL( addObject_, "addObject:" );
    _MDL_PRIVATE_DEF_SEL( removeObject_, "removeObject:" );
    _MDL_PRIVATE_DEF_SEL( objectAtIndexedSubscript_, "objectAtIndexedSubscript:" );
    _MDL_PRIVATE_DEF_SEL( count, "count" );
    _MDL_PRIVATE_DEF_SEL( objects, "objects" );

// MDLValueTypes.hpp
    _MDL_PRIVATE_DEF_SEL( initWithElementCount_, "initWithElementCount:" );
    _MDL_PRIVATE_DEF_SEL( elementCount, "elementCount" );
    _MDL_PRIVATE_DEF_SEL( precision, "precision" );
    _MDL_PRIVATE_DEF_SEL( clear, "clear" );
    _MDL_PRIVATE_DEF_SEL( setFloat4x4Array_count_, "setFloat4x4Array:count:" );
    _MDL_PRIVATE_DEF_SEL( setDouble4x4Array_count_, "setDouble4x4Array:count:" );
    _MDL_PRIVATE_DEF_SEL( getFloat4x4Array_maxCount_, "getFloat4x4Array:maxCount:" );
    _MDL_PRIVATE_DEF_SEL( getDouble4x4Array_maxCount_, "getDouble4x4Array:maxCount:" );

// MDLVertexDescriptor.hpp
    _MDL_PRIVATE_DEF_SEL( initWithStride_stride_, "initWithStride:stride:" );
    _MDL_PRIVATE_DEF_SEL( stride, "stride" );
    _MDL_PRIVATE_DEF_SEL( setStride_, "setStride:" );

    _MDL_PRIVATE_DEF_SEL( initWithName_format_offset_bufferIndex_, "initWithName:format:offset:bufferIndex:" );
    _MDL_PRIVATE_DEF_SEL( name, "name" );
    _MDL_PRIVATE_DEF_SEL( setName_, "setName:" );
    _MDL_PRIVATE_DEF_SEL( format, "format" );
    _MDL_PRIVATE_DEF_SEL( setFormat_, "setFormat:" );
    _MDL_PRIVATE_DEF_SEL( offset, "offset" );
    _MDL_PRIVATE_DEF_SEL( setOffset_, "setOffset:" );
    _MDL_PRIVATE_DEF_SEL( time, "time" );
    _MDL_PRIVATE_DEF_SEL( setTime_, "setTime:" );
    _MDL_PRIVATE_DEF_SEL( initializationValue, "initializationValue" );
    _MDL_PRIVATE_DEF_SEL( setInitializationValue_, "setInitializationValue:" );

    _MDL_PRIVATE_DEF_SEL( initVertexDescriptor_, "initVertexDescriptor:" );
    _MDL_PRIVATE_DEF_SEL( attributeNamed_, "attributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( addOrReplaceAttribute_, "addOrReplaceAttribute:" );
    _MDL_PRIVATE_DEF_SEL( removeAttributeNamed_, "removeAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( reset_, "reset:" );
    _MDL_PRIVATE_DEF_SEL( setPackedStrides_, "setPackedStrides:" );
    _MDL_PRIVATE_DEF_SEL( setPackedOffsets_, "setPackedOffsets:" );

// MDLObject.hpp
    _MDL_PRIVATE_DEF_SEL( components, "components" );
    _MDL_PRIVATE_DEF_SEL( setComponent_forProtocol_, "setComponent:forProtocol:" );
    _MDL_PRIVATE_DEF_SEL( componentConformingToProtocol_, "componentConformingToProtocol:" );
    _MDL_PRIVATE_DEF_SEL( objectForKeyedSubscript_, "objectForKeyedSubscript:" );
    _MDL_PRIVATE_DEF_SEL( setObject_forKeyedSubscript_, "setObject:forKeyedSubscript:" );
    _MDL_PRIVATE_DEF_SEL( parent, "parent" );
    _MDL_PRIVATE_DEF_SEL( instance, "instance" );
    _MDL_PRIVATE_DEF_SEL( path, "path" );
    _MDL_PRIVATE_DEF_SEL( objectAtPath_, "objectAtPath:" );
    _MDL_PRIVATE_DEF_SEL( enumerateChildObjectsOfClass_root_usingBlock_stopPointer_, "enumerateChildObjectsOfClass:root:usingBlock:stopPointer:" );
    _MDL_PRIVATE_DEF_SEL( transform, "transform" );
    _MDL_PRIVATE_DEF_SEL( setTransform_, "setTransform:" );
    _MDL_PRIVATE_DEF_SEL( children, "children" );
    _MDL_PRIVATE_DEF_SEL( setChildren_, "setChildren:" );
    _MDL_PRIVATE_DEF_SEL( hidden, "hidden" );
    _MDL_PRIVATE_DEF_SEL( setHidden_, "setHidden:" );
    _MDL_PRIVATE_DEF_SEL( addChild_, "addChild:" );
    _MDL_PRIVATE_DEF_SEL( boundingBoxAtTime_, "boundingBoxAtTime:" );

} // Selector

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


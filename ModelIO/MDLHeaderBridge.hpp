/*
 MDLHeaderBridge.hpp

 Created by Treata Norouzi on 8/16/24.
*/

#pragma once
#include "MDLPrivate.hpp"

// MARK: - Clas

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

// MDLTransform.hpp
    _MDL_PRIVATE_DEF_CLS( MDLTransform );

// MDLMeshBuffer.hpp
    _MDL_PRIVATE_DEF_CLS( MDLMeshBufferMap );
    _MDL_PRIVATE_DEF_CLS( MDLMeshBufferData );
    _MDL_PRIVATE_DEF_CLS( MDLMeshBufferDataAllocator );
    _MDL_PRIVATE_DEF_CLS( MDLMeshBufferZoneDefault );

} // Class

// MARK: - Protocol

// TODO: Add the remaining Protocols
namespace MDL::Private::Protocol
{
// MDLTypes.hpp
    _MDL_PRIVATE_DEF_PRO(MDLNamed);
    _MDL_PRIVATE_DEF_PRO(MDLComponent);
    _MDL_PRIVATE_DEF_PRO(MDLObjectContainerComponent);


}

// MARK: - Selector

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

// MDLTransform.hpp
    _MDL_PRIVATE_DEF_SEL( matrix, "matrix" );
    _MDL_PRIVATE_DEF_SEL( setMatrix_, "setMatrix:" );
    _MDL_PRIVATE_DEF_SEL( resetsTransform, "resetsTransform" );
    _MDL_PRIVATE_DEF_SEL( setResetsTransform_, "setResetsTransform:" );
    _MDL_PRIVATE_DEF_SEL( minimumTime, "minimumTime" );
    _MDL_PRIVATE_DEF_SEL( maximumTime, "maximumTime" );
    _MDL_PRIVATE_DEF_SEL( keyTimes, "keyTimes" );
    _MDL_PRIVATE_DEF_SEL( setLocalTransform_forTime_, "setLocalTransform:forTime:" );
    _MDL_PRIVATE_DEF_SEL( setLocalTransform_, "setLocalTransform:" );
    _MDL_PRIVATE_DEF_SEL( localTransformAtTime_, "localTransformAtTime:" );
    _MDL_PRIVATE_DEF_SEL( globalTransformWithObject_atTime_, "globalTransformWithObject:atTime:" );
    _MDL_PRIVATE_DEF_SEL( initWithTransformComponent_, "initWithTransformComponent:" );
    _MDL_PRIVATE_DEF_SEL( initWithTransformComponent_resetsTransform_, "initWithTransformComponent:resetsTransform:" );
    _MDL_PRIVATE_DEF_SEL( initWithMatrix_, "initWithMatrix:" );
    _MDL_PRIVATE_DEF_SEL( initWithMatrix_resetsTransform_, "initWithMatrix:resetsTransform:" );
    _MDL_PRIVATE_DEF_SEL( setIdentity, "setIdentity" );
    _MDL_PRIVATE_DEF_SEL( translationAtTime_, "translationAtTime:" );
    _MDL_PRIVATE_DEF_SEL( rotationAtTime_, "rotationAtTime:" );
    _MDL_PRIVATE_DEF_SEL( shearAtTime_, "shearAtTime:" );
    _MDL_PRIVATE_DEF_SEL( scaleAtTime_, "scaleAtTime:" );
    _MDL_PRIVATE_DEF_SEL( setMatrix_forTime_, "setMatrix_forTime:" );
    _MDL_PRIVATE_DEF_SEL( setTranslation_forTime_, "setTranslation:forTime:" );
    _MDL_PRIVATE_DEF_SEL( setRotation_forTime_, "setRotation:forTime:" );
    _MDL_PRIVATE_DEF_SEL( setShear_forTime_, "setShear:forTime:" );
    _MDL_PRIVATE_DEF_SEL( setScale_forTime_, "setScale:forTime:" );
    _MDL_PRIVATE_DEF_SEL( rotationMatrixAtTime_, "rotationMatrixAtTime:" );
    _MDL_PRIVATE_DEF_SEL( translation, "translation" );
    _MDL_PRIVATE_DEF_SEL( setTranslation_, "setTranslation:" );
    _MDL_PRIVATE_DEF_SEL( rotation, "rotation" );
    _MDL_PRIVATE_DEF_SEL( setRotation_, "setRotation:" );
    _MDL_PRIVATE_DEF_SEL( shear, "shear" );
    _MDL_PRIVATE_DEF_SEL( setShear_, "setShear:" );
    _MDL_PRIVATE_DEF_SEL( scale, "scale" );
    _MDL_PRIVATE_DEF_SEL( setScale_, "setScale:" );

// MDLMeshBuffer.hpp
    _MDL_PRIVATE_DEF_SEL( initWithBytes_deallocator_, "initWithBytes:deallocator:" );
    _MDL_PRIVATE_DEF_SEL( bytes, "bytes" );
    _MDL_PRIVATE_DEF_SEL( fillData_offset_, "fillData:offset:" );
    _MDL_PRIVATE_DEF_SEL( length, "length" );
    _MDL_PRIVATE_DEF_SEL( allocator, "allocator" );
    _MDL_PRIVATE_DEF_SEL( zone, "zone" );
    _MDL_PRIVATE_DEF_SEL( type, "type" );

    _MDL_PRIVATE_DEF_SEL( data, "data" );

    _MDL_PRIVATE_DEF_SEL( capacity, "capacity" );
    //_MDL_PRIVATE_DEF_SEL( allocator, "allocator" );

    _MDL_PRIVATE_DEF_SEL( newZone_, "newZone:" );
    _MDL_PRIVATE_DEF_SEL( newZoneForBuffersWithSize_andType_, "newZoneForBuffersWithSize:andType:" );
    _MDL_PRIVATE_DEF_SEL( newBuffer_type_, "newBuffer:type:" );
    _MDL_PRIVATE_DEF_SEL( newBufferWithData_type_, "newBufferWithData:type:" );
    _MDL_PRIVATE_DEF_SEL( newBufferFromZone_length_type_, "newBufferFromZone:length_type:" );
    //_MDL_PRIVATE_DEF_SEL( newBufferFromZone_length_type_, "newBufferFromZone:length_type:" );


} // Selector

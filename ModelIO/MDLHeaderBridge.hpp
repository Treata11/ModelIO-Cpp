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

// MDLAssetResolver.hpp
    _MDL_PRIVATE_DEF_CLS( MDLRelativeAssetResolver );
    _MDL_PRIVATE_DEF_CLS( MDLPathAssetResolver );
    _MDL_PRIVATE_DEF_CLS( MDLBundleAssetResolver );

// MDLVoxelArray.hpp
    _MDL_PRIVATE_DEF_CLS( MDLVoxelArray );

// MDLAnimatedValueTypes.hpp
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedValue );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedScalarArray );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedVector3Array );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedQuaternionArray );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedScalar );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedVector2 );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedVector3 );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedVector4 );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedQuaternion );
    _MDL_PRIVATE_DEF_CLS( MDLAnimatedMatrix4x4 );

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

// MDLAssetResolver.hpp
    _MDL_PRIVATE_DEF_SEL( canResolveAssetNamed_, "canResolveAssetNamed:" );
    _MDL_PRIVATE_DEF_SEL( resolveAssetNamed_, "resolveAssetNamed:" );

    _MDL_PRIVATE_DEF_SEL( initWithAsset_, "initWithAsset:" );
    _MDL_PRIVATE_DEF_SEL( asset, "asset" );
    _MDL_PRIVATE_DEF_SEL( setAsset_, "setAsset:" );

    _MDL_PRIVATE_DEF_SEL( initWithPath_, "initWithPath:" );
    _MDL_PRIVATE_DEF_SEL( setPath_, "setPath:" );

    _MDL_PRIVATE_DEF_SEL( initWithBundle_, "initWithBundle:" );
    //_MDL_PRIVATE_DEF_SEL( initWithPath_, "initWithPath:" );
    //_MDL_PRIVATE_DEF_SEL( setPath_, "setPath:" );

// MDLVoxelArray.hpp
    _MDL_PRIVATE_DEF_SEL( initWithAsset_divisions_patchRadius_, "initWithAsset:divisions:patchRadius:" );
    _MDL_PRIVATE_DEF_SEL( initWithData_boundingBox_voxelExtent_, "initWithData:boundingBox:voxelExtent:" );
    _MDL_PRIVATE_DEF_SEL( initWithAsset_divisions_interiorShells_exteriorShells_patchRadius_, 
                         "initWithAsset:divisions_interiorShells:exteriorShells:patchRadius:" );
    //_MDL_PRIVATE_DEF_SEL( count, "count" );
    _MDL_PRIVATE_DEF_SEL( voxelIndexExtent, "voxelIndexExtent" );
    _MDL_PRIVATE_DEF_SEL( voxelExistsAtIndex_allowAnyX_allowAnyY_allowAnyZ_allowAnyShell_,
                         "voxelExistsAtIndex:allowAnyX:allowAnyY:allowAnyZ:allowAnyShell:" );
    _MDL_PRIVATE_DEF_SEL( voxelsWithinExtent_, "voxelsWithinExtent:" );
    _MDL_PRIVATE_DEF_SEL( voxelIndices, "voxelIndices" );
    _MDL_PRIVATE_DEF_SEL( setVoxelAtIndex_, "setVoxelAtIndex:" );
    _MDL_PRIVATE_DEF_SEL( setVoxelsForMesh_divisions_patchRadius_, "setVoxelsForMesh:divisions:patchRadius:" );
    _MDL_PRIVATE_DEF_SEL( setVoxelsForMesh_divisions_interiorShells_exteriorShells_patchRadius_,
                         "setVoxelsForMesh:divisions:interiorShells:exteriorShells:patchRadius:" );
    _MDL_PRIVATE_DEF_SEL( setVoxelsForMesh_divisions_interiorNBWidth_exteriorNBWidth_patchRadius_,
                         "setVoxelsForMesh:divisions:interiorNBWidth:exteriorNBWidth:patchRadius:" );
    _MDL_PRIVATE_DEF_SEL( unionWithVoxels_, "unionWithVoxels:" );
    _MDL_PRIVATE_DEF_SEL( intersectWithVoxels_, "intersectWithVoxels:" );
    _MDL_PRIVATE_DEF_SEL( differenceWithVoxels_, "differenceWithVoxels:" );
    _MDL_PRIVATE_DEF_SEL( boundingBox, "boundingBox" );
    _MDL_PRIVATE_DEF_SEL( indexOfSpatialLocation_, "indexOfSpatialLocation:" );
    _MDL_PRIVATE_DEF_SEL( spatialLocationOfIndex_, "spatialLocationOfIndex:" );
    _MDL_PRIVATE_DEF_SEL( voxelBoundingBoxAtIndex_, "voxelBoundingBoxAtIndex:" );
    _MDL_PRIVATE_DEF_SEL( convertToSignedShellField_, "convertToSignedShellField:" );
    _MDL_PRIVATE_DEF_SEL( isValidSignedShellField, "isValidSignedShellField" );
    _MDL_PRIVATE_DEF_SEL( shellFieldInteriorThickness, "shellFieldInteriorThickness" );
    _MDL_PRIVATE_DEF_SEL( setShellFieldInteriorThickness_, "setShellFieldInteriorThickness:" );
    _MDL_PRIVATE_DEF_SEL( shellFieldExteriorThickness, "shellFieldExteriorThickness" );
    _MDL_PRIVATE_DEF_SEL( setShellFieldExteriorThickness_, "setShellFieldExteriorThickness:" );
    _MDL_PRIVATE_DEF_SEL( coarseMesh, "coarseMesh" );
    _MDL_PRIVATE_DEF_SEL( coarseMeshUsingAllocator_, "coarseMeshUsingAllocator:" );
    _MDL_PRIVATE_DEF_SEL( meshUsingAllocator_, "meshUsingAllocator:" );

// MDLAnimatedValueTypes.hpp
    _MDL_PRIVATE_DEF_SEL( isAnimated, "isAnimated" );
    //_MDL_PRIVATE_DEF_SEL( precision, "precision" );
    _MDL_PRIVATE_DEF_SEL( timeSampleCount, "timeSampleCount" );
    //_MDL_PRIVATE_DEF_SEL( minimumTime, "minimumTime" );
    //_MDL_PRIVATE_DEF_SEL( maximumTime, "maximumTime" );
    _MDL_PRIVATE_DEF_SEL( interpolation, "interpolation" );
    _MDL_PRIVATE_DEF_SEL( setInterpolation_, "setInterpolation:" );
    //_MDL_PRIVATE_DEF_SEL( keyTimes, "keyTimes" );
    //_MDL_PRIVATE_DEF_SEL( clear, "clear" );
    _MDL_PRIVATE_DEF_SEL( getTimes_maxCount_, "getTimes:maxCount:" );

    //_MDL_PRIVATE_DEF_SEL( elementCount, "elementCount" );
    //_MDL_PRIVATE_DEF_SEL( initWithElementCount_, "initWithElementCount:" );
    _MDL_PRIVATE_DEF_SEL( setFloatArray_count_atTime_, "setFloatArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDoubleArray_count_atTime_, "setDoubleArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( getFloatArray_count_atTime_, "getFloatArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( getDoubleArray_count_atTime_, "getDoubleArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloatArray_count_atTime_count_, "resetWithFloatArray:count:atTime_count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDoubleArray_count_atTime_count_, "resetWithDoubleArray:count:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( getFloatArray_count_, "getFloatArray:count:" );
    _MDL_PRIVATE_DEF_SEL( getDoubleArray_count_, "getDoubleArray:count:" );

    //_MDL_PRIVATE_DEF_SEL( elementCount, "elementCount" );
    //_MDL_PRIVATE_DEF_SEL( initWithElementCount_, "initWithElementCount:" );
    _MDL_PRIVATE_DEF_SEL( setFloat3Array_count_atTime_, "setFloat3Array:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDouble3Array_count_atTime_, "setDouble3Array:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( getFloat3Array_count_atTime_, "getFloat3Array:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( getDouble3Array_count_atTime_, "getDouble3Array:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloat3Array_count_atTime_count_, "resetWithFloat3Array:count:atTime_count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDouble3Array_count_atTime_count_, "resetWithDouble3Array:count:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( getFloat3Array_count_, "getFloat3Array:count:" );
    _MDL_PRIVATE_DEF_SEL( getDouble3Array_count_, "getDouble3Array:count:" );

    //_MDL_PRIVATE_DEF_SEL( elementCount, "elementCount" );
    //_MDL_PRIVATE_DEF_SEL( initWithElementCount_, "initWithElementCount:" );
    _MDL_PRIVATE_DEF_SEL( setFloatQuaternionArray_count_atTime_, "setFloatQuaternionArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDoubleQuaternionArray_count_atTime_, "setDoubleQuaternionArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( getFloatQuaternionArray_count_atTime_, "getFloatQuaternionArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( getDoubleQuaternionArray_count_atTime_, "getDoubleQuaternionArray:count:atTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloatQuaternionArray_count_atTime_count_, "resetWithFloatQuaternionArray:count:atTime_count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDoubleQuaternionArray_count_atTime_count_, "resetWithDoubleQuaternionArray:count:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( getFloatQuaternionArray_count_, "getFloatQuaternionArray:count:" );
    _MDL_PRIVATE_DEF_SEL( getDoubleQuaternionArray_count_, "getDoubleQuaternionArray:count:" );

    _MDL_PRIVATE_DEF_SEL( setFloat_atTime_, "setFloat:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDouble_atTime_, "setDouble:atTime:" );
    _MDL_PRIVATE_DEF_SEL( floatAtTime_, "floatAtTime:" );
    _MDL_PRIVATE_DEF_SEL( doubleAtTime_, "doubleAtTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloatArray_atTime_count_, "resetWithFloatArray:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDoubleArray_atTime_count_, "resetWithDoubleArray:atTime:count:" );

    _MDL_PRIVATE_DEF_SEL( setFloat2_atTime_, "setFloat2:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDouble2_atTime_, "setDouble2:atTime:" );
    _MDL_PRIVATE_DEF_SEL( float2AtTime_, "float2AtTime:" );
    _MDL_PRIVATE_DEF_SEL( double2AtTime_, "double2AtTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloat2Array_atTime_count_, "resetWithFloat2Array:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDouble2Array_atTime_count_, "resetWithDouble2Array:atTime:count:" );

    _MDL_PRIVATE_DEF_SEL( setFloat3_atTime_, "setFloat3:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDouble3_atTime_, "setDouble3:atTime:" );
    _MDL_PRIVATE_DEF_SEL( float3AtTime_, "float3AtTime:" );
    _MDL_PRIVATE_DEF_SEL( double3AtTime_, "double3AtTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloat3Array_atTime_count_, "resetWithFloat3Array:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDouble3Array_atTime_count_, "resetWithDouble3Array:atTime:count:" );

    _MDL_PRIVATE_DEF_SEL( setFloat4_atTime_, "setFloat4:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDouble4_atTime_, "setDouble4:atTime:" );
    _MDL_PRIVATE_DEF_SEL( float4AtTime_, "float4AtTime:" );
    _MDL_PRIVATE_DEF_SEL( double4AtTime_, "double4AtTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloat4Array_atTime_count_, "resetWithFloat4Array:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDouble4Array_atTime_count_, "resetWithDouble4Array:atTime:count:" );

    _MDL_PRIVATE_DEF_SEL( setFloatQuaternion_atTime_, "setFloatQuaternion:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDoubleQuaternion_atTime_, "setDoubleQuaternion:atTime:" );
    _MDL_PRIVATE_DEF_SEL( floatQuaternionAtTime_, "floatQuaternionAtTime:" );
    _MDL_PRIVATE_DEF_SEL( doubleQuaternionAtTime_, "doubleQuaternionAtTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloatQuaternionArray_atTime_count_, "resetWithFloatQuaternionArray:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDoubleQuaternionArray_atTime_count_, "resetWithDoubleQuaternionArray:atTime:count:" );

    _MDL_PRIVATE_DEF_SEL( setFloat4x4_atTime_, "setFloat4x4:atTime:" );
    _MDL_PRIVATE_DEF_SEL( setDouble4x4_atTime_, "setDouble4x4:atTime:" );
    _MDL_PRIVATE_DEF_SEL( float4x4AtTime_, "float4x4AtTime:" );
    _MDL_PRIVATE_DEF_SEL( double4x4AtTime_, "double4x4AtTime:" );
    _MDL_PRIVATE_DEF_SEL( resetWithFloat4x4Array_atTime_count_, "resetWithFloat4x4Array:atTime:count:" );
    _MDL_PRIVATE_DEF_SEL( resetWithDouble4x4Array_atTime_count_, "resetWithDouble4x4Array:atTime:count:" );

} // Selector

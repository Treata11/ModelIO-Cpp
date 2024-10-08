/*
 MDLHeaderBridge.hpp

 Created by Treata Norouzi on 8/16/24.
*/

#pragma once
#include "MDLPrivate.hpp"

// MARK: - Class

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

// MDLAnimation.hpp
    _MDL_PRIVATE_DEF_CLS( MDLSkeleton );
    _MDL_PRIVATE_DEF_CLS( MDLPackedJointAnimation );
    _MDL_PRIVATE_DEF_CLS( MDLAnimationBindComponent );

// MDLTexture.hpp
    _MDL_PRIVATE_DEF_CLS( MDLTexture );
    _MDL_PRIVATE_DEF_CLS( MDLURLTexture );
    _MDL_PRIVATE_DEF_CLS( MDLCheckerboardTexture );
    _MDL_PRIVATE_DEF_CLS( MDLSkyCubeTexture );
    _MDL_PRIVATE_DEF_CLS( MDLColorSwatchTexture );
    _MDL_PRIVATE_DEF_CLS( MDLNoiseTexture );
    _MDL_PRIVATE_DEF_CLS( MDLNormalMapTexture );

// MDLMaterial.hpp
    _MDL_PRIVATE_DEF_CLS( MDLTextureFilter );
    _MDL_PRIVATE_DEF_CLS( MDLTextureSampler );
    _MDL_PRIVATE_DEF_CLS( MDLMaterialProperty );
    _MDL_PRIVATE_DEF_CLS( MDLMaterialPropertyConnection );
    _MDL_PRIVATE_DEF_CLS( MDLMaterialPropertyNode );
    _MDL_PRIVATE_DEF_CLS( MDLMaterialPropertyGraph );
    _MDL_PRIVATE_DEF_CLS( MDLScatteringFunction );
    _MDL_PRIVATE_DEF_CLS( MDLPhysicallyPlausibleScatteringFunction );
    _MDL_PRIVATE_DEF_CLS( MDLMaterial );

// MDLSubmesh.hpp
    _MDL_PRIVATE_DEF_CLS( MDLSubmeshTopology );
    _MDL_PRIVATE_DEF_CLS( MDLSubmesh );

// MDLLight.hpp
    _MDL_PRIVATE_DEF_CLS( MDLLight );
    _MDL_PRIVATE_DEF_CLS( MDLPhysicallyPlausibleLight );
    _MDL_PRIVATE_DEF_CLS( MDLAreaLight );
    _MDL_PRIVATE_DEF_CLS( MDLPhotometricLight );
    _MDL_PRIVATE_DEF_CLS( MDLLightProbe );

// MDLAsset.hpp
    _MDL_PRIVATE_DEF_CLS( MDLAsset );
    // Bogus!
    _MDL_PRIVATE_DEF_CLS( MDLLightProbeIrradianceDataSource );

// MDLMesh.hpp
    _MDL_PRIVATE_DEF_CLS( MDLVertexAttributeData );
    _MDL_PRIVATE_DEF_CLS( MDLMesh );

// MDLTransformStack.hpp
    _MDL_PRIVATE_DEF_CLS( MDLTransformRotateXOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformRotateYOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformRotateZOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformRotateOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformTranslateOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformScaleOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformMatrixOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformOrientOp );
    _MDL_PRIVATE_DEF_CLS( MDLTransformStack );

// MDLCamera.hpp
    _MDL_PRIVATE_DEF_CLS( MDLCamera );
    _MDL_PRIVATE_DEF_CLS( MDLStereoscopicCamera );

} // Class

// MARK: - Protocol

// TODO: Add the remaining Protocols
namespace MDL::Private::Protocol
{
// MDLTypes.hpp
    _MDL_PRIVATE_DEF_PRO(MDLNamed);
    _MDL_PRIVATE_DEF_PRO(MDLComponent);
    _MDL_PRIVATE_DEF_PRO(MDLObjectContainerComponent);

// MDLAsset.hpp
    _MDL_PRIVATE_DEF_PRO(MDLLightProbeIrradianceDataSource);

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

// MDLAnimation.hpp
    _MDL_PRIVATE_DEF_SEL( jointPaths, "jointPaths" );
    _MDL_PRIVATE_DEF_SEL( jointBindTransforms, "jointBindTransforms" );
    _MDL_PRIVATE_DEF_SEL( jointRestTransforms, "jointRestTransforms" );
    _MDL_PRIVATE_DEF_SEL( initWithName_jointPaths_, "initWithName:jointPaths:" );

    //_MDL_PRIVATE_DEF_SEL( jointPaths, "jointPaths" );
    _MDL_PRIVATE_DEF_SEL( translations, "translations" );
    _MDL_PRIVATE_DEF_SEL( rotations, "rotations" );
    _MDL_PRIVATE_DEF_SEL( scales, "scales" );
    //_MDL_PRIVATE_DEF_SEL( initWithName_jointPaths_, "initWithName:jointPaths:" );

    _MDL_PRIVATE_DEF_SEL( skeleton, "skeleton" );
    _MDL_PRIVATE_DEF_SEL( setSkeleton_, "setSkeleton:" );
    _MDL_PRIVATE_DEF_SEL( jointAnimation, "jointAnimation" );
    _MDL_PRIVATE_DEF_SEL( setJointAnimation_, "setJointAnimation:" );
    //_MDL_PRIVATE_DEF_SEL( jointPaths, "jointPaths" );
    _MDL_PRIVATE_DEF_SEL( setJointPaths_, "setJointPaths:" );
    _MDL_PRIVATE_DEF_SEL( geometryBindTransform, "geometryBindTransform" );
    _MDL_PRIVATE_DEF_SEL( setGeometryBindTransform_, "setGeometryBindTransform:" );

// MDLTexture.hpp
    _MDL_PRIVATE_DEF_SEL( textureNamed_, "textureNamed:" );
    _MDL_PRIVATE_DEF_SEL( textureNamed_bundle_, "textureNamed:bundle:" );
    _MDL_PRIVATE_DEF_SEL( textureNamed_assetResolver_, "textureNamed:assetResolver:" );
    _MDL_PRIVATE_DEF_SEL( textureCubeWithImagesNamed_, "textureCubeWithImagesNamed:" );
    _MDL_PRIVATE_DEF_SEL( textureCubeWithImagesNamed_bundle_, "textureCubeWithImagesNamed:bundle:" );
    _MDL_PRIVATE_DEF_SEL( irradianceTextureCubeWithTexture_name_dimensions_, "irradianceTextureCubeWithTexture:name:dimensions:" );
    _MDL_PRIVATE_DEF_SEL( irradianceTextureCubeWithTexture_name_dimensions_roughness_, "irradianceTextureCubeWithTexture:name:dimensions:roughness:" );
    _MDL_PRIVATE_DEF_SEL( initWithData_topLeftOrigin_name_dimensions_rowStride_channelCount_channelEncoding_isCube_,
                         "initWithData:topLeftOrigin:name:dimensions:rowStride:channelCount:channelEncoding:isCube:" );

    _MDL_PRIVATE_DEF_SEL( writeToURL_, "writeToURL:" );
    _MDL_PRIVATE_DEF_SEL( writeToURL_level_, "writeToURL:level:" );
    _MDL_PRIVATE_DEF_SEL( writeToURL_type_, "writeToURL:type:" );
    _MDL_PRIVATE_DEF_SEL( writeToURL_type_level_, "writeToURL:type:level:" );
    _MDL_PRIVATE_DEF_SEL( imageFromTexture, "imageFromTexture" );
    _MDL_PRIVATE_DEF_SEL( imageFromTextureAtLevel_, "imageFromTextureAtLevel:" );
    _MDL_PRIVATE_DEF_SEL( texelDataWithTopLeftOrigin, "texelDataWithTopLeftOrigin" );
    _MDL_PRIVATE_DEF_SEL( texelDataWithBottomLeftOrigin, "texelDataWithBottomLeftOrigin" );
    _MDL_PRIVATE_DEF_SEL( dimensions, "dimensions" );
    _MDL_PRIVATE_DEF_SEL( rowStride, "rowStride" );
    _MDL_PRIVATE_DEF_SEL( channelCount, "channelCount" );
    _MDL_PRIVATE_DEF_SEL( mipLevelCount, "mipLevelCount" );
    _MDL_PRIVATE_DEF_SEL( channelEncoding, "channelEncoding" );
    _MDL_PRIVATE_DEF_SEL( isCube, "isCube" );
    _MDL_PRIVATE_DEF_SEL( setAsCube_, "setAsCube:" );
    _MDL_PRIVATE_DEF_SEL( hasAlphaValues, "hasAlphaValues" );
    _MDL_PRIVATE_DEF_SEL( setAsAlphaValues_, "setAsAlphaValues:" );

    _MDL_PRIVATE_DEF_SEL( initWithURL_name_, "initWithURL:name:" );
    _MDL_PRIVATE_DEF_SEL( URL, "URL" );
    _MDL_PRIVATE_DEF_SEL( setURL_, "setURL:" );

    _MDL_PRIVATE_DEF_SEL( initWithDivisions_name_dimensions_channelCount_channelEncoding_color1_color2_,
                         "initWithDivisions:name:dimensions:channelCount:channelEncoding:color1:color2:" );
    _MDL_PRIVATE_DEF_SEL( divisions, "divisions" );
    _MDL_PRIVATE_DEF_SEL( setDivisions_, "setDivisions:" );
    _MDL_PRIVATE_DEF_SEL( color1, "color1" );
    _MDL_PRIVATE_DEF_SEL( setColor1_, "setColor1:" );
    _MDL_PRIVATE_DEF_SEL( color2, "color2" );
    _MDL_PRIVATE_DEF_SEL( setColor2_, "setColor2:" );

    _MDL_PRIVATE_DEF_SEL( initWithName_channelEncoding_textureDimensions_turbidity_sunElevation_upperAtmosphereScattering_groundAlbedo_,
                         "initWithName:channelEncoding:textureDimensions:turbidity:sunElevation:upperAtmosphereScattering:groundAlbedo:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_channelEncoding_textureDimensions_turbidity_sunElevation_sunAzimuth_upperAtmosphereScattering_groundAlbedo_,
                         "initWithName:channelEncoding:textureDimensions:turbidity:sunElevation:sunAzimuth:upperAtmosphereScattering:groundAlbedo:" );
    _MDL_PRIVATE_DEF_SEL( updateTexture, "updateTexture" );
    _MDL_PRIVATE_DEF_SEL( turbidity, "turbidity" );
    _MDL_PRIVATE_DEF_SEL( setTurbidity_, "setTurbidity:" );
    _MDL_PRIVATE_DEF_SEL( sunElevation, "sunElevation" );
    _MDL_PRIVATE_DEF_SEL( setSunElevation_, "setSunElevation:" );
    _MDL_PRIVATE_DEF_SEL( sunAzimuth, "sunAzimuth" );
    _MDL_PRIVATE_DEF_SEL( setSunAzimuth_, "setSunAzimuth:" );
    _MDL_PRIVATE_DEF_SEL( upperAtmosphereScattering, "upperAtmosphereScattering" );
    _MDL_PRIVATE_DEF_SEL( setUpperAtmosphereScattering_, "setUpperAtmosphereScattering:" );
    _MDL_PRIVATE_DEF_SEL( groundAlbedo, "groundAlbedo" );
    _MDL_PRIVATE_DEF_SEL( setGroundAlbedo_, "setGroundAlbedo:" );
    _MDL_PRIVATE_DEF_SEL( horizonElevation, "horizonElevation" );
    _MDL_PRIVATE_DEF_SEL( setHorizonElevation_, "setHorizonElevation:" );
    _MDL_PRIVATE_DEF_SEL( groundColor, "groundColor" );
    _MDL_PRIVATE_DEF_SEL( setGroundColor_, "setGroundColor:" );
    _MDL_PRIVATE_DEF_SEL( gamma, "gamma" );
    _MDL_PRIVATE_DEF_SEL( setGamma_, "setGamma:" );
    _MDL_PRIVATE_DEF_SEL( exposure, "exposure" );
    _MDL_PRIVATE_DEF_SEL( setExposure_, "setExposure:" );
    _MDL_PRIVATE_DEF_SEL( brightness, "brightness" );
    _MDL_PRIVATE_DEF_SEL( setBrightness_, "setBrightness:" );
    _MDL_PRIVATE_DEF_SEL( contrast, "contrast" );
    _MDL_PRIVATE_DEF_SEL( setContrast_, "setContrast:" );
    _MDL_PRIVATE_DEF_SEL( saturation, "saturation" );
    _MDL_PRIVATE_DEF_SEL( setSaturation_, "setSaturation:" );
    _MDL_PRIVATE_DEF_SEL( highDynamicRangeCompression, "highDynamicRangeCompression" );
    _MDL_PRIVATE_DEF_SEL( setHighDynamicRangeCompression_, "setHighDynamicRangeCompression:" );

    _MDL_PRIVATE_DEF_SEL( initWithColorTemperatureGradientFrom_toColorTemperature_name_textureDimensions_,
                         "initWithColorTemperatureGradientFrom:toColorTemperature:name:textureDimensions:" );
    _MDL_PRIVATE_DEF_SEL( initWithColorGradientFrom_toColor_name_textureDimensions_,
                         "initWithColorGradientFrom:toColor:name:textureDimensions:" );

    _MDL_PRIVATE_DEF_SEL( initVectorNoiseWithSmoothness_name_textureDimensions_channelEncoding_,
                         "initVectorNoiseWithSmoothness:name:textureDimensions:channelEncoding:" );
    _MDL_PRIVATE_DEF_SEL( initScalarNoiseWithSmoothness_name_textureDimensions_channelCount_channelEncoding_grayscale_,
                         "initScalarNoiseWithSmoothness:name:textureDimensions:channelCount:channelEncoding:grayscale:" );
    _MDL_PRIVATE_DEF_SEL( initCellularNoiseWithFrequency_name_textureDimensions_channelEncoding_,
                         "initCellularNoiseWithFrequency:name:textureDimensions:channelEncoding:" );

    _MDL_PRIVATE_DEF_SEL( initByGeneratingNormalMapWithTexture_name_smoothness_contrast_,
                     "initByGeneratingNormalMapWithTexture:name:smoothness:contrast:" );

// MDLMaterial.hpp
    _MDL_PRIVATE_DEF_SEL( sWrapMode, "sWrapMode" );
    _MDL_PRIVATE_DEF_SEL( setSWrapMode_, "setSWrapMode:" );
    _MDL_PRIVATE_DEF_SEL( tWrapMode, "tWrapMode" );
    _MDL_PRIVATE_DEF_SEL( setTWrapMode_, "setTWrapMode:" );
    _MDL_PRIVATE_DEF_SEL( rWrapMode, "rWrapMode" );
    _MDL_PRIVATE_DEF_SEL( setRWrapMode_, "setRWrapMode:" );
    _MDL_PRIVATE_DEF_SEL( minFilter, "minFilter" );
    _MDL_PRIVATE_DEF_SEL( setMinFilter_, "setMinFilter:" );
    _MDL_PRIVATE_DEF_SEL( magFilter, "magFilter" );
    _MDL_PRIVATE_DEF_SEL( setMagFilter_, "setMagFilter:" );
    _MDL_PRIVATE_DEF_SEL( mipFilter, "mipFilter" );
    _MDL_PRIVATE_DEF_SEL( setMipFilter_, "setMipFilter:" );

    _MDL_PRIVATE_DEF_SEL( texture, "texture" );
    _MDL_PRIVATE_DEF_SEL( setTexture_, "setTexture:" );
    _MDL_PRIVATE_DEF_SEL( hardwareFilter, "hardwareFilter" );
    _MDL_PRIVATE_DEF_SEL( setHardwareFilter_, "setHardwareFilter:" );
    //_MDL_PRIVATE_DEF_SEL( transform, "transform" );
    //_MDL_PRIVATE_DEF_SEL( setTransform_, "setTransform:" );

    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_, "initWithName:semantic:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_float2_, "initWithName:semantic:float2:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_float3_, "initWithName:semantic:float3:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_float4_, "initWithName:semantic:float4:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_matrix4x4_, "initWithName:semantic:matrix4x4:" );

    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_URL_, "initWithName:semantic:URL:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_string_, "initWithName:semantic:string:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_textureSampler_, "initWithName:semantic:textureSampler:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_semantic_color_, "initWithName:semantic:color:" );
    _MDL_PRIVATE_DEF_SEL( setProperties_, "setProperties:" );
    _MDL_PRIVATE_DEF_SEL( semantic, "semantic" );
    _MDL_PRIVATE_DEF_SEL( setSemantic_, "setSemantic:" );
    //_MDL_PRIVATE_DEF_SEL( type, "type" );
    _MDL_PRIVATE_DEF_SEL( setType_, "setType:" );
    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( setName_, "setName:" );
    _MDL_PRIVATE_DEF_SEL( stringValue, "stringValue" );
    _MDL_PRIVATE_DEF_SEL( setStringValue_, "setStringValue:" );
    _MDL_PRIVATE_DEF_SEL( URLValue, "URLValue" );
    _MDL_PRIVATE_DEF_SEL( setURLValue_, "setURLValue:" );
    _MDL_PRIVATE_DEF_SEL( textureSamplerValue, "textureSamplerValue" );
    _MDL_PRIVATE_DEF_SEL( setTextureSamplerValue_, "setTextureSamplerValue:" );
    _MDL_PRIVATE_DEF_SEL( color, "color" );
    _MDL_PRIVATE_DEF_SEL( setColor_, "setColor:" );
    _MDL_PRIVATE_DEF_SEL( floatValue, "floatValue" );
    _MDL_PRIVATE_DEF_SEL( setFloatValue_, "setFloatValue:" );
    _MDL_PRIVATE_DEF_SEL( float2Value, "float2Value" );
    _MDL_PRIVATE_DEF_SEL( setFloat2Value_, "setFloat2Value:" );
    _MDL_PRIVATE_DEF_SEL( float3Value, "float3Value" );
    _MDL_PRIVATE_DEF_SEL( setFloat3Value_, "setFloat3Value:" );
    _MDL_PRIVATE_DEF_SEL( float4Value, "float4Value" );
    _MDL_PRIVATE_DEF_SEL( setFloat4Value_, "setFloat4Value:" );
    _MDL_PRIVATE_DEF_SEL( matrix4x4, "matrix4x4" );
    _MDL_PRIVATE_DEF_SEL( setMatrix4x4_, "setMatrix4x4:" );
    _MDL_PRIVATE_DEF_SEL( luminance, "luminance" );
    _MDL_PRIVATE_DEF_SEL( setLuminance_, "setLuminance:" );

    _MDL_PRIVATE_DEF_SEL( initWithOutput_input_, "initWithOutput:input:" );
    _MDL_PRIVATE_DEF_SEL( output, "output" );
    _MDL_PRIVATE_DEF_SEL( input, "input" );

    _MDL_PRIVATE_DEF_SEL( initWithInputs_outputs_evaluationFunction_, "initWithInputs:outputs:evaluationFunction:" );
    _MDL_PRIVATE_DEF_SEL( inputs, "inputs" );
    _MDL_PRIVATE_DEF_SEL( outputs, "outputs" );

    _MDL_PRIVATE_DEF_SEL( initWithNodes_connections_, "initWithNodes:connections:" );
    _MDL_PRIVATE_DEF_SEL( evaluate, "evaluate" );
    _MDL_PRIVATE_DEF_SEL( nodes, "nodes" );
    _MDL_PRIVATE_DEF_SEL( connections, "connections" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( setName_, "setName_" );
    _MDL_PRIVATE_DEF_SEL( baseColor, "baseColor" );
    _MDL_PRIVATE_DEF_SEL( emission, "emission" );
    _MDL_PRIVATE_DEF_SEL( specular, "specular" );
    _MDL_PRIVATE_DEF_SEL( materialIndexOfRefraction, "materialIndexOfRefraction" );
    _MDL_PRIVATE_DEF_SEL( interfaceIndexOfRefraction, "interfaceIndexOfRefraction" );
    _MDL_PRIVATE_DEF_SEL( normal, "normal" );
    _MDL_PRIVATE_DEF_SEL( ambientOcclusion, "ambientOcclusion" );
    _MDL_PRIVATE_DEF_SEL( ambientOcclusionScale, "ambientOcclusionScale" );

    _MDL_PRIVATE_DEF_SEL( version, "version" );
    _MDL_PRIVATE_DEF_SEL( subsurface, "subsurface" );
    _MDL_PRIVATE_DEF_SEL( metallic, "metallic" );
    _MDL_PRIVATE_DEF_SEL( specularAmount, "specularAmount" );
    _MDL_PRIVATE_DEF_SEL( specularTint, "specularTint" );
    _MDL_PRIVATE_DEF_SEL( roughness, "roughness" );
    _MDL_PRIVATE_DEF_SEL( anisotropic, "anisotropic" );
    _MDL_PRIVATE_DEF_SEL( anisotropicRotation, "anisotropicRotation" );
    _MDL_PRIVATE_DEF_SEL( sheen, "sheen" );
    _MDL_PRIVATE_DEF_SEL( sheenTint, "sheenTint" );
    _MDL_PRIVATE_DEF_SEL( clearcoat, "clearcoat" );
    _MDL_PRIVATE_DEF_SEL( clearcoatGloss, "clearcoatGloss" );

    _MDL_PRIVATE_DEF_SEL( initWithName_scatteringFunction_, "initWithName:scatteringFunction:" );
    _MDL_PRIVATE_DEF_SEL( setProperty_, "setProperty:" );
    _MDL_PRIVATE_DEF_SEL( removeProperty_, "removeProperty:" );
    _MDL_PRIVATE_DEF_SEL( propertyNamed_, "propertyNamed:" );
    _MDL_PRIVATE_DEF_SEL( propertyWithSemantic_, "propertyWithSemantic:" );
    _MDL_PRIVATE_DEF_SEL( propertiesWithSemantic_, "propertiesWithSemantic:" );
    _MDL_PRIVATE_DEF_SEL( removeAllProperties, "removeAllProperties" );
    _MDL_PRIVATE_DEF_SEL( resolveTexturesWithResolver_, "resolveTexturesWithResolver:" );
    _MDL_PRIVATE_DEF_SEL( loadTexturesUsingResolver_, "loadTexturesUsingResolver:" );
    _MDL_PRIVATE_DEF_SEL( scatteringFunction, "scatteringFunction" );
    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( setName_, "setName_" );
    _MDL_PRIVATE_DEF_SEL( baseMaterial, "baseMaterial" );
    _MDL_PRIVATE_DEF_SEL( setBaseMaterial_, "setBaseMaterial:" );
    //_MDL_PRIVATE_DEF_SEL( objectAtIndexedSubscript_, "objectAtIndexedSubscript:" );
    //_MDL_PRIVATE_DEF_SEL( objectForKeyedSubscript_, "objectForKeyedSubscript:" );
    //_MDL_PRIVATE_DEF_SEL( count, "count" );
    _MDL_PRIVATE_DEF_SEL( materialFace, "materialFace" );
    _MDL_PRIVATE_DEF_SEL( setMaterialFace_, "setMaterialFace:" );

// MDLSubmesh.hpp
    _MDL_PRIVATE_DEF_SEL( initWithSubmesh_, "initWithSubmesh:" );
    _MDL_PRIVATE_DEF_SEL( faceTopology, "faceTopology" );
    _MDL_PRIVATE_DEF_SEL( setFaceTopology_, "setFaceTopology:" );
    _MDL_PRIVATE_DEF_SEL( faceCount, "faceCount" );
    _MDL_PRIVATE_DEF_SEL( setFaceCount_, "setFaceCount:" );
    _MDL_PRIVATE_DEF_SEL( vertexCreaseIndices, "vertexCreaseIndices" );
    _MDL_PRIVATE_DEF_SEL( setVertexCreaseIndices_, "setVertexCreaseIndices:" );
    _MDL_PRIVATE_DEF_SEL( vertexCreases, "vertexCreases" );
    _MDL_PRIVATE_DEF_SEL( setVertexCreases_, "setVertexCreases:" );
    _MDL_PRIVATE_DEF_SEL( vertexCreaseCount, "vertexCreaseCount" );
    _MDL_PRIVATE_DEF_SEL( setVertexCreaseCount_, "setVertexCreaseCount:" );
    _MDL_PRIVATE_DEF_SEL( holes, "holes" );
    _MDL_PRIVATE_DEF_SEL( setHoles_, "setHoles:" );
    _MDL_PRIVATE_DEF_SEL( holeCount, "holeCount" );
    _MDL_PRIVATE_DEF_SEL( setHoleCount_, "setHoleCount:" );

    _MDL_PRIVATE_DEF_SEL( initWithName_indexBuffer_indexCount_indexType_geometryType_material_,
                         "initWithName:indexBuffer:indexCount:indexType:geometryType:material:" );
    _MDL_PRIVATE_DEF_SEL( initWithIndexBuffer_indexCount_indexType_geometryType_material_,
                         "initWithIndexBuffer:indexCount:indexType:geometryType:material:" );
    _MDL_PRIVATE_DEF_SEL( initWithName_indexBuffer_indexCount_indexType_geometryType_material_topology_,
                         "initWithName:indexBuffer:indexCount:indexType:geometryType:material:topology:" );
    _MDL_PRIVATE_DEF_SEL( initWithMDLSubmesh_indexType_geometryType_,
                         "initWithMDLSubmesh:indexType:geometryType:" );
    _MDL_PRIVATE_DEF_SEL( indexBuffer, "indexBuffer" );
    _MDL_PRIVATE_DEF_SEL( indexBufferAsIndexType_, "indexBufferAsIndexType:" );
    _MDL_PRIVATE_DEF_SEL( indexCount, "indexCount" );
    _MDL_PRIVATE_DEF_SEL( indexType, "indexType" );
    _MDL_PRIVATE_DEF_SEL( geometryType, "geometryType" );
    _MDL_PRIVATE_DEF_SEL( material, "material" );
    _MDL_PRIVATE_DEF_SEL( setMaterial_, "setMaterial:" );
    _MDL_PRIVATE_DEF_SEL( topology, "topology" );
    _MDL_PRIVATE_DEF_SEL( setTopology_, "setTopology:" );
    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( setName_, "setName_" );

//MDLLight.hpp
    _MDL_PRIVATE_DEF_SEL( irradianceAtPoint_, "irradianceAtPoint:" );
    _MDL_PRIVATE_DEF_SEL( irradianceAtPoint_colorSpace_, "irradianceAtPoint:colorSpace:" );
    _MDL_PRIVATE_DEF_SEL( lightType, "lightType" );
    _MDL_PRIVATE_DEF_SEL( setLightType_, "setLightType:" );
    _MDL_PRIVATE_DEF_SEL( colorSpace, "colorSpace" );
    _MDL_PRIVATE_DEF_SEL( setColorSpace_, "setColorSpace:" );

    _MDL_PRIVATE_DEF_SEL( setColorByTemperature_, "setColorByTemperature_" );
    //_MDL_PRIVATE_DEF_SEL( color, "color" );
    //_MDL_PRIVATE_DEF_SEL( setColor_, "setColor:" );
    _MDL_PRIVATE_DEF_SEL( lumens, "lumens" );
    _MDL_PRIVATE_DEF_SEL( setLumens_, "setLumens:" );
    _MDL_PRIVATE_DEF_SEL( innerConeAngle, "innerConeAngle" );
    _MDL_PRIVATE_DEF_SEL( setInnerConeAngle_, "setInnerConeAngle:" );
    _MDL_PRIVATE_DEF_SEL( outerConeAngle, "outerConeAngle" );
    _MDL_PRIVATE_DEF_SEL( setOuterConeAngle_, "setOuterConeAngle:" );
    _MDL_PRIVATE_DEF_SEL( attenuationStartDistance, "attenuationStartDistance" );
    _MDL_PRIVATE_DEF_SEL( setAttenuationStartDistance_, "setAttenuationStartDistance:" );

    _MDL_PRIVATE_DEF_SEL( areaRadius, "areaRadius" );
    _MDL_PRIVATE_DEF_SEL( setAreaRadius_, "setAreaRadius:" );
    _MDL_PRIVATE_DEF_SEL( superEllipticPower, "superEllipticPower" );
    _MDL_PRIVATE_DEF_SEL( setSuperEllipticPower_, "setSuperEllipticPower:" );
    _MDL_PRIVATE_DEF_SEL( aspect, "aspect" );
    _MDL_PRIVATE_DEF_SEL( setAspect_, "setAspect:" );

    _MDL_PRIVATE_DEF_SEL( initWithIESProfile_, "initWithIESProfile:" );
    _MDL_PRIVATE_DEF_SEL( generateSphericalHarmonicsFromLight_, "generateSphericalHarmonicsFromLight:" );
    _MDL_PRIVATE_DEF_SEL( generateCubemapFromLight_, "generateCubemapFromLight:" );
    _MDL_PRIVATE_DEF_SEL( generateTexture_, "generateTexture:" );
    _MDL_PRIVATE_DEF_SEL( lightCubeMap, "lightCubeMap" );
    _MDL_PRIVATE_DEF_SEL( sphericalHarmonicsLevel, "sphericalHarmonicsLevel" );
    _MDL_PRIVATE_DEF_SEL( sphericalHarmonicsCoefficients, "sphericalHarmonicsCoefficients" );

    _MDL_PRIVATE_DEF_SEL( initWithReflectiveTexture_irradianceTexture_, "initWithReflectiveTexture:irradianceTexture:" );
    _MDL_PRIVATE_DEF_SEL( reflectiveTexture, "reflectiveTexture" );
    _MDL_PRIVATE_DEF_SEL( irradianceTexture, "irradianceTexture" );
    //_MDL_PRIVATE_DEF_SEL( sphericalHarmonicsLevel, "sphericalHarmonicsLevel" );
    //_MDL_PRIVATE_DEF_SEL( sphericalHarmonicsCoefficients, "sphericalHarmonicsCoefficients" );
    _MDL_PRIVATE_DEF_SEL( lightProbeWithTextureSize_forLocation_lightsToConsider_objectsToConsider_reflectiveCubemap_irradianceCubemap_,
                         "lightProbeWithTextureSize:forLocation:lightsToConsider:objectsToConsider:reflectiveCubemap:irradianceCubemap:" );

// MDLAsset.hpp
    _MDL_PRIVATE_DEF_SEL( initWithURL_, "initWithURL:" );
    _MDL_PRIVATE_DEF_SEL( initWithURL_vertexDescriptor_bufferAllocator_,
                         "initWithURL:vertexDescriptor:bufferAllocator:" );
    _MDL_PRIVATE_DEF_SEL( initWithBufferAllocator_, "initWithBufferAllocator:" );
    _MDL_PRIVATE_DEF_SEL( initWithURL_vertexDescriptor_bufferAllocator_preserveTopology_error_,
                         "initWithURL:vertexDescriptor:bufferAllocator:preserveTopology:error:" );
    _MDL_PRIVATE_DEF_SEL( exportAssetToURL_, "exportAssetToURL:" );
    _MDL_PRIVATE_DEF_SEL( exportAssetToURL_error_, "exportAssetToURL:error:" );
    //_MDL_PRIVATE_DEF_SEL( objectAtPath_, "objectAtPath:" );
    _MDL_PRIVATE_DEF_SEL( canImportFileExtension_, "canImportFileExtension:" );
    _MDL_PRIVATE_DEF_SEL( canExportFileExtension_, "canExportFileExtension:" );
    _MDL_PRIVATE_DEF_SEL( childObjectsOfClass_, "childObjectsOfClass:" );
    _MDL_PRIVATE_DEF_SEL( loadTextures, "loadTextures" );
    //_MDL_PRIVATE_DEF_SEL( boundingBoxAtTime_, "boundingBoxAtTime:" );
    //_MDL_PRIVATE_DEF_SEL( boundingBox, "boundingBox" );
    _MDL_PRIVATE_DEF_SEL( frameInterval, "frameInterval" );
    _MDL_PRIVATE_DEF_SEL( setFrameInterval_, "setFrameInterval:" );
    _MDL_PRIVATE_DEF_SEL( startTime, "startTime" );
    _MDL_PRIVATE_DEF_SEL( setStartTime_, "setStartTime:" );
    _MDL_PRIVATE_DEF_SEL( endTime, "endTime" );
    _MDL_PRIVATE_DEF_SEL( setEndTime_, "setEndTime:" );
    _MDL_PRIVATE_DEF_SEL( upAxis, "upAxis" );
    _MDL_PRIVATE_DEF_SEL( setUpAxis_, "setUpAxis:" );
    //_MDL_PRIVATE_DEF_SEL( URL, "URL" );
    _MDL_PRIVATE_DEF_SEL( resolver, "resolver" );
    _MDL_PRIVATE_DEF_SEL( setResolver_, "setResolver:" );
    _MDL_PRIVATE_DEF_SEL( bufferAllocator, "bufferAllocator" );
    _MDL_PRIVATE_DEF_SEL( vertexDescriptor, "vertexDescriptor" );
    //_MDL_PRIVATE_DEF_SEL( addObject_, "addObject:" );
    //_MDL_PRIVATE_DEF_SEL( removeObject_, "removeObject:" );
    //_MDL_PRIVATE_DEF_SEL( count, "count" );
    //_MDL_PRIVATE_DEF_SEL( objectAtIndexedSubscript_, "objectAtIndexedSubscript:" );
    _MDL_PRIVATE_DEF_SEL( objectAtIndex_, "objectAtIndex:" );
    _MDL_PRIVATE_DEF_SEL( masters, "masters" );
    _MDL_PRIVATE_DEF_SEL( setMasters_, "setMasters:" );
    _MDL_PRIVATE_DEF_SEL( originals, "originals" );
    _MDL_PRIVATE_DEF_SEL( setOriginals_, "setOriginals:" );
    _MDL_PRIVATE_DEF_SEL( animations, "animations" );
    _MDL_PRIVATE_DEF_SEL( setAnimations_, "setAnimations:" );

    //_MDL_PRIVATE_DEF_SEL( boundingBox, "boundingBox" );
    _MDL_PRIVATE_DEF_SEL( setBoundingBox_, "setBoundingBox:" );
    //_MDL_PRIVATE_DEF_SEL( sphericalHarmonicsLevel, "sphericalHarmonicsLevel" );
    _MDL_PRIVATE_DEF_SEL( setSphericalHarmonicsLevel_, "setSphericalHarmonicsLevel:" );
    _MDL_PRIVATE_DEF_SEL( sphericalHarmonicsCoefficientsAtPosition_, "sphericalHarmonicsCoefficientsAtPosition:" );
    _MDL_PRIVATE_DEF_SEL( placeLightProbesWithDensity_usingIrradianceDataSource_,
                         "placeLightProbesWithDensity_usingIrradianceDataSource_" );

// MDLMesh.hpp
    _MDL_PRIVATE_DEF_SEL( map, "map" );
    _MDL_PRIVATE_DEF_SEL( setMap_, "setMap:" );
    _MDL_PRIVATE_DEF_SEL( dataStart, "dataStart" );
    _MDL_PRIVATE_DEF_SEL( setDataStart_, "setDataStart:" );
    //_MDL_PRIVATE_DEF_SEL( stride, "stride" );
    //_MDL_PRIVATE_DEF_SEL( setStride_, "setStride:" );
    //_MDL_PRIVATE_DEF_SEL( format, "format" );
    //_MDL_PRIVATE_DEF_SEL( setFormat_, "setFormat:" );
    _MDL_PRIVATE_DEF_SEL( bufferSize, "bufferSize" );
    _MDL_PRIVATE_DEF_SEL( setBufferSize_, "setBufferSize:" );

    //_MDL_PRIVATE_DEF_SEL( initWithBufferAllocator_, "initWithBufferAllocator:" );
    _MDL_PRIVATE_DEF_SEL( initWithVertexBuffer_vertexCount_descriptor_submeshes_, "initWithVertexBuffer:vertexCount:descriptor:submeshes:" );
    _MDL_PRIVATE_DEF_SEL( initWithVertexBuffers_vertexCount_descriptor_submeshes_, "initWithVertexBuffers:vertexCount:descriptor:submeshes:" );
    _MDL_PRIVATE_DEF_SEL( vertexAttributeDataForAttributeNamed_, "vertexAttributeDataForAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( vertexAttributeDataForAttributeNamed_asFormat_, "vertexAttributeDataForAttributeNamed:asFormat:" );
    //_MDL_PRIVATE_DEF_SEL( boundingBox, "boundingBox" );
    //_MDL_PRIVATE_DEF_SEL( vertexDescriptor, "vertexDescriptor" );
    _MDL_PRIVATE_DEF_SEL( setVertexDescriptor_, "setVertexDescriptor:" );
    _MDL_PRIVATE_DEF_SEL( vertexCount, "vertexCount" );
    _MDL_PRIVATE_DEF_SEL( setVertexCount_, "setVertexCount:" );
    _MDL_PRIVATE_DEF_SEL( vertexBuffers, "vertexBuffers" );
    _MDL_PRIVATE_DEF_SEL( setVertexBuffers_, "setVertexBuffers:" );
    //_MDL_PRIVATE_DEF_SEL( allocator, "allocator" );

    _MDL_PRIVATE_DEF_SEL( addAttributeWithName_format_, "addAttributeWithName:format:" );
    _MDL_PRIVATE_DEF_SEL( addAttributeWithName_format_type_data_stride_, "addAttributeWithName:format:type:data:stride:" );
    _MDL_PRIVATE_DEF_SEL( addAttributeWithName_format_type_data_stride_time_, "addAttributeWithName:format:type:data:stride:time:" );
    _MDL_PRIVATE_DEF_SEL( addNormalsWithAttributeNamed_creaseThreshold_, "addNormalsWithAttributeNamed:creaseThreshold:" );

    _MDL_PRIVATE_DEF_SEL( addTangentBasisForTextureCoordinateAttributeNamed_tangentAttributeNamed_bitangentAttributeNamed_,
                         "addTangentBasisForTextureCoordinateAttributeNamed:tangentAttributeNamed:bitangentAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( addTangentBasisForTextureCoordinateAttributeNamed_normalAttributeNamed_tangentAttributeNamed_,
                         "addTangentBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( addOrthTanBasisForTextureCoordinateAttributeNamed_normalAttributeNamed_tangentAttributeNamed_,
                         "addOrthTanBasisForTextureCoordinateAttributeNamed:normalAttributeNamed:tangentAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( addUnwrappedTextureCoordinatesForAttributeNamed_, "addUnwrappedTextureCoordinatesForAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( flipTextureCoordinatesInAttributeNamed_, "flipTextureCoordinatesInAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( makeVerticesUnique, "makeVerticesUnique" );
    _MDL_PRIVATE_DEF_SEL( makeVerticesUniqueAndReturnError_, "makeVerticesUniqueAndReturnError:" );
    _MDL_PRIVATE_DEF_SEL( replaceAttributeNamed_, "replaceAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( updateAttributeNamed_, "updateAttributeNamed:" );
    //_MDL_PRIVATE_DEF_SEL( removeAttributeNamed_, "removeAttributeNamed:" );

    _MDL_PRIVATE_DEF_SEL( initBoxWithExtent_segments_inwardNormals_geometryType_allocator_,
                         "initBoxWithExtent:segments:inwardNormals:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initSphereWithExtent_segments_inwardNormals_geometryType_allocator_,
                         "initSphereWithExtent:segments:inwardNormals:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initHemisphereWithExtent_segments_inwardNormals_cap_geometryType_allocator_,
                         "initHemisphereWithExtent:segments:inwardNormals:cap:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initCylinderWithExtent_segments_inwardNormals_topCap_bottomCap_geometryType_allocator_,
                         "initCylinderWithExtent:segments:inwardNormals:topCap:bottomCap:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initCapsuleWithExtent_cylinderSegments_hemisphereSegments_inwardNormals_geometryType_allocator_,
                         "initCapsuleWithExtent:cylinderSegments:hemisphereSegments:inwardNormals:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initConeWithExtent_segments_inwardNormals_geometryType_allocator_,
                         "initConeWithExtent:segments:inwardNormals:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initPlaneWithExtent_segments_geometryType_allocator_,
                         "initPlaneWithExtent:segments:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initIcosahedronWithExtent_segments_geometryType_allocator_,
                         "initIcosahedronWithExtent:segments:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( initMeshBySubdividingMesh_submeshIndex_subdivisionLevels_allocator_,
                         "initMeshBySubdividingMesh:submeshIndex:subdivisionLevels:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newBoxWithDimensions_segments_geometryType_inwardNormals_allocator_,
                         "newBoxWithDimensions:segments:geometryType:inwardNormals:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newEllipsoidWithRadii_radialSegments_verticalSegments_geometryType_inwardNormals_hemisphere_allocator_,
                         "newEllipsoidWithRadii:radialSegments:verticalSegments:geometryType:inwardNormals:hemisphere:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newCylinderWithHeight_radii_radialSegments_verticalSegments_geometryType_inwardNormals_allocator_,
                         "newCylinderWithHeight:radii:radialSegments:verticalSegments:geometryType:inwardNormals:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newCapsuleWithHeight_radii_radialSegments_verticalSegments_hemisphereSegments_geometryType_inwardNormals_allocator_,
                         "newCapsuleWithHeight:radii:radialSegments:verticalSegments:hemisphereSegments:geometryType:inwardNormals:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newEllipticalConeWithHeight_radii_radialSegments_verticalSegments_geometryType_inwardNormals_allocator_,
                         "newEllipticalConeWithHeight:radii:radialSegments:verticalSegments:geometryType:inwardNormals:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newPlaneWithDimensions_segments_geometryType_allocator_,
                         "newPlaneWithDimensions:segments:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newIcosahedronWithRadius_inwardNormals_geometryType_allocator_,
                         "newIcosahedronWithRadius:inwardNormals:geometryType:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newIcosahedronWithRadius_inwardNormals_allocator_,
                         "newIcosahedronWithRadius:inwardNormals:allocator:" );
    _MDL_PRIVATE_DEF_SEL( newSubdividedMesh_submeshIndex_subdivisionLevels_,
                         "newSubdividedMesh:submeshIndex:subdivisionLevels:" );

    _MDL_PRIVATE_DEF_SEL( generateAmbientOcclusionTextureWithSize_raysPerSample_attenuationFactor_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_,
                         "generateAmbientOcclusionTextureWithSize:raysPerSample:attenuationFactor:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:" );
    _MDL_PRIVATE_DEF_SEL( generateAmbientOcclusionTextureWithQuality_attenuationFactor_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_,
                         "generateAmbientOcclusionTextureWithQuality:attenuationFactor:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:" );
    _MDL_PRIVATE_DEF_SEL( generateAmbientOcclusionVertexColorsWithRaysPerSample_attenuationFactor_objectsToConsider_vertexAttributeNamed_,
                         "generateAmbientOcclusionVertexColorsWithRaysPerSample:attenuationFactor:objectsToConsider:vertexAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( generateAmbientOcclusionVertexColorsWithQuality_attenuationFactor_objectsToConsider_vertexAttributeNamed_,
                         "generateAmbientOcclusionVertexColorsWithQuality:attenuationFactor:objectsToConsider:vertexAttributeNamed:" );
    _MDL_PRIVATE_DEF_SEL( generateLightMapTextureWithTextureSize_lightsToConsider_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_,
                         "generateLightMapTextureWithTextureSize:lightsToConsider:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:" );
    _MDL_PRIVATE_DEF_SEL( generateLightMapTextureWithQuality_lightsToConsider_objectsToConsider_vertexAttributeNamed_materialPropertyNamed_,
                         "generateLightMapTextureWithQuality:lightsToConsider:objectsToConsider:vertexAttributeNamed:materialPropertyNamed:" );
    _MDL_PRIVATE_DEF_SEL( generateLightMapVertexColorsWithLightsToConsider_objectsToConsider_vertexAttributeNamed_,
                         "generateLightMapVertexColorsWithLightsToConsider:objectsToConsider:vertexAttributeNamed:" );

// MDLTransformStack.hpp
    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( float4x4AtTime_, "float4x4AtTime:" );
    //_MDL_PRIVATE_DEF_SEL( double4x4AtTime_, "double4x4AtTime:" );
    _MDL_PRIVATE_DEF_SEL( IsInverseOp, "IsInverseOp" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    _MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    //_MDL_PRIVATE_DEF_SEL( name, "name" );
    //_MDL_PRIVATE_DEF_SEL( animatedValue, "animatedValue" );

    _MDL_PRIVATE_DEF_SEL( addTranslateOp_inverse_, "addTranslateOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( addRotateXOp_inverse_, "addRotateXOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( addRotateYOp_inverse_, "addRotateYOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( addRotateZOp_inverse_, "addRotateZOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( addRotateOp_inverse_, "addRotateOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( addScaleOp_inverse_, "addScaleOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( addMatrixOp_inverse_, "addMatrixOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( addOrientOp_inverse_, "addOrientOp:inverse:" );
    _MDL_PRIVATE_DEF_SEL( animatedValueWithName_, "animatedValueWithName:" );
    //_MDL_PRIVATE_DEF_SEL( float4x4AtTime_, "float4x4AtTime:" );
    //_MDL_PRIVATE_DEF_SEL( double4x4AtTime_, "double4x4AtTime:" );
    //_MDL_PRIVATE_DEF_SEL( keyTimes, "keyTimes" );
    _MDL_PRIVATE_DEF_SEL( transformOps, "transformOps" );

// MDLCamera.hpp
    _MDL_PRIVATE_DEF_SEL( projectionMatrix, "projectionMatrix" );
    _MDL_PRIVATE_DEF_SEL( projection, "projection" );
    _MDL_PRIVATE_DEF_SEL( setProjection_, "setProjection:" );
    _MDL_PRIVATE_DEF_SEL( frameBoundingBox_setNearAndFar_, "frameBoundingBox:setNearAndFar:" );
    _MDL_PRIVATE_DEF_SEL( lookAt_, "lookAt:" );
    _MDL_PRIVATE_DEF_SEL( lookAt_from_, "lookAt:from:" );
    _MDL_PRIVATE_DEF_SEL( rayTo_forViewPort_, "rayTo:forViewPort:" );
    _MDL_PRIVATE_DEF_SEL( nearVisibilityDistance, "nearVisibilityDistance" );
    _MDL_PRIVATE_DEF_SEL( setNearVisibilityDistance_, "setNearVisibilityDistance:" );
    _MDL_PRIVATE_DEF_SEL( farVisibilityDistance, "farVisibilityDistance" );
    _MDL_PRIVATE_DEF_SEL( setFarVisibilityDistance_, "setFarVisibilityDistance:" );
    _MDL_PRIVATE_DEF_SEL( worldToMetersConversionScale, "worldToMetersConversionScale" );
    _MDL_PRIVATE_DEF_SEL( setWorldToMetersConversionScale_, "setWorldToMetersConversionScale:" );
    _MDL_PRIVATE_DEF_SEL( barrelDistortion, "barrelDistortion" );
    _MDL_PRIVATE_DEF_SEL( setBarrelDistortion_, "setBarrelDistortion:" );
    _MDL_PRIVATE_DEF_SEL( fisheyeDistortion, "fisheyeDistortion" );
    _MDL_PRIVATE_DEF_SEL( setFisheyeDistortion_, "setFisheyeDistortion:" );
    _MDL_PRIVATE_DEF_SEL( opticalVignetting, "opticalVignetting" );
    _MDL_PRIVATE_DEF_SEL( setOpticalVignetting_, "setOpticalVignetting:" );
    _MDL_PRIVATE_DEF_SEL( chromaticAberration, "chromaticAberration" );
    _MDL_PRIVATE_DEF_SEL( setChromaticAberration_, "setChromaticAberration:" );
    _MDL_PRIVATE_DEF_SEL( focalLength, "focalLength" );
    _MDL_PRIVATE_DEF_SEL( setFocalLength_, "setFocalLength:" );
    _MDL_PRIVATE_DEF_SEL( focusDistance, "focusDistance" );
    _MDL_PRIVATE_DEF_SEL( setFocusDistance_, "setFocusDistance:" );
    _MDL_PRIVATE_DEF_SEL( fieldOfView, "fieldOfView" );
    _MDL_PRIVATE_DEF_SEL( setFieldOfView_, "setFieldOfView:" );
    _MDL_PRIVATE_DEF_SEL( fStop, "fStop" );
    _MDL_PRIVATE_DEF_SEL( setFStop_, "setFStop:" );
    _MDL_PRIVATE_DEF_SEL( apertureBladeCount, "apertureBladeCount" );
    _MDL_PRIVATE_DEF_SEL( setApertureBladeCount_, "setApertureBladeCount:" );
    _MDL_PRIVATE_DEF_SEL( maximumCircleOfConfusion, "maximumCircleOfConfusion" );
    _MDL_PRIVATE_DEF_SEL( setMaximumCircleOfConfusion_, "setMaximumCircleOfConfusion:" );
    _MDL_PRIVATE_DEF_SEL( bokehKernelWithSize_, "bokehKernelWithSize:" );
    _MDL_PRIVATE_DEF_SEL( shutterOpenInterval, "shutterOpenInterval" );
    _MDL_PRIVATE_DEF_SEL( setShutterOpenInterval_, "setShutterOpenInterval:" );
    _MDL_PRIVATE_DEF_SEL( sensorVerticalAperture, "sensorVerticalAperture" );
    _MDL_PRIVATE_DEF_SEL( setSensorVerticalAperture_, "setSensorVerticalAperture:" );
    _MDL_PRIVATE_DEF_SEL( sensorEnlargement, "sensorEnlargement" );
    _MDL_PRIVATE_DEF_SEL( setSensorEnlargement_, "setSensorEnlargement:" );
    _MDL_PRIVATE_DEF_SEL( flash, "flash" );
    _MDL_PRIVATE_DEF_SEL( setFlash_, "setFlash:" );
    _MDL_PRIVATE_DEF_SEL( exposureCompression, "exposureCompression" );
    _MDL_PRIVATE_DEF_SEL( setExposureCompression_, "setExposureCompression:" );
    //_MDL_PRIVATE_DEF_SEL( exposure, "exposure" );
    //_MDL_PRIVATE_DEF_SEL( setExposure_, "setExposure:" );

    _MDL_PRIVATE_DEF_SEL( interPupillaryDistance, "interPupillaryDistance" );
    _MDL_PRIVATE_DEF_SEL( setInterPupillaryDistance_, "setInterPupillaryDistance:" );
    _MDL_PRIVATE_DEF_SEL( leftVergence, "leftVergence" );
    _MDL_PRIVATE_DEF_SEL( setLeftVergence_, "setLeftVergence:" );
    _MDL_PRIVATE_DEF_SEL( rightVergence, "rightVergence" );
    _MDL_PRIVATE_DEF_SEL( setRightVergence_, "setRightVergence:" );
    _MDL_PRIVATE_DEF_SEL( overlap, "overlap" );
    _MDL_PRIVATE_DEF_SEL( setOverlap_, "setOverlap:" );
    _MDL_PRIVATE_DEF_SEL( leftViewMatrix, "leftViewMatrix" );
    _MDL_PRIVATE_DEF_SEL( rightViewMatrix, "rightViewMatrix" );
    _MDL_PRIVATE_DEF_SEL( leftProjectionMatrix, "leftProjectionMatrix" );
    _MDL_PRIVATE_DEF_SEL( rightProjectionMatrix, "rightProjectionMatrix" );

} // Selector


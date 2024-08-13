/*!
 @header MDLTypes.h
 @framework ModelIO
 @abstract A variety of types used in representing 3d assets
 @copyright Copyright © 2015 Apple, Inc. All rights reserved.
 */

//#define MDL_INLINE __attribute__((__always_inline__))
//#define MDL_CONST_INLINE __attribute__((__always_inline__,__const__))

#import "ModelIOExports.hpp"
#include "MDLDefines.hpp"
#include "MDLPrivate.hpp"
//#include "MDLObject.hpp"

#import <Foundation/Foundation.hpp>
#include <simd/simd.h>
#include <math.h>

namespace MDL
{
// TODO: NS_ASSUME_NONNULL_BEGIN
_MDL_ENUM(NS::UInteger, IndexBitDepth) {
    IndexBitDepthInvalid = 0,
    IndexBitDepthUInt8 = 8,
    IndexBitDepthUint8 = 8,
    IndexBitDepthUInt16 = 16,
    IndexBitDepthUint16 = 16,
    IndexBitDepthUInt32 = 32,
    IndexBitDepthUint32 = 32,
};

_MDL_ENUM(NS::Integer, GeometryType) {
    GeometryTypePoints = 0,
    GeometryTypeLines,
    GeometryTypeTriangles,
    GeometryTypeTriangleStrips,
    GeometryTypeQuads,
    GeometryTypeVariableTopology
};

_MDL_ENUM(NS::Integer, ProbePlacement) {
    ProbePlacementUniformGrid = 0,
    ProbePlacementIrradianceDistribution
};

_MDL_ENUM(NS::UInteger, DataPrecision) {
    DataPrecisionUndefined,
    DataPrecisionFloat,
    DataPrecisionDouble
};

// !!!: Uncertain about Copying
class Named : public NS::Copying<Named>
{
public:
    // copy
    NS::String*             name() const;
    void                    setName(const NS::String* name);
};

class Component : public NS::Referencing<Component>
{
};

// TODO: Delete after completion of `MDLObject.hpp`
class Object : public NS::Referencing<MDL::Named>
{
public:
    static class Object*    alloc();

    class Object*           init();
};

// !!!: Uncertain about Referencing
class ObjectContainerComponent : public NS::Referencing<MDL::Component, NS::FastEnumeration>
{
public:
    // addObject:
    void                                    addObject(const MDL::Object* object);
    
    // removeObject:
    void                                    removeObject(const MDL::Object* object);
    
    // objectAtIndexedSubscript:
    class MDL::Object*                      objectAtIndexedSubscript(const NS::UInteger index);
    
    NS::UInteger                            count() const;
    
    NS::Array*                              objects() const;
};


struct MDL_CLASS_EXPORT AxisAlignedBoundingBox
{
    vector_float3 maxBounds;
    vector_float3 minBounds;
};

}

// MARK: - Private Sector

//// static method: alloc
//_MDL_INLINE MDL::Named* MDL::Named::alloc()
//{
//    return NS::Object::alloc<MDL::Named>(_MDL_PRIVATE_PRO(MDLNamed));
//}
//
//// method: init
//_MDL_INLINE MDL::Named* MDL::Named::init()
//{
//    return NS::Object::init<MDL::Named>();
//}

// property: name
_MDL_INLINE NS::String* MDL::Named::name() const
{
                                                        // !!!: Uncertain `name()`
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}
// write method: setStrides:
_MDL_INLINE void MDL::Named::setName(const NS::String* name)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setName_), name);
}

// method: addObject:
_MDL_INLINE void MDL::ObjectContainerComponent::addObject(const MDL::Object* object)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(addObject_), object);
}

// method: addObject:
_MDL_INLINE void MDL::ObjectContainerComponent::removeObject(const MDL::Object* object)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(removeObject_), object);
}

// method: objectAtIndexedSubscript:
_MDL_INLINE MDL::Object* MDL::ObjectContainerComponent::objectAtIndexedSubscript(const NS::UInteger index)
{
    return Object::sendMessage<MDL::Object*>(this, _MDL_PRIVATE_SEL(objectAtIndexedSubscript_), index);
}

// property: count
_MDL_INLINE NS::UInteger MDL::ObjectContainerComponent::count() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(count));
}

// property: count
_MDL_INLINE NS::Array* MDL::ObjectContainerComponent::objects() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(objects));
}


// MARK: - Original Header
// TODO: Delete when done


///* Alembic file format, file extension ABC, UTI public.alembic */
//MDL_EXPORT NSString * __nonnull const kUTTypeAlembic API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0));
//
///* 3d Object file format, file extension OBJ, UTI public.geometry-definition-format */
//MDL_EXPORT NSString * __nonnull const kUTType3dObject API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0));
//
///* Polygon file format, file extension PLY, UTI public.polygon-file-format */
//MDL_EXPORT NSString * __nonnull const kUTTypePolygon API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0));
//
///* Stereolithography file format, file extension STL, UTI public.standard-tesselated-geometry-format */
//MDL_EXPORT NSString * __nonnull const kUTTypeStereolithography API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0));
//
///* Universal Scene Description file format, file extension USDA or USDC, UTI com.pixar.universal-scene-description */
//MDL_EXPORT NSString * __nonnull const kUTTypeUniversalSceneDescription API_AVAILABLE(macos(10.12), ios(10.0), tvos(9.0));
//
///* Universal Scene Description Mobile file format, file extension USDZ, UTI com.pixar.universal-scene-description-mobile */
//MDL_EXPORT NSString * __nonnull const kUTTypeUniversalSceneDescriptionMobile API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0)); 


//NS_ASSUME_NONNULL_BEGIN
//typedef NS_ENUM(NSUInteger, MDLIndexBitDepth)
//{
//    MDLIndexBitDepthInvalid = 0,
//    MDLIndexBitDepthUInt8 = 8,
//    MDLIndexBitDepthUint8 = 8,
//    MDLIndexBitDepthUInt16 = 16,
//    MDLIndexBitDepthUint16 = 16,
//    MDLIndexBitDepthUInt32 = 32,
//    MDLIndexBitDepthUint32 = 32,
//};
//
//typedef NS_ENUM(NSInteger, MDLGeometryType) {
//    MDLGeometryTypePoints = 0,
//    MDLGeometryTypeLines,
//    MDLGeometryTypeTriangles,
//    MDLGeometryTypeTriangleStrips,
//    MDLGeometryTypeQuads,
//    MDLGeometryTypeVariableTopology
//};
//
//typedef NS_ENUM(NSInteger, MDLProbePlacement) {
//    MDLProbePlacementUniformGrid = 0,
//    MDLProbePlacementIrradianceDistribution
//};
//
//typedef NS_ENUM(NSUInteger, MDLDataPrecision) {
//    MDLDataPrecisionUndefined,
//    MDLDataPrecisionFloat,
//    MDLDataPrecisionDouble
//} API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));


//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@protocol MDLNamed
//@required
//@property (nonatomic, copy) NSString *name;
//@end

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@protocol MDLComponent <NSObject>
//@end

//@class MDLObject;
//
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@protocol MDLObjectContainerComponent <MDLComponent, NSFastEnumeration>
//
//- (void)addObject:(MDLObject*)object;
//- (void)removeObject:(MDLObject*)object;
//- (MDLObject *)objectAtIndexedSubscript:(NSUInteger)index API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
//@property (readonly) NSUInteger count API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//
//// returns an array of this object's contained objects, aka children
//@property (nonatomic, readonly, retain) NSArray<MDLObject*> *objects;
//
//@end


//typedef struct MDL_CLASS_EXPORT {
//    vector_float3 maxBounds;
//    vector_float3 minBounds;
//} MDLAxisAlignedBoundingBox;

//NS_ASSUME_NONNULL_END

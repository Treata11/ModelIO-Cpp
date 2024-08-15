/*!
 @header MDLTransform.h
 @framework ModelIO
 @abstract Time sampled transformation of elements in 3d assets
 @copyright Treata Norouzi on 8/14/24.
 */


#include "MDLObject.hpp"
#include "MDLTypes.hpp"
#import "Foundation/Foundation.hpp"
//#include <simd/simd.h>

namespace MDL
{
class TransformComponent : public NS::Copying<TransformComponent, MDL::Component>
{
    // assign
    matrix_float4x4         matrix() const;
    void                    setMatrix(const matrix_float4x4 matrix);
    
    // assign
    BOOL                    resetsTransform() const;
    // Rename maybe?
    void                    setResetsTransform(const BOOL resetsTransform);
    
    // readonly
    NS::TimeInterval        minimumTime() const;
    
    // readonly
    NS::TimeInterval        maximumTime() const;
    
    // readonly
    NS::Array*              keyTimes() const;
    
    // setLocalTransform:forTime:
    void                    setLocalTransform(const matrix_float4x4 transform, const NS::TimeInterval time);
    
    // setLocalTransform:
    void                    setLocalTransform(const matrix_float4x4 transform);
    
    // localTransformAtTime:
    matrix_float4x4         localTransformAtTime(const NS::TimeInterval time);
    
    // globalTransformWithObject:globalTransformWithObject:
    matrix_float4x4         globalTransformWithObject(const MDL::Object* object, const NS::TimeInterval time);
};


class Transform : public NS::Copying<Transform, TransformComponent>
{
    static class Transform*     alloc();
    
    class Transform*            init();
    
    // initWithTransformComponent:
    class Transform*            initWithTransformComponent(const TransformComponent* component);
    
    // initWithTransformComponent:resetsTransform:
    class Transform*            initWithTransformComponent(const TransformComponent* component, const BOOL resetsTransform);
    
    // initWithMatrix:
    class Transform*            initWithMatrix(const matrix_float4x4 matrix);
    
    // initWithMatrix:resetsTransform:
    class Transform*            initWithMatrix(const matrix_float4x4 matrix, const BOOL resetsTransform);
    
    void                        setIdentity();
    
    // translationAtTime:
    vector_float3               translationAtTime(const NS::TimeInterval time);
    
    // rotationAtTime:
    vector_float3               rotationAtTime(const NS::TimeInterval time);
    
    // shearAtTime:
    vector_float3               shearAtTime(const NS::TimeInterval time);
    
    // scaleAtTime:
    vector_float3               scaleAtTime(const NS::TimeInterval time);
    
    // setMatrix:forTime:
    void                        setMatrix(const matrix_float4x4 matrix, const NS::TimeInterval time);
    
    // setTranslation:forTime:
    void                        setTranslation(const vector_float3 translation, const NS::TimeInterval time);
    
    // setRotation:forTime:
    void                        setRotation(const vector_float3 rotation, const NS::TimeInterval time);
    
    // setShear:forTime:
    void                        setShear(const vector_float3 shear, const NS::TimeInterval time);
    
    // setScale:forTime:
    void                        setScale(const vector_float3 scale, const NS::TimeInterval time);
    
    // rotationMatrixAtTime:
    matrix_float4x4             rotationMatrixAtTime(const NS::TimeInterval time);
    
    // Read&Write
    vector_float3               translation() const;
    
    // Read&Write
    vector_float3               rotation() const;
    
    // Read&Write
    vector_float3               shear() const;
    
    // Read&Write
    vector_float3               scale() const;
};

}


// MARK: - Original Header

//#import <ModelIO/MDLObject.h>
//#import <ModelIO/MDLTypes.h>
//#import <Foundation/Foundation.h>
//#include <simd/simd.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//@class MDLObject;

/** MDLTransformComponent
    @summary a container for a time sampled local transformation
 
    @discussion Accessors to get the local transform and the global transform
    for a particular MDLObject are provided.
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@protocol MDLTransformComponent <MDLComponent>
//@required
//
///** The matrix, at minimumTime */
//@property (nonatomic, assign) matrix_float4x4 matrix;

/** if YES, this transform is intended to be in global space, not parent space */
//@property (nonatomic, assign) BOOL resetsTransform;
//
///** If no animation data is present, minimumTime and maximumTime will be zero */
//@property (nonatomic, readonly) NSTimeInterval minimumTime;
//@property (nonatomic, readonly) NSTimeInterval maximumTime;

/** An array of sample times for which a key has been stored
    If no animation data is present, the array will contain a single value of zero */
//@property (nonatomic, readonly, copy) NSArray<NSNumber*> *keyTimes;
//
//@optional
//- (void)setLocalTransform:(matrix_float4x4)transform forTime:(NSTimeInterval)time;
//
///**
// Resets any timing information, and makes transform valid at all times
// */
//- (void)setLocalTransform:(matrix_float4x4)transform;


/** Returns the transform governing this transformable at the specified time
    in the transformable's parent's space.
    If non-animated, all frame values will return the same result.
 */
//- (matrix_float4x4)localTransformAtTime:(NSTimeInterval)time;
//
///** Returns the transform governing this transformable at the specified frame in
//    world space. If there is no parent, identity will be returned
// */
//+ (matrix_float4x4)globalTransformWithObject:(MDLObject *)object atTime:(NSTimeInterval)time;
//
//@end

/**
 Concrete implementation of <MDLTransformComponent>.
 For more complex transform components create a class that conforms to
 <MDLTransformComponent>.
 
 @discussion Setting any of scale, translation, or rotation individually will
 set the matrix property, and clear any timing information.
 
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLTransform : NSObject <NSCopying, MDLTransformComponent>
///*!
// @method init
// @discussion Initialize an MDLTransform's matrices with identity
// */
//- (instancetype)init NS_DESIGNATED_INITIALIZER;
//- (instancetype)initWithIdentity API_DEPRECATED_WITH_REPLACEMENT("init", macos(10.11, 10.13), ios(9.0, 11.0), tvos(9.0, 11.0));
//- (instancetype)initWithTransformComponent:(id<MDLTransformComponent>)component;
//- (instancetype)initWithTransformComponent:(id<MDLTransformComponent>)component resetsTransform:(BOOL)resetsTransform;

/**
 Initialization with a matrix assumes the matrix is an invertible, homogeneous
 affine transform matrix. Retrieving transform components after initialization
 with a non-affine matrix will yield those of the identity transform.
 */
//- (instancetype)initWithMatrix:(matrix_float4x4)matrix;
//- (instancetype)initWithMatrix:(matrix_float4x4)matrix resetsTransform:(BOOL)resetsTransform;

/**
 Set all transform components to identity
 */
//- (void)setIdentity;
//
//- (vector_float3)translationAtTime:(NSTimeInterval)time;
//- (vector_float3)rotationAtTime:(NSTimeInterval)time;
//- (vector_float3)shearAtTime:(NSTimeInterval)time;
//- (vector_float3)scaleAtTime:(NSTimeInterval)time;

//- (void)setMatrix:(matrix_float4x4)matrix forTime:(NSTimeInterval)time API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0));
//- (void)setTranslation:(vector_float3)translation forTime:(NSTimeInterval)time;
//- (void)setRotation:(vector_float3)rotation forTime:(NSTimeInterval)time;
//- (void)setShear:(vector_float3)shear forTime:(NSTimeInterval)time;
//- (void)setScale:(vector_float3)scale forTime:(NSTimeInterval)time;

/**
 Construct a right handed rotation matrix at the specified time
 */
//- (matrix_float4x4)rotationMatrixAtTime:(NSTimeInterval)time;
//
///**
// If these properties are read and animation data exists the earliest value is returned.
// Otherwise, if there is no animation data, the value of the property is the same at all times and that value is returned.
// If written, timing information for said property is removed. To retain or add timing information, use the set:forTime selectors instead.
// */
//@property (nonatomic, readwrite) vector_float3 translation;
//@property (nonatomic, readwrite) vector_float3 rotation;     // Euler XYZ radians
//@property (nonatomic, readwrite) vector_float3 shear;
//@property (nonatomic, readwrite) vector_float3 scale;
//
//@end
//
//NS_ASSUME_NONNULL_END


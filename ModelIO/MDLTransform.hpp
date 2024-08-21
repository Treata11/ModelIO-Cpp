/*!
 @header MDLTransform.hpp
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
// Protocol
class TransformComponent : public NS::Copying<TransformComponent, MDL::Component>
{
public:
    // assign
    matrix_float4x4         matrix() const;
    void                    setMatrix(matrix_float4x4 matrix);
    
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
    void                    setLocalTransform(matrix_float4x4 transform, NS::TimeInterval time);
    
    // setLocalTransform:
    void                    setLocalTransform(matrix_float4x4 transform);
    
    // localTransformAtTime:
    matrix_float4x4         localTransformAtTime(NS::TimeInterval time);
    
    // globalTransformWithObject:atTime:
    matrix_float4x4         globalTransformWithObject(const MDL::Object* object, NS::TimeInterval time);
};


class Transform : public NS::Copying<Transform, TransformComponent>
{
public:
    static class Transform*     alloc();
    
    class Transform*            init();
    
    // initWithTransformComponent:
    class Transform*            init(const TransformComponent* component);
    
    // initWithTransformComponent:resetsTransform:
    class Transform*            init(const TransformComponent* component, BOOL resetsTransform);
    
    // initWithMatrix:
    class Transform*            init(matrix_float4x4 matrix);
    
    // initWithMatrix:resetsTransform:
    class Transform*            init(matrix_float4x4 matrix, BOOL resetsTransform);
    
    void                        setIdentity();
    
    // translationAtTime:
    vector_float3               translationAtTime(NS::TimeInterval time);
    
    // rotationAtTime:
    vector_float3               rotationAtTime(NS::TimeInterval time);
    
    // shearAtTime:
    vector_float3               shearAtTime(NS::TimeInterval time);
    
    // scaleAtTime:
    vector_float3               scaleAtTime(NS::TimeInterval time);
    
    // setMatrix:forTime:
    void                        setMatrix(matrix_float4x4 matrix, NS::TimeInterval time);
    
    // setTranslation:forTime:
    void                        setTranslation(vector_float3 translation, NS::TimeInterval time);
    
    // setRotation:forTime:
    void                        setRotation(vector_float3 rotation, NS::TimeInterval time);
    
    // setShear:forTime:
    void                        setShear(vector_float3 shear, NS::TimeInterval time);
    
    // setScale:forTime:
    void                        setScale(vector_float3 scale, NS::TimeInterval time);
    
    // rotationMatrixAtTime:
    matrix_float4x4             rotationMatrixAtTime(NS::TimeInterval time);
    
    // Read&Write
    vector_float3               translation() const;
    void                        setTranslation(vector_float3 translation);
    
    // Read&Write
    vector_float3               rotation() const;
    void                        setRotation(vector_float3 rotation);
    
    // Read&Write
    vector_float3               shear() const;
    void                        setShear(vector_float3 shear);
    
    // Read&Write
    vector_float3               scale() const;
    void                        setScale(vector_float3 scale);
};

}

// MARK: - Private Sector

// MARK: Protocol TransformComponent

// property: matrix
_MDL_INLINE matrix_float4x4 MDL::TransformComponent::matrix() const
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(matrix));
}
// write method: setMatrix:
_MDL_INLINE void MDL::TransformComponent::setMatrix(matrix_float4x4 matrix)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMatrix_), matrix);
}

// property: resetsTransform
_MDL_INLINE BOOL MDL::TransformComponent::resetsTransform() const
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(resetsTransform));
}
// write method: setResetsTransform:
_MDL_INLINE void MDL::TransformComponent::setResetsTransform(BOOL resetsTransform)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setResetsTransform_), resetsTransform);
}

// property: minimumTime
_MDL_INLINE NS::TimeInterval MDL::TransformComponent::minimumTime() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(minimumTime));
}

// property: maximumTime
_MDL_INLINE NS::TimeInterval MDL::TransformComponent::maximumTime() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(maximumTime));
}

// property: keyTimes
_MDL_INLINE NS::Array* MDL::TransformComponent::keyTimes() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(keyTimes));
}

// method: setLocalTransform:forTime:
_MDL_INLINE void MDL::TransformComponent::setLocalTransform(matrix_float4x4 transform, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setLocalTransform_forTime_), transform, time);
}

// method: setLocalTransform:
_MDL_INLINE void MDL::TransformComponent::setLocalTransform(matrix_float4x4 transform)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setLocalTransform_), transform);
}

// method: localTransformAtTime:
_MDL_INLINE matrix_float4x4 MDL::TransformComponent::localTransformAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(localTransformAtTime_), time);
}

// method: globalTransformWithObject:atTime:
_MDL_INLINE matrix_float4x4 MDL::TransformComponent::globalTransformWithObject(const MDL::Object* object, NS::TimeInterval time)
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(globalTransformWithObject_atTime_), time);
}

// MARK: class Transform

// static method: alloc
_MDL_INLINE MDL::Transform* MDL::Transform::alloc()
{
    return NS::Object::alloc<MDL::Transform>(_MDL_PRIVATE_CLS(MDLTransform));
}

// method: init
_MDL_INLINE MDL::Transform* MDL::Transform::init()
{
    return NS::Object::init<MDL::Transform>();
}

// method: initWithTransformComponent:
_MDL_INLINE MDL::Transform* MDL::Transform::init(const TransformComponent* component)
{
    return Object::sendMessage<MDL::Transform*>(this, _MDL_PRIVATE_SEL(initWithTransformComponent_), component);
}

// method: initWithTransformComponent:resetsTransform:
_MDL_INLINE MDL::Transform* MDL::Transform::init(const TransformComponent* component, BOOL resetsTransform)
{
    return Object::sendMessage<MDL::Transform*>(this, _MDL_PRIVATE_SEL(initWithTransformComponent_resetsTransform_), component, resetsTransform);
}

// method: initWithMatrix:
_MDL_INLINE MDL::Transform* MDL::Transform::init(matrix_float4x4 matrix)
{
    return Object::sendMessage<MDL::Transform*>(this, _MDL_PRIVATE_SEL(initWithMatrix_), matrix);
}

// method: initWithMatrix:resetsTransform:
_MDL_INLINE MDL::Transform* MDL::Transform::init(matrix_float4x4 matrix, BOOL resetsTransform)
{
    return Object::sendMessage<MDL::Transform*>(this, _MDL_PRIVATE_SEL(initWithMatrix_resetsTransform_), matrix, resetsTransform);
}

// method: setIdentity
_MDL_INLINE void MDL::Transform::setIdentity()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setIdentity));
}

// method: translationAtTime:
_MDL_INLINE vector_float3 MDL::Transform::translationAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(translationAtTime_), time);
}

// method: rotationAtTime:
_MDL_INLINE vector_float3 MDL::Transform::rotationAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(rotationAtTime_), time);
}

// method: shearAtTime:
_MDL_INLINE vector_float3 MDL::Transform::shearAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(shearAtTime_), time);
}

// method: scaleAtTime:
_MDL_INLINE vector_float3 MDL::Transform::scaleAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(scaleAtTime_), time);
}

// method: setMatrix:forTime:
_MDL_INLINE void MDL::Transform::setMatrix(matrix_float4x4 matrix, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setMatrix_forTime_), matrix, time);
}

// method: setTranslation:forTime:
_MDL_INLINE void MDL::Transform::setTranslation(vector_float3 translation, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTranslation_forTime_), translation, time);
}

// method: setRotation:forTime:
_MDL_INLINE void MDL::Transform::setRotation(vector_float3 rotation, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setRotation_forTime_), rotation, time);
}

// method: setShear:forTime:
_MDL_INLINE void MDL::Transform::setShear(vector_float3 shear, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setShear_forTime_), shear, time);
}

// method: setScale:forTime:
_MDL_INLINE void MDL::Transform::setScale(vector_float3 scale, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setScale_forTime_), scale, time);
}

// method: rotationMatrixAtTime:
_MDL_INLINE matrix_float4x4 MDL::Transform::rotationMatrixAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(rotationMatrixAtTime_), time);
}

// property: translation
_MDL_INLINE vector_float3 MDL::Transform::translation() const
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(translation));
}
// write method: setTranslation:
_MDL_INLINE void MDL::Transform::setTranslation(vector_float3 translation)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTranslation_), translation);
}

// property: rotation
_MDL_INLINE vector_float3 MDL::Transform::rotation() const
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(rotation));
}
// write method: setRotation:
_MDL_INLINE void MDL::Transform::setRotation(vector_float3 rotation)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setRotation_), rotation);
}

// property: shear
_MDL_INLINE vector_float3 MDL::Transform::shear() const
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(shear));
}
// write method: setShear:
_MDL_INLINE void MDL::Transform::setShear(vector_float3 shear)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setShear_), shear);
}

// property: scale
_MDL_INLINE vector_float3 MDL::Transform::scale() const
{
    return Object::sendMessage<vector_float3>(this, _MDL_PRIVATE_SEL(scale));
}
// write method: setScale:
_MDL_INLINE void MDL::Transform::setScale(vector_float3 scale)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setScale_), scale);
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


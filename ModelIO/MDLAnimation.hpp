/*!
 @header MDLAnimation.hpp
 @framework ModelIO
 @abstract Support for time sampled animation of skeletal meshes
 @copyright Treata Norouzi on 8/16/24.
 */


#include "Foundation/Foundation.hpp"
#include "MDLValueTypes.hpp"
#include "MDLAnimatedValueTypes.hpp"
#include "MDLObject.hpp"

namespace MDL
{
                // !!!: Uncertain
class Skeleton : public NS::Copying<MDL::Object>
{
public:
    static class Skeleton*      alloc();
    
    NS::Array*                  jointPaths() const;
    
    Matrix4x4Array*             jointBindTransforms() const;
    
    Matrix4x4Array*             jointRestTransforms() const;
    
    // initWithName:jointPaths:
    class Skeleton*             init(const NS::String* name, const NS::Array* jointPaths);
};

// Protocol
class JointAnimation {};
                                // !!!: Uncertain
class PackedJointAnimation : public NS::Copying<MDL::JointAnimation>
{
public:
    static class PackedJointAnimation*      alloc();
    
    NS::Array*                              jointPaths() const;
    
    AnimatedVector3Array*                   translations() const;
    
    AnimatedQuaternionArray*                rotations() const;
    
    AnimatedVector3Array*                   scales() const;
    
    // initWithName:jointPaths:
    class PackedJointAnimation*             init(const NS::String* name, const NS::Array* jointPaths);
};

                                // !!!: Uncertain
class AnimationBindComponent : public NS::Copying<MDL::Component>
{
public:
    static class AnimationBindComponent*    alloc();
    
    // !!!: Uncertain about the init
    class AnimationBindComponent*           init();
    
    Skeleton*                               skeleton() const;
    void                                    setSkeleton(const Skeleton* skeleton);
    
    class JointAnimation*                   jointAnimation() const;
    void                                    setJointAnimation(const JointAnimation* jointAnimation);
    
    NS::Array*                              jointPaths() const;
    void                                    setJointPaths(const NS::Array* jointPaths);
    
    matrix_double4x4                        geometryBindTransform() const;
    void                                    setGeometryBindTransform(matrix_double4x4 geometryBindTransform);
};

}

// MARK: - Private Sector

// static method: alloc
_MDL_INLINE MDL::Skeleton* MDL::Skeleton::alloc()
{
    return NS::Object::alloc<MDL::Skeleton>(_MDL_PRIVATE_CLS(MDLSkeleton));
}

// property: jointPaths
_MDL_INLINE NS::Array* MDL::Skeleton::jointPaths() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(jointPaths));
}

// property: jointBindTransforms
_MDL_INLINE MDL::Matrix4x4Array* MDL::Skeleton::jointBindTransforms() const
{
    return Object::sendMessage<Matrix4x4Array*>(this, _MDL_PRIVATE_SEL(jointBindTransforms));
}

// property: jointRestTransforms
_MDL_INLINE MDL::Matrix4x4Array* MDL::Skeleton::jointRestTransforms() const
{
    return Object::sendMessage<Matrix4x4Array*>(this, _MDL_PRIVATE_SEL(jointRestTransforms));
}

// method: initWithName:jointPaths:
_MDL_INLINE MDL::Skeleton* MDL::Skeleton::init(const NS::String* name, const NS::Array* jointPaths)
{
    return Object::sendMessage<MDL::Skeleton*>(this, _MDL_PRIVATE_SEL(initWithName_jointPaths_), name, jointPaths);
}

// MARK: Class PackedJointAnimation

// static method: alloc
_MDL_INLINE MDL::PackedJointAnimation* MDL::PackedJointAnimation::alloc()
{
    return NS::Object::alloc<MDL::PackedJointAnimation>(_MDL_PRIVATE_CLS(MDLPackedJointAnimation));
}

// property: jointPaths
_MDL_INLINE NS::Array* MDL::PackedJointAnimation::jointPaths() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(jointPaths));
}

// property: translations
_MDL_INLINE MDL::AnimatedVector3Array* MDL::PackedJointAnimation::translations() const
{
    return Object::sendMessage<AnimatedVector3Array*>(this, _MDL_PRIVATE_SEL(translations));
}

// property: rotations
_MDL_INLINE MDL::AnimatedQuaternionArray* MDL::PackedJointAnimation::rotations() const
{
    return Object::sendMessage<AnimatedQuaternionArray*>(this, _MDL_PRIVATE_SEL(rotations));
}

// property: scales
_MDL_INLINE MDL::AnimatedVector3Array* MDL::PackedJointAnimation::scales() const
{
    return Object::sendMessage<AnimatedVector3Array*>(this, _MDL_PRIVATE_SEL(scales));
}

// method: initWithName:jointPaths:
_MDL_INLINE MDL::PackedJointAnimation* MDL::PackedJointAnimation::init(const NS::String* name, const NS::Array* jointPaths)
{
    return Object::sendMessage<MDL::PackedJointAnimation*>(this, _MDL_PRIVATE_SEL(initWithName_jointPaths_), name, jointPaths);
}

// MARK: Class AnimationBindComponent

// static method: alloc
_MDL_INLINE MDL::AnimationBindComponent* MDL::AnimationBindComponent::alloc()
{
    return NS::Object::alloc<MDL::AnimationBindComponent>(_MDL_PRIVATE_CLS(MDLAnimationBindComponent));
}

_MDL_INLINE MDL::AnimationBindComponent* MDL::AnimationBindComponent::init()
{
    return NS::Object::init<MDL::AnimationBindComponent>();
}

// property: skeleton
_MDL_INLINE MDL::Skeleton* MDL::AnimationBindComponent::skeleton() const
{
    return Object::sendMessage<Skeleton*>(this, _MDL_PRIVATE_SEL(skeleton));
}
// write method: setSkeleton:
_MDL_INLINE void MDL::AnimationBindComponent::setSkeleton(const Skeleton* skeleton)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setSkeleton_), skeleton);
}

// property: jointAnimation
_MDL_INLINE MDL::JointAnimation* MDL::AnimationBindComponent::jointAnimation() const
{
    return Object::sendMessage<JointAnimation*>(this, _MDL_PRIVATE_SEL(jointAnimation));
}
// write method: setJointAnimation:
_MDL_INLINE void MDL::AnimationBindComponent::setJointAnimation(const JointAnimation* jointAnimation)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setJointAnimation_), jointAnimation);
}

// property: jointPaths
_MDL_INLINE NS::Array* MDL::AnimationBindComponent::jointPaths() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(jointPaths));
}
// write method: setJointPaths:
_MDL_INLINE void MDL::AnimationBindComponent::setJointPaths(const NS::Array* jointPaths)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setJointPaths_), jointPaths);
}

// property: geometryBindTransform
_MDL_INLINE matrix_double4x4 MDL::AnimationBindComponent::geometryBindTransform() const
{
    return Object::sendMessage<matrix_double4x4>(this, _MDL_PRIVATE_SEL(geometryBindTransform));
}
// write method: setGeometryBindTransform:
_MDL_INLINE void MDL::AnimationBindComponent::setGeometryBindTransform(matrix_double4x4 geometryBindTransform)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setGeometryBindTransform_), geometryBindTransform);
}


// MARK: - Original Header


//#import <Foundation/Foundation.h>
//#import <ModelIO/MDLValueTypes.h>
//#import <ModelIO/MDLAnimatedValueTypes.h>
//#import <ModelIO/MDLObject.h>
//
//NS_ASSUME_NONNULL_BEGIN

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLSkeleton : MDLObject<NSCopying>
//
//@property (nonatomic, readonly) NSArray<NSString *> *jointPaths;
//
// // world space bind transforms
//@property (nonatomic, readonly) MDLMatrix4x4Array *jointBindTransforms;
//
// // local space default transforms, used for joints not animated in a MDLPackedJointAnimation
//@property (nonatomic, readonly) MDLMatrix4x4Array *jointRestTransforms;

//-(instancetype) initWithName:(NSString *)name
//                  jointPaths:(NSArray<NSString *> *)jointPaths;
//@end

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@protocol MDLJointAnimation
//@end
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLPackedJointAnimation : MDLObject<NSCopying, MDLJointAnimation>
//@property (nonatomic, readonly) NSArray<NSString *> *jointPaths;
//
//@property (nonatomic, readonly) MDLAnimatedVector3Array *translations;
//@property (nonatomic, readonly) MDLAnimatedQuaternionArray *rotations;
//@property (nonatomic, readonly) MDLAnimatedVector3Array *scales;
//
//-(instancetype) initWithName:(NSString *)name
//                  jointPaths:(NSArray<NSString *> *)jointPaths;
//@end

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimationBindComponent : NSObject<NSCopying, MDLComponent>
//
//@property (nonatomic, nullable, retain) MDLSkeleton* skeleton;
//@property (nonatomic, nullable, retain) id<MDLJointAnimation> jointAnimation;
//
// // optional. If set, jointIndices vertex buffers index into this list of joints.
//@property (nonatomic, nullable, retain) NSArray<NSString *> *jointPaths;
//
//@property (nonatomic) matrix_double4x4 geometryBindTransform;
//@end
//
//
//NS_ASSUME_NONNULL_END


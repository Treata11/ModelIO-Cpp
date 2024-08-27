/*!
 @header MDLTransformStack.hpp
 @framework ModelIO
 @abstract Time sampled transformation of elements in 3d assets
 @copyright Treata Norouzi on 8/19/24.
 */


#import "Foundation/Foundation.hpp"
#import <simd/simd.h>
#import "MDLTypes.hpp"
#import "MDLTransform.hpp"
#import "MDLAnimatedValueTypes.hpp"

namespace MDL
{
_MDL_ENUM(NS::UInteger, TransformOpRotationOrder) {
    TransformOpRotationOrderXYZ = 1,
    TransformOpRotationOrderXZY,
    TransformOpRotationOrderYXZ,
    TransformOpRotationOrderYZX,
    TransformOpRotationOrderZXY,
    TransformOpRotationOrderZYX,
};

// Protocol
class TransformOp : public NS::Referencing<TransformOp>
{
public:
    NS::String*         name() const;
    
    // float4x4AtTime:
    matrix_float4x4     float4x4AtTime(NS::TimeInterval time);
    
    // double4x4AtTime:
    matrix_double4x4    double4x4AtTime(NS::TimeInterval time);
    
    bool                IsInverseOp();
};

class TransformRotateXOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformRotateXOp*    alloc();
    
    class TransformRotateXOp*           init();
    
    NS::String*                         name() const;
    
    AnimatedScalar*                     animatedValue() const;
};

class TransformRotateYOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformRotateYOp*    alloc();
    
    class TransformRotateYOp*           init();
    
    NS::String*                         name() const;
    
    AnimatedScalar*                     animatedValue() const;
};

class TransformRotateZOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformRotateZOp*    alloc();
    
    class TransformRotateZOp*           init();
    
    NS::String*                         name() const;
    
    AnimatedScalar*                     animatedValue() const;
};

class TransformRotateOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformRotateOp*     alloc();
    
    class TransformRotateOp*            init();
    
    NS::String*                         name() const;
    
    AnimatedVector3*                    animatedValue() const;
};

class TransformTranslateOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformTranslateOp*  alloc();
    
    class TransformTranslateOp*         init();
    
    NS::String*                         name() const;
    
    AnimatedVector3*                    animatedValue() const;
};

class TransformScaleOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformScaleOp*      alloc();
    
    class TransformScaleOp*             init();
    
    NS::String*                         name() const;
    
    AnimatedVector3*                    animatedValue() const;
};

class TransformMatrixOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformMatrixOp*     alloc();
    
    class TransformMatrixOp*            init();
    
    NS::String*                         name() const;
    
    AnimatedMatrix4x4*                  animatedValue() const;
};

class TransformOrientOp : public NS::Referencing<MDL::TransformOp>
{
public:
    static class TransformOrientOp*     alloc();
    
    class TransformOrientOp*            init();
    
    NS::String*                         name() const;
    
    AnimatedQuaternion*                 animatedValue() const;
};

class TransformStack : public NS::Copying<MDL::TransformComponent>
{
public:
    static class TransformStack*        alloc();
    
    class TransformStack*               init();

    // addTranslateOp:inverse:
    TransformTranslateOp*               addTranslateOp(const NS::String* animatedValueName,
                                                       bool inverse);
    
    // addRotateXOp:inverse:
    TransformRotateXOp*                 addRotateXOp(const NS::String* animatedValueName,
                                                     bool inverse);
    
    // addRotateYOp:inverse:
    TransformRotateYOp*                 addRotateYOp(const NS::String* animatedValueName,
                                                     bool inverse);
    
    // addRotateZOp:inverse:
    TransformRotateZOp*                 addRotateZOp(const NS::String* animatedValueName,
                                                     bool inverse);
    
    // addRotateOp:order:inverse:
    TransformRotateOp*                  addRotateOp(const NS::String* animatedValueName,
                                                    TransformOpRotationOrder order,
                                                    bool inverse);
    
    // addScaleOp:inverse:
    TransformScaleOp*                   addScaleOp(const NS::String* animatedValueName,
                                                   bool inverse);
        
    // addMatrixOp:inverse:
    TransformMatrixOp*                  addMatrixOp(const NS::String* animatedValueName,
                                                    bool inverse);
    
    // addOrientOp:inverse:
    TransformOrientOp*                  addOrientOp(const NS::String* animatedValueName,
                                                    bool inverse);
    
    // animatedValueWithName:
    AnimatedValue*                      animatedValueWithName(const NS::String* name);
    
    // float4x4AtTime:
    matrix_float4x4                     float4x4AtTime(NS::TimeInterval time);
    
    // double4x4AtTime:
    matrix_double4x4                    double4x4AtTime(NS::TimeInterval time);
    
    NS::Array*                          keyTimes() const;
    
    NS::Array*                          transformOps() const;
};

}

// MARK: - Private Sector 

// property: name
_MDL_INLINE NS::String* MDL::TransformOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// method: float4x4AtTime:
_MDL_INLINE matrix_float4x4 MDL::TransformOp::float4x4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(float4x4AtTime_), time);
}

// method: double4x4AtTime:
_MDL_INLINE matrix_double4x4 MDL::TransformOp::double4x4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_double4x4>(this, _MDL_PRIVATE_SEL(double4x4AtTime_), time);
}

// method: IsInverseOp
_MDL_INLINE bool MDL::TransformOp::IsInverseOp()
{
    return Object::sendMessage<bool>(this, _MDL_PRIVATE_SEL(IsInverseOp));
}

// MARK: Class TransformRotateXOp

// static method: alloc
_MDL_INLINE MDL::TransformRotateXOp* MDL::TransformRotateXOp::alloc()
{
    return NS::Object::alloc<MDL::TransformRotateXOp>(_MDL_PRIVATE_CLS(MDLTransformRotateXOp));
}

// method: init
_MDL_INLINE MDL::TransformRotateXOp* MDL::TransformRotateXOp::init()
{
    return NS::Object::init<MDL::TransformRotateXOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformRotateXOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedScalar* MDL::TransformRotateXOp::animatedValue() const
{
    return Object::sendMessage<AnimatedScalar*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformRotateYOp

// static method: alloc
_MDL_INLINE MDL::TransformRotateYOp* MDL::TransformRotateYOp::alloc()
{
    return NS::Object::alloc<MDL::TransformRotateYOp>(_MDL_PRIVATE_CLS(MDLTransformRotateYOp));
}

// method: init
_MDL_INLINE MDL::TransformRotateYOp* MDL::TransformRotateYOp::init()
{
    return NS::Object::init<MDL::TransformRotateYOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformRotateYOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedScalar* MDL::TransformRotateYOp::animatedValue() const
{
    return Object::sendMessage<AnimatedScalar*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformRotateZOp

// static method: alloc
_MDL_INLINE MDL::TransformRotateZOp* MDL::TransformRotateZOp::alloc()
{
    return NS::Object::alloc<MDL::TransformRotateZOp>(_MDL_PRIVATE_CLS(MDLTransformRotateZOp));
}

// method: init
_MDL_INLINE MDL::TransformRotateZOp* MDL::TransformRotateZOp::init()
{
    return NS::Object::init<MDL::TransformRotateZOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformRotateZOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedScalar* MDL::TransformRotateZOp::animatedValue() const
{
    return Object::sendMessage<AnimatedScalar*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformRotateOp

// static method: alloc
_MDL_INLINE MDL::TransformRotateOp* MDL::TransformRotateOp::alloc()
{
    return NS::Object::alloc<MDL::TransformRotateOp>(_MDL_PRIVATE_CLS(MDLTransformRotateOp));
}

// method: init
_MDL_INLINE MDL::TransformRotateOp* MDL::TransformRotateOp::init()
{
    return NS::Object::init<MDL::TransformRotateOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformRotateOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedVector3* MDL::TransformRotateOp::animatedValue() const
{
    return Object::sendMessage<AnimatedVector3*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformTranslateOp

// static method: alloc
_MDL_INLINE MDL::TransformTranslateOp* MDL::TransformTranslateOp::alloc()
{
    return NS::Object::alloc<MDL::TransformTranslateOp>(_MDL_PRIVATE_CLS(MDLTransformTranslateOp));
}

// method: init
_MDL_INLINE MDL::TransformTranslateOp* MDL::TransformTranslateOp::init()
{
    return NS::Object::init<MDL::TransformTranslateOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformTranslateOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedVector3* MDL::TransformTranslateOp::animatedValue() const
{
    return Object::sendMessage<AnimatedVector3*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformScaleOp

// static method: alloc
_MDL_INLINE MDL::TransformScaleOp* MDL::TransformScaleOp::alloc()
{
    return NS::Object::alloc<MDL::TransformScaleOp>(_MDL_PRIVATE_CLS(MDLTransformScaleOp));
}

// method: init
_MDL_INLINE MDL::TransformScaleOp* MDL::TransformScaleOp::init()
{
    return NS::Object::init<MDL::TransformScaleOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformScaleOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedVector3* MDL::TransformScaleOp::animatedValue() const
{
    return Object::sendMessage<AnimatedVector3*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformMatrixOp

// static method: alloc
_MDL_INLINE MDL::TransformMatrixOp* MDL::TransformMatrixOp::alloc()
{
    return NS::Object::alloc<MDL::TransformMatrixOp>(_MDL_PRIVATE_CLS(MDLTransformMatrixOp));
}

// method: init
_MDL_INLINE MDL::TransformMatrixOp* MDL::TransformMatrixOp::init()
{
    return NS::Object::init<MDL::TransformMatrixOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformMatrixOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedMatrix4x4* MDL::TransformMatrixOp::animatedValue() const
{
    return Object::sendMessage<AnimatedMatrix4x4*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformOrientOp

// static method: alloc
_MDL_INLINE MDL::TransformOrientOp* MDL::TransformOrientOp::alloc()
{
    return NS::Object::alloc<MDL::TransformOrientOp>(_MDL_PRIVATE_CLS(MDLTransformOrientOp));
}

// method: init
_MDL_INLINE MDL::TransformOrientOp* MDL::TransformOrientOp::init()
{
    return NS::Object::init<MDL::TransformOrientOp>();
}

// property: name
_MDL_INLINE NS::String* MDL::TransformOrientOp::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}

// property: animatedValue
_MDL_INLINE MDL::AnimatedQuaternion* MDL::TransformOrientOp::animatedValue() const
{
    return Object::sendMessage<AnimatedQuaternion*>(this, _MDL_PRIVATE_SEL(animatedValue));
}

// MARK: Class TransformStack

// static method: alloc
_MDL_INLINE MDL::TransformStack* MDL::TransformStack::alloc()
{
    return NS::Object::alloc<MDL::TransformStack>(_MDL_PRIVATE_CLS(MDLTransformStack));
}

// method: init
_MDL_INLINE MDL::TransformStack* MDL::TransformStack::init()
{
    return NS::Object::init<MDL::TransformStack>();
}

// method: addTranslateOp:inverse:
_MDL_INLINE MDL::TransformTranslateOp* MDL::TransformStack::addTranslateOp(const NS::String* animatedValueName,
                                                                 bool inverse)
{
    return Object::sendMessage<TransformTranslateOp*>(this, _MDL_PRIVATE_SEL(addTranslateOp_inverse_), animatedValueName, inverse);
}

// method: addRotateXOp:inverse:
_MDL_INLINE MDL::TransformRotateXOp* MDL::TransformStack::addRotateXOp(const NS::String* animatedValueName,
                                                                         bool inverse)
{
    return Object::sendMessage<TransformRotateXOp*>(this, _MDL_PRIVATE_SEL(addRotateXOp_inverse_), animatedValueName, inverse);
}

// method: addRotateYOp:inverse:
_MDL_INLINE MDL::TransformRotateYOp* MDL::TransformStack::addRotateYOp(const NS::String* animatedValueName,
                                                                       bool inverse)
{
    return Object::sendMessage<TransformRotateYOp*>(this, _MDL_PRIVATE_SEL(addRotateYOp_inverse_), animatedValueName, inverse);
}

// method: addRotateZOp:inverse:
_MDL_INLINE MDL::TransformRotateZOp* MDL::TransformStack::addRotateZOp(const NS::String* animatedValueName,
                                                                       bool inverse)
{
    return Object::sendMessage<TransformRotateZOp*>(this, _MDL_PRIVATE_SEL(addRotateZOp_inverse_), animatedValueName, inverse);
}

// method: addRotateOp:inverse:
_MDL_INLINE MDL::TransformRotateOp* MDL::TransformStack::addRotateOp(const NS::String* animatedValueName,
                                                                     TransformOpRotationOrder order,
                                                                     bool inverse)
{
    return Object::sendMessage<TransformRotateOp*>(this, _MDL_PRIVATE_SEL(addRotateOp_inverse_), animatedValueName, order, inverse);
}

// method: addScaleOp:inverse:
_MDL_INLINE MDL::TransformScaleOp* MDL::TransformStack::addScaleOp(const NS::String* animatedValueName,
                                                                   bool inverse)
{
    return Object::sendMessage<TransformScaleOp*>(this, _MDL_PRIVATE_SEL(addScaleOp_inverse_), animatedValueName, inverse);
}

// method: addMatrixOp:inverse:
_MDL_INLINE MDL::TransformMatrixOp* MDL::TransformStack::addMatrixOp(const NS::String* animatedValueName,
                                                                     bool inverse)
{
    return Object::sendMessage<TransformMatrixOp*>(this, _MDL_PRIVATE_SEL(addMatrixOp_inverse_), animatedValueName, inverse);
}

// method: addOrientOp:inverse:
_MDL_INLINE MDL::TransformOrientOp* MDL::TransformStack::addOrientOp(const NS::String* animatedValueName,
                                                                     bool inverse)
{
    return Object::sendMessage<TransformOrientOp*>(this, _MDL_PRIVATE_SEL(addOrientOp_inverse_), animatedValueName, inverse);
}

// method: animatedValueWithName:
_MDL_INLINE MDL::AnimatedValue* MDL::TransformStack::animatedValueWithName(const NS::String* name)
{
    return Object::sendMessage<AnimatedValue*>(this, _MDL_PRIVATE_SEL(animatedValueWithName_), name);
}

// method: float4x4AtTime:
_MDL_INLINE matrix_float4x4 MDL::TransformStack::float4x4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(float4x4AtTime_), time);
}

// method: double4x4AtTime:
_MDL_INLINE matrix_double4x4 MDL::TransformStack::double4x4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_double4x4>(this, _MDL_PRIVATE_SEL(double4x4AtTime_), time);
}

// property: keyTimes
_MDL_INLINE NS::Array* MDL::TransformStack::keyTimes() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(keyTimes));
}

// property: transformOps
_MDL_INLINE NS::Array* MDL::TransformStack::transformOps() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(transformOps));
}









// MARK: - Original Header

//#import <Foundation/Foundation.h>
//#import <simd/simd.h>
//#import <ModelIO/MDLTypes.h>
//#import <ModelIO/MDLTransform.h>
//#import <ModelIO/MDLAnimatedValueTypes.h>
//
//NS_ASSUME_NONNULL_BEGIN
//typedef NS_ENUM(NSUInteger, MDLTransformOpRotationOrder) {
//    MDLTransformOpRotationOrderXYZ = 1,
//    MDLTransformOpRotationOrderXZY,
//    MDLTransformOpRotationOrderYXZ,
//    MDLTransformOpRotationOrderYZX,
//    MDLTransformOpRotationOrderZXY,
//    MDLTransformOpRotationOrderZYX,
//};
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//@protocol MDLTransformOp
//@property (nonatomic, readonly) NSString* name;
//-(matrix_float4x4)float4x4AtTime:(NSTimeInterval)time;
//-(matrix_double4x4)double4x4AtTime:(NSTimeInterval)time;
//-(bool)IsInverseOp;
//@end

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformRotateXOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedScalar* animatedValue;
//@end
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformRotateYOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedScalar* animatedValue;
//@end
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformRotateZOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedScalar* animatedValue;
//@end
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformRotateOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedVector3* animatedValue;
//@end

//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformTranslateOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedVector3* animatedValue;
//@end
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformScaleOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedVector3* animatedValue;
//@end
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformMatrixOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedMatrix4x4* animatedValue;
//@end

//API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0))
//MDL_EXPORT
//@interface MDLTransformOrientOp : NSObject<MDLTransformOp>
//@property (nonatomic, readonly) NSString* name;
//@property (nonatomic, readonly) MDLAnimatedQuaternion* animatedValue;
//@end
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLTransformStack : NSObject<NSCopying, MDLTransformComponent>
//
//- (id)init;
//
//-(MDLTransformTranslateOp*) addTranslateOp:(NSString*)animatedValueName
//                                   inverse:(bool)inverse;
//
//-(MDLTransformRotateXOp*) addRotateXOp:(NSString*)animatedValueName
//                               inverse:(bool)inverse;

//-(MDLTransformRotateYOp*) addRotateYOp:(NSString*)animatedValueName
//                               inverse:(bool)inverse;
//
//-(MDLTransformRotateZOp*) addRotateZOp:(NSString*)animatedValueName
//                               inverse:(bool)inverse;
//
//-(MDLTransformRotateOp*) addRotateOp:(NSString*)animatedValueName
//                               order:(MDLTransformOpRotationOrder)order
//                             inverse:(bool)inverse;

//-(MDLTransformScaleOp*) addScaleOp:(NSString*)animatedValueName
//                           inverse:(bool)inverse;
//
//-(MDLTransformMatrixOp*) addMatrixOp:(NSString*)animatedValueName
//                             inverse:(bool)inverse;
//
//-(MDLTransformOrientOp*) addOrientOp:(NSString*)animatedValueName
//                             inverse:(bool)inverse;

//-(MDLAnimatedValue*) animatedValueWithName:(NSString*) name;
//
//-(matrix_float4x4)float4x4AtTime:(NSTimeInterval)time;
//-(matrix_double4x4)double4x4AtTime:(NSTimeInterval)time;
//
//-(NSUInteger)count;
//
//@property (nonatomic, readonly, copy) NSArray<NSNumber*> *keyTimes;
//@property (nonatomic, readonly, copy) NSArray<id<MDLTransformOp>> *transformOps;
//
//
//@end
//
//
//NS_ASSUME_NONNULL_END


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

// TODO: Private Sector -








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


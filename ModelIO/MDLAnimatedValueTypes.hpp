/*!
 @header MDLAnimatedValueTypes.hpp
 @framework ModelIO
 @abstract Time sampled animated value types
 @copyright Treata Norouzi on 8/16/24.
 */


#include "Foundation/Foundation.hpp"
#include "MDLTypes.hpp"

namespace MDL
{
_MDL_ENUM(NS::UInteger, AnimatedValueInterpolation) {
    AnimatedValueInterpolationConstant,
    AnimatedValueInterpolationLinear
};

class AnimatedValue : public NS::Copying<AnimatedValue> 
{
    static class AnimatedValue*     alloc();
    
    class AnimatedValue*            init();
    
    // isAnimated:
    BOOL                            isAnimated();
    
    DataPrecision                   precision() const;
    
    NS::UInteger                    timeSampleCount() const;
    
    NS::TimeInterval                minimumTime() const;
    
    NS::TimeInterval                maximumTime() const;
    
    AnimatedValueInterpolation      interpolation() const;
    void                            setInterpolation(const AnimatedValueInterpolation interpolation);
    
    NS::Array*                      keyTimes() const;
    
    // clear:
    void                            clear();
    
    // getTimes:maxCount:
    NS::UInteger                    getTimes(const NS::TimeInterval* timesArray, const NS::UInteger maxCount);
};

class AnimatedScalarArray : public NS::Referencing<AnimatedValue>
{
    static class AnimatedScalarArray*   alloc();
    
    class AnimatedScalarArray*          init();
    
    NS::UInteger                    elementCount() const;
    
    // initWithElementCount:
    class AnimatedScalarArray*      initWithElementCount(const NS::UInteger arrayElementCount);
    
    // setFloatArray:count:atTime:
    void                            setFloatArray(const float* array, NS::UInteger count, NS::TimeInterval time);
    
    // setDoubleArray:count:atTime:
    void                            setDoubleArray(const double* array, NS::UInteger count, NS::TimeInterval time);
    
    // getFloatArray:maxCount:atTime:
    void                            getFloatArray(const float* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // getDoubleArray:maxCount:atTime:
    void                            getDoubleArray(const double* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // resetWithFloatArray:count:atTimes:count:
    void                            resetWithFloatArray(const float* valuesArray, NS::UInteger valuesCount, const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // resetWithDoubleArray:count:atTimes:count:
    void                            resetWithDoubleArray(const double* valuesArray, NS::UInteger valuesCount, const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // getFloatArray:maxCount:
    NS::UInteger                    getFloatArray(const float* valuesArray, NS::UInteger maxCount);
    
    // getDoubleArray:maxCount:
    NS::UInteger                    getDoubleArray(const double* valuesArray, NS::UInteger maxCount);
};

class AnimatedVector3Array : public NS::Referencing<AnimatedValue>
{
    static class AnimatedVector3Array*  alloc();
    
    NS::UInteger                        NSUInteger() const;
    
    // initWithElementCount:
    class AnimatedVector3Array*         initWithElementCount(NS::UInteger arrayElementCount);
    
    // setFloat3Array:count:atTime:
    void                        setFloat3Array(const vector_float3* array, NS::UInteger count, NS::TimeInterval time);
    
    // setDouble3Array:count:atTime:
    void                        setDouble3Array(const vector_double3* array, NS::UInteger count, NS::TimeInterval time);
    
    // getFloat3Array:maxCount:atTime:
                                    // !!!: Uncertain about `const`
    NS::UInteger                getFloat3Array(const vector_float3* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // getDouble3Array:maxCount:atTime:
    NS::UInteger                getDouble3Array(const vector_double3* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // resetWithFloat3Array:count:atTimes:count:
    void                        resetWithFloat3Array(const vector_float3* valuesArray, NS::UInteger valuesCount, const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // resetWithDouble3Array:count:atTimes:count:
    void                        resetWithDouble3Array(const vector_double3* valuesArray, NS::UInteger valuesCount, const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // getFloat3Array:maxCount:
    NS::UInteger                getFloat3Array(const vector_float3* valuesArray, NS::UInteger maxCount);
    
    // getDouble3Array:maxCount:
    NS::UInteger                getDouble3Array(const vector_double3* valuesArray, NS::UInteger maxCount);
};

class AnimatedQuaternionArray : public NS::Referencing<AnimatedValue>
{
    static class AnimatedQuaternionArray*   alloc();
    
    NS::UInteger                            elementCount() const;
    
    // initWithElementCount:
    static class AnimatedQuaternionArray*   initWithElementCount(NS::UInteger arrayElementCount);
    
    // setFloatQuaternionArray:count:atTime:
    void                    setFloatQuaternionArray(const simd_quatf* array, NS::UInteger count, NS::TimeInterval time);
    
    // setDoubleQuaternionArray:count:atTime:
    void                    setDoubleQuaternionArray(const simd_quatd* array, NS::UInteger count, NS::TimeInterval time);
    
    // getFloatQuaternionArray:maxCount:atTime:
    void                    getFloatQuaternionArray(const simd_quatf* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // getDoubleQuaternionArray:maxCount:atTime:
    void                    getDoubleQuaternionArray(const simd_quatd* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // resetWithFloatQuaternionArray:count:atTimes:count:
    void                    resetWithFloatQuaternionArray(const simd_quatf* valuesArray, NS::UInteger valuesCount, const NS::TimeInterval* timesArray, NS::TimeInterval timesCount);
    
    // resetWithDoubleQuaternionArray:count:atTimes:count:
    void                    resetWithDoubleQuaternionArray(const simd_quatd* valuesArray, NS::UInteger valuesCount, const NS::TimeInterval* timesArray, NS::TimeInterval timesCount);
    
    // getFloatQuaternionArray:maxCount:
    NS::UInteger            getFloatQuaternionArray(const simd_quatf* valuesArray, NS::UInteger maxCount);
    
    // getDoubleQuaternionArray:maxCount:
    NS::UInteger            getDoubleQuaternionArray(const simd_quatd* valuesArray, NS::UInteger maxCount);
};

class AnimatedScalar : public NS::Referencing<AnimatedValue>
{
    static class AnimatedScalar*    alloc();
    
    class AnimatedScalar*           init();
    
    // setFloat:atTime:
    void                            setFloat(float value, NS::TimeInterval time);
    
    // setDouble:atTime:
    void                            setDouble(double value, NS::TimeInterval time);
    
    // floatAtTime:
    float                           floatAtTime(NS::TimeInterval time);
    
    // doubleAtTime:
    double                          doubleAtTime(NS::TimeInterval time);
    
    // resetWithFloatArray:atTimes:count:
    void                            resetWithFloatArray(const float* valuesArray, const NS::TimeInterval timesArray, NS::UInteger count);
    
    // resetWithDoubleArray:atTimes:count:
    void                            resetWithDoubleArray(const double* valuesArray, const NS::TimeInterval timesArray, NS::UInteger count);
};
    
class AnimatedVector2 : public NS::Referencing<AnimatedValue>
{
    static class AnimatedVector2*   alloc();
    
    class AnimatedVector2*          init();
    
    // setFloat2:atTime:
    void                    setFloat2(vector_float2 value, NS::TimeInterval time);
    
    // setDouble2:atTime:
    void                    setDouble2(vector_double2 value, NS::TimeInterval time);
    
    // float2AtTime:
    vector_float2           float2AtTime(NS::TimeInterval time);
    
    // double2AtTime:
    vector_double2          double2AtTime(NS::TimeInterval time);
    
    // resetWithFloat2Array:atTimes:count:
    void                    resetWithFloat2Array(const vector_float2* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // resetWithDouble2Array:atTimes:count:
    void                    resetWithDouble2Array(const vector_double2* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // getFloat2Array:maxCount:
    NS::UInteger            getFloat2Array(const vector_float2* valuesArray, NS::UInteger maxCount);
    
    // getDouble2Array:maxCount:
    NS::UInteger            getDouble2Array(const vector_double2* valuesArray, NS::UInteger maxCount);
};

class AnimatedVector3 : public NS::Referencing<AnimatedValue>
{
    static class AnimatedVector3*   alloc();
    
    class AnimatedVector3*          init();
    
    // setFloat3:atTime:
    void                    setFloat3(vector_float3 value, NS::TimeInterval time);
    
    // setDouble3:atTime:
    void                    setDouble3(vector_double3 value, NS::TimeInterval time);
    
    // float3AtTime:
    vector_float3           float3AtTime(NS::TimeInterval time);
    
    // double3AtTime:
    vector_double3          double3AtTime(NS::TimeInterval time);
    
    // resetWithFloat3Array:atTimes:count:
    void                    resetWithFloat3Array(const vector_float3* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // resetWithDouble3Array:atTimes:count:
    void                    resetWithDouble3Array(const vector_double3* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // getFloat3Array:maxCount:
    NS::UInteger            getFloat3Array(const vector_float3* valuesArray, NS::UInteger maxCount);
    
    // getDouble3Array:maxCount:
    NS::UInteger            getDouble3Array(const vector_double3* valuesArray, NS::UInteger maxCount);
};

class AnimatedVector4 : public NS::Referencing<AnimatedValue>
{
    static class AnimatedVector4*   alloc();
    
    class AnimatedVector4*          init();
    
    // setFloat4:atTime:
    void                    setFloat4(vector_float4 value, NS::TimeInterval time);
    
    // setDouble4:atTime:
    void                    setDouble4(vector_double4 value, NS::TimeInterval time);
    
    // float4AtTime:
    vector_float4           float4AtTime(NS::TimeInterval time);
    
    // double4AtTime:
    vector_double4          double4AtTime(NS::TimeInterval time);
    
    // resetWithFloat4Array:atTimes:count:
    void                    resetWithFloat4Array(const vector_float4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // resetWithDouble4Array:atTimes:count:
    void                    resetWithDouble4Array(const vector_double4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // getFloat4Array:maxCount:
    NS::UInteger            getFloat4Array(const vector_float4* valuesArray, NS::UInteger maxCount);
    
    // getDouble4Array:maxCount:
    NS::UInteger            getDouble4Array(const vector_double4* valuesArray, NS::UInteger maxCount);
};

class AnimatedQuaternion : public NS::Referencing<AnimatedValue>
{
    static class AnimatedQuaternion*    alloc();
    
    class AnimatedQuaternion*           init();
    
    // setFloatQuaternion:atTime:
    void                setFloatQuaternion(simd_quatf value, NS::TimeInterval time);
    
    // setDoubleQuaternion:atTime:
    void                setDoubleQuaternion(simd_quatd value, NS::TimeInterval time);
    
    // floatQuaternionAtTime:
    simd_quatf          floatQuaternionAtTime(NS::TimeInterval time);
    
    // doubleQuaternionAtTime:
    simd_quatd          doubleQuaternionAtTime(NS::TimeInterval time);
    
    // resetWithFloatQuaternionArray:atTimes:count:
    void                resetWithFloatQuaternionArray(const simd_quatf* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // resetWithDoubleQuaternionArray:atTimes:count:
    void                resetWithDoubleQuaternionArray(const simd_quatd* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // getFloatQuaternionArray:maxCount:
    NS::UInteger        getFloatQuaternionArray(const simd_quatf* valuesArray, NS::UInteger maxCount);
    
    // getDoubleQuaternionArray:maxCount:
    NS::UInteger        getDoubleQuaternionArray(const simd_quatd* valuesArray, NS::UInteger maxCount);
};

class AnimatedMatrix4x4 : public NS::Referencing<AnimatedValue>
{
    static class AnimatedMatrix4x4*     alloc();
    
    class AnimatedMatrix4x4*            init();
    
    // setFloat4x4:atTime:
    void                    setFloat4x4(matrix_float4x4 value, NS::TimeInterval time);
    
    // setDouble4x4:atTime:
    void                    setDouble4x4(matrix_double4x4 value, NS::TimeInterval time);
    
    // float4x4AtTime:
    matrix_float4x4           float4x4AtTime(NS::TimeInterval time);
    
    // double4x4AtTime:
    matrix_double4x4          double4x4AtTime(NS::TimeInterval time);
    
    // resetWithFloat4x4Array:atTimes:count:
    void                    resetWithFloat4x4Array(const matrix_float4x4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // resetWithDouble4x4Array:atTimes:count:
    void                    resetWithDouble4x4Array(const matrix_double4x4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // getFloat4x4Array:maxCount:
    NS::UInteger            getFloat4x4Array(const matrix_float4x4* valuesArray, NS::UInteger maxCount);
    
    // getDouble4x4Array:maxCount:
    NS::UInteger            getDouble4x4Array(const matrix_double4x4* valuesArray, NS::UInteger maxCount);
};

}

// TODO: Private Sector -






// MARK: - Original Header

//#import <Foundation/Foundation.h>
//#import <ModelIO/MDLTypes.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//typedef NS_ENUM(NSUInteger, MDLAnimatedValueInterpolation) {
//    MDLAnimatedValueInterpolationConstant,
//    MDLAnimatedValueInterpolationLinear
//};
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedValue : NSObject<NSCopying>
//-(BOOL)isAnimated;
//@property (nonatomic, readonly) MDLDataPrecision precision;
//@property (nonatomic, readonly) NSUInteger timeSampleCount;
//@property (nonatomic, readonly) NSTimeInterval minimumTime;
//@property (nonatomic, readonly) NSTimeInterval maximumTime;
//@property (nonatomic) MDLAnimatedValueInterpolation interpolation;
//
//@property (nonatomic, readonly) NSArray<NSNumber *> *keyTimes;
//
//-(void)clear;
//-(NSUInteger)getTimes:(NSTimeInterval *)timesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//@end
//
//
/// AUTO-GENERATED FROM CodeGenArray.h
//
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedScalarArray : MDLAnimatedValue
//
//@property (nonatomic, readonly) NSUInteger elementCount;
//
//-(id)initWithElementCount:(NSUInteger)arrayElementCount;
//
//-(void)setFloatArray:(const float *)array count:(NSUInteger)count atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//-(void)setDoubleArray:(const double *)array count:(NSUInteger)count atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloatArray:(float *)array maxCount:(NSUInteger)maxCount atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDoubleArray:(double *)array maxCount:(NSUInteger)maxCount atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//
//-(void)resetWithFloatArray:(const float *)valuesArray count:(NSUInteger)valuesCount atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)timesCount NS_REFINED_FOR_SWIFT;
//-(void)resetWithDoubleArray:(const double *)valuesArray count:(NSUInteger)valuesCount atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)timesCount NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloatArray:(float *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDoubleArray:(double *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end
//
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedVector3Array : MDLAnimatedValue
//
//@property (nonatomic, readonly) NSUInteger elementCount;
//
//-(id)initWithElementCount:(NSUInteger)arrayElementCount;
//
//-(void)setFloat3Array:(const vector_float3 *)array count:(NSUInteger)count atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//-(void)setDouble3Array:(const vector_double3 *)array count:(NSUInteger)count atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloat3Array:(vector_float3 *)array maxCount:(NSUInteger)maxCount atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDouble3Array:(vector_double3 *)array maxCount:(NSUInteger)maxCount atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//
//-(void)resetWithFloat3Array:(const vector_float3 *)valuesArray count:(NSUInteger)valuesCount atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)timesCount NS_REFINED_FOR_SWIFT;
//-(void)resetWithDouble3Array:(const vector_double3 *)valuesArray count:(NSUInteger)valuesCount atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)timesCount NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloat3Array:(vector_float3 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDouble3Array:(vector_double3 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end
//
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedQuaternionArray : MDLAnimatedValue
//
//@property (nonatomic, readonly) NSUInteger elementCount;
//
//-(id)initWithElementCount:(NSUInteger)arrayElementCount;
//
//-(void)setFloatQuaternionArray:(const simd_quatf *)array count:(NSUInteger)count atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//-(void)setDoubleQuaternionArray:(const simd_quatd *)array count:(NSUInteger)count atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloatQuaternionArray:(simd_quatf *)array maxCount:(NSUInteger)maxCount atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDoubleQuaternionArray:(simd_quatd *)array maxCount:(NSUInteger)maxCount atTime:(NSTimeInterval)time NS_REFINED_FOR_SWIFT;
//
//-(void)resetWithFloatQuaternionArray:(const simd_quatf *)valuesArray count:(NSUInteger)valuesCount atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)timesCount NS_REFINED_FOR_SWIFT;
//-(void)resetWithDoubleQuaternionArray:(const simd_quatd *)valuesArray count:(NSUInteger)valuesCount atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)timesCount NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloatQuaternionArray:(simd_quatf *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDoubleQuaternionArray:(simd_quatd *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end


/// AUTO-GENERATED FROM CodeGen.h


//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedScalar : MDLAnimatedValue
//
//-(void)setFloat:(float)value atTime:(NSTimeInterval)time;
//-(void)setDouble:(double)value atTime:(NSTimeInterval)time;
//
//-(float)floatAtTime:(NSTimeInterval)time;
//-(double)doubleAtTime:(NSTimeInterval)time;

//-(void)resetWithFloatArray:(const float *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//-(void)resetWithDoubleArray:(const double *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloatArray:(float *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDoubleArray:(double *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end


//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedVector2 : MDLAnimatedValue
//
//-(void)setFloat2:(vector_float2)value atTime:(NSTimeInterval)time;
//-(void)setDouble2:(vector_double2)value atTime:(NSTimeInterval)time;
//
//-(vector_float2)float2AtTime:(NSTimeInterval)time;
//-(vector_double2)double2AtTime:(NSTimeInterval)time;

//-(void)resetWithFloat2Array:(const vector_float2 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//-(void)resetWithDouble2Array:(const vector_double2 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloat2Array:(vector_float2 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDouble2Array:(vector_double2 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end


//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedVector3 : MDLAnimatedValue
//
//-(void)setFloat3:(vector_float3)value atTime:(NSTimeInterval)time;
//-(void)setDouble3:(vector_double3)value atTime:(NSTimeInterval)time;
//
//-(vector_float3)float3AtTime:(NSTimeInterval)time;
//-(vector_double3)double3AtTime:(NSTimeInterval)time;
//
//-(void)resetWithFloat3Array:(const vector_float3 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//-(void)resetWithDouble3Array:(const vector_double3 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloat3Array:(vector_float3 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDouble3Array:(vector_double3 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end
//
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedVector4 : MDLAnimatedValue
//
//-(void)setFloat4:(vector_float4)value atTime:(NSTimeInterval)time;
//-(void)setDouble4:(vector_double4)value atTime:(NSTimeInterval)time;
//
//-(vector_float4)float4AtTime:(NSTimeInterval)time;
//-(vector_double4)double4AtTime:(NSTimeInterval)time;
//
//-(void)resetWithFloat4Array:(const vector_float4 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//-(void)resetWithDouble4Array:(const vector_double4 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloat4Array:(vector_float4 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDouble4Array:(vector_double4 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end


//API_AVAILABLE(macos(10.14), ios(12.0), tvos(12.0))
//MDL_EXPORT
//@interface MDLAnimatedQuaternion : MDLAnimatedValue
//
//-(void)setFloatQuaternion:(simd_quatf)value atTime:(NSTimeInterval)time;
//-(void)setDoubleQuaternion:(simd_quatd)value atTime:(NSTimeInterval)time;
//
//-(simd_quatf)floatQuaternionAtTime:(NSTimeInterval)time;
//-(simd_quatd)doubleQuaternionAtTime:(NSTimeInterval)time;

//-(void)resetWithFloatQuaternionArray:(const simd_quatf *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//-(void)resetWithDoubleQuaternionArray:(const simd_quatd *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloatQuaternionArray:(simd_quatf *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDoubleQuaternionArray:(simd_quatd *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end


//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLAnimatedMatrix4x4 : MDLAnimatedValue
//
//-(void)setFloat4x4:(matrix_float4x4)value atTime:(NSTimeInterval)time;
//-(void)setDouble4x4:(matrix_double4x4)value atTime:(NSTimeInterval)time;
//
//-(matrix_float4x4)float4x4AtTime:(NSTimeInterval)time;
//-(matrix_double4x4)double4x4AtTime:(NSTimeInterval)time;
//
//-(void)resetWithFloat4x4Array:(const matrix_float4x4 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//-(void)resetWithDouble4x4Array:(const matrix_double4x4 *)valuesArray atTimes:(const NSTimeInterval *)timesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloat4x4Array:(matrix_float4x4 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDouble4x4Array:(matrix_double4x4 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//
//@end
//
//NS_ASSUME_NONNULL_END


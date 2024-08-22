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
public:
    static class AnimatedValue*     alloc();
    
    class AnimatedValue*            init();
    
    // isAnimated
    BOOL                            isAnimated();
    
    // - Readonly
    DataPrecision                   precision() const;
    
    NS::UInteger                    timeSampleCount() const;
    
    NS::TimeInterval                minimumTime() const;
    
    NS::TimeInterval                maximumTime() const;
    
    AnimatedValueInterpolation      interpolation() const;
    void                            setInterpolation(AnimatedValueInterpolation interpolation);
    
    NS::Array*                      keyTimes() const;
    
    // clear
    void                            clear();
    
    // getTimes:maxCount:
    NS::UInteger                    getTimes(const NS::TimeInterval* timesArray, NS::UInteger maxCount);
};

class AnimatedScalarArray : public NS::Referencing<AnimatedValue>
{
public:
    static class AnimatedScalarArray*   alloc();
    
    class AnimatedScalarArray*          init();
    
    NS::UInteger                elementCount() const;
    
    // initWithElementCount:
    class AnimatedScalarArray*  init(NS::UInteger arrayElementCount);
    
    // setFloatArray:count:atTime:
    void                        setFloatArray(const float* array, NS::UInteger count, NS::TimeInterval time);
    
    // setDoubleArray:count:atTime:
    void                        setDoubleArray(const double* array, NS::UInteger count, NS::TimeInterval time);
    
    // getFloatArray:maxCount:atTime:
    NS::UInteger                getFloatArray(const float* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // getDoubleArray:maxCount:atTime:
    NS::UInteger                getDoubleArray(const double* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // resetWithFloatArray:count:atTimes:count:
    void                        resetWithFloatArray(const float* valuesArray, NS::UInteger valuesCount, 
                                                    const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // resetWithDoubleArray:count:atTimes:count:
    void                        resetWithDoubleArray(const double* valuesArray, NS::UInteger valuesCount, 
                                                     const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // getFloatArray:maxCount:
    NS::UInteger                getFloatArray(const float* valuesArray, NS::UInteger maxCount);
    
    // getDoubleArray:maxCount:
    NS::UInteger                getDoubleArray(const double* valuesArray, NS::UInteger maxCount);
};

class AnimatedVector3Array : public NS::Referencing<AnimatedValue>
{
public:
    static class AnimatedVector3Array*  alloc();
    
    NS::UInteger                        elementCount() const;
    
    // initWithElementCount:
    class AnimatedVector3Array*         init(NS::UInteger arrayElementCount);
    
    // setFloat3Array:count:atTime:
    void                setFloat3Array(const vector_float3* array, NS::UInteger count, NS::TimeInterval time);
    
    // setDouble3Array:count:atTime:
    void                setDouble3Array(const vector_double3* array, NS::UInteger count, NS::TimeInterval time);
    
    // getFloat3Array:maxCount:atTime:
    NS::UInteger        getFloat3Array(const vector_float3* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // getDouble3Array:maxCount:atTime:
    NS::UInteger        getDouble3Array(const vector_double3* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // resetWithFloat3Array:count:atTimes:count:
    void                resetWithFloat3Array(const vector_float3* valuesArray, NS::UInteger valuesCount, 
                                             const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // resetWithDouble3Array:count:atTimes:count:
    void                resetWithDouble3Array(const vector_double3* valuesArray, NS::UInteger valuesCount, 
                                              const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // getFloat3Array:maxCount:
    NS::UInteger        getFloat3Array(const vector_float3* valuesArray, NS::UInteger maxCount);
    
    // getDouble3Array:maxCount:
    NS::UInteger        getDouble3Array(const vector_double3* valuesArray, NS::UInteger maxCount);
};

class AnimatedQuaternionArray : public NS::Referencing<AnimatedValue>
{
public:
    static class AnimatedQuaternionArray*   alloc();
    
    NS::UInteger                            elementCount() const;
    
    // initWithElementCount:
    class AnimatedQuaternionArray*          init(NS::UInteger arrayElementCount);
    
    // setFloatQuaternionArray:count:atTime:
    void                    setFloatQuaternionArray(const simd_quatf* array, NS::UInteger count, NS::TimeInterval time);
    
    // setDoubleQuaternionArray:count:atTime:
    void                    setDoubleQuaternionArray(const simd_quatd* array, NS::UInteger count, NS::TimeInterval time);
    
    // getFloatQuaternionArray:maxCount:atTime:
    NS::UInteger            getFloatQuaternionArray(const simd_quatf* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // getDoubleQuaternionArray:maxCount:atTime:
    NS::UInteger            getDoubleQuaternionArray(const simd_quatd* array, NS::UInteger maxCount, NS::TimeInterval time);
    
    // resetWithFloatQuaternionArray:count:atTimes:count:
    void                    resetWithFloatQuaternionArray(const simd_quatf* valuesArray, NS::UInteger valuesCount, 
                                                          const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
    // resetWithDoubleQuaternionArray:count:atTimes:count:
    void                    resetWithDoubleQuaternionArray(const simd_quatd* valuesArray, NS::UInteger valuesCount, 
                                                           const NS::TimeInterval* timesArray, NS::UInteger timesCount);
    
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
    void                            resetWithFloatArray(const float* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
    
    // resetWithDoubleArray:atTimes:count:
    void                            resetWithDoubleArray(const double* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count);
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
    matrix_float4x4         float4x4AtTime(NS::TimeInterval time);
    
    // double4x4AtTime:
    matrix_double4x4        double4x4AtTime(NS::TimeInterval time);
    
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

// MARK: - Private Sector

// static method: alloc
_MDL_INLINE MDL::AnimatedValue* MDL::AnimatedValue::alloc()
{
    return NS::Object::alloc<MDL::AnimatedValue>(_MDL_PRIVATE_CLS(MDLAnimatedValue));
}

// method: init
_MDL_INLINE MDL::AnimatedValue* MDL::AnimatedValue::init()
{
    return NS::Object::init<MDL::AnimatedValue>();
}

// method: isAnimated
_MDL_INLINE BOOL MDL::AnimatedValue::isAnimated()
{
    return Object::sendMessage<BOOL>(this, _MDL_PRIVATE_SEL(isAnimated));
}

// property: precision
_MDL_INLINE MDL::DataPrecision MDL::AnimatedValue::precision() const
{
    return Object::sendMessage<DataPrecision>(this, _MDL_PRIVATE_SEL(precision));
}

// property: timeSampleCount
_MDL_INLINE NS::UInteger MDL::AnimatedValue::timeSampleCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(timeSampleCount));
}

// property: minimumTime
_MDL_INLINE NS::TimeInterval MDL::AnimatedValue::minimumTime() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(minimumTime));
}

// property: maximumTime
_MDL_INLINE NS::TimeInterval MDL::AnimatedValue::maximumTime() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(maximumTime));
}

// property: interpolation
_MDL_INLINE MDL::AnimatedValueInterpolation MDL::AnimatedValue::interpolation() const
{
    return Object::sendMessage<AnimatedValueInterpolation>(this, _MDL_PRIVATE_SEL(interpolation));
}
// write method: setInterpolation:
_MDL_INLINE void MDL::AnimatedValue::setInterpolation(AnimatedValueInterpolation interpolation)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setInterpolation_), interpolation);
}

// property: keyTimes
_MDL_INLINE NS::Array* MDL::AnimatedValue::keyTimes() const
{
    return Object::sendMessage<NS::Array*>(this, _MDL_PRIVATE_SEL(keyTimes));
}

// method: clear
_MDL_INLINE void MDL::AnimatedValue::clear()
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(clear));
}

// method: getTimes:maxCount:
_MDL_INLINE NS::UInteger MDL::AnimatedValue::getTimes(const NS::TimeInterval* timesArray, NS::UInteger maxCount)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getTimes_maxCount_), timesArray, maxCount);
}

// MARK: Class AnimatedScalarArray

// static method: alloc
_MDL_INLINE MDL::AnimatedScalarArray* MDL::AnimatedScalarArray::alloc()
{
    return NS::Object::alloc<MDL::AnimatedScalarArray>(_MDL_PRIVATE_CLS(MDLAnimatedScalarArray));
}

// method: init
_MDL_INLINE MDL::AnimatedScalarArray* MDL::AnimatedScalarArray::init()
{
    return NS::Object::init<MDL::AnimatedScalarArray>();
}

// property: elementCount
_MDL_INLINE NS::UInteger MDL::AnimatedScalarArray::elementCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(elementCount));
}

// method: initWithElementCount:
_MDL_INLINE MDL::AnimatedScalarArray* MDL::AnimatedScalarArray::init(NS::UInteger arrayElementCount)
{
    return Object::sendMessage<MDL::AnimatedScalarArray*>(this, _MDL_PRIVATE_SEL(initWithElementCount_), arrayElementCount);
}

// method: setFloatArray:count:atTime:
_MDL_INLINE void MDL::AnimatedScalarArray::setFloatArray(const float* array, NS::UInteger count, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloatArray_count_atTime_), array, count, time);
}

// method: setDoubleArray:count:atTime:
_MDL_INLINE void MDL::AnimatedScalarArray::setDoubleArray(const double* array, NS::UInteger count, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDoubleArray_count_atTime_), array, count, time);
}

// method: getFloatArray:count:atTime:
_MDL_INLINE NS::UInteger MDL::AnimatedScalarArray::getFloatArray(const float* array, NS::UInteger maxCount, NS::TimeInterval time)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getFloatArray_count_atTime_), array, maxCount, time);
}

// method: getDoubleArray:count:atTime:
_MDL_INLINE NS::UInteger MDL::AnimatedScalarArray::getDoubleArray(const double* array, NS::UInteger maxCount, NS::TimeInterval time)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getDoubleArray_count_atTime_), array, maxCount, time);
}

// method: resetWithFloatArray:count:atTimes:count:
_MDL_INLINE void MDL::AnimatedScalarArray::resetWithFloatArray(const float* valuesArray, NS::UInteger valuesCount,
                                                               const NS::TimeInterval* timesArray, NS::UInteger timesCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloatArray_count_atTime_count_), valuesArray, valuesCount, timesArray, timesCount);
}

// method: resetWithDoubleArray:count:atTimes:count:
_MDL_INLINE void MDL::AnimatedScalarArray::resetWithDoubleArray(const double* valuesArray, NS::UInteger valuesCount,
                                                               const NS::TimeInterval* timesArray, NS::UInteger timesCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDoubleArray_count_atTime_count_), valuesArray, valuesCount, timesArray, timesCount);
}

// method: getFloatArray:maxCount:
_MDL_INLINE NS::UInteger MDL::AnimatedScalarArray::getFloatArray(const float* array, NS::UInteger maxCount)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getFloatArray_count_), array, maxCount);
}

// method: getDoubleArray:maxCount:
_MDL_INLINE NS::UInteger MDL::AnimatedScalarArray::getDoubleArray(const double* array, NS::UInteger maxCount)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getDoubleArray_count_), array, maxCount);
}

// MARK: Class AnimatedVector3Array

// static method: alloc
_MDL_INLINE MDL::AnimatedVector3Array* MDL::AnimatedVector3Array::alloc()
{
    return NS::Object::alloc<MDL::AnimatedVector3Array>(_MDL_PRIVATE_CLS(MDLAnimatedVector3Array));
}

// property: elementCount
_MDL_INLINE NS::UInteger MDL::AnimatedVector3Array::elementCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(elementCount));
}

// method: initWithElementCount:
_MDL_INLINE MDL::AnimatedVector3Array* MDL::AnimatedVector3Array::init(NS::UInteger arrayElementCount)
{
    return Object::sendMessage<MDL::AnimatedVector3Array*>(this, _MDL_PRIVATE_SEL(initWithElementCount_), arrayElementCount);
}

// method: setFloat3Array:count:atTime:
_MDL_INLINE void MDL::AnimatedVector3Array::setFloat3Array(const vector_float3* array, NS::UInteger count, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat3Array_count_atTime_), array, count, time);
}

// method: setDouble3Array:count:atTime:
_MDL_INLINE void MDL::AnimatedVector3Array::setDouble3Array(const vector_double3* array, NS::UInteger count, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDouble3Array_count_atTime_), array, count, time);
}

// method: getFloat3Array:count:atTime:
_MDL_INLINE NS::UInteger MDL::AnimatedVector3Array::getFloat3Array(const vector_float3* array, NS::UInteger maxCount, NS::TimeInterval time)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getFloat3Array_count_atTime_), array, maxCount, time);
}

// method: getDouble3Array:count:atTime:
_MDL_INLINE NS::UInteger MDL::AnimatedVector3Array::getDouble3Array(const vector_double3* array, NS::UInteger maxCount, NS::TimeInterval time)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getDouble3Array_count_atTime_), array, maxCount, time);
}

// method: resetWithFloat3Array:count:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector3Array::resetWithFloat3Array(const vector_float3* valuesArray, NS::UInteger valuesCount,
                                                                 const NS::TimeInterval* timesArray, NS::UInteger timesCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloat3Array_count_atTime_count_), valuesArray, valuesCount, timesArray, timesCount);
}

// method: resetWithDouble3Array:count:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector3Array::resetWithDouble3Array(const vector_double3* valuesArray, NS::UInteger valuesCount,
                                                                  const NS::TimeInterval* timesArray, NS::UInteger timesCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDouble3Array_count_atTime_count_), valuesArray, valuesCount, timesArray, timesCount);
}


_MDL_INLINE NS::UInteger MDL::AnimatedVector3Array::getFloat3Array(const vector_float3* array, NS::UInteger maxCount)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getFloat3Array_count_), array, maxCount);
}

// method: getDouble3Array:maxCount:
_MDL_INLINE NS::UInteger MDL::AnimatedVector3Array::getDouble3Array(const vector_double3* array, NS::UInteger maxCount)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getDouble3Array_count_), array, maxCount);
}

// MARK: Class AnimatedQuaternionArray

// static method: alloc
_MDL_INLINE MDL::AnimatedQuaternionArray* MDL::AnimatedQuaternionArray::alloc()
{
    return NS::Object::alloc<MDL::AnimatedQuaternionArray>(_MDL_PRIVATE_CLS(MDLAnimatedQuaternionArray));
}

// property: elementCount
_MDL_INLINE NS::UInteger MDL::AnimatedQuaternionArray::elementCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(elementCount));
}

// method: initWithElementCount:
_MDL_INLINE MDL::AnimatedQuaternionArray* MDL::AnimatedQuaternionArray::init(NS::UInteger arrayElementCount)
{
    return Object::sendMessage<MDL::AnimatedQuaternionArray*>(this, _MDL_PRIVATE_SEL(initWithElementCount_), arrayElementCount);
}

// method: setFloatQuaternionArray:count:atTime:
_MDL_INLINE void MDL::AnimatedQuaternionArray::setFloatQuaternionArray(const simd_quatf* array, NS::UInteger count, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloatQuaternionArray_count_atTime_), array, count, time);
}

// method: setDoubleQuaternionArray:count:atTime:
_MDL_INLINE void MDL::AnimatedQuaternionArray::setDoubleQuaternionArray(const simd_quatd* array, NS::UInteger count, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDoubleQuaternionArray_count_atTime_), array, count, time);
}

// method: getFloatQuaternionArray:count:atTime:
_MDL_INLINE NS::UInteger MDL::AnimatedQuaternionArray::getFloatQuaternionArray(const simd_quatf* array, NS::UInteger maxCount, NS::TimeInterval time)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getFloatQuaternionArray_count_atTime_), array, maxCount, time);
}

// method: getDoubleQuaternionArray:count:atTime:
_MDL_INLINE NS::UInteger MDL::AnimatedQuaternionArray::getDoubleQuaternionArray(const simd_quatd* array, NS::UInteger maxCount, NS::TimeInterval time)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getDoubleQuaternionArray_count_atTime_), array, maxCount, time);
}

// method: resetWithFloatQuaternionArray:count:atTimes:count:
_MDL_INLINE void MDL::AnimatedQuaternionArray::resetWithFloatQuaternionArray(const simd_quatf* valuesArray, NS::UInteger valuesCount,
                                                                             const NS::TimeInterval* timesArray, NS::UInteger timesCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloatQuaternionArray_count_atTime_count_), valuesArray, valuesCount, timesArray, timesCount);
}

// method: resetWithDoubleQuaternionArray:count:atTimes:count:
_MDL_INLINE void MDL::AnimatedQuaternionArray::resetWithDoubleQuaternionArray(const simd_quatd* valuesArray, NS::UInteger valuesCount,
                                                                              const NS::TimeInterval* timesArray, NS::UInteger timesCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDoubleQuaternionArray_count_atTime_count_), valuesArray, valuesCount, timesArray, timesCount);
}


_MDL_INLINE NS::UInteger MDL::AnimatedQuaternionArray::getFloatQuaternionArray(const simd_quatf* array, NS::UInteger maxCount)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getFloatQuaternionArray_count_), array, maxCount);
}

// method: getDoubleQuaternionArray:maxCount:
_MDL_INLINE NS::UInteger MDL::AnimatedQuaternionArray::getDoubleQuaternionArray(const simd_quatd* array, NS::UInteger maxCount)
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(getDoubleQuaternionArray_count_), array, maxCount);
}

// MARK: Class AnimatedScalar

// static method: alloc
_MDL_INLINE MDL::AnimatedScalar* MDL::AnimatedScalar::alloc()
{
    return NS::Object::alloc<MDL::AnimatedScalar>(_MDL_PRIVATE_CLS(MDLAnimatedScalar));
}

// method: init
_MDL_INLINE MDL::AnimatedScalar* MDL::AnimatedScalar::init()
{
    return NS::Object::init<MDL::AnimatedScalar>();
}

// method: setFloat:atTime:
_MDL_INLINE void MDL::AnimatedScalar::setFloat(float value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat_atTime_), value, time);
}

// method: setDouble:atTime:
_MDL_INLINE void MDL::AnimatedScalar::setDouble(double value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDouble_atTime_), value, time);
}

// method: floatAtTime:
_MDL_INLINE float MDL::AnimatedScalar::floatAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(floatAtTime_), time);
}

// method: doubleAtTime:
_MDL_INLINE double MDL::AnimatedScalar::doubleAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<double>(this, _MDL_PRIVATE_SEL(doubleAtTime_), time);
}

// method: resetWithFloatArray:atTimes:count:
_MDL_INLINE void MDL::AnimatedScalar::resetWithFloatArray(const float* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloatArray_atTime_count_), valuesArray, timesArray, count);
}

// method: resetWithDoubleArray:atTimes:count:
_MDL_INLINE void MDL::AnimatedScalar::resetWithDoubleArray(const double* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDoubleArray_atTime_count_), valuesArray, timesArray, count);
}

// MARK: Class AnimatedVector2

// static method: alloc
_MDL_INLINE MDL::AnimatedVector2* MDL::AnimatedVector2::alloc()
{
    return NS::Object::alloc<MDL::AnimatedVector2>(_MDL_PRIVATE_CLS(MDLAnimatedVector2));
}

// method: init
_MDL_INLINE MDL::AnimatedVector2* MDL::AnimatedVector2::init()
{
    return NS::Object::init<MDL::AnimatedVector2>();
}

// method: setFloat2:atTime:
_MDL_INLINE void MDL::AnimatedVector2::setFloat2(vector_float2 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat2_atTime_), value, time);
}

// method: setDouble2:atTime:
_MDL_INLINE void MDL::AnimatedVector2::setDouble2(vector_double2 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDouble2_atTime_), value, time);
}

// method: float2AtTime:
_MDL_INLINE vector_float2 MDL::AnimatedVector2::float2AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(float2AtTime_), time);
}

// method: double2AtTime:
_MDL_INLINE vector_double2 MDL::AnimatedVector2::double2AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<double>(this, _MDL_PRIVATE_SEL(double2AtTime_), time);
}

// method: resetWithFloat2Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector2::resetWithFloat2Array(const vector_float2* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloat2Array_atTime_count_), valuesArray, timesArray, count);
}

// method: resetWithDouble2Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector2::resetWithDouble2Array(const vector_double2* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDouble2Array_atTime_count_), valuesArray, timesArray, count);
}

// MARK: Class AnimatedVector3

// static method: alloc
_MDL_INLINE MDL::AnimatedVector3* MDL::AnimatedVector3::alloc()
{
    return NS::Object::alloc<MDL::AnimatedVector3>(_MDL_PRIVATE_CLS(MDLAnimatedVector3));
}

// method: init
_MDL_INLINE MDL::AnimatedVector3* MDL::AnimatedVector3::init()
{
    return NS::Object::init<MDL::AnimatedVector3>();
}

// method: setFloat3:atTime:
_MDL_INLINE void MDL::AnimatedVector3::setFloat3(vector_float3 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat3_atTime_), value, time);
}

// method: setDouble3:atTime:
_MDL_INLINE void MDL::AnimatedVector3::setDouble3(vector_double3 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDouble3_atTime_), value, time);
}

// method: float3AtTime:
_MDL_INLINE vector_float3 MDL::AnimatedVector3::float3AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(float3AtTime_), time);
}

// method: double3AtTime:
_MDL_INLINE vector_double3 MDL::AnimatedVector3::double3AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<double>(this, _MDL_PRIVATE_SEL(double3AtTime_), time);
}

// method: resetWithFloat3Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector3::resetWithFloat3Array(const vector_float3* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloat3Array_atTime_count_), valuesArray, timesArray, count);
}

// method: resetWithDouble3Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector3::resetWithDouble3Array(const vector_double3* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDouble3Array_atTime_count_), valuesArray, timesArray, count);
}

// MARK: Class AnimatedVector4

// static method: alloc
_MDL_INLINE MDL::AnimatedVector4* MDL::AnimatedVector4::alloc()
{
    return NS::Object::alloc<MDL::AnimatedVector4>(_MDL_PRIVATE_CLS(MDLAnimatedVector4));
}

// method: init
_MDL_INLINE MDL::AnimatedVector4* MDL::AnimatedVector4::init()
{
    return NS::Object::init<MDL::AnimatedVector4>();
}

// method: setFloat4:atTime:
_MDL_INLINE void MDL::AnimatedVector4::setFloat4(vector_float4 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat4_atTime_), value, time);
}

// method: setDouble4:atTime:
_MDL_INLINE void MDL::AnimatedVector4::setDouble4(vector_double4 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDouble4_atTime_), value, time);
}

// method: float4AtTime:
_MDL_INLINE vector_float4 MDL::AnimatedVector4::float4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<float>(this, _MDL_PRIVATE_SEL(float4AtTime_), time);
}

// method: double4AtTime:
_MDL_INLINE vector_double4 MDL::AnimatedVector4::double4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<double>(this, _MDL_PRIVATE_SEL(double4AtTime_), time);
}

// method: resetWithFloat4Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector4::resetWithFloat4Array(const vector_float4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloat4Array_atTime_count_), valuesArray, timesArray, count);
}

// method: resetWithDouble4Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedVector4::resetWithDouble4Array(const vector_double4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDouble4Array_atTime_count_), valuesArray, timesArray, count);
}

// MARK: Class AnimatedQuaternion

// static method: alloc
_MDL_INLINE MDL::AnimatedQuaternion* MDL::AnimatedQuaternion::alloc()
{
    return NS::Object::alloc<MDL::AnimatedQuaternion>(_MDL_PRIVATE_CLS(MDLAnimatedQuaternion));
}

// method: init
_MDL_INLINE MDL::AnimatedQuaternion* MDL::AnimatedQuaternion::init()
{
    return NS::Object::init<MDL::AnimatedQuaternion>();
}

// method: setFloatQuaternion:atTime:
_MDL_INLINE void MDL::AnimatedQuaternion::setFloatQuaternion(simd_quatf value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloatQuaternion_atTime_), value, time);
}

// method: setDoubleQuaternion:atTime:
_MDL_INLINE void MDL::AnimatedQuaternion::setDoubleQuaternion(simd_quatd value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDoubleQuaternion_atTime_), value, time);
}

// method: floatQuaternionAtTime:
_MDL_INLINE simd_quatf MDL::AnimatedQuaternion::floatQuaternionAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<simd_quatf>(this, _MDL_PRIVATE_SEL(floatQuaternionAtTime_), time);
}

// method: doubleQuaternionAtTime:
_MDL_INLINE simd_quatd MDL::AnimatedQuaternion::doubleQuaternionAtTime(NS::TimeInterval time)
{
    return Object::sendMessage<simd_quatd>(this, _MDL_PRIVATE_SEL(doubleQuaternionAtTime_), time);
}

// method: resetWithFloatQuaternionArray:atTimes:count:
_MDL_INLINE void MDL::AnimatedQuaternion::resetWithFloatQuaternionArray(const simd_quatf* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloatQuaternionArray_atTime_count_), valuesArray, timesArray, count);
}

// method: resetWithDoubleQuaternionArray:atTimes:count:
_MDL_INLINE void MDL::AnimatedQuaternion::resetWithDoubleQuaternionArray(const simd_quatd* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDoubleQuaternionArray_atTime_count_), valuesArray, timesArray, count);
}

// MARK: Class AnimatedMatrix4x4

// static method: alloc
_MDL_INLINE MDL::AnimatedMatrix4x4* MDL::AnimatedMatrix4x4::alloc()
{
    return NS::Object::alloc<MDL::AnimatedMatrix4x4>(_MDL_PRIVATE_CLS(MDLAnimatedMatrix4x4));
}

// method: init
_MDL_INLINE MDL::AnimatedMatrix4x4* MDL::AnimatedMatrix4x4::init()
{
    return NS::Object::init<MDL::AnimatedMatrix4x4>();
}

// method: setFloat4x4:atTime:
_MDL_INLINE void MDL::AnimatedMatrix4x4::setFloat4x4(matrix_float4x4 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat4x4_atTime_), value, time);
}

// method: setDouble4x4:atTime:
_MDL_INLINE void MDL::AnimatedMatrix4x4::setDouble4x4(matrix_double4x4 value, NS::TimeInterval time)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDouble4x4_atTime_), value, time);
}

// method: float4x4AtTime:
_MDL_INLINE matrix_float4x4 MDL::AnimatedMatrix4x4::float4x4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_float4x4>(this, _MDL_PRIVATE_SEL(float4x4AtTime_), time);
}

// method: double4x4AtTime:
_MDL_INLINE matrix_double4x4 MDL::AnimatedMatrix4x4::double4x4AtTime(NS::TimeInterval time)
{
    return Object::sendMessage<matrix_double4x4>(this, _MDL_PRIVATE_SEL(double4x4AtTime_), time);
}

// method: resetWithFloat4x4Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedMatrix4x4::resetWithFloat4x4Array(const matrix_float4x4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithFloat4x4Array_atTime_count_), valuesArray, timesArray, count);
}

// method: resetWithDouble4x4Array:atTimes:count:
_MDL_INLINE void MDL::AnimatedMatrix4x4::resetWithDouble4x4Array(const matrix_double4x4* valuesArray, const NS::TimeInterval* timesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(resetWithDouble4x4Array_atTime_count_), valuesArray, timesArray, count);
}

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


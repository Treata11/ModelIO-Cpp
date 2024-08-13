/*!
 @header MDLValueTypes.hpp
 @framework ModelIO
 @abstract SIMD array value types
 @copyright Treata Norouzi on 8/12/24.
 */


#import "Foundation/Foundation.hpp"
#import "MDLTypes.hpp"

#include "MDLDefines.hpp"
#include "MDLPrivate.hpp"

namespace MDL
{
class Matrix4x4Array : public NS::Copying<Matrix4x4Array>
{
public:
    static class Matrix4x4Array*    alloc();

    class Matrix4x4Array*           init();
    
    // initWithElementCount
    MDL::Matrix4x4Array*            init(const NS::UInteger arrayElementCount);
    
    // - Readonly property accessor
    NS::UInteger                    elementCount() const;
    
    MDL::DataPrecision              precision() const;
    
    void                            clear();
    
    void                            setFloat4x4Array(const matrix_float4x4* valuesArray, NS::UInteger count);
    
    void                            setDouble4x4Array(const matrix_double4x4* valuesArray, NS::UInteger count);
    
    
    void                            getFloat4x4Array(const matrix_float4x4* valuesArray, NS::UInteger maxCount);
    
    void                            getDouble4x4Array(const matrix_double4x4* valuesArray, NS::UInteger maxCount);
};

}

// MARK: - Private sector

// static method: alloc
_MDL_INLINE MDL::Matrix4x4Array* MDL::Matrix4x4Array::alloc()
{
    return NS::Object::alloc<MDL::Matrix4x4Array>(_MDL_PRIVATE_CLS(MTLMatrix4x4Array));
}

// method: init
_MDL_INLINE MDL::Matrix4x4Array* MDL::Matrix4x4Array::init()
{
    return NS::Object::init<MDL::Matrix4x4Array>();
}

// method: initWithElementCount:
_MDL_INLINE MDL::Matrix4x4Array* MDL::Matrix4x4Array::init(const NS::UInteger arrayElementCount)
{
    return Object::sendMessage<MDL::Matrix4x4Array*>(this, _MDL_PRIVATE_SEL(initWithElementCount_), arrayElementCount);
}

// property: elementCount
_MDL_INLINE NS::UInteger MDL::Matrix4x4Array::elementCount() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(elementCount));
}

// property: precision
_MDL_INLINE MDL::DataPrecision MDL::Matrix4x4Array::precision() const
{
    return Object::sendMessage<MDL::DataPrecision>(this, _MDL_PRIVATE_SEL(precision));
}

// method: clear
_MDL_INLINE void MDL::Matrix4x4Array::clear()
{
    return Object::sendMessage<void>( this, _MDL_PRIVATE_SEL(clear) );
}

// method: setFloat4x4Array:count:
_MDL_INLINE void MDL::Matrix4x4Array::setFloat4x4Array(const matrix_float4x4* valuesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFloat4x4Array_count_), valuesArray, count);
}

// method: setDouble4x4Array:count:
_MDL_INLINE void MDL::Matrix4x4Array::setDouble4x4Array(const matrix_double4x4* valuesArray, NS::UInteger count)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setDouble4x4Array_count_), valuesArray, count);
}

// method: getFloat4x4Array:maxCount:
_MDL_INLINE void MDL::Matrix4x4Array::getFloat4x4Array(const matrix_float4x4* valuesArray, NS::UInteger maxCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(getFloat4x4Array_maxCount_), valuesArray, maxCount);
}

// method: getDouble4x4Array:maxCount:
_MDL_INLINE void MDL::Matrix4x4Array::getDouble4x4Array(const matrix_double4x4* valuesArray, NS::UInteger maxCount)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(getDouble4x4Array_maxCount_), valuesArray, maxCount);
}




// MARK: - Original objC APIs

//#import <Foundation/Foundation.h>
//#import <ModelIO/MDLTypes.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLMatrix4x4Array : NSObject<NSCopying>
//
//@property (nonatomic, readonly) NSUInteger elementCount;
//
//@property (nonatomic, readonly) MDLDataPrecision precision;
//
//-(void)clear;
//-(instancetype)initWithElementCount:(NSUInteger)arrayElementCount;
//
//-(void)setFloat4x4Array:(const matrix_float4x4 *)valuesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//-(void)setDouble4x4Array:(const matrix_double4x4 *)valuesArray count:(NSUInteger)count NS_REFINED_FOR_SWIFT;
//
//-(NSUInteger)getFloat4x4Array:(matrix_float4x4 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//-(NSUInteger)getDouble4x4Array:(matrix_double4x4 *)valuesArray maxCount:(NSUInteger)maxCount NS_REFINED_FOR_SWIFT;
//@end
//
//NS_ASSUME_NONNULL_END

/*!
 @header MDLMeshBuffer.hpp
 @framework ModelIO
 @abstract Protocols for creating and backing mesh vertex and index buffers
 @discussion Apps can use these protocols to back buffers with custom memory
             types such as GPU or File based memory
 @copyright Treata Norouzi on 8/12/24.
 */


#import "Foundation/Foundation.hpp"
#include "ModelIOExports.hpp"
#include "MDLTypes.hpp"

namespace MDL
{
_MDL_ENUM(NS::UInteger, MeshBufferType) {
    MeshBufferTypeVertex = 1,
    MeshBufferTypeIndex = 2,
    MeshBufferTypeCustom = 3,
};

class MeshBufferMap : public NS::Referencing<MeshBufferMap>
{
public:
    static class MeshBufferMap*     alloc();
    
    // initWithBytes:deallocator:                         // !!!: Uncertain!
    MDL::MeshBufferMap*             init(const void* bytes, const void (^deallocator)(void));
    
    // - ReadOnly
    void*                           bytes() const;
};

// MARK: MeshBuffer

                        // !!!: Uncertain
// Protocol
class MeshBuffer : public NS::Copying<MeshBuffer> /*, NS::Referencing<MeshBuffer>*/
{
public:
    // fillData:offset:
    void                            fillData(const NS::Data* data, NS::UInteger offset);
    
    // map
    MDL::MeshBuffer*                map();
    
    // - ReadOnly
    NS::UInteger                    length() const;
    
    // - ReadOnly
    class MeshBufferAllocator*      allocator() const;
    
    // - ReadOnly
    class MeshBufferZone*           zone() const;
    
    // - ReadOnly   // !!!: Uncertain!
    MeshBufferType                  type() const;
};

// MARK: MeshBufferData

// class
class MeshBufferData : public NS::Referencing<MeshBufferData>
{
public:
    static class MeshBufferData*        alloc();

    // initWithType:length
    MDL::MeshBufferData*                init(const MDL::MeshBufferType type, NS::UInteger length);
    
    // - ReadOnly
    NS::Data*                           data() const;
};

// MARK: MeshBufferZone

// Protocol
class MeshBufferZone : public NS::Referencing<MeshBufferZone>
{
public:
    // - ReadOnly
    NS::UInteger                        capacity() const;
    
    // - ReadOnly
    class MeshBufferAllocator*          allocator() const;
};

// MARK: MeshBufferAllocator

// protocol
class MeshBufferAllocator : public NS::Referencing<MeshBufferAllocator>
{
public:
    // newZone:
    class MeshBufferZone*                   newZone(NS::UInteger capacity);
    
    // newZoneForBuffersWithSize:andType:
    class MeshBufferZone*                   newZoneForBuffersWithSize(const NS::Array* sizes, const NS::Array* types);
    
    // newBuffer:type:
    class MeshBuffer*                       newBuffer(NS::UInteger length, MDL::MeshBufferType type);
    
    // newBufferWithData:type:
    class MeshBuffer*                       newBufferWithData(const NS::Data* data, MDL::MeshBufferType type);
    
    // newBufferFromZone:length:type:
    class MeshBuffer*                       newBufferFromZone(const MDL::MeshBufferZone* zone, NS::UInteger length, MDL::MeshBufferType type);
    
    // newBufferFromZone:data:type:
    class MeshBuffer*                       newBufferFromZone(const MDL::MeshBufferZone* zone, const NS::Data* data, MDL::MeshBufferType type);
};

// MARK: MeshBufferDataAllocator

class MeshBufferDataAllocator : public NS::Referencing<MeshBufferAllocator>
{
public:
    static class MeshBufferDataAllocator*       alloc();
    
    class MeshBufferDataAllocator*              init();
};

// MARK: MeshBufferZoneDefault

class MeshBufferZoneDefault : public NS::Referencing<MeshBufferZone>
{
public:
    static class MeshBufferZoneDefault*     alloc();
    
    class MeshBufferZoneDefault*            init();
    
    // - ReadOnly
    NS::UInteger                            capacity() const;
    
    // - ReadOnly
    class MeshBufferAllocator*              allocator() const;
};

}

// MARK: - Private Sector

// static method: alloc
_MDL_INLINE MDL::MeshBufferMap* MDL::MeshBufferMap::alloc()
{
    return NS::Object::alloc<MDL::MeshBufferMap>(_MDL_PRIVATE_CLS(MDLMeshBufferMap));
}

// method: initWithBytes:deallocator:
_MDL_INLINE MDL::MeshBufferMap* MDL::MeshBufferMap::init(const void* bytes, const void (^deallocator)(void))
{
    return Object::sendMessage<MDL::MeshBufferMap*>(this, _MDL_PRIVATE_SEL(initWithBytes_deallocator_), bytes, deallocator);
}

// property: bytes
_MDL_INLINE void* MDL::MeshBufferMap::bytes() const
{
    return Object::sendMessage<void*>(this, _MDL_PRIVATE_SEL(bytes));
}

// MARK: Protocol MeshBuffer

// method: fillData:offset:
_MDL_INLINE void MDL::MeshBuffer::fillData(const NS::Data* data, NS::UInteger offset)
{
    return Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(fillData_offset_), data, offset);
}

// property: length
_MDL_INLINE NS::UInteger MDL::MeshBuffer::length() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(length));
}

// property: allocator
_MDL_INLINE MDL::MeshBufferAllocator* MDL::MeshBuffer::allocator() const
{
    return Object::sendMessage<MDL::MeshBufferAllocator*>(this, _MDL_PRIVATE_SEL(allocator));
}

// property: zone
_MDL_INLINE MDL::MeshBufferZone* MDL::MeshBuffer::zone() const
{
    return Object::sendMessage<MDL::MeshBufferZone*>(this, _MDL_PRIVATE_SEL(zone));
}

// property: type
_MDL_INLINE MDL::MeshBufferType MDL::MeshBuffer::type() const
{
    return Object::sendMessage<MDL::MeshBufferType>(this, _MDL_PRIVATE_SEL(type));
}

// MARK: MeshBufferData

// static method: alloc
_MDL_INLINE MDL::MeshBufferData* MDL::MeshBufferData::alloc()
{
    return NS::Object::alloc<MDL::MeshBufferData>(_MDL_PRIVATE_CLS(MDLMeshBufferData));
}

// method: initWithType:length
_MDL_INLINE MDL::MeshBufferData* MDL::MeshBufferData::init(const MDL::MeshBufferType type, NS::UInteger length)
{
    return Object::sendMessage<MDL::MeshBufferData*>(this, _MDL_PRIVATE_SEL(initWithBytes_deallocator_), type, length);
}

// property: data
_MDL_INLINE NS::Data* MDL::MeshBufferData::data() const
{
    return Object::sendMessage<NS::Data*>(this, _MDL_PRIVATE_SEL(data));
}

// MARK: MeshBufferZone

// property: capacity
_MDL_INLINE NS::UInteger MDL::MeshBufferZone::capacity() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(capacity));
}

// property: allocator
_MDL_INLINE MDL::MeshBufferAllocator* MDL::MeshBufferZone::allocator() const
{
    return Object::sendMessage<MDL::MeshBufferAllocator*>(this, _MDL_PRIVATE_SEL(allocator));
}

// MARK: MeshBufferAllocator

// method: newZone:
_MDL_INLINE MDL::MeshBufferZone* MDL::MeshBufferAllocator::newZone(NS::UInteger capacity)
{
    return Object::sendMessage<MDL::MeshBufferZone*>(this, _MDL_PRIVATE_SEL(newZone_), capacity);
}

// method: newZoneForBuffersWithSize:andType:
_MDL_INLINE MDL::MeshBufferZone* MDL::MeshBufferAllocator::newZoneForBuffersWithSize(const NS::Array* sizes, const NS::Array* types)
{
    return Object::sendMessage<MDL::MeshBufferZone*>(this, _MDL_PRIVATE_SEL(newZoneForBuffersWithSize_andType_), sizes, types);
}

// method: newBuffer:type:
_MDL_INLINE MDL::MeshBuffer* MDL::MeshBufferAllocator::newBuffer(NS::UInteger length, MDL::MeshBufferType type)
{
    return Object::sendMessage<MDL::MeshBuffer*>(this, _MDL_PRIVATE_SEL(newBuffer_type_), length, type);
}

// method: newBufferWithData:type:
_MDL_INLINE MDL::MeshBuffer* MDL::MeshBufferAllocator::newBufferWithData(const NS::Data* data, MDL::MeshBufferType type)
{
    return Object::sendMessage<MDL::MeshBuffer*>(this, _MDL_PRIVATE_SEL(newBufferWithData_type_), data, type);
}

// method: newBufferFromZone:length:type:
_MDL_INLINE MDL::MeshBuffer* MDL::MeshBufferAllocator::newBufferFromZone(const MDL::MeshBufferZone* zone, NS::UInteger length, MDL::MeshBufferType type)
{
    return Object::sendMessage<MDL::MeshBuffer*>(this, _MDL_PRIVATE_SEL(newBufferFromZone_length_type_), zone, length, type);
}

// method: newBufferFromZone:data:type:
_MDL_INLINE MDL::MeshBuffer* MDL::MeshBufferAllocator::newBufferFromZone(const MDL::MeshBufferZone* zone, const NS::Data* data, MDL::MeshBufferType type)
{
    return Object::sendMessage<MDL::MeshBuffer*>(this, _MDL_PRIVATE_SEL(newBufferFromZone_length_type_), zone, data, type);
}

// MARK: MeshBufferDataAllocator

// static method: alloc
_MDL_INLINE MDL::MeshBufferDataAllocator* MDL::MeshBufferDataAllocator::alloc()
{
    return NS::Object::alloc<MDL::MeshBufferDataAllocator>(_MDL_PRIVATE_CLS(MDLMeshBufferDataAllocator));
}

// method: init
_MDL_INLINE MDL::MeshBufferDataAllocator* MDL::MeshBufferDataAllocator::init()
{
    return NS::Object::init<MDL::MeshBufferDataAllocator>();
}

// MARK: MeshBufferZoneDefault

// static method: alloc
_MDL_INLINE MDL::MeshBufferZoneDefault* MDL::MeshBufferZoneDefault::alloc()
{
    return NS::Object::alloc<MDL::MeshBufferZoneDefault>(_MDL_PRIVATE_CLS(MDLMeshBufferZoneDefault));
}

// method: init
_MDL_INLINE MDL::MeshBufferZoneDefault* MDL::MeshBufferZoneDefault::init()
{
    return NS::Object::init<MDL::MeshBufferZoneDefault>();
}

// property: capacity
_MDL_INLINE NS::UInteger MDL::MeshBufferZoneDefault::capacity() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(capacity));
}

// property: allocator
_MDL_INLINE MDL::MeshBufferAllocator* MDL::MeshBufferZoneDefault::allocator() const
{
    return Object::sendMessage<MeshBufferAllocator*>(this, _MDL_PRIVATE_SEL(allocator));
}



// MARK: - Original Header -

//#import <Foundation/Foundation.h>
//#import <ModelIO/ModelIOExports.h>
//#import <ModelIO/MDLTypes.h>
//
//NS_ASSUME_NONNULL_BEGIN
//
///*!
// @enum MDLMeshBufferType
// @abstract Type of data a MDLMeshBuffer has been allocated for
// */
//typedef NS_ENUM(NSUInteger, MDLMeshBufferType) {
//    MDLMeshBufferTypeVertex = 1,
//    MDLMeshBufferTypeIndex = 2,
//    MDLMeshBufferTypeCustom = 3,
//};

//@protocol MDLMeshBuffer;
//@protocol MDLMeshBufferAllocator;
//@protocol MDLMeshBufferZone;

/*!
 @class MDLMeshBufferMap
 @abstract Represents a reference to memory of a mapped MeshBuffer
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLMeshBufferMap : NSObject

/*!
 @method initWithBytes:deallocator:
 @abstract Called by implementor of MDLMeshBuffer protocol to create the map
           and arrange for unmapping on deallocation.
 */
//-(instancetype) initWithBytes:(void*)bytes
//                  deallocator:(nullable void (^)(void))deallocator;

/*!
 @property bytes
 @abstract Mutable pointer to data in a MDLMeshBuffer object.
 */
//@property (nonatomic, readonly) void *bytes;
//
//@end

// MARK: - MeshBuffer

/*!
 @protocol MDLMeshBuffer
 @abstract Used by ModelIO to represent a buffer to be filled with vertex and
           index data
 @discussion Supports deep copy of data by conforming to the NSCopying protocol
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//@protocol MDLMeshBuffer <NSObject, NSCopying>

/*!
 @method fillData:offset:
 @abstract Fills buffer with data at offset
 @param data Data to fill buffer with
 @param offset Byte offset in buffer to begin filling data
 @discussion Fills data.length bytes of data.  Will not write beyond length of
             this buffer.
 */
//- (void)fillData:(NSData *)data offset:(NSUInteger)offset;

/*!
 @method map
 @abstract CPU access to buffer's memory
 @return An MDLMeshBufferMap object to read or modify a buffer's memory
 @discussion The buffer will remain mapped as long as the returned MDLMeshBufferMap
             object exists. Mapping a buffer may impose restrictions on a system.
             For instance,  if the implementing class maps an OpenGL buffer, that
             buffer may be  unavailable for rendering while mapped, and cause a
             draw failure.  Precautions must be taken in such cases.
 */
//- (MDLMeshBufferMap *)map;

/*!
 @property length
 @abstract Size in bytes of the buffer allocation
 */
//@property (nonatomic, readonly) NSUInteger length;

/*!
 @property allocator
 @abstract Allocator object used to create this buffer.
 @discussion This allcoator used for copy and relayout operations (such as when
             a new vertex descriptor is applied to a vertex buffer)
 */
//@property (nonatomic, readonly, retain) id<MDLMeshBufferAllocator> allocator;

/*!
 @property zone
 @abstract Zone from which this buffer was created
 @discussion This zone will be used for copy and relayout operations (such as
             when a new vertex descriptor is applied to a vertex buffer).  If
             the default zone is used this will be nil.
 */
//@property (nonatomic, readonly, retain) id<MDLMeshBufferZone> zone;

/*!
 @property type
 @abstract the intended type of the buffer
 */
//@property (nonatomic, readonly) MDLMeshBufferType type;
//
//@end

// MARK: - MeshBufferData

/*!
 @class MDLMeshBufferData
 @abstract A CPU memory backed mesh buffer
 */

//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLMeshBufferData : NSObject <MDLMeshBuffer>

/*!
 @method initWithType:length
 @abstract instantiate a new data backed mesh buffer
 @param type the intended use of the buffer
 @param length the size of buffer to allocate, in bytes
 */
//- (instancetype)initWithType:(MDLMeshBufferType)type length:(NSUInteger)length;

/*!
 @method initWithType:data
 @abstract instantiate a new data backed mesh buffer
 @param type the intended use of the buffer
 @param data the data to be used as a mesh buffer. It will be copied.
 */
//- (instancetype)initWithType:(MDLMeshBufferType)type data:(nullable NSData*)data;

//@property (nonatomic, readonly, retain) NSData *data;
//
//@end



// MARK: - MeshBufferZone

/*!
 @protocol MDLMeshBufferZone
 @abstract A reference to a logical pool of memory from which mesh buffers would
           be allocated
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//@protocol MDLMeshBufferZone <NSObject>

/*!
 @property capacity
 @abstract Total size of memory in the zone
 */
//@property (nonatomic, readonly) NSUInteger capacity;

/*!
 @property allocator
 @abstract Allocator used to create the zone
 */
//@property (nonatomic, readonly) id<MDLMeshBufferAllocator> allocator;
//
//@end


// MARK: -  MeshBufferAllocator

/*!
 @protocol MDLMeshBufferAllocator
 @abstract Object for allocating buffers to back vertex and index data
 @discussion Accepted by MDLAsset init method.  Implementor creates objects
             implementing MDLMeshBuffer with memory to be filled with vertex and
             index data during 3d file loading and parsing.
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//@protocol MDLMeshBufferAllocator <NSObject>

/*!
 @method newZone:
 @abstract Create a zone which can be used to allocate MDLMeshBuffer objects
 @param capacity Total size in bytes of all buffers which can be created from
        this zone
 */
//-(id<MDLMeshBufferZone>)newZone:(NSUInteger)capacity;

/*!
 @method newZoneForBuffersWithSize:andType:
 @abstract Create a zone which can be used to allocate MDLMeshBuffer objects
 @param sizes Sizes of each buffer to be created in this zone
 @param types Type of each buffer to be created in this zone. Values to be of
              MDLMeshBufferType
 @discussion Will create a zone from which MDLMeshBuffer objects can be
             allocated.  This will allocate a zone with enough capacity
             for each of the buffers with sizes and types specified even taking
             into any alignment restrictions necessary to use these buffers.
 */
//-(id<MDLMeshBufferZone>)newZoneForBuffersWithSize:(NSArray<NSNumber*>*)sizes
//                                          andType:(NSArray<NSNumber*>*)types;

/*!
 @method newBuffer:type:
 @abstract Create a buffer in a default zone
 @param length Size of buffer to be created in bytes
 @param type Type of data to be stored in this buffer
 */
//-(id<MDLMeshBuffer>)newBuffer:(NSUInteger)length
//                        type:(MDLMeshBufferType)type;
/*!
 @method newBufferWithData:type:
 @abstract Create a buffer in a default zone and fill with data in the supplied
           NSData object
 @param data Memory to fill the buffer with
 @param type Type of data to be stored in this buffer
 */
//-(id<MDLMeshBuffer>)newBufferWithData:(NSData *)data
//                                type:(MDLMeshBufferType)type;

/*!
 @method newBufferFromZone:length:type:
 @abstract Create a buffer from a given zone with the given length
 @return An object conforming to the MDLMeshBuffer protocol.  Returns nil the
         buffer could not be allocated in the zone given.
 @param zone Zone from which to allocate the memory
 @param type Type of data to be stored in this buffer
 @discussion An implementing MDLMeshBufferAllocator object may increase the size
             of the zone if the buffer could not be allocated with the current
             zone size.  Alternatively the implementation may return nil if the
             buffer could not be allocated.

 */
//-(nullable id<MDLMeshBuffer>)newBufferFromZone:(nullable id<MDLMeshBufferZone>)zone
//                                       length:(NSUInteger)length
//                                         type:(MDLMeshBufferType)type;

/*!
 @method newBufferFromZone:data:type:
 @abstract Create a buffer from a given zone and fill with data in the supplied
           NSData object
 @return An object conforming to the MDLMeshBuffer protocol.  Returns nil the
         buffer could not be allocated in the given zone
 @param zone Zone from which to allocate the memory
 @param data Values with which to fill the buffer
 @param type Type of data to be stored in this buffer
 @discussion An implementing MDLMeshBufferAllocator object may increase the size
             of the zone if the buffer could not be allocated with the current
             zone size. Alternatively the implementation may return nil if the
             buffer could not be allocated.
 */
//-(nullable id<MDLMeshBuffer>)newBufferFromZone:(nullable id<MDLMeshBufferZone>)zone
//                                         data:(NSData *)data
//                                         type:(MDLMeshBufferType)type;

//@end


// MARK: - MeshBufferDataAllocator

/*!
 An allocator to use when backing with an NSData is appropriate.
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLMeshBufferDataAllocator: NSObject <MDLMeshBufferAllocator>
//
//@end

// MARK: - MeshBufferZoneDefault

/*!
 A default zone that can be use for convenience
 */
//API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0))
//MDL_EXPORT
//@interface MDLMeshBufferZoneDefault : NSObject <MDLMeshBufferZone>

//@property (nonatomic, readonly) NSUInteger capacity;
//@property (nonatomic, readonly, retain) id<MDLMeshBufferAllocator> allocator;
//
//@end
//
//NS_ASSUME_NONNULL_END


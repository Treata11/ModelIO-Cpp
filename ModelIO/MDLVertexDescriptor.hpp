/*!
 @header MDLVertexDescriptor.hpp
 @framework ModelIO
 @abstract Structures for describing layout of vertex data in buffers
 @copyright Treata Norouzi on 8/13/24.
 */


#import <Foundation/Foundation.hpp>
#include "ModelIOExports.hpp"
#include "MDLMeshBuffer.hpp"
#import <simd/simd.h>

namespace MDL
{

_NS_CONST(NS::String*, MDLVertexAttributeAnisotropy);

_NS_CONST(NS::String*, MDLVertexAttributeBinormal);

_NS_CONST(NS::String*, MDLVertexAttributeBitangent);

_NS_CONST(NS::String*, MDLVertexAttributeColor);

_NS_CONST(NS::String*, MDLVertexAttributeEdgeCrease);

_NS_CONST(NS::String*, MDLVertexAttributeJointIndices);

_NS_CONST(NS::String*, MDLVertexAttributeJointWeights);

_NS_CONST(NS::String*, MDLVertexAttributeNormal);

_NS_CONST(NS::String*, MDLVertexAttributeOcclusionValue);

_NS_CONST(NS::String*, MDLVertexAttributePosition);

_NS_CONST(NS::String*, MDLVertexAttributeShadingBasisU);

_NS_CONST(NS::String*, MDLVertexAttributeShadingBasisV);

_NS_CONST(NS::String*, MDLVertexAttributeSubdivisionStencil);

_NS_CONST(NS::String*, MDLVertexAttributeTangent);

_NS_CONST(NS::String*, MDLVertexAttributeTextureCoordinate);


_MDL_ENUM(NS::UInteger, VertexFormat) {
    VertexFormatInvalid = 0,
    
    VertexFormatPackedBit = 0x1000,

    VertexFormatUCharBits = 0x10000,
    VertexFormatCharBits = 0x20000,
    VertexFormatUCharNormalizedBits = 0x30000,
    VertexFormatCharNormalizedBits = 0x40000,
    VertexFormatUShortBits = 0x50000,
    VertexFormatShortBits = 0x60000,
    VertexFormatUShortNormalizedBits = 0x70000,
    VertexFormatShortNormalizedBits = 0x80000,
    VertexFormatUIntBits = 0x90000,
    VertexFormatIntBits = 0xA0000,
    VertexFormatHalfBits = 0xB0000,
    VertexFormatFloatBits = 0xC0000,
    
    VertexFormatUChar =  VertexFormatUCharBits | 1,
    VertexFormatUChar2 = VertexFormatUCharBits | 2,
    VertexFormatUChar3 = VertexFormatUCharBits | 3,
    VertexFormatUChar4 = VertexFormatUCharBits | 4,

    VertexFormatChar =  VertexFormatCharBits | 1,
    VertexFormatChar2 = VertexFormatCharBits | 2,
    VertexFormatChar3 = VertexFormatCharBits | 3,
    VertexFormatChar4 = VertexFormatCharBits | 4,

    VertexFormatUCharNormalized =  VertexFormatUCharNormalizedBits | 1,
    VertexFormatUChar2Normalized = VertexFormatUCharNormalizedBits | 2,
    VertexFormatUChar3Normalized = VertexFormatUCharNormalizedBits | 3,
    VertexFormatUChar4Normalized = VertexFormatUCharNormalizedBits | 4,

    VertexFormatCharNormalized =  VertexFormatCharNormalizedBits | 1,
    VertexFormatChar2Normalized = VertexFormatCharNormalizedBits | 2,
    VertexFormatChar3Normalized = VertexFormatCharNormalizedBits | 3,
    VertexFormatChar4Normalized = VertexFormatCharNormalizedBits | 4,

    VertexFormatUShort =  VertexFormatUShortBits | 1,
    VertexFormatUShort2 = VertexFormatUShortBits | 2,
    VertexFormatUShort3 = VertexFormatUShortBits | 3,
    VertexFormatUShort4 = VertexFormatUShortBits | 4,

    VertexFormatShort =  VertexFormatShortBits | 1,
    VertexFormatShort2 = VertexFormatShortBits | 2,
    VertexFormatShort3 = VertexFormatShortBits | 3,
    VertexFormatShort4 = VertexFormatShortBits | 4,

    VertexFormatUShortNormalized =  VertexFormatUShortNormalizedBits | 1,
    VertexFormatUShort2Normalized = VertexFormatUShortNormalizedBits | 2,
    VertexFormatUShort3Normalized = VertexFormatUShortNormalizedBits | 3,
    VertexFormatUShort4Normalized = VertexFormatUShortNormalizedBits | 4,

    VertexFormatShortNormalized =  VertexFormatShortNormalizedBits | 1,
    VertexFormatShort2Normalized = VertexFormatShortNormalizedBits | 2,
    VertexFormatShort3Normalized = VertexFormatShortNormalizedBits | 3,
    VertexFormatShort4Normalized = VertexFormatShortNormalizedBits | 4,

    VertexFormatUInt =  VertexFormatUIntBits | 1,
    VertexFormatUInt2 = VertexFormatUIntBits | 2,
    VertexFormatUInt3 = VertexFormatUIntBits | 3,
    VertexFormatUInt4 = VertexFormatUIntBits | 4,

    VertexFormatInt =  VertexFormatIntBits | 1,
    VertexFormatInt2 = VertexFormatIntBits | 2,
    VertexFormatInt3 = VertexFormatIntBits | 3,
    VertexFormatInt4 = VertexFormatIntBits | 4,

    VertexFormatHalf =  VertexFormatHalfBits | 1,
    VertexFormatHalf2 = VertexFormatHalfBits | 2,
    VertexFormatHalf3 = VertexFormatHalfBits | 3,
    VertexFormatHalf4 = VertexFormatHalfBits | 4,

    VertexFormatFloat =  VertexFormatFloatBits | 1,
    VertexFormatFloat2 = VertexFormatFloatBits | 2,
    VertexFormatFloat3 = VertexFormatFloatBits | 3,
    VertexFormatFloat4 = VertexFormatFloatBits | 4,

    VertexFormatInt1010102Normalized =  VertexFormatIntBits  | VertexFormatPackedBit | 4,
    VertexFormatUInt1010102Normalized = VertexFormatUIntBits | VertexFormatPackedBit | 4
};

// MARK: VertexBufferLayout

class VertexBufferLayout : public NS::Copying<VertexBufferLayout>
{
public:
    static class VertexBufferLayout*    alloc();
    
    // initWithStride:stride:
    MDL::VertexBufferLayout*            init(const NS::UInteger stride);
    
    // Read&Write
    NS::UInteger*                        stride() const;
    void                                 setStride(const NS::UInteger* stride);
};

// MARK: VertexAttribute

class VertexAttribute : public NS::Copying<VertexAttribute>
{
public:
    static class VertexAttribute*   alloc();
    
    // initWithName:format:offset:bufferIndex
    MDL::VertexAttribute*           init(const NS::String* name, const VertexFormat format, const NS::UInteger offset, const NS::UInteger bufferIndex);
    
    // copy                     // !!!: Uncertain
    NS::String*                     name() const;
    void                            setName(const NS::String* name);
    
    // Read&Write
    VertexFormat                    format() const;
    void                            setFormat(const VertexFormat format);
    
    // Read&Write
    NS::UInteger                    offset() const;
    void                            setOffset(const NS::UInteger offset);
    
    // Read&Write
    NS::UInteger                    bufferIndex() const;
    void                            setBufferIndex(const NS::UInteger bufferIndex);
    
    // Read&Write
    NS::TimeInterval                time() const;
    void                            setTime(const NS::TimeInterval time);
    
    // Read&Write
    vector_float4                   initializationValue() const;
    void                            setInitializationValue(const vector_float4 initializationValue);
};

// MARK:

class VertexDescriptor : public NS::Copying<VertexDescriptor>
{
public:
    static class VertexDescriptor*  alloc();
    
    // initVertexDescriptor:
    MDL::VertexDescriptor*          init(const MDL::VertexDescriptor* vertexDescriptor);
    
    // attributeNamed:
    class VertexAttribute*          attributeNamed(const NS::String* name);
    
    // addOrReplaceAttribute:
    void                            addOrReplaceAttribute(const MDL::VertexAttribute* attribute);
    
    // removeAttributeNamed:
    void                            removeAttributeNamed(const NS::String* name);
    
    // !!!: NSMutableArray is not ported to Cpp!
    NS::Array*                      attributes() const;
    
    // !!!: NSMutableArray is not ported to Cpp!
    NS::Array*                      layouts() const;
    
    void                            reset();
    
    void                            setPackedStrides();
    
    void                            setPackedOffsets();
};

}

// MARK: - Private Sector

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeAnisotropy);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeBinormal);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeBitangent);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeColor);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeEdgeCrease);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeJointIndices);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeJointWeights);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeNormal);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeOcclusionValue);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributePosition);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeShadingBasisU);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeShadingBasisV);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeSubdivisionStencil);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeTangent);

_NS_PRIVATE_DEF_CONST(NS::String*, MDLVertexAttributeTextureCoordinate);

//------------------------------------------------------------------------------

// static method: alloc
_MDL_INLINE MDL::VertexBufferLayout* MDL::VertexBufferLayout::alloc()
{
    return NS::Object::alloc<MDL::VertexBufferLayout>(_MDL_PRIVATE_CLS(MDLVertexBufferLayout));
}

// method: initWithStride:stride:
_MDL_INLINE MDL::VertexBufferLayout* MDL::VertexBufferLayout::init(const NS::UInteger stride)
{
    return Object::sendMessage<MDL::VertexBufferLayout*>(this, _MDL_PRIVATE_SEL(initWithStride_stride_), stride);
}

// property: stride
_MDL_INLINE NS::UInteger* MDL::VertexBufferLayout::stride() const
{
    return Object::sendMessage<NS::UInteger*>(this, _MDL_PRIVATE_SEL(stride));
}
// write method: setStrides:
_MDL_INLINE void MDL::VertexBufferLayout::setStride(const NS::UInteger* stride)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setStride_), stride);
}

// static method: alloc
_MDL_INLINE MDL::VertexAttribute* MDL::VertexAttribute::alloc()
{
    return NS::Object::alloc<MDL::VertexAttribute>(_MDL_PRIVATE_CLS(MDLVertexAttribute));
}

// initWithName:format:offset:bufferIndex:
_MDL_INLINE MDL::VertexAttribute* MDL::VertexAttribute::init(const NS::String* name, const VertexFormat format, const NS::UInteger offset, const NS::UInteger bufferIndex)
{
    return Object::sendMessage<MDL::VertexAttribute*>(this, _MDL_PRIVATE_SEL(initWithName_format_offset_bufferIndex_), name, format, offset, bufferIndex);
}

// property: name
_MDL_INLINE NS::String* MDL::VertexAttribute::name() const
{
    return Object::sendMessage<NS::String*>(this, _MDL_PRIVATE_SEL(name));
}
// write method: setName:
_MDL_INLINE void MDL::VertexAttribute::setName(const NS::String* name)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setName_), name);
}

// property: format
_MDL_INLINE MDL::VertexFormat MDL::VertexAttribute::format() const
{
    return Object::sendMessage<MDL::VertexFormat>(this, _MDL_PRIVATE_SEL(format));
}
// write method: setFormat:
_MDL_INLINE void MDL::VertexAttribute::setFormat(const MDL::VertexFormat format)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setFormat_), format);
}

// property: offset
_MDL_INLINE NS::UInteger MDL::VertexAttribute::offset() const
{
    return Object::sendMessage<NS::UInteger>(this, _MDL_PRIVATE_SEL(offset));
}
// write method: setOffset:
_MDL_INLINE void MDL::VertexAttribute::setOffset(const NS::UInteger offset)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setOffset_), offset);
}

// property: time
_MDL_INLINE NS::TimeInterval MDL::VertexAttribute::time() const
{
    return Object::sendMessage<NS::TimeInterval>(this, _MDL_PRIVATE_SEL(time));
}
// write method: setTime:
_MDL_INLINE void MDL::VertexAttribute::setTime(const NS::TimeInterval time)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setTime_), time);
}

// property: initializationValue
_MDL_INLINE vector_float4 MDL::VertexAttribute::initializationValue() const
{
    return Object::sendMessage<vector_float4>(this, _MDL_PRIVATE_SEL(initializationValue));
}
// write method: setInitializationValue:
_MDL_INLINE void MDL::VertexAttribute::setInitializationValue(const vector_float4 initializationValue)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setInitializationValue_), initializationValue);
}

// static method: alloc
_MDL_INLINE MDL::VertexDescriptor* MDL::VertexDescriptor::alloc()
{
    return NS::Object::alloc<MDL::VertexDescriptor>(_MDL_PRIVATE_CLS(MDLVertexDescriptor));
}

// initVertexDescriptor:
_MDL_INLINE MDL::VertexDescriptor* MDL::VertexDescriptor::init(const MDL::VertexDescriptor* vertexDescriptor)
{
    return Object::sendMessage<MDL::VertexDescriptor*>(this, _MDL_PRIVATE_SEL(initVertexDescriptor_), vertexDescriptor);
}

// method: attributeNamed:
_MDL_INLINE MDL::VertexAttribute* MDL::VertexDescriptor::attributeNamed(const NS::String* name)
{
    return Object::sendMessage<MDL::VertexAttribute*>(this, _MDL_PRIVATE_SEL(attributeNamed_), name);
}

// method: addOrReplaceAttribute:
_MDL_INLINE void MDL::VertexDescriptor::addOrReplaceAttribute(const MDL::VertexAttribute* attribute)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(addOrReplaceAttribute_), attribute);
}

// method: removeAttributeNamed:
_MDL_INLINE void MDL::VertexDescriptor::removeAttributeNamed(const NS::String* name)
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(removeAttributeNamed_), name);
}

// TODO: attributes

// TODO: layouts

// method: reset:
_MDL_INLINE void MDL::VertexDescriptor::reset()
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(reset_));
}

// method: setPackedStrides:
_MDL_INLINE void MDL::VertexDescriptor::setPackedStrides()
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setPackedStrides_));
}

// method: setPackedOffsets:
_MDL_INLINE void MDL::VertexDescriptor::setPackedOffsets()
{
    Object::sendMessage<void>(this, _MDL_PRIVATE_SEL(setPackedOffsets_));
}


// MARK: - Original Header


//#import <Foundation/Foundation.h>
//#import "ModelIOExports.h"
//#import "MDLMeshBuffer.h"
//#import <simd/simd.h>
//
//NS_ASSUME_NONNULL_BEGIN

/*!
 @group Default MDLVertexAttribute Names
 @abstract Default names for common vertex attribute types
 @discussion

 These are names that are created during 3d asset file loading to correspond
 to data found in those files.
 */

/*! The attribute data describes the degree to which a surface’s appearance
    changes in appearance when rotated about its normal vector. */
//MDL_EXPORT NSString * const MDLVertexAttributeAnisotropy;
//
///*! The normal to a curve at a vertex position */
//MDL_EXPORT NSString * const MDLVertexAttributeBinormal;
//
///*! The vector completing a tangent basis at a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeBitangent;
//
///*! Color of a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeColor;

/*! A crease value along an edge to be applied during subdivision.
    A zero value indicates an edge is smooth, one is sharply creased. */
//MDL_EXPORT NSString * const MDLVertexAttributeEdgeCrease;
//
///*! Indices of joints in an animation rig corresponding to weighting information */
//MDL_EXPORT NSString * const MDLVertexAttributeJointIndices;
//
///*! Weights corresponding to joints for the purpose of blending animation */
//MDL_EXPORT NSString * const MDLVertexAttributeJointWeights;
//
///*! The direction of a normal at a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeNormal;

/*! A value indicating the degree to which a vertex is occluded by surrounding geometry */
//MDL_EXPORT NSString * const MDLVertexAttributeOcclusionValue;
//
///*! The position of a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributePosition;
//
///*! The u direction of a shading basis at a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeShadingBasisU;
//
///*! The v direction of a shading basis at a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeShadingBasisV;

/*! Stencil values for subdivision at a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeSubdivisionStencil;
//
///*! A vector tangent to a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeTangent;
//
///*! Texture coordinate mapping at a vertex */
//MDL_EXPORT NSString * const MDLVertexAttributeTextureCoordinate;


/*!
 @enum MDLVertexFormat
 @abstract Describes the format of a an attribute in a vertex buffer
 @discussion Designed to be very similar to MTLVertexDescriptor to ease the
             translation from one to the other. Values are chosen such that
             packed types would all be less than 0x1000 and the bottom 5 bits
             can be used to determine the number of channels/components in the
             format.
 */
//typedef NS_ENUM(NSUInteger, MDLVertexFormat)
//{
//    MDLVertexFormatInvalid = 0,
//    
//    MDLVertexFormatPackedBit = 0x1000,
//
//    MDLVertexFormatUCharBits = 0x10000,
//    MDLVertexFormatCharBits = 0x20000,
//    MDLVertexFormatUCharNormalizedBits = 0x30000,
//    MDLVertexFormatCharNormalizedBits = 0x40000,
//    MDLVertexFormatUShortBits = 0x50000,
//    MDLVertexFormatShortBits = 0x60000,
//    MDLVertexFormatUShortNormalizedBits = 0x70000,
//    MDLVertexFormatShortNormalizedBits = 0x80000,
//    MDLVertexFormatUIntBits = 0x90000,
//    MDLVertexFormatIntBits = 0xA0000,
//    MDLVertexFormatHalfBits = 0xB0000,
//    MDLVertexFormatFloatBits = 0xC0000,
//    
//    MDLVertexFormatUChar =  MDLVertexFormatUCharBits | 1,
//    MDLVertexFormatUChar2 = MDLVertexFormatUCharBits | 2,
//    MDLVertexFormatUChar3 = MDLVertexFormatUCharBits | 3,
//    MDLVertexFormatUChar4 = MDLVertexFormatUCharBits | 4,
//
//    MDLVertexFormatChar =  MDLVertexFormatCharBits | 1,
//    MDLVertexFormatChar2 = MDLVertexFormatCharBits | 2,
//    MDLVertexFormatChar3 = MDLVertexFormatCharBits | 3,
//    MDLVertexFormatChar4 = MDLVertexFormatCharBits | 4,
//
//    MDLVertexFormatUCharNormalized =  MDLVertexFormatUCharNormalizedBits | 1,
//    MDLVertexFormatUChar2Normalized = MDLVertexFormatUCharNormalizedBits | 2,
//    MDLVertexFormatUChar3Normalized = MDLVertexFormatUCharNormalizedBits | 3,
//    MDLVertexFormatUChar4Normalized = MDLVertexFormatUCharNormalizedBits | 4,
//
//    MDLVertexFormatCharNormalized =  MDLVertexFormatCharNormalizedBits | 1,
//    MDLVertexFormatChar2Normalized = MDLVertexFormatCharNormalizedBits | 2,
//    MDLVertexFormatChar3Normalized = MDLVertexFormatCharNormalizedBits | 3,
//    MDLVertexFormatChar4Normalized = MDLVertexFormatCharNormalizedBits | 4,
//
//    MDLVertexFormatUShort =  MDLVertexFormatUShortBits | 1,
//    MDLVertexFormatUShort2 = MDLVertexFormatUShortBits | 2,
//    MDLVertexFormatUShort3 = MDLVertexFormatUShortBits | 3,
//    MDLVertexFormatUShort4 = MDLVertexFormatUShortBits | 4,
//
//    MDLVertexFormatShort =  MDLVertexFormatShortBits | 1,
//    MDLVertexFormatShort2 = MDLVertexFormatShortBits | 2,
//    MDLVertexFormatShort3 = MDLVertexFormatShortBits | 3,
//    MDLVertexFormatShort4 = MDLVertexFormatShortBits | 4,
//
//    MDLVertexFormatUShortNormalized =  MDLVertexFormatUShortNormalizedBits | 1,
//    MDLVertexFormatUShort2Normalized = MDLVertexFormatUShortNormalizedBits | 2,
//    MDLVertexFormatUShort3Normalized = MDLVertexFormatUShortNormalizedBits | 3,
//    MDLVertexFormatUShort4Normalized = MDLVertexFormatUShortNormalizedBits | 4,
//
//    MDLVertexFormatShortNormalized =  MDLVertexFormatShortNormalizedBits | 1,
//    MDLVertexFormatShort2Normalized = MDLVertexFormatShortNormalizedBits | 2,
//    MDLVertexFormatShort3Normalized = MDLVertexFormatShortNormalizedBits | 3,
//    MDLVertexFormatShort4Normalized = MDLVertexFormatShortNormalizedBits | 4,
//
//    MDLVertexFormatUInt =  MDLVertexFormatUIntBits | 1,
//    MDLVertexFormatUInt2 = MDLVertexFormatUIntBits | 2,
//    MDLVertexFormatUInt3 = MDLVertexFormatUIntBits | 3,
//    MDLVertexFormatUInt4 = MDLVertexFormatUIntBits | 4,
//
//    MDLVertexFormatInt =  MDLVertexFormatIntBits | 1,
//    MDLVertexFormatInt2 = MDLVertexFormatIntBits | 2,
//    MDLVertexFormatInt3 = MDLVertexFormatIntBits | 3,
//    MDLVertexFormatInt4 = MDLVertexFormatIntBits | 4,
//
//    MDLVertexFormatHalf =  MDLVertexFormatHalfBits | 1,
//    MDLVertexFormatHalf2 = MDLVertexFormatHalfBits | 2,
//    MDLVertexFormatHalf3 = MDLVertexFormatHalfBits | 3,
//    MDLVertexFormatHalf4 = MDLVertexFormatHalfBits | 4,
//
//    MDLVertexFormatFloat =  MDLVertexFormatFloatBits | 1,
//    MDLVertexFormatFloat2 = MDLVertexFormatFloatBits | 2,
//    MDLVertexFormatFloat3 = MDLVertexFormatFloatBits | 3,
//    MDLVertexFormatFloat4 = MDLVertexFormatFloatBits | 4,
//
//    MDLVertexFormatInt1010102Normalized =  MDLVertexFormatIntBits  | MDLVertexFormatPackedBit | 4,
//    MDLVertexFormatUInt1010102Normalized = MDLVertexFormatUIntBits | MDLVertexFormatPackedBit | 4
//};




/*!
 @class MDLVertexBufferLayout
 @abstract Describes a vertex buffer's layout
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLVertexBufferLayout : NSObject <NSCopying>
//
//- (instancetype) initWithStride:(NSUInteger) stride;
//
///*!
// @property stride
// @abstract stride in bytes of each vertex element in the buffer.
// @discussion - If you store multiple attributes interleaved in the vertex
//               buffer, the stride will be the sum of sizes of each attribute (and any padding).
//             - If you store multiple attributes non-interleaved (back to back),
//               the stride will be the size of an attribute (and all attributes are
//               required to have the same size).
// */
//@property (nonatomic, readwrite) NSUInteger stride;
//@end





/*!
 @class MDLVertexAttribute
 @abstract Structure with properties of a vertex attribute
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLVertexAttribute : NSObject <NSCopying>
//
///*!
// @method initWithName:format:offset:bufferIndex
// @abstract Initialize attribute object with all properties
// */
//- (instancetype) initWithName:(NSString *)name
//                       format:(MDLVertexFormat)format
//                       offset:(NSUInteger)offset
//                  bufferIndex:(NSUInteger)bufferIndex;
///*!
// @property name
// @abstract Identifying name of the attribute derived from model file, or one of
//           the predefined MDLVertexAttribute strings
// */
//@property (nonatomic, copy) NSString *name;

/*!
 @property format
 @abstract Format (including number of components) of the attribute
 @discussion If the value is MDLVertexFormatInvalid.   Other values of this
             object will be ignored when setting the MDLVertexDescriptor object
             in a Mesh. The initial value is MDLVertexFormatInvalid.
 */
//@property (nonatomic, readwrite) MDLVertexFormat format;
//
///*!
// @property offset
// @abstract offset in bytes of the attrbute in each element of the vertex buffer
// */
//@property (nonatomic, readwrite)  NSUInteger offset;
//
///*!
// @property bufferIndex
// @abstract index of the buffer in mesh's vertexBuffer array in which this
//           attribute resides
// */
//@property (nonatomic, readwrite) NSUInteger bufferIndex;

/*!
 @property time
 @abstract the time the attribute is intended for.
 @discussion morph targets would store their times here
 */
//@property (nonatomic, readwrite) NSTimeInterval time;
//
///*!
// @property initializationValue
// @abstract Value to initialize the attribute to in the vertex buffer if no values
// @discussion This values of this vector will be set in attribute in the vertex
// attribute if the attribute did not previously exist in the mesh when
// setting the MDLVertexDescriptor in the mesh.  Components of this
// vector will also be set in The initial value of initializationValue
// is (0, 0, 0, 1).
// */
//@property (nonatomic, readwrite) vector_float4 initializationValue;
//
//@end




/*!
 @class MDLVertexDescriptor
 @abstract Describes the layout of vertex buffers in MDLMesh objects
 @discussion This object is a property of MDLMesh describing the current state of
 attributes and buffer layouts of the vertex buffers in the mesh. This must be
 immutable otherwise even small changes could cause the buffers to be out of sync
 with the layout described here.
 
 Designed to be very similar to MTLVertexDescriptor to ease creation of one from
 the other
 */
//API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0))
//MDL_EXPORT
//@interface MDLVertexDescriptor : NSObject <NSCopying>
//
///*!
// @method initVertexDescriptor:
// @abstract Initializes the object with values from supplied vertexDescriptor
// @discussion This performs a deep copy of all data in the supplied descriptor.
// */
//-(instancetype) initWithVertexDescriptor:(MDLVertexDescriptor *)vertexDescriptor;
//
///*!
// @method attributeNamed:
// @abstract Retrieves the attribute with the given name
// @return The attribute with the supplied name or nil if attribute with the given
//         name does not exist in the descriptor object
// */
//-(nullable MDLVertexAttribute *)attributeNamed:(NSString*)name;

/*!
 @method addOrReplaceAttribute:
 @abstract Replace any attribute with the same name and time, or add it if it does not
           already exist.
 */
//- (void)addOrReplaceAttribute:(nonnull MDLVertexAttribute*)attribute;
//
///*!
// @method removeAttributeNamed:
// @abstract Remove the named attribute if it exists
// */
//- (void)removeAttributeNamed:(NSString*)name;

/*!
 @property attributes
 @abstract An array of MDLVertexAttribute objects
 @discussion ay describing the current attribute state of vertex buffers in an
             MDLMesh mesh
 */
//@property (nonatomic, retain) NSMutableArray<MDLVertexAttribute*> *attributes;
//
///*!
// @property layouts
// @abstract An array of MDLVertexBufferLayout
// @discussion An array describing the current layout state of vertex buffers in an
//             MDLMesh mesh
// */
//@property (nonatomic, retain) NSMutableArray<MDLVertexBufferLayout*> *layouts;

/*!
 @method reset
 @abstract Tesets the descriptor to initial values
 */
//- (void)reset;
//
///*!
// @method setPackedStrides
// @abstract Sets the stride in each VertexBufferLout in the layouts array to the
//           minimum value encompassing all attributes in the vertex buffer
// */
//- (void)setPackedStrides;
//
///*!
//  @method setPackedOffsets
//  @abstract Sets the stride in each VertexAttribute in the attributes array to
//            the minimum value to pack each attribute next to each other in its
//            vertexbuffer
//  */
//- (void)setPackedOffsets;
//
//@end
//
//NS_ASSUME_NONNULL_END

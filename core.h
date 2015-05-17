#ifndef CORE_H
#define CORE_H




#define MAX_INT 2147483647 
////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//

//
//  STD includes
//
#include <stdexcept>

//
//	Qt includes
//
#include <QtCore/QtGlobal>
#include <QtCore/qatomic.h>
#include <QtCore/QMetaType>
#include <QtCore/QObject>
#include <QtCore/QPointer>
#include <QtCore/QPair>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QVector>
#include <QtCore/QSet>
#include <QtCore/QHash>
#include <QtCore/QStack>
#include <QtCore/QQueue>
#include <QtCore/QByteArray>
#include <QtCore/QBitArray>
#include <QtCore/QVarLengthArray>
#include <QtCore/QLinkedList>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtCore/QDateTime>
#include <QtCore/QDataStream>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Macros Helpers
//
#if defined (QT_DEBUG)
#	define AD_ASSERT( _test_, _what_ ) Q_ASSERT_X( _test_, '\0', _what_ )
#elif defined (QT_NO_DEBUG)
#	define AD_ASSERT( _test_, _what_ ) ((void)(0))
#endif
////////////////////////////////////////////////////////////////////////////////

//
//	Type definitions
//
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long double longdouble;
typedef unsigned long long ulonglong;



////////////////////////////////////////////////////////////////////////////////
namespace dl { // data layer
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Common supported data types
//
typedef enum EDataType
{
    eDT_Invalid = 0,
    eDT_Bool,
    eDT_Char,
    eDT_Short,
    eDT_Int,
    eDT_LongInt,
	eDT_LongLongInt,
    eDT_Float,

    eDT_UChar,
    eDT_UShort,
    eDT_UInt,
    eDT_ULongInt,
	eDT_ULongLongInt,
    eDT_LongFloat,

    eDT_String,
    eDT_DataTime
    //eDT_Currency
} t_EDataType;
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// Data status
typedef enum EDataStatus
{
	eDS_NoData,
	eDS_Blank,
	eDS_Normal
} t_EDataStatus;
////////////////////////////////////////////////////////////////////////////////

//
//	returns appropiete enumerator of data type
//
template< typename T >
inline t_EDataType typeToEnum()
{
    return eDT_Invalid;
}
template<>
inline t_EDataType typeToEnum<bool>()
{
    return eDT_Bool;
}
template<>
inline t_EDataType typeToEnum<char>()
{
    return eDT_Char;
}
template<>
inline t_EDataType typeToEnum<short>()
{
    return eDT_Short;
}
template<>
inline t_EDataType typeToEnum<int>()
{
    return eDT_Int;
}
template<>
inline t_EDataType typeToEnum<long>()
{
    return eDT_LongInt;
}
template<>
inline t_EDataType typeToEnum<long long>()
{
	return eDT_LongLongInt;
}
template<>
inline t_EDataType typeToEnum<double>()
{
    return eDT_Float;
}
template<>
inline t_EDataType typeToEnum<unsigned char>()
{
    return eDT_UChar;
}
template<>
inline t_EDataType typeToEnum<unsigned short>()
{
    return eDT_UShort;
}
template<>
inline t_EDataType typeToEnum<unsigned int>()
{
    return eDT_UInt;
}
template<>
inline t_EDataType typeToEnum<unsigned long>()
{
    return eDT_ULongInt;
}
template<>
inline t_EDataType typeToEnum<unsigned long long>()
{
	return eDT_ULongLongInt;
}
template<>
inline t_EDataType typeToEnum<QString>()
{
    return eDT_String;
}
template<>
inline t_EDataType typeToEnum<QDateTime>()
{
    return eDT_DataTime;
}
//
//	isValidType
//
template<typename T>
inline bool isValidType()
{
	return false;
}
template<>
inline bool isValidType<bool>()
{
	return true;
}
template<>
inline bool isValidType<char>()
{
	return true;
}
template<>
inline bool isValidType<short>()
{
	return true;
}
template<>
inline bool isValidType<int>()
{
	return true;
}
template<>
inline bool isValidType<long>()
{
	return true;
}
template<>
inline bool isValidType<long long>()
{
	return true;
}
template<>
inline bool isValidType<double>()
{
	return true;
}
template<>
inline bool isValidType<unsigned char>()
{
	return true;
}
template<>
inline bool isValidType<unsigned short>()
{
	return true;
}
template<>
inline bool isValidType<unsigned int>()
{
	return true;
}
template<>
inline bool isValidType<unsigned long>()
{
	return true;
}
template<>
inline bool isValidType<unsigned long long>()
{
	return true;
}
template<>
inline bool isValidType<QString>()
{
	return true;
}
template<>
inline bool isValidType<QDateTime>()
{
	return true;
}

////////////////////////////////////////////////////////////////////////////////
} // namespace dl
////////////////////////////////////////////////////////////////////////////////

#endif // CORE_H

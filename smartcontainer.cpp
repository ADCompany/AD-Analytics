/*
	File:
		smartcontainer.cpp

	Abstract:
		implementation of smart container base class 

*/

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef SMART_CONTAINER_H
#   include "smartcontainer.h"
#endif
////////////////////////////////////////////////////////////////////////////////

//
//	creators
//
dl::CSmartContainer* dl::CSmartContainer::create(t_EDataType eType)
{
	switch ( eType )
	{
	case eDT_Bool:
	{
		return dynamic_cast<CSmartContainer*>( new CDataContainer<bool>() );
		break;
	}
	case eDT_Char:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<char>());
		break;
	}
	case eDT_Short:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<short>());
		break;
	}
	case eDT_Int:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<int>());
		break;
	}
	case eDT_LongInt:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<long>());
		break;
	}
	case eDT_LongLongInt:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<longlong>());
		break;
	}
	case eDT_Float:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<double>());
		break;
	}
	case eDT_LongFloat:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<longdouble>());
		break;
	}
	case eDT_UChar:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<uchar>());
		break;
	}
	case eDT_UShort:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<ushort>());
		break;
	}
	case eDT_UInt:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<uint>());
		break;
	}
	case eDT_ULongInt:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<ulong>());
		break;
	}
	case eDT_ULongLongInt:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<ulonglong>());
		break;
	}
	case eDT_String:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<QString>());
		break;
	}
	case eDT_DataTime:
	{
		return dynamic_cast<CSmartContainer*>(new CDataContainer<QDateTime>());
		break;
	}
	default:
		AD_ASSERT( false, "Unsupported Type!" );
		return NULL;
	}
}
dl::CSmartContainer* dl::CSmartContainer::create(t_EDataType eType, int nSize)
{
	switch (eType)
	{
		case eDT_Bool:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<bool>(nSize, bool() ));
			break;
		}
		case eDT_Char:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<char>(nSize, char() ));
			break;
		}
		case eDT_Short:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<short>(nSize, short() ));
			break;
		}
		case eDT_Int:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<int>(nSize, int() ));
			break;
		}
		case eDT_LongInt:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<long>(nSize, long() ));
			break;
		}
		case eDT_LongLongInt:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<longlong>(nSize, longlong() ));
			break;
		}
		case eDT_Float:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<double>(nSize, double() ));
			break;
		}
		case eDT_LongFloat:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<longdouble>(nSize, longdouble() ));
			break;
		}
		case eDT_UChar:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<uchar>(nSize, uchar() ));
			break;
		}
		case eDT_UShort:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<ushort>(nSize, ushort() ));
			break;
		}
		case eDT_UInt:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<uint>(nSize, uint() ));
			break;
		}
		case eDT_ULongInt:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<ulong>(nSize, ulong() ));
			break;
		}
		case eDT_ULongLongInt:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<ulonglong>(nSize, ulonglong() ));
			break;
		}
		case eDT_String:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<QString>(nSize, QString() ));
			break;
		}
		case eDT_DataTime:
		{
			return dynamic_cast<CSmartContainer*>(new CDataContainer<QDateTime>(nSize, QDateTime() ));
			break;
		}
		default:
			AD_ASSERT(false, "Unsupported Type!");
			return NULL;
	}
}
// copy creator
dl::CSmartContainer* dl::CSmartContainer::create(CSmartContainer const* pOther)
{
	if (!pOther)
		return NULL;
	switch (pOther->getType())
	{
		case eDT_Bool:
		{
			CDataContainer<bool> const* pContainer = static_cast< CDataContainer<bool> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<bool>(*pContainer));
			break;
		}
		case eDT_Char:
		{
			CDataContainer<char> const* pContainer = static_cast< CDataContainer<char> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<char>(*pContainer));
			break;
		}
		case eDT_Short:
		{
			CDataContainer<short> const* pContainer = static_cast< CDataContainer<short> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<short>(*pContainer));
		}
		case eDT_Int:
		{
			CDataContainer<int> const* pContainer = static_cast< CDataContainer<int> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<int>(*pContainer));
			break;
		}
		case eDT_LongInt:
		{
			CDataContainer<long> const* pContainer = static_cast< CDataContainer<long> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<long>(*pContainer));
			break;
		}
		case eDT_LongLongInt:
		{
			CDataContainer<longlong> const* pContainer = static_cast< CDataContainer<longlong> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<longlong>(*pContainer));
			break;
		}
		case eDT_Float:
		{
			CDataContainer<double> const* pContainer = static_cast< CDataContainer<double> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<double>(*pContainer));
			break;
		}
		case eDT_LongFloat:
		{
			CDataContainer<longdouble> const* pContainer = static_cast< CDataContainer<longdouble> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<longdouble>(*pContainer));
			break;
		}
		case eDT_UChar:
		{
			CDataContainer<uchar> const* pContainer = static_cast< CDataContainer<uchar> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<uchar>(*pContainer));
			break;
		}
		case eDT_UShort:
		{
			CDataContainer<ushort> const* pContainer = static_cast< CDataContainer<ushort> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<ushort>(*pContainer));
			break;
		}
		case eDT_UInt:
		{
			CDataContainer<uint> const* pContainer = static_cast< CDataContainer<uint> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<uint>(*pContainer));
			break;
		}
		case eDT_ULongInt:
		{
			CDataContainer<ulong> const* pContainer = static_cast< CDataContainer<ulong> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<ulong>(*pContainer));
			break;
		}
		case eDT_ULongLongInt:
		{
			CDataContainer<ulonglong> const* pContainer = static_cast< CDataContainer<ulonglong> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<ulonglong>(*pContainer));
			break;
		}
		case eDT_String:
		{
			CDataContainer<QString> const* pContainer = static_cast< CDataContainer<QString> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<QString>(*pContainer));
			break;
		}
		case eDT_DataTime:
		{
			CDataContainer<QDateTime> const* pContainer = static_cast< CDataContainer<QDateTime> const* >(pOther);
			return dynamic_cast<CSmartContainer*>(new CDataContainer<QDateTime>(*pContainer));
			break;
		}
		default:
			AD_ASSERT(false, "Unsupported Type!");
			return NULL;
	}
}

// getOccurrenceByIndex()
int  dl::CSmartContainer::getOccurrenceByIndex(int index) const
{
	switch (m_eDataType)
	{
		case eDT_Bool:
		{
			CDataContainer<bool> const* pContainer = static_cast< CDataContainer<bool> const* >(this);
			return pContainer->getOccurrenceByIndex( index );
			break;
		}
		case eDT_Char:
		{
			CDataContainer<char> const* pContainer = static_cast< CDataContainer<char> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_Short:
		{
			CDataContainer<short> const* pContainer = static_cast< CDataContainer<short> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_Int:
		{
			CDataContainer<int> const* pContainer = static_cast< CDataContainer<int> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_LongInt:
		{
			CDataContainer<long> const* pContainer = static_cast< CDataContainer<long> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_LongLongInt:
		{
			CDataContainer<longlong> const* pContainer = static_cast< CDataContainer<longlong> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_Float:
		{
			CDataContainer<double> const* pContainer = static_cast< CDataContainer<double> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_UChar:
		{
			CDataContainer<uchar> const* pContainer = static_cast< CDataContainer<uchar> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_UShort:
		{
			CDataContainer<ushort> const* pContainer = static_cast< CDataContainer<ushort> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_UInt:
		{
			CDataContainer<uint> const* pContainer = static_cast< CDataContainer<uint> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_ULongInt:
		{
			CDataContainer<ulong> const* pContainer = static_cast< CDataContainer<ulong> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_ULongLongInt:
		{
			CDataContainer<ulonglong> const* pContainer = static_cast< CDataContainer<ulonglong> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_LongFloat:
		{
			CDataContainer<longdouble> const* pContainer = static_cast< CDataContainer<longdouble> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_String:
		{
			CDataContainer<QString> const* pContainer = static_cast< CDataContainer<QString> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		case eDT_DataTime:
		{
			CDataContainer<QDateTime> const* pContainer = static_cast< CDataContainer<QDateTime> const* >(this);
			return pContainer->getOccurrenceByIndex(index);
			break;
		}
		default:
			AD_ASSERT(false, "Unsupported Type!");
	}
}
// getUniqueDataCount()
int  dl::CSmartContainer::getUniqueDataCount() const
{
	switch (m_eDataType)
	{
		case eDT_Bool:
		{
			CDataContainer<bool> const* pContainer = static_cast< CDataContainer<bool> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_Char:
		{
			CDataContainer<char> const* pContainer = static_cast< CDataContainer<char> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_Short:
		{
			CDataContainer<short> const* pContainer = static_cast< CDataContainer<short> const* >(this);
			return pContainer->getUniqueDataCount();
		}
		case eDT_Int:
		{
			CDataContainer<int> const* pContainer = static_cast< CDataContainer<int> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_LongInt:
		{
			CDataContainer<long> const* pContainer = static_cast< CDataContainer<long> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_LongLongInt:
		{
			CDataContainer<longlong> const* pContainer = static_cast< CDataContainer<longlong> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_Float:
		{
			CDataContainer<double> const* pContainer = static_cast< CDataContainer<double> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_UChar:
		{
			CDataContainer<uchar> const* pContainer = static_cast< CDataContainer<uchar> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_UShort:
		{
			CDataContainer<ushort> const* pContainer = static_cast< CDataContainer<ushort> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_UInt:
		{
			CDataContainer<uint> const* pContainer = static_cast< CDataContainer<uint> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_ULongInt:
		{
			CDataContainer<ulong> const* pContainer = static_cast< CDataContainer<ulong> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_ULongLongInt:
		{
			CDataContainer<ulonglong> const* pContainer = static_cast< CDataContainer<ulonglong> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_LongFloat:
		{
			CDataContainer<longdouble> const* pContainer = static_cast< CDataContainer<longdouble> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_String:
		{
			CDataContainer<QString> const* pContainer = static_cast< CDataContainer<QString> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		case eDT_DataTime:
		{
			CDataContainer<QDateTime> const* pContainer = static_cast< CDataContainer<QDateTime> const* >(this);
			return pContainer->getUniqueDataCount();
			break;
		}
		default:
			AD_ASSERT(false, "Unsupported Type!");
	}
}
// getSize()
int  dl::CSmartContainer::getSize() const
{
	switch (m_eDataType)
	{
	case eDT_Bool:
	{
		CDataContainer<bool> const* pContainer = static_cast< CDataContainer<bool> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_Char:
	{
		CDataContainer<char> const* pContainer = static_cast< CDataContainer<char> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_Short:
	{
		CDataContainer<short> const* pContainer = static_cast< CDataContainer<short> const* >(this);
		return pContainer->getSize();
	}
	case eDT_Int:
	{
		CDataContainer<int> const* pContainer = static_cast< CDataContainer<int> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_LongInt:
	{
		CDataContainer<long> const* pContainer = static_cast< CDataContainer<long> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_LongLongInt:
	{
		CDataContainer<longlong> const* pContainer = static_cast< CDataContainer<longlong> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_Float:
	{
		CDataContainer<double> const* pContainer = static_cast< CDataContainer<double> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_UChar:
	{
		CDataContainer<uchar> const* pContainer = static_cast< CDataContainer<uchar> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_UShort:
	{
		CDataContainer<ushort> const* pContainer = static_cast< CDataContainer<ushort> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_UInt:
	{
		CDataContainer<uint> const* pContainer = static_cast< CDataContainer<uint> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_ULongInt:
	{
		CDataContainer<ulong> const* pContainer = static_cast< CDataContainer<ulong> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_ULongLongInt:
	{
		CDataContainer<ulonglong> const* pContainer = static_cast< CDataContainer<ulonglong> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_LongFloat:
	{
		CDataContainer<longdouble> const* pContainer = static_cast< CDataContainer<longdouble> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_String:
	{
		CDataContainer<QString> const* pContainer = static_cast< CDataContainer<QString> const* >(this);
		return pContainer->getSize();
		break;
	}
	case eDT_DataTime:
	{
		CDataContainer<QDateTime> const* pContainer = static_cast< CDataContainer<QDateTime> const* >(this);
		return pContainer->getSize();
		break;
	}
	default:
		AD_ASSERT(false, "Unsupported Type!");
		return -1;
	}
}
// isEmpty()
bool dl::CSmartContainer::isEmpty() const
{
	switch (m_eDataType)
	{
	case eDT_Bool:
	{
		CDataContainer<bool> const* pContainer = static_cast< CDataContainer<bool> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_Char:
	{
		CDataContainer<char> const* pContainer = static_cast< CDataContainer<char> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_Short:
	{
		CDataContainer<short> const* pContainer = static_cast< CDataContainer<short> const* >(this);
		return pContainer->isEmpty();
	}
	case eDT_Int:
	{
		CDataContainer<int> const* pContainer = static_cast< CDataContainer<int> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_LongInt:
	{
		CDataContainer<long> const* pContainer = static_cast< CDataContainer<long> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_LongLongInt:
	{
		CDataContainer<longlong> const* pContainer = static_cast< CDataContainer<longlong> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_Float:
	{
		CDataContainer<double> const* pContainer = static_cast< CDataContainer<double> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_UChar:
	{
		CDataContainer<uchar> const* pContainer = static_cast< CDataContainer<uchar> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_UShort:
	{
		CDataContainer<ushort> const* pContainer = static_cast< CDataContainer<ushort> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_UInt:
	{
		CDataContainer<uint> const* pContainer = static_cast< CDataContainer<uint> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_ULongInt:
	{
		CDataContainer<ulong> const* pContainer = static_cast< CDataContainer<ulong> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_ULongLongInt:
	{
		CDataContainer<ulonglong> const* pContainer = static_cast< CDataContainer<ulonglong> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_LongFloat:
	{
		CDataContainer<longdouble> const* pContainer = static_cast< CDataContainer<longdouble> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_String:
	{
		CDataContainer<QString> const* pContainer = static_cast< CDataContainer<QString> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	case eDT_DataTime:
	{
		CDataContainer<QDateTime> const* pContainer = static_cast< CDataContainer<QDateTime> const* >(this);
		return pContainer->isEmpty();
		break;
	}
	default:
		AD_ASSERT(false, "Unsupported Type!");
	}
}
// removeByIndex()
void dl::CSmartContainer::removeByIndex( int nIndex )
{
	switch (m_eDataType)
	{
	case eDT_Bool:
	{
		CDataContainer<bool>* pContainer = static_cast< CDataContainer<bool>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_Char:
	{
		CDataContainer<char>* pContainer = static_cast< CDataContainer<char>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_Short:
	{
		CDataContainer<short>* pContainer = static_cast< CDataContainer<short>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_Int:
	{
		CDataContainer<int>* pContainer = static_cast< CDataContainer<int>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_LongInt:
	{
		CDataContainer<long>* pContainer = static_cast< CDataContainer<long>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_LongLongInt:
	{
		CDataContainer<longlong>* pContainer = static_cast< CDataContainer<longlong>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_Float:
	{
		CDataContainer<double>* pContainer = static_cast< CDataContainer<double>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_UChar:
	{
		CDataContainer<uchar>* pContainer = static_cast< CDataContainer<uchar>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_UShort:
	{
		CDataContainer<ushort>* pContainer = static_cast< CDataContainer<ushort>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_UInt:
	{
		CDataContainer<uint>* pContainer = static_cast< CDataContainer<uint>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_ULongInt:
	{
		CDataContainer<ulong>* pContainer = static_cast< CDataContainer<ulong>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_ULongLongInt:
	{
		CDataContainer<ulonglong>* pContainer = static_cast< CDataContainer<ulonglong>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_LongFloat:
	{
		CDataContainer<longdouble>* pContainer = static_cast< CDataContainer<longdouble>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_String:
	{
		CDataContainer<QString>* pContainer = static_cast< CDataContainer<QString>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	case eDT_DataTime:
	{
		CDataContainer<QDateTime>* pContainer = static_cast< CDataContainer<QDateTime>* >(this);
		return pContainer->removeByIndex( nIndex );
		break;
	}
	default:
		AD_ASSERT(false, "Unsupported Type!");
	}
}
// removeByIndex()
void dl::CSmartContainer::removeByIndex( t_IndexMap const& indexMap )
{
	switch (m_eDataType)
	{
		case eDT_Bool:
		{
			CDataContainer<bool>* pContainer = static_cast< CDataContainer<bool>* >(this);
			return pContainer->removeByIndex( indexMap );
			break;
		}
		case eDT_Char:
		{
			CDataContainer<char>* pContainer = static_cast< CDataContainer<char>* >(this);
			return pContainer->removeByIndex( indexMap );
			break;
		}
		case eDT_Short:
		{
			CDataContainer<short>* pContainer = static_cast< CDataContainer<short>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_Int:
		{
			CDataContainer<int>* pContainer = static_cast< CDataContainer<int>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_LongInt:
		{
			CDataContainer<long>* pContainer = static_cast< CDataContainer<long>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_LongLongInt:
		{
			CDataContainer<longlong>* pContainer = static_cast< CDataContainer<longlong>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_Float:
		{
			CDataContainer<double>* pContainer = static_cast< CDataContainer<double>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_UChar:
		{
			CDataContainer<uchar>* pContainer = static_cast< CDataContainer<uchar>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_UShort:
		{
			CDataContainer<ushort>* pContainer = static_cast< CDataContainer<ushort>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_UInt:
		{
			CDataContainer<uint>* pContainer = static_cast< CDataContainer<uint>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_ULongInt:
		{
			CDataContainer<ulong>* pContainer = static_cast< CDataContainer<ulong>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_ULongLongInt:
		{
			CDataContainer<ulonglong>* pContainer = static_cast< CDataContainer<ulonglong>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_LongFloat:
		{
			CDataContainer<longdouble>* pContainer = static_cast< CDataContainer<longdouble>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_String:
		{
			CDataContainer<QString>* pContainer = static_cast< CDataContainer<QString>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		case eDT_DataTime:
		{
			CDataContainer<QDateTime>* pContainer = static_cast< CDataContainer<QDateTime>* >(this);
			return pContainer->removeByIndex(indexMap);
			break;
		}
		default:
			AD_ASSERT(false, "Unsupported Type!");
	}
}
// clear()
void dl::CSmartContainer::clear()
{
	switch (m_eDataType)
	{
	case eDT_Bool:
	{
		CDataContainer<bool>* pContainer = static_cast< CDataContainer<bool>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_Char:
	{
		CDataContainer<char>* pContainer = static_cast< CDataContainer<char>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_Short:
	{
		CDataContainer<short>* pContainer = static_cast< CDataContainer<short>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_Int:
	{
		CDataContainer<int>* pContainer = static_cast< CDataContainer<int>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_LongInt:
	{
		CDataContainer<long>* pContainer = static_cast< CDataContainer<long>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_LongLongInt:
	{
		CDataContainer<longlong>* pContainer = static_cast< CDataContainer<longlong>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_Float:
	{
		CDataContainer<double>* pContainer = static_cast< CDataContainer<double>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_UChar:
	{
		CDataContainer<uchar>* pContainer = static_cast< CDataContainer<uchar>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_UShort:
	{
		CDataContainer<ushort>* pContainer = static_cast< CDataContainer<ushort>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_UInt:
	{
		CDataContainer<uint>* pContainer = static_cast< CDataContainer<uint>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_ULongInt:
	{
		CDataContainer<ulong>* pContainer = static_cast< CDataContainer<ulong>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_ULongLongInt:
	{
		CDataContainer<ulonglong>* pContainer = static_cast< CDataContainer<ulonglong>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_LongFloat:
	{
		CDataContainer<longdouble>* pContainer = static_cast< CDataContainer<longdouble>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_String:
	{
		CDataContainer<QString>* pContainer = static_cast< CDataContainer<QString>* >(this);
		return pContainer->clear();
		break;
	}
	case eDT_DataTime:
	{
		CDataContainer<QDateTime>* pContainer = static_cast< CDataContainer<QDateTime>* >(this);
		return pContainer->clear();
		break;
	}
	default:
		AD_ASSERT(false, "Unsupported Type!");
	}
}
// serialise()
bool dl::CSmartContainer::serialise(QDataStream& dataStrm)
{
	switch (m_eDataType)
	{
		case eDT_Bool:
		{
			CDataContainer<bool>* pContainer = static_cast< CDataContainer<bool>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_Char:
		{
			CDataContainer<char>* pContainer = static_cast< CDataContainer<char>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_Short:
		{
			CDataContainer<short>* pContainer = static_cast< CDataContainer<short>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_Int:
		{
			CDataContainer<int>* pContainer = static_cast< CDataContainer<int>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_LongInt:
		{
			CDataContainer<long>* pContainer = static_cast< CDataContainer<long>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_LongLongInt:
		{
			CDataContainer<longlong>* pContainer = static_cast< CDataContainer<longlong>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_Float:
		{
			CDataContainer<double>* pContainer = static_cast< CDataContainer<double>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_UChar:
		{
			CDataContainer<uchar>* pContainer = static_cast< CDataContainer<uchar>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_UShort:
		{
			CDataContainer<ushort>* pContainer = static_cast< CDataContainer<ushort>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_UInt:
		{
			CDataContainer<uint>* pContainer = static_cast< CDataContainer<uint>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_ULongInt:
		{
			CDataContainer<ulong>* pContainer = static_cast< CDataContainer<ulong>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_ULongLongInt:
		{
			CDataContainer<ulonglong>* pContainer = static_cast< CDataContainer<ulonglong>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_LongFloat:
		{
			CDataContainer<longdouble>* pContainer = static_cast< CDataContainer<longdouble>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_String:
		{
			CDataContainer<QString>* pContainer = static_cast< CDataContainer<QString>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		case eDT_DataTime:
		{
			CDataContainer<QDateTime>* pContainer = static_cast< CDataContainer<QDateTime>* >(this);
			return pContainer->serialise(dataStrm);
			break;
		}
		default:
			AD_ASSERT(false, "Unsupported Type!");
	}
}
// deserialise()
bool dl::CSmartContainer::deserialise(QDataStream& dataStrm)
{
	switch (m_eDataType)
	{
		case eDT_Bool:
		{
			CDataContainer<bool>* pContainer = static_cast< CDataContainer<bool>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_Char:
		{
			CDataContainer<char>* pContainer = static_cast< CDataContainer<char>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_Short:
		{
			CDataContainer<short>* pContainer = static_cast< CDataContainer<short>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_Int:
		{
			CDataContainer<int>* pContainer = static_cast< CDataContainer<int>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_LongInt:
		{
			CDataContainer<long>* pContainer = static_cast< CDataContainer<long>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_LongLongInt:
		{
			CDataContainer<longlong>* pContainer = static_cast< CDataContainer<longlong>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_Float:
		{
			CDataContainer<double>* pContainer = static_cast< CDataContainer<double>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_UChar:
		{
			CDataContainer<uchar>* pContainer = static_cast< CDataContainer<uchar>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_UShort:
		{
			CDataContainer<ushort>* pContainer = static_cast< CDataContainer<ushort>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_UInt:
		{
			CDataContainer<uint>* pContainer = static_cast< CDataContainer<uint>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_ULongInt:
		{
			CDataContainer<ulong>* pContainer = static_cast< CDataContainer<ulong>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_ULongLongInt:
		{
			CDataContainer<ulonglong>* pContainer = static_cast< CDataContainer<ulonglong>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_LongFloat:
		{
			CDataContainer<longdouble>* pContainer = static_cast< CDataContainer<longdouble>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_String:
		{
			CDataContainer<QString>* pContainer = static_cast< CDataContainer<QString>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		case eDT_DataTime:
		{
			CDataContainer<QDateTime>* pContainer = static_cast< CDataContainer<QDateTime>* >(this);
			return pContainer->deserialise(dataStrm);
			break;
		}
		default:
			AD_ASSERT(false, "Unsupported Type!");
	}
}
// internalSort()
void dl::CSmartContainer::internalSort(bool isAscending )
{
	switch (m_eDataType)
	{
	case eDT_Bool:
	{
		CDataContainer<bool>* pContainer = static_cast< CDataContainer<bool>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_Char:
	{
		CDataContainer<char>* pContainer = static_cast< CDataContainer<char>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_Short:
	{
		CDataContainer<short>* pContainer = static_cast< CDataContainer<short>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_Int:
	{
		CDataContainer<int>* pContainer = static_cast< CDataContainer<int>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_LongInt:
	{
		CDataContainer<long>* pContainer = static_cast< CDataContainer<long>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_LongLongInt:
	{
		CDataContainer<longlong>* pContainer = static_cast< CDataContainer<longlong>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_Float:
	{
		CDataContainer<double>* pContainer = static_cast< CDataContainer<double>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_UChar:
	{
		CDataContainer<uchar>* pContainer = static_cast< CDataContainer<uchar>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_UShort:
	{
		CDataContainer<ushort>* pContainer = static_cast< CDataContainer<ushort>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_UInt:
	{
		CDataContainer<uint>* pContainer = static_cast< CDataContainer<uint>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_ULongInt:
	{
		CDataContainer<ulong>* pContainer = static_cast< CDataContainer<ulong>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_ULongLongInt:
	{
		CDataContainer<ulonglong>* pContainer = static_cast< CDataContainer<ulonglong>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_LongFloat:
	{
		CDataContainer<longdouble>* pContainer = static_cast< CDataContainer<longdouble>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_String:
	{
		CDataContainer<QString>* pContainer = static_cast< CDataContainer<QString>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	case eDT_DataTime:
	{
		CDataContainer<QDateTime>* pContainer = static_cast< CDataContainer<QDateTime>* >(this);
		return pContainer->internalSort(isAscending);
		break;
	}
	default:
		AD_ASSERT(false, "Unsupported Type!");
	}
}
// sort()
dl::t_IndexMap dl::CSmartContainer::sort(bool isAscending ) const
{
	switch (m_eDataType)
	{
	case eDT_Bool:
	{
		CDataContainer<bool> const* pContainer = static_cast< CDataContainer<bool> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_Char:
	{
		CDataContainer<char> const* pContainer = static_cast< CDataContainer<char> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_Short:
	{
		CDataContainer<short> const* pContainer = static_cast< CDataContainer<short> const* >(this);
		return pContainer->sort(isAscending);
	}
	case eDT_Int:
	{
		CDataContainer<int> const* pContainer = static_cast< CDataContainer<int> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_LongInt:
	{
		CDataContainer<long> const* pContainer = static_cast< CDataContainer<long> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_LongLongInt:
	{
		CDataContainer<longlong> const* pContainer = static_cast< CDataContainer<longlong> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_Float:
	{
		CDataContainer<double> const* pContainer = static_cast< CDataContainer<double> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_UChar:
	{
		CDataContainer<uchar> const* pContainer = static_cast< CDataContainer<uchar> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_UShort:
	{
		CDataContainer<ushort> const* pContainer = static_cast< CDataContainer<ushort> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_UInt:
	{
		CDataContainer<uint> const* pContainer = static_cast< CDataContainer<uint> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_ULongInt:
	{
		CDataContainer<ulong> const* pContainer = static_cast< CDataContainer<ulong> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_ULongLongInt:
	{
		CDataContainer<ulonglong> const* pContainer = static_cast< CDataContainer<ulonglong> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_LongFloat:
	{
		CDataContainer<longdouble> const* pContainer = static_cast< CDataContainer<longdouble> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_String:
	{
		CDataContainer<QString> const* pContainer = static_cast< CDataContainer<QString> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	case eDT_DataTime:
	{
		CDataContainer<QDateTime> const* pContainer = static_cast< CDataContainer<QDateTime> const* >(this);
		return pContainer->sort(isAscending);
		break;
	}
	default:
		AD_ASSERT(false, "Unsupported Type!");
	}
}
/*
	File:
		columndatacore.h

	Abstract:
		declaration of base data container class
*/
#ifndef SMART_CONTAINER_H
#define SMART_CONTAINER_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef CORE_H
#   include "core.h"
#endif

#ifndef INDICES_H
#   include "indices.h"
#endif

#ifndef MAIN_COLUMN_DATA_CONTAINER_H
#   include "maincolumndatacontainer.h"
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace dl { // data layer
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//	class CSmartContainer
//  Base class for column data
//
class CSmartContainer
{
protected:
	inline CSmartContainer(){};

public:
	//
	//	Static Creators
	//
	template<typename T>
		static CSmartContainer* create();
	template<typename T>
		static CSmartContainer* create( int nSize );
	template<typename T>
		static CSmartContainer* create(int nSize, T const& value);
	template<typename T>
		static CSmartContainer* create( QVector<T> const& aData );
	//
	// Non Template Creators
	//
	static CSmartContainer* create( t_EDataType eType );
	static CSmartContainer* create( t_EDataType eType, int nSize );
	// returns copy of given container
	static CSmartContainer* create( CSmartContainer const* pOther );


public:
    //
    //!  Main Interface <-
    //
	
	// returns data type
	inline t_EDataType getType() const;  // [TESTED]
	// returns occurrence of value in given index
	int getOccurrenceByIndex(int index) const; // [TESTED]
	// count of unique data
	int getUniqueDataCount() const;  // [TESTED]
	// size
	int getSize() const; // [TESTED]
	// is empty
	bool isEmpty() const; // [TESTED]
	// remove
	void removeByIndex(int nIndex ); // [TESTED]
	void removeByIndex(t_IndexMap const& indexMap); // [CRASH]
	
	// clear 
	void clear(); // [TESTED]
	
	// internaly sorts the  container
	void internalSort(bool isAscending = true); // [TESTED]
	// returns index map of sorted data
	t_IndexMap sort(bool isAscending = true) const; // [CRASH]

	// serialise & deserialise
	inline bool serialise( QDataStream& );
	inline bool deserialise( QDataStream& );
	
	//
	//	Template Functions
	//

	// returns first index of given value
	template<typename T>
		inline int getIndexOf(const T& value) const; // [LOGIC ERROR]
	// returns index map of indices for given value
	template<typename T>
        inline t_IndexMap getIndicesOf( const T& value ) const; // [LOGIC ERROR]
	// returns occurrence of given value
	template<typename T>
		inline int getOccurrenceByValue( const T& value ) const; // [TESTED]
	// returns vector of unique data
	template<typename T>
		inline QVector<T> getUniqueDataVector() const;  // [TESTED]
	// returns data vector of corresponding index map 
	template<typename T> 
		inline QVector<T> getDataVector( t_IndexMap const& indexMap = t_IndexMap() ) const; // [TESTED]
	// get data
	template<typename T>
		inline T getData(int index) const; // [TESTED]
	// set data
	template<typename T>
		inline void setData(int index, const T& value);  // [TESTED]
	// changes unique data in given index to given value
	template<typename T>
		inline void changeUniqueData(int index, const T &value);  // [TESTED]
	// insert
	template<typename T>
		inline void insert(const T& value, int index, int count = 1); // [TESTED]
	template<typename T>
		inline void insert(const QVector<T>& aValue, int index); // [CRASH]
	// append
	template<typename T>
		inline void append(const T &value, int count = 1); // [TESTED]
	// append a vector 
	template<typename T>
		inline void append(const QVector<T>& aValue); // [CRASH]
	// removes all items equal to given value 
	template<typename T>
		inline void removeByValue(const T& value); // [LOGIC ERROR] & [CRASH]
protected:
	//
	//  Content
	//
	t_EDataType m_eDataType;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////

// create() [1]
template<typename T>
CSmartContainer* CSmartContainer::create()
{
	if (!isValidType<T>())
		return NULL;
	return dynamic_cast<CSmartContainer*>( new CDataContainer<T>() );
}
// create() [2]
template<typename T>
CSmartContainer* CSmartContainer::create(int nSize)
{
	if (!isValidType<T>())
		return NULL;
	return dynamic_cast<CSmartContainer*>( new CDataContainer<T>( nSize, T() ) );
}
// create() [3]
template<typename T>
CSmartContainer* CSmartContainer::create( int nSize, T const& value )
{
	if (!isValidType<T>())
		return NULL;
	return dynamic_cast<CSmartContainer*>( new CDataContainer<T>( nSize, value ) );
}
// create() [4]
template<typename T>
CSmartContainer* CSmartContainer::create( QVector<T> const& aData )
{
	if (!isValidType<T>())
		return NULL;
	return dynamic_cast<CSmartContainer*>( new CDataContainer<T>( aData ) );
}

//
//	Main Interface
//

// getType()
inline t_EDataType CSmartContainer::getType() const
{
	return m_eDataType;
}
//
//
//	Template Member Functions
//
//
// getIndexOf()
template<typename T>
inline int CSmartContainer::getIndexOf(T const& value) const
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T> const* pContainer = static_cast< CDataContainer<T> const* >(this);
	return pContainer->getIndexOf(value);
}

// getIndicesOf()
template<typename T>
inline t_IndexMap CSmartContainer::getIndicesOf(const T& value) const
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T> const* pContainer = static_cast< CDataContainer<T> const* >(this);
	return pContainer->getIndicesOf(value);
}

// getOccurrenceByValue()
template<typename T>
inline int CSmartContainer::getOccurrenceByValue(const T& value) const
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T> const* pContainer = static_cast< CDataContainer<T> const* >(this);
	return pContainer->getOccurrenceByValue( value );
}

// getUniqueDataVector()
template<typename T>
inline QVector<T> CSmartContainer::getUniqueDataVector() const
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T> const* pContainer = static_cast< CDataContainer<T> const* >(this);
	return pContainer->getUniqueDataVector();
}

// getDataVector()
template<typename T>
inline QVector<T> CSmartContainer::getDataVector( t_IndexMap const& indexMap ) const
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T> const* pContainer = static_cast< CDataContainer<T> const* >(this);
	return pContainer->getDataVector( indexMap );
}

// getData()
template<typename T>
inline T CSmartContainer::getData(int index) const
{
	AD_ASSERT( typeToEnum<T>() == m_eDataType, "Types dont match!");
	CDataContainer<T> const* pContainer = static_cast< CDataContainer<T> const* >(this);
	return pContainer->getData( index );
}

// setData()
template<typename T>
inline void CSmartContainer::setData(int index, const T& value)
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T>* pContainer = static_cast< CDataContainer<T>* >(this);
	return pContainer->setData( index, value );
}

// changeUniqueData()
template<typename T>
inline void CSmartContainer::changeUniqueData(int index, const T &value)
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T>* pContainer = static_cast< CDataContainer<T>* >(this);
	return pContainer->changeUniqueData( index, value );
}

// insert()
template<typename T>
inline void CSmartContainer::insert(const T& value, int index, int count )
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T>* pContainer = static_cast< CDataContainer<T>* >(this);
	return pContainer->insert( value, index, count );
}
// insert()
template<typename T>
inline void CSmartContainer::insert(const QVector<T>& aValue, int index)
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T>* pContainer = static_cast< CDataContainer<T>* >(this);
	return pContainer->insert( aValue, index);
}
// append()
template<typename T>
inline void CSmartContainer::append(const T &value, int count)
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T>* pContainer = static_cast< CDataContainer<T>* >(this);
	return pContainer->append( value, count );
}
// append()
template<typename T>
inline void CSmartContainer::append(const QVector<T>& aValue)
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T>* pContainer = static_cast< CDataContainer<T>* >(this);
	return pContainer->append( aValue );
}
// removeByValue()
template<typename T>
inline void CSmartContainer::removeByValue(const T& value)
{
	Q_ASSERT(typeToEnum<T>() == m_eDataType);
	CDataContainer<T>* pContainer = static_cast< CDataContainer<T>* >(this);
	return pContainer->removeByValue( value );
}
////////////////////////////////////////////////////////////////////////////////
} //  namespace dl
////////////////////////////////////////////////////////////////////////////////

#endif // SMART_CONTAINER_H
/*End of file*/

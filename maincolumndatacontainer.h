#ifndef MAIN_COLUMN_DATA_CONTAINER_H
#define MAIN_COLUMN_DATA_CONTAINER_H

#define MAX_INDEX 2147483648
////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef SMART_CONTAINER_H
#	include "smartcontainer.h"
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace dl { // data layer
////////////////////////////////////////////////////////////////////////////////

//CDataContainer
template <typename T>
class CDataContainer : public CSmartContainer
{
private:
    //  Typedefs
    typedef QMap< T, QLinkedList<int> > t_ListMap;
    typedef typename t_ListMap::iterator t_Iterator;
    typedef typename t_ListMap::const_iterator t_ConstIterator;
    typedef QVector< t_Iterator > t_IteratorVector;

private:
    //
    //  Content
    //
    t_ListMap m_mUniqueData;
    t_IteratorVector m_aIteratorVector;

//private:
//    class const_iterator : std::iterator< std::input_iterator_tag, T >
//    {
//    private:
//        const t_Iterator* ptr;
//    public:
//        const_iterator()
//            : ptr(NULL)
//        {}
//        const_iterator( const t_Iterator* p )
//            : ptr(p)
//        {}
//        const_iterator( const_iterator const& p )
//            : ptr(p.ptr)
//        {}
//        const T& operator*()
//        {
//            return (*ptr).key();
//        }
//        const_iterator& operator++()
//        {
//            ++ptr;
//            return *this;
//        }
//        const_iterator operator++( int )
//        {
//            const_iterator tmp(*this);
//            operator++();
//            return tmp;
//        }
//        bool operator==( const const_iterator& rhs )
//        {
//            return ptr==rhs.ptr;
//        }
//        bool operator!=( const const_iterator& rhs )
//        {
//            return ptr!=rhs.ptr;
//        }
//    };

public:
    //
    //  Constructors
    //
    inline CDataContainer( );
    inline CDataContainer( int size, const T& value );
    inline CDataContainer( QVector<T> const& aValue );
    inline CDataContainer( CDataContainer<T> const& other );

public:
    //
    //!  Interface <-
    //

    inline void internalSort( bool t = true ); //
    inline t_IndexMap sort( bool t = true ) const; //

    inline t_IndexMap filter( int index, bool (*f) ( T ), t_IndexMap const& indexMap = t_IndexMap() ) const;
    inline void internalFilter( int index, bool (*f) ( T ), t_IndexMap const& indexMap = t_IndexMap() ) const;

    inline int getIndexOf( T const& value ) const; //
    inline t_IndexMap getIndicesOf( T const& value ) const; //

    inline int getOccurrenceByIndex( int index ) const; //
    inline int getOccurrenceByValue( T const& value ) const; //
    inline int getUniqueDataCount() const; //

    inline QVector<T> getUniqueDataVector() const; //
    inline QVector<T> getDataVector( t_IndexMap const& indexMap = t_IndexMap() ) const; //
    inline    T getData( int index ) const; //
    inline void setData( int index, T const& value); //
    inline void changeUniqueData( int index, T const& value ); //

    inline bool serialise( QDataStream& ); // to file
    inline bool deserialise( QDataStream& );

    inline void insert( T const& value, int index, int count = 1 ); //
    inline void insert( const QVector<T>& aValue, int index ); //
    inline void append( T const& value , int count ); //
    inline void append( QVector<T> const& aValue ); //

    inline void removeByValue( T const& value ); //
    inline void removeByIndex( int index ); //
    inline void removeByIndex( t_IndexMap const& indexMap ); //

    inline void clear(); //
    inline  int getSize() const; //
    inline bool isEmpty() const; //

private:
    //
    //  Helper Functions
    //
    inline t_IndexMap sortAscending() const; //
    inline t_IndexMap sortDescending() const; //
    inline void internalSortAscending(); //
    inline void internalSortDescending(); //
    /*
    inline t_IndexMap sortAscending( t_IndexMap const& indexMap ) const;
    inline t_IndexMap sortDescending( t_IndexMap const& indexMap ) const;
    inline void internalSortAscending( t_IndexMap const& indexMap );
    inline void internalSortDescending( t_IndexMap const& indexMap );
    */

    //inline t_IndexMap filter(int index, bool (*f)(T), const t_IndexMap &indexMap) const;
    //inline const_iterator end() const; //
    //inline const_iterator begin() const; //

};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline implementations
//
////////////////////////////////////////////////////////////////////////////////

// Constructors
template <typename T>
inline CDataContainer<T>::CDataContainer()
{
    m_eDataType = typeToEnum<T>();
}

template <typename T>
inline CDataContainer<T>::CDataContainer( int size, T const& value )
    : m_aIteratorVector( size )
{
    m_eDataType = typeToEnum<T>();
    if( size )
    {
        t_Iterator it = m_mUniqueData.insert( value, QLinkedList<int> () );
        while( size )
        {
            --size;
            m_aIteratorVector[size] = it;
            it.value().push_front( size );
        }
    }
}

template <typename T>
inline CDataContainer<T>::CDataContainer( QVector<T> const& aValue )
    : m_aIteratorVector( aValue.size() )
{
    m_eDataType = typeToEnum<T>();
    int size  = aValue.size();
    if( size )
    {
        for(int i = 0; i<size; ++i)
        {
            m_aIteratorVector[i] = m_mUniqueData.find( aValue[i] );
            if(m_aIteratorVector[i] == m_mUniqueData.end())
                m_aIteratorVector[i] = m_mUniqueData.insert( aValue[i], QLinkedList<int>() );
            m_aIteratorVector[i].value().push_front( i );
        }
    }
}

template <typename T>
inline CDataContainer<T>::CDataContainer( CDataContainer<T> const& other )
    : m_mUniqueData( other.m_mUniqueData ),
      m_aIteratorVector( other.m_aIteratorVector.size() )
{
    m_eDataType = other.m_eDataType;
    t_Iterator it = m_mUniqueData.begin();
    while(it != m_mUniqueData.end())
    {
        QLinkedList<int>::iterator lstIt = it.value().begin();
        while(lstIt != it.value().end())
        {
            m_aIteratorVector[*lstIt] = it;
            ++lstIt;
        }
        ++it;
    }
}

// Functions
template <typename T>
inline int CDataContainer<T>::getIndexOf( T const& value ) const
{
    t_ConstIterator it = m_mUniqueData.find( value );
    if(it == m_mUniqueData.end())
        return -1;
    QLinkedList<int>::const_iterator lstIt = it.value().begin();
    int nTemp = *lstIt;
    while(lstIt != it.value().end())
    {
        ++lstIt;
        if(*lstIt < nTemp)
            nTemp = *lstIt;
    }
    return nTemp;
}

template <typename T>
inline t_IndexMap CDataContainer<T>::getIndicesOf( T const& value ) const
{
    t_ConstIterator it = m_mUniqueData.find( value );
    if(it == m_mUniqueData.end())
    {
        t_IndexMap tempIndexMap;
        return tempIndexMap;
    }
    QLinkedList<int>::const_iterator lstIt = it.value().begin();
    int size = it.value().size();
    t_IndexMap tempIndexMap( size );
    while( --size )
    {
        tempIndexMap[size] = *lstIt;
        ++lstIt;
    }
    return tempIndexMap;
}

template <typename T>
inline void CDataContainer<T>::append( T const& value, int count )
{
    int size = m_aIteratorVector.size();
    Q_ASSERT( count>=0 && ( count + size )<=MAX_INDEX );
    t_Iterator it = m_mUniqueData.find( value );
    m_aIteratorVector.resize( count + size );
    if(it == m_mUniqueData.end())
        it =  m_mUniqueData.insert( value, QLinkedList<int>() );
    for( int i = count + size-1; i>=size; --i)
    {
        it.value().push_front( i );
        m_aIteratorVector[i] = it;
    }
}

template <typename T>
inline void CDataContainer<T>::append( QVector<T> const& aValue )
{
    m_aIteratorVector.resize( aValue.size() + m_aIteratorVector.size() );
    for(int i = 0; i<aValue.size(); ++i)
    {
        m_aIteratorVector[m_aIteratorVector.size()+i] = m_mUniqueData.find( aValue[i] );
        if(m_aIteratorVector[m_aIteratorVector.size()+i] == m_mUniqueData.end())
            m_aIteratorVector[m_aIteratorVector.size()+i] = m_mUniqueData.insert( aValue[i], QLinkedList<int>() );
        m_aIteratorVector[m_aIteratorVector.size()+i].value().push_front( m_aIteratorVector.size()+i );
    }
}

template <typename T>
inline void CDataContainer<T>::insert( T const& value, int index, int count )
{
    Q_ASSERT( index>=0 && index<m_aIteratorVector.size() );
    Q_ASSERT( count>=0 && (count + m_aIteratorVector.size())<MAX_INDEX );
    for(int i = index; i<m_aIteratorVector.size(); ++i)
    {        
        QLinkedList<int>::iterator lstIt = m_aIteratorVector[i].value().begin();
        while(*lstIt != i)
            ++lstIt;
        *lstIt+=count;
    }
    t_Iterator it = m_mUniqueData.find( value );
    if(it == m_mUniqueData.end())
        it = m_mUniqueData.insert( value, QLinkedList<int>() );
    m_aIteratorVector.insert( index, count, it );
    while(count)
    {
        --count;
        it.value().push_front( index + count );
    }
}

template <typename T>
inline void CDataContainer<T>::insert( const QVector<T>& aValue, int index )
{
    Q_ASSERT( index>=0 && index<m_aIteratorVector.size() );
    Q_ASSERT( (aValue.size() + m_aIteratorVector.size())<MAX_INDEX );
    for(int i = index; i<m_aIteratorVector.size(); ++i)
    {
        QLinkedList<int>::iterator lstIt = m_aIteratorVector[i].value().begin();
        while(*lstIt != i)
            ++lstIt;
        *lstIt+=aValue.size();
    }
    m_aIteratorVector.insert( m_aIteratorVector.size(), aValue.size(), m_mUniqueData.end() );
    for(int i = 0; i<aValue.size(); ++i)
    {
        t_Iterator it = m_mUniqueData.find( aValue[i] );
        if(it == m_mUniqueData.end())
            it = m_mUniqueData.insert( aValue[i] );
        m_aIteratorVector[index + i] = it;
    }
}

template <typename T>
inline int CDataContainer<T>::getSize() const
{
    return m_aIteratorVector.size();
}

template <typename T>
inline T CDataContainer<T>::getData( int index ) const
{
    Q_ASSERT( index>=0 && index<m_aIteratorVector.size() );
    return m_aIteratorVector[index].key();
}

template <typename T>
inline QVector<T> CDataContainer<T>::getUniqueDataVector( ) const
{
    QVector<T> aUniqueDataVector( m_mUniqueData.size() );
    t_ConstIterator it = m_mUniqueData.begin();
    int i = 0;
    while( it!=m_mUniqueData.end() )
    {
        aUniqueDataVector[i] = it.key();
        ++i;
    }
    return aUniqueDataVector;
}

template <typename T>
inline QVector<T> CDataContainer<T>::getDataVector( t_IndexMap const& indexMap ) const
{
    if(indexMap.isEmpty())
    {
        QVector<T> aDataVector( m_aIteratorVector.size() );
        for(int i = 0; i<aDataVector.size(); ++i)
            aDataVector[i] = m_aIteratorVector[i].key();
        return aDataVector;
    }
    QVector<T> aDataVector( indexMap.size() );
    for(int i = 0; i<indexMap.size(); ++i )
        Q_ASSERT( indexMap[i]>=0 && indexMap[i]<m_aIteratorVector.size() );
    for(int i = 0; i<aDataVector.size(); ++i)
        aDataVector[i] = m_aIteratorVector[indexMap[i]].key();
    return aDataVector;
}

template <typename T>
inline void CDataContainer<T>::setData( int index, T const& value )
{
    Q_ASSERT( index>=0 && index<m_aIteratorVector.size() );
    t_Iterator it = m_mUniqueData.find( value );
    if(it == m_aIteratorVector[index])
        return;
    m_aIteratorVector[index].value().removeOne( index );
    if(it == m_mUniqueData.end())
        it = m_mUniqueData.insert( value, QLinkedList<int>() );
    m_aIteratorVector[index] = it;
    it.value().push_front( index );
}

template <typename T>
inline void CDataContainer<T>::removeByIndex( int index )
{
    Q_ASSERT( index>=0 && index<m_aIteratorVector.size() );
    t_Iterator it = m_aIteratorVector[index];
    it.value().removeOne( index );
    if(it.value().isEmpty())
        m_mUniqueData.erase(it);
    m_aIteratorVector.remove( index );
}

template <typename T>
inline void CDataContainer<T>::removeByValue( T const& value )
{
    t_Iterator it = m_mUniqueData.find( value );
    if(it == m_mUniqueData.end())
        return;
    QLinkedList<int>::iterator lstIt = it.value().begin();
    while(lstIt != it.value().end())
    {
        m_aIteratorVector.remove( *lstIt );
        ++lstIt;
    }
    m_mUniqueData.erase( it );
}

template <typename T>
inline void CDataContainer<T>::changeUniqueData( int index, T const& value )
{
    Q_ASSERT( index>=0 && index<m_aIteratorVector.size() );
    if(m_aIteratorVector[index].key() == value)
        return;
    t_Iterator it = m_mUniqueData.find( value );
    if(it == m_mUniqueData.end())
        it = m_mUniqueData.insert( value, QLinkedList<int>() );
    t_Iterator indexIt = m_aIteratorVector[index];
    QLinkedList<int>::iterator lstIt = m_aIteratorVector[index].value().begin();
    while(lstIt != m_aIteratorVector[index].value().end())
    {
        it.value().push_front( *lstIt );
        m_aIteratorVector[*lstIt] = it;
    }
    m_mUniqueData.erase(indexIt);
}

template <typename T>
inline void CDataContainer<T>::removeByIndex( t_IndexMap const& indexMap )
{
    if( indexMap.isEmpty() )
        return;
    int size = indexMap.size();
    for(int i = 0; i<size; ++i)
        Q_ASSERT( indexMap[i]>=0 && indexMap[i]<m_aIteratorVector.size() );
    for(int i = 0; i<size; ++i)
    {
        m_aIteratorVector[indexMap[i]].value().removeOne( indexMap[i] );
        if( m_aIteratorVector[indexMap[i]].value().isEmpty() )
            m_mUniqueData.erase( m_aIteratorVector[indexMap[i]] );
    }
    for(int i = 0; i<size; ++i)
        m_aIteratorVector[indexMap[i]] = m_mUniqueData.end();
    size = m_aIteratorVector.size();
    for(int i = 0; i<size; ++i)
    {
        if(m_aIteratorVector[i] == m_mUniqueData.end())
            m_aIteratorVector.remove( i );
    }
}

template <typename T>
inline int CDataContainer<T>::getOccurrenceByIndex( int index ) const
{
    Q_ASSERT( index>=0 && index<m_aIteratorVector.size() );
    return m_aIteratorVector[index].value().size();
}

template <typename T>
inline int CDataContainer<T>::getOccurrenceByValue( T const& value ) const
{
    t_ConstIterator it = m_mUniqueData.find( value );
    if(it == m_mUniqueData.end())
        return 0;
    return it.value().size();
}

template <typename T>
inline int CDataContainer<T>::getUniqueDataCount()  const
{
    return m_mUniqueData.size();
}

template <typename T>
inline t_IndexMap CDataContainer<T>::sort(bool t) const
{
        return t ? sortAscending() : sortDescending();
}

template <typename T>
inline void CDataContainer<T>::internalSort( bool t )
{
        return t ? internalSortAscending() : internalSortDescending();
}

template <typename T>
inline t_IndexMap CDataContainer<T>::sortAscending() const
{
    t_IndexMap tempIndexMap( m_aIteratorVector.size() );
    t_ConstIterator it = m_mUniqueData.begin();
    int i = 0;
    while(it != m_mUniqueData.end())
    {
        QLinkedList<int>::const_iterator lstIt = it.value().begin();
        while(lstIt != it.value().end())
        {
            tempIndexMap[i] = *lstIt;
            ++lstIt;
            ++i;
        }
        ++it;
    }
    return tempIndexMap;
}

template <typename T>
inline void CDataContainer<T>::internalSortAscending()
{
    t_Iterator it = m_mUniqueData.begin();
    int i = 0;
    while(it != m_mUniqueData.end())
    {
        int size = it.value().size();
        while(size)
        {
            m_aIteratorVector[i] = it;
            ++i;
            --size;
        }
        ++it;
    }
}

template <typename T>
inline t_IndexMap CDataContainer<T>::sortDescending() const
{
    t_IndexMap tempIndexMap( m_aIteratorVector.size() );
    if(tempIndexMap.isEmpty())
        return tempIndexMap;
    t_ConstIterator it = m_mUniqueData.end();
    int i = 0;
    while(it != m_mUniqueData.begin())
    {
        --it;
        QLinkedList<int>::const_iterator lstIt = it.value().begin();
        while(lstIt!=it.value().end())
        {
            tempIndexMap[i] = *lstIt;
            ++i;
            ++lstIt;
        }
    }
    return tempIndexMap;
}

template <typename T>
inline void CDataContainer<T>::internalSortDescending()
{
    if(m_aIteratorVector.isEmpty())
        return;
    t_Iterator it = m_mUniqueData.end();
    int i = 0;
    while(it != m_mUniqueData.begin())
    {
        --it;
        int size = it.value().size();
        while(size)
        {
            m_aIteratorVector[i] = it;
            ++i;
            --size;
        }
    }
}

template <typename T>
inline void CDataContainer<T>::clear()
{
    m_aIteratorVector.clear();
    m_mUniqueData.clear();
}

template <typename T>
inline bool CDataContainer<T>::isEmpty() const
{
    return m_aIteratorVector.isEmpty();
}

} // namespace dl

#endif // MAIN_COLUMN_DATA_CONTAINER_H
/* End of file */


/*
	File:
		icolumn.h
	
	Abstract:
		Defins the column interface
*/
#ifndef I_COLUMN_H
#define I_COLUMN_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef CORE_H
#	include "core.h"
#endif

#ifndef INDICES_H
#	include "indices.h"
#endif

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace dl {
////////////////////////////////////////////////////////////////////////////////
	
////////////////////////////////////////////////////////////////////////////////
//
//	interface IColumn
//	base interface for const columns
//
class IColumn
{
public:
	// default constructor
	IColumn( t_EDataType );
	// destructor
	virtual ~IColumn() = 0;

public:
	//
	//! Const Column Interface<-
	//
	
	// returns column unique ID
	virtual int id() const = 0;
	// returns column name
	virtual QString name() const = 0;
	// returns column type
	virtual t_EDataType getType() = 0;
	// returns column size
	virtual int getSize() = 0;
	
	// get Data
	virtual t_EDataStatus getData( int nRow, bool& ) const;
	virtual t_EDataStatus getData( int nRow, char& ) const;
	virtual t_EDataStatus getData( int nRow, int& ) const;
	virtual t_EDataStatus getData( int nRow, long& ) const;
	virtual t_EDataStatus getData( int nRow, long long& ) const;
	virtual t_EDataStatus getData( int nRow, double& ) const;
	virtual t_EDataStatus getData( int nRow, unsigned char& ) const;
	virtual t_EDataStatus getData( int nRow, unsigned int& ) const;
	virtual t_EDataStatus getData( int nRow, unsigned long& ) const;
	virtual t_EDataStatus getData( int nRow, unsigned long long& ) const;
	virtual t_EDataStatus getData( int nRow, QString& ) const;
	virtual t_EDataStatus getData( int nRow, QDateTime& ) const;
	
	// return value in QVariant
	virtual QVariant getValue( int nRow ) const;

	// get Data by indices
	virtual void getDataVector( QVector< QPair<bool, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<char, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<int, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<long, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<long long, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<double, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<unsigned char, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<unsigned int, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<unsigned long, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<unsigned long long, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<QString, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	virtual void getDataVector( QVector< QPair<QDateTime, t_EDataStatus> >&,
								CIndices const& = CIndices() ) const;
	// make result-indices of appropriate action
	CResultIndices doAction( CResultIndices::EAction, CIndices const& = CIndices() ) const;

public:
	//
	//!	Editable Column Interface<-
	//
	// pasts data from specified column specified an indices to own column in specifies indices 
 	virtual void pastFrom( 
		IColumn const* pFrom, 
		CIndices const& fromIndices = CIndices(), 
		CIndices const& toIndices = CIndices() );
	// set Data
	virtual bool setData( int nRow, bool );
	virtual bool setData( int nRow, char );
	virtual bool setData( int nRow, int );
	virtual bool setData( int nRow, long );
	virtual bool setData( int nRow, long long );
	virtual bool setData( int nRow, double );
	virtual bool setData( int nRow, unsigned char );
	virtual bool setData( int nRow, unsigned int );
	virtual bool setData( int nRow, unsigned long );
	virtual bool setData( int nRow, unsigned long long );
	virtual bool setData( int nRow, QString const& );
	virtual bool setData( int nRow, QDateTime const& );
	virtual bool setData( int nRow, t_EDataStatus );
	// set value from QVariant
	virtual bool setValue(int nRow, QVariant const&);
	
	// size modifier functions 
	virtual void setSize( int nSize );
	virtual void appendValue( QVariant const& );
	virtual void appendRows( int nRowCount );
	virtual void insertRows( int nPos, int nRowCount );
	virtual void removeRows( CIndices const& );

	// serialization
	virtual bool serialise( QDataStream& );
	virtual bool deserialise( QDataStream& );
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
} // namespace dl
////////////////////////////////////////////////////////////////////////////////


#endif // I_COLUMN_H
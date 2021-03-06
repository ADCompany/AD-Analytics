#ifndef INDICES_H
#define INDICES_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef CORE_H
#   include "core.h"
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace dl { // data layer
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	class CIndices
//
typedef QVector<int> CIndices;
typedef CIndices t_IndexMap;
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	class CResultIndices
//
class CResultIndices
{
public:
    enum EAction
    {
        eAct_NoBlancks = 0,
        eAct_SortAsc = 1,
        eAct_SortDsc = 2
    };
public:
    CResultIndices();
    ~CResultIndices();

public:
    //
    //! Interface <-
    //

private:
    //
    //	Content
    //
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
} // namespace dl
////////////////////////////////////////////////////////////////////////////////
#endif //INDICES_H

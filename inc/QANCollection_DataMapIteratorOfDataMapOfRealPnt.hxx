// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _QANCollection_DataMapIteratorOfDataMapOfRealPnt_HeaderFile
#define _QANCollection_DataMapIteratorOfDataMapOfRealPnt_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMapIterator.hxx>
#include <Standard_Real.hxx>
#include <Handle_QANCollection_DataMapNodeOfDataMapOfRealPnt.hxx>
class Standard_NoSuchObject;
class gp_Pnt;
class TColStd_MapRealHasher;
class QANCollection_DataMapOfRealPnt;
class QANCollection_DataMapNodeOfDataMapOfRealPnt;



class QANCollection_DataMapIteratorOfDataMapOfRealPnt  : public TCollection_BasicMapIterator
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT QANCollection_DataMapIteratorOfDataMapOfRealPnt();
  
  Standard_EXPORT QANCollection_DataMapIteratorOfDataMapOfRealPnt(const QANCollection_DataMapOfRealPnt& aMap);
  
  Standard_EXPORT   void Initialize (const QANCollection_DataMapOfRealPnt& aMap) ;
  
  Standard_EXPORT  const  Standard_Real& Key()  const;
  
  Standard_EXPORT  const  gp_Pnt& Value()  const;




protected:





private:





};







#endif // _QANCollection_DataMapIteratorOfDataMapOfRealPnt_HeaderFile

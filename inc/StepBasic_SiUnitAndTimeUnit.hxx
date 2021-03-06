// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_SiUnitAndTimeUnit_HeaderFile
#define _StepBasic_SiUnitAndTimeUnit_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_SiUnitAndTimeUnit.hxx>

#include <Handle_StepBasic_TimeUnit.hxx>
#include <StepBasic_SiUnit.hxx>
#include <Handle_StepBasic_DimensionalExponents.hxx>
#include <Standard_Boolean.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
class StepBasic_TimeUnit;
class StepBasic_DimensionalExponents;



class StepBasic_SiUnitAndTimeUnit : public StepBasic_SiUnit
{

public:

  
  //! Returns a SiUnitAndTimeUnit
  Standard_EXPORT StepBasic_SiUnitAndTimeUnit();
  
  Standard_EXPORT virtual   void Init (const Handle(StepBasic_DimensionalExponents)& aDimensions) ;
  
  Standard_EXPORT virtual   void Init (const Standard_Boolean hasAprefix, const StepBasic_SiPrefix aPrefix, const StepBasic_SiUnitName aName) ;
  
  Standard_EXPORT   void SetTimeUnit (const Handle(StepBasic_TimeUnit)& aTimeUnit) ;
  
  Standard_EXPORT   Handle(StepBasic_TimeUnit) TimeUnit()  const;




  DEFINE_STANDARD_RTTI(StepBasic_SiUnitAndTimeUnit)

protected:




private: 


  Handle(StepBasic_TimeUnit) timeUnit;


};







#endif // _StepBasic_SiUnitAndTimeUnit_HeaderFile

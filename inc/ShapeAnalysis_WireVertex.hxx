// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeAnalysis_WireVertex_HeaderFile
#define _ShapeAnalysis_WireVertex_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Handle_ShapeExtend_WireData_HeaderFile
#include <Handle_ShapeExtend_WireData.hxx>
#endif
#ifndef _Handle_TColStd_HArray1OfInteger_HeaderFile
#include <Handle_TColStd_HArray1OfInteger.hxx>
#endif
#ifndef _Handle_TColgp_HArray1OfXYZ_HeaderFile
#include <Handle_TColgp_HArray1OfXYZ.hxx>
#endif
#ifndef _Handle_TColStd_HArray1OfReal_HeaderFile
#include <Handle_TColStd_HArray1OfReal.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class ShapeExtend_WireData;
class TColStd_HArray1OfInteger;
class TColgp_HArray1OfXYZ;
class TColStd_HArray1OfReal;
class TopoDS_Wire;
class gp_XYZ;


//! Analyzes and records status of vertices in a Wire <br>
//! <br>
//!          The Wire has formerly been loaded in a ShapeExtend_WireData <br>
//!          For each Vertex, a status and some data can be attached <br>
//!          (case found, position and parameters) <br>
//!          Then, these informations can be used to fix problems <br>
class ShapeAnalysis_WireVertex  {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  //! Empty constructor <br>
  Standard_EXPORT   ShapeAnalysis_WireVertex();
  
  Standard_EXPORT     void Init(const TopoDS_Wire& wire,const Standard_Real preci) ;
  
  Standard_EXPORT     void Init(const Handle(ShapeExtend_WireData)& swbd,const Standard_Real preci) ;
  
  Standard_EXPORT     void Load(const TopoDS_Wire& wire) ;
  
  Standard_EXPORT     void Load(const Handle(ShapeExtend_WireData)& sbwd) ;
  //! Sets the precision for work <br>
//!          Analysing: for each Vertex, comparison between the end of the <br>
//!          preceeding edge and the start of the following edge <br>
//!          Each Vertex rank corresponds to the End Vertex of the Edge of <br>
//!          same rank, in the ShapeExtend_WireData. I.E. for Vertex <num>, <br>
//!          Edge <num> is the preceeding one, <num+1> is the following one <br>
  Standard_EXPORT     void SetPrecision(const Standard_Real preci) ;
  
  Standard_EXPORT     void Analyze() ;
  //! Records status "Same Vertex" (logically) on Vertex <num> <br>
  Standard_EXPORT     void SetSameVertex(const Standard_Integer num) ;
  //! Records status "Same Coords" (at the Vertices Tolerances) <br>
  Standard_EXPORT     void SetSameCoords(const Standard_Integer num) ;
  //! Records status "Close Coords" (at the Precision of <me>) <br>
  Standard_EXPORT     void SetClose(const Standard_Integer num) ;
  //! <num> is the End of preceeding Edge, and its projection on the <br>
//!          following one lies on it at the Precision of <me> <br>
//!          <ufol> gives the parameter on the following edge <br>
  Standard_EXPORT     void SetEnd(const Standard_Integer num,const gp_XYZ& pos,const Standard_Real ufol) ;
  //! <num> is the Start of following Edge, its projection on the <br>
//!          preceeding one lies on it at the Precision of <me> <br>
//!          <upre> gives the parameter on the preceeding edge <br>
  Standard_EXPORT     void SetStart(const Standard_Integer num,const gp_XYZ& pos,const Standard_Real upre) ;
  //! <num> is the Intersection of both Edges <br>
//!          <upre> is the parameter on preceeding edge, <ufol> on <br>
//!          following edge <br>
  Standard_EXPORT     void SetInters(const Standard_Integer num,const gp_XYZ& pos,const Standard_Real upre,const Standard_Real ufol) ;
  //! <num> cannot be said as same vertex <br>
  Standard_EXPORT     void SetDisjoined(const Standard_Integer num) ;
  //! Returns True if analysis was performed, else returns False <br>
  Standard_EXPORT     Standard_Boolean IsDone() const;
  //! Returns precision value used in analysis <br>
  Standard_EXPORT     Standard_Real Precision() const;
  //! Returns the number of edges in analyzed wire (i.e. the <br>
//!          length of all arrays) <br>
  Standard_EXPORT     Standard_Integer NbEdges() const;
  //! Returns analyzed wire <br>
  Standard_EXPORT    const Handle_ShapeExtend_WireData& WireData() const;
  //! Returns the recorded status for a vertex <br>
//!          More detail by method Data <br>
  Standard_EXPORT     Standard_Integer Status(const Standard_Integer num) const;
  
  Standard_EXPORT     gp_XYZ Position(const Standard_Integer num) const;
  
  Standard_EXPORT     Standard_Real UPrevious(const Standard_Integer num) const;
  
  Standard_EXPORT     Standard_Real UFollowing(const Standard_Integer num) const;
  //! Returns the recorded status for a vertex <br>
//!          With its recorded position and parameters on both edges <br>
//!          These values are relevant regarding the status: <br>
//!          Status  Meaning   Position  Preceeding  Following <br>
//!          0       Same       no        no          no <br>
//!          1       SameCoord  no        no          no <br>
//!          2       Close      no        no          no <br>
//!          3       End        yes       no          yes <br>
//!          4       Start      yes       yes         no <br>
//!          5       Inters     yes       yes         yes <br>
//!         -1       Disjoined  no        no          no <br>
  Standard_EXPORT     Standard_Integer Data(const Standard_Integer num,gp_XYZ& pos,Standard_Real& upre,Standard_Real& ufol) const;
  //! For a given status, returns the rank of the vertex which <br>
//!          follows <num> and has the same status. 0 if no more <br>
//!          Acts as an iterator, starts on the first one <br>
  Standard_EXPORT     Standard_Integer NextStatus(const Standard_Integer stat,const Standard_Integer num = 0) const;
  //! For a given criter, returns the rank of the vertex which <br>
//!           follows <num> and has the same status. 0 if no more <br>
//!           Acts as an iterator, starts on the first one <br>
//!           Criters are: <br>
//!           0: same vertex (status 0) <br>
//!           1: a solution exists (status >= 0) <br>
//!           2: same coords (i.e. same params) (status 0 1 2) <br>
//!           3: same coods but not same vertex (status 1 2) <br>
//!           4: redefined coords (status 3 4 5) <br>
//!          -1: no solution (status -1) <br>
  Standard_EXPORT     Standard_Integer NextCriter(const Standard_Integer crit,const Standard_Integer num = 0) const;





protected:





private:



Handle_ShapeExtend_WireData myWire;
Handle_TColStd_HArray1OfInteger myStat;
Handle_TColgp_HArray1OfXYZ myPos;
Handle_TColStd_HArray1OfReal myUPre;
Handle_TColStd_HArray1OfReal myUFol;
Standard_Real myPreci;
Standard_Boolean myDone;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
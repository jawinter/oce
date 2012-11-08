// Created on: 1992-06-24
// Created by: Gilles DEBARBOUILLE
// Copyright (c) 1992-1999 Matra Datavision
// Copyright (c) 1999-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.

// Updated:	Gerard GRAS le 090597 
//		reason is PRO6934 -> plantage sur HP 10.2
//		changes are : Replace the field theword,themean from HAsciiString
//			      to AsciiString.
//		because the compiler try to destroies the handle of HAsciiString to early
//		due to inline use probably.
//		See also Units_Token.lxx

#define PRO8727	//GG_180697
//		Mauvaise construction d'un token par copie
//		plantatoire sur HP.

#include <Units_Token.ixx>
#include <TCollection_AsciiString.hxx>
#include <Units_Operators.hxx>

#define XTRACE 1

//=======================================================================
//function : Units_Token
//purpose  : 
//=======================================================================

Units_Token::Units_Token()
{
  theword=" ";
  themean=" ";
  thevalue=0.;
  thedimensions=new Units_Dimensions(0.,0.,0.,0.,0.,0.,0.,0.,0.);
#ifdef TRACE
  cout << " CREATES Token " << endl;
  Dump(0,0);
#endif
}

//=======================================================================
//function : Units_Token
//purpose  : 
//=======================================================================

Units_Token::Units_Token(const Standard_CString aword)
{
  theword=aword;
  themean=" ";
  thevalue=0.;
  thedimensions=new Units_Dimensions(0.,0.,0.,0.,0.,0.,0.,0.,0.);
#ifdef TRACE
  cout << " CREATES Token " << endl;
  Dump(0,0);
#endif
}

//=======================================================================
//function : Units_Token
//purpose  : 
//=======================================================================

Units_Token::Units_Token(const Standard_CString aword,
			 const Standard_CString amean)
{
  theword=aword;
  themean=amean;
  thevalue=0.;
  thedimensions=new Units_Dimensions(0.,0.,0.,0.,0.,0.,0.,0.,0.);
#ifdef TRACE
  cout << " CREATES Token " << endl;
  Dump(0,0);
#endif
}

//=======================================================================
//function : Units_Token
//purpose  : 
//=======================================================================

Units_Token::Units_Token(const Standard_CString aword,
			 const Standard_CString amean,
			 const Standard_Real avalue)
{
  theword=aword;
  themean=amean;
  thevalue=avalue;
  thedimensions=new Units_Dimensions(0.,0.,0.,0.,0.,0.,0.,0.,0.);
#ifdef TRACE
  cout << " CREATES Token " << endl;
  Dump(0,0);
#endif
}

//=======================================================================
//function : Units_Token
//purpose  : 
//=======================================================================

Units_Token::Units_Token(const Standard_CString aword,
			 const Standard_CString amean,
			 const Standard_Real avalue,
			 const Handle(Units_Dimensions)& adimensions)
{
  theword=aword;
  themean=amean;
  thevalue=avalue;
  if(adimensions.IsNull())
    thedimensions = new Units_Dimensions(0.,0.,0.,0.,0.,0.,0.,0.,0.);
  else
    thedimensions = new Units_Dimensions(adimensions->Mass(),
                                         adimensions->Length(),
                                         adimensions->Time(),
                                         adimensions->ElectricCurrent(),
                                         adimensions->ThermodynamicTemperature(),
                                         adimensions->AmountOfSubstance(),
                                         adimensions->LuminousIntensity(),
                                         adimensions->PlaneAngle(),
                                         adimensions->SolidAngle());
#ifdef TRACE
  cout << " CREATES Token " << endl;
  Dump(0,0);
#endif
}

//=======================================================================
//function : Creates
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Creates() const
{
#ifdef PRO8727
  TCollection_AsciiString word = Word();
  TCollection_AsciiString mean = Mean();
  return new Units_Token(word.ToCString(),mean.ToCString(),Value(),Dimensions());
#else
  return new Units_Token(*this);
#endif
}

//=======================================================================
//function : Length
//purpose  : 
//=======================================================================

Standard_Integer Units_Token::Length() const
{
  return theword.Length();
}

//=======================================================================
//function : Dimensions
//purpose  : 
//=======================================================================

void Units_Token::Dimensions(const Handle(Units_Dimensions)& adimensions)
{
  if(adimensions.IsNull())
    thedimensions = new Units_Dimensions(0.,0.,0.,0.,0.,0.,0.,0.,0.);
  else
    thedimensions = new Units_Dimensions(adimensions->Mass(),
                                         adimensions->Length(),
                                         adimensions->Time(),
                                         adimensions->ElectricCurrent(),
                                         adimensions->ThermodynamicTemperature(),
                                         adimensions->AmountOfSubstance(),
                                         adimensions->LuminousIntensity(),
                                         adimensions->PlaneAngle(),
                                         adimensions->SolidAngle());
}

//=======================================================================
//function : Units_Token
//purpose  : 
//=======================================================================

Units_Token::Units_Token(const Handle(Units_Token)& atoken)
{
  theword       = atoken->Word();
  themean       = atoken->Mean();
  thevalue      = atoken->Value();
  thedimensions = atoken->Dimensions();
}

//=======================================================================
//function : Update
//purpose  : 
//=======================================================================

void Units_Token::Update(const Standard_CString amean)
{
  TCollection_AsciiString string = Mean();
  if(string.Search(amean) != -1)
    cout<<Word()<<" encountered twice with the same signification : "<<amean<<endl;
  string = string + amean;
  themean = string;
}

//=======================================================================
//function : Add
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Add (const Standard_Integer) const
{
//  Standard_CString s=new char[thelength+1];
//  strcpy(s,theword);
//  s[thelength-1]=s[thelength-1]+int(i);
  return new Units_Token();
}

//=======================================================================
//function : Add
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Add (const Handle(Units_Token)& atoken) const
{
  TCollection_AsciiString word = Word();
  if(thedimensions->IsEqual(atoken->Dimensions()))
    return new Units_Token(word.ToCString(), " ", thevalue+atoken->Value(), thedimensions);
  else
    return new Units_Token(" ");
}

//=======================================================================
//function : Subtract
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Subtract (const Handle(Units_Token)& atoken) const
{
  TCollection_AsciiString word = Word();
  if(thedimensions->IsEqual(atoken->Dimensions()))
    return new Units_Token(word.ToCString(), " ", thevalue-atoken->Value(), thedimensions);
  else
    return new Units_Token(" ");
}

//=======================================================================
//function : Multiply
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Multiply (const Handle(Units_Token)& atoken) const
{
  TCollection_AsciiString string = Word();
  string.Insert(1,'(');
  string = string + ")*(";
  string = string + atoken->Word();
  string = string + ")";
  return new Units_Token
    (string.ToCString()," ", thevalue*atoken->Value(), thedimensions * (atoken->Dimensions()));
}

//=======================================================================
//function : Multiplied
//purpose  : 
//=======================================================================

Standard_Real Units_Token::Multiplied (const Standard_Real avalue) const
{
  return avalue * thevalue;
}

//=======================================================================
//function : Divide
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Divide (const Handle(Units_Token)& atoken)
     const
{
  if(fabs(atoken->Value())<1.e-40) {
#ifdef DEB
    cout<<"Warning: division on token with value=0 => return initial token."<<endl;
#endif
    return this;
  }
  TCollection_AsciiString string = Word();
  string.Insert(1,'(');
  string = string + ")/(";
  string = string + atoken->Word();
  string = string + ")";
  return new Units_Token
    (string.ToCString()," ", thevalue/atoken->Value(), thedimensions / (atoken->Dimensions()));
}

//=======================================================================
//function : Divided
//purpose  : 
//=======================================================================

Standard_Real Units_Token::Divided (const Standard_Real avalue) const
{
  return avalue / thevalue;
}

//=======================================================================
//function : Power
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Power(const Handle(Units_Token)& atoken) const
{
  TCollection_AsciiString string = Word();
  string.Insert(1,'(');
  string = string + ")**(";
  string = string + atoken->Word();
  string = string + ")";
  return new Units_Token
    (string.ToCString()," ",pow(thevalue,atoken->Value()),pow(thedimensions,atoken->Value()));
}

//=======================================================================
//function : Power
//purpose  : 
//=======================================================================

Handle(Units_Token) Units_Token::Power(const Standard_Real anexponent) const
{
  TCollection_AsciiString exponent(anexponent);
  TCollection_AsciiString string = Word();
  string.Insert(1,'(');
  string = string + ")**(";
  string = string + exponent;
  string = string + ")";
  return new Units_Token
    (string.ToCString()," ",pow(thevalue,anexponent),pow(thedimensions,anexponent));
}

//=======================================================================
//function : IsEqual
//purpose  : 
//=======================================================================

Standard_Boolean Units_Token::IsEqual (const Standard_CString astring) const
{
  TCollection_AsciiString string = Word();
#ifdef UNX
  Standard_Integer length = string.Length();
#else
  unsigned int length = string.Length();
#endif
  if(strlen(astring) == length)
    return (strncmp(string.ToCString(),astring,unsigned(length)) == 0)
      ? Standard_True : Standard_False;
  else 
    return Standard_False;
}

//=======================================================================
//function : IsEqual
//purpose  : 
//=======================================================================

Standard_Boolean Units_Token::IsEqual (const Handle(Units_Token)& atoken) const
{
  TCollection_AsciiString string1 = Word();
  TCollection_AsciiString string2 = atoken->Word();
  Standard_Integer length = string1.Length();
  if(length == atoken->Length())
    return (strcmp(string1.ToCString(),string2.ToCString()) == 0) ? Standard_True : Standard_False;
  else
    return Standard_False;
}

//=======================================================================
//function : Dump
//purpose  : 
//=======================================================================

void Units_Token::Dump(const Standard_Integer ashift,
		       const Standard_Integer alevel) const
{
  int i;
  TCollection_AsciiString word = Word();
  TCollection_AsciiString mean = Mean();

  for(i=0; i<ashift; i++)cout<<"  ";
  cout << "Units_Token::Dump of " << hex << (intptr_t) this << dec << endl;
  for(i=0; i<ashift; i++)cout<<"  ";
  cout<<word.ToCString()<<endl;
  for(i=0; i<ashift; i++)cout<<"  ";
  cout<<"  value : "<<thevalue<<endl;
  for(i=0; i<ashift; i++)cout<<"  ";
  cout<<"  mean  : "<<mean.ToCString()<<endl;
  if(alevel)thedimensions->Dump(ashift);
}

//=======================================================================
//function : operator +
//purpose  : 
//=======================================================================

Handle(Units_Token) operator +(const Handle(Units_Token)& atoken,const Standard_Integer aninteger)
{
  return atoken->Add(aninteger);
}

//=======================================================================
//function : operator +
//purpose  : 
//=======================================================================

Handle(Units_Token) operator +(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
{
  return atoken1->Add(atoken2);
}

//=======================================================================
//function : operator -
//purpose  : 
//=======================================================================

Handle(Units_Token) operator -(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
{
  return atoken1->Subtract(atoken2);
}

//=======================================================================
//function : operator *
//purpose  : 
//=======================================================================

Handle(Units_Token) operator *(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
{
  return atoken1->Multiply(atoken2);
}

//=======================================================================
//function : operator /
//purpose  : 
//=======================================================================

Handle(Units_Token) operator /(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
{
  return atoken1->Divide(atoken2);
}

//=======================================================================
//function : pow
//purpose  : 
//=======================================================================

Handle(Units_Token) pow(const Handle(Units_Token)& atoken1, const Handle(Units_Token)& atoken2)
{
  return atoken1->Power(atoken2);
}

//=======================================================================
//function : pow
//purpose  : 
//=======================================================================

Handle(Units_Token) pow(const Handle(Units_Token)& atoken,const Standard_Real areal)
{
  return atoken->Power(areal);
}

//=======================================================================
//function : operator ==
//purpose  : 
//=======================================================================

Standard_Boolean operator ==(const Handle(Units_Token)& atoken,const Standard_CString astring)
{
  return atoken->IsEqual(astring);
}

//=======================================================================
//function : operator ==
//purpose  : 
//=======================================================================

//Standard_Boolean operator ==(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
//{
//  return atoken1->IsEqual(atoken2);
//}

//=======================================================================
//function : operator !=
//purpose  : 
//=======================================================================

Standard_Boolean operator !=(const Handle(Units_Token)& atoken,const Standard_CString astring)
{
  return atoken->IsNotEqual(astring);
}

//=======================================================================
//function : operator !=
//purpose  : 
//=======================================================================

//Standard_Boolean operator !=(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
//{
//  return atoken1->IsNotEqual(atoken2);
//}

//=======================================================================
//function : operator <=
//purpose  : 
//=======================================================================

Standard_Boolean operator <=(const Handle(Units_Token)& atoken,const Standard_CString astring)
{
  return atoken->IsLessOrEqual(astring);
}

//=======================================================================
//function : operator >
//purpose  : 
//=======================================================================

Standard_Boolean operator >(const Handle(Units_Token)& atoken,const Standard_CString astring)
{
  return atoken->IsGreater(astring);
}

//=======================================================================
//function : operator >
//purpose  : 
//=======================================================================

Standard_Boolean operator >(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
{
  return atoken1->IsGreater(atoken2);
}

//=======================================================================
//function : operator >=
//purpose  : 
//=======================================================================

Standard_Boolean operator >=(const Handle(Units_Token)& atoken1,const Handle(Units_Token)& atoken2)
{
  return atoken1->IsGreaterOrEqual(atoken2);
}

void Units_Token::Destroy () {

#ifdef TRACE
 cout << " DESTROIES Token" << endl;
 Dump(0,0);
#endif
}

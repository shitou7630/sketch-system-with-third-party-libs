// Copyright (c) 2005-2006  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Partially supported by the IST Programme of the EU as a Shared-cost
// RTD (FET Open) Project under Contract No  IST-2000-26473 
// (ECG - Effective Computational Geometry for Curves and Surfaces) 
// and a STREP (FET Open) Project under Contract No  IST-006413 
// (ACS -- Algorithms for Complex Shapes)
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Algebraic_kernel_for_spheres/include/CGAL/Polynomials_for_line_3.h $
// $Id: Polynomials_for_line_3.h 56667 2010-06-09 07:37:13Z sloriot $
//
// Author(s) : Monique Teillaud <Monique.Teillaud@sophia.inria.fr>
//             Sylvain Pion
//             Pedro Machado

#ifndef CGAL_ALGEBRAIC_KERNEL_POLYNOMIALS_FOR_LINE_3_H
#define CGAL_ALGEBRAIC_KERNEL_POLYNOMIALS_FOR_LINE_3_H

#include <CGAL/enum.h>

namespace CGAL {

template < typename FT_ >
class Polynomials_for_line_3
{
  FT_ rep[6]; // stores a1, b1, a2, b2, c3, d3
              // x = a1 t + b1
              // y = a2 t + b2
              // z = a3 t + b3
public:
  
  typedef FT_ FT;
  
  Polynomials_for_line_3(){}
  
  Polynomials_for_line_3(const FT & a1, const FT & b1, 
                 const FT & a2, const FT & b2,
                 const FT & a3, const FT & b3)
  { 
    rep[0] = a1;
    rep[1] = b1;
    rep[2] = a2;
    rep[3] = b2;
    rep[4] = a3;
    rep[5] = b3;
  }

  const FT & a1() const
  { return rep[0]; }

  const FT & b1() const
  { return rep[1]; }
  
  const FT & a2() const
  { return rep[2]; }
  
  const FT & b2() const
  { return rep[3]; }

  const FT & a3() const
  { return rep[4]; }
  
  const FT & b3() const
  { return rep[5]; }

  bool degenerated() const {
    return is_zero(a1()) &&
           is_zero(a2()) &&
           is_zero(a3());
  }

};

template < typename FT >
inline
bool 
operator == ( const Polynomials_for_line_3<FT> & p1,
	      const Polynomials_for_line_3<FT> & p2 )
{
  return( (p1.a1() == p2.a1()) && 
	  (p1.b1() == p2.b1()) &&
	  (p1.a2() == p2.a2()) &&
	  (p1.b2() == p2.b2()) &&
          (p1.a3() == p2.a3()) &&
	  (p1.b3() == p2.b3()));
}

} //namespace CGAL

#endif //CGAL_ALGEBRAIC_KERNEL_POLYNOMIALS_FOR_LINE_3_H

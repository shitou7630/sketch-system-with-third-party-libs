// Copyright (c) 2002  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Kernel_23/include/CGAL/Is_a_predicate.h $
// $Id: Is_a_predicate.h 56667 2010-06-09 07:37:13Z sloriot $
// 
//
// Author(s)     : Sylvain Pion

#ifndef CGAL_IS_A_PREDICATE_H
#define CGAL_IS_A_PREDICATE_H

// How to determine if a kernel functor is a predicate or a construction.

#include <CGAL/basic.h>
#include <CGAL/enum.h>

namespace CGAL {

namespace internal {

// By default it's a construction
template <typename Return_type>
struct Return_type_of_predicate {
    typedef CGAL::Tag_false type;
};

// Specializations for predicates
template <>
struct Return_type_of_predicate<bool> {
    typedef CGAL::Tag_true type;
};

template <>
struct Return_type_of_predicate<CGAL::Sign> {
    typedef CGAL::Tag_true type;
};

template <>
struct Return_type_of_predicate<CGAL::Bounded_side> {
    typedef CGAL::Tag_true type;
};

template <>
struct Return_type_of_predicate<CGAL::Angle> {
    typedef CGAL::Tag_true type;
};

} // namespace internal

template <typename Functor>
struct Is_a_predicate {
  typedef typename internal::Return_type_of_predicate<
                   typename Functor::result_type>::type type;
};

} //namespace CGAL

#endif // CGAL_IS_A_PREDICATE_H

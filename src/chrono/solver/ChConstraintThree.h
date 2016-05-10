//
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2010 Alessandro Tasora
// Copyright (c) 2013 Project Chrono
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file at the top level of the distribution
// and at http://projectchrono.org/license-chrono.txt.
//

#ifndef CHCONSTRAINTTHREE_H
#define CHCONSTRAINTTHREE_H

#include "chrono/solver/ChConstraint.h"
#include "chrono/solver/ChVariables.h"

namespace chrono {

/// This class is inherited by the base ChConstraint(),
/// which does almost nothing. So here this class implements
/// the functionality for a constrint between a THREE
/// objects of type ChVariables(), and defines three constraint
/// matrices, whose column number automatically matches the number
/// of elements in variables vectors.
///  Before starting the solver one must provide the proper
/// values in constraints (and update them if necessary), i.e.
/// must set at least the c_i and b_i values, and jacobians.

class ChApi ChConstraintThree : public ChConstraint {
    CH_RTTI(ChConstraintThree, ChConstraint)

    //
    // DATA
    //

  protected:
    /// The first  constrained object
    ChLcpVariables* variables_a;
    /// The second constrained object
    ChLcpVariables* variables_b;
    /// The third constrained object
    ChLcpVariables* variables_c;

  public:
    //
    // CONSTRUCTORS
    //
    /// Default constructor
    ChConstraintThree() { variables_a = variables_b = variables_c = NULL; }

    /// Copy constructor
    ChConstraintThree(const ChConstraintThree& other) : ChConstraint(other) {
        variables_a = other.variables_a;
        variables_b = other.variables_b;
        variables_c = other.variables_c;
    }

    virtual ~ChConstraintThree() {}

    /// Assignment operator: copy from other object
    ChConstraintThree& operator=(const ChConstraintThree& other);

    //
    // FUNCTIONS
    //

    /// Access jacobian matrix
    virtual ChMatrix<float>* Get_Cq_a() = 0;
    /// Access jacobian matrix
    virtual ChMatrix<float>* Get_Cq_b() = 0;
    /// Access jacobian matrix
    virtual ChMatrix<float>* Get_Cq_c() = 0;

    /// Access auxiliary matrix (ex: used by iterative solvers)
    virtual ChMatrix<float>* Get_Eq_a() = 0;
    /// Access auxiliary matrix (ex: used by iterative solvers)
    virtual ChMatrix<float>* Get_Eq_b() = 0;
    /// Access auxiliary matrix (ex: used by iterative solvers)
    virtual ChMatrix<float>* Get_Eq_c() = 0;

    /// Access the first variable object
    ChLcpVariables* GetVariables_a() { return variables_a; }
    /// Access the second variable object
    ChLcpVariables* GetVariables_b() { return variables_b; }
    /// Access the second variable object
    ChLcpVariables* GetVariables_c() { return variables_c; }

    /// Set references to the constrained objects, each of ChVariables type,
    /// automatically creating/resizing jacobians if needed.
    virtual void SetVariables(ChLcpVariables* mvariables_a,
                              ChLcpVariables* mvariables_b,
                              ChLcpVariables* mvariables_c) = 0;

    //
    // STREAMING
    //

    /// Method to allow deserializing a persistent binary archive (ex: a file)
    /// into transient data.
    virtual void StreamIN(ChStreamInBinary& mstream);

    /// Method to allow serializing transient data into a persistent
    /// binary archive (ex: a file).
    virtual void StreamOUT(ChStreamOutBinary& mstream);
};

}  // end namespace chrono

#endif

/******************************************************************************
 * Top contributors (to current version):
 *   Mudathir Mohamed
 *
 * This file is part of the cvc5 project.
 *
 * Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
 * in the top-level source directory and their institutional affiliations.
 * All rights reserved.  See the file COPYING in the top-level source
 * directory for licensing information.
 * ****************************************************************************
 *
 * The cvc5 java API.
 */

package cvc5;

public class Triplet<A, B, C>
{
  public A first;
  public B second;
  public C third;
  public Triplet(A first, B second, C third)
  {
    this.first = first;
    this.second = second;
    this.third = third;
  }

  @Override public boolean equals(Object object)
  {
    if (this == object)
      return true;
    if (object == null || getClass() != object.getClass())
      return false;

    Triplet<A, B, C> triplet = (Triplet<A, B, C>) object;
    return this.first.equals(triplet.first) && this.second.equals(triplet.second)
        && this.third.equals(triplet.third);
  }
}

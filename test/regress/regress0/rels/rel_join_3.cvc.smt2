; EXPECT: unsat
(set-option :incremental false)
(set-logic ALL)

(declare-fun x () (Set (Tuple Int Int)))
(declare-fun y () (Set (Tuple Int Int)))
(declare-fun r () (Set (Tuple Int Int)))
(declare-fun z () (Tuple Int Int))
(assert (= z (tuple 1 2)))
(declare-fun zt () (Tuple Int Int))
(assert (= zt (tuple 2 1)))
(declare-fun v () (Tuple Int Int))
(assert (= v (tuple 1 1)))
(declare-fun a () (Tuple Int Int))
(assert (= a (tuple 1 5)))
(assert (member (tuple 1 7) x))
(assert (member (tuple 2 3) x))
(assert (member (tuple 3 4) x))
(assert (member (tuple 7 5) y))
(assert (member (tuple 7 3) y))
(assert (member (tuple 4 7) y))
(assert (= r (join x y)))
(assert (member z x))
(assert (member zt y))
(assert (not (member a r)))
(check-sat)

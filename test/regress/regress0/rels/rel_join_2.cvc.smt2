; EXPECT: unsat
(set-option :incremental false)
(set-logic ALL)


(declare-fun x () (Set (Tuple Int Int)))
(declare-fun y () (Set (Tuple Int Int Int)))
(declare-fun z () (Tuple Int Int))
(assert (= z (tuple 1 2)))
(declare-fun zt () (Tuple Int Int Int))
(assert (= zt (tuple 2 1 3)))
(declare-fun a () (Tuple Int Int Int))
(assert (= a (tuple 1 1 3)))
(assert (member z x))
(assert (member zt y))
(assert (not (member a (join x y))))
(check-sat)

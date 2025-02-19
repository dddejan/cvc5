; EXPECT: unsat
(set-option :incremental false)
(set-logic ALL)

(declare-fun x () (Set (Tuple Int Int)))
(declare-fun y () (Set (Tuple Int Int)))
(declare-fun a () Int)
(declare-fun b () Int)
(declare-fun c () Int)
(declare-fun d () Int)
(assert (member (tuple 1 a) x))
(assert (member (tuple 1 c) x))
(assert (member (tuple 1 d) x))
(assert (member (tuple b 1) x))
(assert (= b d))
(assert (member (tuple 2 b) (join (join x x) x)))
(assert (not (member (tuple 2 1) (tclosure x))))
(check-sat)

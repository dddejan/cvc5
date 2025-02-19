; EXPECT: sat
(set-option :incremental false)
(set-logic ALL)

(declare-fun x () (Set (Tuple Int Int)))
(declare-fun y () (Set (Tuple Int Int)))
(declare-datatypes ((unit 0)) (((u))))


(declare-fun w () (Set (Tuple Int unit)))
(declare-fun z () (Set (Tuple unit Int)))
(assert (let ((_let_1 (join w z))) (let ((_let_2 (join x y))) (or (= _let_2 _let_1) (= _let_2 (transpose _let_1))))))
(assert (member (tuple 0 1) (join x y)))
(declare-fun t () Int)
(assert (and (>= t 0) (<= t 1)))
(declare-fun s () Int)
(assert (and (>= s 0) (<= s 1)))
(assert (= (+ s t) 1))
(assert (member (tuple s u) w))
(assert (not (member (tuple u t) z)))
(check-sat)

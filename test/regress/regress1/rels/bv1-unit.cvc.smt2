; EXPECT: unsat
(set-option :incremental false)
(set-logic ALL)
(declare-datatypes ((unit 0)) (((u))))

(declare-fun x () (Set (Tuple (_ BitVec 1) unit (_ BitVec 1))))
(declare-fun y () (Set (Tuple (_ BitVec 1) unit (_ BitVec 1))))
(declare-fun a () (_ BitVec 1))
(declare-fun b () (_ BitVec 1))
(declare-fun c () (_ BitVec 1))
(declare-fun d () (_ BitVec 1))
(declare-fun e () (_ BitVec 1))
(assert (not (= b c)))
(assert (member (tuple a u b) x))
(assert (member (tuple a u c) x))
(assert (member (tuple d u a) y))
(assert (not (member (tuple a u u a) (join x y))))
(check-sat)

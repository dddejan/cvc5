; EXPECT: sat
(set-logic ALL)
(set-option :incremental false)
(declare-datatypes ((role 0)) (((r1) (r2) (r3))))

(declare-datatypes ((|__cvc5_record_pos_(Set role)_neg_(Set role)| 0)) (((|__cvc5_record_pos_(Set role)_neg_(Set role)_ctor| (pos (Set role)) (neg (Set role))))))


(declare-fun emptyRoleSet () (Set role))
(assert (= emptyRoleSet (as emptyset (Set role))))
(declare-fun d () (Array role |__cvc5_record_pos_(Set role)_neg_(Set role)|))
(assert (= (pos (select d r3)) (singleton r1)))
(assert (= (pos (select d r2)) (union (singleton r2) (singleton r3))))
(assert (= (neg (select d r2)) (singleton r1)))
(check-sat)

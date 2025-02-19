; EXPECT: sat
(set-option :incremental false)
(set-option :sets-ext true)
(set-logic ALL)
(declare-sort Atom 0)

(declare-fun x () (Set (Tuple Atom Atom)))
(declare-fun t () (Set (Tuple Atom)))
(declare-fun univ () (Set (Tuple Atom)))
(declare-fun univ2 () (Set (Tuple Atom Atom)))
(declare-fun a () Atom)
(declare-fun b () Atom)
(declare-fun c () Atom)
(declare-fun d () Atom)
(assert (= univ (as univset (Set (Tuple Atom)))))
(assert (= univ2 (as univset (Set (Tuple Atom Atom)))))
(assert (= univ2 (product univ univ)))
(assert (member (tuple a b) x))
(assert (member (tuple c d) x))
(assert (not (= a b)))
(assert (subset (iden univ) x))
(check-sat)

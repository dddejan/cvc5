; EXPECT: unsat
(set-logic ALL)
(set-option :incremental false)
(set-option :finite-model-find true)
(set-option :fmf-bound-int true)
(declare-fun X () (Set Int))
(assert (= (card X) 3))
(assert (forall ((z Int)) (=> (member z X) (and (> z 0) (< z 2)))))
(check-sat-assuming ( (forall ((z Int)) (=> (member z X) (> z 0))) ))

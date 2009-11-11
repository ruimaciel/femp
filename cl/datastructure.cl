(defstruct point (x 0.0 :type float)  (y 0.0 :type float) (z 0.0 :type float))

(defstruct (node (:include point)) )



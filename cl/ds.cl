;;;; FEM's data structure
;(defpackage :fem)

(defclass point () 
	((x :accessor point-x :initarg :x :initform (error "point needs a :x and :y") :type float) 
	(y :accessor point-y :initarg :y :initform (error "point needs a :x and :y") :type float) 
	(z :accessor point-z :initform 0 :initarg :z :type float))
)


(defclass node (point) 
	()
)

(defclass element () ;	base class for all element classes
	(
	(node-list ; a list of all nodes which form the element
		:type 'array 
		:initarg :nodes
		:initform (make-array 0 :element-type 'fixnum :fill-pointer 0)
	)
	(material	; an index for a material contained in the materials array
		:type 'fixnum
		:initform 0
	)
	)
)


(defclass element1D (element)	; base class for all 1D elements
	()
)

(defclass line2 (element1D)
	()
)

(defclass line3 (element1D)
	()
)


(defclass element2D (element)	; base class for all 2D elements
	()
)

(defclass triangle3 (element2D)
	()
)

(defclass triangle6 (element2D)
	()
)

(defclass element3D (element)	; base class for all 3D elements
	()
)

(defclass tetrahedron4	(element3D)
	()
)


(defclass hexahedron8	(element3D)
	()
)

(defclass prism6	(element3D)
	()
)

(defclass pyramid5	(element3D)
	()
)

(defclass tetrahedron10	(element3D)
	()
)

(defclass hexahedron27	(element3D)
	()
)

(defun make-element (element nodes) 
	(declare (type symbol element))
	(declare (type vector fixnum nodes))
	; check if symbol points to a valid class
	(cond	((eq (find-class element) (find-class 'tetrahedron4)) (if (not (eql (length nodes) 4)) (error "~S needs 4 nodes" element)))
		((eq (find-class element) (find-class 'hexahedron8)) (if (not (eql (length nodes) 8)) (error "~S needs 8 nodes" element)))
		((eq (find-class element) (find-class 'prism6)) (if (not (eql (length nodes) 6)) (error "~S needs 6 nodes" element)))
		((eq (find-class element) (find-class 'pyramid5)) (if (not (eql (length nodes) 5)) (error "~S needs 5 nodes" element)))
		((eq (find-class element) (find-class 'tetrahedron10)) (if (not (eql (length nodes) 10)) (error "~S needs 10 nodes" element)))
		((eq (find-class element) (find-class 'hexahedron27)) (if (not (eql (length nodes) 27)) (error "~S needs 27 nodes" element)))
		(t) (error "invalid type"))
	(make-instance element :nodes nodes)
)

(defclass material () ; class that describes each material entry
	()
)

(defclass boundary-condition () 
	()
)


; the data structures

(defvar nodes 	(make-array 10 :element-type 'node :adjustable t :fill-pointer 0))
(defvar elements	(make-array 10 :element-type 'element :adjustable t :fill-pointer 0))
(defvar materials	(make-array 2 :element-type 'material :adjustable t :fill-pointer 0))


(defun push-node (x y &optional z) 
	(declare (type number x y z))	; enforce parameters of type number
	(vector-push-extend (make-instance 'node :x x :y y :z z) nodes)
)

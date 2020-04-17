
#ifndef SETUF_DEF
#define SETUF_DEF

template <typename T>
class UnionFind;


template <typename T>
class SetUF {
	
 	friend class UnionFind<T>; // FIXME: THIS IS WRONG

	public:

		/**
		 * Constructor taking type T parameter to assign to value
		 *
		 * @param v - parameter to assign to value
		 */
		SetUF(T v): value(v), rank(0), parent(this) {}
		

		/**
		 * Default constructor for SetUF
		 */
		SetUF(): value(nullptr), rank(0), parent(this) {}
	
		/**
		 * Copy constructor for SetUF
		 *
		 * @param a - a pointer to another set that will be copied
		 */
		SetUF(const SetUF &a): value(a.value), rank(0), parent(this) {}
	

		/**
		 * Overloading equals operator for SetUF
		 *
		 * @param a - a pointer to another set that will be copied
		 */
		SetUF& operator=(const SetUF &a){
			value = a.value;
			rank = 0;
			parent = this;
		}

		/**
		 * Accessor method for this setUF's value field
		 *
		 * @return this SetUF's value field
		 */
		operator T()const {return value;}


	private:
		T value;
		unsigned int rank;
		SetUF *parent;





};

#endif

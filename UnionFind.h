#ifndef UNIONFIND_DEF
#define UNIONFIND_DEF


#include <iostream> //FIXME
#include<vector>
#include "SetUF.h"
template <typename T>
class UnionFind {
	public:
		/**
		 * Constructor that takes a singleton as its argument. Adds the argument to sets
		 *
		 * @param singletons - a singleton to add to the 
		 *
		 */
		UnionFind(const std::vector<T> &singletons) {
			for (int i = 0; i < singletons.size(); i++) {
				sets.push_back(SetUF<T>(singletons[i]));
			}
		}
			
		/**
		 * 1.Starting from x, traverse to the root of the set
		 * 2.For each node traversed, set its parent to the root (path compression)
		 * 3.Return root
		 * @param node - the value to start at 
		 * @return the root of the tree
		 */
		SetUF<T>& find(T node) {
			std::vector<SetUF<T>*> traversed;
			SetUF<T>* root;
			SetUF<T>* start;
			for (int i = 0; i < this->sets.size(); i++) {
				if (T((this->sets)[i]) == node) {
					start = &(this->sets[i]);
				}
			}
			while(true) {
				if (T(*start->parent) == T(*start)) {
					root = start;
					break;
				}
				traversed.push_back(start);
				start = start->parent;
			}
			for (int i = 0; i < traversed.size(); i++) {
				traversed[i]->parent = root;
			}
			return *root;
		}
	
		void unionOp(SetUF<T> &x, SetUF<T> &y) {
			if (x.rank >= y.rank) {
				y.parent = &x;
				x.rank += 1;
			} else {
				x.parent = &y;
				y.rank += 1;
			} 
		}
		
		void unionOp(T x, SetUF<T> &y){ 
			SetUF<T> xSet = find(x);
			if (xSet.rank >= y.rank) {
				y.parent = &xSet;
				xSet.rank += 1;
			} else {
				xSet.parent = y;
				y.rank += 1;
			}
		}
	
		void unionOp(SetUF<T> &x, T y) {
			SetUF<T> ySet = find(y);
			if (x.rank >= ySet.rank) {
				ySet.parent = x;
				x.rank += 1;
			} else {
				x.parent = &ySet;
				ySet.rank += 1;
			}
		}
	
	
		void unionOp(T x, T y) {
			SetUF<T> xSet = find(x);
			SetUF<T> ySet = find(y);
			if (xSet.rank >= ySet.rank) {
				ySet.parent = &xSet;
				xSet.rank += 1;
			} else {
				xSet.parent = &ySet;
				ySet.rank += 1;
			}
		}


		~UnionFind() = default; 
	

	private:
		std::vector<SetUF<T>> sets;

};

#endif

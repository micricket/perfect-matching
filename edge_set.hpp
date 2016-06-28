#ifndef UARK_CSCE_EDGE_SET_HEADER
#define UARK_CSCE_EDGE_SET_HEADER

#include <random>
#include <vector>
#include <unordered_set>
#include "math.h"
#include "edge.hpp"
#include "vertex.hpp"
#include "polynomial.hpp"

namespace csce {
	class edge_set {
	public:
        edge_set();
        edge_set(const edge_set& edges);
		std::unordered_set<edge, edge_hash> edges;
		edge_set &add(const edge& edge);
		bool contains(const edge& edge) const;
		edge_set difference(const edge_set& set) const;
        edge_set get_random_subset() const;
		edge_set union_set(const edge_set& set) const;
        std::unordered_set<vertex, vertex_hash> get_verticies() const;
		
	private:
        int getRandomNumber() const;
	};
}

#endif /* UARK_CSCE_EDGE_SET_HEADER */

#ifndef UARK_CSCE_EDGE_HEADER
#define UARK_CSCE_EDGE_HEADER

#include "vertex.hpp"

#include <algorithm>

namespace csce {
	class edge {
	public:
		vertex u;
		vertex v;
		edge(csce::vertex _u, csce::vertex _v);
		
		bool operator ==(const csce::edge& other) const {
			return std::min(u, v) == std::min(other.u, other.v) && std::max(u, v) == std::max(other.u, other.v);
		}
		
	private:
		
	};
	
	
	struct edge_hash {
		std::size_t operator()(const csce::edge& e ) const {
			return std::hash<int>()(e.u.id) ^ std::hash<int>()(e.v.id);
		}
	};
}

#endif /* UARK_CSCE_EDGE_HEADER */
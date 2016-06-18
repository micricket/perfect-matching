#ifndef UARK_CSCE_POLYNOMIAL_HEADER
#define UARK_CSCE_POLYNOMIAL_HEADER

#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include "edge_set.hpp"


namespace csce {
	static const long double EPS = 1e-9L;
	
	bool iszero(long double value);
	
	struct polynomial_term_hash {
		std::size_t operator()(const std::unordered_map<char, int>& terms ) const
		{
			std::size_t result = 0;
			for(auto& term : terms){
				result ^= std::hash<char>()(term.first) ^ std::hash<int>()(term.second);
			}
			return result;
		}
	};

	class polynomial { //3x^5y^3 + y^4 - x^2 + 5
	public:
		csce::polynomial add(const csce::polynomial& other) const;
		csce::polynomial subtract(const csce::polynomial& other) const;
		csce::polynomial multiply(const csce::polynomial& other) const;
		std::string str() const;
		
		static csce::polynomial value_of(long double coefficient);
		
		std::unordered_map< std::unordered_map<char, int>, long double, csce::polynomial_term_hash > terms;   //[ {x^5y^3, 3}, {x^2, -2} ]   =   3x^5y^3 - 2x^2
		
		friend polynomial operator+(const polynomial& a, const polynomial& b){
			return a.add(b);
		}
		
		friend polynomial operator-(const polynomial& a, const polynomial& b){
			return a.subtract(b);
		}
		
		friend polynomial operator*(const polynomial& a, const polynomial& b){
			return a.multiply(b);
		}
		
	private:
		
	};
}

#endif /* UARK_CSCE_POLYNOMIAL_HEADER */
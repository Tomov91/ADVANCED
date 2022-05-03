#ifndef MINAGGREGATOR_H
#define MINAGGREGATOR_H

#include<vector>
#include<algorithm>
class MinAggregator : public StreamAggregator
{
private:
	int current;
public:
	MinAggregator(std::istream& istr) : StreamAggregator(istr) {
		std::vector<int>stash;
		this->aggregationResult = 0;
		while (istr >> current)
			stash.push_back(current);
		
		this->aggregationResult = *min_element(stash.begin(), stash.end());

	}
	~MinAggregator(){}
};

#endif//!MINAGGREGATOR_H
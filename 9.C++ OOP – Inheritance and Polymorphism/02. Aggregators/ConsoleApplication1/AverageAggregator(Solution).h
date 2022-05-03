#ifndef AVERAGEAGGREGATOR_H
#define AVERAGEAGGREGATOR_H

class AverageAggregator : public StreamAggregator
{
private:
	int current;
public:
	AverageAggregator(std::istream& istr) : StreamAggregator(istr)
	{
		this->aggregationResult = 0;
		int counter = 0;
		while (istr >> current)
		{
			counter++;
			this->aggregationResult += current;
		}

		this->aggregationResult /= counter;

	}
	~AverageAggregator() {}
};

#endif//!AVERAGEAGGREGATOR_H

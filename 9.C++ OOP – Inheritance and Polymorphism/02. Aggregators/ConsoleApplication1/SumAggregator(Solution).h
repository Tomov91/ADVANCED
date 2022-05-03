#ifndef SUMAGGREGATOR_H
#define SUMAGGREGATOR_H

class SumAggregator : public StreamAggregator
{
private:
	int current;
public:
	SumAggregator(std::istream& inputStr) : StreamAggregator(inputStr) {
		this->aggregationResult = 0;
		while (inputStr >> current)
			this->aggregationResult += current;
	}
	~SumAggregator()
	{

	}



};


#endif//!SUMAGGREGATOR_H

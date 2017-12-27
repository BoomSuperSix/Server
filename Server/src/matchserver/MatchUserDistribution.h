#pragma once
#include <cmath>

class Distribution
{
public:
	virtual double cdf(double x, double mean) const { return 0; };
	virtual ~Distribution() {};
};

class LogisticDistribution : public Distribution
{
	double base;
	double scale;

public:
	LogisticDistribution(double initial_base, double initial_scale) :
		base(initial_base), scale(initial_scale)
	{
	};

	double get_base() const
	{
		return base;
	}

	double get_scale() const
	{
		return scale;
	}

	void set_base(double new_base)
	{
		base = new_base;
	}

	void set_scale(double new_scale)
	{
		scale = new_scale;
	}

	virtual double cdf(double x, double mean) const override
	{
		return 1.0 / (1.0 + std::pow(base, -((x - mean) / scale)));
	}
};

class NormalDistribution : public Distribution
{
	double stdev;

public:
	NormalDistribution(double initial_stdev) :
		stdev(initial_stdev)
	{
	};

	double get_stdev() const
	{
		return stdev;
	}

	void set_stdev(double new_stdev)
	{
		stdev = new_stdev;
	}

	virtual double cdf(double x, double mean) const override
	{
		return (1 + std::erf((x - mean) / (stdev * std::sqrt(2)))) / 2;
	}
};

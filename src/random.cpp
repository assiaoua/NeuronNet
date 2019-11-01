#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s){
	if (s == 0) {
        std::random_device rd;
        seed = rd();
    } else seed = s;
    rng = std::mt19937(seed);
}


void RandomNumbers::uniform_double(std::vector<double>& tab, double lower, double upper) {
	std::uniform_real_distribution<> unif(lower, upper);
	if (!tab.empty()) {
		for (auto I = tab.begin(); I != tab.end(); I++) *I = unif(rng);
	}
}


double RandomNumbers::uniform_double(double lower, double upper) {
	std::uniform_real_distribution<> unif(lower, upper);
	return unif(rng);
}


void RandomNumbers::normal(std::vector<double>& tab, double mean, double sd) {
	std::normal_distribution<> norm(mean, sd);
	if (!tab.empty()) {
		for (auto I = tab.begin(); I != tab.end(); I++) *I = norm(rng);
	}
}


double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<> norm(mean, sd);
	return norm(rng);
}



void RandomNumbers::poisson(std::vector<int>& tab, double mean){
	std::poisson_distribution<> pois(mean);
	if (!tab.empty()) {
		for (auto I = tab.begin(); I != tab.end(); I++) *I = pois(rng);
	}
}


int RandomNumbers::poisson(double mean){
	std::poisson_distribution<> pois(mean);
	return pois(rng);
}


void RandomNumbers::shuffle(std::vector<size_t> &_v) {
	std::shuffle(_v.begin(), _v.end(), rng);
}


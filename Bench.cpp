#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "core/models.hpp"
#include "core/allocator.hpp"
#include "core/generator.hpp"

using namespace std;
using namespace bo_nho;

int main(int argc, char* argv[]) {
	unsigned int seed = 123;
	if (argc >= 2) {
		seed = static_cast<unsigned int>(stoul(argv[1]));
	}
	vector<int> sizes;

	if (argc >= 3) {
		for (int i = 2; i < argc; ++i) {
			int n = stoi(argv[i]);

			if (n > 0) {
				sizes.push_back(n);

			}
		}
	}
	else {
		sizes = { 100, 1000, 10000, 100000, 1000000 };
	}

	cout << "Seed: " << seed << endl;
	cout << "Input sizes: ";
	for (int n : sizes) {
		cout << n << " ";
	}
	cout << endl;

	for (int n : sizes) {
		vector<Hole> holes = generatorHoles(n, 100, 1000, seed);
		vector<Request> requests = generatorRequests(n, 100, 1000, seed + 1);
		
		cout << "So luong du lieu: " << n << endl;
		cout << "so vung nho : " << holes.size() << endl;
		cout << "so yeu cau : " << requests.size() << endl; 
	}

	return 0;
}
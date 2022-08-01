// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
			tree_order_statistics_node_update>
	ordered_multiset;

// Driver code
int main()
{
	ordered_multiset p;
	p.insert(5);
	p.insert(5);
	p.insert(5);
	p.insert(2);
	p.insert(2);
	p.insert(6);
	p.insert(4);

	for (int i = 0; i < (int)p.size(); i++) {

		cout << "The element present at the index " << i
			<< " is ";

		// Print element present at the ith index
		cout << *p.find_by_order(i) << ' ';
		cout << '\n';
	}

	return 0;
}

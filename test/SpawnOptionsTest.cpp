#include "tut.h"
#include "SpawnOptions.h"

using namespace Passenger;
using namespace std;

namespace tut {
	struct SpawnOptionsTest {
	};

	DEFINE_TEST_GROUP(SpawnOptionsTest);

	// Test the SpawnOptions constructors and toVector().
	TEST_METHOD(1) {
		SpawnOptions options;
		options.appRoot     = "/foo";
		options.frameworkSpawnerTimeout = 123;
		options.appSpawnerTimeout       = 456;
		options.maxRequests = 789;
		
		vector<string> args;
		args.push_back("abc");
		args.push_back("def");
		options.toVector(args);
		
		SpawnOptions copy(args, 2);
		ensure_equals(options.appRoot, copy.appRoot);
		ensure_equals(options.lowerPrivilege, copy.lowerPrivilege);
		ensure_equals(options.lowestUser, copy.lowestUser);
		ensure_equals(options.environment, copy.environment);
		ensure_equals(options.spawnMethod, copy.spawnMethod);
		ensure_equals(options.appType, copy.appType);
		ensure_equals(options.frameworkSpawnerTimeout, copy.frameworkSpawnerTimeout);
		ensure_equals(options.appSpawnerTimeout, copy.appSpawnerTimeout);
		ensure_equals(options.maxRequests, copy.maxRequests);
	}
}

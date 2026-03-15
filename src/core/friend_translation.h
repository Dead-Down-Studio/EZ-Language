#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "types.h"

namespace FriendTranslation {

constexpr std::size_t kMaxFriendCallArgs = 16;

struct FriendScalar {
	SimpleType type = SimpleType::Unknown;
	int64_t intValue = 0;
	double floatValue = 0.0;
};

struct PreparedFriendArgs {
	bool useFloatCall = false;
	std::vector<double> doubleArgs;
	std::vector<int> intArgs;
};

bool isSupportedArgumentType(SimpleType type);
std::string supportedArgumentTypeMessage();
std::string tooManyArgumentsMessage(std::size_t maxArgs = kMaxFriendCallArgs);

bool prepareArguments(const std::vector<FriendScalar> &args,
					 PreparedFriendArgs &prepared,
					 std::string &errorMessage);

bool shouldUseFloatCall(const std::vector<FriendScalar> &args);
double toDoubleArg(const FriendScalar &value);
int toIntArg(const FriendScalar &value);

bool invokeDoubleSymbol(void *symbol,
						const std::vector<double> &args,
						double &result,
						std::string &errorMessage);

bool invokeIntSymbol(void *symbol,
					 const std::vector<int> &args,
					 int &result,
					 std::string &errorMessage);

} // namespace FriendTranslation
